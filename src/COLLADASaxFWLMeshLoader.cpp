/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLPolylist.h"


namespace COLLADASaxFWL
{

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
    const FloatSource* MeshLoader::getPositionsFloatSource () const
    {
        const SourceBase* positionsSource = getPositionsSource ();

        if ( positionsSource->getDataType () != SourceBase::DATA_TYPE_FLOAT )
            return 0;

        return ( FloatSource* ) positionsSource;
    }

    //------------------------------
    const DoubleSource* MeshLoader::getPositionsDoubleSource () const
    {
        const SourceBase* positionsSource = getPositionsSource ();

        if ( positionsSource->getDataType () != SourceBase::DATA_TYPE_DOUBLE )
            //throw new  FrameworkException ( __FILE__, __LINE__, "Positions data type is not a double!" );
            return 0;

        return ( DoubleSource* ) positionsSource;
    }

    //------------------------------
    void MeshLoader::addPolyBaseElement ( const PolyBase& polyBaseElement )
    {
// TODO Do we really need this? We can directly create a mesh primitve element!
//            mPolyBaseElements.append ( polyBaseElement );

        // Go through the list of input elements of the current poly base and get the 
        // source data of the input elements and write it into the source elements.
        // Attention: if there are multiple sources for the same semantic, we have to 
        // concat the source arrays and the indices!
        loadSourceElements ( polyBaseElement );

        // After a PolyBaseElements was set, we are able to read the index lists and 
        // set them into the Framework mesh data.

        COLLADAFW::PrimitiveElement* primitiveElement;
        primitiveElement = new COLLADAFW::PrimitiveElement ( polyBaseElement.getPrimitiveType () );

        primitiveElement->setCount ( polyBaseElement.getCount () );
        primitiveElement->setMaterial ( polyBaseElement.getMaterial () );

        COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();
        COLLADAFW::UIntValuesArray& normalIndices = primitiveElement->getNormalIndices ();
        COLLADAFW::UIntValuesArray& colorIndices = primitiveElement->getColorIndices ();
        COLLADAFW::UIntValuesArray& uvCoordIndices = primitiveElement->getUVCoordIndices ();

        switch ( polyBaseElement.getPrimitiveType () )
        {
        case COLLADAFW::PrimitiveElement::POLYGONS:
            {
                // We need the maximum offset value of the input elements to calculate the 
                // number of indices for each index list.
                size_t maxOffset = polyBaseElement.getInputArrayMaxOffset ();

                // TODO Iterate over all existing p elements 
                // (not about triangles and polylists, but about the polygons)
                const PArray& pArray = polyBaseElement.getPArray ();
                size_t numPElements = pArray.getCount ();

                size_t numPIndices = 0;
                for ( size_t j=0; j<numPElements; ++j )
                {
                    PElement* pElement = pArray [j];
                    numPIndices += pElement->getCount();
                }

                // Get the number of index elements in the index list for each input element.
                size_t numElements = numPIndices / maxOffset;

                // Variables for the offsets of the index input elements.
                size_t positionsOffset = 0; size_t positionsInitialIndex = 0; bool usePositions = true;
                size_t normalsOffset = 0; size_t normalsInitialIndex = 0; bool useNormals = false;
                size_t colorsOffset = 0; bool useColors = false;
                size_t uvCoordsOffset = 0; bool useUVCoords = false;

                // TODO The offset values of the input elements.
                const InputShared* input = polyBaseElement.getPositionInput ();
                if ( input == 0 ) 
                {
                    throw new ColladaSaxFrameworkLoaderException ( "No positions input element!" );
                    return;
                }
                // Get the offset value, the initial index values and alloc the memory.
                positionsOffset = input->getOffset ();
                COLLADABU::URI inputUrl = input->getSource ();
                String sourceId = inputUrl.getFragment ();
                const SourceBase* sourceBase = getSourceById ( sourceId );
                if ( sourceBase == 0 ) 
                {// TODO error handling!
                    return;
                }
                positionsInitialIndex = sourceBase->getInitialIndex ();
                positionIndices.reallocMemory ( numElements );

                // Check for using normals
                input = polyBaseElement.getNormalInput ();
                if ( input != 0 ) 
                {
                    // Get the offset value, the initial index values and alloc the memory.
                    normalsOffset = input->getOffset ();
                    sourceBase = getSourceById ( input->getSource ().getFragment () );
                    normalsInitialIndex = sourceBase->getInitialIndex ();
                    normalIndices.reallocMemory ( numElements );
                    useNormals = true;
                }

                // Check for using colors
                input = polyBaseElement.getColorInput ();
                if ( input != 0 ) 
                {
                    // Get the offset value and alloc the memory.
                    colorsOffset = input->getOffset ();
                    colorIndices.reallocMemory ( numElements );
                    useColors = true;
                }

                // Check for using uv coordinates 
                input = polyBaseElement.getUVCoordInput ();
                if ( input != 0 ) 
                {
                    // Get the offset value and alloc the memory.
                    uvCoordsOffset = input->getOffset ();
                    uvCoordIndices.reallocMemory ( numElements );
                    useUVCoords = true;
                }

                // The current index of the index lists.
                size_t indicesIndex = 0;

                for ( size_t j=0; j<numPElements; ++j )
                {
                    const PElement* pElement = pArray [j];

                    // Write the index values in the index lists.
                    size_t currentOffset = 0;
                    for ( size_t i=0; i<pElement->getCount (); ++i )
                    {
                        // Get the current index value.
                        unsigned int index = ( *pElement ) [i];

                        // Write the indices
                        if ( usePositions && currentOffset == positionsOffset )
                        {
                            positionIndices [ positionsInitialIndex + indicesIndex ] = index;
                        }
                        if ( useNormals && currentOffset == normalsOffset )
                        {
                            normalIndices [ normalsInitialIndex + indicesIndex ] = index;
                        }
                        if ( useColors && currentOffset == colorsOffset )
                        {
                            colorIndices [ indicesIndex ] = index;
                        }
                        if ( useUVCoords && currentOffset == normalsOffset )
                        {
                            uvCoordIndices [ indicesIndex ] = index;
                        }

                        // Increment the current offset value
                        ++currentOffset;

                        // Reset the offset if we went through all offset values
                        if ( i > 0 && currentOffset == maxOffset )
                        {
                            currentOffset = 0;
                            ++indicesIndex;
                        }
                    }
                }
                break;
            }
        default:
            // No more implementations.
            std::cerr << "Primitive type " << polyBaseElement.getPrimitiveType () << " not implemented!";
            return;
        }

        // Append the element into the list of primitive elements.
        mMesh->appendPrimitiveElement ( primitiveElement );
    }

