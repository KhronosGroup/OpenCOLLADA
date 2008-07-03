@echo off
REM Build script for the HTML doc

echo Creating HTML documentation
doxygen doxygen_html.cfg
move ..\doc\api\html\CPF.chm ..\doc\api

