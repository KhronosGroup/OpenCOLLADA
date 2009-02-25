@ECHO OFF
ECHO.

REM Only the filename 
set filename=%~n1
set filepath=%~dp1

set mayaFilename=%~nx1
set mayaFilenamePath=%~f1

set stripped=%mayaFilename:.mb=%
set daeFilename=%filename%.nextgen.dae
set daeFilenamePath=%filepath%%daeFilename%

ECHO Creating %daeFilename% file from %mayaFilename%...
CALL COLLADAMaya.exe %mayaFilenamePath% %daeFilenamePath% 
IF ERRORLEVEL 1 GOTO error1

CALL coherencytest.exe %daeFilenamePath%
IF ERRORLEVEL 1 GOTO error2
ECHO Coherencytest on %daeFilename% successful.

GOTO end

:error1
ECHO.
ECHO Something went wrong on creating %daeFilename% file from %mayaFilename%.
GOTO end

:error2
ECHO.
ECHO Something went wrong with coherencytest on %daeFilename% file.
GOTO end

:end
