/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSplineLoader.h"
#include "COLLADASaxFWLGeometryMaterialIdInfo.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWTriangles.h"
#include "COLLADAFWLines.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWPolygons.h"
#include "COLLADAFWLinestrips.h"
#include "COLLADAFWIWriter.h"

#include <fstream>


namespace COLLADASaxFWL
{

	SplineLoader::SplineLoader( IFilePartLoader* callingFilePartLoader, const String& geometryId, const String& geometryName )
		: SourceArrayLoader (callingFilePartLoader )
		, mSplineUniqueId(createUniqueIdFromId((ParserChar*)geometryId.c_str(), COLLADAFW::Geometry::ID()))
		, mSpline ( new COLLADAFW::Spline(mSplineUniqueId) )
        , mInterpolations()
        , mVerticesInputs()
        , mCurrentVertexInput( 0 )
        , mInVertices ( false )
        , mInSpline (true)
	{
        if ( !geometryName.empty() )
            mSpline->setName ( geometryName );
        else if ( !geometryId.empty() )
            mSpline->setName ( geometryId );

        if ( !geometryId.empty() )
            mSpline->setOriginalId ( geometryId );
	}

    //------------------------------
    const COLLADAFW::UniqueId& SplineLoader::getUniqueId ()
    {
        
        if ( mSpline ) return mSpline->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool SplineLoader::begin__source( const source__AttributeData& attributes )
	{
		return beginSource(attributes);
	}

	//------------------------------
	bool SplineLoader::end__source(  )
	{
		return endSource();
	}

	//------------------------------
	bool SplineLoader::begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData )
	{
		mCurrentVertexInput = new InputUnshared(attributeData.semantic, attributeData.source);
		return true;
	}

	//------------------------------
	bool SplineLoader::end__input____InputLocal()
	{
		mVerticesInputs.getInputArray().append(mCurrentVertexInput);
		mCurrentVertexInput = 0;
		return true;
	}

    //------------------------------

    bool SplineLoader::begin__control_vertices()
    {
        mInVertices = true;

        return true;
    }

    bool SplineLoader::end__control_vertices()
    {
        mInVertices = false;

        return true;
    }

    //------------------------------
    bool SplineLoader::begin__Name_array( const Name_array__AttributeData& attributeData )
    {
        return beginInterpolationArray( false );
    }

    //------------------------------
    bool SplineLoader::end__Name_array()
    {
        return true;
    }

    //------------------------------
    bool SplineLoader::data__Name_array( const ParserString* data, size_t length )
    {
        return dataInterpolationArray( data, length);
    }

    //------------------------------
    bool SplineLoader::beginInterpolationArray( bool isIdArray )
    {
        const String& sourceId = getCurrentSourceId();

        // Without id we will never be able to us this array again. Don't store it.
        if ( sourceId.empty() )
            return true;

        return true;
    }

    //------------------------------
    bool SplineLoader::dataInterpolationArray( const ParserString* data, size_t length )
    {
        for ( size_t i = 0; i < length;  ++i)
        {
            const ParserString& parserString = data[i];
            mInterpolations.push_back( String( parserString.str, parserString.length ) );
        }
        return true;
    }

    bool SplineLoader::end__spline()
    {
        mInSpline = false;

        loadPositions();
        loadOutTangents();
        loadInTangents();
        loadInterpolations();

        // The mesh will be written by the GeometyLoader. Therefore nothing to with the mesh here
        finish();
        return true;
    }

