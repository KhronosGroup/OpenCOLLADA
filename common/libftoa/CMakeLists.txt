set(name ftoa)
project(${name})

set(libftoa_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libftoa_include_dirs ${libftoa_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libftoa_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/src/
)

set(libftoa_src_files 
	${libftoa_src_dirs}/Commondtoa.cpp
	${libftoa_src_dirs}/Commonftoa.cpp
	${libftoa_src_dirs}/Commonitoa.cpp
)

set(libftoa_libs)

include_directories(
	${libftoa_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libftoa_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libftoa_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libftoa_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libftoa_libs}) 
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
endif ()
