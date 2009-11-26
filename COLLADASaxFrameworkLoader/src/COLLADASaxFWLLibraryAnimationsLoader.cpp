/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWValidate.h"
#include "COLLADAFWAnimationCurve.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWTypes.h"


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

	struct AccessorAnimationClassPair
	{
		AccessorAnimationClassPair( const SourceBase::AccessorParameter* _parameters,
									size_t _parameterCount,
			                        COLLADAFW::AnimationList::AnimationClass _animationClass)
									: parameters(_parameters)
									, parameterCount(_parameterCount/sizeof(SourceBase::AccessorParameter))
									, animationClass(_animationClass)
		{}
		const SourceBase::AccessorParameter* parameters;
		size_t parameterCount;
		COLLADAFW::AnimationList::AnimationClass animationClass;
	};

	struct AccessorDimensionsPair
	{
		AccessorDimensionsPair( const SourceBase::AccessorParameter& _parameter,
								COLLADAFW::PhysicalDimension _physicalDimension,
								size_t _dimension)
			: parameter(_parameter)
			, physicalDimension(_physicalDimension)
			, dimension(_dimension)
		{}
		const SourceBase::AccessorParameter& parameter;
		COLLADAFW::PhysicalDimension physicalDimension;
		size_t dimension;
	};

	SourceBase::AccessorParameter parameterTime = {"TIME", "float"};
	SourceBase::AccessorParameter parameterFloat = {"", "float"};
	SourceBase::AccessorParameter parameterX = {"X", "float"};
	SourceBase::AccessorParameter parameterY = {"Y", "float"};
	SourceBase::AccessorParameter parameterZ = {"Z", "float"};
	SourceBase::AccessorParameter parameterR = {"R", "float"};
	SourceBase::AccessorParameter parameterG = {"G", "float"};
	SourceBase::AccessorParameter parameterB = {"B", "float"};
	SourceBase::AccessorParameter parameterA = {"A", "float"};
	SourceBase::AccessorParameter parameterAngle = {"ANGLE", "float"};
	SourceBase::AccessorParameter parameterTransform = {"TRANSFORM", "float4x4"};

	SourceBase::AccessorParameter accessorTime[] = {parameterTime};
	SourceBase::AccessorParameter accessorFloat[] = {parameterFloat};
	SourceBase::AccessorParameter accessorX[] = {parameterX};
	SourceBase::AccessorParameter accessorY[] = {parameterY};
	SourceBase::AccessorParameter accessorZ[] = {parameterZ};
	SourceBase::AccessorParameter accessorR[] = {parameterR};
	SourceBase::AccessorParameter accessorG[] = {parameterG};
	SourceBase::AccessorParameter accessorB[] = {parameterB};
	SourceBase::AccessorParameter accessorA[] = {parameterA};
	SourceBase::AccessorParameter accessorAngle[] = {parameterAngle};
	SourceBase::AccessorParameter accessorTransform[] = {parameterTransform};

	SourceBase::AccessorParameter accessorXYZ[] = {parameterX, parameterY, parameterZ};
	SourceBase::AccessorParameter accessorRGB[] = {parameterR, parameterG, parameterB};
	SourceBase::AccessorParameter accessorRGBA[] = {parameterR, parameterG, parameterB, parameterA};
	SourceBase::AccessorParameter accessorAxisAngle[] = {parameterX, parameterY, parameterZ, parameterAngle};

	AccessorAnimationClassPair animationClassMap[] = 
	{ 
		  AccessorAnimationClassPair( accessorTime, sizeof(accessorTime), COLLADAFW::AnimationList::TIME)
		, AccessorAnimationClassPair( accessorFloat, sizeof(accessorFloat), COLLADAFW::AnimationList::FLOAT)
		, AccessorAnimationClassPair( accessorX, sizeof(accessorX), COLLADAFW::AnimationList::POSITION_X)
		, AccessorAnimationClassPair( accessorY, sizeof(accessorY), COLLADAFW::AnimationList::POSITION_Y)
		, AccessorAnimationClassPair( accessorZ, sizeof(accessorZ), COLLADAFW::AnimationList::POSITION_Z)
		, AccessorAnimationClassPair( accessorR, sizeof(accessorR), COLLADAFW::AnimationList::COLOR_R)
		, AccessorAnimationClassPair( accessorG, sizeof(accessorG), COLLADAFW::AnimationList::COLOR_G)
		, AccessorAnimationClassPair( accessorB, sizeof(accessorB), COLLADAFW::AnimationList::COLOR_B)
		, AccessorAnimationClassPair( accessorA, sizeof(accessorA), COLLADAFW::AnimationList::COLOR_A)
		, AccessorAnimationClassPair( accessorAngle, sizeof(accessorAngle), COLLADAFW::AnimationList::ANGLE)
		, AccessorAnimationClassPair( accessorXYZ, sizeof(accessorXYZ), COLLADAFW::AnimationList::POSITION_XYZ)
		, AccessorAnimationClassPair( accessorRGB, sizeof(accessorRGB), COLLADAFW::AnimationList::COLOR_RGB)
		, AccessorAnimationClassPair( accessorRGBA, sizeof(accessorRGBA), COLLADAFW::AnimationList::COLOR_RGBA)
		, AccessorAnimationClassPair( accessorAxisAngle, sizeof(accessorAxisAngle), COLLADAFW::AnimationList::AXISANGLE)
		, AccessorAnimationClassPair( accessorTransform, sizeof(accessorTransform), COLLADAFW::AnimationList::MATRIX4X4)
	};

