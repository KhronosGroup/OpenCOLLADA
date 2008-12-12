/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKHANDLE_H__
#define __MayaDM_HIKHANDLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkHandle.h"
namespace MayaDM
{
/*
<p><pre>
 The hikHandle manages all of the effectors used to drive Human IK on
 a skeleton. Human IK is a full-body solver. Unlike the other ik
 handles in Maya, the hikHandle is not restricted to a single
 effector on a chain of joints. Instead, the hikHandle manages multiple
 effectors which are used to control biped or quadraped characters.

</pre></p>
*/
class HikHandle : public IkHandle
{
public:
	/*Folder for Solving controls*/
	struct Solving{
		unsigned int postureType;
		bool expertMode;
		float realisticShoulderSolving;
		bool solveFingers;
		unsigned int hipTranslationMode;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", postureType);
			fprintf_s(file,"%i ", expertMode);
			fprintf_s(file,"%f ", realisticShoulderSolving);
			fprintf_s(file,"%i ", solveFingers);
			fprintf_s(file,"%i", hipTranslationMode);
		}
	};
	/*Folder for Floor Contacts controls*/
	struct FloorContacts{
		bool handsFloorContact;
		bool feetFloorContact;
		bool fingersFloorContact;
		bool toesFloorContact;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", handsFloorContact);
			fprintf_s(file,"%i ", feetFloorContact);
			fprintf_s(file,"%i ", fingersFloorContact);
			fprintf_s(file,"%i", toesFloorContact);
		}
	};
	/*Folder for Hands Floor Contact Setup controls*/
	struct HandsFloorContactSetup{
		unsigned int handsFloorPivot;
		unsigned int handsContactType;
		float handsContactStiffness;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", handsFloorPivot);
			fprintf_s(file,"%i ", handsContactType);
			fprintf_s(file,"%f", handsContactStiffness);
		}
	};
	/*Folder for Contacts Position controls*/
	struct ContactsPosition{
		float handHeight;
		float handBack;
		float handMiddle;
		float handFront;
		float handInSide;
		float handOutSide;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", handHeight);
			fprintf_s(file,"%f ", handBack);
			fprintf_s(file,"%f ", handMiddle);
			fprintf_s(file,"%f ", handFront);
			fprintf_s(file,"%f ", handInSide);
			fprintf_s(file,"%f", handOutSide);
		}
	};
	/*Folder for Feet Floor Contact Setup controls*/
	struct FeetFloorContactSetup{
		unsigned int feetFloorPivot;
		unsigned int feetContactType;
		float feetContactStiffness;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", feetFloorPivot);
			fprintf_s(file,"%i ", feetContactType);
			fprintf_s(file,"%f", feetContactStiffness);
		}
	};
	/*Folder for feet contact position controls*/
	struct FeetContactPosition{
		float footHeight;
		float footBack;
		float footMiddle;
		float footFront;
		float footInSide;
		float footOutSide;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", footHeight);
			fprintf_s(file,"%f ", footBack);
			fprintf_s(file,"%f ", footMiddle);
			fprintf_s(file,"%f ", footFront);
			fprintf_s(file,"%f ", footInSide);
			fprintf_s(file,"%f", footOutSide);
		}
	};
	/*Folder for Fingers Floor Contact Setup controls*/
	struct FingersFloorContactSetup{
		unsigned int fingersContactType;
		float fingersContactRollStiffness;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", fingersContactType);
			fprintf_s(file,"%f", fingersContactRollStiffness);
		}
	};
	/*Folder for finger tips size controls*/
	struct FingerTipsSizes{
		float leftHandThumbTip;
		float leftHandIndexTip;
		float leftHandMiddleTip;
		float leftHandRingTip;
		float leftHandPinkyTip;
		float leftHandExtraFingerTip;
		float rightHandThumbTip;
		float rightHandIndexTip;
		float rightHandMiddleTip;
		float rightHandRingTip;
		float rightHandPinkyTip;
		float rightHandExtraFingerTip;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", leftHandThumbTip);
			fprintf_s(file,"%f ", leftHandIndexTip);
			fprintf_s(file,"%f ", leftHandMiddleTip);
			fprintf_s(file,"%f ", leftHandRingTip);
			fprintf_s(file,"%f ", leftHandPinkyTip);
			fprintf_s(file,"%f ", leftHandExtraFingerTip);
			fprintf_s(file,"%f ", rightHandThumbTip);
			fprintf_s(file,"%f ", rightHandIndexTip);
			fprintf_s(file,"%f ", rightHandMiddleTip);
			fprintf_s(file,"%f ", rightHandRingTip);
			fprintf_s(file,"%f ", rightHandPinkyTip);
			fprintf_s(file,"%f", rightHandExtraFingerTip);
		}
	};
	/*Folder for Toes Floor Contact Setup controls*/
	struct ToesFloorContactSetup{
		unsigned int toesContactType;
		float toesContactRollStiffness;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", toesContactType);
			fprintf_s(file,"%f", toesContactRollStiffness);
		}
	};
	/*Folder for Toe Tips Sizes controls*/
	struct ToeTipsSizes{
		float leftFootThumbTip;
		float leftFootIndexTip;
		float leftFootMiddleTip;
		float leftFootRingTip;
		float leftFootPinkyTip;
		float leftFootExtraFingerTip;
		float rightFootThumbTip;
		float rightFootIndexTip;
		float rightFootMiddleTip;
		float rightFootRingTip;
		float rightFootPinkyTip;
		float rightFootExtraFingerTip;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", leftFootThumbTip);
			fprintf_s(file,"%f ", leftFootIndexTip);
			fprintf_s(file,"%f ", leftFootMiddleTip);
			fprintf_s(file,"%f ", leftFootRingTip);
			fprintf_s(file,"%f ", leftFootPinkyTip);
			fprintf_s(file,"%f ", leftFootExtraFingerTip);
			fprintf_s(file,"%f ", rightFootThumbTip);
			fprintf_s(file,"%f ", rightFootIndexTip);
			fprintf_s(file,"%f ", rightFootMiddleTip);
			fprintf_s(file,"%f ", rightFootRingTip);
			fprintf_s(file,"%f ", rightFootPinkyTip);
			fprintf_s(file,"%f", rightFootExtraFingerTip);
		}
	};
	/*Folder for Head controls*/
	struct Head{
		float headPull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", headPull);
		}
	};
	/*Folder for Left Arm controls*/
	struct LeftArm{
		float leftElbowPull;
		float leftHandPullChest;
		float leftHandPullHips;
		float leftFingerBasePull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", leftElbowPull);
			fprintf_s(file,"%f ", leftHandPullChest);
			fprintf_s(file,"%f ", leftHandPullHips);
			fprintf_s(file,"%f", leftFingerBasePull);
		}
	};
	/*Folder for Right Arm controls*/
	struct RightArm{
		float rightElbowPull;
		float rightHandPullChest;
		float rightHandPullHips;
		float rightFingerBasePull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", rightElbowPull);
			fprintf_s(file,"%f ", rightHandPullChest);
			fprintf_s(file,"%f ", rightHandPullHips);
			fprintf_s(file,"%f", rightFingerBasePull);
		}
	};
	/*Folder for Chest controls*/
	struct Chest{
		float chestPull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", chestPull);
		}
	};
	/*Folder for Hips controls*/
	struct Hips{
		float hipsPull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", hipsPull);
		}
	};
	/*Folder for Left Leg controls*/
	struct LeftLeg{
		float leftKneePull;
		float leftFootPull;
		float leftToeBasePull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", leftKneePull);
			fprintf_s(file,"%f ", leftFootPull);
			fprintf_s(file,"%f", leftToeBasePull);
		}
	};
	/*Folder for Right Leg controls*/
	struct RightLeg{
		float rightKneePull;
		float rightFootPull;
		float rightToeBasePull;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", rightKneePull);
			fprintf_s(file,"%f ", rightFootPull);
			fprintf_s(file,"%f", rightToeBasePull);
		}
	};
	/*Folder for Extra controls*/
	struct Extra{
		float pullIterationCount;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", pullIterationCount);
		}
	};
	/*Folder for Stiffness controls*/
	struct Stiffness{
		float neckStiffness;
		float leftShoulderStiffness;
		float leftArmStiffness;
		float leftElbowMaxExtension;
		float leftElbowCompressionFactor;
		float rightShoulderStiffness;
		float rightArmStiffness;
		float rightElbowMaxExtension;
		float rightElbowCompressionFactor;
		float hipsEnforceGravity;
		float chestStiffness;
		float spineStiffness;
		float hipsStiffness;
		float leftKneeMaxExtension;
		float leftLegStiffness;
		float leftKneeCompressionFactor;
		float rightLegStiffness;
		float rightKneeMaxExtension;
		float rightKneeCompressionFactor;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", neckStiffness);
			fprintf_s(file,"%f ", leftShoulderStiffness);
			fprintf_s(file,"%f ", leftArmStiffness);
			fprintf_s(file,"%f ", leftElbowMaxExtension);
			fprintf_s(file,"%f ", leftElbowCompressionFactor);
			fprintf_s(file,"%f ", rightShoulderStiffness);
			fprintf_s(file,"%f ", rightArmStiffness);
			fprintf_s(file,"%f ", rightElbowMaxExtension);
			fprintf_s(file,"%f ", rightElbowCompressionFactor);
			fprintf_s(file,"%f ", hipsEnforceGravity);
			fprintf_s(file,"%f ", chestStiffness);
			fprintf_s(file,"%f ", spineStiffness);
			fprintf_s(file,"%f ", hipsStiffness);
			fprintf_s(file,"%f ", leftKneeMaxExtension);
			fprintf_s(file,"%f ", leftLegStiffness);
			fprintf_s(file,"%f ", leftKneeCompressionFactor);
			fprintf_s(file,"%f ", rightLegStiffness);
			fprintf_s(file,"%f ", rightKneeMaxExtension);
			fprintf_s(file,"%f", rightKneeCompressionFactor);
		}
	};
	/*Folder for kill pitch controls*/
	struct KillPitch{
		bool leftElbowKillPitch;
		bool rightElbowKillPitch;
		bool leftKneeKillPitch;
		bool rightKneeKillPitch;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", leftElbowKillPitch);
			fprintf_s(file,"%i ", rightElbowKillPitch);
			fprintf_s(file,"%i ", leftKneeKillPitch);
			fprintf_s(file,"%i", rightKneeKillPitch);
		}
	};
	/*Folder for Roll Extraction controls*/
	struct RollExtraction{
		unsigned int rollExtractionMode;
		bool leftArmRollMode;
		float leftArmRoll;
		bool leftForeArmRollMode;
		float leftForeArmRoll;
		bool rightArmRollMode;
		float rightArmRoll;
		bool rightForeArmRollMode;
		float rightForeArmRoll;
		bool leftUpLegRollMode;
		float leftUpLegRoll;
		bool leftLegRollMode;
		float leftLegRoll;
		bool rightUpLegRollMode;
		float rightUpLegRoll;
		bool rightLegRollMode;
		float rightLegRoll;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", rollExtractionMode);
			fprintf_s(file,"%i ", leftArmRollMode);
			fprintf_s(file,"%f ", leftArmRoll);
			fprintf_s(file,"%i ", leftForeArmRollMode);
			fprintf_s(file,"%f ", leftForeArmRoll);
			fprintf_s(file,"%i ", rightArmRollMode);
			fprintf_s(file,"%f ", rightArmRoll);
			fprintf_s(file,"%i ", rightForeArmRollMode);
			fprintf_s(file,"%f ", rightForeArmRoll);
			fprintf_s(file,"%i ", leftUpLegRollMode);
			fprintf_s(file,"%f ", leftUpLegRoll);
			fprintf_s(file,"%i ", leftLegRollMode);
			fprintf_s(file,"%f ", leftLegRoll);
			fprintf_s(file,"%i ", rightUpLegRollMode);
			fprintf_s(file,"%f ", rightUpLegRoll);
			fprintf_s(file,"%i ", rightLegRollMode);
			fprintf_s(file,"%f", rightLegRoll);
		}
	};
