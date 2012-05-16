/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SEMANTIC_H__
#define __COLLADAFW_SEMANTIC_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** 
    Provides metainformation that describes the purpose of a parameter declaration.
    
    Semantics describe the intention or purpose of a parameter declaration in an effect, using an 
    overloaded concept. Semantics have been used historically to describe three different type of 
    metainformation:
    • A hardware resource allocated to a parameter, for example, TEXCOORD2, NORMAL.
    • A value from the scene graph or graphics API that is being represented by this parameter, for
    example, MODELVIEWMATRIX, CAMERAPOS, VIEWPORTSIZE.
    • A user-defined value that will be set by the application at run time when the effect is being 
    initialized, for example, DAMAGE_PERCENT, MAGIC_LEVEL.
    Semantics are used by the <instance_geometry> declaration inside <node> to bind effect 
    parameters to values and data sources that can be found in the scene graph, using the 
    <bind_material> mechanism used to disambiguate this mapping.
    */
	class Semantic 	
    {
	private:
	
        /** There is currently no standard set of semantics. This element can contain any 
        xs:NCName defined by your application. */
        String mValue;

	public:

        /** Constructor. */
        Semantic() {}

        /** Destructor. */
        virtual ~Semantic() {}

        /** There is currently no standard set of semantics. This element can contain any 
        xs:NCName defined by your application. */
        const String getValue () const { return mValue; }

        /** There is currently no standard set of semantics. This element can contain any 
        xs:NCName defined by your application. */
        void setValue ( const String Value ) { mValue = Value; }

	private:

        /** Disable default copy ctor. */
		Semantic( const Semantic& pre );

        /** Disable default assignment operator. */
		const Semantic& operator= ( const Semantic& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SEMANTIC_H__
