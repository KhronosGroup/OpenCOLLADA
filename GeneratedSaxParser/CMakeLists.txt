set(name GeneratedSaxParser)
project(${name})

set(libGeneratedSaxParser_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libGeneratedSaxParser_include_dirs ${libGeneratedSaxParser_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

set(libGeneratedSaxParser_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libGeneratedSaxParser_src_files 
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

set(libGeneratedSaxParser_libs
	OpenCOLLADABaseUtils
)

if (USE_LIBXML)
	LIST(APPEND libGeneratedSaxParser_src_files 
		${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserLibxmlSaxParser.cpp
	)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
endif ()

if (USE_EXPAT)
	LIST(APPEND libGeneratedSaxParser_src_files 
		${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserExpatSaxParser.cpp
	)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
endif ()

include_directories(
	${libGeneratedSaxParser_include_dirs}
	${libBaseUtils_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libGeneratedSaxParser_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libGeneratedSaxParser_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libGeneratedSaxParser_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libGeneratedSaxParser_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()
