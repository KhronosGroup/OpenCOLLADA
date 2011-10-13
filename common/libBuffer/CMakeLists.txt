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

opencollada_add_lib(${name} "${libBuffer_src_files}" "${libBuffer_libs}")
