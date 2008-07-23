@ECHO OFF
ECHO.
ECHO Test all Maya files for COLLADAMaya exporter.

FOR %%G IN (*.mb) DO CALL testFile.bat %%G
ECHO.

ECHO COLLADAMaya has finished.
ECHO.

