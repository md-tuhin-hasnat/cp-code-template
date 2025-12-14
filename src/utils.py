"""
Utility functions for the CP Code Template Generator.
"""

import re


def sanitize_name(name):
    """
    Sanitize folder name for display in LaTeX.
    - Remove leading numbers like '01_', '02_', etc.
    - Replace underscores with spaces
    
    Args:
        name: Folder name to sanitize
        
    Returns:
        Sanitized name suitable for LaTeX display
    """
    # Remove leading digits followed by underscore (e.g., '01_')
    name = re.sub(r'^\d+_', '', name)
    # Replace underscores with spaces
    name = name.replace('_', ' ')
    return name


def get_section_command(depth):
    """
    Return appropriate LaTeX sectioning command based on depth.
    
    Args:
        depth: Nesting depth (0 = section, 1 = subsection, etc.)
        
    Returns:
        LaTeX section command name
        
    Examples:
        Depth 0: section
        Depth 1: subsection
        Depth 2: subsubsection
        Depth 3+: paragraph
    """
    commands = ['section', 'subsection', 'subsubsection', 'paragraph']
    if depth < len(commands):
        return commands[depth]
    else:
        return 'paragraph'  # Use paragraph for deeper nesting


def escape_latex(text):
    """
    Escape special LaTeX characters in text.
    
    Args:
        text: String to escape
        
    Returns:
        Escaped string safe for LaTeX
    """
    # Only escape characters that commonly appear in names
    # Do NOT escape backslash as it causes issues
    replacements = {
        '&': r'\&',
        '%': r'\%',
        '$': r'\$',
        '#': r'\#',
        '_': r'\_',
        '{': r'\{',
        '}': r'\}',
    }
    for old, new in replacements.items():
        text = text.replace(old, new)
    return text
