set(name xml)
project(${name})

add_definitions(
		-DLIBXML_AUTOMATA_ENABLED
        -DLIBXML_HTTP_ENABLED
		-DLIBXML_PATTERN_ENABLED
		-DLIBXML_REGEXP_ENABLED
		-DLIBXML_SCHEMAS_ENABLED
		-DLIBXML_XPATH_ENABLED
		-DLIBXML_TREE_ENABLED
	)
	
if(USE_STATIC_MSVC_RUNTIME)
	foreach(flag CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL
			CMAKE_CXX_FLAGS_RELWITHDEBINFO CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
			CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
		if(${flag} MATCHES "/MD")
			STRING(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
		endif()
		if(${flag} MATCHES "/MDd")
			STRING(REGEX REPLACE "/MDd" "/MTd" ${flag} "${${flag}}")
		endif()
	endforeach()
endif()

set(libxml_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(libxml_include_dirs ${libxml_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(SRC
	c14n.c
	catalog.c
	chvalid.c
	debugXML.c
	dict.c
	DOCBparser.c
	encoding.c
	entities.c
	error.c
	legacy.c
	list.c
	nanoftp.c
	nanohttp.c
	parser.c
	parserInternals.c
	pattern.c
	globals.c
	hash.c
	HTMLparser.c
	HTMLtree.c
	SAX2.c
	SAX.c
	threads.c
	relaxng.c
	uri.c
	valid.c
	xinclude.c
	xlink.c
	xmlIO.c
	xmlmemory.c
	xmlmodule.c
	xmlreader.c
	xmlregexp.c
	xmlsave.c
	xmlschemas.c
	xmlschemastypes.c
	xmlstring.c
	xmlunicode.c
	xmlwriter.c
	xpath.c
	tree.c
)

set(libxml_libs)

include_directories(
	${libxml_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

set(TARGET_LIBS)

opencollada_add_lib(${name} "${SRC}" "${TARGET_LIBS}")
