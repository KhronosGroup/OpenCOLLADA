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
		fprintf ( file, "parent" );

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

    /**
    * This command is used to put objects onto or off of the active list. 
    * If none of the five flags [-add, -af, -r, -d, -tgl] are specified, the default is to replace 
    * the objects on the active list with the given list of objects. When selecting a set as in 
    * "select set1", the behaviour is for all the members of the set to become selected instead of 
    * the set itself. If you want to select a set, the "-ne/noExpand" flag must be used. With the 
    * advent of namespaces, selection by name may be confusing. To clarify, without a qualified 
    * namespace, name lookup is limited to objects in the root namespace ":". 
    * There are really two parts of a name: the namespace and the name itself which is unique 
    * within the namespace. If you want to select objects in a specific namespace, you need to 
    * include the namespace separator ":". For example, 'select -r "foo*"' is trying to look for 
    * an object with the "foo" prefix in the root namespace. It is not trying to look for all 
    * objects in the namespace with the "foo" prefix. If you want to select all objects in a 
    * namespace (foo), use 'select "foo:*"'. 
    * Note: When the application starts up, there are several dependency nodes created by the 
    * system which must exist. These objects are not deletable but are selectable. All objects 
    * (dag and dependency nodes) in the scene can be obtained using the "ls" command without any 
    * arguments. When using the "-all", "adn/allDependencyNodes" or "-ado/allDagObjects" flags, 
    * only the deletable objects are selected. The non deletable object can still be selected by 
    * explicitly specifying their name as in "select time1;". 
     * @param FILE* file
     * @param const std::string& obj
     * @param bool noExpand Indicates that any set which is among the specified items should not be 
     *          expanded to its list of members. This allows sets to be selected as opposed to the 
     *          members of sets which is the default behaviour. 
     * @return const
     */
    #define mayaSelect(file, objName, noExpand) \
    {                                           \
        fprintf(file, "select ");               \
        if ( noExpand )                         \
            fprintf(file, "-noExpand ");        \
        fprintf(file, "%s", objName.c_str());   \
        fprintf(file, ";\n");                   \
    }

}

#endif //__MayaDM_COMMANDS_H__
