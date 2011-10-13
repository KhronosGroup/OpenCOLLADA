set(name UTF)
project(${name})

set(libUTF_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libUTF_include_dirs ${libUTF_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/ConvertUTF.c
)

set(libUTF_libs)

include_directories(
	${libUTF_include_dirs} 
)

opencollada_add_lib(${name} "${SRC}" "${libUTF_libs}")
