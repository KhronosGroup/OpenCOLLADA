PROJECT(UTF)

SET(libUTF_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

SET(libUTF_include_dirs ${libUTF_include_dirs} PARENT_SCOPE) #adding include dirs to a parent scope

SET(libUTF_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

file(GLOB_RECURSE libUTF_src_files 
	${libUTF_src_dirs}/*.c
)

SET(libUTF_libs)

INCLUDE_DIRECTORIES(
	${libUTF_include_dirs} 
)
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

ADD_LIBRARY(UTF ${libUTF_src_files})
TARGET_LINK_LIBRARIES(UTF ${libUTF_libs} 
)
