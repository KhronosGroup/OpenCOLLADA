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

#include "COLLADABUHashFunctions.h"
#include "COLLADABUURI.h"
#include "COLLADABUhash_map.h"

#include <list>


namespace COLLADAFW
{
	class Joint;
}


namespace COLLADASaxFWL
{
	class SidTreeNode;

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
		COLLADABU::URI mUrl;

		/** The name of the kinematics model.*/
		String mName;

		SidTreeNode* mSidTreeNode;
	public:
		KinematicsModel(const COLLADABU::URI& url, const char* name );

		~KinematicsModel();

		void addBaseLink( KinematicLink* baseLink ) { mBaseLinks.push_back(baseLink); }

		const KinematicLinkList& getBaseLinks() const { return mBaseLinks; }

		/** The name of the kinematics model.*/
		const String& getName() const { return mName; }

		/** The id of the kinematics model.*/
		const COLLADABU::URI& getUrl() const { return mUrl; }

		SidTreeNode* getSidTreeNode() const { return mSidTreeNode; }
		void setSidTreeNode(SidTreeNode* val) { mSidTreeNode = val; }
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
			case VALUETYPE_UNKNOWN:
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

	typedef COLLADABU::hash_map<String/*sid*/, KinematicsNewParam*> KinematicsNewParams;


	class KinematicsInstanceKinematicsModel : public KinematicInstance
	{
	private:
		KinematicsNewParams mKinematicsNewParams;
	public:
		KinematicsInstanceKinematicsModel( const COLLADABU::URI& uRL)
			: KinematicInstance(uRL){}

		~KinematicsInstanceKinematicsModel() { deleteMap(mKinematicsNewParams);}

		void addKinematicsNewParam(KinematicsNewParam* newParam);

		const KinematicsNewParams& getKinematicsNewParams() const { return mKinematicsNewParams; }

		KinematicsNewParams& getKinematicsNewParams() { return mKinematicsNewParams; }

		KinematicsNewParam* getNewParamBySid(const String& sid)const;

	};

	typedef std::list<KinematicsInstanceKinematicsModel> KinematicsInstanceKinematicsModels;

	/** A kinematics controller as described in COLLADA articulated system.*/
	class KinematicsController: public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICCONTROLLER>
	{
	private:
		/** The id of the kinematics controller.*/
		COLLADABU::URI mUri;

		/** The name of the kinematics controller.*/
		String mName;

		AxisInfoList mAxisInfos;
		KinematicsInstanceKinematicsModels mKinematicsInstanceKinematicsModels;

	public:
		KinematicsController(const COLLADABU::URI& uri, const String& name )
			: mUri( uri ), mName(name) {}

		~KinematicsController(){}

		/** The name of the kinematics controller.*/
		const String& getName() const { return mName; }

		/** The id of the kinematics controller.*/
		const COLLADABU::URI& getUri() const { return mUri; }

		const AxisInfoList& getAxisInfos() const { return mAxisInfos; }
		AxisInfoList& getAxisInfos(){ return mAxisInfos; }

		const KinematicsInstanceKinematicsModels& getKinematicsInstanceKinematicsModels() const { return mKinematicsInstanceKinematicsModels; }
		KinematicsInstanceKinematicsModels& getKinematicsInstanceKinematicsModels() { return mKinematicsInstanceKinematicsModels; }
	};


	/** Bind as it appears in kinematics */
	class KinematicsBind
	{
	public:
		enum ValueType { VALUETYPE_UNKNOWN, VALUETYPE_FLOAT, VALUETYPE_INT, VALUETYPE_BOOL, VALUETYPE_SIDREF, VALUETYPE_PARAM};
	private:
		/** Value type of the bind.*/
		ValueType mValueType;

		union Value
		{
			double _double;
			int _int;
			bool _bool;
			SidAddress* _sidref;
			String* _param;
		} mValue;

		/** The symbol of the bind (sid in COLLADA).*/
		String mSymbol;
	public:

		/** Constructor. */
		KinematicsBind(ValueType valueType);

		/** Constructor. */
		KinematicsBind();

		/** Destructor. */
		virtual ~KinematicsBind(){deleteAll();}

		/** Returns the value type of the bind.*/
		ValueType getValueType() const { return mValueType; }

		/** Sets the value type of the bind.*/
		//		void setValueType(ValueType valueType) { mValueType = valueType; }

		/** Returns the double value of the bind. Type must be VALUETYPE_FLOAT.*/
		double getDoubleValue() const { return mValue._double; }

		/** Sets the double value of the bind. Type will be set to VALUETYPE_FLOAT.*/
		void setDoubleValue(double doubleValue) { deleteAll(); mValue._double = doubleValue; mValueType = VALUETYPE_FLOAT; }

