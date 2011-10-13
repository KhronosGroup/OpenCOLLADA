set(name OpenCOLLADAValidator)
project(${name})

set(libValidator_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libValidator_include_dirs ${libValidator_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libValidator_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(libValidator_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ValidationErrorHandler.cpp
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

include_directories(
	${libValidator_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libFramework_include_dirs} 
	${libSaxFrameworkLoader_include_dirs} 
	${libGeneratedSaxParser_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

ADD_EXECUTABLE(${name} ${libValidator_src_files})
target_link_libraries(${name} ${libValidator_libs})
ADD_DEPENDENCIES(${name} ${CMAKE_REQUIRED_LIBRARIES})