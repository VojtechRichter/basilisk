@echo off

set TARGET=basilisk

set SRC_DIR=./../src/
set SRC_FILES=%SRC_DIR%/basilisk.c %SRC_DIR%/inverted_index.c %SRC_DIR%/document.c

set BUILD_DIR=build

set CL_FLAGS=/GA /FC /Gd /Fe:%TARGET% /std:c17 /Zi /MD /nologo /utf-8

@REM set LIBS=
set LINK_FLAGS=/MACHINE:x64 /nologo

pushd %BUILD_DIR%

cl %CL_FLAGS% %SRC_FILES% /link %LINK_FLAGS%

IF /I "%1"=="run" (.\%TARGET%.exe)

popd