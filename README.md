COLLADAMax and COLALDAMaya are new implementation of a 3ds Max or Maya plug-ins to export scene or parts of it to a COLLADA file, released under an MIT-license. 

In contrast to other existing COLLADA exporters, these new plug-ins do not store the COLLADA document in an intermidiate data model but writes it directly to file. This leads to a dramatic reduction of memory consumption and to much better performance.

For more information about the plug-ins and how to build them, please read the README files in COLLADAMax and COLLADAMaya directories.

For information about how to build OpenCOLLADA under linux and mac OSX usings SCons, please read the BUILD file.

NOTE: The COLLADA.sln solution, contained in this directory, exists only for development purposes. To build the NextGen plug-ins, please use the solutions in the COLLADAMax and COLLADAMaya directories.

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
You may download binaires of OpenCOLLADA tools [here](OpenCOLLADA Tools).
