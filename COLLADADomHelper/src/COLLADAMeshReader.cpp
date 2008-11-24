/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAMeshReader.h"

#include "COLLADAFWParam.h"
#include "COLLADAFWInputUnshared.h"
#include "COLLADAFWPrimitiveBase.h"

#include "dom/domName_array.h"
#include "dom/domPolygons.h"


namespace COLLADADomHelper
{

    // --------------------------------------------
    COLLADAFW::Mesh* MeshReader::createMeshObject ( domMeshRef& meshRef )
    {
        // Set the current domMesh.
        mMeshRef = meshRef;

        // Create a COLLADAFramework::Mesh element with 
        // the dom from the collada document data.
        mMesh = new COLLADAFW::Mesh ();

        // Reads all collada dae source objects and writes it in the COLLADAFramework source object.
        fillSourceElements();

        // Fill the mesh vertex element.
        fillVertexElement();

        // The current face index.
        size_t faceIndex = 0;

        // Get the array of polygons and write it in the COLLADAFW::Mesh object.
        domPolygons_Array polygonsArray = mMeshRef->getPolygons_array ();
        if ( polygonsArray.getCount () != 0 )
        {
            fillMeshPolygonsArray (  polygonsArray, faceIndex  );
        }

        // Get the array of polylists and write it in the COLLADAFW::Mesh object.
        domPolylist_Array polylistArray = mMeshRef->getPolylist_array ();
        if ( polylistArray.getCount () != 0 )
        {
            fillMeshPolylistArray ( polylistArray, faceIndex );
        }

        // TODO
        meshRef->getTriangles_array ();
        meshRef->getTrifans_array ();
        meshRef->getTristrips_array ();

        return mMesh;
    }

    // --------------------------------------------
    void MeshReader::fillMeshPolylistArray ( 
        const domPolylist_Array& polylistArray, 
        size_t& faceIndex ) 
    {
        // The number of vertices and polygons.
        size_t numVertices = 0, numPolygons = 0;

        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.
        domSourceRef positionsRef = getPositionsRef ();

        // The number of polylist elements in the current mesh
        size_t polylistCount = polylistArray.getCount ();

        // Fill the COLLADAFramework polylist data
        COLLADAFW::Polylist* polylistList = new COLLADAFW::Polylist [ polylistCount ]; 
        mMesh->setPolylistArray ( polylistList, polylistCount );

        for ( size_t i=0; i<polylistCount; ++i )
        {
            // Get the polylist element.
            COLLADAFW::Polylist& polylist = polylistList [ i ];

            // Get the current polylist element
            domPolylistRef polylistRef = polylistArray.get ( i );
            numPolygons = ( size_t ) polylistRef->getCount ();
            polylist.setCount ( numPolygons );

            // Assign the material.
            if ( polylistRef->getMaterial () != 0 ) 
                polylist.setMaterial ( polylistRef->getMaterial () );

            // Fill the polylist's input elements.
            fillPolylistInputArray ( polylistRef, polylist );

            // Fill the COLLADAFramework vCountList data
            fillPolylistVCountArray ( polylistRef, polylist );

            // Fill the COLLADAFramework pList data
            fillPolylistPrimitivesArray ( polylistRef, polylist, faceIndex );

        }
    }

