/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLGeometryMaterialIdInfo.h"

#include "COLLADAFWTriangles.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWPolygons.h"

#include "COLLADAFWIWriter.h"

#include <fstream>


namespace COLLADASaxFWL
{

	MeshLoader::MeshLoader( IFilePartLoader* callingFilePartLoader, const String& geometryId, const String& geometryName )
		: SourceArrayLoader (callingFilePartLoader )
		, mMeshUniqueId(getUniqueIdFromId((ParserChar*)geometryId.c_str(), COLLADAFW::Geometry::ID()))
		, mMesh ( new COLLADAFW::Mesh(mMeshUniqueId.getObjectId()) )
		, mMaterialIdInfo(getMeshMaterialIdInfo(mMeshUniqueId))
		, mCurrentMeshPrimitive(0)
		, mCurrentVertexInput(0)
		, mMeshPrimitiveInputs(mVerticesInputs)
		, mCurrentMeshPrimitiveInput(0)
		, mCurrentMaxOffset(0)
		, mCurrentVertexCount(0)
		, mCurrentLastPrimitiveVertexCount(0)
		, mCurrentPhHasEmptyP(true)
		, mCurrentExpectedVertexCount(0)
		, mCurrentFaceCount(0)
        , mCurrentOffset (0)
		, mPositionsOffset (0)
		, mPositionsIndexOffset(0)
		, mUsePositions ( true )
		, mNormalsOffset (0)
		, mNormalsIndexOffset(0)
		, mUseNormals ( false )
        , mTexCoordList (0)
        , mColorList (0)
	{
		if ( !geometryName.empty() )
			mMesh->setName ( geometryName );
		else if ( !geometryId.empty() )
			mMesh->setName ( geometryId );
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
        default:
            // Not implemented source
            std::cerr << "Source with semantic " << semantic << "not implemented!" << std::endl;
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

        // Check if the source element is already loaded.
        if ( sourceBase->getIsLoaded () ) 
			return false;

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
                COLLADAFW::MeshVertexData& positions = mMesh->getPositions ();
                const size_t initialIndex = positions.getValuesCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                positions.setType ( COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT );
                if ( initialIndex != 0 ) 
					positions.appendValues ( valuesArray );
                else 
					positions.setData ( valuesArray.getData (), valuesArray.getCount () );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

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
                if ( initialIndex != 0 ) positions.appendValues ( valuesArray );
                else positions.setData ( valuesArray.getData (), valuesArray.getCount () );
                
                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

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

        // Check if the source element is already loaded.
        if ( sourceBase->getIsLoaded () ) return false;

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
                if ( initialIndex != 0 ) normals.appendValues ( valuesArray );
                else normals.setData ( valuesArray.getData (), valuesArray.getCount () );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

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
                if ( initialIndex != 0 ) normals.appendValues ( valuesArray );
                else normals.setData ( valuesArray.getData (), valuesArray.getCount () );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

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

        // Check if the source element is already loaded.
        if ( sourceBase->getIsLoaded () ) return false;

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
        sourceBase->setIsLoaded ( true );

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

        // Check if the source element is already loaded.
        if ( sourceBase->getIsLoaded () ) return false;

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
        sourceBase->setIsLoaded ( true );

        return retValue;
    }