    bool SplineLoader::loadPositions()
    {
        const InputUnshared * input = mVerticesInputs.getInputBySemantic( InputSemantic::POSITION );

        if( input )
        {
            // Get the source element with the uri of the input element.
            COLLADABU::URI inputUrl = input->getSource ();
            String sourceId = inputUrl.getFragment ();
            SourceBase* sourceBase = getSourceById ( sourceId );
            if ( sourceBase == 0 ) return false;

            // Get the source input array
            const SourceBase::DataType& dataType = sourceBase->getDataType ();
            switch ( dataType )
            {
            case SourceBase::DATA_TYPE_FLOAT:
                {
                    // Get the values array from the source
                    FloatSource* source = ( FloatSource* ) sourceBase;
                    FloatArrayElement& arrayElement = source->getArrayElement ();
                    COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement.getValues ();

                    // TODO
                    unsigned long long stride = source->getStride ();

                    // Check if there are already some values in the positions list.
                    // If so, we have to store the last index to increment the following indexes.
                    COLLADAFW::MeshVertexData& positions = mSpline->getPositions ();
                    const size_t initialIndex = positions.getValuesCount ();
                    sourceBase->setInitialIndex ( initialIndex );

                    // Push the new positions into the list of positions.
                    positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT );
                    if ( initialIndex != 0 ) 
                    {
                        positions.appendValues ( valuesArray );
                    }
                    else
                    {
                        positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                        valuesArray.yieldOwnerShip();
                    }

                    // Set the source base as loaded element.
                    sourceBase->addLoadedInputElement ( InputSemantic::POSITION  );

                    break;
                }
            case SourceBase::DATA_TYPE_DOUBLE:
                {
                    // Get the values array from the source
                    DoubleSource* source = ( DoubleSource* ) sourceBase;
                    DoubleArrayElement& arrayElement = source->getArrayElement ();
                    COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement.getValues ();

                    // Check if there are already some values in the positions list.
                    // If so, we have to store the last index to increment the following indexes.
                    COLLADAFW::MeshVertexData& positions = mSpline->getPositions ();
                    const size_t initialIndex = positions.getValuesCount ();
                    sourceBase->setInitialIndex ( initialIndex );

                    // Push the new positions into the list of positions.
                    positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE );
                    if ( initialIndex != 0 ) 
                    {
                        positions.appendValues ( valuesArray );
                    }
                    else 
                    {
                        positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                        valuesArray.yieldOwnerShip();
                    }

                    // Set the source base as loaded element.
                    sourceBase->addLoadedInputElement ( InputSemantic::POSITION  );

                    break;
                }
            default:
                std::cerr << "Position source has an other datatype as float or double! " << dataType << std::endl;
                return false;
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    bool SplineLoader::loadOutTangents()
    {
        const InputUnshared * input = mVerticesInputs.getInputBySemantic( InputSemantic::OUT_TANGENT );

        if( input )
        {
            // Get the source element with the uri of the input element.
            COLLADABU::URI inputUrl = input->getSource ();
            String sourceId = inputUrl.getFragment ();
            SourceBase* sourceBase = getSourceById ( sourceId );
            if ( sourceBase == 0 ) return false;

            // Get the source input array
            const SourceBase::DataType& dataType = sourceBase->getDataType ();
            switch ( dataType )
            {
            case SourceBase::DATA_TYPE_FLOAT:
                {
                    // Get the values array from the source
                    FloatSource* source = ( FloatSource* ) sourceBase;
                    FloatArrayElement& arrayElement = source->getArrayElement ();
                    COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement.getValues ();

                    // TODO
                    unsigned long long stride = source->getStride ();

                    // Check if there are already some values in the positions list.
                    // If so, we have to store the last index to increment the following indexes.
                    COLLADAFW::MeshVertexData& positions = mSpline->getOutTangents();
                    const size_t initialIndex = positions.getValuesCount ();
                    sourceBase->setInitialIndex ( initialIndex );

                    // Push the new positions into the list of positions.
                    positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT );
                    if ( initialIndex != 0 ) 
                    {
                        positions.appendValues ( valuesArray );
                    }
                    else
                    {
                        positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                        valuesArray.yieldOwnerShip();
                    }

                    // Set the source base as loaded element.
                    sourceBase->addLoadedInputElement ( InputSemantic::OUT_TANGENT  );

                    break;
                }
            case SourceBase::DATA_TYPE_DOUBLE:
                {
                    // Get the values array from the source
                    DoubleSource* source = ( DoubleSource* ) sourceBase;
                    DoubleArrayElement& arrayElement = source->getArrayElement ();
                    COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement.getValues ();

                    // Check if there are already some values in the positions list.
                    // If so, we have to store the last index to increment the following indexes.
                    COLLADAFW::MeshVertexData& positions = mSpline->getOutTangents ();
                    const size_t initialIndex = positions.getValuesCount ();
                    sourceBase->setInitialIndex ( initialIndex );

                    // Push the new positions into the list of positions.
                    positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE );
                    if ( initialIndex != 0 ) 
                    {
                        positions.appendValues ( valuesArray );
                    }
                    else 
                    {
                        positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                        valuesArray.yieldOwnerShip();
                    }

                    // Set the source base as loaded element.
                    sourceBase->addLoadedInputElement ( InputSemantic::OUT_TANGENT  );

                    break;
                }
            default:
                std::cerr << "Position source has an other datatype as float or double! " << dataType << std::endl;
                return false;
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    bool SplineLoader::loadInTangents()
    {
        const InputUnshared * input = mVerticesInputs.getInputBySemantic( InputSemantic::IN_TANGENT );

        if( input )
        {
            // Get the source element with the uri of the input element.
            COLLADABU::URI inputUrl = input->getSource ();
            String sourceId = inputUrl.getFragment ();
            SourceBase* sourceBase = getSourceById ( sourceId );
            if ( sourceBase == 0 ) return false;

            // Get the source input array
            const SourceBase::DataType& dataType = sourceBase->getDataType ();
            switch ( dataType )
            {
            case SourceBase::DATA_TYPE_FLOAT:
                {
                    // Get the values array from the source
                    FloatSource* source = ( FloatSource* ) sourceBase;
                    FloatArrayElement& arrayElement = source->getArrayElement ();
                    COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement.getValues ();

                    // TODO
                    unsigned long long stride = source->getStride ();

                    // Check if there are already some values in the positions list.
                    // If so, we have to store the last index to increment the following indexes.
                    COLLADAFW::MeshVertexData& positions = mSpline->getInTangents ();
                    const size_t initialIndex = positions.getValuesCount ();
                    sourceBase->setInitialIndex ( initialIndex );

                    // Push the new positions into the list of positions.
                    positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT );
                    if ( initialIndex != 0 ) 
                    {
                        positions.appendValues ( valuesArray );
                    }
                    else
                    {
                        positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                        valuesArray.yieldOwnerShip();
                    }

                    // Set the source base as loaded element.
                    sourceBase->addLoadedInputElement ( InputSemantic::POSITION  );

                    break;
                }
            case SourceBase::DATA_TYPE_DOUBLE:
                {
                    // Get the values array from the source
                    DoubleSource* source = ( DoubleSource* ) sourceBase;
                    DoubleArrayElement& arrayElement = source->getArrayElement ();
                    COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement.getValues ();

                    // Check if there are already some values in the positions list.
                    // If so, we have to store the last index to increment the following indexes.
                    COLLADAFW::MeshVertexData& positions = mSpline->getInTangents ();
                    const size_t initialIndex = positions.getValuesCount ();
                    sourceBase->setInitialIndex ( initialIndex );

                    // Push the new positions into the list of positions.
                    positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE );
                    if ( initialIndex != 0 ) 
                    {
                        positions.appendValues ( valuesArray );
                    }
                    else 
                    {
                        positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                        valuesArray.yieldOwnerShip();
                    }

                    // Set the source base as loaded element.
                    sourceBase->addLoadedInputElement ( InputSemantic::IN_TANGENT  );

                    break;
                }
            default:
                std::cerr << "Position source has an other datatype as float or double! " << dataType << std::endl;
                return false;
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    bool SplineLoader::loadInterpolations()
    {
        if( mInterpolations.size() )
        {
            COLLADAFW::Spline::InterpolationArray & interpolations = mSpline->getInterpolations();

            interpolations.reallocMemory( mInterpolations.size() );

            StringList::const_iterator it = mInterpolations.begin(), end = mInterpolations.end();
            for( ; it != end ; ++it)
            {
                if( *it == "LINEAR" )
                {
                    interpolations.append( COLLADAFW::Spline::LINEAR );
                }
                else if( *it == "BEZIER" )
                {
                    interpolations.append( COLLADAFW::Spline::BEZIER );
                }
                else
                {
                    std::cerr << "Interpolation source has an unknown type : " << *it << std::endl;
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

} // namespace COLLADASaxFWL
