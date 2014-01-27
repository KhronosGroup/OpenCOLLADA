updated OpenCOLLADA tools [here](https://github.com/KhronosGroup/OpenCOLLADA/wiki/OpenCOLLADA-Tools).  

OpenCOLLADA
-------------------

COLLADAMax and COLLADAMaya are new implementation of a 3ds Max or Maya plug-ins to export scene or parts of it to a COLLADA file, released under an MIT-license. 

In contrast to other existing COLLADA exporters, these new plug-ins do not store the COLLADA document in an intermidiate data model but writes it directly to file. This leads to a dramatic reduction of memory consumption and to much better performance.

For more information about the plug-ins and how to build them, please read the README files in COLLADAMax and COLLADAMaya directories.

For information about how to build OpenCOLLADA under linux and mac OSX usings SCons, please read the BUILD file.

NOTE: The COLLADA.sln solution, contained in this directory, exists only for development purposes. To build the NextGen plug-ins, please use the solutions in the COLLADAMax and COLLADAMaya directories.

Building with cmake
-------------------

Mac OS X *Tested with Lion and Mountain Lion*:

1. Install [cmake](http://www.cmake.org/cmake/resources/software.html) with command line links.
2. some packages are required, they can be easily installed using a terminal with [brew](http://mxcl.github.com/homebrew/) type:
 * ruby -e "$(curl -fsSL https://raw.github.com/Homebrew/homebrew/go/install)"
 * brew install pkgconfig
 * brew install pcre
4. When using recent Xcode, install the command line tools in Prereferences -> Download -> Command Line Tools. (otherwise cmake will not be able to find out what is the compiler)
5. Open Terminal
6. Within the OpenCOLLADA folder (if you want to override projects in place)
Type in a terminal:
 * cmake -G Xcode -DWITH_IN_SOURCE_BUILD=ON
 * If you don't want to override the projects, just type cmake -G Xcode OpenCOLLADA  (Assuming your current directory is OpenCOLLADA's parent directory).

You should end up with a ready to be used OPENCOLLADA.xcodeproj.

Windows
-------

1. Install [CMake](http://cmake.org/cmake/resources/software.html).
2. Create a new folder alongside this repository (not inside it), called `OpenCOLLADA-cmake`
3. `cd OpenCOLLADA-cmake`
4. `cmake ../OpenCOLLADA`
5. Open `OPENCOLLADA.sln` from the new folder, and build the default startup project, `ALL_BUILD`.

Linux *todo*
----- 

Directories
-----------
* [COLLADABaseUtils](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADABaseUtils) -- Utils used by many of the other projects
* [COLLADAFramework](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADAFramework) -- Datamodel used to load COLLADA files
* [COLLADAMax](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADAMax) -- COLLADAMax NextGen plug-in sources
* [COLLADAMaya](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADAMaya) -- COLLADAMaya NextGen plug-in sources
* [COLLADASaxFrameworkLoader](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADASaxFrameworkLoader) -- Library that loads COLLADA files in a sax like manner into the framework data model
* [COLLADAStreamWriter](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADAStreamWriter) -- COLLADAStreamWriter sources (Library to write COLLADA files) 
* [COLLADAValidator](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/COLLADAValidator) -- XML validator for COLLADA files, based on the COLLADASaxFrameworkLoader
* [dae2ogre](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/dae2ogre) -- Demo project that converts COLLADA files to OGRE meshes
* [Externals](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/Externals) -- Third party projects required to build the NextGen plug-ins    
* [GeneratedSaxParser](https://github.com/KhronosGroup/OpenCOLLADA/tree/master/GeneratedSaxParser) -- Library used to load xml files in the way used by COLLADASaxFrameworkLoader      

OpenCOLLADA Tools
You may download binaires of OpenCOLLADA tools [here](https://github.com/KhronosGroup/OpenCOLLADA/wiki/OpenCOLLADA-Tools).
