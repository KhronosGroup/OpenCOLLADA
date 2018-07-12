/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_LINESTRIPS_H__
#define __COLLADAFW_LINESTRIPS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class Linestrips : public MeshPrimitiveWithFaceVertexCount<unsigned int>
		{
	private:
		/** The number of line strips.*/
		size_t mLinestripCount;

	public:

        /** Constructor. */
		Linestrips(const UniqueId& uniqueId) : MeshPrimitiveWithFaceVertexCount<unsigned int>( uniqueId, LINE_STRIPS), mLinestripCount(0){}

        /** Destructor. */
		virtual ~Linestrips(){}

		/** Gets the number of line strips.*/
		size_t getLinestripCount () const { return mLinestripCount; }

		/** Sets the number of line strips.*/
		void setLinestripCount ( size_t count ) { mLinestripCount = count; }

	private:

        /** Disable default copy ctor. */
		Linestrips( const Linestrips& pre );

        /** Disable default assignment operator. */
		const Linestrips& operator= ( const Linestrips& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_LINESTRIPS_H__
