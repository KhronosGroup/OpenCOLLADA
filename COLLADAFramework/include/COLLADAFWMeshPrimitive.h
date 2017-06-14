/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MESHPRIMITIVE_H__
#define __COLLADAFW_MESHPRIMITIVE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWConstants.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWEdge.h"
#include "COLLADAFWIndexList.h"

#include <map>
#include <vector>


namespace COLLADAFW
{

    /**
    Geometric primitives, which assemble values from the inputs into vertex attribute data. 
    Can be any combination of any primitive types in any order. 

    To describe geometric primitives that are formed from the vertex data, the <mesh> element may 
    contain zero or more of the primitive elements <lines>, <linestrips>, <polygons>, <polylist>,
    <triangles>, <trifans>, and <tristrips>.
    The <vertices> element under <mesh> is used to describe mesh-vertices. Polygons, triangles, and 
    so forth index mesh-vertices, not positions directly. Mesh-vertices must have at least one 
    <input> (unshared) element with a semantic attribute whose value is POSITION.
    For texture coordinates, COLLADA's right-handed coordinate system applies; therefore, an ST 
    texture coordinate of [0,0] maps to the lower-left texel of a texture image, when loaded in a 
    professional 2-D texture viewer/editor.
    */
    class MeshPrimitive : public ObjectTemplate<COLLADA_TYPE::PRIMITIVE_ELEMENT>
    {

    public:

        /** The types of primitives. */
	    enum PrimitiveType
	    {
		    LINES, /**< A list of lines. Only one element is contained in the face-vertex count list.
			    It represents the total number of line vertices. The total number of lines is
			    equal to half the total number of line vertices. */
		    LINE_STRIPS, /**< A list of continuous lines. Each element in the face-vertex count list
			    represents the number of consecutive line vertices before restarting. */
		    POLYGONS, /**< A list of polygons. All the polygons may be triangles.
			    This is the most common primitive type. The polygons may have holes. Each element in the
			    face-vertex count list represent the number of vertices for one polygon. */
            POLYLIST,
            TRIANGLES, 
		    TRIANGLE_FANS, /**< A list of triangle fans. Each element in the face-vertex count list
			    represents the number of vertices for one fan. A triangle fan is defined by re-using the first
			    vertex for every triangle. Advancing pairs are then used in order to generate adjacent triangles
			    such that if there are 5 vertices, then 3 triangles are created: {0,1,2}, {0,2,3} and {0,3,4}. */
		    TRIANGLE_STRIPS, /**< A list of continuous triangles. Each element in the face-vertex count list
			    represents the number of vertices for one strip. A triangle strip is defined by re-using two
			    advancing vertices from the previous triangle for the next triangle. If there are 5 vertices in 
			    the strip, then 3 triangles are created: {0,1,2}, {1,2,3}, {2,3,4}. Note that vertex winding must
			    also be taken into consideration and every even triangle in the strip has its vertices swapped
			    from the above pattern. */
		    POINTS, /**< A list of Camera-facing sprites. The face-vertex count list will contain one element that 
			    represents the total number of points. Two non-COLLADA geometry sources (POINT_SIZE and POINT_ROTATION)
			    are specific to this type. */
            UNDEFINED_PRIMITIVE_TYPE
	    };

    private:

        /** 
        * The type of the current primitive. Possible values are:
        * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. 
        */
        PrimitiveType mPrimitiveType;

        /**
        * The attribute indicates the number of polygon faces in the current primitive element.
        */
        size_t mFaceCount;

        /**
        * The material attribute declares a symbol for a material. This symbol 
        * is bound to a material at  the time of instantiation. If the material 
        * attribute is not specified then the lighting and  shading results are 
        * application defined. Optional attribute. 
        */
        String mMaterial;

		/** The material id of the sub mesh. This material id is used to assign material 
		to submeshes when the mesh gets instantiated.*/
		MaterialId mMaterialId;

		/** 
        * The index list of the positions array. 
        */
        UIntValuesArray mPositionIndices;

        /** 
        * The index list of the normals array. 
        */
        UIntValuesArray mNormalIndices;

        /** 
        * The index list of the tangent array (support of multiple uv sets). 
        */
        UIntValuesArray mTangentIndices;

        /** 
        * The index list of the binormal array (support of multiple uv sets). 
        */
        UIntValuesArray mBinormalIndices;
        

        /** 
        * The index list of the colors array  (support of multiple colors). 
        */
        IndexListArray mColorIndicesArray;

        /** 
        * The index list of the uv coordinates array (support of multiple uv sets). 
        */
        IndexListArray mUVCoordIndicesArray;

    public:	

        /**
        * Constructor.
        */
        MeshPrimitive ( const UniqueId& uniqueId );

        /**
        * Constructor.
        */
        MeshPrimitive ( const UniqueId& uniqueId, PrimitiveType primitiveType );

        /**
        * Destructor.
        */
        virtual ~MeshPrimitive();

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        const MeshPrimitive::PrimitiveType getPrimitiveType () const { return mPrimitiveType; }

        /** The type of the current primitive. Possible values are:
        <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>. */
        void setPrimitiveType ( const MeshPrimitive::PrimitiveType PrimitiveType ) { mPrimitiveType = PrimitiveType; }

        /**
        * Gets the count attribute.
        * @return Returns the count attribute.
        */
        const size_t getFaceCount () const { return mFaceCount; }

        /**
        * Sets the count attribute.
        * @param atCount The new value for the count attribute.
        */
        void setFaceCount ( const size_t count ) { mFaceCount = count; }

