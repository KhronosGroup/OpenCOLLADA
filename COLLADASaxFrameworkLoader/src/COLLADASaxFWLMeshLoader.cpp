/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader.h"
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

	MeshLoader::MeshLoader( IFilePartLoader* callingFilePartLoader, const String& geometryId, const String& geometryName )
		: SourceArrayLoader (callingFilePartLoader )
		, mMeshUniqueId(createUniqueIdFromId((ParserChar*)geometryId.c_str(), COLLADAFW::Geometry::ID()))
		, mMesh ( new COLLADAFW::Mesh(mMeshUniqueId) )
		, mMaterialIdInfo(getMeshMaterialIdInfo())
		, mCurrentMeshPrimitive(0)
		, mCurrentVertexInput(0)
        , mInVertices ( false )
		, mMeshPrimitiveInputs(mVerticesInputs)
		, mCurrentMeshPrimitiveInput(0)
		, mCurrentMaxOffset(0)
		, mCurrentVertexCount(0)
		, mCurrentLastPrimitiveVertexCount(0)
		, mCurrentPhHasEmptyP(true)
		, mCurrentExpectedVertexCount(0)
		, mCurrentFaceOrLineCount(0)
        , mCurrentOffset (0)
		, mPositionsOffset (0)
		, mPositionsIndexOffset(0)
		, mUsePositions ( true )
		, mNormalsOffset (0)
		, mNormalsIndexOffset(0)
		, mUseNormals ( false )
        , mUseTangents ( false )
        , mUseBinormals ( false )
        , mTexCoordList (0)
        , mColorList (0)
		, mCurrentPrimitiveType(NONE)
		, mPOrPhElementCountOfCurrentPrimitive(0)
        , mInMesh (true)
	{
        if ( !geometryName.empty() )
            mMesh->setName ( geometryName );
        else if ( !geometryId.empty() )
            mMesh->setName ( geometryId );

        if ( !geometryId.empty() )
            mMesh->setOriginalId ( geometryId );
	}

    //------------------------------
    const COLLADAFW::UniqueId& MeshLoader::getUniqueId ()
    {
        switch ( mCurrentPrimitiveType )
        {
        case TRIANGLES:
        case LINES:
        case TRISTRIPS:
        case TRIFANS:
        case POLYGONS:
        case POLYGONS_HOLE:
		case POLYLIST: 
		case LINESTRIPS: 
            return mCurrentMeshPrimitive->getUniqueId (); break;
        default:
            if ( mMesh ) return mMesh->getUniqueId (); break;
        }

        return COLLADAFW::UniqueId::INVALID;
    }

    //------------------------------
    const InputUnshared* MeshLoader::getVertexInputBySemantic ( const InputSemantic::Semantic& semantic ) const 
    {
        // Search the vertex input elements for the semantic element.
        return getVertices().getInputBySemantic ( semantic );
    }

    //------------------------------
    const SourceBase* MeshLoader::getSourceByInputSemanticFromVertices ( const InputSemantic::Semantic& semantic ) const
    {
        // Check if the input element with the semantic is a vertex element.
        const InputUnshared* positionsInput = getVertexInputBySemantic ( semantic );
        if ( positionsInput == 0 ) return 0;

        // Get the source element with the uri of the input element.
        COLLADABU::URI positionsInputSource = positionsInput->getSource ();
        String sourceId = positionsInputSource.getFragment ();

        return getSourceById ( sourceId );
    }

    //------------------------------
    const SourceBase* MeshLoader::getPositionsSource () const
    {
        return getSourceByInputSemanticFromVertices ( InputSemantic::POSITION );
    }

 
    //------------------------------
    void MeshLoader::loadSourceElements ( const MeshPrimitiveInputList& polyBaseElement )
    {
        const InputSharedArray& inputArray = polyBaseElement.getInputArray ();
        size_t numInputElements = inputArray.getCount ();
        for ( size_t n=0; n<numInputElements; ++n )
        {
            // Get the input element and read the semantic.
            InputShared* input = inputArray [n];

            // Load the source element of the current input element into the framework mesh.
            loadSourceElement ( *input );
        }
    }

    //------------------------------
    bool MeshLoader::loadSourceElement ( const InputShared& input )
    {
        bool retValue = false;

        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        switch ( semantic )
        {
        case InputSemantic::POSITION:
            retValue = loadPositionsSourceElement ( input );
            break;
        case InputSemantic::NORMAL:
            retValue = loadNormalsSourceElement ( input );
            break;
        case InputSemantic::COLOR:
            retValue = loadColorsSourceElement ( input );
            break;
        case InputSemantic::UV:
        case InputSemantic::TEXCOORD:
            retValue = loadTexCoordsSourceElement ( input );
            break;
        case InputSemantic::TEXTANGENT:
            retValue = loadTexTangentSourceElement( input );
            break;
        case InputSemantic::TEXBINORMAL:
            retValue = loadTexBinormalSourceElement( input );
            break;
        default:
            // Not implemented source
//            std::cerr << "Source with semantic " << semantic << "not implemented!" << std::endl;
            retValue = false;
        }

        return retValue;
    }

	//------------------------------
    bool MeshLoader::loadPositionsSourceElement ( const InputShared& input )
    {
        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::POSITION )
        {
            std::cerr << "The current input element is not a POSITION element!" << std::endl;
            return false;
        }

        // Get the source element with the uri of the input element.
        COLLADABU::URI inputUrl = input.getSource ();
        String sourceId = inputUrl.getFragment ();
        SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) return false;
        
        // Check if the source element is already loaded.
        if ( sourceBase->isLoadedInputElement ( semantic ) ) return false;

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
                /* unsigned long long stride = source->getStride (); */ /* UNUSED */

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                COLLADAFW::MeshVertexData& positions = mMesh->getPositions ();
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
                sourceBase->addLoadedInputElement ( semantic );

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
                COLLADAFW::MeshVertexData& positions = mMesh->getPositions ();
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
                sourceBase->addLoadedInputElement ( semantic );

                break;
            }
        default:
            std::cerr << "Position source has an other datatype as float or double! " << dataType << std::endl;
            return false;
        }

        return true;
    }

	//------------------------------
    bool MeshLoader::loadNormalsSourceElement ( const InputShared& input )
    {
        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::NORMAL )
        {
            std::cerr << "The current input element is not a NORMAL element!" << std::endl;
            return false;
        }

        // Get the source element with the uri of the input element.
        COLLADABU::URI inputUrl = input.getSource ();
        String sourceId = inputUrl.getFragment ();
        SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) return false;

        // Check if the source element is already loaded.
        if ( sourceBase->isLoadedInputElement ( semantic ) ) return false;

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

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                COLLADAFW::MeshVertexData& normals = mMesh->getNormals ();
                const size_t initialIndex = normals.getValuesCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                normals.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT );
                if ( initialIndex != 0 ) 
				{
					normals.appendValues ( valuesArray );
				}
                else 
				{
					normals.setData ( valuesArray.getData (), valuesArray.getCount () );
					valuesArray.yieldOwnerShip();
				}

                // Set the source base as loaded element.
                sourceBase->addLoadedInputElement ( semantic );

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
                COLLADAFW::MeshVertexData& normals = mMesh->getNormals ();
                const size_t initialIndex = normals.getValuesCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                normals.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE );
                if ( initialIndex != 0 ) 
				{
					normals.appendValues ( valuesArray );
				}
                else 
				{ 
					normals.setData ( valuesArray.getData (), valuesArray.getCount () );
					valuesArray.yieldOwnerShip();
				}

                // Set the source base as loaded element.
                sourceBase->addLoadedInputElement ( semantic );

                break;
            }
        default:
            std::cerr << "Normals source has an other datatype as float or double! " << dataType << std::endl;
            return false;
        }

        return true;
    }
    //------------------------------
    bool MeshLoader::loadColorsSourceElement ( const InputShared& input )
    {
        bool retValue = true;

        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::COLOR )
        {
            std::cerr << "The current input element is not a COLOR element!" << std::endl;
            return false;
        }

        // Get the source element with the uri of the input element.
        COLLADABU::URI inputUrl = input.getSource ();
        String sourceId = inputUrl.getFragment ();
        SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) return false;

        // Check if the source element is already loaded.
        if ( sourceBase->isLoadedInputElement ( semantic ) ) return false;

        // Get the stride of the uv coordinates. 
        // This is the dimension of the uv coordinates.
        // In depend on the dimension, we store the coordinates in the mesh.
        unsigned long long stride = sourceBase->getStride ();
        if ( stride < 3 || stride > 4 )
        {
            std::cerr << "The color source " <<  input.getSource().getURIString () 
                << " has a wrong dimension of " << stride 
                << ". Dimensions between 3 (RGB) and 4 (RGBA) are allowed. " << std::endl;
            retValue = false;
        }
        else
        {
            COLLADAFW::MeshVertexData& colors = mMesh->getColors ();
            retValue = appendVertexValues ( sourceBase, colors );
        }

        // Set the source base as loaded element.
        sourceBase->addLoadedInputElement ( semantic );

        return retValue;
    }

    bool MeshLoader::loadTexTangentSourceElement( const InputShared& input )
    {
        bool retValue = true;

        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::TEXTANGENT )
        {
            std::cerr << "The current input element is not a TEXTANGENT element!" << std::endl;
            return false;
        }

        // Get the source element with the uri of the input element.
        COLLADABU::URI inputUrl = input.getSource ();
        String sourceId = inputUrl.getFragment ();
        SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) return false;

        // Check if the source element is already loaded.
        if ( sourceBase->isLoadedInputElement ( semantic ) ) return false;

        // Get the stride of the uv coordinates. 
        // This is the dimension of the uv coordinates.
        // In depend on the dimension, we store the coordinates in the mesh.
        unsigned long long stride = sourceBase->getStride ();
        if ( stride !=  3 )
        {
            std::cerr << "The tangent source " <<  input.getSource().getURIString () 
                << " has a wrong dimension of " << stride 
                << ". Dimensions must be 3." << std::endl;
            retValue = false;
        }
        else
        {
            COLLADAFW::MeshVertexData& colors = mMesh->getTangents ();
            retValue = appendVertexValues ( sourceBase, colors );
        }

        // Set the source base as loaded element.
        sourceBase->addLoadedInputElement ( semantic );

        return retValue;
    }

    bool MeshLoader::loadTexBinormalSourceElement ( const InputShared& input )
    {
        bool retValue = true;

        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::TEXBINORMAL )
        {
            std::cerr << "The current input element is not a TEXBINORMAL element!" << std::endl;
            return false;
        }

        // Get the source element with the uri of the input element.
        COLLADABU::URI inputUrl = input.getSource ();
        String sourceId = inputUrl.getFragment ();
        SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) return false;

        // Check if the source element is already loaded.
        if ( sourceBase->isLoadedInputElement ( semantic ) ) return false;

        // Get the stride of the uv coordinates. 
        // This is the dimension of the uv coordinates.
        // In depend on the dimension, we store the coordinates in the mesh.
        unsigned long long stride = sourceBase->getStride ();
        if ( stride !=  3 )
        {
            std::cerr << "The binormal source " <<  input.getSource().getURIString () 
                << " has a wrong dimension of " << stride 
                << ". Dimensions must be 3." << std::endl;
            retValue = false;
        }
        else
        {
            COLLADAFW::MeshVertexData& colors = mMesh->getBinormals ();
            retValue = appendVertexValues ( sourceBase, colors );
        }

        // Set the source base as loaded element.
        sourceBase->addLoadedInputElement ( semantic );

        return retValue;
    }

    //------------------------------
    bool MeshLoader::appendVertexValues ( 
        SourceBase* sourceBase, 
        COLLADAFW::MeshVertexData &vertexData )
    {
        bool retValue = true;

        // Check if there are already some values in the positions list.
        // If so, we have to store the last index to increment the following indexes.
        const size_t initialIndex = vertexData.getValuesCount ();
        sourceBase->setInitialIndex ( initialIndex );

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

                // Push the values with the infos into the list.
                vertexData.appendValues ( valuesArray, source->getId (), (size_t) source->getStride () );

                break;  
            }
        case SourceBase::DATA_TYPE_DOUBLE:
            {
                // Get the values array from the source
                DoubleSource* source = ( DoubleSource* ) sourceBase;
                DoubleArrayElement& arrayElement = source->getArrayElement ();
                COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement.getValues ();

                // Push the values with the infos into the list.
                vertexData.appendValues ( valuesArray, source->getId (), (size_t) source->getStride () );

                break;
            }
        default:
            std::cerr << "Source has an other datatype as float or double! " << dataType << std::endl;
            retValue = false;
        }

        return retValue;
    }

    //------------------------------
    bool MeshLoader::loadTexCoordsSourceElement ( const InputShared& input )
    {
        bool retValue = true;

        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::UV && semantic != InputSemantic::TEXCOORD )
        {
            std::cerr << "The current input element is not a UV / TEXCOORD element!" << std::endl;
            return false;
        }

        // Get the source element with the uri of the input element.
        COLLADABU::URI inputUrl = input.getSource ();
        String sourceId = inputUrl.getFragment ();
        SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) return false;

        // Check if the source element is already loaded.
        if ( sourceBase->isLoadedInputElement ( semantic ) ) return false;

        // Get the stride of the uv coordinates. 
        // This is the dimension of the uv coordinates.
        // In depend on the dimension, we store the coordinates in the mesh.
        unsigned long long stride = sourceBase->getStride ();
        if ( stride < 2 || stride > 4 )
        {
            std::cerr << "The uv source " <<  input.getSource().getURIString () 
                << " has a wrong dimension of " << stride 
                << ". Dimensions between 2 and 4 are allowed. " << std::endl;
            retValue = false;
        }
        else
        {
            COLLADAFW::MeshVertexData& uvCoords = mMesh->getUVCoords ();
            retValue = appendVertexValues ( sourceBase, uvCoords );
        }

        // Set the source base as loaded element.
        sourceBase->addLoadedInputElement ( semantic );

        return retValue;
    }

    //------------------------------
	bool MeshLoader::writePrimitiveIndices ( const unsigned long long* data, size_t length )
	{
		// check, if we are parsing an unsupported primitive type
		if ( !mCurrentMeshPrimitive )
			return true;

		// Write the index values in the index lists.
		for ( size_t i=0; i<length; ++i )
		{
			// Get the current index value.
			unsigned int index = (unsigned int)data [i];

			// Write the indices
			if ( mUsePositions && (mCurrentOffset == mPositionsOffset) )
			{
				COLLADAFW::UIntValuesArray& positionIndices = mCurrentMeshPrimitive->getPositionIndices();
				positionIndices.append ( index + mPositionsIndexOffset );
			}

			if ( mUseNormals && (mCurrentOffset == mNormalsOffset) )
			{
				COLLADAFW::UIntValuesArray& normalIndices = mCurrentMeshPrimitive->getNormalIndices();
				normalIndices.append ( index + mNormalsIndexOffset );
			}

            if ( mUseTangents && (mCurrentOffset == mTangentsOffset) )
            {
                COLLADAFW::UIntValuesArray& tangentIndices = mCurrentMeshPrimitive->getTangentIndices();
                tangentIndices.append ( index + mTangentsIndexOffset );
            }

            if ( mUseBinormals && (mCurrentOffset == mBinormalsOffset) )
            {
                COLLADAFW::UIntValuesArray& binormalIndices = mCurrentMeshPrimitive->getBinormalIndices();
                binormalIndices.append ( index + mBinormalsIndexOffset );
            }


            // Look if the current offset is a texcoord offset.
            size_t numTexCoordinates = mTexCoordList.size();
            for ( size_t j=0; j<numTexCoordinates; ++j )
            {
                PrimitiveInput& texCoord = mTexCoordList[j];
                if ( mCurrentOffset == texCoord.mOffset )
                {
                    COLLADAFW::ArrayPrimitiveType<COLLADAFW::IndexList*>& texCoordIndicesArray = 
                        mCurrentMeshPrimitive->getUVCoordIndicesArray();

                    // Resize the array if necessary
                    if ( texCoordIndicesArray.getCount () != numTexCoordinates ) 
                    {
                        // Be careful: no constructor is called!
                        texCoordIndicesArray.reallocMemory ( numTexCoordinates );
                        for ( size_t k=0; k<numTexCoordinates; ++k )
                        {
                            COLLADAFW::IndexList* texCoordIndices = new COLLADAFW::IndexList ();
                            PrimitiveInput& tex = mTexCoordList [k];
                            texCoordIndices->setSetIndex ( tex.mSetIndex );
                            texCoordIndices->setName ( tex.mName );
                            texCoordIndices->setStride ( tex.mStride );
                            texCoordIndices->setInitialIndex ( tex.mInitialIndex );

                            texCoordIndicesArray.append( texCoordIndices );
                        }
                    }

                    // Write the values.
                    COLLADAFW::IndexList* texCoordIndices = mCurrentMeshPrimitive->getUVCoordIndices ( j );
                    texCoordIndices->getIndices().append ( index + (unsigned int)texCoord.mInitialIndex );
                }
            }

            // Look if the current offset is a texcoord offset.
            size_t numColors = mColorList.size ();
            for ( size_t j=0; j<numColors; ++j )
            {
                PrimitiveInput& color = mColorList [j];
                if ( mCurrentOffset == color.mOffset )
                {
                    COLLADAFW::ArrayPrimitiveType<COLLADAFW::IndexList*>& colorIndicesArray = 
                        mCurrentMeshPrimitive->getColorIndicesArray ();

                    // Resize the array if necessary
                    if ( colorIndicesArray.getCount () != numColors ) 
                    {
                        // Be careful: no constructor is called!
                        colorIndicesArray.reallocMemory ( numColors );
                        for ( size_t k=0; k<numColors; ++k )
                        {
                            COLLADAFW::IndexList* colorIndices = new COLLADAFW::IndexList ();
                            PrimitiveInput& col = mColorList [k];
                            colorIndices->setSetIndex ( col.mSetIndex );
                            colorIndices->setName ( col.mName );
                            colorIndices->setStride ( col.mStride );
                            colorIndices->setInitialIndex ( col.mInitialIndex );

                            colorIndicesArray.append ( colorIndices );
                        }
                    }

                    // Write the values.
                    COLLADAFW::IndexList* colorIndices = mCurrentMeshPrimitive->getColorIndices ( j );
                    colorIndices->getIndices().append ( index + (unsigned int)color.mInitialIndex );
                }
            }

			// Reset the offset if we went through all offset values
			if ( mCurrentOffset == mCurrentMaxOffset )
			{
				// Reset the current offset value
				mCurrentOffset = 0;
				++mCurrentVertexCount;
			}
			else
			{
				// Increment the current offset value
				++mCurrentOffset;
			}
		}
		return true;
	}


	//------------------------------
	void MeshLoader::initializeOffsets()
	{
        // Reset the members
        mCurrentOffset = 0;
        mPositionsOffset = 0;
        mPositionsIndexOffset = 0;
        mUsePositions = true;
        mNormalsOffset = 0;
        mNormalsIndexOffset = 0;
        mUseNormals = false;
        mUseTangents = false;
        mUseBinormals = false;
        mTexCoordList.clear ();
        mColorList.clear ();

		// We need the maximum offset value of the input elements to calculate the 
		// number of indices for each index list.
		mCurrentMaxOffset = (size_t)mMeshPrimitiveInputs.getInputArrayMaxOffset ();

		// The offset values of the input elements.
        initializePositionsOffset();
        initializeNormalsOffset();
        initializeColorsOffset();
        initializeTexCoordsOffset();
        initializeTangentsOffset();
        initializeBinormalsOffset();
	}

    //------------------------------
    void MeshLoader::initializePositionsOffset ()
    {
        const InputShared* positionInput = mMeshPrimitiveInputs.getPositionInput ();
		COLLADABU_ASSERT ( positionInput != 0 );
        if ( positionInput == 0 )
            handleFWLError ( SaxFWLError::ERROR_DATA_NOT_VALID, "No positions, can't import!", IError::SEVERITY_CRITICAL );

        // Get the offset value, the initial index values and alloc the memory.
        mPositionsOffset = positionInput->getOffset ();
        COLLADABU::URI inputUrl = positionInput->getSource ();
        String sourceId = inputUrl.getFragment ();
        const SourceBase* sourceBase = getSourceById ( sourceId );
        COLLADABU_ASSERT ( sourceBase != 0 );
        if ( sourceBase == 0 )
            handleFWLError ( SaxFWLError::ERROR_DATA_NOT_VALID, "Positions sourceBase is null.", IError::SEVERITY_CRITICAL );

        // only stride 3 makes sense for normals
        unsigned long long stride = sourceBase->getStride();
        if ( stride != 3 )
            handleFWLError ( SaxFWLError::ERROR_DATA_NOT_VALID, "Positios stride is not three.", IError::SEVERITY_CRITICAL );

        mPositionsIndexOffset = (unsigned int)sourceBase->getInitialIndex();
    }

    //------------------------------
    void MeshLoader::initializeNormalsOffset ()
    {
        // Check for using normals
        const InputShared* normalInput = mMeshPrimitiveInputs.getNormalInput ();
        if ( normalInput != 0 ) 
        {
            // Get the offset value, the initial index values and alloc the memory.
            mNormalsOffset = normalInput->getOffset ();
            const SourceBase* sourceBase = getSourceById ( normalInput->getSource ().getFragment () );
            if ( !sourceBase )
            {
                mNormalsIndexOffset = 0;
                mUseNormals = false;
            }
            else 
            {
                // only stride 3 makes sense for normals
                unsigned long long stride = sourceBase->getStride();
                if ( stride == 3 )
                {
                    mNormalsIndexOffset = (unsigned int)(sourceBase->getInitialIndex() / stride);
                    mUseNormals = true;
                }
                else
                {
                    mNormalsIndexOffset = 0;
                    mUseNormals = false;
                }
            }
        }
        else
        {
            mNormalsIndexOffset = 0;
            mUseNormals = false;
        }
    }

    //------------------------------
    void MeshLoader::initializeTangentsOffset ()
    {
        // Check for using normals
        const InputShared* tangentInput = mMeshPrimitiveInputs.getTangentInput ();
        if ( tangentInput != 0 ) 
        {
            // Get the offset value, the initial index values and alloc the memory.
            mTangentsOffset = tangentInput->getOffset ();
            const SourceBase* sourceBase = getSourceById ( tangentInput->getSource ().getFragment () );
            if ( !sourceBase )
            {
                mTangentsIndexOffset = 0;
                mUseTangents = false;
            }
            else 
            {
                // only stride 3 makes sense for normals
                unsigned long long stride = sourceBase->getStride();
                if ( stride == 3 )
                {
                    mTangentsIndexOffset = (unsigned int)(sourceBase->getInitialIndex() / stride);
                    mUseTangents = true;
                }
                else
                {
                    mTangentsIndexOffset = 0;
                    mUseTangents = false;
                }
            }
        }
        else
        {
            mTangentsIndexOffset = 0;
            mUseTangents = false;
        }
    }


    //------------------------------
    void MeshLoader::initializeBinormalsOffset ()
    {
        // Check for using normals
        const InputShared* binormalInput = mMeshPrimitiveInputs.getBinormalInput ();
        if ( binormalInput != 0 ) 
        {
            // Get the offset value, the initial index values and alloc the memory.
            mBinormalsOffset = binormalInput->getOffset ();
            const SourceBase* sourceBase = getSourceById ( binormalInput->getSource ().getFragment () );
            if ( !sourceBase )
            {
                mBinormalsIndexOffset = 0;
                mUseBinormals = false;
            }
            else 
            {
                // only stride 3 makes sense for normals
                unsigned long long stride = sourceBase->getStride();
                if ( stride == 3 )
                {
                    mBinormalsIndexOffset = (unsigned int)(sourceBase->getInitialIndex() / stride);
                    mUseBinormals = true;
                }
                else
                {
                    mBinormalsIndexOffset = 0;
                    mUseBinormals = false;
                }
            }
        }
        else
        {
            mBinormalsIndexOffset = 0;
            mUseBinormals = false;
        }
    }

    //------------------------------
    void MeshLoader::initializeColorsOffset ()
    {
        // Check for using colors
        const InputSharedArray& inputArray = mMeshPrimitiveInputs.getInputArray ();
        size_t numInputs = inputArray.getCount ();

        for ( size_t i=0; i<numInputs; ++i )
        {
            const InputShared* input = inputArray [i];
            if ( input->getSemantic () == InputSemantic::COLOR )
            {
                // TODO Id management!
                String sourceId = input->getSource ().getFragment ();
                SourceBase* sourceBase = getSourceById ( sourceId );
                if ( sourceBase == 0 ) 
                {
                    handleFWLError ( SaxFWLError::ERROR_DATA_NOT_VALID, "SourceBase of tex coords with semantic TEXCOORD not valid!" );
                    return;
                }

                // only stride 1, 2, 3 or 4 makes sense for uv coords
                size_t stride = ( size_t ) sourceBase->getStride();
                COLLADABU_ASSERT ( (stride >= 1) || (stride <= 4) ); 

                size_t intitialIndex = sourceBase->getInitialIndex ();
                size_t indexOffset = intitialIndex / stride;

                PrimitiveInput color;
                color.mOffset = ( size_t ) input->getOffset ();
                color.mInitialIndex = indexOffset;
                color.mStride = stride;
                color.mSetIndex = ( size_t ) input->getSet ();
                color.mName = sourceId;

                mColorList.push_back ( color );
            }
        }
    }

    //------------------------------
    void MeshLoader::initializeTexCoordsOffset ()
    {
        // Check for using tex coordinates 
        const InputSharedArray& inputArray = mMeshPrimitiveInputs.getInputArray ();
        size_t numInputs = inputArray.getCount ();

        for ( size_t i=0; i<numInputs; ++i )
        {
            const InputShared* input = inputArray [i];
            if ( input->getSemantic () == InputSemantic::TEXCOORD )
            {
                // TODO Id management!
                String sourceId = input->getSource ().getFragment ();
                SourceBase* sourceBase = getSourceById ( sourceId );
                if ( sourceBase == 0 ) 
                {
                    handleFWLError ( SaxFWLError::ERROR_DATA_NOT_VALID, "SourceBase of tex coords with semantic TEXCOORD not valid!" );
                    return;
                }

                // only stride 1, 2, 3 or 4 makes sense for uv coords
                size_t stride = ( size_t ) sourceBase->getStride();
                COLLADABU_ASSERT ( (stride >= 1) || (stride <= 4) ); 

                size_t intitialIndex = sourceBase->getInitialIndex ();
                size_t indexOffset = intitialIndex / stride;
 
                PrimitiveInput texCoord;
                texCoord.mOffset = ( size_t ) input->getOffset ();
                texCoord.mInitialIndex = indexOffset;
                texCoord.mStride = stride;
                texCoord.mSetIndex = ( size_t ) input->getSet ();
                texCoord.mName = sourceId;

                mTexCoordList.push_back ( texCoord );
            }
        }
    }


	//------------------------------
	void MeshLoader::initCurrentValues()
	{
		mCurrentVertexCount = 0;
		mCurrentLastPrimitiveVertexCount = 0;
		mCurrentExpectedVertexCount = 0;
		mCurrentMeshPrimitive = 0;
		mCurrentFaceOrLineCount = 0;
		mCurrentPhHasEmptyP = true;
		mPOrPhElementCountOfCurrentPrimitive = 0;
	}

	//------------------------------
	bool MeshLoader::end__mesh() 
	{
        mInMesh = false;

		// The mesh will be written by the GeometyLoader. Therefore nothing to with the mesh here
		finish();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__source( const source__AttributeData& attributes )
	{
		return beginSource(attributes);
	}

	//------------------------------
	bool MeshLoader::end__source(  )
	{
		return endSource();
	}

	//------------------------------
	bool MeshLoader::begin__vertices( const vertices__AttributeData& attributeData )
	{
        mInVertices = true;

		if ( attributeData.id )
			mVerticesInputs.setId( attributeData.id );
		if ( attributeData.name )
			mVerticesInputs.setName( attributeData.name );
		return true;
	}

	//------------------------------
	bool MeshLoader::end__vertices()
	{
        mInVertices = false;

		return true;
	}

	//------------------------------
	bool MeshLoader::begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData )
	{
		mCurrentVertexInput = new InputUnshared(attributeData.semantic, attributeData.source);
		return true;
	}

	//------------------------------
	bool MeshLoader::end__input____InputLocal()
	{
		mVerticesInputs.getInputArray().append(mCurrentVertexInput);
		mCurrentVertexInput = 0;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__triangles( const triangles__AttributeData& attributeData )
	{
		mCurrentPrimitiveType = TRIANGLES;
		mCurrentMeshPrimitive = new COLLADAFW::Triangles(createUniqueId(COLLADAFW::Triangles::ID()));
		if ( (size_t)attributeData.count > 0)
		{
			mCurrentMeshPrimitive->getPositionIndices().reallocMemory((size_t)attributeData.count);
			if ( mUseNormals )
			{
				mCurrentMeshPrimitive->getNormalIndices().reallocMemory((size_t)attributeData.count);
			}

            if ( mUseTangents )
            {
                mCurrentMeshPrimitive->getTangentIndices().reallocMemory((size_t)attributeData.count);
            }

            if ( mUseBinormals )
            {
                mCurrentMeshPrimitive->getBinormalIndices().reallocMemory((size_t)attributeData.count);
            }

			// TODO pre-alloc memory for uv indices
		}
		if ( attributeData.material )
		{
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId(attributeData.material));
			mCurrentMeshPrimitive->setMaterial(attributeData.material);
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__triangles()
	{
		size_t trianglesCount = mCurrentVertexCount/3;
		// check if the triangles really contains triangles. If not, we will discard it
		if ( trianglesCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(trianglesCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		mCurrentPrimitiveType = NONE;
		return true;
	}


	//------------------------------
	bool MeshLoader::begin__input____InputLocalOffset( const input____InputLocalOffset__AttributeData& attributeData )
	{
		return beginInput(attributeData);
	}

	//------------------------------
	bool MeshLoader::end__input____InputLocalOffset()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::beginInput( const input____InputLocalOffset__AttributeData& attributeData )
	{
		bool setPresent = (attributeData.present_attributes & input____InputLocalOffset__AttributeData::ATTRIBUTE_SET_PRESENT) == input____InputLocalOffset__AttributeData::ATTRIBUTE_SET_PRESENT;
		mMeshPrimitiveInputs.appendInputElement(new InputShared(attributeData.semantic, 
			attributeData.source, 
			attributeData.offset,
			setPresent ? attributeData.set : 0));
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__polylist( const polylist__AttributeData& attributeData )
	{
		mCurrentPrimitiveType = POLYLIST;
        COLLADAFW::Polygons* polygons = new COLLADAFW::Polygons(createUniqueId(COLLADAFW::Polygons::ID()));
		polygons->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = polygons;
		if ( attributeData.material )
		{
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( attributeData.material ));
			mCurrentMeshPrimitive->setMaterial(attributeData.material);

		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__polylist()
	{
		// check if there are enough vertices as expected by the vcount and that there exist at least
		// one polygon. If not, we will discard it
		if ( mCurrentVertexCount >= mCurrentExpectedVertexCount && mCurrentVertexCount > 0 )
		{
			COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
			COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();

			mCurrentMeshPrimitive->setFaceCount(vertexCountArray.getCount());
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		mCurrentPrimitiveType = NONE;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__lines( const lines__AttributeData& attributeData )
	{
        mCurrentPrimitiveType = LINES;
        if ( attributeData.material )
            mCurrentMeshMaterial = attributeData.material;
        mCurrentCOLLADAPrimitiveCount = (size_t)attributeData.count;
        return true;
	}

	//------------------------------
	bool MeshLoader::end__lines()
	{
        mMeshPrimitiveInputs.clearInputs();
        mCurrentPrimitiveType = NONE;
        return true;
// 		initCurrentValues();
// 		return true;
	}

	//------------------------------
	bool MeshLoader::begin__linestrips( const linestrips__AttributeData& attributeData )
	{
		COLLADAFW::Linestrips* lineStrips = new COLLADAFW::Linestrips(createUniqueId(COLLADAFW::Linestrips::ID()));
		// The actual size might be bigger, but its a lower bound
		lineStrips->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = lineStrips;
		mCurrentPrimitiveType = LINESTRIPS;
		if ( attributeData.material )
		{
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( attributeData.material ));
			mCurrentMeshPrimitive->setMaterial(attributeData.material);
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__linestrips()
	{
		mCurrentPrimitiveType = LINESTRIPS;
		// check if there is at least one linestrip. If not, we will discard it.
		if ( mCurrentFaceOrLineCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceOrLineCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		mCurrentPrimitiveType = NONE;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__vcount()
	{
//		initializeOffsets();
		return true;
	}

	//------------------------------
	bool MeshLoader::end__vcount()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::data__vcount( const unsigned long long* data, size_t length )
	{
		COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
		COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();
		size_t count = vertexCountArray.getCount();
		vertexCountArray.reallocMemory( count + length);
		for ( size_t i = 0; i < length; ++i)
		{
			unsigned long long vcount = data[i];
			vertexCountArray.append((unsigned int)vcount);
			mCurrentExpectedVertexCount += (size_t)vcount;
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__polygons( const polygons__AttributeData& attributeData )
	{
		mCurrentPrimitiveType = POLYGONS;
		COLLADAFW::Polygons* polygons = new COLLADAFW::Polygons(createUniqueId(COLLADAFW::Polygons::ID()));
		// The actual size might be bigger, but its a lower bound
		polygons->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = polygons;
		if ( attributeData.material )
		{
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( attributeData.material ));
			mCurrentMeshPrimitive->setMaterial(attributeData.material);
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__polygons()
	{
		// check if there is at least one polygon. If not, we will discard it.
		if ( mCurrentFaceOrLineCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceOrLineCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		mCurrentPrimitiveType = NONE;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__ph()
	{
		mCurrentPhHasEmptyP = true;
		mCurrentPrimitiveType = POLYGONS_HOLE;
		return true;
	}

	//------------------------------
	bool MeshLoader::end__ph()
	{
		mCurrentPrimitiveType = POLYGONS;
		mPOrPhElementCountOfCurrentPrimitive++;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__h()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::end__h()
	{
		int currentFaceVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
		if ( currentFaceVertexCount > 0 )
		{
			COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
			COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();
			vertexCountArray.append(-currentFaceVertexCount);
			mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::data__h( const uint64* data, size_t length )
	{
		// If the p element of the parent ph is empty, we don't need to read the h element
		if ( mCurrentPhHasEmptyP )
			return true;
		return writePrimitiveIndices(data, length);
	}

	//------------------------------
	bool MeshLoader::begin__tristrips( const tristrips__AttributeData& attributeData )
	{
		COLLADAFW::Tristrips* tristrips = new COLLADAFW::Tristrips(createUniqueId(COLLADAFW::Tristrips::ID()));
		// The actual size might be bigger, but its a lower bound
		tristrips->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = tristrips;
		mCurrentPrimitiveType = TRISTRIPS;
		if ( attributeData.material )
		{
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( attributeData.material ));
			mCurrentMeshPrimitive->setMaterial(attributeData.material);
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__tristrips()
	{
		mCurrentPrimitiveType = TRISTRIPS;
		// check if there is at least one tristrip. If not, we will discard it.
		if ( mCurrentFaceOrLineCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceOrLineCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		mCurrentPrimitiveType = NONE;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__trifans( const trifans__AttributeData& attributeData )
	{
		mCurrentPrimitiveType = TRIFANS;
		COLLADAFW::Trifans* trifans = new COLLADAFW::Trifans(createUniqueId(COLLADAFW::Trifans::ID()));
		// The actual size might be bigger, but its a lower bound
		trifans->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = trifans;
		if ( attributeData.material )
		{
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( attributeData.material ));
			mCurrentMeshPrimitive->setMaterial(attributeData.material);
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__trifans()
	{
		// check if there is at least one trifan. If not, we will discard it.
		if ( mCurrentFaceOrLineCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceOrLineCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		mCurrentPrimitiveType = NONE;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__p()
	{
		switch ( mCurrentPrimitiveType )
		{
		case TRIANGLES:
			{
				loadSourceElements(mMeshPrimitiveInputs);
				initializeOffsets();
			}
			break;
        case LINES:
            {
                loadSourceElements(mMeshPrimitiveInputs);
                initializeOffsets();
                mCurrentMeshPrimitive = new COLLADAFW::Lines(createUniqueId(COLLADAFW::Lines::ID()));
                if ( mCurrentCOLLADAPrimitiveCount > 0)
                {
                    mCurrentMeshPrimitive->getPositionIndices().reallocMemory(mCurrentCOLLADAPrimitiveCount);
                    if ( mUseNormals )
                    {
                        mCurrentMeshPrimitive->getNormalIndices().reallocMemory(mCurrentCOLLADAPrimitiveCount);
                    }
                    // TODO pre-alloc memory for uv indices
                }
                mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId(mCurrentMeshMaterial));
				mCurrentMeshPrimitive->setMaterial(mCurrentMeshMaterial);
            }
            break;
		case TRIFANS:
			{
				if ( mPOrPhElementCountOfCurrentPrimitive == 0)
				{
					loadSourceElements(mMeshPrimitiveInputs);
					initializeOffsets();
				}
				int currentTrifanVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
				if ( currentTrifanVertexCount > 0 )
				{
					COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) mCurrentMeshPrimitive;
					if ( currentTrifanVertexCount >= 3 )
					{
						COLLADAFW::Trifans::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray();
						vertexCountArray.append(currentTrifanVertexCount);
						trifans->setTrifanCount(trifans->getTrifanCount() + 1);
						mCurrentFaceOrLineCount += (currentTrifanVertexCount - 2);
					}
					else
					{
						trifans->getPositionIndices().erase(currentTrifanVertexCount);
						trifans->getNormalIndices().erase(currentTrifanVertexCount);

						const COLLADAFW::IndexListArray& colorIndicesArray = trifans->getColorIndicesArray ();
						for ( size_t i=0; i<colorIndicesArray.getCount (); ++i )
							trifans->getColorIndices(i)->getIndices ().erase(currentTrifanVertexCount);

						const COLLADAFW::IndexListArray& uvCoordIndicesArray = trifans->getUVCoordIndicesArray ();
						for ( size_t i=0; i<uvCoordIndicesArray.getCount (); ++i )
							trifans->getUVCoordIndices(i)->getIndices ().erase(currentTrifanVertexCount);
					}
					mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
				}
			}
			break;
		case TRISTRIPS:
		case POLYLIST:
		case POLYGONS:
        case POLYGONS_HOLE:
		case LINESTRIPS:
			{
				if ( mPOrPhElementCountOfCurrentPrimitive == 0)
				{
					loadSourceElements(mMeshPrimitiveInputs);
					initializeOffsets();
				}
			}
			break;
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::end__p()
	{
		mPOrPhElementCountOfCurrentPrimitive++;
		switch ( mCurrentPrimitiveType )
		{
		case TRIANGLES:
			{
				
			}
			break;
        case LINES:
            {
                size_t linesCount = mCurrentVertexCount/2;
                // check if the lines really contains lines. If not, we will discard it
                if ( linesCount > 0 )
                {
                    mCurrentMeshPrimitive->setFaceCount(linesCount);
                    mMesh->appendPrimitive(mCurrentMeshPrimitive);
                }
                else
                {
                    delete mCurrentMeshPrimitive;
                }
                initCurrentValues();
            }
            break;
        case TRIFANS:
			{
				int currentTrifanVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
				if ( currentTrifanVertexCount > 0 )
				{
					COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) mCurrentMeshPrimitive;
					if ( currentTrifanVertexCount >= 3 )
					{
						COLLADAFW::Trifans::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray();
						vertexCountArray.append(currentTrifanVertexCount);
						trifans->setTrifanCount(trifans->getTrifanCount() + 1);
						mCurrentFaceOrLineCount += (currentTrifanVertexCount - 2);
					}
					else
					{
						trifans->getPositionIndices().erase(currentTrifanVertexCount);
						trifans->getNormalIndices().erase(currentTrifanVertexCount);

						const COLLADAFW::IndexListArray& colorIndicesArray = trifans->getColorIndicesArray ();
						for ( size_t i=0; i<colorIndicesArray.getCount (); ++i )
							trifans->getColorIndices(i)->getIndices ().erase(currentTrifanVertexCount);

						const COLLADAFW::IndexListArray& uvCoordIndicesArray = trifans->getUVCoordIndicesArray ();
						for ( size_t i=0; i<uvCoordIndicesArray.getCount (); ++i )
							trifans->getUVCoordIndices(i)->getIndices ().erase(currentTrifanVertexCount);
					}
					mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
				}
			}
			break;
		case TRISTRIPS:
			{
				int currentTristripVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
				if ( currentTristripVertexCount > 0 )
				{
					COLLADAFW::Tristrips* tristrips = (COLLADAFW::Tristrips*) mCurrentMeshPrimitive;
					if ( currentTristripVertexCount >= 3 )
					{
						COLLADAFW::Tristrips::VertexCountArray& vertexCountArray = tristrips->getGroupedVerticesVertexCountArray();
						vertexCountArray.append(currentTristripVertexCount);
						tristrips->setTristripCount(tristrips->getTristripCount() + 1);
						mCurrentFaceOrLineCount += (currentTristripVertexCount - 2);
					}
					else
					{
						tristrips->getPositionIndices().erase(currentTristripVertexCount);
						tristrips->getNormalIndices().erase(currentTristripVertexCount);

						const COLLADAFW::IndexListArray& colorIndicesArray = tristrips->getColorIndicesArray ();
						for ( size_t i=0; i<colorIndicesArray.getCount (); ++i )
							tristrips->getColorIndices(i)->getIndices().erase(currentTristripVertexCount);

						const COLLADAFW::IndexListArray& uvCoordIndicesArray = tristrips->getUVCoordIndicesArray ();
						for ( size_t i=0; i<uvCoordIndicesArray.getCount (); ++i )
							tristrips->getUVCoordIndices(i)->getIndices ().erase(currentTristripVertexCount);
					}
					mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
				}
			}
			break;
		case LINESTRIPS:
			{
				int currentLinestripVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
				if ( currentLinestripVertexCount > 0 )
				{
					COLLADAFW::Linestrips* linestrips = (COLLADAFW::Linestrips*) mCurrentMeshPrimitive;
					if ( currentLinestripVertexCount >= 2 )
					{
						COLLADAFW::Tristrips::VertexCountArray& vertexCountArray = linestrips->getGroupedVerticesVertexCountArray();
						vertexCountArray.append(currentLinestripVertexCount);
						linestrips->setLinestripCount(linestrips->getLinestripCount() + 1);
						mCurrentFaceOrLineCount += (currentLinestripVertexCount - 1);
					}
					else
					{
						linestrips->getPositionIndices().erase(currentLinestripVertexCount);
						linestrips->getNormalIndices().erase(currentLinestripVertexCount);

						const COLLADAFW::IndexListArray& colorIndicesArray = linestrips->getColorIndicesArray ();
						for ( size_t i=0; i<colorIndicesArray.getCount (); ++i )
							linestrips->getColorIndices(i)->getIndices().erase(currentLinestripVertexCount);

						const COLLADAFW::IndexListArray& uvCoordIndicesArray = linestrips->getUVCoordIndicesArray ();
						for ( size_t i=0; i<uvCoordIndicesArray.getCount (); ++i )
							linestrips->getUVCoordIndices(i)->getIndices ().erase(currentLinestripVertexCount);
					}
					mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
				}
			}
			break;
		case POLYLIST:
			{

			}
			break;
		case POLYGONS:
			{
				int currentFaceVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
				if ( currentFaceVertexCount > 0 )
				{
					COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
					COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();
					vertexCountArray.append(currentFaceVertexCount);
					mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
					mCurrentFaceOrLineCount++;
				}
			}
			break;
		case POLYGONS_HOLE:
			{
				int currentPolygonVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
				if ( currentPolygonVertexCount > 0 )
				{
					COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
					COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();
					vertexCountArray.append(currentPolygonVertexCount);
					mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
					mCurrentFaceOrLineCount++;
					mCurrentPhHasEmptyP = false;
				}
				else
				{
					mCurrentPhHasEmptyP = true;
				}
			}
			break;
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::data__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
	}


} // namespace COLLADASaxFWL
