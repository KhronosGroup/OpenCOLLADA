/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHMeshLoader.h"

#include "COLLADAFWParam.h"
#include "COLLADAFWInputUnshared.h"
#include "COLLADAFWPrimitiveBase.h"

#include "dom/domName_array.h"
#include "dom/domPolygons.h"


namespace COLLADADH
{

    // --------------------------------------------
    COLLADAFW::Mesh* MeshLoader::createMeshObject ( domMeshRef& meshRef )
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
    void MeshLoader::fillMeshPolylistArray ( 
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
        COLLADAFW::PolylistArray arrayPolylist ( polylistList, polylistCount );
//        COLLADAFW::Array <COLLADAFW::Polylist*> arrayPolylist ( polylistList, polylistCount );

        mMesh->setPolylistArray ( arrayPolylist );

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
    void MeshLoader::fillMeshPolygonsArray ( 
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
        COLLADAFW::PolygonsArray arrayPolygons ( polygonsList, polygonsCount );
        mMesh->setPolygonsArray ( arrayPolygons );

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
    domSourceRef MeshLoader::getPositionsRef ()
    {
        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.

        // Get the vertices input array (there is only one per mesh).
        domVerticesRef verticesRef = mMeshRef->getVertices ();
        domInputLocal_Array verticesInputArray = verticesRef->getInput_array ();

        // Get the point positions of the vertexes
		domSourceRef positionsSource = 0;
        size_t numOfInputs = verticesInputArray.getCount ();
        for ( size_t j=0; j<numOfInputs; ++j )
        {
            domInputLocalRef vertexInputRef = verticesInputArray.get ( j );
            xsNMTOKEN semantic = vertexInputRef->getSemantic ();
            if ( COLLADASW::Utils::equalsIgnoreCase ( semantic, COLLADAFW::Constants::SEMANTIC_POSITION ) )
            {
                positionsSource = daeSafeCast<domSource> (vertexInputRef->getSource().getElement());
				break;
            }
        }

        return positionsSource;
    }

    // --------------------------------------------
    COLLADAFW::SourceBase* MeshLoader::createNameArrayElementSource ( const domSourceRef& sourceRef )
    {
        domName_arrayRef arrayRef = sourceRef->getName_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::Source<COLLADAFW::NameArrayElement>* source;
            source = new COLLADAFW::Source<COLLADAFW::NameArrayElement> ( COLLADAFW::SourceBase::VALUE_TYPE_NAME ); 
            
            COLLADAFW::NameArrayElement* arrayElement = source->getNameArrayElement ();
            arrayElement->setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement->setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement->setName ( arrayRef->getName () );

            domListOfNames& domValues = arrayRef->getValue ();
            daeMemoryRef memoryRef = domValues.getRawData ();
            arrayElement->setValues ( reinterpret_cast <String*> ( domValues.getRawData () ), domValues.getCount () );

            return source;
        }

        return 0;
    }

    // --------------------------------------------
    COLLADAFW::SourceBase* MeshLoader::createBoolArrayElementSource ( const domSourceRef& sourceRef )
    {
        domBool_arrayRef arrayRef = sourceRef->getBool_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::Source<COLLADAFW::BoolArrayElement>* source;
            source = new COLLADAFW::Source<COLLADAFW::BoolArrayElement> ( COLLADAFW::SourceBase::VALUE_TYPE_BOOL ); 

            COLLADAFW::BoolArrayElement* arrayElement = source->getBoolArrayElement ();
            arrayElement->setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement->setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement->setName ( arrayRef->getName () );

            domListOfBools& domValues = arrayRef->getValue ();
            daeMemoryRef memoryRef = domValues.getRawData ();
            arrayElement->setValues ( reinterpret_cast <bool*> ( domValues.getRawData () ), domValues.getCount () );

            return source;
        }

        return 0;
    }

