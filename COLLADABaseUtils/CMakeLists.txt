set(name OpenCOLLADABaseUtils)
project(${name})

set(libBaseUtils_include_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math
)

set(libBaseUtils_include_dirs ${libBaseUtils_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libBaseUtils_src_files
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUURI.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUPrecompiledHeaders.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUPcreCompiledPattern.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUIDList.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUStringUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUHashFunctions.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/COLLADABUNativeString.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathMatrix3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathVector3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathUtils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathQuaternion.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Math/COLLADABUMathMatrix4.cpp
)

set(libBaseUtils_libs
	UTF
	${PCRE_LIBRARIES}
)

include_directories(
	${libBaseUtils_include_dirs} 
	${libUTF_include_dirs}
	${PCRE_INCLUDE_DIR}
)
link_directories(${LIBRARY_OUTPUT_PATH})

if (USE_STATIC)
	add_library(${name}_static STATIC ${libBaseUtils_src_files})
	set_target_properties(${name}_static PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_static ${libBaseUtils_libs})
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
	add_library(${name}_shared SHARED ${libBaseUtils_src_files})
	set_target_properties(${name}_shared PROPERTIES OUTPUT_NAME ${name})
	target_link_libraries(${name}_shared ${libBaseUtils_libs})
	set(CMAKE_REQUIRED_LIBRARIES "${name}_shared;${CMAKE_REQUIRED_LIBRARIES}"  PARENT_SCOPE)

	install(
		TARGETS ${name}_shared
		LIBRARY DESTINATION ${OPENCOLLADA_INST_LIBRARY}
	)
endif ()



