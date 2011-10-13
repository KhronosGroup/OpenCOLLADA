set(name OpenCOLLADABaseUtils)
project(${name})

set(libBaseUtils_include_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math
)

set(libBaseUtils_include_dirs ${libBaseUtils_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/COLLADABUUtils.cpp
	src/COLLADABUURI.cpp
	src/COLLADABUPrecompiledHeaders.cpp
	src/COLLADABUPcreCompiledPattern.cpp
	src/COLLADABUIDList.cpp
	src/COLLADABUStringUtils.cpp
	src/COLLADABUHashFunctions.cpp
	src/COLLADABUNativeString.cpp

	src/Math/COLLADABUMathMatrix3.cpp
	src/Math/COLLADABUMathVector3.cpp
	src/Math/COLLADABUMathUtils.cpp
	src/Math/COLLADABUMathQuaternion.cpp
	src/Math/COLLADABUMathMatrix4.cpp
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

opencollada_add_lib(${name} "${SRC}" "${libBaseUtils_libs}")
