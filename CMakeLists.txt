CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/cmake-modules")
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Only do Release and Debug" FORCE )
MARK_AS_ADVANCED(CMAKE_CONFIGURATION_TYPES)

PROJECT(OPENCOLLADA)      #must be after setting cmake_configuration_types

#defines where specific parts of BRICS_MM are stored or created
SET(LIBRARY_OUTPUT_PATH            ${CMAKE_HOME_DIRECTORY}/lib)  #static libraries 
SET(EXECUTABLE_OUTPUT_PATH         ${CMAKE_HOME_DIRECTORY}/bin)  #executables 
SET(EXTERNAL_LIBRARIES        	   ${CMAKE_HOME_DIRECTORY}/Externals)  #external libraries
SET(CMAKE_MODULE_PATH "${EXTERNAL_LIBRARIES}/cmake-modules")

IF (NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
ENDIF (NOT WIN32)

OPTION(USE_STATIC "Build static libraries" ON)
OPTION(USE_SHARED "Build shared libraries" OFF)
OPTION(USE_LIBXML "Use LibXml2 parser" ON)
OPTION(USE_EXPAT "Use expat parser" OFF)
#adding xml2
IF(USE_LIBXML)
	ADD_DEFINITIONS(-DGENERATEDSAXPARSER_XMLPARSER_LIBXML)
	ADD_DEFINITIONS(-DXMLPARSER_LIBXML)
	FIND_PACKAGE(LibXml2)
	IF (LIBXML2_FOUND)
		MESSAGE(STATUS "SUCCESSFUL: LibXml2 found")
	ELSE (LIBXML2_FOUND) #if xml2 not found building its local copy from ./Externals
		IF (WIN32)
			MESSAGE("WARNING: Native LibXml2 not found, taking LibXml from ./Externals")
			ADD_SUBDIRECTORY(${EXTERNAL_LIBRARIES}/LibXML)
			SET(LIBXML2_INCLUDE_DIR
			${libxml_include_dirs}				
			)
			SET(LIBXML2_LIBRARIES xml)
		ELSE (WIN32)
			MESSAGE("ERROR: LibXml2 not found, please install xml2 library (for Debian libxml2-dev)")
		ENDIF (WIN32)
	ENDIF (LIBXML2_FOUND)
ENDIF(USE_LIBXML)

IF(USE_EXPAT)
	ADD_DEFINITIONS(-DGENERATEDSAXPARSER_XMLPARSER_EXPAT)
	MESSAGE("FATAL: EXPAT support not implemented")
	#TODO:: use externals
ENDIF(USE_EXPAT)

#adding PCRE
FIND_PACKAGE(PCRE)
IF (PCRE_FOUND)
	MESSAGE(STATUS "SUCCESSFUL: PCRE found")
ELSE (PCRE_FOUND) #if pcre not found building its local copy from ./Externals
	IF (WIN32)
		MESSAGE("WARNING: Native PCRE not found, taking PCRE from ./Externals")
		ADD_DEFINITIONS(-DPCRE_STATIC)
		ADD_SUBDIRECTORY(${EXTERNAL_LIBRARIES}/pcre)
		SET(PCRE_INCLUDE_DIR
			${libpcre_include_dirs}				
		)
		SET(PCRE_LIBRARIES pcre)
	ELSE (WIN32)
		MESSAGE("ERROR: PCRE not found, please install pcre library")
	ENDIF (WIN32)
ENDIF (PCRE_FOUND)

#building required libs
ADD_SUBDIRECTORY(common/libftoa)
ADD_SUBDIRECTORY(common/libBuffer)	
ADD_SUBDIRECTORY(${EXTERNAL_LIBRARIES}/UTF)
ADD_SUBDIRECTORY(${EXTERNAL_LIBRARIES}/MathMLSolver)

#building OpenCOLLADA libs
ADD_SUBDIRECTORY(COLLADABaseUtils)
ADD_SUBDIRECTORY(COLLADAFramework)
ADD_SUBDIRECTORY(GeneratedSaxParser)
ADD_SUBDIRECTORY(COLLADASaxFrameworkLoader)
ADD_SUBDIRECTORY(COLLADAStreamWriter)

#building COLLADAValidator app
ADD_SUBDIRECTORY(COLLADAValidator)