        /**
        * Gets the material attribute.
        * @return Returns a xsNCName of the material attribute.
        */
        String getMaterial () const { return mMaterial; }

        /**
        * Sets the material attribute.
        * @param atMaterial The new value for the material attribute.
        */
        void setMaterial ( const String& material ) { mMaterial = material; }

		/** 
		* The index list of the positions array. 
		*/
		UIntValuesArray& getPositionIndices () { return mPositionIndices; }

		/** 
		* The index list of the positions array. 
		*/
		const UIntValuesArray& getPositionIndices () const { return mPositionIndices; }

        /** 
        * The index list of the positions array. 
        */
        void setPositionIndices ( const UIntValuesArray& PositionIndices ) { mPositionIndices = PositionIndices; }

		/** 
		* The index list of the normals array. 
		*/
		UIntValuesArray& getNormalIndices () { return mNormalIndices; }

		/** 
		* The index list of the normals array. 
		*/
		const UIntValuesArray& getNormalIndices () const{ return mNormalIndices; }

        /** 
        * The index list of the normals array. 
        */
        void setNormalIndices ( const UIntValuesArray& NormalIndices ) { mNormalIndices = NormalIndices; }

		/**Returns true if the mesh primitive has normals.*/
		bool hasNormalIndices() const { return !mNormalIndices.empty(); }

        /** 
		* The index list of the normals array. 
		*/
		UIntValuesArray& getTangentIndices () { return mTangentIndices; }

		/** 
		* The index list of the normals array. 
		*/
        const UIntValuesArray& getTangentIndices () const{ return mTangentIndices; }

        /** 
        * The index list of the normals array. 
        */
        void setTagentIndices ( const UIntValuesArray& TangentIndices ) { mTangentIndices = TangentIndices; }

		/**Returns true if the mesh primitive has normals.*/
		bool hasTangentIndices() const { return !mTangentIndices.empty(); }

        		/** 
		* The index list of the normals array. 
		*/
		UIntValuesArray& getBinormalIndices () { return mBinormalIndices; }

		/** 
		* The index list of the normals array. 
		*/
		const UIntValuesArray& getBinormalIndices () const{ return mBinormalIndices; }

        /** 
        * The index list of the normals array. 
        */
        void setBinormalIndices ( const UIntValuesArray& BinormalIndices ) { mBinormalIndices = BinormalIndices; }

		/**Returns true if the mesh primitive has normals.*/
		bool hasBinormalIndices() const { return !mBinormalIndices.empty(); }

        /** 
        * The index list of the colors array. 
        */
        IndexList* getColorIndices ( size_t index ) 
        { 
            if ( index >= mColorIndicesArray.getCount () ) return 0;
            return mColorIndicesArray [ index ]; 
        }

        /** 
        * The index list of the colors array. 
        */
        const IndexList* getColorIndices ( size_t index ) const 
        { 
            if ( index >= mColorIndicesArray.getCount () ) return 0;
            return mColorIndicesArray [ index ]; 
        }

        /** 
        * The index list of the colors array. 
        */
        IndexListArray& getColorIndicesArray () { return mColorIndicesArray; }

        /** 
        * The index list of the colors array. 
        */
        const IndexListArray& getColorIndicesArray () const { return mColorIndicesArray; }

		/**Returns true if the mesh primitive has at least one set of colors.*/
		bool hasColorIndices() const { return !mColorIndicesArray.empty(); }

        /** 
        * The index list of the colors array. 
        */
        void appendColorIndices ( IndexList* colorIndices ) { mColorIndicesArray.append ( colorIndices ); }

        /** 
        * The index list of the uv coordinates array. 
        */
        IndexListArray& getUVCoordIndicesArray () { return mUVCoordIndicesArray; }

        /** 
        * The index list of the uv coordinates array. 
        */
        const IndexListArray& getUVCoordIndicesArray () const { return mUVCoordIndicesArray; }

        /** 
        * The index list of the uv coordinates array. 
        */
        IndexList* getUVCoordIndices ( size_t index )
        {
            if ( index >= mUVCoordIndicesArray.getCount () ) return 0;
            return mUVCoordIndicesArray [ index ]; 
        }

        /** 
        * The index list of the uv coordinates array. 
        */
        const IndexList* getUVCoordIndices ( size_t index ) const 
        {
            if ( index >= mUVCoordIndicesArray.getCount () ) return 0;
            return mUVCoordIndicesArray [ index ]; 
        }

        /** 
        * The index list of the uv coordinates array. 
        */
        void appendUVCoordIndices ( IndexList* uvCoordIndices ) { mUVCoordIndicesArray.append ( uvCoordIndices ); }

		/**Returns true if the mesh primitive has at least one set of uv coordinates.*/
		bool hasUVCoordIndices() const { return !mUVCoordIndicesArray.empty(); }

		/** @return The material id of the sub mesh. This material id is used to assign material 
		to submeshes when the mesh gets instantiated.*/
		MaterialId getMaterialId() const { return mMaterialId; }

		/** Sets the material id of the sub mesh. This material id is used to assign material 
		to submeshes when the mesh gets instantiated.*/
		void setMaterialId(MaterialId val) { mMaterialId = val; }
		
        /*
        * Determine the number of grouped vertex elements in the current mesh primitive.
        */
        const size_t getGroupedVertexElementsCount () const;

        /*
         *	Returns the vertex count of the face with the specified index.
         */
        const int getGroupedVerticesVertexCount ( const size_t faceIndex ) const;

    };

    
    typedef ArrayPrimitiveType<MeshPrimitive*> MeshPrimitiveArray;

}

#endif // __COLLADAFW_MESHPRIMITIVE_H__
