set(name xml)
project(${name})

set(libxml_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libxml_include_dirs ${libxml_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libxml_src_dirs 
	${CMAKE_CURRENT_SOURCE_DIR}
)

set(libxml_src_files 
	${libxml_src_dirs}/c14n.c
	${libxml_src_dirs}/catalog.c
	${libxml_src_dirs}/chvalid.c
	${libxml_src_dirs}/debugXML.c
	${libxml_src_dirs}/dict.c
	${libxml_src_dirs}/DOCBparser.c
	${libxml_src_dirs}/encoding.c
	${libxml_src_dirs}/entities.c
	${libxml_src_dirs}/error.c
	${libxml_src_dirs}/legacy.c
	${libxml_src_dirs}/list.c
	${libxml_src_dirs}/nanoftp.c
	${libxml_src_dirs}/nanohttp.c
	${libxml_src_dirs}/parser.c
	${libxml_src_dirs}/parserInternals.c
	${libxml_src_dirs}/pattern.c
	${libxml_src_dirs}/globals.c
	${libxml_src_dirs}/hash.c
	${libxml_src_dirs}/HTMLparser.c
	${libxml_src_dirs}/HTMLtree.c
	${libxml_src_dirs}/SAX2.c
	${libxml_src_dirs}/SAX.c
	${libxml_src_dirs}/threads.c
	${libxml_src_dirs}/relaxng.c
	${libxml_src_dirs}/uri.c
	${libxml_src_dirs}/valid.c
	${libxml_src_dirs}/xinclude.c
	${libxml_src_dirs}/xlink.c
	${libxml_src_dirs}/xmlIO.c
	${libxml_src_dirs}/xmlmemory.c
	${libxml_src_dirs}/xmlmodule.c
	${libxml_src_dirs}/xmlreader.c
	${libxml_src_dirs}/xmlregexp.c
	${libxml_src_dirs}/xmlsave.c
	${libxml_src_dirs}/xmlstring.c
	${libxml_src_dirs}/xmlunicode.c
	${libxml_src_dirs}/xmlwriter.c
	${libxml_src_dirs}/tree.c
)

set(libxml_libs)

include_directories(
	${libxml_include_dirs}
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_library(${name} STATIC ${libxml_src_files})
set_target_properties(${name} PROPERTIES OUTPUT_NAME ${name})
target_link_libraries(${name} ${libxml_libs})
set(CMAKE_REQUIRED_LIBRARIES "${name};${CMAKE_REQUIRED_LIBRARIES}" PARENT_SCOPE)
