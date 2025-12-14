#!/bin/bash
# CP Library Generator - Complete Workflow (Linux/Mac)
set -e

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo " CP Library Generator - Complete Workflow"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Check dependencies
echo "🔍 Checking dependencies..."
command -v python3 >/dev/null 2>&1 || { echo "❌ Error: python3 is required but not installed."; exit 1; }
command -v xelatex >/dev/null 2>&1 || { echo "❌ Error: xelatex is required but not installed."; exit 1; }
echo "✓ All dependencies found"
echo ""

# Step 1: Generate content.tex and team_info.tex
echo "📝 Step 1: Generating content.tex from library/..."
echo ""
python3 src/main.py || { echo "❌ Content generation failed"; exit 1; }
echo ""
echo "✓ content.tex generated successfully"
echo ""

# Step 2: Copy template to root and compile PDF
echo "📄 Step 2: Compiling PDF with XeLaTeX..."
cp templates/main.tex .
xelatex -shell-escape -output-directory=output main.tex > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "❌ First XeLaTeX pass failed"
    exit 1
fi

echo "   Running second pass for TOC..."
xelatex -shell-escape -output-directory=output main.tex > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "❌ Second XeLaTeX pass failed"
    exit 1
fi

echo "✓ PDF compiled successfully"
echo ""

# Step 3: Clean up auxiliary files
echo "🧹 Cleaning up auxiliary files..."
rm -f main.aux main.log main.out main.toc main.tex
find output -type f ! -name '*.pdf' ! -name '*.tex' -delete 2>/dev/null
echo "   Cleaned up"
echo ""

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo " ✅ Complete! Your PDF is ready."
echo ""
echo " Output: output/main.pdf"
echo " Size: $(du -h output/main.pdf | cut -f1)"
echo ""
echo "To view:"
echo "  - Linux: xdg-open output/main.pdf"
echo "  - macOS: open output/main.pdf"
echo ""
echo "To regenerate:"
echo "  1. Edit files in library/"
echo "  2. Run: ./run.sh"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
