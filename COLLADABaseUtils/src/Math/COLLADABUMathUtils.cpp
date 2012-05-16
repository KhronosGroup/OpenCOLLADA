/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "Math/COLLADABUMathUtils.h"


namespace COLLADABU
{
	namespace Math
	{
		const double Utils::PI = 3.1415926535;
		const float Utils::PI_f = 3.1415926535f;

		const double Utils::DEG_TO_RAD = PI/180.0;
		const double Utils::RAD_TO_DEG = 180.0/PI;

		const float Utils::DEG_TO_RAD_f = PI_f/180.0f;
		const float Utils::RAD_TO_DEG_f = 180.0f/PI_f;


		//------------------------------------------------------
		bool Utils::epsilonEquals( Real r1, Real r2, Real epsilon )
		{
			Real upperBound = r1 + epsilon;
			Real lowerBound = r1 - epsilon;

			if ( upperBound > r2 && r2 > lowerBound )
			{
				return true;
			}

			return false;
		}

		//------------------------------------------------------
		void Utils::getMatrixTransposed( float* matrix, const Matrix4 m )
		{
			for(size_t row = 0; row < 4; ++row)
			{
				for(size_t col = 0; col < 4; ++col)
				{
					size_t index = ((row * 4) +col);
					matrix[index] = (float)(m[col][row]);
				}
			}
		}
	}
} // namespace COLLADAFW
