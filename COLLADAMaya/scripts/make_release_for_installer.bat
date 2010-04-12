@echo off & setlocal 

REM set VS2008_PATH to your vs2008 installation path
REM set MAXMAYA_INSTALLER_PATH to the location of the maxmaya installer

SET DESTINATION=%MAXMAYA_INSTALLER_PATH%\ColladaMayaInstaller\bin

SET LOGFILE=release_log.txt
SET WD=%CD%

CALL "%VS2008_PATH%\VC\vcvarsall.bat"

del /Q  %WD%\%LOGFILE%



devenv ..\COLLADAMaya.sln /build "ReleasePlugin2008|x64"
copy "..\bin\win\x64\ReleasePlugin2008\COLLADAMaya.mll" %DESTINATION%\maya2008-x64 >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2008-x64 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2008-x64 >> %LOGFILE%

devenv ..\COLLADAMaya.sln /build "ReleasePlugin2008|Win32" >> %LOGFILE%
copy "..\bin\win\win32\ReleasePlugin2008\COLLADAMaya.mll" %DESTINATION%\maya2008-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\maya2008-x86\COLLADAMaya.mll >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2008-x86 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2008-x86 >> %LOGFILE%


devenv ..\COLLADAMaya.sln /build "ReleasePlugin2009|x64"
copy "..\bin\win\x64\ReleasePlugin2009\COLLADAMaya.mll" %DESTINATION%\maya2009-x64 >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2009-x64 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2009-x64 >> %LOGFILE%

devenv ..\COLLADAMaya.sln /build "ReleasePlugin2009|Win32" >> %LOGFILE%
copy "..\bin\win\win32\ReleasePlugin2009\COLLADAMaya.mll" %DESTINATION%\maya2009-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\maya2009-x86\COLLADAMaya.mll >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2009-x86 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2009-x86 >> %LOGFILE%


devenv ..\COLLADAMaya.sln /build "ReleasePlugin2010|x64"
copy "..\bin\win\x64\ReleasePlugin2010\COLLADAMaya.mll" %DESTINATION%\maya2010-x64 >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2010-x64 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2010-x64 >> %LOGFILE%

devenv ..\COLLADAMaya.sln /build "ReleasePlugin2010|Win32" >> %LOGFILE%
copy "..\bin\win\win32\ReleasePlugin2010\COLLADAMaya.mll" %DESTINATION%\maya2010-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\maya2010-x86\COLLADAMaya.mll >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2010-x86 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2010-x86 >> %LOGFILE%


devenv ..\COLLADAMaya.sln /build "ReleasePlugin2011|x64"
copy "..\bin\win\x64\ReleasePlugin2011\COLLADAMaya.mll" %DESTINATION%\maya2011-x64 >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2011-x64 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2011-x64 >> %LOGFILE%

devenv ..\COLLADAMaya.sln /build "ReleasePlugin2011|Win32" >> %LOGFILE%
copy "..\bin\win\win32\ReleasePlugin2011\COLLADAMaya.mll" %DESTINATION%\maya2011-x86 >> %LOGFILE%
%UPX_PATH%\upx.exe -9 %DESTINATION%\maya2011-x86\COLLADAMaya.mll >> %LOGFILE%
copy "openColladaExporterOpts.mel" %DESTINATION%\maya2011-x86 >> %LOGFILE%
copy "openColladaImporterOpts.mel" %DESTINATION%\maya2011-x86 >> %LOGFILE%



pause










