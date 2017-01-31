set(name DAEValidator)
project(${name})

set(libDAEValidator_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libDAEValidator_include_dirs ${libDAEValidator_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	src/ArgumentParser.cpp
	src/Dae.cpp
	src/DaeValidator.cpp
	src/Log.cpp
	src/main.cpp
	src/PathUtil.cpp
	src/Strings.cpp
	src/StringUtil.cpp
	src/Uri.cpp
	src/XmlAttribute.cpp
	src/XmlDoc.cpp
	src/XmlNamespace.cpp
	src/XmlNode.cpp
	src/XmlNodes.cpp
	src/XmlNodeSet.cpp
	src/XmlSchema.cpp
	
	include/ArgumentParser.h
	include/Dae.h
	include/DaeValidator.h
	include/Log.h
	include/no_warning_iostream
	include/PathUtil.h
	include/Strings.h
	include/StringUtil.h
	include/Uri.h
	include/Xml.h
	include/XmlCommon.h
	include/XmlAttribute.h
	include/XmlDoc.h
	include/XmlNamespace.h
	include/XmlNode.h
	include/XmlNodes.h
	include/XmlNodeSet.h
	include/XmlSchema.h
    include/win/dirent.h
)

set(libDAEValidator_libs
	${LIBXML2_LIBRARIES}
	zlib
)

if (WIN32)
    set(libDAEValidator_libs ${libDAEValidator_libs}
        ws2_32.lib
    )
endif ()

include_directories(
	${libDAEValidator_include_dirs}
	${LIBXML2_INCLUDE_DIR}
	${zlib_include_dirs}
)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(${name} ${SRC})
target_link_libraries(${name} ${libDAEValidator_libs})

if (NOT LIBXML2_FOUND)
	add_definitions(
		-DLIBXML_AUTOMATA_ENABLED
        -DLIBXML_HTTP_ENABLED
		-DLIBXML_PATTERN_ENABLED
		-DLIBXML_REGEXP_ENABLED
		-DLIBXML_SCHEMAS_ENABLED
		-DLIBXML_XPATH_ENABLED
		-DLIBXML_TREE_ENABLED
		)
	if (USE_STATIC)
		add_dependencies(${name} xml_static)
	endif ()
	if (USE_SHARED)
		add_dependencies(${name} xml_shared)
	endif ()
endif ()

if (USE_STATIC)
	add_dependencies(${name} zlib_static)
else ()
	add_dependencies(${name} zlib_shared)
endif ()

if (WIN32)
# C4514: 'function' : unreferenced inline function has been removed
# C4710: 'function' : function not inlined
# C4711: function 'function' selected for inline expansion
# C4820: 'bytes' bytes padding added after construct 'member_name'
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /Wall /WX /wd4514 /wd4710 /wd4711 /wd4820")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
endif ()

add_custom_command(
	TARGET ${name} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/xsd $<TARGET_FILE_DIR:${name}>
	)
