/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_VISUALSCENELOADER_H__
#define __COLLADASAXFWL_VISUALSCENELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"

#include "COLLADAFWNode.h"

#include <stack>


namespace COLLADAFW
{ 
	class VisualScene;
	class Transformation;
}

namespace COLLADASaxFWL
{

    /** Imports the entire visual scene and sends it to the writer. */
	class VisualSceneLoader : public FilePartLoader 
		{
	private:
		/** Stack of nodes.*/
		typedef std::stack<COLLADAFW::Node*> NodeStack;

		/** Pointer to the visual scene this loader creates.*/
		COLLADAFW::VisualScene* mVisualScene;

		/** Stack of nodes to traverse back in node hierarchy. Array and contents will be delete in destructor.*/
		NodeStack mNodeStack;

		/** The transformation, that is currently being pared. Null if none is being parsed.*/
		COLLADAFW::Transformation* mCurrentTransformation;

		/** The number of floats that have been received since the last begin* method 
		by the transformation data* methods. This is used to know where the next received number must 
		be placed in the transformation.*/
		size_t mTransformationNumbersReceived;
	public:

        /** Constructor. */
		VisualSceneLoader(IFilePartLoader* callingFilePartLoader);

        /** Destructor. */
		virtual ~VisualSceneLoader();

	private:

        /** Disable default copy ctor. */
		VisualSceneLoader( const VisualSceneLoader& pre );

        /** Disable default assignment operator. */
		const VisualSceneLoader& operator= ( const VisualSceneLoader& pre );

		/** This method handles the beginning of a node element, independent of its parent.*/
		bool beginNode( const char* nodeName );

		/** This method handles the ending of a node element, independent of its parent.*/
		bool endNode();

		/** This method handles the beginning of a transformation independent of its type.*/
		template<class Transformationtype>
		bool beginTransformation();

		/** This method handles the ending of a transformation independent of its type.*/
		bool endTransformation();

		/** Sax callback function for the beginning of nodes, as child of a node.*/
		virtual bool begin__node( const node__AttributeData& attributeData );
		
		/** Sax callback function for the ending of nodes, as child of a node.*/
		virtual bool end__node();


		/** Sax callback function for the beginning of nodes, as child of a visual scene.*/
		virtual bool begin__visual_scene__node( const visual_scene__node__AttributeData& attributeData );

		/** Sax callback function for the ending of nodes, as child of a visual scene.*/
		virtual bool end__visual_scene__node();


		/** Sax callback function for the beginning of a translate element.*/
		virtual bool begin__translate( const translate__AttributeData& attributeData );

		/** Sax callback function for the ending of a translate element.*/
		virtual bool end__translate();

		/** Sax callback function for the float data of a translate element.*/
		virtual bool data__translate( const double* data, size_t length );


		/** Sax callback function for the beginning of a rotate element.*/
		virtual bool begin__node__rotate( const node__rotate__AttributeData& attributeData );

		/** Sax callback function for the ending of a rotate element.*/
		virtual bool end__node__rotate();

		/** Sax callback function for the float data of a rotate element.*/
		virtual bool data__node__rotate( const double* data, size_t length );


		/** Sax callback function for the beginning of a matrix element.*/
		virtual bool begin__matrix( const matrix__AttributeData& attributeData );

		/** Sax callback function for the ending of a matrix element.*/
		virtual bool end__matrix();

		/** Sax callback function for the float data of a rotate element.*/
		virtual bool data__matrix( const double* data, size_t length );


		/** Sax callback function for the beginning of a scale element.*/
		virtual bool begin__scale( const scale__AttributeData& attributeData );

		/** Sax callback function for the ending of a scale element.*/
		virtual bool end__scale();

		/** Sax callback function for the float data of a scale element.*/
		virtual bool data__scale( const double* data, size_t length );


		/** Sax callback function for the beginning of an instance geometry element.*/
		virtual bool begin__node__instance_geometry( const node__instance_geometry__AttributeData& attributeData );

		/** Sax callback function for the beginning of an instance geometry element.*/
		virtual bool end__node__instance_geometry();


		/** Sax callback function for the ending of a visual scene.*/
		virtual bool end__visual_scene();



	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_VISUALSCENELOADER_H__