    // --------------------------------------------
    COLLADAFW::SourceBase* MeshLoader::createIntArrayElementSource ( const domSourceRef& sourceRef )
    {
        domInt_arrayRef arrayRef = sourceRef->getInt_array ();
        if ( arrayRef != 0 )
        {
            // The dom has internal a long long!
            COLLADAFW::Source<COLLADAFW::Long64ArrayElement>* source;
            source = new COLLADAFW::Source<COLLADAFW::Long64ArrayElement> ( COLLADAFW::SourceBase::VALUE_TYPE_LONG64 ); 

            COLLADAFW::Long64ArrayElement* arrayElement = source->getLong64ArrayElement ();
            arrayElement->setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement->setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement->setName ( arrayRef->getName () );

            domListOfInts& domValues = arrayRef->getValue ();
            daeMemoryRef memoryRef = domValues.getRawData ();
            arrayElement->setValues ( reinterpret_cast <long long*> ( domValues.getRawData () ), domValues.getCount () );

            return source;
        }

        return 0;
    }

    // --------------------------------------------
    COLLADAFW::SourceBase* MeshLoader::createFloatArrayElementSource ( const domSourceRef& sourceRef )
    {
        domFloat_arrayRef arrayRef = sourceRef->getFloat_array ();
        if ( arrayRef != 0 )
        {
            // The dom has internal a double!
            COLLADAFW::Source<COLLADAFW::DoubleArrayElement>* source;
            source = new COLLADAFW::Source<COLLADAFW::DoubleArrayElement> ( COLLADAFW::SourceBase::VALUE_TYPE_DOUBLE ); 

            COLLADAFW::DoubleArrayElement* arrayElement = source->getDoubleArrayElement ();
            arrayElement->setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement->setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement->setName ( arrayRef->getName () );

            domListOfFloats& domValues = arrayRef->getValue ();
            daeMemoryRef memoryRef = domValues.getRawData ();
            arrayElement->setValues ( reinterpret_cast <double*> ( domValues.getRawData () ), domValues.getCount () );

            return source;
        }

        return 0;
    }

    // --------------------------------------------
    COLLADAFW::SourceBase*  MeshLoader::createIDREFArrayElementSource ( const domSourceRef& sourceRef )
    {
        domIDREF_arrayRef arrayRef = sourceRef->getIDREF_array ();
        if ( arrayRef != 0 )
        {
            COLLADAFW::Source<COLLADAFW::IDREFArrayElement>* source;
            source = new COLLADAFW::Source<COLLADAFW::IDREFArrayElement> ( COLLADAFW::SourceBase::VALUE_TYPE_IDREF ); 

            COLLADAFW::IDREFArrayElement* arrayElement = source->getIDREFArrayElement ();
            arrayElement->setCount ( ( unsigned int ) arrayRef->getCount () );
            if ( arrayRef->getId () != 0 ) arrayElement->setId ( arrayRef->getId () );
            if ( arrayRef->getName () != 0 ) arrayElement->setName ( arrayRef->getName () );

            xsIDREFS domValues = arrayRef->getValue ();
            size_t valuesCount = domValues.getCount ();
            String* valuesArray = new String [ valuesCount ];
            for ( size_t m=0; m<valuesCount; ++m )
            {
                daeIDRef& val = domValues.get ( m );
                // TODO Is this that i want to have???
                valuesArray [ m ] = val.getID ();
            }
            arrayElement->setValues ( valuesArray, valuesCount );

            return source;
        }

        return 0;
    }

    // --------------------------------------------
    void MeshLoader::fillSourceElements ()
    {
        // Fill the mesh source elements
        domSource_Array domSourceArray = mMeshRef->getSource_array ();
        size_t sourceArraySize = domSourceArray.getCount ();

        // Create a new source array with the required size
        COLLADAFW::SourceBase** sources = new COLLADAFW::SourceBase* [ sourceArraySize ];
        COLLADAFW::SourceArray sourceArray ( sources, sourceArraySize );

        for ( size_t n=0; n<sourceArraySize; ++n )
        {
            // The dom source element
            domSourceRef sourceRef = domSourceArray.get ( n );

            // Fills the current dae source element into a COLLADAFramework source element.
            COLLADAFW::SourceBase* source = createSourceElement ( sourceRef );
            source->setId ( sourceRef->getId () );
            if ( sourceRef->getName () != 0 ) source->setName ( sourceRef->getName () );

            // TODO Return source!
            // Fill the technique common elements.
            fillTechniqueCommon ( sourceRef, source );

            // The current source array to fill in.
            sourceArray [n] = source;
        }

        // Set the source array into the mesh object.
        mMesh->setSourceArray ( sourceArray );
    }

