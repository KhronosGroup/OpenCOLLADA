set(name pcre)
project(${name})

set(libpcre_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libpcre_include_dirs ${libpcre_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libpcre_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libpcre_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_chartables.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_compile.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_exec.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_globals.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_newline.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_tables.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/pcre_try_flipped.c
)

set(libpcre_libs)

include_directories(
	${libpcre_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_library(${name} ${libpcre_src_files})
target_link_libraries(${name} ${libpcre_libs})
set(CMAKE_REQUIRED_LIBRARIES "${name};${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)