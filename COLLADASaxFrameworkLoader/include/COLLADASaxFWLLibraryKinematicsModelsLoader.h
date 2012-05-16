/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYKINEMATICSMODELLOADER_H__
#define __COLLADASAXFWL_LIBRARYKINEMATICSMODELLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLJointsLoader.h"
#include "COLLADASaxFWLFormulasLoader.h"
#include "COLLADASaxFWLTransformationLoader.h"
#include "COLLADASaxFWLKinematicsIntermediateData.h"
#include "COLLADASaxFWLFilePartLoader.h"

namespace COLLADAFW
{
	class Transformation;
}

namespace COLLADASaxFWL
{

    /** Loads an entire library kinematics and stores the data in KinematicsIntermediateData.  */
	class LibraryKinematicsModelsLoader : public FilePartLoader, public FormulasLoader
	{
	private:
		typedef std::stack<KinematicLink*> LinkStack;

	private:
		/** handles all joint related elements.*/
		JointsLoader mJointsLoader;

		TransformationLoader mTransformationLoader;


		/** The kinematics model, that is currently being parsed. Null if none is being parsed.*/
		KinematicsModel* mCurrentKinematicsModel;

		/** The joint instance, that is currently being parsed. Null if none is being parsed.*/
		KinematicInstance* mCurrentJointInstance;

		/** Stack of the links in the current model.*/
		LinkStack mLinkStack;

		/** The attachment currently being parse. ( the last in the tree only).*/
		KinematicAttachment* mCurrentAttachment;

	public:

        /** Constructor. */
		LibraryKinematicsModelsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryKinematicsModelsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		bool beginAttachment( KinematicAttachment::Type attachmentType, const attachment_AttributeData& attributeData );
		bool endAttachment();

		/** This method handles the beginning of a transformation independent of its type.*/
		template<class Transformationtype> 
		bool beginTransformation( const char* sid);

		/** This method handles the ending of a transformation independent of its type.*/
		bool endTransformation();

		/** Joint methods begin.*/
		virtual bool begin__joint( const joint__AttributeData& attributeData ) { return mJointsLoader.begin__joint(attributeData); }
		virtual bool end__joint() { return mJointsLoader.end__joint(); }

		virtual bool begin__prismatic( const prismatic__AttributeData& attributeData ) { return mJointsLoader.begin__prismatic(attributeData); }
		virtual bool end__prismatic() { return mJointsLoader.end__prismatic(); }

		virtual bool begin__revolute( const revolute__AttributeData& attributeData ) { return mJointsLoader.begin__revolute(attributeData); }
		virtual bool end__revolute() { return mJointsLoader.end__revolute(); }

		virtual bool begin__axis____axis_type( const axis____axis_type__AttributeData& attributeData ) { return mJointsLoader.begin__axis____axis_type(attributeData); }
		virtual bool end__axis____axis_type() { return mJointsLoader.end__axis____axis_type(); }
		virtual bool data__axis____axis_type( const float* value, size_t length ) { return mJointsLoader.data__axis____axis_type(value, length); }

		virtual bool begin__limits____joint_limits_type(){ { return mJointsLoader.begin__limits____joint_limits_type(); }}
		virtual bool end__limits____joint_limits_type(){ { return mJointsLoader.end__limits____joint_limits_type(); }}

		virtual bool begin__min____minmax_type( const min____minmax_type__AttributeData& attributeData ){ { return mJointsLoader.begin__min____minmax_type(attributeData); }}
		virtual bool end__min____minmax_type(){ { return mJointsLoader.end__min____minmax_type(); }}
		virtual bool data__min____minmax_type( float value ) { return mJointsLoader.data__min____minmax_type(value); }

		virtual bool begin__max____minmax_type( const max____minmax_type__AttributeData& attributeData ){ { return mJointsLoader.begin__max____minmax_type(attributeData); }}
		virtual bool end__max____minmax_type(){ { return mJointsLoader.end__max____minmax_type(); }}
		virtual bool data__max____minmax_type( float value ) { return mJointsLoader.data__max____minmax_type(value); }

		/** Joint methods end.*/


		virtual bool end__library_kinematics_models();

		virtual bool begin__kinematics_model( const kinematics_model__AttributeData& attributeData );
		virtual bool end__kinematics_model();

		virtual bool begin__technique_common____kinematics_model_technique_type(){return true;}
		virtual bool end__technique_common____kinematics_model_technique_type(){return true;}

		virtual bool begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData ){return true;}
		virtual bool end__newparam____kinematics_newparam_type(){return true;}

		virtual bool begin__instance_joint( const instance_joint__AttributeData& attributeData );
		virtual bool end__instance_joint();

		virtual bool begin__link( const link__AttributeData& attributeData );
		virtual bool end__link();

		virtual bool begin__attachment_full( const attachment_AttributeData& attributeData );
		virtual bool end__attachment_full();

		virtual bool begin__attachment_start( const attachment_AttributeData& attributeData );
		virtual bool end__attachment_start();

		virtual bool begin__attachment_end( const attachment_AttributeData& attributeData );
		virtual bool end__attachment_end();

		virtual bool begin__translate( const translate__AttributeData& attributeData );
		virtual bool end__translate();
		virtual bool data__translate( const float* data, size_t length );

		virtual bool begin__rotate( const rotate__AttributeData& attributeData );
		virtual bool end__rotate();
		virtual bool data__rotate( const float* data, size_t length );



	private:

        /** Disable default copy ctor. */
		LibraryKinematicsModelsLoader( const LibraryKinematicsModelsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryKinematicsModelsLoader& operator= ( const LibraryKinematicsModelsLoader& pre );
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYKINEMATICSMODELLOADER_H__
