
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	if(NOT DEFINED WITH_IN_SOURCE_BUILD)
		message(FATAL_ERROR
			"CMake generation for OpenCollada is not allowed within the source directory!"
			"\n Remove the CMakeCache.txt file and try again from another folder, e.g.:"
			"\n "
			"\n rm CMakeCache.txt"
			"\n cd .."
			"\n mkdir cmake-make"
			"\n cd cmake-make"
			"\n cmake ../opencollada"
			"\n "
			"\n Alternately define WITH_IN_SOURCE_BUILD to force this option (not recommended!)"
		)
	endif()
endif()

cmake_minimum_required(VERSION 2.6)


#-----------------------------------------------------------------------------
# Set policy.

# see "cmake --help-policy CMP0003"
# So library linking is more sane
cmake_policy(SET CMP0003 NEW)

# So defines are automatically quoted
cmake_policy(SET CMP0005 NEW)

# So syntax problems are errors
cmake_policy(SET CMP0010 NEW)

# Input directories must have CMakeLists.txt
cmake_policy(SET CMP0014 NEW)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Externals/cmake-modules")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Only do Release and Debug" FORCE )
mark_as_advanced(CMAKE_CONFIGURATION_TYPES)


#-----------------------------------------------------------------------------
# Initialize project.

project(OPENCOLLADA)  # must be after setting cmake_configuration_types

# defines where specific parts of BRICS_MM are stored or created
set(LIBRARY_OUTPUT_PATH            ${CMAKE_HOME_DIRECTORY}/lib)  # static libraries 
set(EXECUTABLE_OUTPUT_PATH         ${CMAKE_HOME_DIRECTORY}/bin)  # executables 
set(EXTERNAL_LIBRARIES        	   ${CMAKE_HOME_DIRECTORY}/Externals)  # external libraries
set(CMAKE_MODULE_PATH "${EXTERNAL_LIBRARIES}/cmake-modules")

if (NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif ()


#-----------------------------------------------------------------------------
# Redirect output files

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "" FORCE )
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "" FORCE )


#-----------------------------------------------------------------------------
# Set default config options

option(USE_STATIC "Build static libraries"  ON)
option(USE_SHARED "Build shared libraries"  OFF)
option(USE_LIBXML "Use LibXml2 parser"      ON)
option(USE_EXPAT  "Use expat parser"        OFF)

#adding xml2
if (USE_LIBXML)
	add_definitions(
		-DGENERATEDSAXPARSER_XMLPARSER_LIBXML
		-DXMLPARSER_LIBXML
	)
	find_package(LibXml2)
	if (LIBXML2_FOUND)
		message(STATUS "SUCCESSFUL: LibXml2 found")
	else ()  # if xml2 not found building its local copy from ./Externals
		if (WIN32)
			message("WARNING: Native LibXml2 not found, taking LibXml from ./Externals")
			add_subdirectory(${EXTERNAL_LIBRARIES}/LibXML)
			set(LIBXML2_INCLUDE_DIR
				${libxml_include_dirs}				
			)
			set(LIBXML2_LIBRARIES xml)
		else ()
			message("ERROR: LibXml2 not found, please install xml2 library (for Debian libxml2-dev)")
		endif ()
	endif ()
endif ()

if (USE_EXPAT)
	add_definitions(-DGENERATEDSAXPARSER_XMLPARSER_EXPAT)
	message("FATAL: EXPAT support not implemented")
	# TODO:: use externals
endif ()

#adding PCRE
find_package(PCRE)
if (PCRE_FOUND)
	message(STATUS "SUCCESSFUL: PCRE found")
else ()  # if pcre not found building its local copy from ./Externals
	if (WIN32)
		message("WARNING: Native PCRE not found, taking PCRE from ./Externals")
		add_definitions(-DPCRE_STATIC)
		add_subdirectory(${EXTERNAL_LIBRARIES}/pcre)
		set(PCRE_INCLUDE_DIR ${libpcre_include_dirs})
		set(PCRE_LIBRARIES pcre)
	else ()
		message("ERROR: PCRE not found, please install pcre library")
	endif ()
endif ()

# building required libs
add_subdirectory(common/libftoa)
add_subdirectory(common/libBuffer)	
add_subdirectory(${EXTERNAL_LIBRARIES}/UTF)
add_subdirectory(${EXTERNAL_LIBRARIES}/MathMLSolver)

# building OpenCOLLADA libs
add_subdirectory(COLLADABaseUtils)
add_subdirectory(COLLADAFramework)
add_subdirectory(GeneratedSaxParser)
add_subdirectory(COLLADASaxFrameworkLoader)
add_subdirectory(COLLADAStreamWriter)

# building COLLADAValidator app
add_subdirectory(COLLADAValidator)
