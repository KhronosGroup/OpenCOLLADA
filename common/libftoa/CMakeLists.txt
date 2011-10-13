set(name ftoa)
project(${name})

set(libftoa_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libftoa_include_dirs ${libftoa_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libftoa_src_files 
	${CMAKE_CURRENT_SOURCE_DIR}/src/Commondtoa.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Commonftoa.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Commonitoa.cpp
)

set(libftoa_libs)

include_directories(
	${libftoa_include_dirs}
)

opencollada_add_lib(${name} "${libftoa_src_files}" "${libftoa_libs}")
