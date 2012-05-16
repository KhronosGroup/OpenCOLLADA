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

#ifndef __COLLADAMAX_TEXTANGENTCALCULATOR_H__
#define __COLLADAMAX_TEXTANGENTCALCULATOR_H__

#include "COLLADAMaxPrerequisites.h"
#include "math/COLLADABUMathVector3.h"

#include "COLLADAMaxIMeshAccess.h"

#include <vector>

namespace COLLADAMax
{

    /** Calculates textangents and texbinormals for a triangle mesh */
	class TexTangentCalculator 
	{
	public:
		typedef COLLADABU::Math::Vector3 Vector3;
		typedef COLLADABU::Math::Real Real;

		struct VertexIdentifier
		{
			int positionIndex;
			int normalIndex;
			int textureIndex;
			bool operator<(const VertexIdentifier& rhs) const;
		};

		struct VertexTexTangentInfo
		{
			Vector3 tangent;
			Vector3 biTangent;
			int count;
			unsigned long index;
		};

		typedef std::map<VertexIdentifier, VertexTexTangentInfo*> VertexIdentifierVertexTexTangentInfoMap;
	

		/** List of vector3.*/
		typedef std::vector<VertexTexTangentInfo*> VertexTexTangentInfoList;

		/** List of indices.*/
		typedef std::vector<unsigned long> IndicesList;

	private:
		IMeshAccess* mMesh;

		VertexTexTangentInfoList mTexTangents;

		IndicesList mIndices;

		VertexIdentifierVertexTexTangentInfoMap mVertexIdentifierVertexTexTangentInfoMap;

		unsigned long mTexTangentsCount;

	public:

        /** Constructor. */
		TexTangentCalculator( IMeshAccess* mesh );

        /** Destructor. */
		virtual ~TexTangentCalculator();

		void calculateTriangleMeshTextangents();

		const VertexTexTangentInfoList&  getTexTangents() const { return mTexTangents; }

		void clearTexTangentData();

		const IndicesList& getIndices() const { return  mIndices; }

	private:

        /** Disable default copy ctor. */
		TexTangentCalculator( const TexTangentCalculator& pre );

        /** Disable default assignment operator. */
		const TexTangentCalculator& operator= ( const TexTangentCalculator& pre );

		void computeTangent( Vector3 textureVertex[3], Vector3 geometryVertex[3], Vector3& texTangent);

		unsigned long  addTexTangent( int vertexIndex, int normalIndex, int textureIndex, const Vector3& texTangent );

		void normalizeTangentsAndCalculateBiTangents();

		void deleteTexTangentInfo();


	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_TEXTANGENTCALCULATOR_H__
