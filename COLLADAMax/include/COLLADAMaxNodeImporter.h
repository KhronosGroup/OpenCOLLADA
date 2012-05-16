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

#ifndef __COLLADAMAX_NODEIMPORTER_H__
#define __COLLADAMAX_NODEIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

#include "COLLADAFWNode.h"

namespace COLLADAMax
{

	/** this class imports a visual scene into the max scene graph. */
	class NodeImporter : public ImporterBase
	{
	public:

		/** Constructor. */
		NodeImporter(DocumentImporter* documentImporter);

		/** Destructor. */
		virtual ~NodeImporter();

		bool NodeImporter::importNodes( const COLLADAFW::NodePointerArray& nodes );

		bool NodeImporter::importNode( const COLLADAFW::Node* node );

	private:

		/** Disable default copy ctor. */
		NodeImporter( const NodeImporter& pre );

		/** Disable default assignment operator. */
		const NodeImporter& operator= ( const NodeImporter& pre );
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_NODEIMPORTER_H__
