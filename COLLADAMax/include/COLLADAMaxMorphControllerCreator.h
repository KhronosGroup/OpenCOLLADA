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

#ifndef __COLLADAMAX_MORPHCONTROLLERCREATOR_H__
#define __COLLADAMAX_MORPHCONTROLLERCREATOR_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxAnimationCreator.h"

class MorphR3;

namespace COLLADAMax
{

    /** Creates all the morph controllers that have been imported by the ControllerImporter */
	class MorphControllerCreator : public AnimationCreator 
	{
	private:
		/** The derived object. References the base object and has a morp controller assigned.*/
		IDerivedObject* mDerivedObject;

		/** The max morph modifier.*/
		MorphR3* mMorphModifier;

	public:

		/** Constructor. */
		MorphControllerCreator( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~MorphControllerCreator();

		/** Performs the creation of all material.
		@return True on success, false otherwise.*/
		bool create();

	private:
        /** Disable default copy ctor. */
		MorphControllerCreator( const MorphControllerCreator& pre );

        /** Disable default assignment operator. */
		const MorphControllerCreator& operator= ( const MorphControllerCreator& pre );

		/** Creates a morph controller (modifier) using the data in @a morphController and assigns the to 
		@a referencingINode.*/
		bool createMorphController( const COLLADAFW::MorphController* morphController, INode* referencingINode );
	
		/** Sets the vertex data of the morph channel. This is required for channels that use geometries not
		instantiated in the scene.
		Heavily based on morphChannel::buildFromNode.
		@returns True on success, false if an error occurred and the vertex data could not be set.*/
		bool initializeChannelGeometry(morphChannel* channel, Object* geometryObject);

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_MORPHCONTROLLERCREATOR_H__