    // --------------------------------------------
    void MeshReader::fillMeshPolygonsArray ( 
        const domPolygons_Array& polygonsArray, 
        size_t& faceIndex )
    {
        // The number of vertices and polygons.
        size_t numVertices = 0, numPolygons = 0;

        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.
        domSourceRef positionsRef = getPositionsRef ();

        // The number of polygon elements in the current mesh
        size_t polygonsCount = polygonsArray.getCount ();

        // Fill the COLLADAFramework polygons data
        COLLADAFW::Polygons* polygonsList = new COLLADAFW::Polygons [ polygonsCount ]; 
        mMesh->setPolygonsArray ( polygonsList, polygonsCount );

        // Go through all poygons of the current mesh.
        for ( size_t i=0; i<polygonsCount; ++i )
        {
            // Get the current COLLADAFramework polygons element
            COLLADAFW::Polygons& polygons = polygonsList [ i ];

            // Get a reference to the current polygons element.
            domPolygonsRef polygonsRef = polygonsArray.get ( i );
            numPolygons = ( size_t ) polygonsRef->getCount ();
            polygons.setCount ( numPolygons );

            // Assign the material.
            if ( polygonsRef->getMaterial () != 0 ) 
                polygons.setMaterial ( polygonsRef->getMaterial () );

            // Fill the polylist's input elements.
            fillPolygonsInputArray ( polygonsRef, polygons );

            // Fills all the primitives arrays of the polygons element (p and ph elements).
            fillPolygonsPrimitivesElements ( polygonsRef, polygons, faceIndex );
        }

    }

    // --------------------------------------------
    domSourceRef MeshReader::getPositionsRef ()
    {
        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.

        // Get the vertices input array (there is only one per mesh).
        domVerticesRef verticesRef = mMeshRef->getVertices ();
        domInputLocal_Array verticesInputArray = verticesRef->getInput_array ();

        // Get the point positions of the vertexes
        domURIFragmentType positionUri ( * ( mDoc.getDAE () ) );
        size_t numOfInputs = verticesInputArray.getCount ();
        for ( size_t j=0; j<numOfInputs; ++j )
        {
            domInputLocalRef vertexInputRef = verticesInputArray.get ( j );
            xsNMTOKEN semantic = vertexInputRef->getSemantic ();
            if ( COLLADASW::Utils::equalsIgnoreCase ( semantic, COLLADAFW::Constants::SEMANTIC_POSITION ) )
            {
                positionUri = vertexInputRef->getSource ();
            }
        }
        if ( positionUri.getState() != daeURI::uri_success )
        {
            positionUri.setContainer ( mDoc.getDomRoot() );
            positionUri.resolveElement ();
        }

        return daeSafeCast<domSource> ( positionUri.getElement() );
    }