    //------------------------------
	bool MeshLoader::writePrimitiveIndices ( const unsigned long long* data, size_t length )
	{
		// Write the index values in the index lists.
		for ( size_t i=0; i<length; ++i )
		{
			// Get the current index value.
			unsigned int index = (unsigned int)data [i];

			// Write the indices
			if ( mCurrentOffset == mPositionsOffset )
			{
                if ( mUsePositions )
                {
                    COLLADAFW::UIntValuesArray& positionIndices = mCurrentMeshPrimitive->getPositionIndices ();
                    positionIndices.append ( index + mPositionsIndexOffset );
                }
			}
			else if ( mCurrentOffset == mNormalsOffset )
			{
                if ( mUseNormals )
                {
                    COLLADAFW::UIntValuesArray& normalIndices = mCurrentMeshPrimitive->getNormalIndices ();
                    normalIndices.append ( index + mNormalsIndexOffset );
                }
			}
			else 
            {
                // Look if the current offset is a texcoord offset.
                size_t numTexCoordinates = mTexCoordList.size ();
                for ( size_t j=0; j<numTexCoordinates; ++j )
                {
                    PrimitiveInput& texCoord = mTexCoordList [j];
                    if ( mCurrentOffset == texCoord.mOffset )
                    {
                        COLLADAFW::ArrayPrimitiveType<COLLADAFW::IndexList*>& texCoordIndicesArray = 
                            mCurrentMeshPrimitive->getUVCoordIndicesArray ();

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

                                texCoordIndicesArray.append ( texCoordIndices );
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
                        colorIndices->getIndices().append ( index + color.mInitialIndex );
                    }
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


#if 0
	//------------------------------
    bool MeshLoader::initializeIndexLists ( 
        COLLADAFW::MeshPrimitive* primitiveElement, 
        const InputList* polyBaseElement )
    {
        // Get the index lists.
        COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();
        COLLADAFW::UIntValuesArray& normalIndices = primitiveElement->getNormalIndices ();
        COLLADAFW::UIntValuesArray& colorIndices = primitiveElement->getColorIndices ();
        COLLADAFW::UIntValuesArray& uvCoordIndices = primitiveElement->getUVCoordIndices ();

        // We need the maximum offset value of the input elements to calculate the 
        // number of indices for each index list.
        const size_t maxOffset = polyBaseElement->getInputArrayMaxOffset ();

        // Get the number of all indices in all p elements in the current primitive element.
//        size_t numPIndices = polyBaseElement->getIndexCount ();
  //      if ( numPIndices == 0 ) numPIndices = getNumOfPrimitiveIndices ( polyBaseElement );
		assert(false);

        // Get the number of index elements in the index list for each input element.
        size_t numElements = numPIndices / maxOffset;

        // The offset values of the input elements.
        const InputShared* input = polyBaseElement->getPositionInput ();
        if ( input == 0 ) 
        {
            throw new ColladaSaxFrameworkLoaderException ( "No positions input element!" );
            return false;
        }
        // Get the offset value, the initial index values and alloc the memory.
        mPositionsOffset = input->getOffset ();
        COLLADABU::URI inputUrl = input->getSource ();
        String sourceId = inputUrl.getFragment ();
        const SourceBase* sourceBase = getSourceById ( sourceId );
        if ( sourceBase == 0 ) 
        {   
            // TODO error handling!
            return false;
        }
        positionIndices.reallocMemory ( numElements );

        // Check for using normals
        input = polyBaseElement->getNormalInput ();
        if ( input != 0 ) 
        {
            // Get the offset value, the initial index values and alloc the memory.
            mNormalsOffset = input->getOffset ();
            sourceBase = getSourceById ( input->getSource ().getFragment () );
            normalIndices.reallocMemory ( numElements );
            mUseNormals = true;
        }

        // Check for using colors
        input = polyBaseElement->getColorInput ();
        if ( input != 0 ) 
        {
            // Get the offset value and alloc the memory.
            mColorsOffset = input->getOffset ();
            colorIndices.reallocMemory ( numElements );
            mUseColors = true;
        }

        // Check for using uv coordinates 
        input = polyBaseElement->getUVCoordInput ();
        if ( input != 0 ) 
        {
            // Get the offset value and alloc the memory.
            mUVCoordsOffset = input->getOffset ();
            uvCoordIndices.reallocMemory ( numElements );
            mUseUVCoords = true;
        }

        return true;
    }
#endif

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
	}

    //------------------------------
    void MeshLoader::initializePositionsOffset ()
    {
        const InputShared* positionInput = mMeshPrimitiveInputs.getPositionInput ();
        assert ( positionInput != 0 );

        // Get the offset value, the initial index values and alloc the memory.
        mPositionsOffset = positionInput->getOffset ();
        COLLADABU::URI inputUrl = positionInput->getSource ();
        String sourceId = inputUrl.getFragment ();
        const SourceBase* sourceBase = getSourceById ( sourceId );
        assert ( sourceBase != 0 );
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
            unsigned long long stride = sourceBase->getStride();
            // only stride 3 makes sense for normals
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
        else
        {
            mNormalsIndexOffset = 0;
            mUseNormals = false;
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

                // only stride 1, 2, 3 or 4 makes sense for uv coords
                size_t stride = ( size_t ) sourceBase->getStride();
                assert ( (stride >= 1) || (stride <= 4) ); 

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

                // only stride 1, 2, 3 or 4 makes sense for uv coords
                size_t stride = ( size_t ) sourceBase->getStride();
                assert ( (stride >= 1) || (stride <= 4) ); 

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


#if 0
    //------------------------------
    void MeshLoader::loadFaceVertexCountArray ( 
        COLLADAFW::MeshPrimitive* primitiveElement, 
        const PolyBase* polyBaseElement )
    {
        // TODO Not all types implemented!
        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = polyBaseElement->getPrimitiveType ();

        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::POLYGONS:
            {
                // Calculate to get the polygonal face vertex counts 
                // and push them in the face vertex count list.

                // Allocate the necessary memory
                COLLADAFW::UIntValuesArray& faceVertexCountArray = primitiveElement->getFaceVertexCountArray ();
                faceVertexCountArray.allocMemory ( polyBaseElement->getFaceCount () );

                // Write the number of vertices for every face in the list of face vertex counts.
                Polygons* polygons = ( Polygons* ) polyBaseElement;

                // The current index in the face vertex count array.
                size_t index = 0;

                // TODO What's about the order of the elements? 
                const PArray& pArray = polyBaseElement->getPArray ();
                size_t numPElements = pArray.getCount ();
                for ( size_t j=0; j<numPElements; ++j )
                {
                    // Count the number of p elements.
                    PElement* pElement = pArray [j];
                    faceVertexCountArray [ index++ ] = pElement->getCount();
                }
                // Every ph element has exact one p element.
                Polygons* polygonsElement = ( Polygons* ) polyBaseElement;
                const PHArray& phArray = polygonsElement->getPHArray ();
                size_t numPHElements = phArray.getCount ();
                for ( size_t j=0; j<numPHElements; ++j )
                {
                    // Count the number of p elements.
                    const PHElement* phElement = phArray [j];
                    const PElement& pElement = phElement->getPElement ();
                    faceVertexCountArray [ index++ ] = pElement.getCount();
                }

                break;
            }
        case COLLADAFW::MeshPrimitive::POLYLIST:
            {
                // A POLYLIST element should already has set the face vertex count array. 
                Polylist* polylist = ( Polylist* ) polyBaseElement;
                COLLADAFW::UIntValuesArray& vCountArray = polylist->getVCountArray ();

                COLLADAFW::UIntValuesArray& faceVertexCountArray = primitiveElement->getFaceVertexCountArray ();
                faceVertexCountArray.setData ( vCountArray.getData (), vCountArray.getCount (), vCountArray.getCapacity () );
                break;
            }
        case COLLADAFW::MeshPrimitive::TRIANGLES:
            // TODO Always three, we don't need to store!?
            break;
        default:
            std::cerr << "Type not implemented! " << std::endl;
            return;
        }
    }
#endif 

#if 0
    //------------------------------
    void MeshLoader::loadIndexLists ( 
        COLLADAFW::MeshPrimitive* primitiveElement, 
        const PolyBase* polyBaseElement )
    {
        // TODO Not all types implemented!
        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = polyBaseElement->getPrimitiveType ();

        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
        case COLLADAFW::MeshPrimitive::TRIANGLES:
            {
                // Initialize the size of the index lists, check for used source elements and get 
                // the offset values of the index lists.
                if ( initializeIndexLists ( primitiveElement, polyBaseElement) == false ) return;

                // TODO Iterate over all existing p elements and get the index values.
                // (not about triangles and polylists, but about the polygons)

                // Get the maximum offset value in the input list.
                const size_t maxOffset = polyBaseElement->getInputArrayMaxOffset ();

                // Write the indexes of p elements of the p array.
                const PArray& pArray = polyBaseElement->getPArray ();
                size_t numPElements = pArray.getCount ();
                for ( size_t j=0; j<numPElements; ++j )
                {
                    const PElement* pElement = pArray [j];
                    writePElementIndices( pElement, primitiveElement, maxOffset );
                }

                if ( primitiveType == COLLADAFW::MeshPrimitive::POLYGONS )
                {
                    // Write the indexes of the p elements of each ph element in the the ph array.
                    Polygons* polygonsElement = ( Polygons* ) polyBaseElement;
                    const PHArray& phArray = polygonsElement->getPHArray ();
                    size_t numPHElements = phArray.getCount ();
                    for ( size_t j=0; j<numPHElements; ++j )
                    {
                        // Count the number of p elements.
                        const PHElement* phElement = phArray [j];
                        const PElement& pElement = phElement->getPElement ();
                        writePElementIndices( &pElement, primitiveElement, maxOffset );
                    }
                }

                // Output
                std::ofstream outFile;
                outFile.open ( "C:\\Temp\\DebugLog.txt", std::ios_base::out );

                // Get the index lists.
                COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();
                COLLADAFW::UIntValuesArray& normalIndices = primitiveElement->getNormalIndices ();
                COLLADAFW::UIntValuesArray& colorIndices = primitiveElement->getColorIndices ();
                COLLADAFW::UIntValuesArray& uvCoordIndices = primitiveElement->getUVCoordIndices ();

                outFile << "position indices = ";
                for ( size_t p=0; p<positionIndices.getCount (); ++p )
                    outFile << positionIndices[p] << ", ";
                outFile << std::endl;

                outFile << "normal indices = ";
                for ( size_t p=0; p<normalIndices.getCount (); ++p )
                    outFile << normalIndices[p] << ", ";
                outFile << std::endl;

                outFile << "color indices = ";
                for ( size_t p=0; p<colorIndices.getCount (); ++p )
                    outFile << colorIndices[p] << ", ";
                outFile << std::endl;

                outFile << "uv coord indices = ";
                for ( size_t p=0; p<uvCoordIndices.getCount (); ++p )
                    outFile << uvCoordIndices[p] << ", ";
                outFile << std::endl;

                break;
            }
        default:
            // No more implementations.
            std::cerr << "Primitive type " << primitiveType << " not implemented!";
            return;
        }
    }
#endif

	//------------------------------
	void MeshLoader::initCurrentValues()
	{
		mCurrentVertexCount = 0;
		mCurrentLastPrimitiveVertexCount = 0;
		mCurrentExpectedVertexCount = 0;
		mCurrentMeshPrimitive = 0;
		mCurrentFaceCount = 0;
		mCurrentPhHasEmptyP = true;
		mCurrentMeshMaterial.clear();
	}

	//------------------------------
	bool MeshLoader::end__mesh() 
	{
		bool success = writer()->writeGeometry(mMesh);
		delete mMesh;
		finish();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__mesh__source( const mesh__source__AttributeData& attributes )
	{
		return beginSource(attributes);
	}

	//------------------------------
	bool MeshLoader::end__mesh__source(  )
	{
		return endSource();
	}

	//------------------------------
	bool MeshLoader::begin__mesh__vertices( const vertices__AttributeData& attributeData )
	{
		if ( attributeData.id )
			mVerticesInputs.setId( (const char*)attributeData.id );
		if ( attributeData.name )
			mVerticesInputs.setName( (const char*)attributeData.name );
		return true;
	}

	//------------------------------
	bool MeshLoader::end__mesh__vertices()
	{
		//we don't need to do anything here
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__vertices__input( const vertices__input__AttributeData& attributeData )
	{
		mCurrentVertexInput = new InputUnshared((const char*)attributeData.semantic, (const char*)attributeData.source);
		return true;
	}

	//------------------------------
	bool MeshLoader::end__vertices__input()
	{
		mVerticesInputs.getInputArray().append(mCurrentVertexInput);
		mCurrentVertexInput = 0;
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__mesh__triangles( const triangles__AttributeData& attributeData )
	{
		if ( attributeData.material )
			mCurrentMeshMaterial = (const char *)attributeData.material;
		return true;
	}

	//------------------------------
	bool MeshLoader::end__mesh__triangles()
	{
		mMeshPrimitiveInputs.clearInputs();
		return true;
	}


	//------------------------------
	bool MeshLoader::begin__triangles__input( const triangles__input__AttributeData& attributeData )
	{
		return beginInput(attributeData);
	}

	//------------------------------
	bool MeshLoader::end__triangles__input()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::beginInput( const triangles__input__AttributeData& attributeData )
	{
		mMeshPrimitiveInputs.appendInputElement(new InputShared((const char*)attributeData.semantic, 
			(const char*)attributeData.source, 
			attributeData.offset,
			attributeData.set));
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__triangles__p()
	{
		loadSourceElements(mMeshPrimitiveInputs);
		initializeOffsets();
		mCurrentMeshPrimitive = new COLLADAFW::Triangles();
		mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId(mCurrentMeshMaterial));
		return true;
	}

	//------------------------------
	bool MeshLoader::end__triangles__p()
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
		return true;
	}

	//------------------------------
	bool MeshLoader::data__triangles__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
	}

	//------------------------------
	bool MeshLoader::begin__mesh__polylist( const polylist__AttributeData& attributeData )
	{
		COLLADAFW::Polygons* polygons = new COLLADAFW::Polygons();
		polygons->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = polygons;
		if ( attributeData.material )
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( (const char*)attributeData.material ));
		return true;
	}

	//------------------------------
	bool MeshLoader::end__mesh__polylist()
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
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__polylist__input( const polylist__input__AttributeData& attributeData )
	{
		return beginInput( *((triangles__input__AttributeData*)&attributeData) );
	}

	//------------------------------
	bool MeshLoader::end__polylist__input()
	{
		loadSourceElements(mMeshPrimitiveInputs);
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__polylist__vcount()
	{
		initializeOffsets();
		return true;
	}

	//------------------------------
	bool MeshLoader::end__polylist__vcount()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::data__polylist__vcount( const unsigned long long* data, size_t length )
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
	bool MeshLoader::begin__polylist__p()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::end__polylist__p()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::data__polylist__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
	}

	//------------------------------
	bool MeshLoader::begin__mesh__polygons( const polygons__AttributeData& attributeData )
	{
		COLLADAFW::Polygons* polygons = new COLLADAFW::Polygons();
		// The actual size might be bigger, but its a lower bound
		polygons->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = polygons;
		if ( attributeData.material )
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( (const char*)attributeData.material ));
		return true;
	}

	//------------------------------
	bool MeshLoader::end__mesh__polygons()
	{
		// check if there is at least one polygon. If not, we will discard it.
		if ( mCurrentFaceCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__polygons__input( const polygons__input__AttributeData& attributeData )
	{
		return beginInput( *((triangles__input__AttributeData*)&attributeData) );
	}

	//------------------------------
	bool MeshLoader::end__polygons__input()
	{
		loadSourceElements(mMeshPrimitiveInputs);
		initializeOffsets();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__polygons__p()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::end__polygons__p()
	{
		int currentFaceVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
		if ( currentFaceVertexCount > 0 )
		{
			COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
			COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();
			vertexCountArray.append(currentFaceVertexCount);
			mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
			mCurrentFaceCount++;
		}

		return true;
	}

	//------------------------------
	bool MeshLoader::data__polygons__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
	}

	//------------------------------
	bool MeshLoader::begin__ph()
	{
		mCurrentPhHasEmptyP = true;
		return true;
	}

	//------------------------------
	bool MeshLoader::end__ph()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__ph__p()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::end__ph__p()
	{
		int currentPolygonVertexCount = (int)mCurrentVertexCount - (int)mCurrentLastPrimitiveVertexCount;
		if ( currentPolygonVertexCount > 0 )
		{
			COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) mCurrentMeshPrimitive;
			COLLADAFW::Polygons::VertexCountArray& vertexCountArray = polygons->getGroupedVerticesVertexCountArray();
			vertexCountArray.append(currentPolygonVertexCount);
			mCurrentLastPrimitiveVertexCount = mCurrentVertexCount;
			mCurrentFaceCount++;
			mCurrentPhHasEmptyP = false;
		}
		else
		{
			mCurrentPhHasEmptyP = true;
		}
		return true;
	}

	//------------------------------
	bool MeshLoader::data__ph__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
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
	bool MeshLoader::data__h( const unsigned long long* data, size_t length )
	{
		// If the p element of the parent ph is empty, we don't need to read the h element
		if ( mCurrentPhHasEmptyP )
			return true;
		return writePrimitiveIndices(data, length);
	}

	//------------------------------
	bool MeshLoader::begin__mesh__tristrips( const tristrips__AttributeData& attributeData )
	{
		COLLADAFW::Tristrips* tristrips = new COLLADAFW::Tristrips();
		// The actual size might be bigger, but its a lower bound
		tristrips->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = tristrips;
		if ( attributeData.material )
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( (const char*)attributeData.material ));
		return true;
	}

	//------------------------------
	bool MeshLoader::end__mesh__tristrips()
	{
		// check if there is at least one tristrip. If not, we will discard it.
		if ( mCurrentFaceCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__tristrips__input( const tristrips__input__AttributeData& attributeData )
	{
		return beginInput( *((triangles__input__AttributeData*)&attributeData) );
	}

	//------------------------------
	bool MeshLoader::end__tristrips__input()
	{
		loadSourceElements(mMeshPrimitiveInputs);
		initializeOffsets();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__tristrips__p()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::end__tristrips__p()
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
				mCurrentFaceCount += (currentTristripVertexCount - 2);
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
		return true;
	}

	//------------------------------
	bool MeshLoader::data__tristrips__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
	}



	//------------------------------
	bool MeshLoader::begin__mesh__trifans( const trifans__AttributeData& attributeData )
	{
		COLLADAFW::Trifans* trifans = new COLLADAFW::Trifans();
		// The actual size might be bigger, but its a lower bound
		trifans->getGroupedVerticesVertexCountArray().allocMemory((size_t)attributeData.count);
		mCurrentMeshPrimitive = trifans;
		if ( attributeData.material )
			mCurrentMeshPrimitive->setMaterialId(mMaterialIdInfo.getMaterialId( (const char*)attributeData.material ));
		return true;
	}

	//------------------------------
	bool MeshLoader::end__mesh__trifans()
	{
		// check if there is at least one trifan. If not, we will discard it.
		if ( mCurrentFaceCount > 0 )
		{
			mCurrentMeshPrimitive->setFaceCount(mCurrentFaceCount);
			mMesh->appendPrimitive(mCurrentMeshPrimitive);
		}
		else
		{
			delete mCurrentMeshPrimitive;
		}
		initCurrentValues();
		mMeshPrimitiveInputs.clearInputs();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__trifans__input( const trifans__input__AttributeData& attributeData )
	{
		return beginInput( *((triangles__input__AttributeData*)&attributeData) );
	}

	//------------------------------
	bool MeshLoader::end__trifans__input()
	{
		loadSourceElements(mMeshPrimitiveInputs);
		initializeOffsets();
		return true;
	}

	//------------------------------
	bool MeshLoader::begin__trifans__p()
	{
		return true;
	}

	//------------------------------
	bool MeshLoader::end__trifans__p()
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
				mCurrentFaceCount += (currentTrifanVertexCount - 2);
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
		return true;
	}

	//------------------------------
	bool MeshLoader::data__trifans__p( const unsigned long long* data, size_t length )
	{
		return writePrimitiveIndices(data, length);
	}

} // namespace COLLADASaxFWL
