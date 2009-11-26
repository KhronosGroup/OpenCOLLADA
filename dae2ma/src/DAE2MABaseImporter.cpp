/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "DAE2MAStableHeaders.h"
#include "DAE2MABaseImporter.h"

#include "Math/COLLADABUMathUtils.h"

#include <MayaDMCommands.h>


namespace DAE2MA
{
    /** The maya block size value for writing maya ascii files. */
    const size_t BaseImporter::MAYA_BLOCK_SIZE = 4000;

    /** Attribute values. */
    const String BaseImporter::ATTRIBUTE_DATA_TYPE = "dt";
    const String BaseImporter::ATTRIBUTE_ATTRIBUTE_TYPE = "at";
    const String BaseImporter::ATTRIBUTE_TYPE = "type";
    const String BaseImporter::ATTRIBUTE_TYPE_STRING = "string";
    const String BaseImporter::ATTRIBUTE_TYPE_STRING_ARRAY = "stringArray";
    const String BaseImporter::ATTRIBUTE_TYPE_COMPOUND = "compound";
    const String BaseImporter::ATTRIBUTE_PARENT = "p";
    const String BaseImporter::ATTRIBUTE_NUMBER_OF_CHILDREN = "nc";
    const String BaseImporter::ATTRIBUTE_HIDDEN = "h";

    /** The standard name for a group without name. */
    const String BaseImporter::GROUP_ID_NAME = "groupId";
    const String BaseImporter::GROUP_ID_NAME_APPEND = "GroupId";
    const String BaseImporter::GROUP_PARTS_NAME = "groupParts";
    const String BaseImporter::GROUP_PARTS_NAME_APPEND = "GroupParts";


    //-----------------------------
    double BaseImporter::toLinearUnit ( const double val )
    {
        return ( val * mDocumentImporter->getLinearUnitConvertFactor () );
    }

    //-----------------------------
    float BaseImporter::toLinearUnit ( const float val )
    {
        return ( val * (float) mDocumentImporter->getLinearUnitConvertFactor () );
    }

    //-----------------------------
    MayaDM::double3 BaseImporter::toLinearUnit ( const MayaDM::double3& val )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( toLinearUnit ( val[1]*(-1) ), toLinearUnit ( val[0] ), toLinearUnit ( val[2] ) ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[2] ), toLinearUnit ( val[1]*(-1) ) ) );
//         else return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
        return ( MayaDM::double3 ( toLinearUnit ( val[0] ), toLinearUnit ( val[1] ), toLinearUnit ( val[2] ) ) );
    }

    //-----------------------------
    MayaDM::double3 BaseImporter::toAngularUnit ( const MayaDM::double3& val )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[1]*(-1) ), COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[2] ) ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[2] ), COLLADABU::Math::Utils::radToDeg ( val[1]*(-1) ) ) );
//         else return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[1] ), COLLADABU::Math::Utils::radToDeg ( val[2] ) ) );
        return ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg ( val[0] ), COLLADABU::Math::Utils::radToDeg ( val[1] ), COLLADABU::Math::Utils::radToDeg ( val[2] ) ) );
    }

    //-----------------------------
    void BaseImporter::toLinearUnit ( const double val0, const double val1, const double val2, COLLADABU::Math::Vector3& retVal )
    {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//         {
//             retVal [0] = toLinearUnit ( val1*(-1) );
//             retVal [1] = toLinearUnit ( val0 );
//             retVal [2] = toLinearUnit ( val2 );
//         }
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//         {
//             retVal [0] = toLinearUnit ( val0 );
//             retVal [1] = toLinearUnit ( val2 );
//             retVal [2] = toLinearUnit ( val1*(-1) );
//         }
//         else 
        {
            retVal [0] = toLinearUnit ( val0 );
            retVal [1] = toLinearUnit ( val1 );
            retVal [2] = toLinearUnit ( val2 );
        }
    }

    //-----------------------------
    double BaseImporter::toMayaBindShapeBugLinearUnit ( const double val )
    {
        return ( val * mDocumentImporter->getLinearUnitMayaBindShapeBugConvertFactor () );
    }

    //-----------------------------
    float BaseImporter::toMayaBindShapeBugLinearUnit ( const float val )
    {
        return ( val * (float) mDocumentImporter->getLinearUnitMayaBindShapeBugConvertFactor () );
    }

