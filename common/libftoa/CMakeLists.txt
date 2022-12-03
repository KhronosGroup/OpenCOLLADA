set(name ftoa)
project(${name})

set(libftoa_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SRC
	src/Commondtoa.cpp
	src/Commonftoa.cpp
	src/Commonitoa.cpp

	include/Commondtoa.h
	include/Commonftoa.h
	include/Commonitoa.h
)

set(TARGET_LIBS)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}" "${libftoa_include_dirs}" "")
