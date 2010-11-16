SET(name GeneratedSaxParser)
PROJECT(${name})

SET(libGeneratedSaxParser_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libGeneratedSaxParser_include_dirs ${libGeneratedSaxParser_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libGeneratedSaxParser_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

SET(libGeneratedSaxParser_src_files 
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserCoutErrorHandler.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserNamespaceStack.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserParser.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserParserError.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserParserTemplateBase.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserParserTemplate.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserRawUnknownElementHandler.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserSaxParser.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserStackMemoryManager.cpp
	${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserUtils.cpp
)

SET(libGeneratedSaxParser_libs
	OpenCOLLADABaseUtils
)

IF (USE_LIBXML)
	LIST(APPEND libGeneratedSaxParser_src_files 
		${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserLibxmlSaxParser.cpp
	)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
ENDIF (USE_LIBXML)

IF (USE_EXPAT)
	LIST(APPEND libGeneratedSaxParser_src_files 
		${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserExpatSaxParser.cpp
	)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
ENDIF (USE_EXPAT)

INCLUDE_DIRECTORIES(${libGeneratedSaxParser_include_dirs} ${libBaseUtils_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

IF (USE_STATIC)
	ADD_LIBRARY(${name}_static STATIC ${libGeneratedSaxParser_src_files})
	SET_TARGET_PROPERTIES(${name}_static PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_static ${libGeneratedSaxParser_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_STATIC)

IF (USE_SHARED)
	IF (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	ENDIF (NOT UNIX)
	ADD_LIBRARY(${name}_shared SHARED ${libGeneratedSaxParser_src_files})
	SET_TARGET_PROPERTIES(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	TARGET_LINK_LIBRARIES(${name}_shared ${libGeneratedSaxParser_libs})
	SET(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
ENDIF (USE_SHARED)