//     //-----------------------------
//     MayaDM::double3 BaseImporter::toUpAxisTypeAxis ( const MayaDM::double3& val )
//     {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( val[1]*(-1), val[0], val[2] ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( val[0], val[2], val[1]*(-1) ) );
//         else return ( MayaDM::double3 ( val[0], val[1], val[2] ) );
//     }
// 
//     //-----------------------------
//     MayaDM::double3 BaseImporter::toUpAxisTypeFactor ( const MayaDM::double3& val )
//     {
//         if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::X_UP )
//             return ( MayaDM::double3 ( val[1], val[0], val[2] ) );
//         else if ( mDocumentImporter->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
//             return ( MayaDM::double3 ( val[0], val[2], val[1] ) );
//         else return ( MayaDM::double3 ( val[0], val[1], val[2] ) );
//     }

    // -----------------------------------
    double BaseImporter::getDoubleValue ( 
        const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
        const size_t position )
    {
        double inputValue = 0;

        size_t numInputValues = inputValuesArray.getValuesCount ();
        if ( position > numInputValues - 1 )
            std::cerr << "Out of range error!" << std::endl;

        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        switch ( inputDataType )
        {
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::DoubleArray* inputValues = inputValuesArray.getDoubleValues ();
                inputValue = (*inputValues) [position];
            }
            break;
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::FloatArray* inputValues = inputValuesArray.getFloatValues ();
                inputValue = (double)(*inputValues) [position];
            }
            break;
        default:
            std::cerr << "AnimationImporter::setInTangents(): inputDataType unknown data type!" << std::endl;
        }

        return inputValue;
    }

    // -----------------------------------
    float BaseImporter::getFloatValue ( 
        const COLLADAFW::FloatOrDoubleArray &inputValuesArray, 
        const size_t position )
    {
        float inputValue = 0;

        size_t numInputValues = inputValuesArray.getValuesCount ();
        if ( position > numInputValues - 1 )
            std::cerr << "Out of range error!" << std::endl;

        const COLLADAFW::FloatOrDoubleArray::DataType& inputDataType = inputValuesArray.getType ();
        switch ( inputDataType )
        {
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::DoubleArray* inputValues = inputValuesArray.getDoubleValues ();
                inputValue = (float)(*inputValues) [position];
            }
            break;
        case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::FloatArray* inputValues = inputValuesArray.getFloatValues ();
                inputValue = (*inputValues) [position];
            }
            break;
        default:
            std::cerr << "AnimationImporter::setInTangents(): inputDataType unknown data type!" << std::endl;
        }

        return inputValue;
    }

    // -----------------------------------
    String BaseImporter::generateUniqueDependNodeName ( 
        String nodeName, 
        bool returnConverted /*= true*/, 
        bool alwaysAddNumberSuffix /*= false */ )
    {
        // Add the name into the global node name list. If there already exist another node with
        // the name, the node will be renamed.
        nodeName = mDocumentImporter->addGlobalNodeId ( nodeName, returnConverted, alwaysAddNumberSuffix );

        // Add the name into depend node list.
        mDocumentImporter->addDependNodeId ( nodeName );

        return nodeName;
    }

    // -----------------------------------
    String BaseImporter::generateUniqueDagNodeName ( 
        String nodeName, 
        MayaNode* parentMayaNode,
        bool returnConverted /*= true*/, 
        bool alwaysAddNumberSuffix /*= false */ )
    {
        // Check, if there is already a depend node, which use the node name.
        if ( mDocumentImporter->containsDependNodeId ( nodeName ) )
        {
            // Rename it and add the new name into the global node list.
            nodeName = mDocumentImporter->addGlobalNodeId ( nodeName, returnConverted, alwaysAddNumberSuffix );

            // Add the name into the scene graph dag node list.
            mDocumentImporter->addDagNodeId ( nodeName );

            // The name has to be unique under the current transform node. No renaming!
            String dummyNodeName = parentMayaNode->addChildNodeId ( nodeName );
            if ( !COLLADABU::Utils::equals ( dummyNodeName, nodeName ) )
                std::cerr << "Something went wrong on unique id handling!" << std::endl;	
        }
        else
        {
            // Add the dag node name to the list of node names under the current transform node.
            // If there is already a node with the current name, the node will be renamed.
            nodeName = parentMayaNode->addChildNodeId ( nodeName, returnConverted, alwaysAddNumberSuffix );

            // If there isn't already another scene graph dag node, which use the node name, we have
            // to add the node name in the list of scene graph dag nodes and in the global node list.
            if ( !mDocumentImporter->containsDagNodeId ( nodeName ) )
            {
                // Add the name into the global node list. No renaming!
                String dummyNodeName = mDocumentImporter->addGlobalNodeId ( nodeName );
                if ( !COLLADABU::Utils::equals ( dummyNodeName, nodeName ) )
                    std::cerr << "Something went wrong on unique id handling!" << std::endl;	

                // Add the name into the scene graph dag node list.
                mDocumentImporter->addDagNodeId ( nodeName );
            }
        }
        
        return nodeName;
    }

    // -----------------------------------
    String BaseImporter::getOriginalMayaId ( 
        const ExtraDataCallbackHandler &mayaIdCallbackHandler, 
        const COLLADAFW::UniqueId& uniqueId, 
        const StringHash& hashElement )
    {
        // Check if we are really in the camera element (nothing else should be...).
        const ExtraInfo* extraInfo = mayaIdCallbackHandler.findExtraInfo ( uniqueId, hashElement );
        if ( !extraInfo ) return EMPTY_STRING;

        // Return the original maya node id.
        return extraInfo->getOriginalMayaId ();
    }

