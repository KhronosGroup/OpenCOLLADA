set(name pcre)
project(${name})

set(libpcre_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libpcre_include_dirs ${libpcre_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/pcre_chartables.c
	src/pcre_compile.c
	src/pcre_exec.c
	src/pcre_globals.c
	src/pcre_newline.c
	src/pcre_tables.c
	src/pcre_try_flipped.c
)

set(libpcre_libs)

include_directories(
	${libpcre_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_library(${name} ${SRC})
target_link_libraries(${name} ${libpcre_libs})
set(CMAKE_REQUIRED_LIBRARIES "${name};${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)