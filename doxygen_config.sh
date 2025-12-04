# Doxyfile pentru Snake Game
# Proiect: Snake Game
# Autor: Igor Dodan
# An: 2025

#---------------------------------------------------------------------------
# Configurare Proiect
#---------------------------------------------------------------------------
PROJECT_NAME           = "Snake Game"
PROJECT_NUMBER         = 1.0
PROJECT_BRIEF          = "Classic Snake Game implementation in C++"
OUTPUT_DIRECTORY       = docs
CREATE_SUBDIRS         = NO

#---------------------------------------------------------------------------
# Configurare Build
#---------------------------------------------------------------------------
OPTIMIZE_OUTPUT_FOR_C  = NO
OPTIMIZE_OUTPUT_JAVA   = NO

#---------------------------------------------------------------------------
# Setări Intrare
#---------------------------------------------------------------------------
INPUT                  = . Position.hpp Apple.hpp Direction.hpp Map.hpp Player.hpp Engine.hpp Renderer.hpp
FILE_PATTERNS          = *.cpp *.hpp *.h
RECURSIVE              = NO
EXCLUDE                = tests
EXCLUDE_PATTERNS       = */tests/*

#---------------------------------------------------------------------------
# Setări Extragere Cod
#---------------------------------------------------------------------------
EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES
EXTRACT_LOCAL_CLASSES  = YES

#---------------------------------------------------------------------------
# Setări Avertismente
#---------------------------------------------------------------------------
WARNINGS               = YES
WARN_IF_UNDOCUMENTED   = YES
WARN_IF_DOC_ERROR      = YES

#---------------------------------------------------------------------------
# Setări Input
#---------------------------------------------------------------------------
INPUT_ENCODING         = UTF-8
USE_MDFILE_AS_MAINPAGE = README.md

#---------------------------------------------------------------------------
# Setări HTML Output
#---------------------------------------------------------------------------
GENERATE_HTML          = YES
HTML_OUTPUT            = html
HTML_FILE_EXTENSION    = .html
HTML_COLORSTYLE_HUE    = 220
HTML_COLORSTYLE_SAT    = 100
HTML_COLORSTYLE_GAMMA  = 80

#---------------------------------------------------------------------------
# Setări LaTeX Output (opțional)
#---------------------------------------------------------------------------
GENERATE_LATEX         = NO

#---------------------------------------------------------------------------
# Setări Diagrame
#---------------------------------------------------------------------------
HAVE_DOT               = NO
CLASS_DIAGRAMS         = YES
CALL_GRAPH             = NO
CALLER_GRAPH           = NO
