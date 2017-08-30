Requirements:
-------------

- Autodesk 3ds Max
  To build the COLLADAMax plug-in you need to have a version of 3ds Max, including the SDK, installed.
  Supported versions are:
  3ds Max 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018

- MS Visual Studio 2015 for loading the solution 
   MS Visual Studio 2008 to compile for Max 2011/2012
   MS Visual Studio 2010 to compile for Max 2013/2014
   MS Visual Studio 2012 to compile for Max 2015/2016
   MS Visual Studio 2015 to compile for Max 2017
   MS Visual Studio 2015 update 3 with Windows SDK 10.0.10586 for Max 2018

IMPORTANT : DO NOT let visual studio convert the project files if it ask to when loading the solution.
  It is normal that the solution references different toolchains.

(optional)
- GIT comand line tool in your path. This is used by script\create_version_info_h.bat to create include\COLLADAMaxVersionInfo.h file in the COLLADAMAX prebuild


Building:
---------
Before you can start to build you need to set an environment variable that points to the MAX SDK

The variable is MAX_SDK_PATHXXXX with XXXX replaced with the version of 3DSMAX you want to build for.

For example:

MAX_SDK_PATH2012=C:\Program Files (x86)\Autodesk\3ds Max 2012\maxsdk

would be the value for a 2012 default installation. 

remember to set the variable before launching visual studio, preferably using the 

Then selet the corresponding build target in visual studio

Release or ReleaseStatic or Debug or DebugStatic for the correct version of 3DS MAX.


No longer supported:
--------------------

The following versions used to be supported by the plug-in.
But those are no longer maintained/tested. The source code still contains reference to those versions


3ds Max 7      (32bit)
3ds Max 8      (32bit)
3ds Max 9      (32bit/64bit)
3ds Max 2008   (32bit/64bit)
3ds Max 2009   (32bit/64bit)
3ds Max 2010   (32bit/64bit)
