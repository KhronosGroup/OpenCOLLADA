/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRISTRIPS_H__
#define __COLLADAFW_TRISTRIPS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"


namespace COLLADAFW
{

	/** The Tristrips class holds an arbitrary number of tristrips.
	Data Format:
	The UIntValuesArray returned by getFaceVertexCountArray() contains the number of vertices of each tristrip.
	*/
	class Tristrips : public MeshPrimitiveWithFaceVertexCount<unsigned int>
	{
	private:

		/** The number of tristrips.*/
		size_t mTristripCount;

	public:

        /** Constructor. */
		Tristrips ( const UniqueId& uniqueId ) 
            : MeshPrimitiveWithFaceVertexCount<unsigned int>( uniqueId, TRIANGLE_STRIPS )
            , mTristripCount(0){}

        /** Destructor. */
		virtual ~Tristrips(){}

		/** Gets the number of tristrips.*/
		size_t getTristripCount () const { return mTristripCount; }

		/** Sets the number of tristrips.*/
		void setTristripCount ( size_t count ) { mTristripCount = count; }


	private:

        /** Disable default copy ctor. */
		Tristrips( const Tristrips& pre );

        /** Disable default assignment operator. */
		const Tristrips& operator= ( const Tristrips& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_TRISTRIPS_H__
