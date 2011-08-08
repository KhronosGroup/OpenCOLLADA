@echo off & setlocal 

REM set VS2008_PATH to your vs2008 installation path
REM set MAXMAYA_INSTALLER_PATH to the location of the maxmaya installer

SET DESTINATION=%MAXMAYA_INSTALLER_PATH%\ColladaMaxInstaller\bin

SET LOGFILE=release_log.txt
SET WD=%CD%

CALL "%VS2008_PATH%\VC\vcvarsall.bat"

del /Q  %WD%\%LOGFILE%



devenv ..\COLLADAMax.sln /build "Release_Max7_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max7_static\COLLADAMaxNew.dle" %DESTINATION%\max7-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max7-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max8_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max8_static\COLLADAMaxNew.dle" %DESTINATION%\max8-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max8-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max9_static|x64"
copy "..\bin\win\x64\Release_Max9_static\COLLADAMaxNew.dle" %DESTINATION%\max9-x64 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release_Max9_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max9_static\COLLADAMaxNew.dle" %DESTINATION%\max9-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max9-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max2008_static|x64"
copy "..\bin\win\x64\Release_Max2008_static\COLLADAMaxNew.dle" %DESTINATION%\max2008-x64 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release_Max2008_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max2008_static\COLLADAMaxNew.dle" %DESTINATION%\max2008-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max2008-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max2009_static|x64"
copy "..\bin\win\x64\Release_Max2009_static\COLLADAMaxNew.dle" %DESTINATION%\max2009-x64 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release_Max2009_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max2009_static\COLLADAMaxNew.dle" %DESTINATION%\max2009-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max2009-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max2010_static|x64"
copy "..\bin\win\x64\Release_Max2010_static\COLLADAMaxNew.dle" %DESTINATION%\max2010-x64 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release_Max2010_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max2010_static\COLLADAMaxNew.dle" %DESTINATION%\max2010-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max2010-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max2011_static|x64"
copy "..\bin\win\x64\Release_Max2011_static\COLLADAMaxNew.dle" %DESTINATION%\max2011-x64 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release_Max2011_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max2011_static\COLLADAMaxNew.dle" %DESTINATION%\max2011-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max2011-x86\COLLADAMaxNew.dle >> %LOGFILE%


devenv ..\COLLADAMax.sln /build "Release_Max2012_static|x64"
copy "..\bin\win\x64\Release_Max2012_static\COLLADAMaxNew.dle" %DESTINATION%\max2012-x64 >> %LOGFILE%

devenv ..\COLLADAMax.sln /build "Release_Max2012_static|Win32" >> %LOGFILE%
copy "..\bin\win\win32\Release_Max2012_static\COLLADAMaxNew.dle" %DESTINATION%\max2012-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\max2012-x86\COLLADAMaxNew.dle >> %LOGFILE%



pause










