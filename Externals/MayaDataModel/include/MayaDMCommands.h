/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_COMMANDS_H__
#define __MayaDM_COMMANDS_H__

namespace MayaDM
{
	/** This command parents (moves) objects under a new group, removes
	objects from an existing group, or adds/removes parents. The parent 
	command usually only operates on transforms. Using the shape flag 
	allows a shape that is specified to be directly parented under the
	given transform. This is used to instance a shape node.
	*/
	static void parent ( FILE* file, const std::string& childName, const std::string& parentName = "", 
		bool absolute = false, bool addObject = false, bool noConnections = false, 
		bool relative = false, bool removeObject = false, bool shape = false, 
		bool world = false ) 
	{
		fprintf ( file, "   parent" );

		if ( absolute ) fprintf ( file, " -a" );
		if ( addObject ) fprintf ( file, " -add" );
		if ( noConnections ) fprintf ( file, " -nc" );
		if ( relative ) fprintf ( file, " -r" );
		if ( removeObject ) fprintf ( file, " -rm" );
		if ( shape ) fprintf ( file, " -s" );
		if ( world ) fprintf ( file, " -w" );

		fprintf ( file, " \"%s\"", childName.c_str () );
		if ( strcmp ( parentName.c_str (), "" ) != 0 )
		{
			fprintf ( file, " \"%s\"", parentName.c_str () );
		}
		fprintf ( file, ";\n" );
	}
	
	/** This command parents (moves) shapes under a new group, removes
	shapes from an existing group, or adds/removes parents.
	*/
	static void parentShape ( FILE* file, const std::string& childName, const std::string& parentName = "", 
		bool absolute = false, bool addObject = false, bool noConnections = false, 
		bool relative = false, bool removeObject = false, bool world = false ) 
	{
		parent(file, childName, parentName, absolute, addObject, noConnections, relative, removeObject, true, world);
	}

//     template<typename C>
//     C setParent ( FILE* file, C& childNode, DagNode& parentNode,
//         bool absolute = false, bool addObject = false, bool noConnections = false, 
//         bool relative = false, bool removeObject = false, bool shape = false, 
//         bool world = false ) //     {
//         parent(file, childNode.getName(), parentNode.getName(), absolute, addObject, noConnections, relative, removeObject, shape, world);
//         if(addObject && !removeObject)
//         {
//             C newInstance = childNode;
//             newInstance.setParent(parentNode.getName());
//             return newInstance;
//         }
//         else if(!addObject && !removeObject)
//         {
//             childNode.setParent(parentNode.getName());
//             return childNode;
//         }
//         else if (removeObject)
//         {
//             childNode.
//         }
//         if (world)
//         {
//             childNode.setParent("");
//             return childNode;
//         }
//     }
}

#endif //__MayaDM_COMMANDS_H__
