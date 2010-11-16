SET(name OpenCOLLADASaxFrameworkLoader)
PROJECT(${name})

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
	GeneratedSaxParser
	OpenCOLLADAFramework
	MathMLSolver
      ${PCRE_LIBRARIES}
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
	${PCRE_INCLUDE_DIR}
)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libSaxFrameworkLoader_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libSaxFrameworkLoader_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libSaxFrameworkLoader_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libSaxFrameworkLoader_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)