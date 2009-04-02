/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryAnimationsLoader.h"
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
	{}

    //------------------------------
	LibraryAnimationsLoader::~LibraryAnimationsLoader()
	{
	}


	//------------------------------
	bool LibraryAnimationsLoader::end__library_animations()
	{
		SaxVirtualFunctionTest(end__library_animations());

//		bool success = writer()->writeGeometry(mMesh);
//		delete mMesh;
		finish();
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::begin__animation__source( const animation__source__AttributeData& attributes )
	{
		SaxVirtualFunctionTest(begin__animation__source(attributes));
		return beginSource(attributes);
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__animation__source(  )
	{
		SaxVirtualFunctionTest(end__animation__source());
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
		return true;
	}

	//------------------------------
	bool LibraryAnimationsLoader::end__sampler()
	{
		SaxVirtualFunctionTest(end__sampler());
		bool success = writer()->writeAnimation(mCurrentAnimationCurve);
		mCurrentAnimationCurve = 0;
		return success;
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

		COLLADABU::URI sourceUrl = String(attributeData.source);
		String sourceId = sourceUrl.getFragment ();
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
				COLLADAFW::FloatOrDoubleArray& inputValues = mCurrentAnimationCurve->getInputValues();
				if ( !inputValues.empty() )
				{
					// There already must have been an input with semantic INPUT. We ignore all following.
					break;
				}
				inputValues.setType( DATA_TYPE_REAL );
				const RealSource* realSource = (const RealSource*)sourceBase;
				const RealArrayElement& realArrayElement = realSource->getArrayElement();
				inputValues.appendValues(realArrayElement.getValues());
			}
			break;
		case SEMANTIC_OUTPUT:
			{
				if ( sourceDataType != SourceBase::DATA_TYPE_REAL )
				{
					// The source array has wrong type. Only reals are allowed for semantic INPUT
					break;
				}
				COLLADAFW::FloatOrDoubleArray& outputValues = mCurrentAnimationCurve->getOutputValues();
				if ( !outputValues.empty() )
				{
					// There already must have been an input with semantic INPUT. We ignore all following.
					break;
				}
				outputValues.setType( DATA_TYPE_REAL );
				const RealSource* realSource = (const RealSource*)sourceBase;
				const RealArrayElement& realArrayElement = realSource->getArrayElement();
				outputValues.appendValues(realArrayElement.getValues());

				mCurrentAnimationCurve->setOutDimension((size_t)realSource->getStride());
			}
			break;
		}

		return true;
	}
} // namespace COLLADASaxFWL
