/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_KINEMATICSINTERMEDIATEDATA_H__
#define __COLLADASAXFWL_KINEMATICSINTERMEDIATEDATA_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLUtils.h"
#include "COLLADASaxFWLSidAddress.h"
#include "COLLADASaxFWLIntermediateTargetable.h"

#include "COLLADAFWTransformation.h"

#include "COLLADABUURI.h"

#include <list>


namespace COLLADAFW
{
	class Joint;
}


namespace COLLADASaxFWL
{

	typedef std::vector<COLLADAFW::Transformation*> TransformationList;

	/** An instance within kinematics.*/
	class KinematicInstance : public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICS_INSTANCE>
	{
	private:
		/** The URI of the referenced element in the COLLADA file.*/
		COLLADABU::URI mUrl;

		/** The unique id of the frame work object, that will replace the instance in the kinematics model.*/
		COLLADAFW::UniqueId mReplacingObjectUniqueId;

	public:
		KinematicInstance(COLLADABU::URI url) : mUrl(url){}

		KinematicInstance(COLLADABU::URI url, COLLADAFW::UniqueId replacingObjectUniqueId) : mUrl(url), mReplacingObjectUniqueId(replacingObjectUniqueId){}

		const COLLADABU::URI& getUrl() const { return mUrl; }

		/** The unique id of the frame work object, that will replace the instance in the kinematics model.*/
		const COLLADAFW::UniqueId& getReplacingObjectUniqueId() const { return mReplacingObjectUniqueId; }

		/** The unique id of the frame work object, that will replace the instance in the kinematics model.*/
		void setReplacingObjectUniqueId(COLLADAFW::UniqueId replacingObjectUniqueId) { mReplacingObjectUniqueId = replacingObjectUniqueId; }
	};


	class  KinematicAttachment;

	typedef std::vector<KinematicAttachment*> KinematicAttachmentList;

	/** A link within a kinematics model.*/
	class KinematicLink : public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICLINK>
	{
	private:
		KinematicAttachmentList mAttachments;
		TransformationList mTransformations;
	public:
		~KinematicLink(){ deleteVector(mAttachments); deleteVector(mTransformations); }

		/** Adds an attachment to the link. The link will be deleted on destruction.*/
		void addAttachment( KinematicAttachment* attachement ) { mAttachments.push_back(attachement); }

		/** Adds a transformation to the link. The transformation will be deleted on destruction.*/
		void addTransformation( COLLADAFW::Transformation* transformation ) { mTransformations.push_back(transformation); }

		const KinematicAttachmentList& getAttachments() const { return mAttachments; }

		const TransformationList& getTransformations() const { return mTransformations; }
	};
	
	typedef std::vector<KinematicLink*> KinematicLinkList;

	/** An attachment within a kinematics model.*/
	class KinematicAttachment : public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICATTACHMENT>
	{
	public:
		enum Type { FULL, START, END };
	private:
		KinematicLink mLink;
		Type mType;
		TransformationList mTransformations;
		SidAddress mJoint;
	public:
		KinematicAttachment( Type type, const SidAddress& joint ) 
			: mType(type) 
			, mJoint(joint)
		{}

		~KinematicAttachment(){ deleteVector(mTransformations); }

		const KinematicLink& getLink() const { return mLink; }
		KinematicLink& getLink(){ return mLink; }

		Type getType() const { return mType; }

		const SidAddress& getJoint() const { return mJoint; }

		/** Adds a transformation to the link. The transformation will be deleted on destruction.*/
		void addTransformation( COLLADAFW::Transformation* transformation ) { mTransformations.push_back(transformation); }

		const TransformationList& getTransformations() const { return mTransformations; }
	};


	/** A kinematics model as described in COLLADA.*/
	class KinematicsModel: public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICMODEL>
	{
	private:
		KinematicLinkList mBaseLinks;

		/** The id of the kinematics model.*/
		String mId;

		/** The name of the kinematics model.*/
		String mName;
	public:
		KinematicsModel(const char* id, const char* name );

		~KinematicsModel();

		void addBaseLink( KinematicLink* baseLink ) { mBaseLinks.push_back(baseLink); }

		const KinematicLinkList& getBaseLinks() const { return mBaseLinks; }

		/** The name of the kinematics model.*/
		const String& getName() const { return mName; }

		/** The id of the kinematics model.*/
		const String& getId() const { return mId; }
	};


	class AxisInfo 	
	{
	private:
		/** The joint primitive which axes is referenced by the AxisInfo.*/
		SidAddress mJointPrimitiveAddress;

		/** True if the joint is active, false otherwise. Defaults to true.*/
		bool mIsActive;

		/** True if the joint is locked, false otherwise. Defaults to false.*/
		bool mIsLocked;

		/** The index of the axis in the roboter. 1-base, 0 meas unset.*/
		int mIndex;
	public:

