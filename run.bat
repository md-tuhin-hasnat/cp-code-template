@echo off
REM CP Library Generator - Complete Workflow (Windows)
setlocal enabledelayedexpansion

echo.
echo ================================================
echo  CP Library Generator - Complete Workflow
echo ================================================
echo.

REM Check dependencies
echo Checking dependencies...
python --version >nul 2>&1
if errorlevel 1 (
    echo Error: Python is required but not installed.
    exit /b 1
)

xelatex --version >nul 2>&1
if errorlevel 1 (
    echo Error: XeLaTeX is required but not installed.
    exit /b 1
)
echo All dependencies found
echo.

REM Step 1: Generate content.tex and team_info.tex
echo Step 1: Generating content.tex from library/...
echo.
python src\main.py
if errorlevel 1 (
    echo Content generation failed
    exit /b 1
)
echo.
echo content.tex generated successfully
echo.

REM Step 2: Copy template and compile PDF
echo Step 2: Compiling PDF with XeLaTeX...
copy templates\main.tex . >nul
xelatex -shell-escape -output-directory=output main.tex >nul 2>&1
if errorlevel 1 (
    echo First XeLaTeX pass failed
    exit /b 1
)

echo    Running second pass for TOC...
xelatex -shell-escape -output-directory=output main.tex >nul 2>&1
if errorlevel 1 (
    echo Second XeLaTeX pass failed
    exit /b 1
)

echo PDF compiled successfully
echo.

REM Step 3: Clean up auxiliary files
echo Cleaning up auxiliary files...
del main.aux main.log main.out main.toc main.tex 2>nul
for %%F in (output\*) do (
    if /i not "%%~xF"==".pdf" if /i not "%%~xF"==".tex" del "%%F" 2>nul
)
echo    Cleaned up
echo.

echo ================================================
echo  Complete! Your PDF is ready.
echo.
echo  Output: output\main.pdf
for %%A in (output\main.pdf) do echo  Size: %%~zA bytes
echo.
echo To view:
echo   - Windows: start output\main.pdf
echo.
echo To regenerate:
echo   1. Edit files in library\
echo   2. Run: run.bat
echo ================================================
echo.
