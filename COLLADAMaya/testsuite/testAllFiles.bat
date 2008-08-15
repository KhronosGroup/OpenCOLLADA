@ECHO OFF
ECHO.
ECHO Test all Maya files for COLLADAMaya exporter.

if EXIST .\*.log DEL /S .\*.log
REM if EXIST .\*.dae DEL /S .\*.dae
if EXIST .\*.out DEL /S .\*.out

REM Recursive call
FOR /R %%G IN (*.mb) DO CALL testFile.bat %%G
FOR /R %%G IN (*.ma) DO CALL testFile.bat %%G
REM FOR %%G IN (*.mb) DO CALL testFile.bat %%G
ECHO.

ECHO COLLADAMaya has finished.
ECHO.