//     // -----------------------------------
//     void BaseImporter::setExtraData ( const COLLADAFW::ExtraDataArray &extraDataArray )
//     {
//         // Iterate over the extra data tags.
//         const size_t numExtraData = extraDataArray.getCount ();
//         if ( numExtraData == 0 ) return;        
// 
//         /** The list of root tree extra elements. */
//         std::map<String, ExtraTreeElement*> rootExtraTreeElements;
// 
//         // First we have to build a tree. With this tree, we know the number of children of every 
//         // knot in the tree. We have to create a compound attribute for every knot. After we have
//         // created the compound attributes, we can set the extra data values.
//         createExtraDataTree ( extraDataArray, rootExtraTreeElements );
// 
//         // After we filled the tree, we have to create the attributes.
//         addExtraDataAttributes ( rootExtraTreeElements );
// 
//         // After all the attributes are created, we can set the attribute values.
//         setExtraDataAttributes ( rootExtraTreeElements );
// 
//         // Delete the tree elements.
//         std::map<String, ExtraTreeElement*>::iterator it = rootExtraTreeElements.begin ();
//         while ( it != rootExtraTreeElements.end () )
//         {
//             ExtraTreeElement* extraTreeElement = it->second;
//             delete extraTreeElement;
//             extraTreeElement = 0;
//             ++it;
//         }
//         rootExtraTreeElements.clear ();
//     }

