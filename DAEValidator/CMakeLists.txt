project(DAEValidator)


# DAEValidatorLibrary

set(DAEValidatorLibrarySources
	library/src/ArgumentParser.cpp
	library/src/Dae.cpp
	library/src/DaeValidator.cpp
	library/src/Log.cpp
	library/src/DAEValidatorLibrary.cpp
	library/src/PathUtil.cpp
	library/src/Strings.cpp
	library/src/StringUtil.cpp
	library/src/Uri.cpp
	library/src/XmlAttribute.cpp
	library/src/XmlDoc.cpp
	library/src/XmlNamespace.cpp
	library/src/XmlNode.cpp
	library/src/XmlNodes.cpp
	library/src/XmlNodeSet.cpp
	library/src/XmlSchema.cpp
	
	library/include/ArgumentParser.h
	library/include/Dae.h
	library/include/DaeValidator.h
	library/include/Log.h
	library/include/Macros.h
	library/include/DAEValidatorLibrary.h
	library/include/no_warning_algorithm
	library/include/no_warning_array
	library/include/no_warning_begin
	library/include/no_warning_chrono
	library/include/no_warning_end
	library/include/no_warning_fstream
	library/include/no_warning_functional
	library/include/no_warning_iomanip
	library/include/no_warning_iostream
	library/include/no_warning_list
	library/include/no_warning_map
	library/include/no_warning_memory
	library/include/no_warning_regex
	library/include/no_warning_sstream
	library/include/no_warning_string
	library/include/no_warning_vector
	library/include/no_warning_Windows.h
	library/include/PathUtil.h
	library/include/Strings.h
	library/include/StringUtil.h
	library/include/Uri.h
	library/include/Xml.h
	library/include/XmlCommon.h
	library/include/XmlAttribute.h
	library/include/XmlDoc.h
	library/include/XmlNamespace.h
	library/include/XmlNode.h
	library/include/XmlNodes.h
	library/include/XmlNodeSet.h
	library/include/XmlSchema.h
    library/include/win/dirent.h
)
add_library(DAEValidatorLibrary ${DAEValidatorLibrarySources})
include_directories("library/include")


# DAEValidatorExecutable

set(DAEValidatorExecutableSources
	executable/src/Main.cpp
)
add_executable(DAEValidatorExecutable ${DAEValidatorExecutableSources})
add_dependencies(DAEValidatorExecutable DAEValidatorLibrary)
set(Libraries DAEValidatorLibrary)
if (NOT LIBXML2_FOUND)
    if (USE_STATIC)
        list(APPEND Libraries xml_static)
    else ()
        list(APPEND Libraries xml_shared)
    endif ()
else ()
    list(APPEND Libraries ${LIBXML2_LIBRARIES})
endif ()
if (USE_STATIC)
        list(APPEND Libraries zlib_static)
    else ()
        list(APPEND Libraries zlib_shared)
    endif ()
if (WIN32)
	list(APPEND Libraries ws2_32.lib)
endif ()
target_link_libraries(DAEValidatorExecutable ${Libraries})
set_target_properties(DAEValidatorExecutable PROPERTIES OUTPUT_NAME DAEValidator)

if (WIN32)
# C4505: 'function' : unreferenced local function has been removed
# C4514: 'function' : unreferenced inline function has been removed
# C4592: symbol will be dynamically initialized (implementation limitation)
# C4710: 'function' : function not inlined
# C4711: function 'function' selected for inline expansion
# C4820: 'bytes' bytes padding added after construct 'member_name'
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /Wall /wd4505 /wd4514 /wd4592 /wd4710 /wd4711 /wd4820")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
endif ()

add_custom_command(
	TARGET DAEValidatorExecutable POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/xsd $<TARGET_FILE_DIR:DAEValidatorExecutable>
	)

# DAEValidatorTests

macro(configure_files srcDir destDir)
    message(STATUS "Configuring directory ${srcDir} -> ${destDir}")
    make_directory(${destDir})

    file(GLOB_RECURSE templateFiles RELATIVE ${srcDir} ${srcDir}/*)
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
            message(STATUS "Configuring file ${templateFile}")
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    COPYONLY)
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
endmacro(configure_files)

if (WIN32 AND ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION} GREATER 3.0.1)
	set(DAEValidatorTestsSources
		tests/src/ArgumentParserTests.cpp
		tests/src/Common.cpp
		tests/src/DaeTests.cpp
		tests/src/DaeValidatorTests.cpp
		tests/src/DaeValidatorLibraryTests.cpp
		tests/src/LogTests.cpp
		tests/src/PathUtilTests.cpp
		tests/src/StringUtilTests.cpp
		tests/src/UriTests.cpp
		tests/src/XmlAttributeTests.cpp
		tests/src/XmlDocTests.cpp
		tests/src/XmlNamespaceTests.cpp
		tests/src/XmlNodeSetTests.cpp
		tests/src/XmlNodesTests.cpp
		tests/src/XmlNodeTests.cpp
		tests/src/XmlSchemaTests.cpp

		tests/include/Common.h
	)
	string(REGEX REPLACE "/Common7/IDE/devenv.com" "/VC" VCINSTALLDIR ${CMAKE_VS_DEVENV_COMMAND})
	link_directories(${VCINSTALLDIR}/UnitTest/lib)
	add_library(DAEValidatorTests SHARED ${DAEValidatorTestsSources})
	add_dependencies(DAEValidatorTests DAEValidatorLibrary)
	target_include_directories(DAEValidatorTests PRIVATE ${VCINSTALLDIR}/UnitTest/include tests/include)
	set(Libraries DAEValidatorLibrary)
	if (USE_STATIC)
		list(APPEND Libraries xml_static zlib_static)
	else ()
		list(APPEND Libraries xml_shared zlib_shared)
	endif ()
	if (WIN32)
		list(APPEND Libraries ws2_32.lib)
	endif ()
	target_link_libraries(DAEValidatorTests ${Libraries})
	configure_files(${CMAKE_CURRENT_SOURCE_DIR}/tests/data ${CMAKE_CURRENT_BINARY_DIR}/tests/data)
	set_target_properties(DAEValidatorTests
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests/lib
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests/lib
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests/bin
		)
	add_custom_command(
		TARGET DAEValidatorTests POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/xsd ${CMAKE_CURRENT_BINARY_DIR}/tests/bin/Debug
		)
	add_custom_command(
		TARGET DAEValidatorTests POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/xsd ${CMAKE_CURRENT_BINARY_DIR}/tests/bin/Release
		)
endif ()


# Externals

# libxml
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
		add_dependencies(DAEValidatorExecutable xml_static)
	endif ()
	if (USE_SHARED)
		add_dependencies(DAEValidatorExecutable xml_shared)
	endif ()
    include_directories("../Externals/LibXML/include")
else ()
    include_directories(${LIBXML2_INCLUDE_DIR})
endif ()

# zlib
if (USE_STATIC)
	add_dependencies(DAEValidatorExecutable zlib_static)
else ()
	add_dependencies(DAEValidatorExecutable zlib_shared)
endif ()
include_directories("../Externals/zlib/include")
