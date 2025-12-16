#!/bin/bash
# Simulate the exact GitHub Actions CI workflow locally
# This script mimics what happens in .github/workflows/generate-pdf.yml

set -e

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo " Running CI Workflow Locally"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Step 1: Check dependencies (like CI does)
echo "🔍 Checking dependencies..."
command -v python3 >/dev/null 2>&1 || { echo "❌ Error: python3 is required"; exit 1; }
command -v xelatex >/dev/null 2>&1 || { echo "❌ Error: xelatex is required"; exit 1; }
python3 -c "import pygments" 2>/dev/null || { echo "❌ Error: pygments is required (run: pip install pygments)"; exit 1; }
echo "✓ All dependencies found"
echo ""

# Step 2: Generate content.tex (using CI script)
echo "📝 Generating content.tex..."
python3 src/generate_ci.py
echo ""

# Step 3: Compile PDF
echo "📄 Compiling PDF with XeLaTeX..."
mkdir -p output
cp templates/main.tex .

echo "   First pass..."
xelatex -shell-escape -interaction=nonstopmode -output-directory=output main.tex > /dev/null 2>&1 || true
if [ ! -f output/main.pdf ]; then
    echo "❌ XeLaTeX compilation failed - PDF not created"
    echo "Check output/main.log for details"
    exit 1
fi

echo "   Second pass for TOC..."
xelatex -shell-escape -interaction=nonstopmode -output-directory=output main.tex > /dev/null 2>&1 || true

# Final check
if [ ! -f output/main.pdf ]; then
    echo "❌ PDF generation failed"
    echo "Check output/main.log for details"
    exit 1
fi

echo "✓ PDF compiled successfully"
echo ""

# Step 4: Clean up auxiliary files
echo "🧹 Cleaning up auxiliary files..."
rm -f main.aux main.log main.out main.toc main.tex
find output -type f ! -name '*.pdf' ! -name '*.tex' -delete 2>/dev/null || true
echo "   Cleaned up"
echo ""

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo " ✅ CI Workflow Complete!"
echo ""
echo " Output: output/main.pdf"
echo " Size: $(du -h output/main.pdf | cut -f1)"
echo ""
echo " This PDF was generated using CI defaults:"
echo "   Team: BUBT_Sunday_Monday_Close"
echo "   Contest: ICPC Dhaka Regional 2025"
echo ""
echo " To customize team info, edit: src/generate_ci.py"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
