PROJECT(OpenCOLLADASaxFrameworkLoader)

SET(libSaxFrameworkLoader_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated14
	${CMAKE_CURRENT_SOURCE_DIR}/include/generated15
)

SET(libSaxFrameworkLoader_include_dirs ${libSaxFrameworkLoader_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libSaxFrameworkLoader_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libSaxFrameworkLoader_src_files 
	${libSaxFrameworkLoader_src_dirs}/*.cpp
	${libSaxFrameworkLoader_src_dirs}/*.h
)

SET(libSaxFrameworkLoader_libs
	OpenCOLLADABaseUtils
	OpenCOLLADAFramework
	GeneratedSaxParser
)

IF (USE_LIBXML)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
ENDIF (USE_LIBXML)

IF (USE_EXPAT)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
ENDIF (USE_EXPAT)

INCLUDE_DIRECTORIES(
	${libSaxFrameworkLoader_include_dirs} 
	${libMathMLSolver_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libFramework_include_dirs} 
	${libGeneratedSaxParser_include_dirs}
)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(OpenCOLLADASaxFrameworkLoader ${libSaxFrameworkLoader_src_files})
TARGET_LINK_LIBRARIES( 
	OpenCOLLADASaxFrameworkLoader ${libSaxFrameworkLoader_libs} 
)
