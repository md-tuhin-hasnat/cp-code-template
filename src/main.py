#!/usr/bin/env python3
"""
CP Code Template Generator - Main Entry Point

This script generates LaTeX content from a competitive programming library
and compiles it into a PDF document.
"""

import sys
from pathlib import Path

# Add src directory to path for imports
src_dir = Path(__file__).parent
sys.path.insert(0, str(src_dir))

import team_info
import content_generator


def main():
    """Main function to generate content.tex and team_info.tex from library/ directory."""
    
    # Define paths
    project_root = Path(__file__).parent.parent
    library_path = project_root / 'library'
    templates_dir = project_root / 'templates'
    output_dir = project_root / 'output'
    
    # Ensure directories exist
    templates_dir.mkdir(exist_ok=True)
    output_dir.mkdir(exist_ok=True)
    
    # Check if library exists
    if not library_path.exists():
        print("Error: library/ directory not found!")
        print("Please create it or run setup scripts first.")
        sys.exit(1)
    
    # Collect team information
    team_info_data = team_info.collect_team_info()
    
    # Generate team_info.tex in templates/
    team_info_path = templates_dir / 'team_info.tex'
    team_info.generate_team_info_tex(team_info_data, team_info_path)
    print(f"✓ Generated {team_info_path}")
    
    print("Generating content.tex from library/...")
    
    # Generate content.tex in templates/
    content_path = templates_dir / 'content.tex'
    num_lines = content_generator.generate_content_tex(library_path, content_path)
    
    print(f"✓ Generated {content_path} successfully!")
    print(f"  Total lines: {num_lines}")


if __name__ == '__main__':
    main()
