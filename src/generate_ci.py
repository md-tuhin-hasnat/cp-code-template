#!/usr/bin/env python3
"""
CI/CD Generator Script - Automated PDF generation for GitHub Actions

This script generates the LaTeX content files without user interaction,
using predefined default values for team information.
"""

import sys
from pathlib import Path

# Add src directory to path for imports
src_dir = Path(__file__).parent
sys.path.insert(0, str(src_dir))

import team_info
import content_generator


def main():
    """Generate content.tex and team_info.tex with default values for CI/CD."""
    
    # Define paths
    project_root = Path(__file__).parent.parent
    library_path = project_root / 'library'
    templates_dir = project_root / 'templates'
    
    # Ensure directories exist
    templates_dir.mkdir(exist_ok=True)
    
    # Check if library exists
    if not library_path.exists():
        print("Error: library/ directory not found!")
        sys.exit(1)
    
    # Use default team info for automated builds
    team_info_data = {
        'title': 'ICPC Dhaka Regional 2025',
        'team_name': 'BUBT_Sunday_Monday_Close',
        'members': ['Md. Tuhin Hasnat', 'Amir Hamza Miraz', 'Rakin Absar Ratul']
    }
    
    # Generate team_info.tex in templates/
    team_info_path = templates_dir / 'team_info.tex'
    team_info.generate_team_info_tex(team_info_data, team_info_path)
    print(f"✓ Generated {team_info_path}")
    
    # Generate content.tex in templates/
    content_path = templates_dir / 'content.tex'
    num_lines = content_generator.generate_content_tex(library_path, content_path)
    print(f"✓ Generated {content_path} with {num_lines} lines")
    
    print("\n✅ All files generated successfully for CI/CD build!")


if __name__ == '__main__':
    main()
