/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryAnimationsLoader.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLSidTreeNode.h"
#include "COLLADASaxFWLInterpolationTypeSource.h"

#include "COLLADAFWValidate.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

	enum SamplerInputSemantics
	{
		SEMANTIC_UNKNOWN,
		SEMANTIC_INPUT,
		SEMANTIC_OUTPUT,
		SEMANTIC_INTERPOLATION,
		SEMANTIC_IN_TANGENT,
		SEMANTIC_OUT_TANGENT
	};

	const String INTERPOLATIONTYPE_LINEAR("LINEAR");
	const String INTERPOLATIONTYPE_BEZIER("BEZIER"); 
	const String INTERPOLATIONTYPE_CARDINAL("CARDINAL"); 
	const String INTERPOLATIONTYPE_HERMITE("HERMITE");
	const String INTERPOLATIONTYPE_BSPLINE("BSPLINE"); 
	const String INTERPOLATIONTYPE_STEP("STEP");
	const String INTERPOLATIONTYPE_MIXED("MIXED");

	//------------------------------
	bool operator==( const ParserString& parserString, const String& stlSring )
	{
		if ( parserString.length != stlSring.length() )
			return false;

		size_t pos = 0;
		const char* str = stlSring.c_str();
		while ( (pos < parserString.length) )
		{
			if ( parserString.str[pos] != str[pos] )
				return false;
			++pos;
		}
		return true;
	}

	//------------------------------
	COLLADAFW::AnimationCurve::InterpolationType LibraryAnimationsLoader::getInterpolationTypeByString( const ParserString& string )
	{
		if ( string == INTERPOLATIONTYPE_LINEAR )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR;
		}
		else if ( string == INTERPOLATIONTYPE_BEZIER )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER;
		}
		else if ( string == INTERPOLATIONTYPE_CARDINAL )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_CARDINAL;
		}
		else if ( string == INTERPOLATIONTYPE_HERMITE )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE;
		}
		else if ( string == INTERPOLATIONTYPE_BSPLINE )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_BSPLINE;
		}
		else if ( string == INTERPOLATIONTYPE_STEP )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_STEP;
		}
		else if ( string == INTERPOLATIONTYPE_MIXED )
		{
			return COLLADAFW::AnimationCurve::INTERPOLATION_MIXED;
		}

		return COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN;
	}

	//------------------------------
	SamplerInputSemantics getSemanticBySemanticStr( const char * semanticStr)
	{
		if ( strcmp(semanticStr, "INPUT" ) == 0 )
		{
			return SEMANTIC_INPUT;
		}
		else if ( strcmp(semanticStr, "OUTPUT" ) == 0 )
		{
			return SEMANTIC_OUTPUT;
		}
		else if ( strcmp(semanticStr, "INTERPOLATION" ) == 0 )
		{
			return SEMANTIC_INTERPOLATION;
		}
		else if ( strcmp(semanticStr, "IN_TANGENT" ) == 0 )
		{
			return SEMANTIC_IN_TANGENT;
		}
		else if ( strcmp(semanticStr, "OUT_TANGENT" ) == 0 )
		{
			return SEMANTIC_OUT_TANGENT;
		}
		return SEMANTIC_UNKNOWN;
	}

	//------------------------------
	LibraryAnimationsLoader::LibraryAnimationsLoader( IFilePartLoader* callingFilePartLoader )
		: SourceArrayLoader(callingFilePartLoader)
		, mCurrentAnimationCurve(0)
		, mCurrentlyParsingInterpolationArray(false)
	{}

    //------------------------------
	LibraryAnimationsLoader::~LibraryAnimationsLoader()
	{
	}

	/** Copies the values contained in @a realSource into @a realsArray .*/
	//------------------------------
	void setRealValues( COLLADAFW::FloatOrDoubleArray& realsArray, const RealSource* realSource )
	{
		if ( !realsArray.empty() )
		{
			// There already must have been an input with semantic INPUT. We ignore all following.
			return;
		}
		realsArray.setType( SourceArrayLoader::DATA_TYPE_REAL );
		const RealArrayElement& realArrayElement = realSource->getArrayElement();
		realsArray.appendValues(realArrayElement.getValues());
	}

	//------------------------------
	const COLLADAFW::UniqueId& LibraryAnimationsLoader::getAnimationBySamplerId( const String& samplerId )
	{
		StringUniqueIdMap::const_iterator it = mSamplerIdAnimationUniqueIdMap.find( samplerId );
		if ( it == mSamplerIdAnimationUniqueIdMap.end() )
		{
			return COLLADAFW::UniqueId::INVALID;
		}
		else
		{
			return it->second;
		}
	}


	//------------------------------
	bool LibraryAnimationsLoader::end__library_animations()
	{
		SaxVirtualFunctionTest(end__library_animations());

		finish();
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__source( const source__AttributeData& attributes )
	{
		SaxVirtualFunctionTest(begin__source(attributes));
		return beginSource(attributes);
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__source(  )
	{
		SaxVirtualFunctionTest(end__source());
		return endSource();
	}


	//------------------------------
	bool LibraryAnimationsLoader::begin__animation( const animation__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__animation(attributeData));
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__animation()
	{
		SaxVirtualFunctionTest(end__animation());
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__sampler( const sampler__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__sampler(attributeData));
		mCurrentAnimationCurve = FW_NEW COLLADAFW::AnimationCurve(getUniqueIdFromId(attributeData.id, COLLADAFW::Animation::ID()).getObjectId());
		
		if ( attributeData.id && *attributeData.id )
		{
			mSamplerIdAnimationUniqueIdMap[ attributeData.id ] = mCurrentAnimationCurve->getUniqueId();
		}
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__sampler()
	{
		SaxVirtualFunctionTest(end__sampler());
		bool success = true;
		if ( COLLADAFW::validate( mCurrentAnimationCurve ) )
		{
			success = writer()->writeAnimation(mCurrentAnimationCurve);
		}
		else
		{
			// todo handle error
		}
		mCurrentAnimationCurve = 0;
		return success;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__channel( const channel__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__channel(attributeData));
		String samplerId = getIdFromURIFragmentType(attributeData.source);

		const COLLADAFW::UniqueId& animationUniqueId = getAnimationBySamplerId( samplerId );

		if ( !animationUniqueId.isValid() )
			return true;

		SidAddress sidAddress( attributeData.target );
		const SidTreeNode* sidTreeNode = resolveSid( sidAddress );

		if ( sidTreeNode )
		{
			if ( sidTreeNode->getTargetType() == SidTreeNode::TARGETTYPE_ANIMATABLE )
			{
				COLLADAFW::Animatable* animatable = sidTreeNode->getAnimatableTarget();
				COLLADAFW::UniqueId animationListUniqueId = animatable->getAnimationList();
				if ( !animationListUniqueId.isValid() )
				{
					animationListUniqueId = getUniqueId( COLLADAFW::AnimationList::ID() );
					animatable->setAnimationList( animationListUniqueId );
				}
				COLLADAFW::AnimationList*& animationList = getAnimationListByUniqueId(animationListUniqueId);

				if ( !animationList )
				{
					animationList = new COLLADAFW::AnimationList( animationListUniqueId.getObjectId() );
				}

				// TODO determine animation class 
				COLLADAFW::AnimationList::AnimationBinding animationBinding;
				animationBinding.animation = animationUniqueId;
				animationBinding.animationClass = COLLADAFW::AnimationList::POSITION_XYZ;
				animationBinding.firstIndex = 0;
				animationBinding.secondIndex = 0;
				animationList->getAnimationBindings().append( animationBinding );
			}
		}
		else
		{
			// the references element has not been parsed. Store the connection. Will be precessed by FileLoader
			// at the end of the collada file.
			addToAnimationUniqueIdSidAddressPairList( animationUniqueId, sidAddress );
		}

		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__channel()
	{
		SaxVirtualFunctionTest(end__channel());
		return true;
	}


	//------------------------------
	bool LibraryAnimationsLoader::begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__input____InputLocal(attributeData));

		// we ignore inputs that don't have semantics and source
		if ( !attributeData.semantic || !attributeData.source  )
		{
			return true;
		}

		SamplerInputSemantics semantic = getSemanticBySemanticStr( attributeData.semantic );
		if ( semantic == SEMANTIC_UNKNOWN )
		{
			return true;
		}

		String sourceId = getIdFromURIFragmentType(attributeData.source);
		const SourceBase* sourceBase = getSourceById ( sourceId );
		// TODO handle case where source could not be found
		if ( !sourceBase )
			return true;
		SourceBase::DataType sourceDataType =  sourceBase->getDataType();


		switch ( semantic )
		{
		case SEMANTIC_INPUT:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_REAL )
				{
					// The source array has wrong type. Only reals are allowed for semantic INPUT
					break;
				}
				setRealValues( mCurrentAnimationCurve->getInputValues(), (const RealSource*)sourceBase);
			}
			break;
		case SEMANTIC_OUTPUT:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_REAL )
				{
					// The source array has wrong type. Only reals are allowed for semantic OUTPUT
					break;
				}

				const RealSource* realSource = (const RealSource*)sourceBase;
				setRealValues( mCurrentAnimationCurve->getOutputValues(), realSource);

				mCurrentAnimationCurve->setOutDimension((size_t)realSource->getStride());
			}
			break;
		case SEMANTIC_OUT_TANGENT:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_REAL )
				{
					// The source array has wrong type. Only reals are allowed for semantic OUTPUT
					break;
				}
				setRealValues( mCurrentAnimationCurve->getOutTangentValues(), (const RealSource*)sourceBase);
			}
			break;
		case SEMANTIC_IN_TANGENT:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_REAL )
				{
					// The source array has wrong type. Only reals are allowed for semantic OUTPUT
					break;
				}
				setRealValues( mCurrentAnimationCurve->getInTangentValues(), (const RealSource*)sourceBase);
			}
			break;
		case SEMANTIC_INTERPOLATION:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_INTERPOLATIONTYPE )
				{
					// The source array has wrong type. Only reals are allowed for semantic INTERPOLATION
					break;
				}

				COLLADAFW::AnimationCurve::InterpolationType currentAnimationCurveInterpolationType = mCurrentAnimationCurve->getInterpolationType();

				if ( currentAnimationCurveInterpolationType != COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN )
				{
					// There already must have been an input with semantic INTERPOLATION. We ignore all following.
					break;
				}

				const InterpolationTypeSource* interpolationTypeSource = (const InterpolationTypeSource*)sourceBase;
				COLLADAFW::AnimationCurve::InterpolationType interpolationType = interpolationTypeSource->getInterpolationType();

				mCurrentAnimationCurve->setInterpolationType(interpolationType);

				if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_MIXED )
				{
					COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypes = mCurrentAnimationCurve->getInterpolationTypes();
					interpolationTypes.appendValues(interpolationTypeSource->getArrayElement().getValues());
				}
			}
			break;
		}

		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__Name_array( const Name_array__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__Name_array(attributeData));
		return beginArray<InterpolationTypeSource>( attributeData.count, attributeData.id ) != 0;
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__Name_array()
	{
		SaxVirtualFunctionTest(end__Name_array());
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::data__Name_array( const ParserString* data, size_t length )
	{
		SaxVirtualFunctionTest(data__Name_array(data, length));
		InterpolationTypeSource* interpolationTypeSource = (InterpolationTypeSource*)mCurrentSoure;
		for ( size_t i = 0; i < length;  ++i)
		{
			const ParserString& interpolationTypeString = data[i];
			COLLADAFW::AnimationCurve::InterpolationType interpolationType = getInterpolationTypeByString( interpolationTypeString );
			COLLADAFW::AnimationCurve::InterpolationTypeArray& array  = interpolationTypeSource->getArrayElement().getValues();
			array.append( interpolationType );

			COLLADAFW::AnimationCurve::InterpolationType interpolationTypeSourceInterpolationType = interpolationTypeSource->getInterpolationType();
			if ( interpolationTypeSourceInterpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN )
			{
				interpolationTypeSource->setInterpolationType( interpolationType );
			}
			else if ( interpolationTypeSourceInterpolationType != interpolationType )
			{
				interpolationTypeSource->setInterpolationType( COLLADAFW::AnimationCurve::INTERPOLATION_MIXED);
			}
		}
		return true;
	}

} // namespace COLLADASaxFWL