    //------------------------------
    void MeshLoader::loadSourceElements ( const PolyBase& polyBaseElement )
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
            retValue = loadUVCoordsSourceElement ( input );
            break;
        default:
            // Not implemented source
            std::cout << "Source with semantic " << semantic << "not implemented!" << std::endl;
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
        if ( sourceBase->getIsLoaded () ) return false;

        // Get the source input array
        const SourceBase::DataType& dataType = sourceBase->getDataType ();
        switch ( dataType )
        {
        case SourceBase::DATA_TYPE_FLOAT:
            {
                // Get the values array from the source
                FloatSource* source = ( FloatSource* ) sourceBase;
                const FloatArrayElement* arrayElement = source->getFloatArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshPositions* positions = mMesh->getPositions ();
                const size_t initialIndex = positions->getPositionsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                positions->appendValues ( valuesArray );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

                break;
            }
        case SourceBase::DATA_TYPE_DOUBLE:
            {
                // Get the values array from the source
                DoubleSource* source = ( DoubleSource* ) sourceBase;
                const DoubleArrayElement* arrayElement = source->getDoubleArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshPositions* positions = mMesh->getPositions ();
                const size_t initialIndex = positions->getPositionsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                positions->appendValues ( valuesArray );

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
                const FloatArrayElement* arrayElement = source->getFloatArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshNormals* normals = mMesh->getNormals ();
                const size_t initialIndex = normals->getNormalsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                normals->appendValues ( valuesArray );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

                break;
            }
        case SourceBase::DATA_TYPE_DOUBLE:
            {
                // Get the values array from the source
                DoubleSource* source = ( DoubleSource* ) sourceBase;
                const DoubleArrayElement* arrayElement = source->getDoubleArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshNormals* normals = mMesh->getNormals ();
                const size_t initialIndex = normals->getNormalsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                normals->appendValues ( valuesArray );

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

        // Get the source input array
        const SourceBase::DataType& dataType = sourceBase->getDataType ();
        switch ( dataType )
        {
        case SourceBase::DATA_TYPE_FLOAT:
            {
                // Get the values array from the source
                FloatSource* source = ( FloatSource* ) sourceBase;
                const FloatArrayElement* arrayElement = source->getFloatArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshColors* colors = mMesh->getColors ();
                const size_t initialIndex = colors->getColorsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                colors->appendValues ( valuesArray );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

                break;
            }
        case SourceBase::DATA_TYPE_DOUBLE:
            {
                // Get the values array from the source
                DoubleSource* source = ( DoubleSource* ) sourceBase;
                const DoubleArrayElement* arrayElement = source->getDoubleArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshColors* colors = mMesh->getColors ();
                const size_t initialIndex = colors->getColorsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                colors->appendValues ( valuesArray );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

                break;
            }
        default:
            std::cerr << "Color source has an other datatype as float or double! " << dataType << std::endl;
            return false;
        }

        return true;
    }

    //------------------------------
    bool MeshLoader::loadUVCoordsSourceElement ( const InputShared& input )
    {
        // Get the semantic of the current input element.
        InputSemantic::Semantic semantic = input.getSemantic ();
        if ( semantic != InputSemantic::UV )
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

        // Get the source input array
        const SourceBase::DataType& dataType = sourceBase->getDataType ();
        switch ( dataType )
        {
        case SourceBase::DATA_TYPE_FLOAT:
            {
                // Get the values array from the source
                FloatSource* source = ( FloatSource* ) sourceBase;
                const FloatArrayElement* arrayElement = source->getFloatArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<float>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshUVCoords* uvCoords = mMesh->getUVCoords ();
                const size_t initialIndex = uvCoords->getUVCoordsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                uvCoords->appendValues ( valuesArray );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

                break;  
            }
        case SourceBase::DATA_TYPE_DOUBLE:
            {
                // Get the values array from the source
                DoubleSource* source = ( DoubleSource* ) sourceBase;
                const DoubleArrayElement* arrayElement = source->getDoubleArrayElement ();
                const COLLADAFW::ArrayPrimitiveType<double>& valuesArray = arrayElement->getValues ();

                // Check if there are already some values in the positions list.
                // If so, we have to store the last index to increment the following indexes.
                const COLLADAFW::MeshUVCoords* uvCoords = mMesh->getUVCoords ();
                const size_t initialIndex = uvCoords->getUVCoordsCount ();
                sourceBase->setInitialIndex ( initialIndex );

                // Push the new positions into the list of positions.
                uvCoords->appendValues ( valuesArray );

                // Set the source base as loaded element.
                sourceBase->setIsLoaded ( true );

                break;
            }
        default:
            std::cerr << "UV coordinates source has an other datatype as float or double! " << dataType << std::endl;
            return false;
        }

        return true;
    }

} // namespace COLLADASaxFWL
