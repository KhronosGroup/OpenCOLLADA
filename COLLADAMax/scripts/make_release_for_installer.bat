@echo off & setlocal 

SET VERSION=0.8.1.217_alpha

SET DESTINATION=%MAXMAYA_INSTALLER_PATH%\ColladaMaxInstaller\bin

SET LOGFILE=release_log.txt
SET WD=%CD%


CALL "C:\netallied\software\vs2005\VC\vcvarsall.bat"

del /Q  %WD%\%LOGFILE%



devenv ..\COLLADAMax.sln /build "Release Max8|Win32" > %LOGFILE%
copy "..\bin\win\win32\release max8\COLLADAMaxNew.dle" %DESTINATION%\max8-x86 > %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release Max9|Win32" >> %LOGFILE%
copy "..\bin\win\win32\release max9\COLLADAMaxNew.dle" %DESTINATION%\max9-x86 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release Max9|x64"
copy "..\bin\win\x64\release max9\COLLADAMaxNew.dle" %DESTINATION%\max9-x64 >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release Max2008|Win32" >> %LOGFILE%
copy "..\bin\win\win32\release max2008\COLLADAMaxNew.dle" %DESTINATION%\max2008-x86 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release Max2008|x64"
copy "..\bin\win\x64\release max2008\COLLADAMaxNew.dle" %DESTINATION%\max2008-x64 >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release Max2009|Win32" >> %LOGFILE%
copy "..\bin\win\win32\release max2009\COLLADAMaxNew.dle" %DESTINATION%\max2009-x86 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release Max2009|x64"
copy "..\bin\win\x64\release max2009\COLLADAMaxNew.dle" %DESTINATION%\max2009-x64 >> %LOGFILE%



pause










