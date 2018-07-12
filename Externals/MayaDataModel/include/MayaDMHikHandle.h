/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class HikHandle : public IkHandle
{
public:
	struct Solving{
		unsigned int postureType;
		bool expertMode;
		float realisticShoulderSolving;
		bool solveFingers;
		unsigned int hipTranslationMode;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", postureType);
			fprintf(file,"%i ", expertMode);
			fprintf(file,"%f ", realisticShoulderSolving);
			fprintf(file,"%i ", solveFingers);
			fprintf(file,"%i", hipTranslationMode);
		}
	};
	struct FloorContacts{
		bool handsFloorContact;
		bool feetFloorContact;
		bool fingersFloorContact;
		bool toesFloorContact;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", handsFloorContact);
			fprintf(file,"%i ", feetFloorContact);
			fprintf(file,"%i ", fingersFloorContact);
			fprintf(file,"%i", toesFloorContact);
		}
	};
	struct HandsFloorContactSetup{
		unsigned int handsFloorPivot;
		unsigned int handsContactType;
		float handsContactStiffness;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", handsFloorPivot);
			fprintf(file,"%i ", handsContactType);
			fprintf(file,"%f", handsContactStiffness);
		}
	};
	struct ContactsPosition{
		float handHeight;
		float handBack;
		float handMiddle;
		float handFront;
		float handInSide;
		float handOutSide;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", handHeight);
			fprintf(file,"%f ", handBack);
			fprintf(file,"%f ", handMiddle);
			fprintf(file,"%f ", handFront);
			fprintf(file,"%f ", handInSide);
			fprintf(file,"%f", handOutSide);
		}
	};
	struct FeetFloorContactSetup{
		unsigned int feetFloorPivot;
		unsigned int feetContactType;
		float feetContactStiffness;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", feetFloorPivot);
			fprintf(file,"%i ", feetContactType);
			fprintf(file,"%f", feetContactStiffness);
		}
	};
	struct FeetContactPosition{
		float footHeight;
		float footBack;
		float footMiddle;
		float footFront;
		float footInSide;
		float footOutSide;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", footHeight);
			fprintf(file,"%f ", footBack);
			fprintf(file,"%f ", footMiddle);
			fprintf(file,"%f ", footFront);
			fprintf(file,"%f ", footInSide);
			fprintf(file,"%f", footOutSide);
		}
	};
	struct FingersFloorContactSetup{
		unsigned int fingersContactType;
		float fingersContactRollStiffness;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", fingersContactType);
			fprintf(file,"%f", fingersContactRollStiffness);
		}
	};
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
			fprintf(file,"%f ", leftHandThumbTip);
			fprintf(file,"%f ", leftHandIndexTip);
			fprintf(file,"%f ", leftHandMiddleTip);
			fprintf(file,"%f ", leftHandRingTip);
			fprintf(file,"%f ", leftHandPinkyTip);
			fprintf(file,"%f ", leftHandExtraFingerTip);
			fprintf(file,"%f ", rightHandThumbTip);
			fprintf(file,"%f ", rightHandIndexTip);
			fprintf(file,"%f ", rightHandMiddleTip);
			fprintf(file,"%f ", rightHandRingTip);
			fprintf(file,"%f ", rightHandPinkyTip);
			fprintf(file,"%f", rightHandExtraFingerTip);
		}
	};
	struct ToesFloorContactSetup{
		unsigned int toesContactType;
		float toesContactRollStiffness;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", toesContactType);
			fprintf(file,"%f", toesContactRollStiffness);
		}
	};
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
			fprintf(file,"%f ", leftFootThumbTip);
			fprintf(file,"%f ", leftFootIndexTip);
			fprintf(file,"%f ", leftFootMiddleTip);
			fprintf(file,"%f ", leftFootRingTip);
			fprintf(file,"%f ", leftFootPinkyTip);
			fprintf(file,"%f ", leftFootExtraFingerTip);
			fprintf(file,"%f ", rightFootThumbTip);
			fprintf(file,"%f ", rightFootIndexTip);
			fprintf(file,"%f ", rightFootMiddleTip);
			fprintf(file,"%f ", rightFootRingTip);
			fprintf(file,"%f ", rightFootPinkyTip);
			fprintf(file,"%f", rightFootExtraFingerTip);
		}
	};
	struct Head{
		float headPull;
		void write(FILE* file) const
		{
			fprintf(file,"%f", headPull);
		}
	};
	struct LeftArm{
		float leftElbowPull;
		float leftHandPullChest;
		float leftHandPullHips;
		float leftFingerBasePull;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", leftElbowPull);
			fprintf(file,"%f ", leftHandPullChest);
			fprintf(file,"%f ", leftHandPullHips);
			fprintf(file,"%f", leftFingerBasePull);
		}
	};
	struct RightArm{
		float rightElbowPull;
		float rightHandPullChest;
		float rightHandPullHips;
		float rightFingerBasePull;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", rightElbowPull);
			fprintf(file,"%f ", rightHandPullChest);
			fprintf(file,"%f ", rightHandPullHips);
			fprintf(file,"%f", rightFingerBasePull);
		}
	};
	struct Chest{
		float chestPull;
		void write(FILE* file) const
		{
			fprintf(file,"%f", chestPull);
		}
	};
	struct Hips{
		float hipsPull;
		void write(FILE* file) const
		{
			fprintf(file,"%f", hipsPull);
		}
	};
	struct LeftLeg{
		float leftKneePull;
		float leftFootPull;
		float leftToeBasePull;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", leftKneePull);
			fprintf(file,"%f ", leftFootPull);
			fprintf(file,"%f", leftToeBasePull);
		}
	};
	struct RightLeg{
		float rightKneePull;
		float rightFootPull;
		float rightToeBasePull;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", rightKneePull);
			fprintf(file,"%f ", rightFootPull);
			fprintf(file,"%f", rightToeBasePull);
		}
	};
	struct Extra{
		float pullIterationCount;
		void write(FILE* file) const
		{
			fprintf(file,"%f", pullIterationCount);
		}
	};
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
			fprintf(file,"%f ", neckStiffness);
			fprintf(file,"%f ", leftShoulderStiffness);
			fprintf(file,"%f ", leftArmStiffness);
			fprintf(file,"%f ", leftElbowMaxExtension);
			fprintf(file,"%f ", leftElbowCompressionFactor);
			fprintf(file,"%f ", rightShoulderStiffness);
			fprintf(file,"%f ", rightArmStiffness);
			fprintf(file,"%f ", rightElbowMaxExtension);
			fprintf(file,"%f ", rightElbowCompressionFactor);
			fprintf(file,"%f ", hipsEnforceGravity);
			fprintf(file,"%f ", chestStiffness);
			fprintf(file,"%f ", spineStiffness);
			fprintf(file,"%f ", hipsStiffness);
			fprintf(file,"%f ", leftKneeMaxExtension);
			fprintf(file,"%f ", leftLegStiffness);
			fprintf(file,"%f ", leftKneeCompressionFactor);
			fprintf(file,"%f ", rightLegStiffness);
			fprintf(file,"%f ", rightKneeMaxExtension);
			fprintf(file,"%f", rightKneeCompressionFactor);
		}
	};
	struct KillPitch{
		bool leftElbowKillPitch;
		bool rightElbowKillPitch;
		bool leftKneeKillPitch;
		bool rightKneeKillPitch;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", leftElbowKillPitch);
			fprintf(file,"%i ", rightElbowKillPitch);
			fprintf(file,"%i ", leftKneeKillPitch);
			fprintf(file,"%i", rightKneeKillPitch);
		}
	};
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
			fprintf(file,"%i ", rollExtractionMode);
			fprintf(file,"%i ", leftArmRollMode);
			fprintf(file,"%f ", leftArmRoll);
			fprintf(file,"%i ", leftForeArmRollMode);
			fprintf(file,"%f ", leftForeArmRoll);
			fprintf(file,"%i ", rightArmRollMode);
			fprintf(file,"%f ", rightArmRoll);
			fprintf(file,"%i ", rightForeArmRollMode);
			fprintf(file,"%f ", rightForeArmRoll);
			fprintf(file,"%i ", leftUpLegRollMode);
			fprintf(file,"%f ", leftUpLegRoll);
			fprintf(file,"%i ", leftLegRollMode);
			fprintf(file,"%f ", leftLegRoll);
			fprintf(file,"%i ", rightUpLegRollMode);
			fprintf(file,"%f ", rightUpLegRoll);
			fprintf(file,"%i ", rightLegRollMode);
			fprintf(file,"%f", rightLegRoll);
		}
	};
