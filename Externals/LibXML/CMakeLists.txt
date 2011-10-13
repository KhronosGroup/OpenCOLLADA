set(name xml)
project(${name})

set(libxml_include_dirs
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

set(libxml_include_dirs ${libxml_include_dirs} PARENT_SCOPE)  # adding include dirs to a parent scope

set(libxml_src_files 
	${CMAKE_CURRENT_SOURCE_DIR}/c14n.c
	${CMAKE_CURRENT_SOURCE_DIR}/catalog.c
	${CMAKE_CURRENT_SOURCE_DIR}/chvalid.c
	${CMAKE_CURRENT_SOURCE_DIR}/debugXML.c
	${CMAKE_CURRENT_SOURCE_DIR}/dict.c
	${CMAKE_CURRENT_SOURCE_DIR}/DOCBparser.c
	${CMAKE_CURRENT_SOURCE_DIR}/encoding.c
	${CMAKE_CURRENT_SOURCE_DIR}/entities.c
	${CMAKE_CURRENT_SOURCE_DIR}/error.c
	${CMAKE_CURRENT_SOURCE_DIR}/legacy.c
	${CMAKE_CURRENT_SOURCE_DIR}/list.c
	${CMAKE_CURRENT_SOURCE_DIR}/nanoftp.c
	${CMAKE_CURRENT_SOURCE_DIR}/nanohttp.c
	${CMAKE_CURRENT_SOURCE_DIR}/parser.c
	${CMAKE_CURRENT_SOURCE_DIR}/parserInternals.c
	${CMAKE_CURRENT_SOURCE_DIR}/pattern.c
	${CMAKE_CURRENT_SOURCE_DIR}/globals.c
	${CMAKE_CURRENT_SOURCE_DIR}/hash.c
	${CMAKE_CURRENT_SOURCE_DIR}/HTMLparser.c
	${CMAKE_CURRENT_SOURCE_DIR}/HTMLtree.c
	${CMAKE_CURRENT_SOURCE_DIR}/SAX2.c
	${CMAKE_CURRENT_SOURCE_DIR}/SAX.c
	${CMAKE_CURRENT_SOURCE_DIR}/threads.c
	${CMAKE_CURRENT_SOURCE_DIR}/relaxng.c
	${CMAKE_CURRENT_SOURCE_DIR}/uri.c
	${CMAKE_CURRENT_SOURCE_DIR}/valid.c
	${CMAKE_CURRENT_SOURCE_DIR}/xinclude.c
	${CMAKE_CURRENT_SOURCE_DIR}/xlink.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlIO.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlmemory.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlmodule.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlreader.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlregexp.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlsave.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlstring.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlunicode.c
	${CMAKE_CURRENT_SOURCE_DIR}/xmlwriter.c
	${CMAKE_CURRENT_SOURCE_DIR}/tree.c
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
