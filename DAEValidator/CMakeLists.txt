set(name DAEValidator)
project(${name})

set(libValidator_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libValidator_include_dirs ${libValidator_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

# Creates C resources file from files in given directory
function(create_resources dir output)
    # Create empty output file
    file(WRITE ${output} "namespace opencollada {\n")
    # Collect input files
    file(GLOB bins ${dir}/*)
    # Iterate through input files
    foreach(bin ${bins})
        # Get short filename
        string(REGEX MATCH "([^/]+)$" filename ${bin})
        # Replace filename spaces & extension separator for C compatibility
        string(REGEX REPLACE "\\.| |-" "_" filename ${filename})
        # Read hex data from file
        file(READ ${bin} filedata HEX)
        # Convert hex data for C compatibility
        string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1," filedata ${filedata})
		# Split string into lines of 16 values to make text editors more responsive when opening generated file.
		# Regex expression should be ([^,]+[,]){1,16} but cmake does not support brace quantifier.
		string(REGEX REPLACE "([^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,][^,]+[,])" "\\1\n" filedata ${filedata})
        # Append data to output file
        file(APPEND ${output} "unsigned char ${filename}[] = {${filedata}0x00};\nsize_t ${filename}_size = sizeof(${filename});\n")
    endforeach()
	file(APPEND ${output} "}\n")
endfunction()

# Embed official collada xsd files into executable
create_resources("res" "src/Resources.cpp")

set(SRC
	src/ArgumentParser.cpp
	src/Dae.cpp
	src/DaeValidator.cpp
	src/main.cpp
	src/XmlAttribute.cpp
	src/XmlDoc.cpp
	src/XmlNamespace.cpp
	src/XmlNode.cpp
	src/XmlNodes.cpp
	src/XmlNodeSet.cpp
	src/XmlSchema.cpp
	src/Resources.cpp
	
	include/ArgumentParser.h
	include/Dae.h
	include/DaeValidator.h
	include/Xml.h
	include/XmlCommon.h
	include/XmlAttribute.h
	include/XmlDoc.h
	include/XmlNamespace.h
	include/XmlNode.h
	include/XmlNodes.h
	include/XmlNodeSet.h
	include/XmlSchema.h
)

set(libValidator_libs
	OpenCOLLADABaseUtils
	OpenCOLLADAStreamWriter
	${LIBXML2_LIBRARIES}
	UTF
	${PCRE_LIBRARIES}
)

if (WIN32)
    set(libValidator_libs ${libValidator_libs}
        ws2_32.lib
    )
endif ()

include_directories(
	${libBaseUtils_include_dirs}
	${libStreamWriter_include_dirs}
	${libValidator_include_dirs}
	${LIBXML2_INCLUDE_DIR}
)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(${name} ${SRC})
target_link_libraries(${name} ${libValidator_libs})

if (NOT LIBXML2_FOUND)
	add_definitions(
		-DLIBXML_AUTOMATA_ENABLED
        -DLIBXML_HTTP_ENABLED
		-DLIBXML_PATTERN_ENABLED
		-DLIBXML_REGEXP_ENABLED
		-DLIBXML_SCHEMAS_ENABLED
		-DLIBXML_XPATH_ENABLED
		)
	if (USE_STATIC)
		add_dependencies(${name} xml_static)
	endif ()
	if (USE_SHARED)
		add_dependencies(${name} xml_shared)
	endif ()
endif ()

add_dependencies(${name} ${CMAKE_REQUIRED_LIBRARIES})

if (NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -stdlib=libc++")
endif ()

file(GLOB xsds *.xsd)
message("Copying " ${xsds} " to " ${PROJECT_BINARY_DIR})
file(INSTALL ${xsds} DESTINATION ${PROJECT_BINARY_DIR})