		/** Returns the int value of the bind. Type must be VALUETYPE_INT.*/
		int getIntValue() const { return mValue._int; }

		/** Sets the int value of the bind. Type will be set to VALUETYPE_INT.*/
		void setIntValue(int intValue) { deleteAll(); mValue._int = intValue; mValueType = VALUETYPE_INT; }

		/** Returns the bool value of the bind. Type must be VALUETYPE_BOOL.*/
		bool getBoolValue() const { return mValue._bool; }

		/** Sets the bool value of the bind. Type will be set to VALUETYPE_BOOL.*/
		void setBoolValue(bool boolValue) { deleteAll(); mValue._bool = boolValue; mValueType = VALUETYPE_BOOL; }

		/** Returns the sidref value of the bind. Type must be VALUETYPE_SIDREF.*/
		const SidAddress* getSidrefValue() const { return mValue._sidref; }

		/** Sets the sidref value of the bind. Type will be set to VALUETYPE_SIDREF.*/
		void setSidrefValue( const SidAddress& sidrefValue) { deleteAll(); mValue._sidref = new SidAddress(sidrefValue); mValueType = VALUETYPE_SIDREF; }

		/** Returns the param ref of the bind. Type must be VALUETYPE_PARAM.*/
		const String* getParamValue() const { return mValue._param; }

		/** Sets the param value of the bind. Type will be set to VALUETYPE_PARAM.*/
		void setParamValue( const String& paramValue) { deleteAll(); mValue._param = new String(paramValue); mValueType = VALUETYPE_PARAM; }

		/** Returns the name of the bind (sid in COLLADA).*/
		const String& getSymbol() const { return mSymbol; }

		/** Returns the name of the bind (sid in COLLADA).*/
		void setSymbol(const String& symbol) { mSymbol = symbol; }

	private:
		void deleteSidRef()
		{
			if ( mValueType == VALUETYPE_SIDREF)
			{
				delete mValue._sidref;
				mValue._sidref = 0;
			}
		}

		void deleteParam()
		{
			if ( mValueType == VALUETYPE_PARAM)
			{
				delete mValue._param;
				mValue._param = 0;
			}
		}

		void deleteAll()
		{
			deleteSidRef();
			deleteParam();
		}

		/** Disable default copy ctor. */
		KinematicsBind( const KinematicsBind& pre );

		/** Disable default assignment operator. */
		const KinematicsBind& operator= ( const KinematicsBind& pre );
	};

	typedef std::vector<KinematicsBind*> KinematicsBinds;



	/** A kinematics controller as described in COLLADA articulated system.*/
	class KinematicsInstanceArticulatedSystem : public KinematicInstance	
	{
	private:
		KinematicsNewParams mKinematicsNewParams;
		KinematicsBinds mKinematicsBinds;

	public:
		KinematicsInstanceArticulatedSystem( const COLLADABU::URI& uRL)
			: KinematicInstance(uRL){}

		~KinematicsInstanceArticulatedSystem();

		void addBind( KinematicsBind* bind) { mKinematicsBinds.push_back(bind); }

	};

	typedef std::vector<KinematicsInstanceArticulatedSystem*> KinematicsInstanceArticulatedSystems;

	/** A kinematics scene as described in COLLADA articulated system.*/
	class KinematicsScene: public IntermediateTargetableTemplate<INTERMEDIATETARGETABLE_TYPE::KINEMATICSCENE>
	{
	private:
		/** The id of the kinematics scene.*/
		COLLADABU::URI mUri;

		/** The name of the kinematics scene.*/
		String mName;

		KinematicsInstanceArticulatedSystems mKinematicsInstanceArticulatedSystems;

		KinematicsInstanceKinematicsModels mKinematicsInstanceKinematicsModels;

	public:
		KinematicsScene(const COLLADABU::URI& uri, const String& name )
			: mUri( uri ), mName(name) {}

		~KinematicsScene();

		void addInstanceArticulatedSystem(KinematicsInstanceArticulatedSystem* kinematicsInstanceArticulatedSystem);

		const KinematicsInstanceArticulatedSystems& getKinematicsInstanceArticulatedSystems() const { return mKinematicsInstanceArticulatedSystems; }

		void addInstanceKinematicsModel(KinematicsInstanceKinematicsModel* kinematicsInstanceKinematicsModel);

		const KinematicsInstanceKinematicsModels& getKinematicsInstanceKinematicsModels() const { return mKinematicsInstanceKinematicsModels; }

		KinematicsInstanceKinematicsModels& getKinematicsInstanceKinematicsModels() { return mKinematicsInstanceKinematicsModels; }

		/** The id of the kinematics scene.*/
		const COLLADABU::URI& getUri() const { return mUri; }
	};


