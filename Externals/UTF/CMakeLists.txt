set(name UTF)
project(${name})

set(libUTF_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libUTF_include_dirs ${libUTF_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libUTF_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/ConvertUTF.c
)

set(libUTF_libs)

include_directories(
	${libUTF_include_dirs} 
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libUTF_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libUTF_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_static;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)

	install(
		TARGETS ${name}_static
		ARCHIVE DESTINATION ${OPENCOLLADA_INST_LIBRARY}
	)
endif ()

if (USE_SHARED)
	if (NOT UNIX)
		message(${name} " WARNING: Shared library support implemented for UNIX-like OS only")
	endif ()
	add_library(${name}_shared SHARED ${libUTF_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libUTF_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)

	install(
		TARGETS ${name}_shared
		LIBRARY DESTINATION ${OPENCOLLADA_INST_LIBRARY}
	)
endif ()
