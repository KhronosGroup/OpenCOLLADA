/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_EXPORTSCENEGRAPH_H__
#define __COLLADAMAX_EXPORTSCENEGRAPH_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxExportNode.h"
#include "COLLADABUIDList.h"

#include <map>
#include <vector>

class INode;

namespace COLLADAMax
{

	/** Contains Information about a geometry that is used by a morph controller but is not in the scene, 
	neither hidden nor unhidden.*/
	struct  MorphControllerHelperGeometry
	{
		ExportNode* exportNode;
		MorphController* morphController;
		String controllerId;
		size_t channelBankindex;
		bool operator<(const MorphControllerHelperGeometry& rhs)const;
	};

	typedef std::vector<MorphControllerHelperGeometry> MorphControllerHelperGeometryList;
	
	/** Class to build a scene graph of all nodes that should be exported. It
     allows to store additional data for each node.*/
    class ExportSceneGraph
    {
	public:
		typedef std::map<INode*, ExportNode*> INodeExportNodeMap;

		/** Struct that holds information about a XRef scene*/
		struct XRefSceneGraph
		{
			String exportFileBaseName;                 //!< Base name of the created COLLADASW file
			ExportSceneGraph* exportSceneGraph;    //!< The export scene graph of the XRef scene file
		};

		typedef std::vector<XRefSceneGraph> XRefSceneGraphList;

    private:
        /** True if only the selection should be exported, false if the entire scene should be exported.*/
        bool mExportSelection;

        /** The root export node.*/
        ExportNode * mRootExportNode;

        /** The root INode.*/
        INode * mRootNode;

		/** The file name of the max file represented by this export scene graph.*/
		COLLADABU::URI mMaxFileUri;

		/** List of all XRef scenes below the file represented by this export scene graph*/
		XRefSceneGraphList mXRefSceneGraphList;

        /** Holds the unique ids of the nodes.*/
        COLLADABU::IDList mNodeIdList;

		/** Holds the unique file names of the exported XRef files. This is necessary if all files
		are exported into the same directory.*/
		COLLADABU::IDList& mXRefExportFileNames;

		/** Mapping between INodes and ExportNodes.*/
		INodeExportNodeMap mINodeExportNodeMap;

		/** The number nodes identified as bones in the scene graph. We use it to generate unique sids for the joint nodes.*/
		size_t mBoneCount;

		/** The base of the joint sid created by createJointSid().*/
		static const String JOINT_SID_BASE_NAME;

		/** Suffix used to build ids for helper geometries used by morphers.*/
		static const String HELPER_GEOMETRY_ID_SUFFIX;

		/** List of all helper geometries required by morph controllers. Does not work yet.*/
		MorphControllerHelperGeometryList mMorphControllerHelperGeometryList;

    public:
		ExportSceneGraph ( INode * iNode, const COLLADABU::URI& maxFileUri, COLLADABU::IDList& xRefExportFileNames );
        ~ExportSceneGraph();

        /** Creates the export scene graph.
        @a return returns true if there are nodes to export and false otherwise.*/
        bool create ( bool exportSelection );

        /** Returns the root export node.*/
        ExportNode * getRootExportNode() const
        {
            return mRootExportNode;
        }

		/** Returns the uri of the max file represented by this export scene graph.*/
		const COLLADABU::URI& getMaxFileUri() const
		{
			return mMaxFileUri;
		}

		/** Checks, if @a exportNode is the root node of the export scene graph.*/
		bool isRootExportNode(ExportNode* exportNode) { return exportNode == mRootExportNode;}

		/** Creates a unique sid for joints.*/
		String createJointSid();

		/** Returns the export node that represents @a iNode. If the node is not in the scene graph, null is returned.*/
		ExportNode * getExportNode(INode* iNode)const;

		/** Returns the id of @a morphControllerHelperGeometry.*/
		static String getMorphControllerHelperId(const MorphControllerHelperGeometry& morphControllerHelperGeometry);

		/** Returns the list of helper geometries used by morph controllers.*/
		const MorphControllerHelperGeometryList& getMorphControllerHelperGeometryList()const{return mMorphControllerHelperGeometryList;}

		/** Returns the XRefSceneGraphList of all XRef scenes.*/
		const XRefSceneGraphList& getXRefSceneGraphList() const { return mXRefSceneGraphList; }

    private:
        ExportSceneGraph ( const ExportSceneGraph & exportSceneGraph );
        ExportSceneGraph & operator= ( const ExportSceneGraph & exportSceneGraph );

        /** Creates the export scene graph.*/
        ExportNode * create ( INode *iNode, ExportNode* parent, bool& isInVisualScene );

        /** Returns true if @a iNode should be exported, false otherwise.
        The result of this member function depends on user options and on the selection status of the INode.*/
        bool isNodeInVisualScene ( INode * iNode );

		/** Recursively checks if @a exportNode references other objects and sets their isReferenced flag*/
		void findReferencedObjects(ExportNode* exportNode);

    };
}


#endif //__EXPORTSCENEGRAPH_H__