    // --------------------------------------------
    void MeshReader::fillNameArrayElement ( const domSourceRef& sourceRef, COLLADAFW::Source& source )
    {
        domName_arrayRef arrayRef = sourceRef->getName_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::NameArrayElement& arrayElement = source.getNameArrayElement ();
            arrayElement.setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement.setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement.setName ( arrayRef->getName () );

            domListOfNames domNameValues = arrayRef->getValue ();
            size_t nameCount = domNameValues.getCount ();
            String* nameArray = new String [ nameCount ];
            for ( size_t m=0; m<nameCount; ++m )
            {
                domName& name = domNameValues.get ( m );
                nameArray [ m ] = name;
            }
            arrayElement.setValues ( nameArray, nameCount );

            source.setNameArrayElement ( arrayElement );
        }
    }

    // --------------------------------------------
    void MeshReader::fillBoolArrayElement ( const domSourceRef& sourceRef, COLLADAFW::Source& source )
    {
        domBool_arrayRef arrayRef = sourceRef->getBool_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::BoolArrayElement& arrayElement = source.getBoolArrayElement ();
            arrayElement.setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement.setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement.setName ( arrayRef->getName () );

            domListOfBools domValues = arrayRef->getValue ();
            size_t valuesCount = domValues.getCount ();
            bool* valuesArray = new bool [ valuesCount ];
            for ( size_t m=0; m<valuesCount; ++m )
            {
                domBool& val = domValues.get ( m );
                valuesArray [ m ] = val;
            }
            arrayElement.setValues ( valuesArray, valuesCount );

            source.setBoolArrayElement ( arrayElement );
        }
    }

    // --------------------------------------------
    void MeshReader::fillIntArrayElement ( const domSourceRef& sourceRef, COLLADAFW::Source& source )
    {
        domInt_arrayRef arrayRef = sourceRef->getInt_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::IntArrayElement& arrayElement = source.getIntArrayElement ();
            arrayElement.setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement.setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement.setName ( arrayRef->getName () );

            domListOfInts domValues = arrayRef->getValue ();
            size_t valuesCount = domValues.getCount ();
            int* valuesArray = new int [ valuesCount ];
            for ( size_t m=0; m<valuesCount; ++m )
            {
                domInt& val = domValues.get ( m );
                valuesArray [ m ] = ( int ) val;
            }
            arrayElement.setValues ( valuesArray, valuesCount );
        }
    }

    // --------------------------------------------
    void MeshReader::fillFloatArrayElement ( const domSourceRef& sourceRef, COLLADAFW::Source& source )
    {
        domFloat_arrayRef arrayRef = sourceRef->getFloat_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::DoubleArrayElement& arrayElement = source.getDoubleArrayElement ();
            arrayElement.setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement.setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement.setName ( arrayRef->getName () );

            domListOfFloats& domValues = arrayRef->getValue ();
            daeMemoryRef memoryRef = domValues.getRawData ();
            arrayElement.setValues ( reinterpret_cast <double*> ( domValues.getRawData () ), domValues.getCount () );
        }
    }

    // --------------------------------------------
    void MeshReader::fillIDREFArrayElement ( const domSourceRef& sourceRef, COLLADAFW::Source& source )
    {
        domIDREF_arrayRef arrayRef = sourceRef->getIDREF_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::IDREFArrayElement& arrayElement = source.getIDREFArrayElement ();
            arrayElement.setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement.setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement.setName ( arrayRef->getName () );

            xsIDREFS domValues = arrayRef->getValue ();
            size_t valuesCount = domValues.getCount ();
            String* valuesArray = new String [ valuesCount ];
            for ( size_t m=0; m<valuesCount; ++m )
            {
                daeIDRef& val = domValues.get ( m );
                // TODO Is this that i want to have???
                valuesArray [ m ] = val.getID ();
            }
            arrayElement.setValues ( valuesArray, valuesCount );

            source.setIDREFArrayElement ( arrayElement );
        }
    }

    // --------------------------------------------
    void MeshReader::fillSourceElements ()
    {
        // Fill the mesh source elements
        domSource_Array domSourceArray = mMeshRef->getSource_array ();
        size_t sourceArraySize = domSourceArray.getCount ();

        // Create a new source array with the required size
        COLLADAFW::SourceArray sourceArray;
        sourceArray = new COLLADAFW::Source [ sourceArraySize ];
        mMesh->setSourceArray ( sourceArray, sourceArraySize );

        for ( size_t n=0; n<sourceArraySize; ++n )
        {
            // The dom source element
            domSourceRef sourceRef = domSourceArray.get ( n );

            // The current source array to fill in.
            COLLADAFW::Source& source = sourceArray [ n ];
            source.setId ( sourceRef->getId () );
            if ( sourceRef->getName () != 0 ) source.setName ( sourceRef->getName () );

            // Fills the current dae source element into a COLLADAFramework source element.
            fillSourceElement ( sourceRef, source );
        }
    }

    // --------------------------------------------
    void MeshReader::fillSourceElement ( const domSourceRef& sourceRef, COLLADAFW::Source& source )
    {
        // Fill the array element of the existing type.
        fillNameArrayElement ( sourceRef, source );
        fillIntArrayElement ( sourceRef, source );
        fillFloatArrayElement ( sourceRef, source );
        fillBoolArrayElement ( sourceRef, source );
        fillIDREFArrayElement ( sourceRef, source );

        // Fill the technique common elements.
        fillTechniqueCommon(sourceRef, source);
    }

    // --------------------------------------------
    void MeshReader::fillTechniqueCommon ( const domSourceRef& sourceRef, COLLADAFW::Source &source )
    {
        domSource::domTechnique_commonRef techniqueCommonRef;
        techniqueCommonRef = sourceRef->getTechnique_common ();
        domAccessorRef accessorRef = techniqueCommonRef->getAccessor ();

        COLLADAFW::TechniqueCommon& techniqueCommon = source.getTechniqueCommon ();
        COLLADAFW::Accessor& accessor = techniqueCommon.getAccessor ();

        unsigned int count = ( unsigned int ) accessorRef->getCount ();
        accessor.setCount ( count );

        unsigned int stride = ( unsigned int ) accessorRef->getStride ();
        accessor.setStride ( stride );

        accessor.setSource ( COLLADASW::URI::nativePathToUri (  accessorRef->getSource ().getOriginalURI () ) );

        unsigned int offset = ( unsigned int ) accessorRef->getOffset ();
        accessor.setOffset ( offset );

        // Read the parameter array
        domParam_Array paramArrayDom = accessorRef->getParam_array ();
        size_t paramCount = paramArrayDom.getCount ();

        COLLADAFW::ParamArray paramArray = new COLLADAFW::Param [ paramCount ];
        accessor.setParamArray ( paramArray, paramCount );

        for ( size_t i=0; i<paramCount; ++i )
        {
            domParamRef paramRef = paramArrayDom.get ( i );
            COLLADAFW::Param& param = paramArray [ i ];

            if ( paramRef->getName () != 0 ) param.setName ( paramRef->getName () );
            if ( paramRef->getSemantic () != 0 ) param.setSemantic ( paramRef->getSemantic () );
            if ( paramRef->getSid () != 0 ) param.setSid ( paramRef->getSid () );
            param.setType ( COLLADAFW::ValueType::getValueTypeFromString ( paramRef->getType () ) );
//             String paramValue = paramRef->getValue ();
//             param.setValue ( paramValue );
        }

        // TODO
//         domTechnique_Array techniqueArray = sourceRef->getTechnique_array ();
//         size_t techniqueCount = techniqueArray.getCount ();
    }

    // --------------------------------------------
    void MeshReader::fillVertexElement ()
    {
        // Fill the mesh vertex element.
        domVerticesRef verticesRef = mMeshRef->getVertices ();

        COLLADAFW::Vertices& vertices = mMesh->getVertices ();
        if ( verticesRef->getId () != 0 ) vertices.setId ( verticesRef->getId () );
        if ( verticesRef->getName () != 0 ) vertices.setName ( verticesRef->getName () );

        domInputLocal_Array inputArrayDom = verticesRef->getInput_array ();
        size_t inputCount = inputArrayDom.getCount ();

        COLLADAFW::InputUnsharedArray inputArray = new COLLADAFW::InputUnshared [ inputCount ];
        vertices.setInputArray ( inputArray, inputCount );

        for ( size_t i=0; i<inputCount; ++i )
        {
            domInputLocalRef inputRef = inputArrayDom.get ( i );
            COLLADAFW::InputUnshared& input = inputArray [ i ];
            if ( inputRef->getSemantic () != 0 )
                input.setSemantic ( COLLADAFW::InputUnshared::getSemanticFromString ( inputRef->getSemantic () ) );

            input.setSource ( COLLADASW::URI::nativePathToUri ( inputRef->getSource ().originalStr () ) );
        }
    }

    // --------------------------------------------
    void MeshReader::fillPolylistInputArray ( 
        const domPolylistRef polylistRef, 
        COLLADAFW::Polylist& polylist )
    {
        // Fill the COLLADAFramework input list elements.
        domInputLocalOffset_Array domInputArray;
        domInputArray = polylistRef->getInput_array ();
        size_t polylistInputCount = domInputArray.getCount ();

        COLLADAFW::InputSharedArray inputArray = new COLLADAFW::InputShared [ polylistInputCount ];
        polylist.setInputArray ( inputArray, polylistInputCount );

        // Fill the input array.
        fillInputArray ( domInputArray, inputArray );
    }

    // --------------------------------------------
    void MeshReader::fillPolygonsInputArray ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons& polygons )
    {
        // Fill the COLLADAFramework input list elements.
        domInputLocalOffset_Array domInputArray;
        domInputArray = polygonsRef->getInput_array ();
        size_t polylistInputCount = domInputArray.getCount ();

        COLLADAFW::InputSharedArray inputArray = new COLLADAFW::InputShared [ polylistInputCount ];
        polygons.setInputArray ( inputArray, polylistInputCount );

        // Fill the input array.
        fillInputArray ( domInputArray, inputArray );
    }

    // --------------------------------------------
    void MeshReader::fillInputArray ( 
        const domInputLocalOffset_Array& domInputArray, 
        COLLADAFW::InputSharedArray& inputArray )
    {
        size_t inputCount = domInputArray.getCount ();
        for ( size_t n=0; n<inputCount; ++n )
        {
            // Get the current COLLADAFramework input element.
            COLLADAFW::InputShared& input = inputArray [ n ];

            // Get the current dom input element.
            domInputLocalOffsetRef polylistInputRef;
            polylistInputRef = domInputArray.get ( n );

            xsNMTOKEN semantic = polylistInputRef->getSemantic ();
            input.setSemantic ( COLLADAFW::InputUnshared::getSemanticFromString ( semantic ) );

            domURIFragmentType domUri = polylistInputRef->getSource ();
            input.setSource ( COLLADASW::URI::nativePathToUri ( domUri.originalStr () ) );

            unsigned int offset = ( unsigned int ) polylistInputRef->getOffset ();
            input.setOffset ( offset );

            unsigned int set = ( unsigned int ) polylistInputRef->getSet ();
            input.setSet ( set );
        }
    }

    // --------------------------------------------
    void MeshReader::fillPolylistVCountArray ( 
        const domPolylistRef polylistRef, 
        COLLADAFW::Polylist& polylist )
    {
        domPolylist::domVcountRef vCountRef = polylistRef->getVcount ();
        domListOfUInts domVCountList = vCountRef->getValue ();

        size_t vCountListSize = domVCountList.getCount ();
        COLLADAFW::Polylist::VCountArray vCountList = new unsigned int [ vCountListSize ];
        for ( size_t m=0; m<vCountListSize; ++m )
        {
            vCountList [ m ] = ( unsigned int ) domVCountList.get ( m );
        }
        polylist.setVCountArray ( vCountList, vCountListSize );
    }

    // --------------------------------------------
    void MeshReader::fillPolylistPrimitivesArray ( 
        const domPolylistRef polylistRef, 
        COLLADAFW::Polylist& polylist, 
        size_t& faceIndex )
    {
        // Get the dom p element of the ph element and the COLLADAFramework p element
        // and fill the COLLADAFramework pList values.
        domPRef pRef = polylistRef->getP ();
        COLLADAFW::PElement& pElement = polylist.getPElement ();
        fillPListValues ( pRef, pElement, faceIndex );
    }

    // --------------------------------------------
    void MeshReader::fillPolygonsPrimitivesElements ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons& polygons, 
        size_t& faceIndex )
    {
        fillPolygonsPArrays ( polygonsRef, polygons, faceIndex );
        fillPolygonsPHArrays(polygonsRef, polygons, faceIndex);
    }

    // --------------------------------------------
    void MeshReader::fillPolygonsPArrays ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons &polygons, 
        size_t& faceIndex )
    {
        // Contains a list of polygon lists. Each polygon list contains a list of UInts 
        // that specifies the vertex attributes (indices) for an individual polygon.
        domP_Array domPArray = polygonsRef->getP_array ();

        // Get the number of polygons in the current polygons element.
        size_t numPolygons = domPArray.getCount ();

        // Create a COLLADAFW:PArray and set it into the COLLADAFramework polygons object.
        COLLADAFW::PArray pArray = new COLLADAFW::PElement [ numPolygons ];
        polygons.setPArray ( pArray, numPolygons );

        // Go through each polygon and write the vertices per polygon.
        for ( size_t n=0; n<numPolygons; ++n )
        {
            // Get the dom p element of the ph element and the COLLADAFramework p element
            // and fill the COLLADAFramework pList values.
            domPRef pRef = domPArray.get ( n );
            COLLADAFW::PElement& pElement = pArray [ n ];
            fillPListValues ( pRef, pElement, faceIndex );
        }
    }

    // --------------------------------------------
    void MeshReader::fillPolygonsPHArrays ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons &polygons, 
        size_t& faceIndex )
    {
        // Gets the ph element array.
        domPolygons::domPh_Array domPHArray = polygonsRef->getPh_array ();

        // Get the number of polygons in the current polygons element.
        size_t numPolygons = domPHArray.getCount ();

        // Create a COLLADAFW:PHArray and set it into the COLLADAFramework polygons object.
        COLLADAFW::PHArray phArray = new COLLADAFW::PHElement [ numPolygons ];
        polygons.setPHArray ( phArray, numPolygons );

        // Go through each polygon and write the vertices per polygon.
        for ( size_t n=0; n<numPolygons; ++n )
        {
            // Get the dom ph element and the COLLADAFramework ph element.
            domPolygons::domPhRef phRef = domPHArray.get ( n );
            COLLADAFW::PHElement& phElement = phArray [ n ];

            // Get the dom p element of the ph element and the COLLADAFramework p element
            // and fill the COLLADAFramework pList values.
            domPRef pRef = phRef->getP ();
            COLLADAFW::PElement& pElement = phElement.getPElement ();
            fillPListValues ( pRef, pElement, faceIndex );

            // Get the dom h array of the ph element.
            domPolygons::domPh::domH_Array domHArray = phRef->getH_array ();

            // Create a new h array and set it into the COLLADAFramework ph element.
            size_t hArraySize = domHArray.getCount ();
            COLLADAFW::HArray hArray = new COLLADAFW::HElement [ hArraySize ];
            phElement.setHArray ( hArray, hArraySize );

            // Go through the h elements
            for ( size_t m=0; m<hArraySize; ++m )
            {
                // Get the dom h element of the h array and the COLLADAFramework h element
                // and fill the COLLADAFramework hList values.
                domPolygons::domPh::domHRef hRef = domHArray.get ( m );
                COLLADAFW::HElement& hElement = hArray [ m ];
                fillHListValues ( hRef, hElement, faceIndex );
            }
        }
    }

    // --------------------------------------------
    void MeshReader::fillPListValues ( 
        const domPRef pRef, 
        COLLADAFW::PElement &pElement, 
        size_t& faceIndex )
    {
        // Get the values list.
        domListOfUInts domPList = pRef->getValue ();
        size_t pListSize = domPList.getCount ();

        // Create the COLLADAFramework polygons array list
        COLLADAFW::UIntValuesArray pListValues = new unsigned int [ pListSize ];
        pElement.setUIntValuesArray ( pListValues, pListSize, faceIndex );

        // Increment the face index for the currently used face.
        ++faceIndex;

        // Fill the primitives list
        for ( size_t m=0; m<pListSize; ++m )
        {
            pListValues [ m ] = ( unsigned int ) domPList.get ( m );
        }
    }

    // --------------------------------------------
    void MeshReader::fillHListValues ( 
        const domPolygons::domPh::domHRef hRef, 
        COLLADAFW::HElement &hElement, 
        size_t& faceIndex )
    {
        // Get the values list.
        domListOfUInts domHList = hRef->getValue ();
        size_t hListSize = domHList.getCount ();

        // Create the COLLADAFramework polygons array list
        COLLADAFW::UIntValuesArray hListValues = new unsigned int [ hListSize ];
        hElement.setUIntValuesArray ( hListValues, hListSize, faceIndex );

        // Increment the face index for the currently used face.
        ++faceIndex;

        // Fill the primitives list
        for ( size_t m=0; m<hListSize; ++m )
        {
            hListValues [ m ] = ( unsigned int ) domHList.get ( m );
        }
    }

}