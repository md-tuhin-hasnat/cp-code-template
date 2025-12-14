"""
Code file detection and language mapping.
"""

from pathlib import Path


# Language extensions mapping
LANGUAGE_EXTENSIONS = {
    '.cpp': 'cpp',
    '.py': 'python',
    '.java': 'java',
    '.c': 'c',
    '.sh': 'bash'
}

# Display names for languages
LANGUAGE_DISPLAY_NAMES = {
    'cpp': 'C++',
    'python': 'Python',
    'java': 'Java',
    'c': 'C',
    'bash': 'Bash'
}


def find_code_file(directory):
    """
    Find code file in directory, checking extensions in priority order.
    
    Args:
        directory: Path object of directory to search
        
    Returns:
        Tuple of (filename, language) or (None, None) if not found
        
    Examples:
        >>> find_code_file(Path('library/math'))
        ('code.cpp', 'cpp')
    """
    for ext, lang in LANGUAGE_EXTENSIONS.items():
        code_file = directory / f'code{ext}'
        if code_file.exists():
            return (code_file.name, lang)
    
    return (None, None)


def get_language_display_name(lang_id):
    """
    Get the display name for a language ID.
    
    Args:
        lang_id: Language identifier (e.g., 'cpp', 'python')
        
    Returns:
        Display name (e.g., 'C++', 'Python') or capitalized lang_id if not found
    """
    return LANGUAGE_DISPLAY_NAMES.get(lang_id, lang_id.capitalize())
