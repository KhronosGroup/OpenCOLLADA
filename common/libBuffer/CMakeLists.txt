set(name buffer)
project(${name})

set(libBuffer_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include

	${libUTF_include_dirs}
)

set(SRC
	src/CommonBuffer.cpp
	src/CommonCharacterBuffer.cpp
	src/CommonFWriteBufferFlusher.cpp
	src/CommonStreamBufferFlusher.cpp
	# src/CommonLogFileBufferFlusher.cpp

	include/CommonBuffer.h
	include/CommonCharacterBuffer.h
	include/CommonFWriteBufferFlusher.h
	include/CommonIBufferFlusher.h
	include/CommonLogFileBufferFlusher.h
	include/CommonStreamBufferFlusher.h
	include/performanceTest/performanceTest.h
)

set(TARGET_LIBS ftoa UTF)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}" "${libBuffer_include_dirs}" "")
