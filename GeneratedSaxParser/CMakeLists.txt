PROJECT(GeneratedSaxParser)


SET(libGeneratedSaxParser_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libGeneratedSaxParser_include_dirs ${libGeneratedSaxParser_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libGeneratedSaxParser_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libGeneratedSaxParser_src_files 
	${libGeneratedSaxParser_src_dirs}/*.cpp
	${libGeneratedSaxParser_src_dirs}/*.h
)

SET(libGeneratedSaxParser_libs
	OpenCOLLADABaseUtils
)

IF (USE_LIBXML)
	file(REMOVE libGeneratedSaxParser_src_files 
		${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserExpatSaxParser.cpp
	)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBXML2_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBXML2_LIBRARIES})
ENDIF (USE_LIBXML)

IF (USE_EXPAT)
	file(REMOVE libGeneratedSaxParser_src_files 
		${libGeneratedSaxParser_src_dirs}/GeneratedSaxParserLibxmlSaxParser.cpp
	)
	LIST(APPEND libGeneratedSaxParser_include_dirs ${LIBEXPAT_INCLUDE_DIR})
	LIST(APPEND libGeneratedSaxParser_libs ${LIBEXPAT_LIBRARIES})
ENDIF (USE_EXPAT)

INCLUDE_DIRECTORIES(${libGeneratedSaxParser_include_dirs} ${libBaseUtils_include_dirs})
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(GeneratedSaxParser ${libGeneratedSaxParser_src_files})
TARGET_LINK_LIBRARIES(GeneratedSaxParser ${libGeneratedSaxParser_libs})