		/** Constructor. */
		AxisInfo(SidAddress jointPrimitiveAddress) 
			: mJointPrimitiveAddress(jointPrimitiveAddress)
			, mIsActive(true)
			, mIsLocked(false)
			, mIndex(0)
		{}

		/** Destructor. */
		virtual ~AxisInfo(){}

		/** The joint primitive which axes is referenced by the AxisInfo.*/
		const SidAddress& getJointPrimitiveRefAddress() const { return mJointPrimitiveAddress; }

		/** The joint primitive which axes is referenced by the AxisInfo.*/
		void setJointPrimitiveAddress( const SidAddress& jointPrimitiveAddress) { mJointPrimitiveAddress = jointPrimitiveAddress; }

		/** True if the joint is active, false otherwise .*/
		bool getIsActive() const { return mIsActive; }

		/** True if the joint is active, false otherwise .*/
		void setIsActive(bool isActive) { mIsActive = isActive; }

		/** True if the joint is locked, false otherwise .*/
		bool getIsLocked() const { return mIsLocked; }

		/** True if the joint is locked, false otherwise .*/
		void setIsLocked(bool isLocked) { mIsLocked = isLocked; }

		/** The index of the axis in the roboter. 1-base, 0 meas unset.*/
		int getIndex() const { return mIndex; }

		/** The index of the axis in the roboter. 1-base, 0 meas unset.*/
		void setIndex(int index) { mIndex = index; }
	};

	typedef std::vector<AxisInfo> AxisInfoList;


	/** New param as it appears in formula and kinematics */
	class KinematicsNewParam 	
	{
	public:
		enum ValueType { VALUETYPE_UNKNOWN, VALUETYPE_FLOAT, VALUETYPE_INT, VALUETYPE_BOOL, VALUETYPE_SIDREF};
	private:
		/** Value type of the new param.*/
		ValueType mValueType;

		
		union Value
		{
			double _double;
			int _int;
			bool _bool;
			SidAddress* _sidref;
		} mValue;

		/** The name of the new param (sid in COLLADA).*/
		String mName;
	public:

		/** Constructor. */
		KinematicsNewParam(ValueType valueType) 
			: mValueType(valueType)
		{
			switch ( mValueType )
			{
			case VALUETYPE_BOOL: 
				mValue._bool = true;
				break;
			case VALUETYPE_FLOAT: 
				mValue._double = 0;
				break;
			case VALUETYPE_INT: 
				mValue._int = 0;
				break;
			case VALUETYPE_SIDREF: 
				mValue._sidref = 0;
				break;
			}
		}

		/** Destructor. */
		virtual ~KinematicsNewParam(){deleteSidRef();}

		/** Returns the value type of the new param.*/
		ValueType getValueType() const { return mValueType; }

		/** Sets the value type of the new param.*/
//		void setValueType(ValueType valueType) { mValueType = valueType; }

		/** Returns the double value of the new param. Type must be VALUETYPE_FLOAT.*/
		double getDoubleValue() const { return mValue._double; }

		/** Sets the double value of the new param. Type will be set to VALUETYPE_FLOAT.*/
		void setDoubleValue(double doubleValue) { deleteSidRef(); mValue._double = doubleValue; mValueType = VALUETYPE_FLOAT; }

		/** Returns the int value of the new param. Type must be VALUETYPE_INT.*/
		int getIntValue() const { return mValue._int; }

		/** Sets the int value of the new param. Type will be set to VALUETYPE_INT.*/
		void setIntValue(int intValue) { deleteSidRef(); mValue._int = intValue; mValueType = VALUETYPE_INT; }

		/** Returns the bool value of the new param. Type must be VALUETYPE_BOOL.*/
		bool getBoolValue() const { return mValue._bool; }

		/** Sets the bool value of the new param. Type will be set to VALUETYPE_BOOL.*/
		void setBoolValue(bool boolValue) { deleteSidRef(); mValue._bool = boolValue; mValueType = VALUETYPE_BOOL; }

		/** Returns the sidref value of the new param. Type must be VALUETYPE_SIDREF.*/
		const SidAddress* getSidrefValue() const { return mValue._sidref; }

		/** Sets the sidref value of the new param. Type will be set to VALUETYPE_SIDREF.*/
		void setSidrefValue( const SidAddress& sidrefValue) { deleteSidRef(); mValue._sidref = new SidAddress(sidrefValue); mValueType = VALUETYPE_SIDREF; }

		/** Returns the name of the new param (sid in COLLADA).*/
		const String& getName() const { return mName; }

		/** Returns the name of the new param (sid in COLLADA).*/
		void setName(const String& name) { mName = name; }

	private:
		void deleteSidRef()
		{
			if ( mValueType == VALUETYPE_SIDREF)
			{
				delete mValue._sidref;
				mValue._sidref = 0;
			}
		}

		/** Disable default copy ctor. */
		KinematicsNewParam( const KinematicsNewParam& pre );

