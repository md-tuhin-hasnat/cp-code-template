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

# Test content generation with default values
echo "📝 Testing content generation..."
python3 -c "
import sys
from pathlib import Path
sys.path.insert(0, 'src')

import content_generator
import team_info

# Define paths
library_path = Path('library')
templates_dir = Path('templates')
templates_dir.mkdir(exist_ok=True)

# Use default team info
team_info_data = {
    'title': 'ICPC World Finals',
    'team_name': 'Team Name',
    'members': ['Member 1', 'Member 2', 'Member 3']
}

# Generate team_info.tex
team_info_path = templates_dir / 'team_info.tex'
team_info.generate_team_info_tex(team_info_data, team_info_path)
print('✓ team_info.tex generated successfully')

# Generate content.tex
content_path = templates_dir / 'content.tex'
num_lines = content_generator.generate_content_tex(library_path, content_path)
print(f'✓ content.tex generated successfully with {num_lines} lines')
"

echo ""
echo "✅ Test completed successfully!"
echo "The workflow should work on GitHub Actions."
