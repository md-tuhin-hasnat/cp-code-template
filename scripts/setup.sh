#!/bin/bash
# Dependency installer for CP Code Template Generator
# Supports: Ubuntu/Debian, Arch Linux, macOS, and WSL

set -e  # Exit on error

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo " CP Code Template Generator - Setup"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""

# Detect OS
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    if [ -f /etc/debian_version ]; then
        OS="debian"
        echo "📋 Detected: Debian/Ubuntu Linux"
    elif [ -f /etc/arch-release ]; then
        OS="arch"
        echo "📋 Detected: Arch Linux"
    else
        OS="linux"
        echo "📋 Detected: Generic Linux"
    fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
    OS="macos"
    echo "📋 Detected: macOS"
else
    OS="unknown"
    echo "⚠️  Unknown OS: $OSTYPE"
fi

echo ""

# Function to check if command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Install for Debian/Ubuntu
install_debian() {
    echo "🔧 Installing dependencies for Debian/Ubuntu..."
    echo ""
    
    # Update package list
    echo "📥 Updating package list..."
    sudo apt-get update -qq
    
    # Install XeLaTeX and required packages
    echo "📥 Installing TeX Live (XeLaTeX)..."
    sudo apt-get install -y \
        texlive-xetex \
        texlive-latex-extra \
        texlive-fonts-extra \
        texlive-fonts-recommended
    
    # Install Python and pygments
    echo "📥 Installing Python and Pygments..."
    sudo apt-get install -y python3 python3-pygments
    
    echo ""
    echo "✅ Debian/Ubuntu dependencies installed successfully!"
}

# Install for Arch Linux
install_arch() {
    echo "🔧 Installing dependencies for Arch Linux..."
    echo ""
    
    echo "📥 Installing TeX Live and Python packages..."
    sudo pacman -S --noconfirm \
        texlive-core \
        texlive-latexextra \
        texlive-fontsextra \
        python \
        python-pip \
        python-pygments
    
    echo ""
    echo "✅ Arch Linux dependencies installed successfully!"
}

# Install for macOS
install_macos() {
    echo "🔧 Installing dependencies for macOS..."
    echo ""
    
    # Check if Homebrew is installed
    if ! command_exists brew; then
        echo "❌ Homebrew not found!"
        echo "   Please install Homebrew first: https://brew.sh"
        echo "   Run: /bin/bash -c \"\$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\""
        exit 1
    fi
    
    # Install MacTeX (XeLaTeX)
    echo "📥 Installing MacTeX (this may take a while)..."
    if ! command_exists xelatex; then
        brew install --cask mactex
        echo "ℹ️  You may need to restart your terminal for XeLaTeX to be available in PATH"
    else
        echo "✅ XeLaTeX already installed"
    fi
    
    # Install pygments
    echo "📥 Installing Pygments..."
    pip3 install --user pygments
    
    echo ""
    echo "✅ macOS dependencies installed successfully!"
}

# Main installation logic
echo "🚀 Starting installation..."
echo ""

case $OS in
    debian)
        install_debian
        ;;
    arch)
        install_arch
        ;;
    macos)
        install_macos
        ;;
    linux)
        echo "⚠️  Generic Linux detected. Attempting Debian-style installation..."
        echo "   If this fails, please install manually:"
        echo "   - XeLaTeX (texlive-xetex)"
        echo "   - Python 3"
        echo "   - Pygments (pip3 install pygments)"
        echo ""
        read -p "Continue with Debian-style installation? (y/n) " -n 1 -r
        echo
        if [[ $REPLY =~ ^[Yy]$ ]]; then
            install_debian
        else
            echo "Installation cancelled."
            exit 1
        fi
        ;;
    *)
        echo "❌ Unsupported operating system!"
        echo ""
        echo "Please install the following manually:"
        echo "  1. XeLaTeX (from TeX Live or MiKTeX)"
        echo "  2. Python 3"
        echo "  3. Pygments: pip3 install pygments"
        exit 1
        ;;
esac

# Verify installations
echo ""
echo "🔍 Verifying installations..."
echo ""

ALL_OK=true

# Check XeLaTeX
if command_exists xelatex; then
    XELATEX_VERSION=$(xelatex --version | head -n1)
    echo "✅ XeLaTeX: $XELATEX_VERSION"
else
    echo "❌ XeLaTeX: NOT FOUND"
    echo "   You may need to restart your terminal or add TeX to your PATH"
    ALL_OK=false
fi

# Check Python
if command_exists python3; then
    PYTHON_VERSION=$(python3 --version)
    echo "✅ Python: $PYTHON_VERSION"
else
    echo "❌ Python 3: NOT FOUND"
    ALL_OK=false
fi

# Check Pygments
if python3 -c "import pygments" 2>/dev/null; then
    PYGMENTS_VERSION=$(python3 -c "import pygments; print(pygments.__version__)")
    echo "✅ Pygments: version $PYGMENTS_VERSION"
else
    echo "❌ Pygments: NOT FOUND"
    echo "   Try: pip3 install --user pygments"
    ALL_OK=false
fi

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

if [ "$ALL_OK" = true ]; then
    echo "✅ Setup complete! All dependencies installed."
    echo ""
    echo "Next steps:"
    echo "  1. Organize your code in library/"
    echo "  2. Run: ./scripts/run.sh"
    echo "  3. View: output/main.pdf"
    echo ""
    echo "See README.md for more information."
else
    echo "⚠️  Setup incomplete. Please fix the issues above."
fi

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
