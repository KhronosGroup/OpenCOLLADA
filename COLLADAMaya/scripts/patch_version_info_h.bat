@echo off
REM  This script will replace undefined SHA1 with the right one into the input file


set "TEMP_FILE=temp.h"
set "INPUT_FILE=..\..\COLLADABaseUtils\include\COLLADABUVersionInfo.h"
set CURRENT_REV="CURRENT_REVISION"


REM GET GIT SHA1
FOR /f  %%A in ('git describe  --always') do set SHA=%%A


REM SEARCH FOR STRING TO CHANGED
For /f "tokens=1,2,3,4,5 delims= " %%A in (%INPUT_FILE%) do (
  if "%%C"==%CURRENT_REV% (
  set SEARCHED_STRING="%%E"
  )  
)


REM Remove both Ends // http://www.dostips.com/DtTipsStringManipulation.php#Snippets.Replace
set SEARCHED_STRING=%SEARCHED_STRING:~2,-3%


REM CHANGE THIS STRING
REM call replace.bat "%%a" %SEARCHED_STRING% %SHA% %TEMP_FILE%

for /f "delims=" %%a in (%INPUT_FILE%) do ( 
SetLocal EnableDelayedExpansion
set "line=%%a"
echo !line:%SEARCHED_STRING%=%SHA%! >> %TEMP_FILE%
EndLocal
)

REM REPLACE INPUT_FILE
copy %TEMP_FILE% %INPUT_FILE%
del %TEMP_FILE%


