set(name GeneratedSaxParser)
project(${name})

set(libGeneratedSaxParser_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libGeneratedSaxParser_include_dirs ${libGeneratedSaxParser_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

set(SRC
	src/GeneratedSaxParserCoutErrorHandler.cpp
	src/GeneratedSaxParserNamespaceStack.cpp
	src/GeneratedSaxParserParser.cpp
	src/GeneratedSaxParserParserError.cpp
	src/GeneratedSaxParserParserTemplateBase.cpp
	src/GeneratedSaxParserParserTemplate.cpp
	src/GeneratedSaxParserRawUnknownElementHandler.cpp
	src/GeneratedSaxParserSaxParser.cpp
	src/GeneratedSaxParserStackMemoryManager.cpp
	src/GeneratedSaxParserUtils.cpp
)

set(libGeneratedSaxParser_libs
	OpenCOLLADABaseUtils
)

if (USE_LIBXML)
	list(APPEND SRC src/GeneratedSaxParserLibxmlSaxParser.cpp)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	list(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
endif ()

if (USE_EXPAT)
	list(APPEND SRC src/GeneratedSaxParserExpatSaxParser.cpp)
	list(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	list(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
endif ()

include_directories(
	${libGeneratedSaxParser_include_dirs}
	${libBaseUtils_include_dirs}
)

opencollada_add_lib(${name} "${SRC}" "${libGeneratedSaxParser_libs}")

