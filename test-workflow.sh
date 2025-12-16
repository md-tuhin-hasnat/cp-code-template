#!/bin/bash
# Test script to simulate the GitHub Actions workflow locally

set -e

echo "Testing workflow steps locally..."
echo ""

# Check if templates directory exists
if [ ! -d "templates" ]; then
    echo "❌ templates/ directory not found"
    exit 1
fi

# Test content generation using the CI script
echo "📝 Testing content generation..."
python3 src/generate_ci.py

echo ""
echo "✅ Test completed successfully!"
echo "The workflow should work on GitHub Actions."
