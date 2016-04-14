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
	optimized OpenCOLLADASaxFrameworkLoader
	optimized GeneratedSaxParser
	optimized OpenCOLLADAFramework
	optimized OpenCOLLADABaseUtils
	optimized MathMLSolver
	optimized UTF
	
	debug OpenCOLLADASaxFrameworkLoader${CMAKE_DEBUG_POSTFIX}
	debug GeneratedSaxParser${CMAKE_DEBUG_POSTFIX}
	debug OpenCOLLADAFramework${CMAKE_DEBUG_POSTFIX}
	debug OpenCOLLADABaseUtils${CMAKE_DEBUG_POSTFIX}
	debug MathMLSolver${CMAKE_DEBUG_POSTFIX}	
	debug UTF${CMAKE_DEBUG_POSTFIX}
)

if(DEFINED PCRE_LIBRARY)
    LIST(APPEND libValidator_libs
        optimized ${PCRE_LIBRARY}
        debug ${PCRE_LIBRARY}${CMAKE_DEBUG_POSTFIX}
    )
endif(DEFINED PCRE_LIBRARY)

if(DEFINED LIBXML2_LIBRARY)
    LIST(APPEND libValidator_libs
	    optimized ${LIBXML2_LIBRARY}
    	debug ${LIBXML2_LIBRARY}${CMAKE_DEBUG_POSTFIX}
    )
endif(DEFINED LIBXML2_LIBRARY)


include_directories(
	${libValidator_include_dirs}
	${libBaseUtils_include_dirs}
	${libFramework_include_dirs}
	${libSaxFrameworkLoader_include_dirs}
	${libGeneratedSaxParser_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(${name} ${SRC})

target_link_libraries(${name} ${libValidator_libs})
add_dependencies(${name} ${CMAKE_REQUIRED_LIBRARIES})
