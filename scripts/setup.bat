@echo off
REM Dependency installer for CP Code Template Generator (Windows)
setlocal enabledelayedexpansion

echo.
echo ================================================
echo  CP Code Template Generator - Setup
echo ================================================
echo.

echo Detected: Windows
echo.

REM Function to check if command exists
where python >nul 2>&1
if %errorlevel% equ 0 (
    set PYTHON_EXISTS=1
) else (
    set PYTHON_EXISTS=0
)

where xelatex >nul 2>&1
if %errorlevel% equ 0 (
    set XELATEX_EXISTS=1
) else (
    set XELATEX_EXISTS=0
)

echo Checking current installation status...
echo.

REM Check Python
if %PYTHON_EXISTS% equ 1 (
    echo [OK] Python is installed
    python --version
) else (
    echo [!] Python is NOT installed
)

REM Check XeLaTeX
if %XELATEX_EXISTS% equ 1 (
    echo [OK] XeLaTeX is installed
    xelatex --version | findstr /C:"XeTeX"
) else (
    echo [!] XeLaTeX is NOT installed
)

echo.
echo ================================================
echo.

REM If both are installed, we're done
if %PYTHON_EXISTS% equ 1 if %XELATEX_EXISTS% equ 1 (
    echo All dependencies are already installed!
    echo.
    echo Checking Pygments...
    python -c "import pygments; print('Pygments version:', pygments.__version__)" 2>nul
    if errorlevel 1 (
        echo Pygments is NOT installed. Installing...
        pip install pygments
        if errorlevel 1 (
            echo.
            echo Error: Failed to install Pygments
            echo Please try manually: pip install pygments
            pause
            exit /b 1
        )
        echo Pygments installed successfully!
    ) else (
        echo Pygments is already installed.
    )
    echo.
    echo ================================================
    echo  Setup complete! All dependencies installed.
    echo.
    echo Next steps:
    echo   1. Organize your code in library\
    echo   2. Run: scripts\run.bat
    echo   3. View: output\main.pdf
    echo.
    echo See README.md for more information.
    echo ================================================
    echo.
    pause
    exit /b 0
)

REM Need to install something
echo Installation Required
echo ================================================
echo.

if %PYTHON_EXISTS% equ 0 (
    echo Python is required but not installed.
    echo.
    echo Please install Python 3:
    echo   1. Visit https://www.python.org/downloads/
    echo   2. Download Python 3.x for Windows
    echo   3. During installation, CHECK "Add Python to PATH"
    echo   4. Complete the installation
    echo   5. Restart this script
    echo.
)

if %XELATEX_EXISTS% equ 0 (
    echo XeLaTeX is required but not installed.
    echo.
    echo Please install MiKTeX:
    echo   1. Visit https://miktex.org/download
    echo   2. Download MiKTeX for Windows
    echo   3. Run the installer and follow the instructions
    echo   4. During installation, select "Install missing packages automatically"
    echo   5. Complete the installation
    echo   6. Restart this script
    echo.
)

echo ================================================
echo.

REM If Python exists but XeLaTeX doesn't, offer to install Pygments
if %PYTHON_EXISTS% equ 1 if %XELATEX_EXISTS% equ 0 (
    echo Python is installed. Do you want to install Pygments now?
    echo (You can do this later after installing XeLaTeX^)
    echo.
    set /p INSTALL_PYGMENTS="Install Pygments? (y/n): "
    if /i "!INSTALL_PYGMENTS!" equ "y" (
        echo.
        echo Installing Pygments...
        pip install pygments
        if errorlevel 1 (
            echo.
            echo Error: Failed to install Pygments
            echo Please try manually later: pip install pygments
        ) else (
            echo Pygments installed successfully!
        )
    )
    echo.
)

echo Please install the missing dependencies and run this script again.
echo.
pause
