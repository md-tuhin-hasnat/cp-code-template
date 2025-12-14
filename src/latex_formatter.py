"""
LaTeX formatting utilities for code headers and sections.
"""


def format_code_header(lang_display):
    """
    Generate LaTeX code for a code header with language label and dashed line.
    
    Args:
        lang_display: Display name of the language (e.g., 'C++', 'Python')
        
    Returns:
        List of LaTeX lines for the code header
    """
    return [
        '',  # Line break before header
        f'\\textbf{{\\textit{{Code in {lang_display}:}}}}\\\\[-2pt]',  # Header with reduced space
        '\\noindent\\tikz{\\draw[gray, line width=0.2pt, dash pattern=on 3pt off 2pt] (0,0) -- (\\linewidth,0);}',  # Dashed line
        '\\vspace{-0.3in}'  # Reduce space before code
    ]


def format_section_header(section_name, section_cmd):
    """
    Generate LaTeX code for a section header.
    
    Args:
        section_name: Name of the section
        section_cmd: LaTeX section command (e.g., 'section', 'subsection')
        
    Returns:
        LaTeX line for section header
    """
    return f'\\{section_cmd}{{{section_name}}}'
