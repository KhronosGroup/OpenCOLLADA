set(name OpenCOLLADAValidator)
project(${name})

set(libValidator_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libValidator_include_dirs ${libValidator_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/main.cpp
	src/ValidationErrorHandler.cpp
	
	include/ValidationErrorHandler.h
	include/Writer.h
)

set(libValidator_libs
	OpenCOLLADASaxFrameworkLoader
	GeneratedSaxParser
	OpenCOLLADAFramework
	OpenCOLLADABaseUtils
	MathMLSolver
	${PCRE_LIBRARIES}
	${LIBXML2_LIBRARIES}
	UTF
)

if (WIN32)
    set(libValidator_libs ${libValidator_libs}
        ws2_32.lib
    )
endif ()

include_directories(
	${libValidator_include_dirs}
	${libBaseUtils_include_dirs}
	${libFramework_include_dirs}
	${libSaxFrameworkLoader_include_dirs}
	${libGeneratedSaxParser_include_dirs}
)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(${name} ${SRC})
target_link_libraries(${name} ${libValidator_libs})
add_dependencies(${name} ${CMAKE_REQUIRED_LIBRARIES})

if (NOT LIBXML2_FOUND)
	add_definitions(
		-DLIBXML_AUTOMATA_ENABLED
        -DLIBXML_HTTP_ENABLED
		-DLIBXML_PATTERN_ENABLED
		-DLIBXML_REGEXP_ENABLED
		-DLIBXML_SCHEMAS_ENABLED
		-DLIBXML_XPATH_ENABLED
		)
	if (USE_STATIC)
		add_dependencies(${name} xml_static)
	endif ()
	if (USE_SHARED)
		add_dependencies(${name} xml_shared)
	endif ()
endif ()
