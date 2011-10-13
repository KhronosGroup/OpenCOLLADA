set(name ftoa)
project(${name})

set(libftoa_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libftoa_include_dirs ${libftoa_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/Commondtoa.cpp
	src/Commonftoa.cpp
	src/Commonitoa.cpp

	include/Commondtoa.h
	include/Commonftoa.h
	include/Commonitoa.h
)

set(TARGET_LIBS)

include_directories(
	${libftoa_include_dirs}
)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")
