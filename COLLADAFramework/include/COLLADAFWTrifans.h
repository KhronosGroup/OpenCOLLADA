/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRIFANS_H__
#define __COLLADAFW_TRIFANS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class Trifans : public MeshPrimitiveWithFaceVertexCount<unsigned int>
		{
	private:
		/** The number of trifans.*/
		size_t mTrifanCount;


	public:

        /** Constructor. */
		Trifans ( const UniqueId& uniqueId ) 
            : MeshPrimitiveWithFaceVertexCount<unsigned int>( uniqueId, TRIANGLE_FANS )
            , mTrifanCount(0)
        {}

        /** Destructor. */
		virtual ~Trifans(){}

		/** Gets the number of trifans.*/
		size_t getTrifanCount () const { return mTrifanCount; }

		/** Sets the number of trifans.*/
		void setTrifanCount ( size_t count ) { mTrifanCount = count; }


	private:

        /** Disable default copy ctor. */
		Trifans( const Trifans& pre );

        /** Disable default assignment operator. */
		const Trifans& operator= ( const Trifans& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_TRIFANS_H__
