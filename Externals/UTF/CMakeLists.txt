set(name UTF)
project(${name})

set(libUTF_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SRC
	src/ConvertUTF.c

	include/ConvertUTF.h
)

set(TARGET_LIBS)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}" "${libUTF_include_dirs}" "")