public:
	HikHandle(FILE* file,const std::string& name,const std::string& parent=""):IkHandle(file, name, parent, "hikHandle"){}
	virtual ~HikHandle(){}
	/*The associated hikEffectors for this handle.*/
	void setEffectors(size_t eff_i,const BoolID& eff){fprintf_s(mFile,"connectAttr \"");eff.write(mFile);fprintf_s(mFile,"\" \"%s.eff[%i]\";\n",mName.c_str(),eff_i);}
	/*
	The ground plane for the left foot floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use leftFootOrientedGroundPlane instead.
	*/
	void setLeftFootGroundPlane(const DoubleID& lfg){fprintf_s(mFile,"connectAttr \"");lfg.write(mFile);fprintf_s(mFile,"\" \"%s.lfg\";\n",mName.c_str());}
	/*
	The ground plane for the right foot floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use rightFootOrientedGroundPlane instead.
	*/
	void setRightFootGroundPlane(const DoubleID& rfg){fprintf_s(mFile,"connectAttr \"");rfg.write(mFile);fprintf_s(mFile,"\" \"%s.rfg\";\n",mName.c_str());}
	/*The oriented ground plane for the right foot floor contact.*/
	void setRightFootOrientedGroundPlane(const MatrixID& rog){fprintf_s(mFile,"connectAttr \"");rog.write(mFile);fprintf_s(mFile,"\" \"%s.rog\";\n",mName.c_str());}
	/*The oriented ground plane for the left foot floor contact.*/
	void setLeftFootOrientedGroundPlane(const MatrixID& log){fprintf_s(mFile,"connectAttr \"");log.write(mFile);fprintf_s(mFile,"\" \"%s.log\";\n",mName.c_str());}
	/*
	The ground plane for the left hand floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use leftHandOrientedGroundPlane instead.
	*/
	void setLeftHandGroundPlane(const DoubleID& lhg){fprintf_s(mFile,"connectAttr \"");lhg.write(mFile);fprintf_s(mFile,"\" \"%s.lhg\";\n",mName.c_str());}
	/*
	The ground plane for the right hand floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use rightHandOrientedGroundPlane instead.
	*/
	void setRightHandGroundPlane(const DoubleID& rhg){fprintf_s(mFile,"connectAttr \"");rhg.write(mFile);fprintf_s(mFile,"\" \"%s.rhg\";\n",mName.c_str());}
	/*The oriented ground plane for the left hand floor contact.*/
	void setLeftHandOrientedGroundPlane(const MatrixID& loh){fprintf_s(mFile,"connectAttr \"");loh.write(mFile);fprintf_s(mFile,"\" \"%s.loh\";\n",mName.c_str());}
	/*The oriented ground plane for the right hand floor contact.*/
	void setRightHandOrientedGroundPlane(const MatrixID& roh){fprintf_s(mFile,"connectAttr \"");roh.write(mFile);fprintf_s(mFile,"\" \"%s.roh\";\n",mName.c_str());}
	/*The joints controlled by this handle.*/
	void setJoints(size_t jt_i,const MessageID& jt){fprintf_s(mFile,"connectAttr \"");jt.write(mFile);fprintf_s(mFile,"\" \"%s.jt[%i]\";\n",mName.c_str(),jt_i);}
	/*the FK joints, which together with the effectors, drive the joints controlled by this handle*/
	void setFkjoints(size_t fj_i,const MessageID& fj){fprintf_s(mFile,"connectAttr \"");fj.write(mFile);fprintf_s(mFile,"\" \"%s.fj[%i]\";\n",mName.c_str(),fj_i);}
	/*The current time.*/
	void setTime(const TimeID& tim){fprintf_s(mFile,"connectAttr \"");tim.write(mFile);fprintf_s(mFile,"\" \"%s.tim\";\n",mName.c_str());}
	/*
	This attribute is used during file save and retrieve only.
	It stores the current default matrix for each joint at the time
	the file was saved. This matrix is used to initialize the humanIK
	solve after file open.
	*/
	void setDefaultMatrix(size_t dm_i,const matrix& dm){if(dm == identity) return; fprintf_s(mFile, "setAttr \".dm[%i]\" -type \"matrix\" ",dm_i);dm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute is used during file save and retrieve only.
	It stores the current default matrix for each joint at the time
	the file was saved. This matrix is used to initialize the humanIK
	solve after file open.
	*/
	void setDefaultMatrix(size_t dm_i,const MatrixID& dm){fprintf_s(mFile,"connectAttr \"");dm.write(mFile);fprintf_s(mFile,"\" \"%s.dm[%i]\";\n",mName.c_str(),dm_i);}
	/*
	This attribute stores the stance pose that will be needed to initialize
	human ik.
	*/
	void setStancePoseMatrix(size_t sm_i,const matrix& sm){if(sm == identity) return; fprintf_s(mFile, "setAttr \".sm[%i]\" -type \"matrix\" ",sm_i);sm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute stores the stance pose that will be needed to initialize
	human ik.
	*/
	void setStancePoseMatrix(size_t sm_i,const MatrixID& sm){fprintf_s(mFile,"connectAttr \"");sm.write(mFile);fprintf_s(mFile,"\" \"%s.sm[%i]\";\n",mName.c_str(),sm_i);}
	/*Indicates whether the FK skeleton is in Motion Builder 5.5 format.*/
	void setUsingMB55Rig(bool m55){if(m55 == false) return; fprintf_s(mFile, "setAttr \".m55\" %i;\n", m55);}
	/*Indicates whether the FK skeleton is in Motion Builder 5.5 format.*/
	void setUsingMB55Rig(const BoolID& m55){fprintf_s(mFile,"connectAttr \"");m55.write(mFile);fprintf_s(mFile,"\" \"%s.m55\";\n",mName.c_str());}
	/*Indicates whether the Full body system should be active or not.*/
	void setActivate(bool act){if(act == true) return; fprintf_s(mFile, "setAttr \".act\" %i;\n", act);}
	/*Indicates whether the Full body system should be active or not.*/
	void setActivate(const BoolID& act){fprintf_s(mFile,"connectAttr \"");act.write(mFile);fprintf_s(mFile,"\" \"%s.act\";\n",mName.c_str());}
	/*
	Indicates upon file open, whether to put the scale of all effectors to
	unity and scale up the radius by the same amount.  This attribute is put
	primarily for backward compatibility purposes, where in previous versions
	of Maya (pre 2008) the scale of effectors did not matter, but starting
	from Maya 2008, at least the scale of secondary pivots does matter.
	*/
	void setConvertScale(bool cs){if(cs == true) return; fprintf_s(mFile, "setAttr \".cs\" %i;\n", cs);}
	/*
	Indicates upon file open, whether to put the scale of all effectors to
	unity and scale up the radius by the same amount.  This attribute is put
	primarily for backward compatibility purposes, where in previous versions
	of Maya (pre 2008) the scale of effectors did not matter, but starting
	from Maya 2008, at least the scale of secondary pivots does matter.
	*/
	void setConvertScale(const BoolID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*Internal attribute used to optimize evaluation of properties for the solver.*/
	void setPropertyChanged(const MessageID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*Folder for Solving controls*/
	void setSolving(const Solving& sol){fprintf_s(mFile, "setAttr \".sol\" ");sol.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Solving controls*/
	void setSolving(const SolvingID& sol){fprintf_s(mFile,"connectAttr \"");sol.write(mFile);fprintf_s(mFile,"\" \"%s.sol\";\n",mName.c_str());}
	/*Switches your control rig between a biped or quadraped posture.*/
	void setPostureType(unsigned int pt){if(pt == 0) return; fprintf_s(mFile, "setAttr \".sol.pt\" %i;\n", pt);}
	/*Switches your control rig between a biped or quadraped posture.*/
	void setPostureType(const UnsignedintID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.sol.pt\";\n",mName.c_str());}
	/*
	When activated, the pull and stiffness options are available and
	contribute to the FBIK solution during playback.
	*/
	void setExpertMode(bool exp){if(exp == 0) return; fprintf_s(mFile, "setAttr \".sol.exp\" %i;\n", exp);}
	/*
	When activated, the pull and stiffness options are available and
	contribute to the FBIK solution during playback.
	*/
	void setExpertMode(const BoolID& exp){fprintf_s(mFile,"connectAttr \"");exp.write(mFile);fprintf_s(mFile,"\" \"%s.sol.exp\";\n",mName.c_str());}
	/*Shoulder correction for extreme rotation.*/
	void setRealisticShoulderSolving(float rss){if(rss == 0.00) return; fprintf_s(mFile, "setAttr \".sol.rss\" %f;\n", rss);}
	/*Shoulder correction for extreme rotation.*/
	void setRealisticShoulderSolving(const FloatID& rss){fprintf_s(mFile,"connectAttr \"");rss.write(mFile);fprintf_s(mFile,"\" \"%s.sol.rss\";\n",mName.c_str());}
	/*
	Controls whether IK solving is done for fingers. When disabled,
	performance will be improved.
	*/
	void setSolveFingers(bool sf){if(sf == 1) return; fprintf_s(mFile, "setAttr \".sol.sf\" %i;\n", sf);}
	/*
	Controls whether IK solving is done for fingers. When disabled,
	performance will be improved.
	*/
	void setSolveFingers(const BoolID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sol.sf\";\n",mName.c_str());}
	/*
	The hips translation mode setting lets you select whether rotation
	is applied to both (body rigid) the hips node and the hipsTranslation node,
	or only the hips node (world rigid). This is useful when you have defined
	a second joint for translating the hips of your model and you do not want
	the second node to receive rotation. To use this setting, you must define
	a hipsTranslation node when setting up your character.
	*/
	void setHipTranslationMode(unsigned int htm){if(htm == 0) return; fprintf_s(mFile, "setAttr \".sol.htm\" %i;\n", htm);}
	/*
	The hips translation mode setting lets you select whether rotation
	is applied to both (body rigid) the hips node and the hipsTranslation node,
	or only the hips node (world rigid). This is useful when you have defined
	a second joint for translating the hips of your model and you do not want
	the second node to receive rotation. To use this setting, you must define
	a hipsTranslation node when setting up your character.
	*/
	void setHipTranslationMode(const UnsignedintID& htm){fprintf_s(mFile,"connectAttr \"");htm.write(mFile);fprintf_s(mFile,"\" \"%s.sol.htm\";\n",mName.c_str());}
	/*Folder for Floor Contacts controls*/
	void setFloorContacts(const FloorContacts& fc){fprintf_s(mFile, "setAttr \".fc\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Floor Contacts controls*/
	void setFloorContacts(const FloorContactsID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*When enabled, prevents the hands from going through the floor.*/
	void setHandsFloorContact(bool hfc){if(hfc == 0) return; fprintf_s(mFile, "setAttr \".fc.hfc\" %i;\n", hfc);}
	/*When enabled, prevents the hands from going through the floor.*/
	void setHandsFloorContact(const BoolID& hfc){fprintf_s(mFile,"connectAttr \"");hfc.write(mFile);fprintf_s(mFile,"\" \"%s.fc.hfc\";\n",mName.c_str());}
	/*When enabled, prevents the feet from going through the floor.*/
	void setFeetFloorContact(bool fec){if(fec == 0) return; fprintf_s(mFile, "setAttr \".fc.fec\" %i;\n", fec);}
	/*When enabled, prevents the feet from going through the floor.*/
	void setFeetFloorContact(const BoolID& fec){fprintf_s(mFile,"connectAttr \"");fec.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fec\";\n",mName.c_str());}
	/*When enabled, prevents the fingers from going through the floor.*/
	void setFingersFloorContact(bool fic){if(fic == 0) return; fprintf_s(mFile, "setAttr \".fc.fic\" %i;\n", fic);}
	/*When enabled, prevents the fingers from going through the floor.*/
	void setFingersFloorContact(const BoolID& fic){fprintf_s(mFile,"connectAttr \"");fic.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fic\";\n",mName.c_str());}
	/*When enabled, prevents the toes from going through the floor.*/
	void setToesFloorContact(bool tfc){if(tfc == 0) return; fprintf_s(mFile, "setAttr \".fc.tfc\" %i;\n", tfc);}
	/*When enabled, prevents the toes from going through the floor.*/
	void setToesFloorContact(const BoolID& tfc){fprintf_s(mFile,"connectAttr \"");tfc.write(mFile);fprintf_s(mFile,"\" \"%s.fc.tfc\";\n",mName.c_str());}
	/*Folder for Hands Floor Contact Setup controls*/
	void setHandsFloorContactSetup(const HandsFloorContactSetup& flc){fprintf_s(mFile, "setAttr \".flc\" ");flc.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Hands Floor Contact Setup controls*/
	void setHandsFloorContactSetup(const HandsFloorContactSetupID& flc){fprintf_s(mFile,"connectAttr \"");flc.write(mFile);fprintf_s(mFile,"\" \"%s.flc\";\n",mName.c_str());}
	/*Define a stable point when applying floor contact.*/
	void setHandsFloorPivot(unsigned int hfp){if(hfp == 0) return; fprintf_s(mFile, "setAttr \".flc.hfp\" %i;\n", hfp);}
	/*Define a stable point when applying floor contact.*/
	void setHandsFloorPivot(const UnsignedintID& hfp){fprintf_s(mFile,"connectAttr \"");hfp.write(mFile);fprintf_s(mFile,"\" \"%s.flc.hfp\";\n",mName.c_str());}
	/*
	This attribute allows you to define the number and orientation of
	markers used to define the floor contact for the hands. In "normal" contact,
	six markers define each contact between the hand and the floor. The middle markers
	should define where the fingers begin. In "wrist" contact, four
	points define each contact. The hand markers are displayed around each palm.
	In "FingerBase" contact, four points define each contact. The hand floor
	contact markers display around each finger. In "hoof" contact, four
	points define each contact, but the points are oriented at a 90 degree angle,
	allowing you to define the floor contact for animal types with hooves, such
	as horses. These contact markers allow for 180 degrees of movement.
	*/
	void setHandsContactType(unsigned int hct){if(hct == 0) return; fprintf_s(mFile, "setAttr \".flc.hct\" %i;\n", hct);}
	/*
	This attribute allows you to define the number and orientation of
	markers used to define the floor contact for the hands. In "normal" contact,
	six markers define each contact between the hand and the floor. The middle markers
	should define where the fingers begin. In "wrist" contact, four
	points define each contact. The hand markers are displayed around each palm.
	In "FingerBase" contact, four points define each contact. The hand floor
	contact markers display around each finger. In "hoof" contact, four
	points define each contact, but the points are oriented at a 90 degree angle,
	allowing you to define the floor contact for animal types with hooves, such
	as horses. These contact markers allow for 180 degrees of movement.
	*/
	void setHandsContactType(const UnsignedintID& hct){fprintf_s(mFile,"connectAttr \"");hct.write(mFile);fprintf_s(mFile,"\" \"%s.flc.hct\";\n",mName.c_str());}
	/*
	Defines how stiff the hand becomes as soon as any part of the
	hand contacts the floor.
	At 100% (1.0) the wrist rotation will not change, this keeps the hand configuration while contacting.
	At 0% the wrist rotation will be adapted to minimize floor penetration.
	In both cases, wrist translation will do the final correction.
	*/
	void setHandsContactStiffness(float hcs){if(hcs == 0.00) return; fprintf_s(mFile, "setAttr \".flc.hcs\" %f;\n", hcs);}
	/*
	Defines how stiff the hand becomes as soon as any part of the
	hand contacts the floor.
	At 100% (1.0) the wrist rotation will not change, this keeps the hand configuration while contacting.
	At 0% the wrist rotation will be adapted to minimize floor penetration.
	In both cases, wrist translation will do the final correction.
	*/
	void setHandsContactStiffness(const FloatID& hcs){fprintf_s(mFile,"connectAttr \"");hcs.write(mFile);fprintf_s(mFile,"\" \"%s.flc.hcs\";\n",mName.c_str());}
	/*Folder for Contacts Position controls*/
	void setContactsPosition(const ContactsPosition& cp){fprintf_s(mFile, "setAttr \".cp\" ");cp.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Contacts Position controls*/
	void setContactsPosition(const ContactsPositionID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
	/*Defines the floor contact offset height for the hand*/
	void setHandHeight(float hh){if(hh == 7.50) return; fprintf_s(mFile, "setAttr \".cp.hh\" %f;\n", hh);}
	/*Defines the floor contact offset height for the hand*/
	void setHandHeight(const FloatID& hh){fprintf_s(mFile,"connectAttr \"");hh.write(mFile);fprintf_s(mFile,"\" \"%s.cp.hh\";\n",mName.c_str());}
	/*Defines the length of the back edge of the hand.*/
	void setHandBack(float hb){if(hb == 4.50) return; fprintf_s(mFile, "setAttr \".cp.hb\" %f;\n", hb);}
	/*Defines the length of the back edge of the hand.*/
	void setHandBack(const FloatID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.cp.hb\";\n",mName.c_str());}
	/*Defines the length to the middle of the hand, where the fingers bend.*/
	void setHandMiddle(float hm){if(hm == 13.00) return; fprintf_s(mFile, "setAttr \".cp.hm\" %f;\n", hm);}
	/*Defines the length to the middle of the hand, where the fingers bend.*/
	void setHandMiddle(const FloatID& hm){fprintf_s(mFile,"connectAttr \"");hm.write(mFile);fprintf_s(mFile,"\" \"%s.cp.hm\";\n",mName.c_str());}
	/*Defines the length of the frontmost part of the hand.*/
	void setHandFront(float hf){if(hf == 7.00) return; fprintf_s(mFile, "setAttr \".cp.hf\" %f;\n", hf);}
	/*Defines the length of the frontmost part of the hand.*/
	void setHandFront(const FloatID& hf){fprintf_s(mFile,"connectAttr \"");hf.write(mFile);fprintf_s(mFile,"\" \"%s.cp.hf\";\n",mName.c_str());}
	/*Defines the length of the interior of the hand.*/
	void setHandInSide(float his){if(his == 5.00) return; fprintf_s(mFile, "setAttr \".cp.his\" %f;\n", his);}
	/*Defines the length of the interior of the hand.*/
	void setHandInSide(const FloatID& his){fprintf_s(mFile,"connectAttr \"");his.write(mFile);fprintf_s(mFile,"\" \"%s.cp.his\";\n",mName.c_str());}
	/*Defines the length of the exterior of the hand.*/
	void setHandOutSide(float hos){if(hos == 5.00) return; fprintf_s(mFile, "setAttr \".cp.hos\" %f;\n", hos);}
	/*Defines the length of the exterior of the hand.*/
	void setHandOutSide(const FloatID& hos){fprintf_s(mFile,"connectAttr \"");hos.write(mFile);fprintf_s(mFile,"\" \"%s.cp.hos\";\n",mName.c_str());}
	/*Folder for Feet Floor Contact Setup controls*/
	void setFeetFloorContactSetup(const FeetFloorContactSetup& fle){fprintf_s(mFile, "setAttr \".fle\" ");fle.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Feet Floor Contact Setup controls*/
	void setFeetFloorContactSetup(const FeetFloorContactSetupID& fle){fprintf_s(mFile,"connectAttr \"");fle.write(mFile);fprintf_s(mFile,"\" \"%s.fle\";\n",mName.c_str());}
	/*
	Specify which part of the feet take priority when they make
	contact with the floor. A selection of "auto" will average
	priority between the ankle and toes so that when the
	foot makes conact with the floor the ankle is translated back
	and the toes are pushed forward. A selection of "ankle"
	will cause the toes to move forward to maintain the trajectory
	of the ankle. A selection of "toes" will cause the ankle to
	be translated backwards to keep the toes firmly planted.
	*/
	void setFeetFloorPivot(unsigned int fpv){if(fpv == 0) return; fprintf_s(mFile, "setAttr \".fle.fpv\" %i;\n", fpv);}
	/*
	Specify which part of the feet take priority when they make
	contact with the floor. A selection of "auto" will average
	priority between the ankle and toes so that when the
	foot makes conact with the floor the ankle is translated back
	and the toes are pushed forward. A selection of "ankle"
	will cause the toes to move forward to maintain the trajectory
	of the ankle. A selection of "toes" will cause the ankle to
	be translated backwards to keep the toes firmly planted.
	*/
	void setFeetFloorPivot(const UnsignedintID& fpv){fprintf_s(mFile,"connectAttr \"");fpv.write(mFile);fprintf_s(mFile,"\" \"%s.fle.fpv\";\n",mName.c_str());}
	/*
	This attribute allows you to define the number and orientation of
	markers used to define the floor contact for the foot. In "normal" contact,
	six markers define each contact between the foot and the floor. The middle markers
	should define where the toes begin. In "ankle" contact, four
	points define each contact and are placed around the base of the foot.
	In "toe base" contact, four points define each contact and are placed
	around the toes of each foot. In "hoof" contact, four
	points define each contact, but the points are oriented at a 90 degree angle,
	allowing you to define the floor contact for animal types with hooves, such
	as horses. These contact markers allow for 180 degrees of movement.
	*/
	void setFeetContactType(unsigned int fct){if(fct == 0) return; fprintf_s(mFile, "setAttr \".fle.fct\" %i;\n", fct);}
	/*
	This attribute allows you to define the number and orientation of
	markers used to define the floor contact for the foot. In "normal" contact,
	six markers define each contact between the foot and the floor. The middle markers
	should define where the toes begin. In "ankle" contact, four
	points define each contact and are placed around the base of the foot.
	In "toe base" contact, four points define each contact and are placed
	around the toes of each foot. In "hoof" contact, four
	points define each contact, but the points are oriented at a 90 degree angle,
	allowing you to define the floor contact for animal types with hooves, such
	as horses. These contact markers allow for 180 degrees of movement.
	*/
	void setFeetContactType(const UnsignedintID& fct){fprintf_s(mFile,"connectAttr \"");fct.write(mFile);fprintf_s(mFile,"\" \"%s.fle.fct\";\n",mName.c_str());}
	/*
	Defines how stiff the foot becomes as soon as any part of the
	foot contacts the floor.
	At 100% (1.0) the ankle rotation will not change, this keeps the foot configuration while contacting.
	At 0% the ankle rotation will be adapted to minimize floor penetration.
	In both cases, ankle translation will do the final correction.
	*/
	void setFeetContactStiffness(float fcs){if(fcs == 0.00) return; fprintf_s(mFile, "setAttr \".fle.fcs\" %f;\n", fcs);}
	/*
	Defines how stiff the foot becomes as soon as any part of the
	foot contacts the floor.
	At 100% (1.0) the ankle rotation will not change, this keeps the foot configuration while contacting.
	At 0% the ankle rotation will be adapted to minimize floor penetration.
	In both cases, ankle translation will do the final correction.
	*/
	void setFeetContactStiffness(const FloatID& fcs){fprintf_s(mFile,"connectAttr \"");fcs.write(mFile);fprintf_s(mFile,"\" \"%s.fle.fcs\";\n",mName.c_str());}
	/*Folder for feet contact position controls*/
	void setFeetContactPosition(const FeetContactPosition& flf){fprintf_s(mFile, "setAttr \".flf\" ");flf.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for feet contact position controls*/
	void setFeetContactPosition(const FeetContactPositionID& flf){fprintf_s(mFile,"connectAttr \"");flf.write(mFile);fprintf_s(mFile,"\" \"%s.flf\";\n",mName.c_str());}
	/*Defines the floor contact offset height for the foot*/
	void setFootHeight(float fh){if(fh == 7.50) return; fprintf_s(mFile, "setAttr \".flf.fh\" %f;\n", fh);}
	/*Defines the floor contact offset height for the foot*/
	void setFootHeight(const FloatID& fh){fprintf_s(mFile,"connectAttr \"");fh.write(mFile);fprintf_s(mFile,"\" \"%s.flf.fh\";\n",mName.c_str());}
	/*Defines the length of the back edge of the foot.*/
	void setFootBack(float fra){if(fra == 4.50) return; fprintf_s(mFile, "setAttr \".flf.fra\" %f;\n", fra);}
	/*Defines the length of the back edge of the foot.*/
	void setFootBack(const FloatID& fra){fprintf_s(mFile,"connectAttr \"");fra.write(mFile);fprintf_s(mFile,"\" \"%s.flf.fra\";\n",mName.c_str());}
	/*Defines the length of the middle (ball) of the foot.*/
	void setFootMiddle(float fma){if(fma == 13.00) return; fprintf_s(mFile, "setAttr \".flf.fma\" %f;\n", fma);}
	/*Defines the length of the middle (ball) of the foot.*/
	void setFootMiddle(const FloatID& fma){fprintf_s(mFile,"connectAttr \"");fma.write(mFile);fprintf_s(mFile,"\" \"%s.flf.fma\";\n",mName.c_str());}
	/*Defines the length of the frontmost section of the foot.*/
	void setFootFront(float ffm){if(ffm == 7.00) return; fprintf_s(mFile, "setAttr \".flf.ffm\" %f;\n", ffm);}
	/*Defines the length of the frontmost section of the foot.*/
	void setFootFront(const FloatID& ffm){fprintf_s(mFile,"connectAttr \"");ffm.write(mFile);fprintf_s(mFile,"\" \"%s.flf.ffm\";\n",mName.c_str());}
	/*Defines the length of the interior of the foot.*/
	void setFootInSide(float fia){if(fia == 5.00) return; fprintf_s(mFile, "setAttr \".flf.fia\" %f;\n", fia);}
	/*Defines the length of the interior of the foot.*/
	void setFootInSide(const FloatID& fia){fprintf_s(mFile,"connectAttr \"");fia.write(mFile);fprintf_s(mFile,"\" \"%s.flf.fia\";\n",mName.c_str());}
	/*Defines the length of the exterior of the foot.*/
	void setFootOutSide(float foa){if(foa == 5.00) return; fprintf_s(mFile, "setAttr \".flf.foa\" %f;\n", foa);}
	/*Defines the length of the exterior of the foot.*/
	void setFootOutSide(const FloatID& foa){fprintf_s(mFile,"connectAttr \"");foa.write(mFile);fprintf_s(mFile,"\" \"%s.flf.foa\";\n",mName.c_str());}
	/*Folder for Fingers Floor Contact Setup controls*/
	void setFingersFloorContactSetup(const FingersFloorContactSetup& flg){fprintf_s(mFile, "setAttr \".flg\" ");flg.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Fingers Floor Contact Setup controls*/
	void setFingersFloorContactSetup(const FingersFloorContactSetupID& flg){fprintf_s(mFile,"connectAttr \"");flg.write(mFile);fprintf_s(mFile,"\" \"%s.flg\";\n",mName.c_str());}
	/*
	Controls the behavior of the fingers as they make contact with the
	floor. You can select between three different behaviors: sticky, spread
	and stickySpread. "Sticky" causes each finger to stick to the floor exactly
	where contact is made. "Spread" spreads the fingers as they make contact
	with the floor, attempting to keep the position of the fingers intact.
	Rotation is applied to the root of each finger. "StickySpread" averages
	the finger behaviour between both Sticky and Spread.
	*/
	void setFingersContactType(unsigned int fcm){if(fcm == 1) return; fprintf_s(mFile, "setAttr \".flg.fcm\" %i;\n", fcm);}
	/*
	Controls the behavior of the fingers as they make contact with the
	floor. You can select between three different behaviors: sticky, spread
	and stickySpread. "Sticky" causes each finger to stick to the floor exactly
	where contact is made. "Spread" spreads the fingers as they make contact
	with the floor, attempting to keep the position of the fingers intact.
	Rotation is applied to the root of each finger. "StickySpread" averages
	the finger behaviour between both Sticky and Spread.
	*/
	void setFingersContactType(const UnsignedintID& fcm){fprintf_s(mFile,"connectAttr \"");fcm.write(mFile);fprintf_s(mFile,"\" \"%s.flg.fcm\";\n",mName.c_str());}
	/*Defines how the finger rotations will react to a floor contact.*/
	void setFingersContactRollStiffness(float hcr){if(hcr == 0.00) return; fprintf_s(mFile, "setAttr \".flg.hcr\" %f;\n", hcr);}
	/*Defines how the finger rotations will react to a floor contact.*/
	void setFingersContactRollStiffness(const FloatID& hcr){fprintf_s(mFile,"connectAttr \"");hcr.write(mFile);fprintf_s(mFile,"\" \"%s.flg.hcr\";\n",mName.c_str());}
	/*Folder for finger tips size controls*/
	void setFingerTipsSizes(const FingerTipsSizes& fts){fprintf_s(mFile, "setAttr \".fts\" ");fts.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for finger tips size controls*/
	void setFingerTipsSizes(const FingerTipsSizesID& fts){fprintf_s(mFile,"connectAttr \"");fts.write(mFile);fprintf_s(mFile,"\" \"%s.fts\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left thumb.*/
	void setLeftHandThumbTip(float ltt){if(ltt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.ltt\" %f;\n", ltt);}
	/*Adjusts the size of the floor marker used to outline the left thumb.*/
	void setLeftHandThumbTip(const FloatID& ltt){fprintf_s(mFile,"connectAttr \"");ltt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.ltt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left index finger.*/
	void setLeftHandIndexTip(float lit){if(lit == 0.50) return; fprintf_s(mFile, "setAttr \".fts.lit\" %f;\n", lit);}
	/*Adjusts the size of the floor marker used to outline the left index finger.*/
	void setLeftHandIndexTip(const FloatID& lit){fprintf_s(mFile,"connectAttr \"");lit.write(mFile);fprintf_s(mFile,"\" \"%s.fts.lit\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left middle finger.*/
	void setLeftHandMiddleTip(float lmt){if(lmt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.lmt\" %f;\n", lmt);}
	/*Adjusts the size of the floor marker used to outline the left middle finger.*/
	void setLeftHandMiddleTip(const FloatID& lmt){fprintf_s(mFile,"connectAttr \"");lmt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.lmt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left ring finger.*/
	void setLeftHandRingTip(float lrt){if(lrt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.lrt\" %f;\n", lrt);}
	/*Adjusts the size of the floor marker used to outline the left ring finger.*/
	void setLeftHandRingTip(const FloatID& lrt){fprintf_s(mFile,"connectAttr \"");lrt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.lrt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left pinky finger.*/
	void setLeftHandPinkyTip(float lpt){if(lpt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.lpt\" %f;\n", lpt);}
	/*Adjusts the size of the floor marker used to outline the left pinky finger.*/
	void setLeftHandPinkyTip(const FloatID& lpt){fprintf_s(mFile,"connectAttr \"");lpt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.lpt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left extra finger.*/
	void setLeftHandExtraFingerTip(float lxt){if(lxt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.lxt\" %f;\n", lxt);}
	/*Adjusts the size of the floor marker used to outline the left extra finger.*/
	void setLeftHandExtraFingerTip(const FloatID& lxt){fprintf_s(mFile,"connectAttr \"");lxt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.lxt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right thumb.*/
	void setRightHandThumbTip(float rtt){if(rtt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.rtt\" %f;\n", rtt);}
	/*Adjusts the size of the floor marker used to outline the right thumb.*/
	void setRightHandThumbTip(const FloatID& rtt){fprintf_s(mFile,"connectAttr \"");rtt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.rtt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right index finger.*/
	void setRightHandIndexTip(float rit){if(rit == 0.50) return; fprintf_s(mFile, "setAttr \".fts.rit\" %f;\n", rit);}
	/*Adjusts the size of the floor marker used to outline the right index finger.*/
	void setRightHandIndexTip(const FloatID& rit){fprintf_s(mFile,"connectAttr \"");rit.write(mFile);fprintf_s(mFile,"\" \"%s.fts.rit\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right middle finger.*/
	void setRightHandMiddleTip(float rmt){if(rmt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.rmt\" %f;\n", rmt);}
	/*Adjusts the size of the floor marker used to outline the right middle finger.*/
	void setRightHandMiddleTip(const FloatID& rmt){fprintf_s(mFile,"connectAttr \"");rmt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.rmt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right ring finger.*/
	void setRightHandRingTip(float rrt){if(rrt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.rrt\" %f;\n", rrt);}
	/*Adjusts the size of the floor marker used to outline the right ring finger.*/
	void setRightHandRingTip(const FloatID& rrt){fprintf_s(mFile,"connectAttr \"");rrt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.rrt\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right pinky finger.*/
	void setRightHandPinkyTip(float rpp){if(rpp == 0.50) return; fprintf_s(mFile, "setAttr \".fts.rpp\" %f;\n", rpp);}
	/*Adjusts the size of the floor marker used to outline the right pinky finger.*/
	void setRightHandPinkyTip(const FloatID& rpp){fprintf_s(mFile,"connectAttr \"");rpp.write(mFile);fprintf_s(mFile,"\" \"%s.fts.rpp\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right extra finger.*/
	void setRightHandExtraFingerTip(float rxt){if(rxt == 0.50) return; fprintf_s(mFile, "setAttr \".fts.rxt\" %f;\n", rxt);}
	/*Adjusts the size of the floor marker used to outline the right extra finger.*/
	void setRightHandExtraFingerTip(const FloatID& rxt){fprintf_s(mFile,"connectAttr \"");rxt.write(mFile);fprintf_s(mFile,"\" \"%s.fts.rxt\";\n",mName.c_str());}
	/*Folder for Toes Floor Contact Setup controls*/
	void setToesFloorContactSetup(const ToesFloorContactSetup& fli){fprintf_s(mFile, "setAttr \".fli\" ");fli.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Toes Floor Contact Setup controls*/
	void setToesFloorContactSetup(const ToesFloorContactSetupID& fli){fprintf_s(mFile,"connectAttr \"");fli.write(mFile);fprintf_s(mFile,"\" \"%s.fli\";\n",mName.c_str());}
	/*
	Controls the behavior of the toes as they make contact with the
	floor. You can select between three different behaviors: sticky, spread
	and stickySpread. "Sticky" causes each toe to stick to the floor exactly
	where contact is made. "Spread" spreads the toes as they make contact
	with the floor, attempting to keep the position of the toes intact.
	Rotation is applied to the root of each toe. "StickySpread" averages
	the toe behaviour between both Sticky and Spread.
	*/
	void setToesContactType(unsigned int tct){if(tct == 1) return; fprintf_s(mFile, "setAttr \".fli.tct\" %i;\n", tct);}
	/*
	Controls the behavior of the toes as they make contact with the
	floor. You can select between three different behaviors: sticky, spread
	and stickySpread. "Sticky" causes each toe to stick to the floor exactly
	where contact is made. "Spread" spreads the toes as they make contact
	with the floor, attempting to keep the position of the toes intact.
	Rotation is applied to the root of each toe. "StickySpread" averages
	the toe behaviour between both Sticky and Spread.
	*/
	void setToesContactType(const UnsignedintID& tct){fprintf_s(mFile,"connectAttr \"");tct.write(mFile);fprintf_s(mFile,"\" \"%s.fli.tct\";\n",mName.c_str());}
	/*Defines how the toe rotations will react to a floor contact.*/
	void setToesContactRollStiffness(float fcr){if(fcr == 0.00) return; fprintf_s(mFile, "setAttr \".fli.fcr\" %f;\n", fcr);}
	/*Defines how the toe rotations will react to a floor contact.*/
	void setToesContactRollStiffness(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fli.fcr\";\n",mName.c_str());}
	/*Folder for Toe Tips Sizes controls*/
	void setToeTipsSizes(const ToeTipsSizes& flj){fprintf_s(mFile, "setAttr \".flj\" ");flj.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Toe Tips Sizes controls*/
	void setToeTipsSizes(const ToeTipsSizesID& flj){fprintf_s(mFile,"connectAttr \"");flj.write(mFile);fprintf_s(mFile,"\" \"%s.flj\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left big toe.*/
	void setLeftFootThumbTip(float ttl){if(ttl == 0.50) return; fprintf_s(mFile, "setAttr \".flj.ttl\" %f;\n", ttl);}
	/*Adjusts the size of the floor marker used to outline the left big toe.*/
	void setLeftFootThumbTip(const FloatID& ttl){fprintf_s(mFile,"connectAttr \"");ttl.write(mFile);fprintf_s(mFile,"\" \"%s.flj.ttl\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left index toe.*/
	void setLeftFootIndexTip(float til){if(til == 0.50) return; fprintf_s(mFile, "setAttr \".flj.til\" %f;\n", til);}
	/*Adjusts the size of the floor marker used to outline the left index toe.*/
	void setLeftFootIndexTip(const FloatID& til){fprintf_s(mFile,"connectAttr \"");til.write(mFile);fprintf_s(mFile,"\" \"%s.flj.til\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left middle toe.*/
	void setLeftFootMiddleTip(float tml){if(tml == 0.50) return; fprintf_s(mFile, "setAttr \".flj.tml\" %f;\n", tml);}
	/*Adjusts the size of the floor marker used to outline the left middle toe.*/
	void setLeftFootMiddleTip(const FloatID& tml){fprintf_s(mFile,"connectAttr \"");tml.write(mFile);fprintf_s(mFile,"\" \"%s.flj.tml\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left ring toe.*/
	void setLeftFootRingTip(float trl){if(trl == 0.50) return; fprintf_s(mFile, "setAttr \".flj.trl\" %f;\n", trl);}
	/*Adjusts the size of the floor marker used to outline the left ring toe.*/
	void setLeftFootRingTip(const FloatID& trl){fprintf_s(mFile,"connectAttr \"");trl.write(mFile);fprintf_s(mFile,"\" \"%s.flj.trl\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left pinky toe.*/
	void setLeftFootPinkyTip(float tpl){if(tpl == 0.50) return; fprintf_s(mFile, "setAttr \".flj.tpl\" %f;\n", tpl);}
	/*Adjusts the size of the floor marker used to outline the left pinky toe.*/
	void setLeftFootPinkyTip(const FloatID& tpl){fprintf_s(mFile,"connectAttr \"");tpl.write(mFile);fprintf_s(mFile,"\" \"%s.flj.tpl\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the left extra toe.*/
	void setLeftFootExtraFingerTip(float txl){if(txl == 0.50) return; fprintf_s(mFile, "setAttr \".flj.txl\" %f;\n", txl);}
	/*Adjusts the size of the floor marker used to outline the left extra toe.*/
	void setLeftFootExtraFingerTip(const FloatID& txl){fprintf_s(mFile,"connectAttr \"");txl.write(mFile);fprintf_s(mFile,"\" \"%s.flj.txl\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right big toe.*/
	void setRightFootThumbTip(float ttr){if(ttr == 0.50) return; fprintf_s(mFile, "setAttr \".flj.ttr\" %f;\n", ttr);}
	/*Adjusts the size of the floor marker used to outline the right big toe.*/
	void setRightFootThumbTip(const FloatID& ttr){fprintf_s(mFile,"connectAttr \"");ttr.write(mFile);fprintf_s(mFile,"\" \"%s.flj.ttr\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right index toe.*/
	void setRightFootIndexTip(float tir){if(tir == 0.50) return; fprintf_s(mFile, "setAttr \".flj.tir\" %f;\n", tir);}
	/*Adjusts the size of the floor marker used to outline the right index toe.*/
	void setRightFootIndexTip(const FloatID& tir){fprintf_s(mFile,"connectAttr \"");tir.write(mFile);fprintf_s(mFile,"\" \"%s.flj.tir\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right middle toe.*/
	void setRightFootMiddleTip(float tmr){if(tmr == 0.50) return; fprintf_s(mFile, "setAttr \".flj.tmr\" %f;\n", tmr);}
	/*Adjusts the size of the floor marker used to outline the right middle toe.*/
	void setRightFootMiddleTip(const FloatID& tmr){fprintf_s(mFile,"connectAttr \"");tmr.write(mFile);fprintf_s(mFile,"\" \"%s.flj.tmr\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right ring toe.*/
	void setRightFootRingTip(float trr){if(trr == 0.50) return; fprintf_s(mFile, "setAttr \".flj.trr\" %f;\n", trr);}
	/*Adjusts the size of the floor marker used to outline the right ring toe.*/
	void setRightFootRingTip(const FloatID& trr){fprintf_s(mFile,"connectAttr \"");trr.write(mFile);fprintf_s(mFile,"\" \"%s.flj.trr\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right pinky toe.*/
	void setRightFootPinkyTip(float tpr){if(tpr == 0.50) return; fprintf_s(mFile, "setAttr \".flj.tpr\" %f;\n", tpr);}
	/*Adjusts the size of the floor marker used to outline the right pinky toe.*/
	void setRightFootPinkyTip(const FloatID& tpr){fprintf_s(mFile,"connectAttr \"");tpr.write(mFile);fprintf_s(mFile,"\" \"%s.flj.tpr\";\n",mName.c_str());}
	/*Adjusts the size of the floor marker used to outline the right extra toe.*/
	void setRightFootExtraFingerTip(float txr){if(txr == 0.50) return; fprintf_s(mFile, "setAttr \".flj.txr\" %f;\n", txr);}
	/*Adjusts the size of the floor marker used to outline the right extra toe.*/
	void setRightFootExtraFingerTip(const FloatID& txr){fprintf_s(mFile,"connectAttr \"");txr.write(mFile);fprintf_s(mFile,"\" \"%s.flj.txr\";\n",mName.c_str());}
	/*Folder for Head controls*/
	void setHead(const Head& fll){fprintf_s(mFile, "setAttr \".fll\" ");fll.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Head controls*/
	void setHead(const HeadID& fll){fprintf_s(mFile,"connectAttr \"");fll.write(mFile);fprintf_s(mFile,"\" \"%s.fll\";\n",mName.c_str());}
	/*The extent to which the head is attracted to its effector during IK playback.*/
	void setHeadPull(float phd){if(phd == 0.00) return; fprintf_s(mFile, "setAttr \".fll.phd\" %f;\n", phd);}
	/*The extent to which the head is attracted to its effector during IK playback.*/
	void setHeadPull(const FloatID& phd){fprintf_s(mFile,"connectAttr \"");phd.write(mFile);fprintf_s(mFile,"\" \"%s.fll.phd\";\n",mName.c_str());}
	/*Folder for Left Arm controls*/
	void setLeftArm(const LeftArm& flm){fprintf_s(mFile, "setAttr \".flm\" ");flm.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Left Arm controls*/
	void setLeftArm(const LeftArmID& flm){fprintf_s(mFile,"connectAttr \"");flm.write(mFile);fprintf_s(mFile,"\" \"%s.flm\";\n",mName.c_str());}
	/*The extent to which the left elbow is attracted to its effector during IK playback.*/
	void setLeftElbowPull(float ple){if(ple == 0.00) return; fprintf_s(mFile, "setAttr \".flm.ple\" %f;\n", ple);}
	/*The extent to which the left elbow is attracted to its effector during IK playback.*/
	void setLeftElbowPull(const FloatID& ple){fprintf_s(mFile,"connectAttr \"");ple.write(mFile);fprintf_s(mFile,"\" \"%s.flm.ple\";\n",mName.c_str());}
	/*The extent to which the left hand affects the chest during IK playback.*/
	void setLeftHandPullChest(float cpl){if(cpl == 1.00) return; fprintf_s(mFile, "setAttr \".flm.cpl\" %f;\n", cpl);}
	/*The extent to which the left hand affects the chest during IK playback.*/
	void setLeftHandPullChest(const FloatID& cpl){fprintf_s(mFile,"connectAttr \"");cpl.write(mFile);fprintf_s(mFile,"\" \"%s.flm.cpl\";\n",mName.c_str());}
	/*The extent to which the left hand affects the hips during IK playback.*/
	void setLeftHandPullHips(float plh){if(plh == 1.00) return; fprintf_s(mFile, "setAttr \".flm.plh\" %f;\n", plh);}
	/*The extent to which the left hand affects the hips during IK playback.*/
	void setLeftHandPullHips(const FloatID& plh){fprintf_s(mFile,"connectAttr \"");plh.write(mFile);fprintf_s(mFile,"\" \"%s.flm.plh\";\n",mName.c_str());}
	/*The extent to which the left finger base is attracted to its effector during IK playback.*/
	void setLeftFingerBasePull(float plb){if(plb == 0.00) return; fprintf_s(mFile, "setAttr \".flm.plb\" %f;\n", plb);}
	/*The extent to which the left finger base is attracted to its effector during IK playback.*/
	void setLeftFingerBasePull(const FloatID& plb){fprintf_s(mFile,"connectAttr \"");plb.write(mFile);fprintf_s(mFile,"\" \"%s.flm.plb\";\n",mName.c_str());}
	/*Folder for Right Arm controls*/
	void setRightArm(const RightArm& fln){fprintf_s(mFile, "setAttr \".fln\" ");fln.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Right Arm controls*/
	void setRightArm(const RightArmID& fln){fprintf_s(mFile,"connectAttr \"");fln.write(mFile);fprintf_s(mFile,"\" \"%s.fln\";\n",mName.c_str());}
	/*The extent to which the right elbow is attracted to its effector during IK playback.*/
	void setRightElbowPull(float pre){if(pre == 0.00) return; fprintf_s(mFile, "setAttr \".fln.pre\" %f;\n", pre);}
	/*The extent to which the right elbow is attracted to its effector during IK playback.*/
	void setRightElbowPull(const FloatID& pre){fprintf_s(mFile,"connectAttr \"");pre.write(mFile);fprintf_s(mFile,"\" \"%s.fln.pre\";\n",mName.c_str());}
	/*The extent to which the right hand affects the chest during IK playback.*/
	void setRightHandPullChest(float cpr){if(cpr == 1.00) return; fprintf_s(mFile, "setAttr \".fln.cpr\" %f;\n", cpr);}
	/*The extent to which the right hand affects the chest during IK playback.*/
	void setRightHandPullChest(const FloatID& cpr){fprintf_s(mFile,"connectAttr \"");cpr.write(mFile);fprintf_s(mFile,"\" \"%s.fln.cpr\";\n",mName.c_str());}
	/*The extent to which the right hand affects the hips during IK playback.*/
	void setRightHandPullHips(float prh){if(prh == 1.00) return; fprintf_s(mFile, "setAttr \".fln.prh\" %f;\n", prh);}
	/*The extent to which the right hand affects the hips during IK playback.*/
	void setRightHandPullHips(const FloatID& prh){fprintf_s(mFile,"connectAttr \"");prh.write(mFile);fprintf_s(mFile,"\" \"%s.fln.prh\";\n",mName.c_str());}
	/*The extent to which the right finger base is attracted to its effector during IK playback.*/
	void setRightFingerBasePull(float prb){if(prb == 0.00) return; fprintf_s(mFile, "setAttr \".fln.prb\" %f;\n", prb);}
	/*The extent to which the right finger base is attracted to its effector during IK playback.*/
	void setRightFingerBasePull(const FloatID& prb){fprintf_s(mFile,"connectAttr \"");prb.write(mFile);fprintf_s(mFile,"\" \"%s.fln.prb\";\n",mName.c_str());}
	/*Folder for Chest controls*/
	void setChest(const Chest& flo){fprintf_s(mFile, "setAttr \".flo\" ");flo.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Chest controls*/
	void setChest(const ChestID& flo){fprintf_s(mFile,"connectAttr \"");flo.write(mFile);fprintf_s(mFile,"\" \"%s.flo\";\n",mName.c_str());}
	/*The degree to which the solver tries to preserve the initial FK angle of the chest.*/
	void setChestPull(float rcp){if(rcp == 0.00) return; fprintf_s(mFile, "setAttr \".flo.rcp\" %f;\n", rcp);}
	/*The degree to which the solver tries to preserve the initial FK angle of the chest.*/
	void setChestPull(const FloatID& rcp){fprintf_s(mFile,"connectAttr \"");rcp.write(mFile);fprintf_s(mFile,"\" \"%s.flo.rcp\";\n",mName.c_str());}
	/*Folder for Hips controls*/
	void setHips(const Hips& flp){fprintf_s(mFile, "setAttr \".flp\" ");flp.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Hips controls*/
	void setHips(const HipsID& flp){fprintf_s(mFile,"connectAttr \"");flp.write(mFile);fprintf_s(mFile,"\" \"%s.flp\";\n",mName.c_str());}
	/*The degree to which the solver tries to preserve the initial FK angle of the hips.*/
	void setHipsPull(float chp){if(chp == 0.00) return; fprintf_s(mFile, "setAttr \".flp.chp\" %f;\n", chp);}
	/*The degree to which the solver tries to preserve the initial FK angle of the hips.*/
	void setHipsPull(const FloatID& chp){fprintf_s(mFile,"connectAttr \"");chp.write(mFile);fprintf_s(mFile,"\" \"%s.flp.chp\";\n",mName.c_str());}
	/*Folder for Left Leg controls*/
	void setLeftLeg(const LeftLeg& flq){fprintf_s(mFile, "setAttr \".flq\" ");flq.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Left Leg controls*/
	void setLeftLeg(const LeftLegID& flq){fprintf_s(mFile,"connectAttr \"");flq.write(mFile);fprintf_s(mFile,"\" \"%s.flq\";\n",mName.c_str());}
	/*The extent to which the left knee is attracted to its effector during IK playback.*/
	void setLeftKneePull(float plk){if(plk == 0.00) return; fprintf_s(mFile, "setAttr \".flq.plk\" %f;\n", plk);}
	/*The extent to which the left knee is attracted to its effector during IK playback.*/
	void setLeftKneePull(const FloatID& plk){fprintf_s(mFile,"connectAttr \"");plk.write(mFile);fprintf_s(mFile,"\" \"%s.flq.plk\";\n",mName.c_str());}
	/*The extent to which the left foot is attracted to its effector during IK playback.*/
	void setLeftFootPull(float plf){if(plf == 1.00) return; fprintf_s(mFile, "setAttr \".flq.plf\" %f;\n", plf);}
	/*The extent to which the left foot is attracted to its effector during IK playback.*/
	void setLeftFootPull(const FloatID& plf){fprintf_s(mFile,"connectAttr \"");plf.write(mFile);fprintf_s(mFile,"\" \"%s.flq.plf\";\n",mName.c_str());}
	/*The extent to which the left toe base is attracted to its effector during IK playback.*/
	void setLeftToeBasePull(float plt){if(plt == 0.00) return; fprintf_s(mFile, "setAttr \".flq.plt\" %f;\n", plt);}
	/*The extent to which the left toe base is attracted to its effector during IK playback.*/
	void setLeftToeBasePull(const FloatID& plt){fprintf_s(mFile,"connectAttr \"");plt.write(mFile);fprintf_s(mFile,"\" \"%s.flq.plt\";\n",mName.c_str());}
	/*Folder for Right Leg controls*/
	void setRightLeg(const RightLeg& flr){fprintf_s(mFile, "setAttr \".flr\" ");flr.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Right Leg controls*/
	void setRightLeg(const RightLegID& flr){fprintf_s(mFile,"connectAttr \"");flr.write(mFile);fprintf_s(mFile,"\" \"%s.flr\";\n",mName.c_str());}
	/*The extent to which the right knee is attracted to its effector during IK playback.*/
	void setRightKneePull(float prk){if(prk == 0.00) return; fprintf_s(mFile, "setAttr \".flr.prk\" %f;\n", prk);}
	/*The extent to which the right knee is attracted to its effector during IK playback.*/
	void setRightKneePull(const FloatID& prk){fprintf_s(mFile,"connectAttr \"");prk.write(mFile);fprintf_s(mFile,"\" \"%s.flr.prk\";\n",mName.c_str());}
	/*The extent to which the right foot is attracted to its effector during IK playback.*/
	void setRightFootPull(float prf){if(prf == 1.00) return; fprintf_s(mFile, "setAttr \".flr.prf\" %f;\n", prf);}
	/*The extent to which the right foot is attracted to its effector during IK playback.*/
	void setRightFootPull(const FloatID& prf){fprintf_s(mFile,"connectAttr \"");prf.write(mFile);fprintf_s(mFile,"\" \"%s.flr.prf\";\n",mName.c_str());}
	/*The extent to which the right toe base is attracted to its effector during IK playback.*/
	void setRightToeBasePull(float prt){if(prt == 0.00) return; fprintf_s(mFile, "setAttr \".flr.prt\" %f;\n", prt);}
	/*The extent to which the right toe base is attracted to its effector during IK playback.*/
	void setRightToeBasePull(const FloatID& prt){fprintf_s(mFile,"connectAttr \"");prt.write(mFile);fprintf_s(mFile,"\" \"%s.flr.prt\";\n",mName.c_str());}
	/*Folder for Extra controls*/
	void setExtra(const Extra& ex){fprintf_s(mFile, "setAttr \".ex\" ");ex.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Extra controls*/
	void setExtra(const ExtraID& ex){fprintf_s(mFile,"connectAttr \"");ex.write(mFile);fprintf_s(mFile,"\" \"%s.ex\";\n",mName.c_str());}
	/*
	Controls the number of times pull is calculated. The greater the
	number of iterations, the more accurate the pull calculation. However,
	a higher number of iterations may decrease system performance.
	*/
	void setPullIterationCount(float pic){if(pic == 10.00) return; fprintf_s(mFile, "setAttr \".ex.pic\" %f;\n", pic);}
	/*
	Controls the number of times pull is calculated. The greater the
	number of iterations, the more accurate the pull calculation. However,
	a higher number of iterations may decrease system performance.
	*/
	void setPullIterationCount(const FloatID& pic){fprintf_s(mFile,"connectAttr \"");pic.write(mFile);fprintf_s(mFile,"\" \"%s.ex.pic\";\n",mName.c_str());}
	/*Folder for Stiffness controls*/
	void setStiffness(const Stiffness& st){fprintf_s(mFile, "setAttr \".st\" ");st.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Stiffness controls*/
	void setStiffness(const StiffnessID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the neck.*/
	void setNeckStiffness(float nst){if(nst == 0.00) return; fprintf_s(mFile, "setAttr \".st.nst\" %f;\n", nst);}
	/*Degree to which the solver tries to preserve the initial FK angle on the neck.*/
	void setNeckStiffness(const FloatID& nst){fprintf_s(mFile,"connectAttr \"");nst.write(mFile);fprintf_s(mFile,"\" \"%s.st.nst\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the left collar.*/
	void setLeftShoulderStiffness(float rlco){if(rlco == 0.50) return; fprintf_s(mFile, "setAttr \".st.rlco\" %f;\n", rlco);}
	/*Degree to which the solver tries to preserve the initial FK angle on the left collar.*/
	void setLeftShoulderStiffness(const FloatID& rlco){fprintf_s(mFile,"connectAttr \"");rlco.write(mFile);fprintf_s(mFile,"\" \"%s.st.rlco\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the left elbow.*/
	void setLeftArmStiffness(float rle){if(rle == 0.50) return; fprintf_s(mFile, "setAttr \".st.rle\" %f;\n", rle);}
	/*Degree to which the solver tries to preserve the initial FK angle on the left elbow.*/
	void setLeftArmStiffness(const FloatID& rle){fprintf_s(mFile,"connectAttr \"");rle.write(mFile);fprintf_s(mFile,"\" \"%s.st.rle\";\n",mName.c_str());}
	/*
	Dampens the left arm as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setLeftElbowMaxExtension(float mle){if(mle == 0.50) return; fprintf_s(mFile, "setAttr \".st.mle\" %f;\n", mle);}
	/*
	Dampens the left arm as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setLeftElbowMaxExtension(const FloatID& mle){fprintf_s(mFile,"connectAttr \"");mle.write(mFile);fprintf_s(mFile,"\" \"%s.st.mle\";\n",mName.c_str());}
	/*
	Changes the stiffness of an extended left arm as it
	contracts or closes. At 100% (1.0) the extended left arm
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setLeftElbowCompressionFactor(float cle){if(cle == 0.50) return; fprintf_s(mFile, "setAttr \".st.cle\" %f;\n", cle);}
	/*
	Changes the stiffness of an extended left arm as it
	contracts or closes. At 100% (1.0) the extended left arm
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setLeftElbowCompressionFactor(const FloatID& cle){fprintf_s(mFile,"connectAttr \"");cle.write(mFile);fprintf_s(mFile,"\" \"%s.st.cle\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the right collar.*/
	void setRightShoulderStiffness(float rrc){if(rrc == 0.50) return; fprintf_s(mFile, "setAttr \".st.rrc\" %f;\n", rrc);}
	/*Degree to which the solver tries to preserve the initial FK angle on the right collar.*/
	void setRightShoulderStiffness(const FloatID& rrc){fprintf_s(mFile,"connectAttr \"");rrc.write(mFile);fprintf_s(mFile,"\" \"%s.st.rrc\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the right elbow.*/
	void setRightArmStiffness(float rre){if(rre == 0.50) return; fprintf_s(mFile, "setAttr \".st.rre\" %f;\n", rre);}
	/*Degree to which the solver tries to preserve the initial FK angle on the right elbow.*/
	void setRightArmStiffness(const FloatID& rre){fprintf_s(mFile,"connectAttr \"");rre.write(mFile);fprintf_s(mFile,"\" \"%s.st.rre\";\n",mName.c_str());}
	/*
	Dampens the right arm as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setRightElbowMaxExtension(float mre){if(mre == 0.50) return; fprintf_s(mFile, "setAttr \".st.mre\" %f;\n", mre);}
	/*
	Dampens the right arm as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setRightElbowMaxExtension(const FloatID& mre){fprintf_s(mFile,"connectAttr \"");mre.write(mFile);fprintf_s(mFile,"\" \"%s.st.mre\";\n",mName.c_str());}
	/*
	Changes the stiffness of an extended right arm as it
	contracts or closes. At 100% (1.0) the extended right arm
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setRightElbowCompressionFactor(float cre){if(cre == 0.50) return; fprintf_s(mFile, "setAttr \".st.cre\" %f;\n", cre);}
	/*
	Changes the stiffness of an extended right arm as it
	contracts or closes. At 100% (1.0) the extended right arm
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setRightElbowCompressionFactor(const FloatID& cre){fprintf_s(mFile,"connectAttr \"");cre.write(mFile);fprintf_s(mFile,"\" \"%s.st.cre\";\n",mName.c_str());}
	/*
	Forces the character's hips to be between its feet.
	The hipsStiffness must be set to a non-zero value to take
	advantage of hipsEnforceGravity.
	*/
	void setHipsEnforceGravity(float egr){if(egr == 0.60) return; fprintf_s(mFile, "setAttr \".st.egr\" %f;\n", egr);}
	/*
	Forces the character's hips to be between its feet.
	The hipsStiffness must be set to a non-zero value to take
	advantage of hipsEnforceGravity.
	*/
	void setHipsEnforceGravity(const FloatID& egr){fprintf_s(mFile,"connectAttr \"");egr.write(mFile);fprintf_s(mFile,"\" \"%s.st.egr\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the chest.*/
	void setChestStiffness(float rco){if(rco == 0.00) return; fprintf_s(mFile, "setAttr \".st.rco\" %f;\n", rco);}
	/*Degree to which the solver tries to preserve the initial FK angle on the chest.*/
	void setChestStiffness(const FloatID& rco){fprintf_s(mFile,"connectAttr \"");rco.write(mFile);fprintf_s(mFile,"\" \"%s.st.rco\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the spine.*/
	void setSpineStiffness(float sst){if(sst == 0.00) return; fprintf_s(mFile, "setAttr \".st.sst\" %f;\n", sst);}
	/*Degree to which the solver tries to preserve the initial FK angle on the spine.*/
	void setSpineStiffness(const FloatID& sst){fprintf_s(mFile,"connectAttr \"");sst.write(mFile);fprintf_s(mFile,"\" \"%s.st.sst\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the hips.*/
	void setHipsStiffness(float rho){if(rho == 0.00) return; fprintf_s(mFile, "setAttr \".st.rho\" %f;\n", rho);}
	/*Degree to which the solver tries to preserve the initial FK angle on the hips.*/
	void setHipsStiffness(const FloatID& rho){fprintf_s(mFile,"connectAttr \"");rho.write(mFile);fprintf_s(mFile,"\" \"%s.st.rho\";\n",mName.c_str());}
	/*
	Dampens the left leg as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setLeftKneeMaxExtension(float mlk){if(mlk == 0.50) return; fprintf_s(mFile, "setAttr \".st.mlk\" %f;\n", mlk);}
	/*
	Dampens the left leg as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setLeftKneeMaxExtension(const FloatID& mlk){fprintf_s(mFile,"connectAttr \"");mlk.write(mFile);fprintf_s(mFile,"\" \"%s.st.mlk\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the left knee.*/
	void setLeftLegStiffness(float rlk){if(rlk == 0.50) return; fprintf_s(mFile, "setAttr \".st.rlk\" %f;\n", rlk);}
	/*Degree to which the solver tries to preserve the initial FK angle on the left knee.*/
	void setLeftLegStiffness(const FloatID& rlk){fprintf_s(mFile,"connectAttr \"");rlk.write(mFile);fprintf_s(mFile,"\" \"%s.st.rlk\";\n",mName.c_str());}
	/*
	Changes the stiffness of an extended left leg as it
	contracts or closes. At 100% (1.0) the extended left leg
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setLeftKneeCompressionFactor(float clk){if(clk == 0.50) return; fprintf_s(mFile, "setAttr \".st.clk\" %f;\n", clk);}
	/*
	Changes the stiffness of an extended left leg as it
	contracts or closes. At 100% (1.0) the extended left leg
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setLeftKneeCompressionFactor(const FloatID& clk){fprintf_s(mFile,"connectAttr \"");clk.write(mFile);fprintf_s(mFile,"\" \"%s.st.clk\";\n",mName.c_str());}
	/*Degree to which the solver tries to preserve the initial FK angle on the right knee.*/
	void setRightLegStiffness(float rrk){if(rrk == 0.50) return; fprintf_s(mFile, "setAttr \".st.rrk\" %f;\n", rrk);}
	/*Degree to which the solver tries to preserve the initial FK angle on the right knee.*/
	void setRightLegStiffness(const FloatID& rrk){fprintf_s(mFile,"connectAttr \"");rrk.write(mFile);fprintf_s(mFile,"\" \"%s.st.rrk\";\n",mName.c_str());}
	/*
	Dampens the right leg as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setRightKneeMaxExtension(float mrk){if(mrk == 0.50) return; fprintf_s(mFile, "setAttr \".st.mrk\" %f;\n", mrk);}
	/*
	Dampens the right leg as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	void setRightKneeMaxExtension(const FloatID& mrk){fprintf_s(mFile,"connectAttr \"");mrk.write(mFile);fprintf_s(mFile,"\" \"%s.st.mrk\";\n",mName.c_str());}
	/*
	Changes the stiffness of an extended right leg as it
	contracts or closes. At 100% (1.0) the extended right leg
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setRightKneeCompressionFactor(float crk){if(crk == 0.50) return; fprintf_s(mFile, "setAttr \".st.crk\" %f;\n", crk);}
	/*
	Changes the stiffness of an extended right leg as it
	contracts or closes. At 100% (1.0) the extended right leg
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	void setRightKneeCompressionFactor(const FloatID& crk){fprintf_s(mFile,"connectAttr \"");crk.write(mFile);fprintf_s(mFile,"\" \"%s.st.crk\";\n",mName.c_str());}
	/*Folder for kill pitch controls*/
	void setKillPitch(const KillPitch& kp){fprintf_s(mFile, "setAttr \".kp\" ");kp.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for kill pitch controls*/
	void setKillPitch(const KillPitchID& kp){fprintf_s(mFile,"connectAttr \"");kp.write(mFile);fprintf_s(mFile,"\" \"%s.kp\";\n",mName.c_str());}
	/*When enabled, removes the pitch axis on the left elbow.*/
	void setLeftElbowKillPitch(bool lek){if(lek == 0) return; fprintf_s(mFile, "setAttr \".kp.lek\" %i;\n", lek);}
	/*When enabled, removes the pitch axis on the left elbow.*/
	void setLeftElbowKillPitch(const BoolID& lek){fprintf_s(mFile,"connectAttr \"");lek.write(mFile);fprintf_s(mFile,"\" \"%s.kp.lek\";\n",mName.c_str());}
	/*When enabled, removes the pitch axis on the right elbow.*/
	void setRightElbowKillPitch(bool rek){if(rek == 0) return; fprintf_s(mFile, "setAttr \".kp.rek\" %i;\n", rek);}
	/*When enabled, removes the pitch axis on the right elbow.*/
	void setRightElbowKillPitch(const BoolID& rek){fprintf_s(mFile,"connectAttr \"");rek.write(mFile);fprintf_s(mFile,"\" \"%s.kp.rek\";\n",mName.c_str());}
	/*When enabled, removes the pitch axis on the left knee.*/
	void setLeftKneeKillPitch(bool lkk){if(lkk == 0) return; fprintf_s(mFile, "setAttr \".kp.lkk\" %i;\n", lkk);}
	/*When enabled, removes the pitch axis on the left knee.*/
	void setLeftKneeKillPitch(const BoolID& lkk){fprintf_s(mFile,"connectAttr \"");lkk.write(mFile);fprintf_s(mFile,"\" \"%s.kp.lkk\";\n",mName.c_str());}
	/*When enabled, removes the pitch axis on the right knee.*/
	void setRightKneeKillPitch(bool rkk){if(rkk == 0) return; fprintf_s(mFile, "setAttr \".kp.rkk\" %i;\n", rkk);}
	/*When enabled, removes the pitch axis on the right knee.*/
	void setRightKneeKillPitch(const BoolID& rkk){fprintf_s(mFile,"connectAttr \"");rkk.write(mFile);fprintf_s(mFile,"\" \"%s.kp.rkk\";\n",mName.c_str());}
	/*Folder for Roll Extraction controls*/
	void setRollExtraction(const RollExtraction& re){fprintf_s(mFile, "setAttr \".re\" ");re.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Roll Extraction controls*/
	void setRollExtraction(const RollExtractionID& re){fprintf_s(mFile,"connectAttr \"");re.write(mFile);fprintf_s(mFile,"\" \"%s.re\";\n",mName.c_str());}
	/*Controls whether the roll extraction is relative or absolute.*/
	void setRollExtractionMode(unsigned int rem){if(rem == 0) return; fprintf_s(mFile, "setAttr \".re.rem\" %i;\n", rem);}
	/*Controls whether the roll extraction is relative or absolute.*/
	void setRollExtractionMode(const UnsignedintID& rem){fprintf_s(mFile,"connectAttr \"");rem.write(mFile);fprintf_s(mFile,"\" \"%s.re.rem\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the left arm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftArmRollMode(bool larm){if(larm == 0) return; fprintf_s(mFile, "setAttr \".re.larm\" %i;\n", larm);}
	/*
	Activate/deactivate the roll extraction for the left arm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftArmRollMode(const BoolID& larm){fprintf_s(mFile,"connectAttr \"");larm.write(mFile);fprintf_s(mFile,"\" \"%s.re.larm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the left arm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftArmRoll(float lar){if(lar == 0.60) return; fprintf_s(mFile, "setAttr \".re.lar\" %f;\n", lar);}
	/*
	Adjusts the roll of the left arm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftArmRoll(const FloatID& lar){fprintf_s(mFile,"connectAttr \"");lar.write(mFile);fprintf_s(mFile,"\" \"%s.re.lar\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the left forearm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftForeArmRollMode(bool lfrm){if(lfrm == 0) return; fprintf_s(mFile, "setAttr \".re.lfrm\" %i;\n", lfrm);}
	/*
	Activate/deactivate the roll extraction for the left forearm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftForeArmRollMode(const BoolID& lfrm){fprintf_s(mFile,"connectAttr \"");lfrm.write(mFile);fprintf_s(mFile,"\" \"%s.re.lfrm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the left forearm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftForeArmRoll(float lfr){if(lfr == 0.60) return; fprintf_s(mFile, "setAttr \".re.lfr\" %f;\n", lfr);}
	/*
	Adjusts the roll of the left forearm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftForeArmRoll(const FloatID& lfr){fprintf_s(mFile,"connectAttr \"");lfr.write(mFile);fprintf_s(mFile,"\" \"%s.re.lfr\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the right arm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightArmRollMode(bool rarm){if(rarm == 0) return; fprintf_s(mFile, "setAttr \".re.rarm\" %i;\n", rarm);}
	/*
	Activate/deactivate the roll extraction for the right arm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightArmRollMode(const BoolID& rarm){fprintf_s(mFile,"connectAttr \"");rarm.write(mFile);fprintf_s(mFile,"\" \"%s.re.rarm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the right arm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightArmRoll(float rar){if(rar == 0.60) return; fprintf_s(mFile, "setAttr \".re.rar\" %f;\n", rar);}
	/*
	Adjusts the roll of the right arm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightArmRoll(const FloatID& rar){fprintf_s(mFile,"connectAttr \"");rar.write(mFile);fprintf_s(mFile,"\" \"%s.re.rar\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the left forearm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightForeArmRollMode(bool rfrm){if(rfrm == 0) return; fprintf_s(mFile, "setAttr \".re.rfrm\" %i;\n", rfrm);}
	/*
	Activate/deactivate the roll extraction for the left forearm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightForeArmRollMode(const BoolID& rfrm){fprintf_s(mFile,"connectAttr \"");rfrm.write(mFile);fprintf_s(mFile,"\" \"%s.re.rfrm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the right forearm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightForeArmRoll(float rfr){if(rfr == 0.60) return; fprintf_s(mFile, "setAttr \".re.rfr\" %f;\n", rfr);}
	/*
	Adjusts the roll of the right forearm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightForeArmRoll(const FloatID& rfr){fprintf_s(mFile,"connectAttr \"");rfr.write(mFile);fprintf_s(mFile,"\" \"%s.re.rfr\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the left upper leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftUpLegRollMode(bool lurm){if(lurm == 0) return; fprintf_s(mFile, "setAttr \".re.lurm\" %i;\n", lurm);}
	/*
	Activate/deactivate the roll extraction for the left upper leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftUpLegRollMode(const BoolID& lurm){fprintf_s(mFile,"connectAttr \"");lurm.write(mFile);fprintf_s(mFile,"\" \"%s.re.lurm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the left upper leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftUpLegRoll(float lur){if(lur == 0.60) return; fprintf_s(mFile, "setAttr \".re.lur\" %f;\n", lur);}
	/*
	Adjusts the roll of the left upper leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftUpLegRoll(const FloatID& lur){fprintf_s(mFile,"connectAttr \"");lur.write(mFile);fprintf_s(mFile,"\" \"%s.re.lur\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the left leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftLegRollMode(bool llrm){if(llrm == 0) return; fprintf_s(mFile, "setAttr \".re.llrm\" %i;\n", llrm);}
	/*
	Activate/deactivate the roll extraction for the left leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setLeftLegRollMode(const BoolID& llrm){fprintf_s(mFile,"connectAttr \"");llrm.write(mFile);fprintf_s(mFile,"\" \"%s.re.llrm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the left leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftLegRoll(float llr){if(llr == 0.60) return; fprintf_s(mFile, "setAttr \".re.llr\" %f;\n", llr);}
	/*
	Adjusts the roll of the left leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setLeftLegRoll(const FloatID& llr){fprintf_s(mFile,"connectAttr \"");llr.write(mFile);fprintf_s(mFile,"\" \"%s.re.llr\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the right upper leg.
	0% extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightUpLegRollMode(bool rurm){if(rurm == 0) return; fprintf_s(mFile, "setAttr \".re.rurm\" %i;\n", rurm);}
	/*
	Activate/deactivate the roll extraction for the right upper leg.
	0% extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightUpLegRollMode(const BoolID& rurm){fprintf_s(mFile,"connectAttr \"");rurm.write(mFile);fprintf_s(mFile,"\" \"%s.re.rurm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the right upper leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightUpLegRoll(float rur){if(rur == 0.60) return; fprintf_s(mFile, "setAttr \".re.rur\" %f;\n", rur);}
	/*
	Adjusts the roll of the right upper leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightUpLegRoll(const FloatID& rur){fprintf_s(mFile,"connectAttr \"");rur.write(mFile);fprintf_s(mFile,"\" \"%s.re.rur\";\n",mName.c_str());}
	/*
	Activate/deactivate the roll extraction for the right leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightLegRollMode(bool rlrm){if(rlrm == 0) return; fprintf_s(mFile, "setAttr \".re.rlrm\" %i;\n", rlrm);}
	/*
	Activate/deactivate the roll extraction for the right leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	void setRightLegRollMode(const BoolID& rlrm){fprintf_s(mFile,"connectAttr \"");rlrm.write(mFile);fprintf_s(mFile,"\" \"%s.re.rlrm\";\n",mName.c_str());}
	/*
	Adjusts the roll of the right leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightLegRoll(float rlro){if(rlro == 0.60) return; fprintf_s(mFile, "setAttr \".re.rlro\" %f;\n", rlro);}
	/*
	Adjusts the roll of the right leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	void setRightLegRoll(const FloatID& rlro){fprintf_s(mFile,"connectAttr \"");rlro.write(mFile);fprintf_s(mFile,"\" \"%s.re.rlro\";\n",mName.c_str());}
	/*The associated hikEffectors for this handle.*/
	const BoolID& getEffectors(size_t eff_i){char buffer[4096];sprintf_s (buffer, "%s.eff[%i]",mName.c_str(),eff_i);return (const char*)buffer;}
	/*
	The ground plane for the left foot floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use leftFootOrientedGroundPlane instead.
	*/
	DoubleID getLeftFootGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.lfg",mName.c_str());return (const char*)buffer;}
	/*
	The ground plane for the right foot floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use rightFootOrientedGroundPlane instead.
	*/
	DoubleID getRightFootGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.rfg",mName.c_str());return (const char*)buffer;}
	/*The oriented ground plane for the right foot floor contact.*/
	MatrixID getRightFootOrientedGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.rog",mName.c_str());return (const char*)buffer;}
	/*The oriented ground plane for the left foot floor contact.*/
	MatrixID getLeftFootOrientedGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.log",mName.c_str());return (const char*)buffer;}
	/*
	The ground plane for the left hand floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use leftHandOrientedGroundPlane instead.
	*/
	DoubleID getLeftHandGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.lhg",mName.c_str());return (const char*)buffer;}
	/*
	The ground plane for the right hand floor contact.
	*obsolete* used for non-oriented floor contacts.
	Use rightHandOrientedGroundPlane instead.
	*/
	DoubleID getRightHandGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.rhg",mName.c_str());return (const char*)buffer;}
	/*The oriented ground plane for the left hand floor contact.*/
	MatrixID getLeftHandOrientedGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.loh",mName.c_str());return (const char*)buffer;}
	/*The oriented ground plane for the right hand floor contact.*/
	MatrixID getRightHandOrientedGroundPlane(){char buffer[4096];sprintf_s (buffer, "%s.roh",mName.c_str());return (const char*)buffer;}
	/*The joints controlled by this handle.*/
	const MessageID& getJoints(size_t jt_i){char buffer[4096];sprintf_s (buffer, "%s.jt[%i]",mName.c_str(),jt_i);return (const char*)buffer;}
	/*the FK joints, which together with the effectors, drive the joints controlled by this handle*/
	const MessageID& getFkjoints(size_t fj_i){char buffer[4096];sprintf_s (buffer, "%s.fj[%i]",mName.c_str(),fj_i);return (const char*)buffer;}
	/*The current time.*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.tim",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is used during file save and retrieve only.
	It stores the current default matrix for each joint at the time
	the file was saved. This matrix is used to initialize the humanIK
	solve after file open.
	*/
	const MatrixID& getDefaultMatrix(size_t dm_i){char buffer[4096];sprintf_s (buffer, "%s.dm[%i]",mName.c_str(),dm_i);return (const char*)buffer;}
	/*
	This attribute stores the stance pose that will be needed to initialize
	human ik.
	*/
	const MatrixID& getStancePoseMatrix(size_t sm_i){char buffer[4096];sprintf_s (buffer, "%s.sm[%i]",mName.c_str(),sm_i);return (const char*)buffer;}
	/*Indicates whether the FK skeleton is in Motion Builder 5.5 format.*/
	BoolID getUsingMB55Rig(){char buffer[4096];sprintf_s (buffer, "%s.m55",mName.c_str());return (const char*)buffer;}
	/*Indicates whether the Full body system should be active or not.*/
	BoolID getActivate(){char buffer[4096];sprintf_s (buffer, "%s.act",mName.c_str());return (const char*)buffer;}
	/*
	Indicates upon file open, whether to put the scale of all effectors to
	unity and scale up the radius by the same amount.  This attribute is put
	primarily for backward compatibility purposes, where in previous versions
	of Maya (pre 2008) the scale of effectors did not matter, but starting
	from Maya 2008, at least the scale of secondary pivots does matter.
	*/
	BoolID getConvertScale(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*Internal attribute used to optimize evaluation of properties for the solver.*/
	MessageID getPropertyChanged(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Folder for Solving controls*/
	SolvingID getSolving(){char buffer[4096];sprintf_s (buffer, "%s.sol",mName.c_str());return (const char*)buffer;}
	/*Switches your control rig between a biped or quadraped posture.*/
	UnsignedintID getPostureType(){char buffer[4096];sprintf_s (buffer, "%s.sol.pt",mName.c_str());return (const char*)buffer;}
	/*
	When activated, the pull and stiffness options are available and
	contribute to the FBIK solution during playback.
	*/
	BoolID getExpertMode(){char buffer[4096];sprintf_s (buffer, "%s.sol.exp",mName.c_str());return (const char*)buffer;}
	/*Shoulder correction for extreme rotation.*/
	FloatID getRealisticShoulderSolving(){char buffer[4096];sprintf_s (buffer, "%s.sol.rss",mName.c_str());return (const char*)buffer;}
	/*
	Controls whether IK solving is done for fingers. When disabled,
	performance will be improved.
	*/
	BoolID getSolveFingers(){char buffer[4096];sprintf_s (buffer, "%s.sol.sf",mName.c_str());return (const char*)buffer;}
	/*
	The hips translation mode setting lets you select whether rotation
	is applied to both (body rigid) the hips node and the hipsTranslation node,
	or only the hips node (world rigid). This is useful when you have defined
	a second joint for translating the hips of your model and you do not want
	the second node to receive rotation. To use this setting, you must define
	a hipsTranslation node when setting up your character.
	*/
	UnsignedintID getHipTranslationMode(){char buffer[4096];sprintf_s (buffer, "%s.sol.htm",mName.c_str());return (const char*)buffer;}
	/*Folder for Floor Contacts controls*/
	FloorContactsID getFloorContacts(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the hands from going through the floor.*/
	BoolID getHandsFloorContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.hfc",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the feet from going through the floor.*/
	BoolID getFeetFloorContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.fec",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the fingers from going through the floor.*/
	BoolID getFingersFloorContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.fic",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the toes from going through the floor.*/
	BoolID getToesFloorContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.tfc",mName.c_str());return (const char*)buffer;}
	/*Folder for Hands Floor Contact Setup controls*/
	HandsFloorContactSetupID getHandsFloorContactSetup(){char buffer[4096];sprintf_s (buffer, "%s.flc",mName.c_str());return (const char*)buffer;}
	/*Define a stable point when applying floor contact.*/
	UnsignedintID getHandsFloorPivot(){char buffer[4096];sprintf_s (buffer, "%s.flc.hfp",mName.c_str());return (const char*)buffer;}
	/*
	This attribute allows you to define the number and orientation of
	markers used to define the floor contact for the hands. In "normal" contact,
	six markers define each contact between the hand and the floor. The middle markers
	should define where the fingers begin. In "wrist" contact, four
	points define each contact. The hand markers are displayed around each palm.
	In "FingerBase" contact, four points define each contact. The hand floor
	contact markers display around each finger. In "hoof" contact, four
	points define each contact, but the points are oriented at a 90 degree angle,
	allowing you to define the floor contact for animal types with hooves, such
	as horses. These contact markers allow for 180 degrees of movement.
	*/
	UnsignedintID getHandsContactType(){char buffer[4096];sprintf_s (buffer, "%s.flc.hct",mName.c_str());return (const char*)buffer;}
	/*
	Defines how stiff the hand becomes as soon as any part of the
	hand contacts the floor.
	At 100% (1.0) the wrist rotation will not change, this keeps the hand configuration while contacting.
	At 0% the wrist rotation will be adapted to minimize floor penetration.
	In both cases, wrist translation will do the final correction.
	*/
	FloatID getHandsContactStiffness(){char buffer[4096];sprintf_s (buffer, "%s.flc.hcs",mName.c_str());return (const char*)buffer;}
	/*Folder for Contacts Position controls*/
	ContactsPositionID getContactsPosition(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
	/*Defines the floor contact offset height for the hand*/
	FloatID getHandHeight(){char buffer[4096];sprintf_s (buffer, "%s.cp.hh",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the back edge of the hand.*/
	FloatID getHandBack(){char buffer[4096];sprintf_s (buffer, "%s.cp.hb",mName.c_str());return (const char*)buffer;}
	/*Defines the length to the middle of the hand, where the fingers bend.*/
	FloatID getHandMiddle(){char buffer[4096];sprintf_s (buffer, "%s.cp.hm",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the frontmost part of the hand.*/
	FloatID getHandFront(){char buffer[4096];sprintf_s (buffer, "%s.cp.hf",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the interior of the hand.*/
	FloatID getHandInSide(){char buffer[4096];sprintf_s (buffer, "%s.cp.his",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the exterior of the hand.*/
	FloatID getHandOutSide(){char buffer[4096];sprintf_s (buffer, "%s.cp.hos",mName.c_str());return (const char*)buffer;}
	/*Folder for Feet Floor Contact Setup controls*/
	FeetFloorContactSetupID getFeetFloorContactSetup(){char buffer[4096];sprintf_s (buffer, "%s.fle",mName.c_str());return (const char*)buffer;}
	/*
	Specify which part of the feet take priority when they make
	contact with the floor. A selection of "auto" will average
	priority between the ankle and toes so that when the
	foot makes conact with the floor the ankle is translated back
	and the toes are pushed forward. A selection of "ankle"
	will cause the toes to move forward to maintain the trajectory
	of the ankle. A selection of "toes" will cause the ankle to
	be translated backwards to keep the toes firmly planted.
	*/
	UnsignedintID getFeetFloorPivot(){char buffer[4096];sprintf_s (buffer, "%s.fle.fpv",mName.c_str());return (const char*)buffer;}
	/*
	This attribute allows you to define the number and orientation of
	markers used to define the floor contact for the foot. In "normal" contact,
	six markers define each contact between the foot and the floor. The middle markers
	should define where the toes begin. In "ankle" contact, four
	points define each contact and are placed around the base of the foot.
	In "toe base" contact, four points define each contact and are placed
	around the toes of each foot. In "hoof" contact, four
	points define each contact, but the points are oriented at a 90 degree angle,
	allowing you to define the floor contact for animal types with hooves, such
	as horses. These contact markers allow for 180 degrees of movement.
	*/
	UnsignedintID getFeetContactType(){char buffer[4096];sprintf_s (buffer, "%s.fle.fct",mName.c_str());return (const char*)buffer;}
	/*
	Defines how stiff the foot becomes as soon as any part of the
	foot contacts the floor.
	At 100% (1.0) the ankle rotation will not change, this keeps the foot configuration while contacting.
	At 0% the ankle rotation will be adapted to minimize floor penetration.
	In both cases, ankle translation will do the final correction.
	*/
	FloatID getFeetContactStiffness(){char buffer[4096];sprintf_s (buffer, "%s.fle.fcs",mName.c_str());return (const char*)buffer;}
	/*Folder for feet contact position controls*/
	FeetContactPositionID getFeetContactPosition(){char buffer[4096];sprintf_s (buffer, "%s.flf",mName.c_str());return (const char*)buffer;}
	/*Defines the floor contact offset height for the foot*/
	FloatID getFootHeight(){char buffer[4096];sprintf_s (buffer, "%s.flf.fh",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the back edge of the foot.*/
	FloatID getFootBack(){char buffer[4096];sprintf_s (buffer, "%s.flf.fra",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the middle (ball) of the foot.*/
	FloatID getFootMiddle(){char buffer[4096];sprintf_s (buffer, "%s.flf.fma",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the frontmost section of the foot.*/
	FloatID getFootFront(){char buffer[4096];sprintf_s (buffer, "%s.flf.ffm",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the interior of the foot.*/
	FloatID getFootInSide(){char buffer[4096];sprintf_s (buffer, "%s.flf.fia",mName.c_str());return (const char*)buffer;}
	/*Defines the length of the exterior of the foot.*/
	FloatID getFootOutSide(){char buffer[4096];sprintf_s (buffer, "%s.flf.foa",mName.c_str());return (const char*)buffer;}
	/*Folder for Fingers Floor Contact Setup controls*/
	FingersFloorContactSetupID getFingersFloorContactSetup(){char buffer[4096];sprintf_s (buffer, "%s.flg",mName.c_str());return (const char*)buffer;}
	/*
	Controls the behavior of the fingers as they make contact with the
	floor. You can select between three different behaviors: sticky, spread
	and stickySpread. "Sticky" causes each finger to stick to the floor exactly
	where contact is made. "Spread" spreads the fingers as they make contact
	with the floor, attempting to keep the position of the fingers intact.
	Rotation is applied to the root of each finger. "StickySpread" averages
	the finger behaviour between both Sticky and Spread.
	*/
	UnsignedintID getFingersContactType(){char buffer[4096];sprintf_s (buffer, "%s.flg.fcm",mName.c_str());return (const char*)buffer;}
	/*Defines how the finger rotations will react to a floor contact.*/
	FloatID getFingersContactRollStiffness(){char buffer[4096];sprintf_s (buffer, "%s.flg.hcr",mName.c_str());return (const char*)buffer;}
	/*Folder for finger tips size controls*/
	FingerTipsSizesID getFingerTipsSizes(){char buffer[4096];sprintf_s (buffer, "%s.fts",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left thumb.*/
	FloatID getLeftHandThumbTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.ltt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left index finger.*/
	FloatID getLeftHandIndexTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.lit",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left middle finger.*/
	FloatID getLeftHandMiddleTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.lmt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left ring finger.*/
	FloatID getLeftHandRingTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.lrt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left pinky finger.*/
	FloatID getLeftHandPinkyTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.lpt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left extra finger.*/
	FloatID getLeftHandExtraFingerTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.lxt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right thumb.*/
	FloatID getRightHandThumbTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.rtt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right index finger.*/
	FloatID getRightHandIndexTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.rit",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right middle finger.*/
	FloatID getRightHandMiddleTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.rmt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right ring finger.*/
	FloatID getRightHandRingTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.rrt",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right pinky finger.*/
	FloatID getRightHandPinkyTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.rpp",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right extra finger.*/
	FloatID getRightHandExtraFingerTip(){char buffer[4096];sprintf_s (buffer, "%s.fts.rxt",mName.c_str());return (const char*)buffer;}
	/*Folder for Toes Floor Contact Setup controls*/
	ToesFloorContactSetupID getToesFloorContactSetup(){char buffer[4096];sprintf_s (buffer, "%s.fli",mName.c_str());return (const char*)buffer;}
	/*
	Controls the behavior of the toes as they make contact with the
	floor. You can select between three different behaviors: sticky, spread
	and stickySpread. "Sticky" causes each toe to stick to the floor exactly
	where contact is made. "Spread" spreads the toes as they make contact
	with the floor, attempting to keep the position of the toes intact.
	Rotation is applied to the root of each toe. "StickySpread" averages
	the toe behaviour between both Sticky and Spread.
	*/
	UnsignedintID getToesContactType(){char buffer[4096];sprintf_s (buffer, "%s.fli.tct",mName.c_str());return (const char*)buffer;}
	/*Defines how the toe rotations will react to a floor contact.*/
	FloatID getToesContactRollStiffness(){char buffer[4096];sprintf_s (buffer, "%s.fli.fcr",mName.c_str());return (const char*)buffer;}
	/*Folder for Toe Tips Sizes controls*/
	ToeTipsSizesID getToeTipsSizes(){char buffer[4096];sprintf_s (buffer, "%s.flj",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left big toe.*/
	FloatID getLeftFootThumbTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.ttl",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left index toe.*/
	FloatID getLeftFootIndexTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.til",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left middle toe.*/
	FloatID getLeftFootMiddleTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.tml",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left ring toe.*/
	FloatID getLeftFootRingTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.trl",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left pinky toe.*/
	FloatID getLeftFootPinkyTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.tpl",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the left extra toe.*/
	FloatID getLeftFootExtraFingerTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.txl",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right big toe.*/
	FloatID getRightFootThumbTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.ttr",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right index toe.*/
	FloatID getRightFootIndexTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.tir",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right middle toe.*/
	FloatID getRightFootMiddleTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.tmr",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right ring toe.*/
	FloatID getRightFootRingTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.trr",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right pinky toe.*/
	FloatID getRightFootPinkyTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.tpr",mName.c_str());return (const char*)buffer;}
	/*Adjusts the size of the floor marker used to outline the right extra toe.*/
	FloatID getRightFootExtraFingerTip(){char buffer[4096];sprintf_s (buffer, "%s.flj.txr",mName.c_str());return (const char*)buffer;}
	/*Folder for Head controls*/
	HeadID getHead(){char buffer[4096];sprintf_s (buffer, "%s.fll",mName.c_str());return (const char*)buffer;}
	/*The extent to which the head is attracted to its effector during IK playback.*/
	FloatID getHeadPull(){char buffer[4096];sprintf_s (buffer, "%s.fll.phd",mName.c_str());return (const char*)buffer;}
	/*Folder for Left Arm controls*/
	LeftArmID getLeftArm(){char buffer[4096];sprintf_s (buffer, "%s.flm",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left elbow is attracted to its effector during IK playback.*/
	FloatID getLeftElbowPull(){char buffer[4096];sprintf_s (buffer, "%s.flm.ple",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left hand affects the chest during IK playback.*/
	FloatID getLeftHandPullChest(){char buffer[4096];sprintf_s (buffer, "%s.flm.cpl",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left hand affects the hips during IK playback.*/
	FloatID getLeftHandPullHips(){char buffer[4096];sprintf_s (buffer, "%s.flm.plh",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left finger base is attracted to its effector during IK playback.*/
	FloatID getLeftFingerBasePull(){char buffer[4096];sprintf_s (buffer, "%s.flm.plb",mName.c_str());return (const char*)buffer;}
	/*Folder for Right Arm controls*/
	RightArmID getRightArm(){char buffer[4096];sprintf_s (buffer, "%s.fln",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right elbow is attracted to its effector during IK playback.*/
	FloatID getRightElbowPull(){char buffer[4096];sprintf_s (buffer, "%s.fln.pre",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right hand affects the chest during IK playback.*/
	FloatID getRightHandPullChest(){char buffer[4096];sprintf_s (buffer, "%s.fln.cpr",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right hand affects the hips during IK playback.*/
	FloatID getRightHandPullHips(){char buffer[4096];sprintf_s (buffer, "%s.fln.prh",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right finger base is attracted to its effector during IK playback.*/
	FloatID getRightFingerBasePull(){char buffer[4096];sprintf_s (buffer, "%s.fln.prb",mName.c_str());return (const char*)buffer;}
	/*Folder for Chest controls*/
	ChestID getChest(){char buffer[4096];sprintf_s (buffer, "%s.flo",mName.c_str());return (const char*)buffer;}
	/*The degree to which the solver tries to preserve the initial FK angle of the chest.*/
	FloatID getChestPull(){char buffer[4096];sprintf_s (buffer, "%s.flo.rcp",mName.c_str());return (const char*)buffer;}
	/*Folder for Hips controls*/
	HipsID getHips(){char buffer[4096];sprintf_s (buffer, "%s.flp",mName.c_str());return (const char*)buffer;}
	/*The degree to which the solver tries to preserve the initial FK angle of the hips.*/
	FloatID getHipsPull(){char buffer[4096];sprintf_s (buffer, "%s.flp.chp",mName.c_str());return (const char*)buffer;}
	/*Folder for Left Leg controls*/
	LeftLegID getLeftLeg(){char buffer[4096];sprintf_s (buffer, "%s.flq",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left knee is attracted to its effector during IK playback.*/
	FloatID getLeftKneePull(){char buffer[4096];sprintf_s (buffer, "%s.flq.plk",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left foot is attracted to its effector during IK playback.*/
	FloatID getLeftFootPull(){char buffer[4096];sprintf_s (buffer, "%s.flq.plf",mName.c_str());return (const char*)buffer;}
	/*The extent to which the left toe base is attracted to its effector during IK playback.*/
	FloatID getLeftToeBasePull(){char buffer[4096];sprintf_s (buffer, "%s.flq.plt",mName.c_str());return (const char*)buffer;}
	/*Folder for Right Leg controls*/
	RightLegID getRightLeg(){char buffer[4096];sprintf_s (buffer, "%s.flr",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right knee is attracted to its effector during IK playback.*/
	FloatID getRightKneePull(){char buffer[4096];sprintf_s (buffer, "%s.flr.prk",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right foot is attracted to its effector during IK playback.*/
	FloatID getRightFootPull(){char buffer[4096];sprintf_s (buffer, "%s.flr.prf",mName.c_str());return (const char*)buffer;}
	/*The extent to which the right toe base is attracted to its effector during IK playback.*/
	FloatID getRightToeBasePull(){char buffer[4096];sprintf_s (buffer, "%s.flr.prt",mName.c_str());return (const char*)buffer;}
	/*Folder for Extra controls*/
	ExtraID getExtra(){char buffer[4096];sprintf_s (buffer, "%s.ex",mName.c_str());return (const char*)buffer;}
	/*
	Controls the number of times pull is calculated. The greater the
	number of iterations, the more accurate the pull calculation. However,
	a higher number of iterations may decrease system performance.
	*/
	FloatID getPullIterationCount(){char buffer[4096];sprintf_s (buffer, "%s.ex.pic",mName.c_str());return (const char*)buffer;}
	/*Folder for Stiffness controls*/
	StiffnessID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the neck.*/
	FloatID getNeckStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.nst",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the left collar.*/
	FloatID getLeftShoulderStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rlco",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the left elbow.*/
	FloatID getLeftArmStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rle",mName.c_str());return (const char*)buffer;}
	/*
	Dampens the left arm as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	FloatID getLeftElbowMaxExtension(){char buffer[4096];sprintf_s (buffer, "%s.st.mle",mName.c_str());return (const char*)buffer;}
	/*
	Changes the stiffness of an extended left arm as it
	contracts or closes. At 100% (1.0) the extended left arm
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	FloatID getLeftElbowCompressionFactor(){char buffer[4096];sprintf_s (buffer, "%s.st.cle",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the right collar.*/
	FloatID getRightShoulderStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rrc",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the right elbow.*/
	FloatID getRightArmStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rre",mName.c_str());return (const char*)buffer;}
	/*
	Dampens the right arm as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	FloatID getRightElbowMaxExtension(){char buffer[4096];sprintf_s (buffer, "%s.st.mre",mName.c_str());return (const char*)buffer;}
	/*
	Changes the stiffness of an extended right arm as it
	contracts or closes. At 100% (1.0) the extended right arm
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	FloatID getRightElbowCompressionFactor(){char buffer[4096];sprintf_s (buffer, "%s.st.cre",mName.c_str());return (const char*)buffer;}
	/*
	Forces the character's hips to be between its feet.
	The hipsStiffness must be set to a non-zero value to take
	advantage of hipsEnforceGravity.
	*/
	FloatID getHipsEnforceGravity(){char buffer[4096];sprintf_s (buffer, "%s.st.egr",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the chest.*/
	FloatID getChestStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rco",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the spine.*/
	FloatID getSpineStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.sst",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the hips.*/
	FloatID getHipsStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rho",mName.c_str());return (const char*)buffer;}
	/*
	Dampens the left leg as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	FloatID getLeftKneeMaxExtension(){char buffer[4096];sprintf_s (buffer, "%s.st.mlk",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the left knee.*/
	FloatID getLeftLegStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rlk",mName.c_str());return (const char*)buffer;}
	/*
	Changes the stiffness of an extended left leg as it
	contracts or closes. At 100% (1.0) the extended left leg
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	FloatID getLeftKneeCompressionFactor(){char buffer[4096];sprintf_s (buffer, "%s.st.clk",mName.c_str());return (const char*)buffer;}
	/*Degree to which the solver tries to preserve the initial FK angle on the right knee.*/
	FloatID getRightLegStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st.rrk",mName.c_str());return (const char*)buffer;}
	/*
	Dampens the right leg as it fully extends to prevent limb snapping.
	The higher the value, the more gradual the limb extendeds. By default,
	a value of .5 corrects most limb snapping.
	*/
	FloatID getRightKneeMaxExtension(){char buffer[4096];sprintf_s (buffer, "%s.st.mrk",mName.c_str());return (const char*)buffer;}
	/*
	Changes the stiffness of an extended right leg as it
	contracts or closes. At 100% (1.0) the extended right leg
	will not bend, but instead pushes the chest of the character,
	moving the character.
	*/
	FloatID getRightKneeCompressionFactor(){char buffer[4096];sprintf_s (buffer, "%s.st.crk",mName.c_str());return (const char*)buffer;}
	/*Folder for kill pitch controls*/
	KillPitchID getKillPitch(){char buffer[4096];sprintf_s (buffer, "%s.kp",mName.c_str());return (const char*)buffer;}
	/*When enabled, removes the pitch axis on the left elbow.*/
	BoolID getLeftElbowKillPitch(){char buffer[4096];sprintf_s (buffer, "%s.kp.lek",mName.c_str());return (const char*)buffer;}
	/*When enabled, removes the pitch axis on the right elbow.*/
	BoolID getRightElbowKillPitch(){char buffer[4096];sprintf_s (buffer, "%s.kp.rek",mName.c_str());return (const char*)buffer;}
	/*When enabled, removes the pitch axis on the left knee.*/
	BoolID getLeftKneeKillPitch(){char buffer[4096];sprintf_s (buffer, "%s.kp.lkk",mName.c_str());return (const char*)buffer;}
	/*When enabled, removes the pitch axis on the right knee.*/
	BoolID getRightKneeKillPitch(){char buffer[4096];sprintf_s (buffer, "%s.kp.rkk",mName.c_str());return (const char*)buffer;}
	/*Folder for Roll Extraction controls*/
	RollExtractionID getRollExtraction(){char buffer[4096];sprintf_s (buffer, "%s.re",mName.c_str());return (const char*)buffer;}
	/*Controls whether the roll extraction is relative or absolute.*/
	UnsignedintID getRollExtractionMode(){char buffer[4096];sprintf_s (buffer, "%s.re.rem",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the left arm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getLeftArmRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.larm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the left arm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getLeftArmRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.lar",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the left forearm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getLeftForeArmRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.lfrm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the left forearm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getLeftForeArmRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.lfr",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the right arm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getRightArmRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.rarm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the right arm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getRightArmRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.rar",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the left forearm. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getRightForeArmRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.rfrm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the right forearm. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getRightForeArmRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.rfr",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the left upper leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getLeftUpLegRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.lurm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the left upper leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getLeftUpLegRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.lur",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the left leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getLeftLegRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.llrm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the left leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getLeftLegRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.llr",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the right upper leg.
	0% extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getRightUpLegRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.rurm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the right upper leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getRightUpLegRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.rur",mName.c_str());return (const char*)buffer;}
	/*
	Activate/deactivate the roll extraction for the right leg. 0% roll
	extraction is not equal to no extraction when you are in
	"absolute extraction mode".
	*/
	BoolID getRightLegRollMode(){char buffer[4096];sprintf_s (buffer, "%s.re.rlrm",mName.c_str());return (const char*)buffer;}
	/*
	Adjusts the roll of the right leg. At 100% (1.0), all of
	the roll transfers from the original limb to the roll bone, moving
	the roll bone and its parent. At 50% (0.5), the roll is equally distributed
	between the limb and the roll bone. At 0%, none of the roll is
	transferred to the rest of the limb, moving only the roll bone.
	*/
	FloatID getRightLegRoll(){char buffer[4096];sprintf_s (buffer, "%s.re.rlro",mName.c_str());return (const char*)buffer;}
protected:
	HikHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkHandle(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HIKHANDLE_H__
