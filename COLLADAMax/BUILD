Requirements:
-------------

- Autodesk 3ds Max
  To build the COLLADAMax plug-in you need to have a version of 3ds Max, including the SDK, installed.
  Supported versions are:
  3ds Max 9
  3ds Max 2008
  3ds Max 2009

- boost C++ libraries
  Supported and tested versions:
  -	Boost 1.35 available at http://www.boost.org/users/download/
  -	Boost 1.36 available at http://www.boost.org/users/download/

- MS Visual Studio 2005.

- SVN comand line tool, especially svnversion  (optional)
  Available at http://subversion.tigris.org/
  svnversion must be in your path


Building:
---------
Before you can start to build you need to set three environment variables. The MAX_PATH* variable 
must be set to the installation path of the 3ds Max installation you want to use, i.e. the path  
that contains 3dsmax.exe and the MAX_SDK_PATH* variable must be set to the installation path of the 
3ds Max installation you want to use, i.e. the path hat contains, among others,  the "include"  
and "lib" directories. The complete name of the environment variable 
depends on the version of 3ds Max as listed below:

3ds Max Version  |  max environment variable   |  max sdk environment variable 
------------------------------------------------------------------------------
3ds Max 9        |  MAX_PATH9                  |  MAX_SDK_PATH9
3ds Max 2008     |  MAX_PATH2008               |  MAX_SDK_PATH2008
3ds Max 2009     |  MAX_PATH2009               |  MAX_SDK_PATH2009


The following environment variables need to be set for BOOST:

"BOOST_ROOT":                     Set to your installation path of the boost headers, i.e. the path that contains 
                                  the "include" directory.
"BOOST_LIB_PATH" (win32 only):    Set to your installation path of the boost libraries, i.e. the path that contains 
                                  all the *.lib files.
"BOOST_LIB64_PATH" (win64 only):  Set to your installation path of the boost libraries, i.e. the path that contains 
                                  all the *.lib files.


To build the plug-in open "COLLADAMax.sln" with MS Visual Studio 2005, choose the configuration 
you want to build und build the project.

If the build process succeeded the plug-in file (ColladaMaxNew.dle) is automatically copied into 
your "plugins" directory of your 3ds Max installation.

After the next start of 3ds Max the plugin is available and can be found as "NEWCOLLADA" in the 
export dialog.
