/*
Copyright (c) 2008 NetAllied Systems GmbH

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

#ifndef __COLLADAMAX_ANIMATIONASSIGNER_H__
#define __COLLADAMAX_ANIMATIONASSIGNER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAMax
{

    /** Assigns all the controllers to the corresponding animatables. */
	class AnimationAssigner : public ImporterBase 
	{
	private:
	
	public:

        /** Constructor. */
		AnimationAssigner( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~AnimationAssigner();

		/** Performs the assignment.
		@return True on success, false otherwise.*/
		bool assign();

		/** Assigns all transformation controllers.*/
		bool assignTransformationControllers();

		bool AnimationAssigner::assignTransformationController( const COLLADAFW::Node* node, INode* iNode );

	private:

        /** Disable default copy ctor. */
		AnimationAssigner( const AnimationAssigner& pre );

        /** Disable default assignment operator. */
		const AnimationAssigner& operator= ( const AnimationAssigner& pre );
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONASSIGNER_H__
