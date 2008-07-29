@ECHO OFF
ECHO.
ECHO Test all Maya files for COLLADAMaya exporter.

if EXIST .\*.log DEL .\*.log
if EXIST .\*.dae DEL .\*.dae
if EXIST .\*.out DEL .\*.out

FOR %%G IN (*.mb) DO CALL testFile.bat %%G
ECHO.

ECHO COLLADAMaya has finished.
ECHO.

