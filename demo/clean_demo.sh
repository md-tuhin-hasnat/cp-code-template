#!/bin/bash
# Clean demo content script
set -e

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo " CP Code Template - Clean Demo Content"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Check if library directory exists
if [ ! -d "library" ]; then
    echo "ℹ️  No library directory found. Nothing to clean."
    exit 0
fi

# Ask for confirmation
echo "⚠️  This will delete all content in library/"
echo ""
read -p "Are you sure you want to continue? (y/n) " -n 1 -r
echo ""

if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo "❌ Cancelled."
    exit 0
fi

echo ""
echo "🗑️  Removing demo content..."

# Remove all subdirectories in library
rm -rf library/*/

# Check if library is now empty
if [ -z "$(ls -A library)" ]; then
    echo "✅ Demo content cleaned!"
else
    echo "✅ Demo content removed, but library/ contains other files."
fi

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "ℹ️  Library is now empty and ready for your code."
echo ""
echo "To add your own code:"
echo "  1. Create folders in library/"
echo "  2. Add your code files"
echo "  3. Run: ./run.sh"
echo ""
echo "To restore demo content:"
echo "  Run: ./demo/demo_seed.sh"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
