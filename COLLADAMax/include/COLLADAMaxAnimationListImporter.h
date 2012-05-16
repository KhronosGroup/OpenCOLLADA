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

#ifndef __COLLADAMAX_ANIMATIONLISTIMPORTER_H__
#define __COLLADAMAX_ANIMATIONLISTIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

namespace COLLADAFW
{
	class AnimationList;
};

namespace COLLADAMax
{

	/** Import animation lists and store them in a document importe global map. */
	class AnimationListImporter : public ImporterBase 
	{
	private:
		/** The animationList to import.*/
		const COLLADAFW::AnimationList* mAnimationList;

	public:

		/** Constructor. */
		AnimationListImporter( DocumentImporter* documentImporter, const COLLADAFW::AnimationList* animationList );

		/** Destructor. */
		virtual ~AnimationListImporter();

		/** Performs the import of the animation list.
		@return True on success, false otherwise.*/
		bool import();

	private:

		/** Disable default copy ctor. */
		AnimationListImporter( const AnimationListImporter& pre );

		/** Disable default assignment operator. */
		const AnimationListImporter& operator= ( const AnimationListImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_ANIMATIONLISTIMPORTER_H__