#if 0
	AccessorDimensionsPair animationDimensionMap[] = 
	{ 
	      AccessorDimensionsPair( parameterFloat, PHYSICAL_DIMENSION_UNKNOWN, 1)
    	, AccessorDimensionsPair( parameterX, PHYSICAL_DIMENSION_LENGTH, 1)
		, AccessorDimensionsPair( parameterY, PHYSICAL_DIMENSION_LENGTH, 1)
		, AccessorDimensionsPair( parameterZ, PHYSICAL_DIMENSION_LENGTH, 1)
		, AccessorDimensionsPair( parameterAngle, PHYSICAL_DIMENSION_ANGLE, 1)
		, AccessorDimensionsPair( parameterTransform, PHYSICAL_DIMENSION_TRANSFORMATIONMATRIX4X4, 16)
	};
#endif


	/** Determines the animation class from the accessor.*/
	//------------------------------
	COLLADAFW::AnimationList::AnimationClass determineAnimationClass( const SourceBase::Accessor& accessor )
	{
		static const size_t mapSize = sizeof(animationClassMap)/sizeof(AccessorAnimationClassPair);
		for ( size_t i = 0; i < mapSize; ++i)
		{
			const AccessorAnimationClassPair& animationClassPair = animationClassMap[i];

			if ( accessor.size() != animationClassPair.parameterCount )
			{
				// two accessor must have equal number of parameters to be equal
				continue;
			}

			bool equal = true;
			for ( size_t j = 0; j < animationClassPair.parameterCount; ++j)
			{
				const SourceBase::AccessorParameter& parameter = animationClassPair.parameters[j];
				const SourceBase::AccessorParameter& accessorParameter = accessor[j];
				if ( parameter !=  accessorParameter ) 
				{
					equal = false;
					break;
				}
			}

			if ( equal )
			{
				// if we reach this point, the parameters in accessor are equal to those in animationClassPair
				return animationClassPair.animationClass;
			}
		}

		return COLLADAFW::AnimationList::UNKNOWN_CLASS;
	}

#if 0
	/** Determines the physical dimension and the dimension of @a parameter.
	@param parameters the accessor parameter to determine the dimensions from
	@param physicalDimension Will be set to the physical dimension
	@param dimension Will be set to the dimension of the parameter, e.g. 1 for float, 16 for float4x4 
	@return True if parameter was found, false otherwise.*/
	//------------------------------
	bool determineParameterDimensions( const SourceBase::AccessorParameter& parameter,
									   COLLADAFW::PhysicalDimension& physicalDimension,
									   size_t& dimension)
	{
		static const size_t mapSize = sizeof(animationDimensionMap)/sizeof(AccessorDimensionsPair);
		for ( size_t i = 0; i < mapSize; ++i)
		{
			const AccessorDimensionsPair& animationDimensionPair = animationDimensionMap[i];

			if ( parameter ==  animationDimensionPair.parameter ) 
			{
				physicalDimension = animationDimensionPair.physicalDimension;
				dimension = animationDimensionPair.dimension;
				return true;
			}
		}

		return false;
	}
