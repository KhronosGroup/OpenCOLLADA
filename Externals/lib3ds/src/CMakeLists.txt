IF(MSVC)
	ADD_DEFINITIONS(-DLIB3DS_EXPORTS)
ENDIF(MSVC)

ADD_LIBRARY(lib3ds SHARED
    lib3ds.h
    lib3ds_impl.h
    lib3ds_atmosphere.c
    lib3ds_background.c
    lib3ds_camera.c
    lib3ds_chunk.c
    lib3ds_chunktable.c
    lib3ds_file.c
    lib3ds_io.c
    lib3ds_light.c
    lib3ds_material.c
    lib3ds_math.c
    lib3ds_matrix.c
    lib3ds_mesh.c
    lib3ds_node.c
    lib3ds_quat.c
    lib3ds_shadow.c
    lib3ds_track.c
    lib3ds_util.c
    lib3ds_vector.c
    lib3ds_viewport.c
    lib3ds.rc)

IF(WIN32)
    SET_TARGET_PROPERTIES(lib3ds PROPERTIES 
        OUTPUT_NAME "lib3ds-2_0" 
        DEBUG_POSTFIX "d")
ENDIF(WIN32)

SET_TARGET_PROPERTIES(lib3ds
    PROPERTIES VERSION 2.0)
    