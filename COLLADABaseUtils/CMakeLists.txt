set(name OpenCOLLADABaseUtils)
project(${name})

set(libBaseUtils_include_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/include/Math
)

set(libBaseUtils_include_dirs ${libBaseUtils_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(INST_SRC
	include/COLLADABUIDList.h
	include/COLLADABUStableHeaders.h
	include/COLLADABUNativeString.h
	include/COLLADABUException.h
	include/COLLADABU.h
	include/COLLADABUhash_map.h
	include/COLLADABUStringUtils.h
	include/COLLADABUPrerequisites.h
	include/COLLADABUPcreCompiledPattern.h
	include/COLLADABUUtils.h
	include/COLLADABUPlatform.h
	include/COLLADABUURI.h
	include/COLLADABUHashFunctions.h
)
set(INST_MATH_SRC
	include/Math/COLLADABUMathUtils.h
	include/Math/COLLADABUMathVector3.h
	include/Math/COLLADABUMathMatrix3.h
	include/Math/COLLADABUMathMatrix4.h
	include/Math/COLLADABUMathQuaternion.h
	include/Math/COLLADABUMathPrerequisites.h
)

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

    ${INST_SRC}
    ${INST_MATH_SRC}
)

set(TARGET_LIBS
	UTF
	${PCRE_LIBRARY}
)

include_directories(
	${libBaseUtils_include_dirs} 
	${libUTF_include_dirs}
	${PCRE_INCLUDE_DIR}
)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")

install(
	FILES ${INST_SRC}
	DESTINATION ${OPENCOLLADA_INST_INCLUDE}/COLLADABaseUtils
)
install(
	FILES ${INST_MATH_SRC}
	DESTINATION ${OPENCOLLADA_INST_INCLUDE}/COLLADABaseUtils/Math
)
