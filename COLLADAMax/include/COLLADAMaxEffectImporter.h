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

#ifndef __COLLADAMAX_EFFECTIMPORTER_H__
#define __COLLADAMAX_EFFECTIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAFW
{
	class Effect;
};


namespace COLLADAMax
{

	/** Imports one effect */
	class EffectImporter : public ImporterBase 
	{
	private:
		/** The effect to import.*/
		const COLLADAFW::Effect* mEffect;
	
	public:

        /** Constructor. */
		EffectImporter(DocumentImporter* documentImporter, const COLLADAFW::Effect* effect);

        /** Destructor. */
		virtual ~EffectImporter();

		/** Performs the import of the effect.
		@return True on success, false otherwise.*/
		bool import();

	private:

        /** Disable default copy ctor. */
		EffectImporter( const EffectImporter& pre );

        /** Disable default assignment operator. */
		const EffectImporter& operator= ( const EffectImporter& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_EFFECTIMPORTER_H__