	/** Bind as it appears in kinematics */
	class KinematicsSidrefOrParam
	{
	public:
		enum ValueType { VALUETYPE_UNKNOWN, VALUETYPE_PARAM, VALUETYPE_SIDREF};
	private:
		/** Value type of the bind.*/
		ValueType mValueType;

		union Value
		{
			SidAddress* _sidref;
			String* _param;
		} mValue;

		/** The symbol of the bind (sid in COLLADA).*/
		String mSymbol;
	public:

		/** Constructor. */
		KinematicsSidrefOrParam(ValueType axisType);

		/** Constructor. */
		KinematicsSidrefOrParam() : mValueType(VALUETYPE_UNKNOWN){}

		/** Destructor. */
		virtual ~KinematicsSidrefOrParam(){deleteAll();}

		/** Returns the value type SidrefOrParam.*/
		ValueType getValueType() const { return mValueType; }

		/** Returns the sidref value SidrefOrParam. Type must be VALUETYPE_SIDREF.*/
		const SidAddress* getSidrefValue() const { return mValue._sidref; }

		/** Sets the sidref value SidrefOrParam. Type will be set to VALUETYPE_SIDREF.*/
		void setSidrefValue( const SidAddress& sidrefValue);

		/** Returns the param ref SidrefOrParam. Type must be VALUETYPE_PARAM.*/
		const String* getParamValue() const { return mValue._param; }

		/** Sets the param value SidrefOrParam. Type will be set to VALUETYPE_PARAM.*/
		void setParamValue( const String& paramValue);
	private:
		void deleteSidRef();

		void deleteParam();

		void deleteAll();

		/** Disable default copy ctor. */
		KinematicsSidrefOrParam( const KinematicsSidrefOrParam& pre );

		/** Disable default assignment operator. */
		const KinematicsSidrefOrParam& operator= ( const KinematicsSidrefOrParam& pre );
	};

	typedef KinematicsSidrefOrParam KinematicsAxis;

	/** Bind as it appears in kinematics */
	class KinematicsFloatOrParam
	{
	public:
		enum ValueType { VALUETYPE_UNKNOWN, VALUETYPE_PARAM, VALUETYPE_FLOAT};
	private:
		/** Value type of the bind.*/
		ValueType mValueType;

		union Value
		{
			float _float;
			String* _param;
		} mValue;

		/** The symbol of the bind (sid in COLLADA).*/
		String mSymbol;
	public:

		/** Constructor. */
		KinematicsFloatOrParam(ValueType axisType);

		/** Constructor. */
		KinematicsFloatOrParam() : mValueType(VALUETYPE_UNKNOWN){}

		/** Destructor. */
		virtual ~KinematicsFloatOrParam(){deleteParam();}

		/** Returns the axis type FloatOrParam.*/
		ValueType getValueType() const { return mValueType; }

		/** Returns the sidref value FloatOrParam. Type must be VALUETYPE_FLOAT.*/
		float getFloatValue() const { return mValue._float; }

		/** Sets the sidref value FloatOrParam. Type will be set to VALUETYPE_FLOAT.*/
		void setFloatValue( float value) { deleteParam(); mValue._float=value; mValueType = VALUETYPE_FLOAT; }

		/** Returns the param ref FloatOrParam. Type must be VALUETYPE_PARAM.*/
		const String* getParamValue() const { return mValue._param; }

		/** Sets the param value FloatOrParam. Type will be set to VALUETYPE_PARAM.*/
		void setParamValue( const String& paramValue) { deleteParam(); mValue._param = new String(paramValue); mValueType = VALUETYPE_PARAM; }
	private:
		void deleteParam()
		{
			if ( mValueType == VALUETYPE_PARAM)
			{
				delete mValue._param;
				mValue._param = 0;
			}
		}

		/** Disable default copy ctor. */
		KinematicsFloatOrParam( const KinematicsFloatOrParam& pre );

		/** Disable default assignment operator. */
		const KinematicsFloatOrParam& operator= ( const KinematicsFloatOrParam& pre );
	};

	typedef KinematicsFloatOrParam KinematicsValue;

	/** bind_joint_axis as it appears in kinematics */
	class KinematicsBindJointAxis
	{
	private:

		/** The target of the bind (sid in COLLADA).*/
		SidAddress mTarget;
	
		/** The axis.*/
		KinematicsAxis mAxis;

		/** The value of the axis.*/
		KinematicsValue mValue;
	public:

		/** Constructor. */
		KinematicsBindJointAxis(SidAddress target) : mTarget(target){}

		/** Destructor. */
		virtual ~KinematicsBindJointAxis(){}

		/** Returns the target of the bind (sid in COLLADA).*/
		const SidAddress& getTarget() const { return mTarget; }

