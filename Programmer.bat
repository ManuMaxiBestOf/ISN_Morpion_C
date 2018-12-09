@echo off

set LC_ALL=fr_FR
set USB_DRIVE=%~dp0

set SYS_PATH=%USB_DRIVE%Systeme

set MINGW_BASE=%SYS_PATH%\MinGW
set MINGW=%MINGW_BASE%\bin
set MSYS=%MINGW_BASE%\msys\1.0\bin

set PATH=%MINGW%;%MSYS%;%PATH%

"%SYS_PATH%\PNotepad\PN.exe"