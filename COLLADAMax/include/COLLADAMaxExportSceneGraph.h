/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_EXPORTSCENEGRAPH_H__
#define __COLLADAMAX_EXPORTSCENEGRAPH_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxExportNode.h"
#include "COLLADAIDList.h"

#include <map>

class INode;

namespace COLLADAMax
{

    /** Class to build a scene graph of all nodes that should be exported. It
     allows to store additional data for each node.*/

    class ExportSceneGraph
    {
	public:
		typedef std::map<INode*, ExportNode*> INodeExportNodeMap;

    private:
        /** True if only the selection should be exported, false if the entire scene should be exported.*/
        bool mExportSelection;

        /** The root export node.*/
        ExportNode * mRootExportNode;

        /** The root INode.*/
        INode * mRootNode;

        /** Holds the unique ids of the nodes.*/
        COLLADA::IDList mNodeIdList;

		/** Mapping between INodes and ExportNodes.*/
		INodeExportNodeMap mINodeExportNodeMap;

		/** The number nodes identified as bones in the scene graph. We use it to generate unique sids for the joint nodes.*/
		size_t mBoneCount;

		/** The base of the joint sid created by createJointSid().*/
		static const String JOINT_SID_BASE_NAME;

    public:
        ExportSceneGraph ( INode * iNode );
        ~ExportSceneGraph()
        {}

        /** Creates the export scene graph.
        @a return returns true if there are nodes to export and false otherwise.*/
        bool create ( bool exportSelection );

        /** Returns the root export node.*/
        ExportNode * getRootExportNode() const
        {
            return mRootExportNode;
        }

		/** Creates a unique sid for joints.*/
		String createJointSid();

		/** Returns the export node that represents @a iNode. If the node is not in the scene grapf, null is returned.*/
		ExportNode * getExportNode(INode* iNode)const;

    private:
        ExportSceneGraph ( const ExportSceneGraph & exportSceneGraph );
        ExportSceneGraph & operator= ( const ExportSceneGraph & exportSceneGraph );

        /** Creates the export scene graph.*/
        ExportNode * create ( INode *iNode );

        /** Returns true if @a iNode should be exported, false otherwise.
        The result of this member function depends on user options and on the selection status of the INode.*/
        bool exportThisNode ( INode * iNode );


    };
}


#endif //__EXPORTSCENEGRAPH_H__
