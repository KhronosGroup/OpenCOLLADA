set(name GeneratedSaxParser)
project(${name})

set(libGeneratedSaxParser_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libGeneratedSaxParser_include_dirs ${libGeneratedSaxParser_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope



# GeneratedSaxParser
set(INST_SRC
	include/GeneratedSaxParser.h
	include/GeneratedSaxParserCoutErrorHandler.h
	include/GeneratedSaxParserExpatSaxParser.h
	include/GeneratedSaxParserIErrorHandler.h
	include/GeneratedSaxParserINamespaceHandler.h
	include/GeneratedSaxParserIUnknownElementHandler.h
	include/GeneratedSaxParserLibxmlSaxParser.h
	include/GeneratedSaxParserNamespaceStack.h
	include/GeneratedSaxParserParser.h
	include/GeneratedSaxParserParserError.h
	include/GeneratedSaxParserParserTemplate.h
	include/GeneratedSaxParserParserTemplateBase.h
	include/GeneratedSaxParserPrerequisites.h
	include/GeneratedSaxParserRawUnknownElementHandler.h
	include/GeneratedSaxParserSaxParser.h
	include/GeneratedSaxParserStackMemoryManager.h
	include/GeneratedSaxParserTypes.h
	include/GeneratedSaxParserUtils.h
)

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

    ${INST_SRC}
)

set(TARGET_LIBS
	OpenCOLLADABaseUtils
)

if (USE_LIBXML)
	list(APPEND SRC
		src/GeneratedSaxParserLibxmlSaxParser.cpp
	)
	list(APPEND libGeneratedSaxParser_include_dirs
		${LIBXML2_INCLUDE_DIR}
	)
	list(APPEND TARGET_LIBS
		${LIBXML2_LIBRARIES}
	)
endif ()

if (USE_EXPAT)
	list(APPEND SRC
		src/GeneratedSaxParserExpatSaxParser.cpp
	)
	list(APPEND libGeneratedSaxParser_include_dirs
		${LIBEXPAT_INCLUDE_DIR}
	)
	list(APPEND TARGET_LIBS
		${LIBEXPAT_LIBRARIES}
	)
endif ()

include_directories(
	${libGeneratedSaxParser_include_dirs}
	${libBaseUtils_include_dirs}
)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")

install(
	FILES ${INST_SRC}
	DESTINATION ${OPENCOLLADA_INST_INCLUDE}/GeneratedSaxParser
)
