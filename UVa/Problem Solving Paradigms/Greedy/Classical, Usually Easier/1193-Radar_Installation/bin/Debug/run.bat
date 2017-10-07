echo off
cls
chcp
radar.exe<be.txt>s.txt
type s.txt
echo.
echo -------------------------------------------------------------
echo.
fc s.txt ki.txt
pause