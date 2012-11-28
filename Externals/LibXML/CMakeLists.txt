set(name xml)
project(${name})

set(libxml_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_definitions( -DLIBXML_STATIC )

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
	xmlstring.c
	xmlunicode.c
	xmlwriter.c
	tree.c
)

set(libxml_libs)

include_directories(
	${libxml_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_library(${name} STATIC ${SRC})
set_target_properties(${name} PROPERTIES OUTPUT_NAME ${name})
target_link_libraries(${name} ${libxml_libs})
set(CMAKE_REQUIRED_LIBRARIES "${name};${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
