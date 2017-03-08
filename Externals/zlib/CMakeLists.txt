set(name zlib)
project(${name})

set(zlib_include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(zlib_include_dirs ${zlib_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope
include_directories(${zlib_include_dirs})

set(SRC
	src/adler32.c
	src/compress.c
	src/crc32.c
	src/deflate.c
	src/gvmat32c.c
	src/gzio.c
	src/infback.c
	src/inffast.c
	src/inflate.c
	src/inftrees.c
	src/trees.c
	src/uncompr.c
	src/zutil.c
)

set(TARGET_LIBS)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")