		/** Disable default assignment operator. */
		const KinematicsNewParam& operator= ( const KinematicsNewParam& pre );


	};


	class KinematicsInstanceKinematicsModel : public KinematicInstance
	{
	public:
		typedef std::vector<KinematicsNewParam*> KinematicsNewParams;
	private:
		KinematicsNewParams mKinematicsNewParams;
	public:
		KinematicsInstanceKinematicsModel( const COLLADABU::URI& uRL)
			: KinematicInstance(uRL){}

		~KinematicsInstanceKinematicsModel() { deleteVector(mKinematicsNewParams);}

		const KinematicsNewParams& getKinematicsNewParams() const { return mKinematicsNewParams; }

		KinematicsNewParams& getKinematicsNewParams() { return mKinematicsNewParams; }

	};

	typedef std::vector<KinematicsInstanceKinematicsModel> KinematicsInstanceKinematicsModels;

	/** A kinematics controller as described in COLLADA articulated system.*/
	class KinematicsController: public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICCONTROLLER>
	{
	private:
		/** The id of the kinematics controller.*/
		String mId;

		/** The name of the kinematics controller.*/
		String mName;

		AxisInfoList mAxisInfos;
		KinematicsInstanceKinematicsModels mKinematicsInstanceKinematicsModels;

	public:
		KinematicsController(const String& id, const String& name )
			: mId( id ), mName(name) {}

		~KinematicsController(){}

		/** The name of the kinematics controller.*/
		const String& getName() const { return mName; }

		/** The id of the kinematics controller.*/
		const String& getId() const { return mId; }

		const AxisInfoList& getAxisInfos() const { return mAxisInfos; }
		AxisInfoList& getAxisInfos(){ return mAxisInfos; }

		const KinematicsInstanceKinematicsModels& getKinematicsInstanceKinematicsModels() const { return mKinematicsInstanceKinematicsModels; }
		KinematicsInstanceKinematicsModels& getKinematicsInstanceKinematicsModels() { return mKinematicsInstanceKinematicsModels; }
	};


    /** Kinematics data that needs to be stored while parsing a COLLADA file. This data is used to 
	build the kinematics model, after the entire file has been parsed. 
	All the heap instances of FW classes are created by using FW_NEW, instances of other classes by using new.*/
	class KinematicsIntermediateData 	
	{
	public:
		/** List of Joints.*/
		typedef std::vector< COLLADAFW::Joint* > JointList;

		/** List of instance instances.*/
		typedef std::vector< KinematicInstance* > KinematicInstanceList;

		/** List of kinematic models.*/
		typedef std::vector< KinematicsModel* > KinematicsModelList;

		/** List of kinematic controller.*/
		typedef std::vector< KinematicsController* > KinematicsControllerList;


	private:
		/** List of all joints already created. They will be written as part of kinematics.*/
		JointList mJoints;

		/** List of all instance joints already created. They will be written as part of kinematics.*/
		KinematicInstanceList mInstanceJoints;

		/** List of all kinematic models already created. They will be written as part of kinematics.*/
		KinematicsModelList mKinematicsModels;

		/** List of all kinematic controller already created. They will be written as part of kinematics.*/
		KinematicsControllerList mKinematicsControllers;

	public:

		/** Returns the list of all joints already created. They will be written as part of kinematics.*/
		const JointList& getJoints() const { return mJoints; }

		/** Returns the list of all joints already created. They will be written as part of kinematics.*/
		JointList& getJoints() { return mJoints; }

		/** Returns the list of all InstanceJoints already created. They will be written as part of kinematics.*/
		const KinematicInstanceList& getInstanceJoints() const { return mInstanceJoints; }

		/** Returns the list of all InstanceJoints already created. They will be written as part of kinematics.*/
		KinematicInstanceList& getInstanceJoints() { return mInstanceJoints; }

		/** List of all kinematic models already created. They will be written as part of kinematics.*/
		const KinematicsModelList& getKinematicsModels() const { return mKinematicsModels; }

		/** List of all kinematic models already created. They will be written as part of kinematics.*/
		KinematicsModelList& getKinematicsModels() { return mKinematicsModels; }

		/** List of all kinematic controllers already created. They will be written as part of kinematics.*/
		const KinematicsControllerList& getKinematicsControllers() const { return mKinematicsControllers; }

		/** List of all kinematic controllers already created. They will be written as part of kinematics.*/
		KinematicsControllerList& getKinematicsControllers() { return mKinematicsControllers; }

        /** Constructor. */
		KinematicsIntermediateData();

        /** Destructor. */
		virtual ~KinematicsIntermediateData();

	private:

        /** Disable default copy ctor. */
		KinematicsIntermediateData( const KinematicsIntermediateData& pre );

        /** Disable default assignment operator. */
		const KinematicsIntermediateData& operator= ( const KinematicsIntermediateData& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_KINEMATICSINTERMEDIATEDATA_H__
