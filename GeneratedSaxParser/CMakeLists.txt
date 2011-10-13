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