		/** Sets the target of the bind (sid in COLLADA).*/
		void setTarget( const SidAddress& target) { mTarget = target; }

		/** Returns the axis.*/
		const KinematicsAxis& getAxis() const { return mAxis; }

		/** Returns the axis.*/
		KinematicsAxis& getAxis(){ return mAxis; }

		/** Returns the value.*/
		const KinematicsValue& getValue() const { return mValue; }

		/** Returns the value.*/
		KinematicsValue& getValue(){ return mValue; }

	private:
		/** Disable default copy ctor. */
		KinematicsBindJointAxis( const KinematicsBindJointAxis& pre );

		/** Disable default assignment operator. */
		const KinematicsBindJointAxis& operator= ( const KinematicsBindJointAxis& pre );
	};

	typedef std::vector<KinematicsBindJointAxis*> KinematicsBindJointAxes;


	/** instance_kinematics_scene as it appears in kinematics */
	class KinematicsInstanceKinematicsScene
	{
	private:

		/** The url of the instantiate kinematics scene.*/
		COLLADABU::URI mUrl;

		KinematicsBindJointAxes mBindJointAxes;

		// file id

	public:

		/** Constructor. */
		KinematicsInstanceKinematicsScene(){}

		/** Destructor. */
		virtual ~KinematicsInstanceKinematicsScene();

		/** The url of the instantiate kinematics scene.*/
		COLLADABU::URI getUrl() const { return mUrl; }

		/** The url of the instantiate kinematics scene.*/
		void setUrl(COLLADABU::URI url) { mUrl = url; }

		void addBindJointAxis(KinematicsBindJointAxis* bindJointAxis) { mBindJointAxes.push_back(bindJointAxis);}

		const KinematicsBindJointAxes& getBindJointAxes() const { return mBindJointAxes; }
	private:
		/** Disable default copy ctor. */
		KinematicsInstanceKinematicsScene( const KinematicsInstanceKinematicsScene& pre );

		/** Disable default assignment operator. */
		const KinematicsInstanceKinematicsScene& operator= ( const KinematicsInstanceKinematicsScene& pre );
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
		typedef COLLADABU::hash_map< COLLADABU::URI, KinematicsModel* > KinematicsModelMap;

		/** List of kinematic controllers.*/
		typedef COLLADABU::hash_map< COLLADABU::URI, KinematicsController* > KinematicsControllerMap;

		/** List of kinematic scenes.*/
		typedef COLLADABU::hash_map< COLLADABU::URI, KinematicsScene* > KinematicsSceneMap;

		/** List of instance kinematics scenes.*/
		typedef std::vector<KinematicsInstanceKinematicsScene*> KinematicsInstanceKinematicsScenes;

	private:
		/** List of all joints already created. They will be written as part of kinematics.*/
		JointList mJoints;

		/** List of all instance joints already created. They will be written as part of kinematics.*/
		KinematicInstanceList mInstanceJoints;

		/** List of all kinematic models already created. They will be written as part of kinematics.*/
		KinematicsModelMap mKinematicsModels;

		/** List of all kinematic controller already created. They will be written as part of kinematics.*/
		KinematicsControllerMap mKinematicsControllers;

		/** List of all kinematic scenes already created. They will be written as part of kinematics.*/
		KinematicsSceneMap mKinematicsScenes;

		/** The only instance kinematics scenes.*/
		KinematicsInstanceKinematicsScenes mInstanceKinematicsScenes;

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
		const KinematicsModelMap& getKinematicsModels() const { return mKinematicsModels; }

		/** List of all kinematic models already created. They will be written as part of kinematics.*/
		KinematicsModelMap& getKinematicsModels() { return mKinematicsModels; }

		/** List of all kinematic controllers already created. They will be written as part of kinematics.*/
		const KinematicsControllerMap& getKinematicsControllers() const { return mKinematicsControllers; }

		/** List of all kinematic controllers already created. They will be written as part of kinematics.*/
		KinematicsControllerMap& getKinematicsControllers() { return mKinematicsControllers; }

		/** List of all kinematic scenes already created. They will be written as part of kinematics.*/
		const KinematicsSceneMap& getKinematicsScenes() const { return mKinematicsScenes; }

		/** List of all kinematic scenes already created. They will be written as part of kinematics.*/
		KinematicsSceneMap& getKinematicsScenes() { return mKinematicsScenes; }

		/** List of all instance kinematic scenes already created. They will be written as part of kinematics.*/
		const KinematicsInstanceKinematicsScenes& getInstanceKinematicsScenes() const { return mInstanceKinematicsScenes; }

		/** List of all instance kinematic scenes already created. They will be written as part of kinematics.*/
		KinematicsInstanceKinematicsScenes& getInstanceKinematicsScenes() { return mInstanceKinematicsScenes; }

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