public:

	HikHandle():IkHandle(){}
	HikHandle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:IkHandle(file, name, parent, "hikHandle", shared, create){}
	virtual ~HikHandle(){}

	void setTime(double tim)
	{
		if(tim == 0) return;
		fprintf(mFile,"\tsetAttr \".tim\" %f;\n", tim);
	}
	void setDefaultMatrix(size_t dm_i,const matrix& dm)
	{
		if(dm == identity) return;
		fprintf(mFile,"\tsetAttr \".dm[%i]\" -type \"matrix\" ",dm_i);
		dm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDefaultMatrix(size_t dm_start,size_t dm_end,matrix* dm)
	{
		fprintf(mFile,"\tsetAttr \".dm[%i:%i]\" ", dm_start,dm_end);
		size_t size = (dm_end-dm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			dm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startDefaultMatrix(size_t dm_start,size_t dm_end)const
	{
		fprintf(mFile,"\tsetAttr \".dm[%i:%i]\"",dm_start,dm_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendDefaultMatrix(const matrix& dm)const
	{
		fprintf(mFile," ");
		dm.write(mFile);
	}
	void endDefaultMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setStancePoseMatrix(size_t sm_i,const matrix& sm)
	{
		if(sm == identity) return;
		fprintf(mFile,"\tsetAttr \".sm[%i]\" -type \"matrix\" ",sm_i);
		sm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStancePoseMatrix(size_t sm_start,size_t sm_end,matrix* sm)
	{
		fprintf(mFile,"\tsetAttr \".sm[%i:%i]\" ", sm_start,sm_end);
		size_t size = (sm_end-sm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startStancePoseMatrix(size_t sm_start,size_t sm_end)const
	{
		fprintf(mFile,"\tsetAttr \".sm[%i:%i]\"",sm_start,sm_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendStancePoseMatrix(const matrix& sm)const
	{
		fprintf(mFile," ");
		sm.write(mFile);
	}
	void endStancePoseMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setUsingMB55Rig(bool m55)
	{
		if(m55 == false) return;
		fprintf(mFile,"\tsetAttr \".m55\" %i;\n", m55);
	}
	void setActivate(bool act)
	{
		if(act == true) return;
		fprintf(mFile,"\tsetAttr \".act\" %i;\n", act);
	}
	void setConvertScale(bool cs)
	{
		if(cs == true) return;
		fprintf(mFile,"\tsetAttr \".cs\" %i;\n", cs);
	}
	void setSolving(const Solving& sol)
	{
		fprintf(mFile,"\tsetAttr \".sol\" ");
		sol.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPostureType(unsigned int pt)
	{
		if(pt == 0) return;
		fprintf(mFile,"\tsetAttr \".sol.pt\" %i;\n", pt);
	}
	void setExpertMode(bool exp)
	{
		if(exp == 0) return;
		fprintf(mFile,"\tsetAttr \".sol.exp\" %i;\n", exp);
	}
	void setRealisticShoulderSolving(float rss)
	{
		if(rss == 0.00) return;
		fprintf(mFile,"\tsetAttr \".sol.rss\" %f;\n", rss);
	}
	void setSolveFingers(bool sf)
	{
		if(sf == 1) return;
		fprintf(mFile,"\tsetAttr \".sol.sf\" %i;\n", sf);
	}
	void setHipTranslationMode(unsigned int htm)
	{
		if(htm == 0) return;
		fprintf(mFile,"\tsetAttr \".sol.htm\" %i;\n", htm);
	}
	void setFloorContacts(const FloorContacts& fc)
	{
		fprintf(mFile,"\tsetAttr \".fc\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHandsFloorContact(bool hfc)
	{
		if(hfc == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.hfc\" %i;\n", hfc);
	}
	void setFeetFloorContact(bool fec)
	{
		if(fec == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.fec\" %i;\n", fec);
	}
	void setFingersFloorContact(bool fic)
	{
		if(fic == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.fic\" %i;\n", fic);
	}
	void setToesFloorContact(bool tfc)
	{
		if(tfc == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.tfc\" %i;\n", tfc);
	}
	void setHandsFloorContactSetup(const HandsFloorContactSetup& flc)
	{
		fprintf(mFile,"\tsetAttr \".flc\" ");
		flc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHandsFloorPivot(unsigned int hfp)
	{
		if(hfp == 0) return;
		fprintf(mFile,"\tsetAttr \".flc.hfp\" %i;\n", hfp);
	}
	void setHandsContactType(unsigned int hct)
	{
		if(hct == 0) return;
		fprintf(mFile,"\tsetAttr \".flc.hct\" %i;\n", hct);
	}
	void setHandsContactStiffness(float hcs)
	{
		if(hcs == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flc.hcs\" %f;\n", hcs);
	}
	void setContactsPosition(const ContactsPosition& cp)
	{
		fprintf(mFile,"\tsetAttr \".cp\" ");
		cp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHandHeight(float hh)
	{
		if(hh == 7.50) return;
		fprintf(mFile,"\tsetAttr \".cp.hh\" %f;\n", hh);
	}
	void setHandBack(float hb)
	{
		if(hb == 4.50) return;
		fprintf(mFile,"\tsetAttr \".cp.hb\" %f;\n", hb);
	}
	void setHandMiddle(float hm)
	{
		if(hm == 13.00) return;
		fprintf(mFile,"\tsetAttr \".cp.hm\" %f;\n", hm);
	}
	void setHandFront(float hf)
	{
		if(hf == 7.00) return;
		fprintf(mFile,"\tsetAttr \".cp.hf\" %f;\n", hf);
	}
	void setHandInSide(float his)
	{
		if(his == 5.00) return;
		fprintf(mFile,"\tsetAttr \".cp.his\" %f;\n", his);
	}
	void setHandOutSide(float hos)
	{
		if(hos == 5.00) return;
		fprintf(mFile,"\tsetAttr \".cp.hos\" %f;\n", hos);
	}
	void setFeetFloorContactSetup(const FeetFloorContactSetup& fle)
	{
		fprintf(mFile,"\tsetAttr \".fle\" ");
		fle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFeetFloorPivot(unsigned int fpv)
	{
		if(fpv == 0) return;
		fprintf(mFile,"\tsetAttr \".fle.fpv\" %i;\n", fpv);
	}
	void setFeetContactType(unsigned int fct)
	{
		if(fct == 0) return;
		fprintf(mFile,"\tsetAttr \".fle.fct\" %i;\n", fct);
	}
	void setFeetContactStiffness(float fcs)
	{
		if(fcs == 0.00) return;
		fprintf(mFile,"\tsetAttr \".fle.fcs\" %f;\n", fcs);
	}
	void setFeetContactPosition(const FeetContactPosition& flf)
	{
		fprintf(mFile,"\tsetAttr \".flf\" ");
		flf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFootHeight(float fh)
	{
		if(fh == 7.50) return;
		fprintf(mFile,"\tsetAttr \".flf.fh\" %f;\n", fh);
	}
	void setFootBack(float fra)
	{
		if(fra == 4.50) return;
		fprintf(mFile,"\tsetAttr \".flf.fra\" %f;\n", fra);
	}
	void setFootMiddle(float fma)
	{
		if(fma == 13.00) return;
		fprintf(mFile,"\tsetAttr \".flf.fma\" %f;\n", fma);
	}
	void setFootFront(float ffm)
	{
		if(ffm == 7.00) return;
		fprintf(mFile,"\tsetAttr \".flf.ffm\" %f;\n", ffm);
	}
	void setFootInSide(float fia)
	{
		if(fia == 5.00) return;
		fprintf(mFile,"\tsetAttr \".flf.fia\" %f;\n", fia);
	}
	void setFootOutSide(float foa)
	{
		if(foa == 5.00) return;
		fprintf(mFile,"\tsetAttr \".flf.foa\" %f;\n", foa);
	}
	void setFingersFloorContactSetup(const FingersFloorContactSetup& flg)
	{
		fprintf(mFile,"\tsetAttr \".flg\" ");
		flg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFingersContactType(unsigned int fcm)
	{
		if(fcm == 1) return;
		fprintf(mFile,"\tsetAttr \".flg.fcm\" %i;\n", fcm);
	}
	void setFingersContactRollStiffness(float hcr)
	{
		if(hcr == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flg.hcr\" %f;\n", hcr);
	}
	void setFingerTipsSizes(const FingerTipsSizes& fts)
	{
		fprintf(mFile,"\tsetAttr \".fts\" ");
		fts.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeftHandThumbTip(float ltt)
	{
		if(ltt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.ltt\" %f;\n", ltt);
	}
	void setLeftHandIndexTip(float lit)
	{
		if(lit == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.lit\" %f;\n", lit);
	}
	void setLeftHandMiddleTip(float lmt)
	{
		if(lmt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.lmt\" %f;\n", lmt);
	}
	void setLeftHandRingTip(float lrt)
	{
		if(lrt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.lrt\" %f;\n", lrt);
	}
	void setLeftHandPinkyTip(float lpt)
	{
		if(lpt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.lpt\" %f;\n", lpt);
	}
	void setLeftHandExtraFingerTip(float lxt)
	{
		if(lxt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.lxt\" %f;\n", lxt);
	}
	void setRightHandThumbTip(float rtt)
	{
		if(rtt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.rtt\" %f;\n", rtt);
	}
	void setRightHandIndexTip(float rit)
	{
		if(rit == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.rit\" %f;\n", rit);
	}
	void setRightHandMiddleTip(float rmt)
	{
		if(rmt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.rmt\" %f;\n", rmt);
	}
	void setRightHandRingTip(float rrt)
	{
		if(rrt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.rrt\" %f;\n", rrt);
	}
	void setRightHandPinkyTip(float rpp)
	{
		if(rpp == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.rpp\" %f;\n", rpp);
	}
	void setRightHandExtraFingerTip(float rxt)
	{
		if(rxt == 0.50) return;
		fprintf(mFile,"\tsetAttr \".fts.rxt\" %f;\n", rxt);
	}
	void setToesFloorContactSetup(const ToesFloorContactSetup& fli)
	{
		fprintf(mFile,"\tsetAttr \".fli\" ");
		fli.write(mFile);
		fprintf(mFile,";\n");
	}
	void setToesContactType(unsigned int tct)
	{
		if(tct == 1) return;
		fprintf(mFile,"\tsetAttr \".fli.tct\" %i;\n", tct);
	}
	void setToesContactRollStiffness(float fcr)
	{
		if(fcr == 0.00) return;
		fprintf(mFile,"\tsetAttr \".fli.fcr\" %f;\n", fcr);
	}
	void setToeTipsSizes(const ToeTipsSizes& flj)
	{
		fprintf(mFile,"\tsetAttr \".flj\" ");
		flj.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeftFootThumbTip(float ttl)
	{
		if(ttl == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.ttl\" %f;\n", ttl);
	}
	void setLeftFootIndexTip(float til)
	{
		if(til == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.til\" %f;\n", til);
	}
	void setLeftFootMiddleTip(float tml)
	{
		if(tml == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.tml\" %f;\n", tml);
	}
	void setLeftFootRingTip(float trl)
	{
		if(trl == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.trl\" %f;\n", trl);
	}
	void setLeftFootPinkyTip(float tpl)
	{
		if(tpl == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.tpl\" %f;\n", tpl);
	}
	void setLeftFootExtraFingerTip(float txl)
	{
		if(txl == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.txl\" %f;\n", txl);
	}
	void setRightFootThumbTip(float ttr)
	{
		if(ttr == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.ttr\" %f;\n", ttr);
	}
	void setRightFootIndexTip(float tir)
	{
		if(tir == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.tir\" %f;\n", tir);
	}
	void setRightFootMiddleTip(float tmr)
	{
		if(tmr == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.tmr\" %f;\n", tmr);
	}
	void setRightFootRingTip(float trr)
	{
		if(trr == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.trr\" %f;\n", trr);
	}
	void setRightFootPinkyTip(float tpr)
	{
		if(tpr == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.tpr\" %f;\n", tpr);
	}
	void setRightFootExtraFingerTip(float txr)
	{
		if(txr == 0.50) return;
		fprintf(mFile,"\tsetAttr \".flj.txr\" %f;\n", txr);
	}
	void setHead(const Head& fll)
	{
		fprintf(mFile,"\tsetAttr \".fll\" ");
		fll.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHeadPull(float phd)
	{
		if(phd == 0.00) return;
		fprintf(mFile,"\tsetAttr \".fll.phd\" %f;\n", phd);
	}
	void setLeftArm(const LeftArm& flm)
	{
		fprintf(mFile,"\tsetAttr \".flm\" ");
		flm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeftElbowPull(float ple)
	{
		if(ple == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flm.ple\" %f;\n", ple);
	}
	void setLeftHandPullChest(float cpl)
	{
		if(cpl == 1.00) return;
		fprintf(mFile,"\tsetAttr \".flm.cpl\" %f;\n", cpl);
	}
	void setLeftHandPullHips(float plh)
	{
		if(plh == 1.00) return;
		fprintf(mFile,"\tsetAttr \".flm.plh\" %f;\n", plh);
	}
	void setLeftFingerBasePull(float plb)
	{
		if(plb == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flm.plb\" %f;\n", plb);
	}
	void setRightArm(const RightArm& fln)
	{
		fprintf(mFile,"\tsetAttr \".fln\" ");
		fln.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRightElbowPull(float pre)
	{
		if(pre == 0.00) return;
		fprintf(mFile,"\tsetAttr \".fln.pre\" %f;\n", pre);
	}
	void setRightHandPullChest(float cpr)
	{
		if(cpr == 1.00) return;
		fprintf(mFile,"\tsetAttr \".fln.cpr\" %f;\n", cpr);
	}
	void setRightHandPullHips(float prh)
	{
		if(prh == 1.00) return;
		fprintf(mFile,"\tsetAttr \".fln.prh\" %f;\n", prh);
	}
	void setRightFingerBasePull(float prb)
	{
		if(prb == 0.00) return;
		fprintf(mFile,"\tsetAttr \".fln.prb\" %f;\n", prb);
	}
	void setChest(const Chest& flo)
	{
		fprintf(mFile,"\tsetAttr \".flo\" ");
		flo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setChestPull(float rcp)
	{
		if(rcp == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flo.rcp\" %f;\n", rcp);
	}
	void setHips(const Hips& flp)
	{
		fprintf(mFile,"\tsetAttr \".flp\" ");
		flp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHipsPull(float chp)
	{
		if(chp == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flp.chp\" %f;\n", chp);
	}
	void setLeftLeg(const LeftLeg& flq)
	{
		fprintf(mFile,"\tsetAttr \".flq\" ");
		flq.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeftKneePull(float plk)
	{
		if(plk == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flq.plk\" %f;\n", plk);
	}
	void setLeftFootPull(float plf)
	{
		if(plf == 1.00) return;
		fprintf(mFile,"\tsetAttr \".flq.plf\" %f;\n", plf);
	}
	void setLeftToeBasePull(float plt)
	{
		if(plt == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flq.plt\" %f;\n", plt);
	}
	void setRightLeg(const RightLeg& flr)
	{
		fprintf(mFile,"\tsetAttr \".flr\" ");
		flr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRightKneePull(float prk)
	{
		if(prk == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flr.prk\" %f;\n", prk);
	}
	void setRightFootPull(float prf)
	{
		if(prf == 1.00) return;
		fprintf(mFile,"\tsetAttr \".flr.prf\" %f;\n", prf);
	}
	void setRightToeBasePull(float prt)
	{
		if(prt == 0.00) return;
		fprintf(mFile,"\tsetAttr \".flr.prt\" %f;\n", prt);
	}
	void setExtra(const Extra& ex)
	{
		fprintf(mFile,"\tsetAttr \".ex\" ");
		ex.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPullIterationCount(float pic)
	{
		if(pic == 10.00) return;
		fprintf(mFile,"\tsetAttr \".ex.pic\" %f;\n", pic);
	}
	void setStiffness(const Stiffness& st)
	{
		fprintf(mFile,"\tsetAttr \".st\" ");
		st.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNeckStiffness(float nst)
	{
		if(nst == 0.00) return;
		fprintf(mFile,"\tsetAttr \".st.nst\" %f;\n", nst);
	}
	void setLeftShoulderStiffness(float rlco)
	{
		if(rlco == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.rlco\" %f;\n", rlco);
	}
	void setLeftArmStiffness(float rle)
	{
		if(rle == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.rle\" %f;\n", rle);
	}
	void setLeftElbowMaxExtension(float mle)
	{
		if(mle == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.mle\" %f;\n", mle);
	}
	void setLeftElbowCompressionFactor(float cle)
	{
		if(cle == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.cle\" %f;\n", cle);
	}
	void setRightShoulderStiffness(float rrc)
	{
		if(rrc == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.rrc\" %f;\n", rrc);
	}
	void setRightArmStiffness(float rre)
	{
		if(rre == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.rre\" %f;\n", rre);
	}
	void setRightElbowMaxExtension(float mre)
	{
		if(mre == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.mre\" %f;\n", mre);
	}
	void setRightElbowCompressionFactor(float cre)
	{
		if(cre == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.cre\" %f;\n", cre);
	}
	void setHipsEnforceGravity(float egr)
	{
		if(egr == 0.60) return;
		fprintf(mFile,"\tsetAttr \".st.egr\" %f;\n", egr);
	}
	void setChestStiffness(float rco)
	{
		if(rco == 0.00) return;
		fprintf(mFile,"\tsetAttr \".st.rco\" %f;\n", rco);
	}
	void setSpineStiffness(float sst)
	{
		if(sst == 0.00) return;
		fprintf(mFile,"\tsetAttr \".st.sst\" %f;\n", sst);
	}
	void setHipsStiffness(float rho)
	{
		if(rho == 0.00) return;
		fprintf(mFile,"\tsetAttr \".st.rho\" %f;\n", rho);
	}
	void setLeftKneeMaxExtension(float mlk)
	{
		if(mlk == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.mlk\" %f;\n", mlk);
	}
	void setLeftLegStiffness(float rlk)
	{
		if(rlk == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.rlk\" %f;\n", rlk);
	}
	void setLeftKneeCompressionFactor(float clk)
	{
		if(clk == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.clk\" %f;\n", clk);
	}
	void setRightLegStiffness(float rrk)
	{
		if(rrk == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.rrk\" %f;\n", rrk);
	}
	void setRightKneeMaxExtension(float mrk)
	{
		if(mrk == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.mrk\" %f;\n", mrk);
	}
	void setRightKneeCompressionFactor(float crk)
	{
		if(crk == 0.50) return;
		fprintf(mFile,"\tsetAttr \".st.crk\" %f;\n", crk);
	}
	void setKillPitch(const KillPitch& kp)
	{
		fprintf(mFile,"\tsetAttr \".kp\" ");
		kp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeftElbowKillPitch(bool lek)
	{
		if(lek == 0) return;
		fprintf(mFile,"\tsetAttr \".kp.lek\" %i;\n", lek);
	}
	void setRightElbowKillPitch(bool rek)
	{
		if(rek == 0) return;
		fprintf(mFile,"\tsetAttr \".kp.rek\" %i;\n", rek);
	}
	void setLeftKneeKillPitch(bool lkk)
	{
		if(lkk == 0) return;
		fprintf(mFile,"\tsetAttr \".kp.lkk\" %i;\n", lkk);
	}
	void setRightKneeKillPitch(bool rkk)
	{
		if(rkk == 0) return;
		fprintf(mFile,"\tsetAttr \".kp.rkk\" %i;\n", rkk);
	}
	void setRollExtraction(const RollExtraction& re)
	{
		fprintf(mFile,"\tsetAttr \".re\" ");
		re.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRollExtractionMode(unsigned int rem)
	{
		if(rem == 0) return;
		fprintf(mFile,"\tsetAttr \".re.rem\" %i;\n", rem);
	}
	void setLeftArmRollMode(bool larm)
	{
		if(larm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.larm\" %i;\n", larm);
	}
	void setLeftArmRoll(float lar)
	{
		if(lar == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.lar\" %f;\n", lar);
	}
	void setLeftForeArmRollMode(bool lfrm)
	{
		if(lfrm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.lfrm\" %i;\n", lfrm);
	}
	void setLeftForeArmRoll(float lfr)
	{
		if(lfr == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.lfr\" %f;\n", lfr);
	}
	void setRightArmRollMode(bool rarm)
	{
		if(rarm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.rarm\" %i;\n", rarm);
	}
	void setRightArmRoll(float rar)
	{
		if(rar == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.rar\" %f;\n", rar);
	}
	void setRightForeArmRollMode(bool rfrm)
	{
		if(rfrm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.rfrm\" %i;\n", rfrm);
	}
	void setRightForeArmRoll(float rfr)
	{
		if(rfr == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.rfr\" %f;\n", rfr);
	}
	void setLeftUpLegRollMode(bool lurm)
	{
		if(lurm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.lurm\" %i;\n", lurm);
	}
	void setLeftUpLegRoll(float lur)
	{
		if(lur == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.lur\" %f;\n", lur);
	}
	void setLeftLegRollMode(bool llrm)
	{
		if(llrm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.llrm\" %i;\n", llrm);
	}
	void setLeftLegRoll(float llr)
	{
		if(llr == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.llr\" %f;\n", llr);
	}
	void setRightUpLegRollMode(bool rurm)
	{
		if(rurm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.rurm\" %i;\n", rurm);
	}
	void setRightUpLegRoll(float rur)
	{
		if(rur == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.rur\" %f;\n", rur);
	}
	void setRightLegRollMode(bool rlrm)
	{
		if(rlrm == 0) return;
		fprintf(mFile,"\tsetAttr \".re.rlrm\" %i;\n", rlrm);
	}
	void setRightLegRoll(float rlro)
	{
		if(rlro == 0.60) return;
		fprintf(mFile,"\tsetAttr \".re.rlro\" %f;\n", rlro);
	}
	void getEffectors(size_t eff_i)const
	{
		fprintf(mFile,"\"%s.eff[%i]\"",mName.c_str(),eff_i);
	}
	void getEffectors()const
	{

		fprintf(mFile,"\"%s.eff\"",mName.c_str());
	}
	void getLeftFootGroundPlane()const
	{
		fprintf(mFile,"\"%s.lfg\"",mName.c_str());
	}
	void getRightFootGroundPlane()const
	{
		fprintf(mFile,"\"%s.rfg\"",mName.c_str());
	}
	void getRightFootOrientedGroundPlane()const
	{
		fprintf(mFile,"\"%s.rog\"",mName.c_str());
	}
	void getLeftFootOrientedGroundPlane()const
	{
		fprintf(mFile,"\"%s.log\"",mName.c_str());
	}
	void getLeftHandGroundPlane()const
	{
		fprintf(mFile,"\"%s.lhg\"",mName.c_str());
	}
	void getRightHandGroundPlane()const
	{
		fprintf(mFile,"\"%s.rhg\"",mName.c_str());
	}
	void getLeftHandOrientedGroundPlane()const
	{
		fprintf(mFile,"\"%s.loh\"",mName.c_str());
	}
	void getRightHandOrientedGroundPlane()const
	{
		fprintf(mFile,"\"%s.roh\"",mName.c_str());
	}
	void getJoints(size_t jt_i)const
	{
		fprintf(mFile,"\"%s.jt[%i]\"",mName.c_str(),jt_i);
	}
	void getJoints()const
	{

		fprintf(mFile,"\"%s.jt\"",mName.c_str());
	}
	void getFkjoints(size_t fj_i)const
	{
		fprintf(mFile,"\"%s.fj[%i]\"",mName.c_str(),fj_i);
	}
	void getFkjoints()const
	{

		fprintf(mFile,"\"%s.fj\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
	void getDefaultMatrix(size_t dm_i)const
	{
		fprintf(mFile,"\"%s.dm[%i]\"",mName.c_str(),dm_i);
	}
	void getDefaultMatrix()const
	{

		fprintf(mFile,"\"%s.dm\"",mName.c_str());
	}
	void getStancePoseMatrix(size_t sm_i)const
	{
		fprintf(mFile,"\"%s.sm[%i]\"",mName.c_str(),sm_i);
	}
	void getStancePoseMatrix()const
	{

		fprintf(mFile,"\"%s.sm\"",mName.c_str());
	}
	void getUsingMB55Rig()const
	{
		fprintf(mFile,"\"%s.m55\"",mName.c_str());
	}
	void getActivate()const
	{
		fprintf(mFile,"\"%s.act\"",mName.c_str());
	}
	void getConvertScale()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getPropertyChanged()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getSolving()const
	{
		fprintf(mFile,"\"%s.sol\"",mName.c_str());
	}
	void getPostureType()const
	{
		fprintf(mFile,"\"%s.sol.pt\"",mName.c_str());
	}
	void getExpertMode()const
	{
		fprintf(mFile,"\"%s.sol.exp\"",mName.c_str());
	}
	void getRealisticShoulderSolving()const
	{
		fprintf(mFile,"\"%s.sol.rss\"",mName.c_str());
	}
	void getSolveFingers()const
	{
		fprintf(mFile,"\"%s.sol.sf\"",mName.c_str());
	}
	void getHipTranslationMode()const
	{
		fprintf(mFile,"\"%s.sol.htm\"",mName.c_str());
	}
	void getFloorContacts()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getHandsFloorContact()const
	{
		fprintf(mFile,"\"%s.fc.hfc\"",mName.c_str());
	}
	void getFeetFloorContact()const
	{
		fprintf(mFile,"\"%s.fc.fec\"",mName.c_str());
	}
	void getFingersFloorContact()const
	{
		fprintf(mFile,"\"%s.fc.fic\"",mName.c_str());
	}
	void getToesFloorContact()const
	{
		fprintf(mFile,"\"%s.fc.tfc\"",mName.c_str());
	}
	void getHandsFloorContactSetup()const
	{
		fprintf(mFile,"\"%s.flc\"",mName.c_str());
	}
	void getHandsFloorPivot()const
	{
		fprintf(mFile,"\"%s.flc.hfp\"",mName.c_str());
	}
	void getHandsContactType()const
	{
		fprintf(mFile,"\"%s.flc.hct\"",mName.c_str());
	}
	void getHandsContactStiffness()const
	{
		fprintf(mFile,"\"%s.flc.hcs\"",mName.c_str());
	}
	void getContactsPosition()const
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());
	}
	void getHandHeight()const
	{
		fprintf(mFile,"\"%s.cp.hh\"",mName.c_str());
	}
	void getHandBack()const
	{
		fprintf(mFile,"\"%s.cp.hb\"",mName.c_str());
	}
	void getHandMiddle()const
	{
		fprintf(mFile,"\"%s.cp.hm\"",mName.c_str());
	}
	void getHandFront()const
	{
		fprintf(mFile,"\"%s.cp.hf\"",mName.c_str());
	}
	void getHandInSide()const
	{
		fprintf(mFile,"\"%s.cp.his\"",mName.c_str());
	}
	void getHandOutSide()const
	{
		fprintf(mFile,"\"%s.cp.hos\"",mName.c_str());
	}
	void getFeetFloorContactSetup()const
	{
		fprintf(mFile,"\"%s.fle\"",mName.c_str());
	}
	void getFeetFloorPivot()const
	{
		fprintf(mFile,"\"%s.fle.fpv\"",mName.c_str());
	}
	void getFeetContactType()const
	{
		fprintf(mFile,"\"%s.fle.fct\"",mName.c_str());
	}
	void getFeetContactStiffness()const
	{
		fprintf(mFile,"\"%s.fle.fcs\"",mName.c_str());
	}
	void getFeetContactPosition()const
	{
		fprintf(mFile,"\"%s.flf\"",mName.c_str());
	}
	void getFootHeight()const
	{
		fprintf(mFile,"\"%s.flf.fh\"",mName.c_str());
	}
	void getFootBack()const
	{
		fprintf(mFile,"\"%s.flf.fra\"",mName.c_str());
	}
	void getFootMiddle()const
	{
		fprintf(mFile,"\"%s.flf.fma\"",mName.c_str());
	}
	void getFootFront()const
	{
		fprintf(mFile,"\"%s.flf.ffm\"",mName.c_str());
	}
	void getFootInSide()const
	{
		fprintf(mFile,"\"%s.flf.fia\"",mName.c_str());
	}
	void getFootOutSide()const
	{
		fprintf(mFile,"\"%s.flf.foa\"",mName.c_str());
	}
	void getFingersFloorContactSetup()const
	{
		fprintf(mFile,"\"%s.flg\"",mName.c_str());
	}
	void getFingersContactType()const
	{
		fprintf(mFile,"\"%s.flg.fcm\"",mName.c_str());
	}
	void getFingersContactRollStiffness()const
	{
		fprintf(mFile,"\"%s.flg.hcr\"",mName.c_str());
	}
	void getFingerTipsSizes()const
	{
		fprintf(mFile,"\"%s.fts\"",mName.c_str());
	}
	void getLeftHandThumbTip()const
	{
		fprintf(mFile,"\"%s.fts.ltt\"",mName.c_str());
	}
	void getLeftHandIndexTip()const
	{
		fprintf(mFile,"\"%s.fts.lit\"",mName.c_str());
	}
	void getLeftHandMiddleTip()const
	{
		fprintf(mFile,"\"%s.fts.lmt\"",mName.c_str());
	}
	void getLeftHandRingTip()const
	{
		fprintf(mFile,"\"%s.fts.lrt\"",mName.c_str());
	}
	void getLeftHandPinkyTip()const
	{
		fprintf(mFile,"\"%s.fts.lpt\"",mName.c_str());
	}
	void getLeftHandExtraFingerTip()const
	{
		fprintf(mFile,"\"%s.fts.lxt\"",mName.c_str());
	}
	void getRightHandThumbTip()const
	{
		fprintf(mFile,"\"%s.fts.rtt\"",mName.c_str());
	}
	void getRightHandIndexTip()const
	{
		fprintf(mFile,"\"%s.fts.rit\"",mName.c_str());
	}
	void getRightHandMiddleTip()const
	{
		fprintf(mFile,"\"%s.fts.rmt\"",mName.c_str());
	}
	void getRightHandRingTip()const
	{
		fprintf(mFile,"\"%s.fts.rrt\"",mName.c_str());
	}
	void getRightHandPinkyTip()const
	{
		fprintf(mFile,"\"%s.fts.rpp\"",mName.c_str());
	}
	void getRightHandExtraFingerTip()const
	{
		fprintf(mFile,"\"%s.fts.rxt\"",mName.c_str());
	}
	void getToesFloorContactSetup()const
	{
		fprintf(mFile,"\"%s.fli\"",mName.c_str());
	}
	void getToesContactType()const
	{
		fprintf(mFile,"\"%s.fli.tct\"",mName.c_str());
	}
	void getToesContactRollStiffness()const
	{
		fprintf(mFile,"\"%s.fli.fcr\"",mName.c_str());
	}
	void getToeTipsSizes()const
	{
		fprintf(mFile,"\"%s.flj\"",mName.c_str());
	}
	void getLeftFootThumbTip()const
	{
		fprintf(mFile,"\"%s.flj.ttl\"",mName.c_str());
	}
	void getLeftFootIndexTip()const
	{
		fprintf(mFile,"\"%s.flj.til\"",mName.c_str());
	}
	void getLeftFootMiddleTip()const
	{
		fprintf(mFile,"\"%s.flj.tml\"",mName.c_str());
	}
	void getLeftFootRingTip()const
	{
		fprintf(mFile,"\"%s.flj.trl\"",mName.c_str());
	}
	void getLeftFootPinkyTip()const
	{
		fprintf(mFile,"\"%s.flj.tpl\"",mName.c_str());
	}
	void getLeftFootExtraFingerTip()const
	{
		fprintf(mFile,"\"%s.flj.txl\"",mName.c_str());
	}
	void getRightFootThumbTip()const
	{
		fprintf(mFile,"\"%s.flj.ttr\"",mName.c_str());
	}
	void getRightFootIndexTip()const
	{
		fprintf(mFile,"\"%s.flj.tir\"",mName.c_str());
	}
	void getRightFootMiddleTip()const
	{
		fprintf(mFile,"\"%s.flj.tmr\"",mName.c_str());
	}
	void getRightFootRingTip()const
	{
		fprintf(mFile,"\"%s.flj.trr\"",mName.c_str());
	}
	void getRightFootPinkyTip()const
	{
		fprintf(mFile,"\"%s.flj.tpr\"",mName.c_str());
	}
	void getRightFootExtraFingerTip()const
	{
		fprintf(mFile,"\"%s.flj.txr\"",mName.c_str());
	}
	void getHead()const
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());
	}
	void getHeadPull()const
	{
		fprintf(mFile,"\"%s.fll.phd\"",mName.c_str());
	}
	void getLeftArm()const
	{
		fprintf(mFile,"\"%s.flm\"",mName.c_str());
	}
	void getLeftElbowPull()const
	{
		fprintf(mFile,"\"%s.flm.ple\"",mName.c_str());
	}
	void getLeftHandPullChest()const
	{
		fprintf(mFile,"\"%s.flm.cpl\"",mName.c_str());
	}
	void getLeftHandPullHips()const
	{
		fprintf(mFile,"\"%s.flm.plh\"",mName.c_str());
	}
	void getLeftFingerBasePull()const
	{
		fprintf(mFile,"\"%s.flm.plb\"",mName.c_str());
	}
	void getRightArm()const
	{
		fprintf(mFile,"\"%s.fln\"",mName.c_str());
	}
	void getRightElbowPull()const
	{
		fprintf(mFile,"\"%s.fln.pre\"",mName.c_str());
	}
	void getRightHandPullChest()const
	{
		fprintf(mFile,"\"%s.fln.cpr\"",mName.c_str());
	}
	void getRightHandPullHips()const
	{
		fprintf(mFile,"\"%s.fln.prh\"",mName.c_str());
	}
	void getRightFingerBasePull()const
	{
		fprintf(mFile,"\"%s.fln.prb\"",mName.c_str());
	}
	void getChest()const
	{
		fprintf(mFile,"\"%s.flo\"",mName.c_str());
	}
	void getChestPull()const
	{
		fprintf(mFile,"\"%s.flo.rcp\"",mName.c_str());
	}
	void getHips()const
	{
		fprintf(mFile,"\"%s.flp\"",mName.c_str());
	}
	void getHipsPull()const
	{
		fprintf(mFile,"\"%s.flp.chp\"",mName.c_str());
	}
	void getLeftLeg()const
	{
		fprintf(mFile,"\"%s.flq\"",mName.c_str());
	}
	void getLeftKneePull()const
	{
		fprintf(mFile,"\"%s.flq.plk\"",mName.c_str());
	}
	void getLeftFootPull()const
	{
		fprintf(mFile,"\"%s.flq.plf\"",mName.c_str());
	}
	void getLeftToeBasePull()const
	{
		fprintf(mFile,"\"%s.flq.plt\"",mName.c_str());
	}
	void getRightLeg()const
	{
		fprintf(mFile,"\"%s.flr\"",mName.c_str());
	}
	void getRightKneePull()const
	{
		fprintf(mFile,"\"%s.flr.prk\"",mName.c_str());
	}
	void getRightFootPull()const
	{
		fprintf(mFile,"\"%s.flr.prf\"",mName.c_str());
	}
	void getRightToeBasePull()const
	{
		fprintf(mFile,"\"%s.flr.prt\"",mName.c_str());
	}
	void getExtra()const
	{
		fprintf(mFile,"\"%s.ex\"",mName.c_str());
	}
	void getPullIterationCount()const
	{
		fprintf(mFile,"\"%s.ex.pic\"",mName.c_str());
	}
	void getStiffness()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getNeckStiffness()const
	{
		fprintf(mFile,"\"%s.st.nst\"",mName.c_str());
	}
	void getLeftShoulderStiffness()const
	{
		fprintf(mFile,"\"%s.st.rlco\"",mName.c_str());
	}
	void getLeftArmStiffness()const
	{
		fprintf(mFile,"\"%s.st.rle\"",mName.c_str());
	}
	void getLeftElbowMaxExtension()const
	{
		fprintf(mFile,"\"%s.st.mle\"",mName.c_str());
	}
	void getLeftElbowCompressionFactor()const
	{
		fprintf(mFile,"\"%s.st.cle\"",mName.c_str());
	}
	void getRightShoulderStiffness()const
	{
		fprintf(mFile,"\"%s.st.rrc\"",mName.c_str());
	}
	void getRightArmStiffness()const
	{
		fprintf(mFile,"\"%s.st.rre\"",mName.c_str());
	}
	void getRightElbowMaxExtension()const
	{
		fprintf(mFile,"\"%s.st.mre\"",mName.c_str());
	}
	void getRightElbowCompressionFactor()const
	{
		fprintf(mFile,"\"%s.st.cre\"",mName.c_str());
	}
	void getHipsEnforceGravity()const
	{
		fprintf(mFile,"\"%s.st.egr\"",mName.c_str());
	}
	void getChestStiffness()const
	{
		fprintf(mFile,"\"%s.st.rco\"",mName.c_str());
	}
	void getSpineStiffness()const
	{
		fprintf(mFile,"\"%s.st.sst\"",mName.c_str());
	}
	void getHipsStiffness()const
	{
		fprintf(mFile,"\"%s.st.rho\"",mName.c_str());
	}
	void getLeftKneeMaxExtension()const
	{
		fprintf(mFile,"\"%s.st.mlk\"",mName.c_str());
	}
	void getLeftLegStiffness()const
	{
		fprintf(mFile,"\"%s.st.rlk\"",mName.c_str());
	}
	void getLeftKneeCompressionFactor()const
	{
		fprintf(mFile,"\"%s.st.clk\"",mName.c_str());
	}
	void getRightLegStiffness()const
	{
		fprintf(mFile,"\"%s.st.rrk\"",mName.c_str());
	}
	void getRightKneeMaxExtension()const
	{
		fprintf(mFile,"\"%s.st.mrk\"",mName.c_str());
	}
	void getRightKneeCompressionFactor()const
	{
		fprintf(mFile,"\"%s.st.crk\"",mName.c_str());
	}
	void getKillPitch()const
	{
		fprintf(mFile,"\"%s.kp\"",mName.c_str());
	}
	void getLeftElbowKillPitch()const
	{
		fprintf(mFile,"\"%s.kp.lek\"",mName.c_str());
	}
	void getRightElbowKillPitch()const
	{
		fprintf(mFile,"\"%s.kp.rek\"",mName.c_str());
	}
	void getLeftKneeKillPitch()const
	{
		fprintf(mFile,"\"%s.kp.lkk\"",mName.c_str());
	}
	void getRightKneeKillPitch()const
	{
		fprintf(mFile,"\"%s.kp.rkk\"",mName.c_str());
	}
	void getRollExtraction()const
	{
		fprintf(mFile,"\"%s.re\"",mName.c_str());
	}
	void getRollExtractionMode()const
	{
		fprintf(mFile,"\"%s.re.rem\"",mName.c_str());
	}
	void getLeftArmRollMode()const
	{
		fprintf(mFile,"\"%s.re.larm\"",mName.c_str());
	}
	void getLeftArmRoll()const
	{
		fprintf(mFile,"\"%s.re.lar\"",mName.c_str());
	}
	void getLeftForeArmRollMode()const
	{
		fprintf(mFile,"\"%s.re.lfrm\"",mName.c_str());
	}
	void getLeftForeArmRoll()const
	{
		fprintf(mFile,"\"%s.re.lfr\"",mName.c_str());
	}
	void getRightArmRollMode()const
	{
		fprintf(mFile,"\"%s.re.rarm\"",mName.c_str());
	}
	void getRightArmRoll()const
	{
		fprintf(mFile,"\"%s.re.rar\"",mName.c_str());
	}
	void getRightForeArmRollMode()const
	{
		fprintf(mFile,"\"%s.re.rfrm\"",mName.c_str());
	}
	void getRightForeArmRoll()const
	{
		fprintf(mFile,"\"%s.re.rfr\"",mName.c_str());
	}
	void getLeftUpLegRollMode()const
	{
		fprintf(mFile,"\"%s.re.lurm\"",mName.c_str());
	}
	void getLeftUpLegRoll()const
	{
		fprintf(mFile,"\"%s.re.lur\"",mName.c_str());
	}
	void getLeftLegRollMode()const
	{
		fprintf(mFile,"\"%s.re.llrm\"",mName.c_str());
	}
	void getLeftLegRoll()const
	{
		fprintf(mFile,"\"%s.re.llr\"",mName.c_str());
	}
	void getRightUpLegRollMode()const
	{
		fprintf(mFile,"\"%s.re.rurm\"",mName.c_str());
	}
	void getRightUpLegRoll()const
	{
		fprintf(mFile,"\"%s.re.rur\"",mName.c_str());
	}
	void getRightLegRollMode()const
	{
		fprintf(mFile,"\"%s.re.rlrm\"",mName.c_str());
	}
	void getRightLegRoll()const
	{
		fprintf(mFile,"\"%s.re.rlro\"",mName.c_str());
	}
protected:
	HikHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:IkHandle(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HIKHANDLE_H__
