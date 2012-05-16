/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INTERPOLATIONTYPESOURCE_H__
#define __COLLADASAXFWL_INTERPOLATIONTYPESOURCE_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSource.h"

#include "COLLADAFWAnimationCurve.h"


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class InterpolationTypeSource : public Source < InterpolationTypeArrayElement, SourceBase::DATA_TYPE_INTERPOLATIONTYPE>
	{
	private:
		/** The interpolation type of the source. If the array is constant, i.e. all interpolation types are equal,
		this member is set to this interpolation type, otherwise it is set to COLLADAFW::AnimationCurve::INTERPOLATION_MIXED.*/
		COLLADAFW::AnimationCurve::InterpolationType mInterpolationType;

		/** True, if at least one interpolation type is bezier or hermite, false otherwise.*/
		bool mRequiresTangents;
	public:
		InterpolationTypeSource()
			: Source < InterpolationTypeArrayElement, SourceBase::DATA_TYPE_INTERPOLATIONTYPE>()
		    , mInterpolationType(COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN)
			, mRequiresTangents(false)
			{}

		virtual ~InterpolationTypeSource(){}

		COLLADAFW::AnimationCurve::InterpolationType getInterpolationType() const { return mInterpolationType; }

		void setInterpolationType(COLLADAFW::AnimationCurve::InterpolationType interpolationType) { mInterpolationType = interpolationType; }


		bool getRequiresTangents() const { return mRequiresTangents; }

		void setRequiresTangents(bool requiresTangents) { mRequiresTangents = requiresTangents; }

	private:

        /** Disable default copy ctor. */
		InterpolationTypeSource( const InterpolationTypeSource& pre );

        /** Disable default assignment operator. */
		const InterpolationTypeSource& operator= ( const InterpolationTypeSource& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_INTERPOLATIONTYPESOURCE_H__