//     // -----------------------------------
//     void BaseImporter::createExtraDataTree ( 
//         const COLLADAFW::ExtraDataArray& extraDataArray, 
//         std::map<String, ExtraTreeElement*>& rootExtraTreeElements )
//     {
//         // Build a tree of the extra data elements.
//         const size_t numExtraData = extraDataArray.getCount ();
//         if ( numExtraData == 0 ) return;        
// 
//         // Iterate over the extra data tags.
//         for ( size_t i=0; i<numExtraData; ++i )
//         {
//             // Get the current extra data pair.
//             const COLLADAFW::ExtraDataPair* extraDataPair = extraDataArray [i];
// 
//             // Get the key of the current extra data element.
//             const String& key = extraDataPair->getKey ();
//             if ( key.empty () ) continue;
// 
//             // Convert the source into maya style.
//             const String& source = extraDataPair->getValue ();
//             if ( source.empty () ) continue;
//             String encodedSource = COLLADABU::URI::uriEncode ( source );
//             COLLADABU::Utils::stringFindAndReplace ( encodedSource, "\"", "\\\"" );
// 
//             // Make a not const copy of the key.
//             String attributeName ( key );
// 
//             // Check, if we have some path underpath parts. For example "COLLADA/mesh/profile_name" 
//             // or "COLLADA/primitive_element[2]/profile_tristrip".
//             // Without a underpath part, a path looks just like "COLLADA/profile_name".
//             std::vector<String> pathParts;
//             COLLADABU::Utils::split ( attributeName, String ("/"), pathParts );
//             size_t numParts = pathParts.size ();
//             if ( numParts < 2 ) 
//             {
//                 std::cerr << "No valid extra tag: " << attributeName << std::endl;
//                 continue;
//             }
//             // Get the name of the current profile.
//             String profileName = pathParts [numParts-1];
// 
//             // Check if we have an "OpenCOLLADAMaya" tag. Don't preserve them.
//             if ( COLLADABU::Utils::equals ( profileName, PROFILE_MAYA ) ) continue;
// 
//             // Get / create the root element.
//             String parentElementName = pathParts [0];
//             ExtraTreeElement* parentElement = getRootExtraElement ( parentElementName, rootExtraTreeElements );
//             if ( !parentElement )
//             {
//                 parentElement = new ExtraTreeElement ( parentElementName );
//                 rootExtraTreeElements [parentElementName] = parentElement;
//             }
// 
//             // Flag, if we handle a primitive extra element.
//             bool physicalIndexElement = false;
// 
//             // Go over the underpathes and put the elements in the tree.
//             ExtraTreeElement* childElement = 0;
//             for ( size_t p=1; p<numParts; ++p )
//             {
//                 // Get the name of the current element.
//                 String childElementName;
// 
//                 // If we handle the index of an primitive extra element, we have to append the
//                 // parent element name in front of the current index (su).
//                 // If we handle the profile name (always the last element), we have to make the 
//                 // profile name unique for the current object. To do this, we also append the 
//                 // parent element name in front of the current profile name.
//                 if ( physicalIndexElement || p == numParts-1 )
//                 {
//                     childElementName = parentElement->getName () + "_";
//                 }
//                 childElementName.append ( pathParts [p] );
// 
//                 // Check if we have an extra tag of an physical index element (primitive element, 
//                 // surface, sampler2d or texture). In this case, the next path element is just the 
//                 // physical index of the element. For maya attributes, the attribute name must not
//                 // start with a number! About this, we set the name of the parent element in front
//                 // of the current index.
//                 if ( COLLADABU::Utils::equals ( childElementName, COLLADAFW::ExtraKeys::PRIMITIVE_ELEMENT )
//                     || COLLADABU::Utils::equals ( childElementName, COLLADAFW::ExtraKeys::SURFACE )
//                     || COLLADABU::Utils::equals ( childElementName, COLLADAFW::ExtraKeys::SAMPLER2D )
//                     || COLLADABU::Utils::equals ( childElementName, COLLADAFW::ExtraKeys::TEXTURE ) )
//                 {
//                     // The next path element is a physical index.
//                     physicalIndexElement = true;
//                 }
//                 else physicalIndexElement = false;
// 
//                 // Check if there already exist an element with the current name under the parent element.
//                 childElement = parentElement->getChild ( childElementName );
//                 if ( !childElement )
//                 {
//                     // If not, create one.
//                     childElement = new ExtraTreeElement ( childElementName, parentElement );
//                     parentElement->addChild ( childElement );
//                 }
// 
//                 // Set the current child element for the next parent element.
//                 parentElement = childElement;
//             }
// 
//             // Add the current value to the values of the child.
//             childElement->appendValue ( encodedSource );
//         }
//     }

    // -----------------------------------
    void BaseImporter::addExtraDataAttributes ( 
        const std::map<String, ExtraTreeElement*>& rootExtraTreeElements )
    {
        // After we filled the tree, we have to create the attributes.
        std::map<String, ExtraTreeElement*>::const_iterator it = rootExtraTreeElements.begin ();
        while ( it != rootExtraTreeElements.end () )
        {
            // Get the current root element.
            const ExtraTreeElement* extraTreeElement = it->second;

            // Recursive call to add the attributes.
            addExtraDataAttribute ( extraTreeElement );

            ++it;
        }
    }

    // -----------------------------------
    void BaseImporter::addExtraDataAttribute ( const ExtraTreeElement* extraTreeElement )
    {
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the child attributes.
        const std::map<String, ExtraTreeElement*>& children = extraTreeElement->getChildren ();
        size_t numChildren = children.size ();

        // Create the flags.
        std::vector<MayaDM::AttributeFlag> attributeFlags;
        if ( extraTreeElement->getValue ().empty () )
        {
            // Create a compound attribute for the knot element.
            attributeFlags.push_back ( MayaDM::AttributeFlag ( ATTRIBUTE_ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_COMPOUND, false ) );
            attributeFlags.push_back ( MayaDM::AttributeFlag ( ATTRIBUTE_NUMBER_OF_CHILDREN, COLLADABU::Utils::toString ( numChildren ), false ) );
        }
        else
        {
            // Create a normal attribute for the current leaf element.
            attributeFlags.push_back ( MayaDM::AttributeFlag ( ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING ) );
        }

        // Get the parent element if it exist and set it into the current tree element.
        const ExtraTreeElement* parentExtraElement = extraTreeElement->getParent ();
        if ( parentExtraElement )
            attributeFlags.push_back ( MayaDM::AttributeFlag ( ATTRIBUTE_PARENT, parentExtraElement->getName (), false ) );

        // Add the current extra tree element.
        attributeFlags.push_back ( MayaDM::AttributeFlag ( ATTRIBUTE_HIDDEN, "true", false ) );
        MayaDM::addAttr ( file, extraTreeElement->getName (), attributeFlags );

        // Recursive call.
        std::map<String, ExtraTreeElement*>::const_iterator it = children.begin ();
        while ( it != children.end () )
        {
            addExtraDataAttribute ( it->second );
            ++it;
        }
    }

    // -----------------------------------
    void BaseImporter::setExtraDataAttributes ( 
        const std::map<String, ExtraTreeElement*>& rootExtraTreeElements )
    {
        // After all the attributes are created, we can set the attribute values.
        std::map<String, ExtraTreeElement*>::const_iterator it = rootExtraTreeElements.begin ();
        while ( it != rootExtraTreeElements.end () )
        {
            // Get the current root element.
            const ExtraTreeElement* extraTreeElement = it->second;

            // Set the extra data recursive.
            setExtraDataAttribute ( extraTreeElement );

            ++it;
        }
    }

    // -----------------------------------
    void BaseImporter::setExtraDataAttribute ( const ExtraTreeElement* extraTreeElement )
    {
        FILE* file = getDocumentImporter ()->getFile ();

        if ( !extraTreeElement->getValue().empty () )
        {
            String attributeName = extraTreeElement->getName ();
            String attributeValue = extraTreeElement->getValue ();
            MayaDM::setAttr ( file, attributeName, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, attributeValue );
        }

        // Get the child attributes.
        const std::map<String, ExtraTreeElement*>& children = extraTreeElement->getChildren ();
        size_t numChildren = children.size ();

        // Recursive call.
        std::map<String, ExtraTreeElement*>::const_iterator it = children.begin ();
        while ( it != children.end () )
        {
            setExtraDataAttribute ( it->second );
            ++it;
        }

    }

    // -----------------------------------
    BaseImporter::ExtraTreeElement* BaseImporter::getRootExtraElement ( 
        const String& name, 
        const std::map<String, ExtraTreeElement*>& rootExtraTreeElements )
    {
        std::map<String, ExtraTreeElement*>::const_iterator it = rootExtraTreeElements.find ( name );
        if ( it != rootExtraTreeElements.end () ) return it->second;
        return 0;
    }

    // -----------------------------------
    COLLADABU::Math::Matrix3 BaseImporter::extract3x3MatrixWithNormalizedColumns ( 
        const COLLADABU::Math::Matrix4 &transformMatrix )
    {
        COLLADABU::Math::Matrix3 m3x3;
        transformMatrix.extract3x3Matrix ( m3x3 );

        // Take the scale from the matrix.
        COLLADABU::Math::Vector3 scale = transformMatrix.getScale ();

        // Remove the scale from the matrix.
        COLLADABU::Math::Vector3 col0 = m3x3.getColumn (0) * (1/scale.x);
        m3x3.setColumn ( 0, col0 );
        COLLADABU::Math::Vector3 col1 = m3x3.getColumn (1) * (1/scale.y);
        m3x3.setColumn ( 1, col1 );
        COLLADABU::Math::Vector3 col2 = m3x3.getColumn (2) * (1/scale.z);
        m3x3.setColumn ( 2, col2 );

        // Check if we now have an orthogonale matrix. If not, we can't get the rotation!
        double scalarProduct0 = col0.dotProduct ( col1 );
        double scalarProduct1 = col1.dotProduct ( col2 );
        double scalarProduct2 = col2.dotProduct ( col0 );
        if ( !COLLADABU::Math::Utils::equals ( scalarProduct0, 0.0, getTolerance () ) 
            || !COLLADABU::Math::Utils::equals ( scalarProduct1, 0.0, getTolerance () ) 
            || !COLLADABU::Math::Utils::equals ( scalarProduct2, 0.0, getTolerance () ) )
        {
            std::cerr << "Can't get the rotation, about we have a skew in the transform matrix!" << std::endl;
            return COLLADABU::Math::Matrix3::IDENTITY;
        }

        return m3x3;
    }

} // namespace DAE2MA
