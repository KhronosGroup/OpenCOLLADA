/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE23DS_CHUNKIDS_H__
#define __DAE23DS_CHUNKIDS_H__

#include "DAE23dsPrerequisites.h"


namespace DAE23ds
{

	typedef unsigned short ChunkID;


	//>------ Primary chunk

	static const ChunkID MAIN3DS        = 0x4D4D;

	//>------ Main Chunks

	static const ChunkID EDIT3DS        = 0x3D3D;  // this is the start of the editor config
	static const ChunkID MESH3DS_VERSION= 0x3D3E;  // the mesh version
	static const ChunkID KEYF3DS        = 0xB000;  // this is the start of the keyframer config
	static const ChunkID M3D3DS_VERSION = 0x0002;  // M3D_VERSION

	//>------ sub defines of EDIT3DS

	static const ChunkID EDIT_MATERIAL      = 0xAFFF;
	static const ChunkID EDIT_MASTERSCALE   = 0x0100;
	static const ChunkID EDIT_CONFIG2       = 0x3E3D;
	static const ChunkID EDIT_VIEW_P1       = 0x7012;
	static const ChunkID EDIT_VIEW_P2       = 0x7011;
	static const ChunkID EDIT_VIEW_P3       = 0x7020;
	static const ChunkID EDIT_VIEW1         = 0x7001;
	static const ChunkID EDIT_BACKGR        = 0x1200;
	static const ChunkID EDIT_AMBIENT       = 0x2100;
	static const ChunkID EDIT_OBJECT        = 0x4000;

	static const ChunkID EDIT_UNKNW01   = 0x1100;
	static const ChunkID EDIT_UNKNW02   = 0x1201;
	static const ChunkID EDIT_UNKNW03   = 0x1300;
	static const ChunkID EDIT_UNKNW04   = 0x1400;
	static const ChunkID EDIT_UNKNW05   = 0x1420;
	static const ChunkID EDIT_UNKNW06   = 0x1450;
	static const ChunkID EDIT_UNKNW07   = 0x1500;
	static const ChunkID EDIT_UNKNW08   = 0x2200;
	static const ChunkID EDIT_UNKNW09   = 0x2201;
	static const ChunkID EDIT_UNKNW10   = 0x2210;
	static const ChunkID EDIT_UNKNW11   = 0x2300;
	static const ChunkID EDIT_UNKNW12   = 0x2302; 
	static const ChunkID EDIT_UNKNW13   = 0x3000;
	static const ChunkID EDIT_UNKNW14   = 0xAFFF;

	//>------ sub defines of EDIT_OBJECT
	static const ChunkID OBJ_TRIMESH    = 0x4100;
	static const ChunkID OBJ_LIGHT      = 0x4600;
	static const ChunkID OBJ_CAMERA     = 0x4700;

	static const ChunkID OBJ_UNKNWN01   = 0x4010;
	static const ChunkID OBJ_UNKNWN02   = 0x4012; //>>---- Could be shadow

	//>------ sub defines of OBJ_CAMERA
	static const ChunkID CAM_UNKNWN01   = 0x4710; 
	static const ChunkID CAM_UNKNWN02   = 0x4720; 

	//>------ sub defines of OBJ_LIGHT
	static const ChunkID LIT_OFF        = 0x4620;
	static const ChunkID LIT_SPOT       = 0x4610;
	static const ChunkID LIT_UNKNWN01   = 0x465A;

	//>------ sub defines of OBJ_TRIMESH
	static const ChunkID TRI_VERTEXL    = 0x4110;
	static const ChunkID TRI_FACEL2     = 0x4111; 
	static const ChunkID TRI_FACEL1     = 0x4120;
	static const ChunkID TRI_FACES_MAT  = 0x4130;
	static const ChunkID TRI_SMOOTH     = 0x4150;
	static const ChunkID TRI_LOCAL      = 0x4160;
	static const ChunkID TRI_VISIBLE    = 0x4165;


	//>>------ sub defs of EDIT_MATERIAL
	static const ChunkID MATERIAL_NAME           = 0xA000;
	static const ChunkID MATERIAL_AMBIENT_COLOR  = 0xA010;
	static const ChunkID MATERIAL_DIFFUSE_COLOR  = 0xA020;
	static const ChunkID MATERIAL_SPECULAR_COLOR  = 0xA030;


	//>>------ sub defs of KEYF3DS

	static const ChunkID KEYF_CURTIME     = 0xB009;
	static const ChunkID KEYF_OBJDES      = 0xB002;
	static const ChunkID KEYF_OBJHIERARCH = 0xB010;
	static const ChunkID KEYF_NODE_ID     = 0xB030;
	static const ChunkID POS_TRACK_TAG    = 0xB020;
	static const ChunkID ROT_TRACK_TAG    = 0xB021;
	static const ChunkID SCL_TRACK_TAG    = 0xB022;
	static const ChunkID PIVOT            = 0xB013;
	static const ChunkID KEYF_HDR         = 0xB00A;
	static const ChunkID KEYF_FRAMES      = 0xB008;

	//>>------  these define the different color chunk types
	static const ChunkID COL_RGB   = 0x0010;
	static const ChunkID COL_TRU   = 0x0011;
	static const ChunkID COL_UNK   = 0x0013;

	//>>------ defines for viewport chunks

	static const ChunkID TOP            = 0x0001;
	static const ChunkID BOTTOM         = 0x0002;
	static const ChunkID LEFT           = 0x0003;
	static const ChunkID RIGHT          = 0x0004;
	static const ChunkID FRONT          = 0x0005;
	static const ChunkID BACK           = 0x0006;
	static const ChunkID USER           = 0x0007;
	static const ChunkID CAMERA         = 0x0008; // 0xFFFF is the actual code read from file
	static const ChunkID LIGHT          = 0x0009;
	static const ChunkID DISABLED       = 0x0010;
	static const ChunkID BOGUS          = 0x0011;

} // namespace DAE23ds

#endif // __DAE23DS_CHUNKIDS_H__
