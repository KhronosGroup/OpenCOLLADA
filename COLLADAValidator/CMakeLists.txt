set(name OpenCOLLADAValidator)
project(${name})

set(libValidator_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SRC
	src/main.cpp
	src/ValidationErrorHandler.cpp
	
	include/ValidationErrorHandler.h
	include/Writer.h
)

if(USE_SHARED)
	set(libValidator_libs
		OpenCOLLADASaxFrameworkLoader_shared
		GeneratedSaxParser_shared
		OpenCOLLADAFramework_shared
		OpenCOLLADABaseUtils_shared
		MathMLSolver_shared
	)
elseif(USE_STATIC)
	set(libValidator_libs
		OpenCOLLADASaxFrameworkLoader_static
		GeneratedSaxParser_static
		OpenCOLLADAFramework_static
		OpenCOLLADABaseUtils_static
		MathMLSolver_static
	)
else()
	message(FATAL_ERROR "Libraries must be static or shared")
endif()

list(APPEND libValidator_libs
	PCRE::PCRE
	LibXml2::LibXml2
	UTF
)

if (WIN32)
    set(libValidator_libs ${libValidator_libs}
        ws2_32.lib
    )
endif ()

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(${name} ${SRC})
target_link_libraries(${name} ${libValidator_libs})
target_include_directories(${name} PRIVATE
	${libValidator_include_dirs}
)

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
