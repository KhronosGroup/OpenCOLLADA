set(name zlib)
project(${name})

set(zlib_include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/include)

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

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}" "${zlib_include_dirs}" "")
