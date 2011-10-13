set(name GeneratedSaxParser)
project(${name})

set(libGeneratedSaxParser_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libGeneratedSaxParser_include_dirs ${libGeneratedSaxParser_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

set(libGeneratedSaxParser_src_files 
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserCoutErrorHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserNamespaceStack.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserParser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserParserError.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserParserTemplateBase.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserParserTemplate.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserRawUnknownElementHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserSaxParser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserStackMemoryManager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserUtils.cpp
)

set(libGeneratedSaxParser_libs
	OpenCOLLADABaseUtils
)

if (USE_LIBXML)
	list(APPEND libGeneratedSaxParser_src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserLibxmlSaxParser.cpp)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	list(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
endif ()

if (USE_EXPAT)
	list(APPEND libGeneratedSaxParser_src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/GeneratedSaxParserExpatSaxParser.cpp)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	list(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
endif ()

include_directories(
	${libGeneratedSaxParser_include_dirs}
	${libBaseUtils_include_dirs}
)

opencollada_add_lib(${name} "${libGeneratedSaxParser_src_files}" "${libGeneratedSaxParser_libs}")

