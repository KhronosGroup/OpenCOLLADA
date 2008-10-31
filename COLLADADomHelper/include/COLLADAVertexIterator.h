#ifndef _COLLADA_VERTEXITERATOR_H_
#define _COLLADA_VERTEXITERATOR_H_

#include "COLLADAShapeIterator.h"

namespace COLLADADomHelper
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
