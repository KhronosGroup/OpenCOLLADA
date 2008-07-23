@ECHO OFF
ECHO.

set mayaFilename=%1
set stripped=%mayaFilename:.mb=%
set daeFilename=%stripped%.dae

ECHO Creating %daeFilename% file from %mayaFilename%...
CALL COLLADAMaya.exe ./%mayaFilename% ./%daeFilename% 
IF ERRORLEVEL 1 GOTO error1

CALL coherencytest.exe ./%daeFilename%
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
