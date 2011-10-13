set(name buffer)
project(${name})

set(libBuffer_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/

	# TODO, this needs to be fixed but get it working first.
	# the way this variable is set its not really correct I think - campbell
	#  ${libUTF_include_dirs} # XXX, this is not available so hard code the path
	${CMAKE_CURRENT_SOURCE_DIR}/../../Externals/UTF/include
)

set(libBuffer_include_dirs ${libBuffer_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libBuffer_src_files 
	${CMAKE_CURRENT_SOURCE_DIR}/src/CommonBuffer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/CommonCharacterBuffer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/CommonFWriteBufferFlusher.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/CommonStreamBufferFlusher.cpp
)

set(libBuffer_libs ftoa)

include_directories(
	${libBuffer_include_dirs}
	${libftoa_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libBuffer_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libBuffer_libs})
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
	add_library(${name}_shared SHARED ${libBuffer_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libBuffer_libs}) 
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)

	install(
		TARGETS ${name}_shared
		LIBRARY DESTINATION ${OPENCOLLADA_INST_LIBRARY}
	)
endif ()