#endif

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
		, mCurrentAnimationInfo( 0 )
		, mCurrentAnimationCurveRequiresTangents(true)
	{}

    //------------------------------
	LibraryAnimationsLoader::~LibraryAnimationsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryAnimationsLoader::getUniqueId ()
    {
        if ( mCurrentAnimationCurve )
            return mCurrentAnimationCurve->getUniqueId ();

        // TODO One curve for every sampler in an collada animation. Returns always an invalid id!
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	AnimationInfo* LibraryAnimationsLoader::getAnimationInfoBySamplerId( const String& samplerId )
	{
		StringAnimationInfoMap::iterator it = mSamplerIdAnimationInfoMap.find( samplerId );
		if ( it == mSamplerIdAnimationInfoMap.end() )
		{
			return 0;
		}
		else
		{
			return &(it->second);
		}
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__library_animations()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__source( const source__AttributeData& attributes )
	{
		return beginSource(attributes);
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__source(  )
	{
		return endSource();
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__animation( const animation__AttributeData& attributeData )
	{
        if ( attributeData.name ) 
            mName = (const char*)attributeData.name;
        else if ( attributeData.id) 
            mName = (const char*)attributeData.id;

        if ( attributeData.id )
            mOriginalId = (const char*)attributeData.id;

		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__animation()
	{
        mOriginalId = COLLADABU::Utils::EMPTY_STRING;

		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__sampler( const sampler__AttributeData& attributeData )
	{
		mCurrentAnimationCurve = FW_NEW COLLADAFW::AnimationCurve(createUniqueIdFromId(attributeData.id, COLLADAFW::Animation::ID()));

		mCurrentAnimationCurve->setName ( mName );
        mCurrentAnimationCurve->setOriginalId ( mOriginalId );

		if ( attributeData.id && *attributeData.id )
		{
			AnimationInfo animationInfo;
			animationInfo.uniqueId = mCurrentAnimationCurve->getUniqueId();
			animationInfo.animationClass = COLLADAFW::AnimationList::UNKNOWN_CLASS;
			mCurrentAnimationInfo = &(mSamplerIdAnimationInfoMap.insert(std::make_pair(attributeData.id, animationInfo)).first->second);
		}
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__sampler()
	{
		bool success = true;
		if ( !mCurrentAnimationCurveRequiresTangents )
		{
			mCurrentAnimationCurve->getInTangentValues().clear();
			mCurrentAnimationCurve->getOutTangentValues().clear();
		}
		if ( (getObjectFlags() & Loader::ANIMATION_FLAG) != 0 )
		{
			//assume linear interpolation if no interpolation is set
			if ( mCurrentAnimationCurve->getInterpolationType() == COLLADAFW::AnimationCurve::INTERPOLATION_UNKNOWN )
			{
				mCurrentAnimationCurve->setInterpolationType(COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR );
			}

			if ( COLLADAFW::validate( mCurrentAnimationCurve ) )
			{
				success = writer()->writeAnimation(mCurrentAnimationCurve);
				FW_DELETE mCurrentAnimationCurve;
			}
			else
			{
                handleFWLError ( SaxFWLError::ERROR_DATA_NOT_VALID, "Animation curve \"" + mCurrentAnimationCurve->getName () + "\" not valid!" );
			}
		}
		mCurrentAnimationCurve = 0;
		mCurrentAnimationInfo = 0;
		mCurrentAnimationCurveRequiresTangents = true;
		return success;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__channel( const channel__AttributeData& attributeData )
	{
		String samplerId = getIdFromURIFragmentType(attributeData.source);

		AnimationInfo* animationInfo = getAnimationInfoBySamplerId( samplerId );

		if ( !animationInfo )
			return true;

		SidAddress sidAddress( String(attributeData.target) );
#if 0
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

				// TODO handle this for arrays
				COLLADAFW::AnimationList::AnimationBinding animationBinding;
				animationBinding.animation = animationInfo->uniqueId;
				animationBinding.animationClass = animationInfo->animationClass;
				if ( animationBinding.animationClass == COLLADAFW::AnimationList::MATRIX4X4_ELEMENT )
				{
					animationBinding.firstIndex = sidAddress.getFirstIndex();
					animationBinding.secondIndex = sidAddress.getSecondIndex();
				}
				else
				{
					animationBinding.firstIndex = 0;
					animationBinding.secondIndex = 0;
				}
				animationList->getAnimationBindings().append( animationBinding );
			}
		}
		else
#endif
		{
			// the references element has not been parsed. Store the connection. Will be processed by FileLoader
			// at the end of the collada file.
			addToAnimationSidAddressBindings( *animationInfo, sidAddress );
		}

		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__channel()
	{
		return true;
	}


	//------------------------------
	bool LibraryAnimationsLoader::begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData )
	{
		// we ignore inputs that don't have semantics or source
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

				COLLADAFW::AnimationList::AnimationClass animationClass = determineAnimationClass( sourceBase->getAccessor() );

				if ( animationClass == COLLADAFW::AnimationList::TIME )
				{
					mCurrentAnimationCurve->setInPhysicalDimension( COLLADAFW::PHYSICAL_DIMENSION_TIME );
				}
				else
				{
					mCurrentAnimationCurve->setInPhysicalDimension( COLLADAFW::PHYSICAL_DIMENSION_UNKNOWN );
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

				assert( mCurrentAnimationInfo );
				COLLADAFW::PhysicalDimensionArray& physicalDimensions = mCurrentAnimationCurve->getOutPhysicalDimensions();
				
				if ( mCurrentAnimationInfo )
				{
					COLLADAFW::AnimationList::AnimationClass animationClass = determineAnimationClass( sourceBase->getAccessor() );
					mCurrentAnimationInfo->animationClass = animationClass;

					switch ( animationClass )
					{
					case COLLADAFW::AnimationList::POSITION_X:
					case COLLADAFW::AnimationList::POSITION_Y:
					case COLLADAFW::AnimationList::POSITION_Z:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						break;
					case COLLADAFW::AnimationList::POSITION_XYZ:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						break;
					case COLLADAFW::AnimationList::ANGLE:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_ANGLE);
						break;
					case COLLADAFW::AnimationList::AXISANGLE:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_ANGLE);
						break;
					case COLLADAFW::AnimationList::MATRIX4X4:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_LENGTH);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
						break;
					case COLLADAFW::AnimationList::COLOR_R:
					case COLLADAFW::AnimationList::COLOR_G:
					case COLLADAFW::AnimationList::COLOR_B:
					case COLLADAFW::AnimationList::COLOR_A:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						break;
					case COLLADAFW::AnimationList::COLOR_RGB:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						break;
					case COLLADAFW::AnimationList::COLOR_RGBA:
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_COLOR);
						break;
                    case COLLADAFW::AnimationList::FLOAT:
                        physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_NUMBER);
                        break;
					}
				}

				const RealSource* realSource = (const RealSource*)sourceBase;
				setRealValues( mCurrentAnimationCurve->getOutputValues(), realSource);

				size_t stride = (size_t)realSource->getStride();
				size_t physicalDimensionsCount = physicalDimensions.getCount();
				// if stride is larger that physicalDimensionsCount, we need to append dimensions to physicalDimensions
				for ( size_t i =  physicalDimensionsCount; i < stride; ++i)
				{
					physicalDimensions.append(COLLADAFW::PHYSICAL_DIMENSION_UNKNOWN);
				}
				mCurrentAnimationCurve->setOutDimension(stride);
			}
			break;
		case SEMANTIC_OUT_TANGENT:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_REAL )
				{
					// The source array has wrong type. Only reals are allowed for semantic OUTPUT
					break;
				}

				if ( !mCurrentAnimationCurveRequiresTangents )
				{
					// This animation does not require tangents
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
				if ( !mCurrentAnimationCurveRequiresTangents )
				{
					// This animation does not require tangents
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
				mCurrentAnimationCurveRequiresTangents = interpolationTypeSource->getRequiresTangents();

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
		return beginArray<InterpolationTypeSource>( attributeData.count, attributeData.id ) != 0;
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__Name_array()
	{
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::data__Name_array( const ParserString* data, size_t length )
	{
		InterpolationTypeSource* interpolationTypeSource = (InterpolationTypeSource*)mCurrentSoure;
		for ( size_t i = 0; i < length;  ++i)
		{
			const ParserString& interpolationTypeString = data[i];
			COLLADAFW::AnimationCurve::InterpolationType interpolationType = getInterpolationTypeByString( interpolationTypeString );
			COLLADAFW::AnimationCurve::InterpolationTypeArray& array  = interpolationTypeSource->getArrayElement().getValues();
			array.append( interpolationType );

			COLLADAFW::AnimationCurve::InterpolationType interpolationTypeSourceInterpolationType = interpolationTypeSource->getInterpolationType();
			if ( (interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER) || 
				 (interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_HERMITE) )
			{
				interpolationTypeSource->setRequiresTangents( true );
			}
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