    // --------------------------------------------
    COLLADAFW::SourceBase* MeshLoader::createSourceElement ( const domSourceRef& sourceRef )
    {
        COLLADAFW::SourceBase* source;

        // Fill the array element of the existing type.
        source = createNameArrayElementSource ( sourceRef );
        if ( source != 0 ) return source;

        source = createIntArrayElementSource ( sourceRef );
        if ( source != 0 ) return source;

        source = createFloatArrayElementSource ( sourceRef );
        if ( source != 0 ) return source;

        source = createBoolArrayElementSource ( sourceRef );
        if ( source != 0 ) return source;

        source = createIDREFArrayElementSource ( sourceRef );
        if ( source != 0 ) return source;

        return 0;
    }

    // --------------------------------------------
    void MeshLoader::fillTechniqueCommon ( const domSourceRef& sourceRef, COLLADAFW::SourceBase* source )
    {
        domSource::domTechnique_commonRef techniqueCommonRef;
        techniqueCommonRef = sourceRef->getTechnique_common ();
        domAccessorRef accessorRef = techniqueCommonRef->getAccessor ();

        COLLADAFW::TechniqueCommon& techniqueCommon = source->getTechniqueCommon ();
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
    void MeshLoader::fillVertexElement ()
    {
        // Fill the mesh vertex element.
        domVerticesRef verticesRef = mMeshRef->getVertices ();

        COLLADAFW::Vertices& vertices = mMesh->getVertices ();
        if ( verticesRef->getId () != 0 ) vertices.setId ( verticesRef->getId () );
        if ( verticesRef->getName () != 0 ) vertices.setName ( verticesRef->getName () );

        domInputLocal_Array inputArrayDom = verticesRef->getInput_array ();
        size_t inputCount = inputArrayDom.getCount ();

        // Fill the COLLADAFramework data
        COLLADAFW::InputUnshared* inputs = new COLLADAFW::InputUnshared [ inputCount ];
        COLLADAFW::InputUnsharedArray inputArray ( inputs, inputCount );
        vertices.setInputArray ( inputArray );

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
    void MeshLoader::fillPolylistInputArray ( 
        const domPolylistRef polylistRef, 
        COLLADAFW::Polylist& polylist )
    {
        // Fill the COLLADAFramework input list elements.
        domInputLocalOffset_Array domInputArray;
        domInputArray = polylistRef->getInput_array ();
        size_t polylistInputCount = domInputArray.getCount ();

        // Fill the COLLADAFramework data
        COLLADAFW::InputShared* inputs = new COLLADAFW::InputShared [ polylistInputCount ];
        COLLADAFW::InputSharedArray inputArray ( inputs, polylistInputCount );
        polylist.setInputArray ( inputArray );

        // Fill the input array.
        fillInputArray ( domInputArray, inputArray );
    }

    // --------------------------------------------
    void MeshLoader::fillPolygonsInputArray ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons& polygons )
    {
        // Fill the COLLADAFramework input list elements.
        domInputLocalOffset_Array domInputArray;
        domInputArray = polygonsRef->getInput_array ();
        size_t polylistInputCount = domInputArray.getCount ();

        // Fill the COLLADAFramework data
        COLLADAFW::InputShared* inputs = new COLLADAFW::InputShared [ polylistInputCount ];
        COLLADAFW::InputSharedArray inputArray ( inputs, polylistInputCount );
        polygons.setInputArray ( inputArray );

        // Fill the input array.
        fillInputArray ( domInputArray, inputArray );
    }

    // --------------------------------------------
    void MeshLoader::fillInputArray ( 
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
    void MeshLoader::fillPolylistVCountArray ( 
        const domPolylistRef polylistRef, 
        COLLADAFW::Polylist& polylist )
    {
        domPolylist::domVcountRef vCountRef = polylistRef->getVcount ();
        domListOfUInts domVCountList = vCountRef->getValue ();

        // Fill the COLLADAFramework data
        size_t vCountListSize = domVCountList.getCount ();
        unsigned int* vCounts = new unsigned int [ vCountListSize ];
        COLLADAFW::Polylist::VCountArray vCountList ( vCounts, vCountListSize );

        for ( size_t m=0; m<vCountListSize; ++m )
        {
            vCountList [ m ] = ( unsigned int ) domVCountList.get ( m );
        }
        polylist.setVCountArray ( vCountList );
    }

    // --------------------------------------------
    void MeshLoader::fillPolylistPrimitivesArray ( 
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
    void MeshLoader::fillPolygonsPrimitivesElements ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons& polygons, 
        size_t& faceIndex )
    {
        fillPolygonsPArrays ( polygonsRef, polygons, faceIndex );
        fillPolygonsPHArrays(polygonsRef, polygons, faceIndex);
    }

    // --------------------------------------------
    void MeshLoader::fillPolygonsPArrays ( 
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
        COLLADAFW::PElement* pElements = new COLLADAFW::PElement [ numPolygons ];
        COLLADAFW::PArray pArray ( pElements, numPolygons );
        polygons.setPArray ( pArray );

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
    void MeshLoader::fillPolygonsPHArrays ( 
        const domPolygonsRef polygonsRef, 
        COLLADAFW::Polygons &polygons, 
        size_t& faceIndex )
    {
        // Gets the ph element array.
        domPolygons::domPh_Array domPHArray = polygonsRef->getPh_array ();

        // Get the number of polygons in the current polygons element.
        size_t numPolygons = domPHArray.getCount ();

        // Create a COLLADAFW:PHArray and set it into the COLLADAFramework polygons object.
        COLLADAFW::PHElement* phElements = new COLLADAFW::PHElement [ numPolygons ];
        COLLADAFW::PHArray phArray ( phElements, numPolygons );
        polygons.setPHArray ( phArray );

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
            COLLADAFW::HElement* hElements = new COLLADAFW::HElement [ hArraySize ];
            COLLADAFW::HArray hArray ( hElements, hArraySize );
            phElement.setHArray ( hArray );

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
    void MeshLoader::fillPListValues ( 
        const domPRef pRef, 
        COLLADAFW::PElement &pElement, 
        size_t& faceIndex )
    {
        // Get the values list.
        domListOfUInts domPList = pRef->getValue ();
        size_t pListSize = domPList.getCount ();

        // Create the COLLADAFramework polygons array list
        unsigned int* pValues = new unsigned int [ pListSize ];
        COLLADAFW::UIntValuesArray pArrayValues ( pValues, pListSize );
        pElement.setUIntValuesArray ( pArrayValues, faceIndex );

        // Increment the face index for the currently used face.
        ++faceIndex;

        // Fill the primitives list
        for ( size_t m=0; m<pListSize; ++m )
        {
            pArrayValues [ m ] = ( unsigned int ) domPList.get ( m );
        }
    }

    // --------------------------------------------
    void MeshLoader::fillHListValues ( 
        const domPolygons::domPh::domHRef hRef, 
        COLLADAFW::HElement &hElement, 
        size_t& faceIndex )
    {
        // Get the values list.
        domListOfUInts domHList = hRef->getValue ();
        size_t hListSize = domHList.getCount ();

        // Create the COLLADAFramework polygons array list
        unsigned int* hValues = new unsigned int [ hListSize ];
        COLLADAFW::UIntValuesArray hListValues ( hValues, hListSize );
        hElement.setUIntValuesArray ( hListValues, faceIndex );

        // Increment the face index for the currently used face.
        ++faceIndex;

        // Fill the primitives list
        for ( size_t m=0; m<hListSize; ++m )
        {
            hListValues [ m ] = ( unsigned int ) domHList.get ( m );
        }
    }

}