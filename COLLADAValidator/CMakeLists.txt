SET (name OpenCOLLADAValidator)
PROJECT(${name})

SET(libValidator_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libValidator_include_dirs ${libValidator_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libValidator_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

file(GLOB_RECURSE libValidator_src_files 
	${libValidator_src_dirs}/*.cpp
	${libValidator_src_dirs}/*.h
)

SET(libValidator_libs
	OpenCOLLADASaxFrameworkLoader	
	GeneratedSaxParser	
	OpenCOLLADAFramework	
	OpenCOLLADABaseUtils
	MathMLSolver
        ${PCRE_LIBRARIES}
	${LIBXML2_LIBRARIES}
	UTF
)

INCLUDE_DIRECTORIES(
	${libValidator_include_dirs} 
	${libBaseUtils_include_dirs} 
	${libFramework_include_dirs} 
	${libSaxFrameworkLoader_include_dirs} 
	${libGeneratedSaxParser_include_dirs}
)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_EXECUTABLE(${name} ${libValidator_src_files})
TARGET_LINK_LIBRARIES(${name} ${libValidator_libs})
ADD_DEPENDENCIES(${name} ${CMAKE_REQUIRED_LIBRARIES})