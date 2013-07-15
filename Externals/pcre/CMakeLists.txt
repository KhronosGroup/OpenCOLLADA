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

	include/pcre.h
	include/pcre_internal.h
	include/ucp.h
)

if (WIN32)
	list(APPEND SRC
		include/config_win.h
	)
elseif (APPLE)
	list(APPEND SRC
		include/config_mac.h
	)
else ()  # *nix
	list(APPEND SRC
		include/config_linux.h
	)
endif()

set(libpcre_libs)

include_directories(
	${libpcre_include_dirs}
)

set(TARGET_LIBS)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")
