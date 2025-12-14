# CP Code Template Generator

A powerful tool to generate beautifully formatted PDF code templates for competitive programming contests (ICPC, etc.). Converts your library of algorithms and data structures into a professional, multi-column reference document.

## Features

- **Automatic PDF Generation** - Converts your code library into a formatted PDF
- **Cross-Platform** - Works on Linux, macOS, and Windows
- **Multi-Language Support** - C++, Python, Java, C, and Bash
- **Professional Layout**:
  - 3-column landscape A4 format
  - Syntax-highlighted code blocks
  - Hierarchical section organization
  - Table of contents
  - Custom cover page with team information
  - Page footers with team name and page numbers
- **Customizable** - Support for custom fonts, equations, and notes
- **Modular Codebase** - Clean, maintainable Python code

## Project Structure

```
cp-code-template/
├── src/                          # Python source code
│   ├── main.py                   # Entry point
│   ├── utils.py                  # Utility functions
│   ├── code_file_handler.py      # Code file detection
│   ├── content_generator.py      # Content generation logic
│   ├── team_info.py              # Team information collection
│   └── latex_formatter.py        # LaTeX formatting
├── templates/                    # LaTeX templates and generated content
│   ├── main.tex                  # Main LaTeX template
│   ├── content.tex               # Auto-generated (from library/)
│   └── team_info.tex             # Auto-generated (team info)
├── library/                      # Your code library (organize your code here)
│   ├── 01_Data_Structures/
│   ├── 02_Math/
│   └── ...
├── fonts/                        # Custom fonts (optional)
│   ├── text-font/
│   ├── code-font/
│   └── equation-font/
├── output/                       # Final PDF output
│   └── main.pdf
├── scripts/                      # Setup scripts
│   ├── setup.sh                  # Linux/Mac setup
│   └── setup.bat                 # Windows setup
├── demo/                         # Demo content scripts
│   ├── demo_seed.sh              # Populate with sample code
│   └── clean_demo.sh             # Remove demo content
├── run.sh                        # Linux/Mac build script
└── run.bat                       # Windows build script
```

## Quick Start

### Prerequisites

**All Platforms:**
- Python 3.6+
- XeLaTeX (from TeX Live, MiKTeX, or MacTeX)
- Pygments (for syntax highlighting)

### Installation

#### Linux/macOS

**Automated Installation (Recommended):**

```bash
# Clone or download this repository
cd cp-code-template

# Run the setup script
chmod +x scripts/setup.sh
./scripts/setup.sh
```

The setup script will automatically:
- Detect your OS (Ubuntu/Debian, Arch Linux, or macOS)
- Install TeX Live with XeLaTeX
- Install Python 3 and Pygments
- Verify all installations

**Manual Installation:**

If you prefer manual installation or the script doesn't work:

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install texlive-xetex texlive-latex-extra python3 python3-pygments

# Arch Linux
sudo pacman -S texlive-core texlive-latexextra python python-pygments

# macOS (requires Homebrew)
brew install --cask mactex
pip3 install pygments
```

#### Windows

**Automated Setup (Recommended):**

```powershell
# Navigate to project directory
cd cp-code-template

# Run the setup script
scripts\setup.bat
```

The setup script will:
- Check for existing installations
- Provide download links for missing dependencies
- Install Pygments automatically if Python is available

**Manual Installation:**

1. **Install MiKTeX**
   - Download from https://miktex.org/download
   - Run installer and select "Install missing packages automatically"

2. **Install Python**
   - Download from https://www.python.org/downloads/
   - During installation, CHECK "Add Python to PATH"

3. **Install Pygments**
   ```powershell
   pip install pygments
   ```

### Usage

#### Linux/macOS

```bash
# Run the generator
./run.sh

# Or run directly with Python
python3 src/main.py
```

#### Windows

```powershell
# Run the generator
run.bat

# Or run directly with Python
python src\main.py
```

The script will:
1. Ask for team information (contest title, team name, members)
2. Generate LaTeX files from your library
3. Compile the PDF
4. Output the final PDF to `output/main.pdf`

## Quick Demo

Want to see it in action? Use the demo scripts:

```bash
# Populate library with sample code
./demo/demo_seed.sh

