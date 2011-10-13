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

opencollada_add_lib(${name} "${libBaseUtils_src_files}" "${libBaseUtils_libs}")
