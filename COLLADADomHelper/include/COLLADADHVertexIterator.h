/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef _COLLADA_VERTEXITERATOR_H_
#define _COLLADA_VERTEXITERATOR_H_

#include "COLLADADHShapeIterator.h"

namespace COLLADADH
{
	/** Iterates over the vertices element in COLLADA an retrieves the corresponding point.
	*/
	class VertexIterator : public ShapeIterator
	{
		enum Order
        {
            OTHER = 0x00,
            POINT = 0x01,
        };
	public:
		VertexIterator( const domVertices& vertexElement );
		virtual ~VertexIterator();
		/** Checks if there are already vertices.
		*/
		virtual bool more();

	protected:
		const domVertices &mVertexElement;
		domSource* positions;
		std::vector<Order> mOrder;
		size_t mCurrentIndex;
	};
};

#endif // _COLLADA_VERTEXITERATOR_H_
