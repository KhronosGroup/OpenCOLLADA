/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_WRITER_H__
#define __COLLADA_MAYA_WRITER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAFWIWriter.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWGeometry.h"


namespace COLLADAMaya
{
    class Writer : public COLLADAFW::IWriter 
	{
	private:
	
	public:

        /** Constructor. */
		Writer();

        /** Destructor. */
		virtual ~Writer();

        /** When this method is called, the writer must write the entire visual scene.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeVisualScene ( const COLLADAFW::VisualScene* visualScene );

        /** When this method is called, the writer must write the geometry.
        @return The writer should return true, if writing succeeded, false otherwise.*/
        virtual bool writeGeometry ( const COLLADAFW::Geometry* geometry );

	private:

        /** Disable default copy ctor. */
		Writer( const Writer& pre );
        
        /** Disable default assignment operator. */
		const Writer& operator= ( const Writer& pre );

	};
	
} // namespace COLLADADH

#endif // __COLLADA_MAYA_WRITER_H__