# Generate PDF
./run.sh

# View the result
xdg-open output/main.pdf  # Linux
# or: open output/main.pdf  # macOS

# Clean up demo content when done
./demo/clean_demo.sh
```

The demo creates sample code for:
- **Data Structures**: Segment Tree
- **Math**: Number Theory, Combinatorics  
- **Graphs**: DFS, BFS

This gives you a complete example to see the formatting and structure.

## Organizing Your Library

Create your library in the `library/` directory with this structure:

```
library/
├── 01_Data_Structures/
│   ├── Segment_Tree/
│   │   ├── info.tex          # Description (optional)
│   │   ├── code.cpp           # Code implementation
│   │   ├── equation.tex       # Math equations (optional)
│   │   └── note.tex           # Additional notes (optional)
│   └── Fenwick_Tree/
│       └── code.cpp
├── 02_Math/
│   ├── Number_Theory/
│   └── Combinatorics/
└── 03_Graphs/
    ├── DFS/
    └── BFS/
```

### File Types

- **`code.{cpp|py|java|c|sh}`** - Your code implementation (automatically detected)
- **`info.tex`** - Description or usage information (LaTeX format)
- **`equation.tex`** - Mathematical formulas (LaTeX format)
- **`note.tex`** - Important notes or complexity analysis (LaTeX format)

### Naming Conventions

- Use numbers (e.g., `01_`, `02_`) to control display order
- Use underscores for spaces (e.g., `Segment_Tree` → "Segment Tree")
- Folders create sections/subsections in the PDF

## Customization

### Custom Fonts

Place font files in the `fonts/` directory:

```
fonts/
├── text-font/         # For body text (.ttf or .otf files)
├── code-font/         # For code blocks
└── equation-font/     # For mathematical equations
```

Name your font files with these suffixes:
- `YourFont-Regular.ttf`
- `YourFont-Bold.ttf`
- `YourFont-Italic.ttf`
- `YourFont-BoldItalic.ttf`

Update the font names in `templates/main.tex` to match your fonts.

### LaTeX Template

Edit `templates/main.tex` to customize:
- Page layout and margins
- Color scheme
- Section styling
- Header/footer format

## Development

### Code Structure

The generator is modularized for maintainability:

- **`src/main.py`** - Orchestrates the generation process
- **`src/utils.py`** - Utility functions for name sanitization and LaTeX escaping
- **`src/code_file_handler.py`** - Detects code files and maps languages
- **`src/content_generator.py`** - Recursively processes library directory
- **`src/team_info.py`** - Handles team information collection
- **`src/latex_formatter.py`** - Generates LaTeX formatting for headers

### Adding New Language Support

Edit `src/code_file_handler.py`:

```python
LANGUAGE_EXTENSIONS = {
    '.cpp': 'cpp',
    '.py': 'python',
    '.rs': 'rust',  # Add new language
    # ...
}

LANGUAGE_DISPLAY_NAMES = {
    'cpp': 'C++',
    'python': 'Python',
    'rust': 'Rust',  # Add display name
    # ...
}
```

## Output

The generated PDF includes:

1. **Cover Page**
   - Contest title
   - Team name
   - Team member names
   - Generation date

2. **Table of Contents**
   - Hierarchical outline of your library
   - Clickable links to sections

3. **Content Pages**
   - Organized by sections/subsections
   - Syntax-highlighted code blocks
   - Language labels (e.g., "Code in C++:")
   - Custom notes and equations
   - Footer with team name and page number

## Contributing

Contributions are welcome! Feel free to:
- Add new features
- Improve documentation
- Report bugs
- Suggest enhancements

## License

This project is open source and available for competitive programming use.

## Acknowledgments

- Uses [minted](https://github.com/gpoore/minted) for syntax highlighting
- Built with XeLaTeX for advanced typesetting
- Inspired by ICPC team reference document requirements

## Support

If you encounter issues:
1. Check that all dependencies are installed
2. Verify your library structure follows the conventions
3. Review the LaTeX log files in the `output/` directory
4. Ensure font files are properly named if using custom fonts

---

**Happy Competitive Programming!**
