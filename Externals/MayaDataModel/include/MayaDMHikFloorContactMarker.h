/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKFLOORCONTACTMARKER_H__
#define __MayaDM_HIKFLOORCONTACTMARKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
/*
<p><pre>
 The hikFloorContactMarker node is a holder node for the Human IK floor contact parameters.

</pre></p>
*/
class HikFloorContactMarker : public Locator
{
public:
	/*Folder for Floor Contacts controls*/
	struct FloorContacts{
		bool drawHandContact;
		bool handsContact;
		bool drawFeetContact;
		bool feetContact;
		bool fingersContact;
		bool toesContact;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", drawHandContact);
			fprintf_s(file,"%i ", handsContact);
			fprintf_s(file,"%i ", drawFeetContact);
			fprintf_s(file,"%i ", feetContact);
			fprintf_s(file,"%i ", fingersContact);
			fprintf_s(file,"%i", toesContact);
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
public:
	HikFloorContactMarker(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "hikFloorContactMarker"){}
	virtual ~HikFloorContactMarker(){}
	/*Size to draw the contact markers.*/
	void setMarkerSize(double msz){if(msz == 1.0) return; fprintf_s(mFile, "setAttr \".msz\" %f;\n", msz);}
	/*Size to draw the contact markers.*/
	void setMarkerSize(const DoubleID& msz){fprintf_s(mFile,"connectAttr \"");msz.write(mFile);fprintf_s(mFile,"\" \"%s.msz\";\n",mName.c_str());}
	/*Folder for Floor Contacts controls*/
	void setFloorContacts(const FloorContacts& fc){fprintf_s(mFile, "setAttr \".fc\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*Folder for Floor Contacts controls*/
	void setFloorContacts(const FloorContactsID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*
	The hand contact markers are drawn when this attribute is true
	and handsContact is enabled.
	*/
	void setDrawHandContact(bool dhc){if(dhc == 1) return; fprintf_s(mFile, "setAttr \".fc.dhc\" %i;\n", dhc);}
	/*
	The hand contact markers are drawn when this attribute is true
	and handsContact is enabled.
	*/
	void setDrawHandContact(const BoolID& dhc){fprintf_s(mFile,"connectAttr \"");dhc.write(mFile);fprintf_s(mFile,"\" \"%s.fc.dhc\";\n",mName.c_str());}
	/*When enabled, prevents the hands from going through the floor.*/
	void setHandsContact(bool hfc){if(hfc == 0) return; fprintf_s(mFile, "setAttr \".fc.hfc\" %i;\n", hfc);}
	/*When enabled, prevents the hands from going through the floor.*/
	void setHandsContact(const BoolID& hfc){fprintf_s(mFile,"connectAttr \"");hfc.write(mFile);fprintf_s(mFile,"\" \"%s.fc.hfc\";\n",mName.c_str());}
	/*
	The feet contact markers are drawn when this attribute is true
	and feetContact is enabled.
	*/
	void setDrawFeetContact(bool dfc){if(dfc == 1) return; fprintf_s(mFile, "setAttr \".fc.dfc\" %i;\n", dfc);}
	/*
	The feet contact markers are drawn when this attribute is true
	and feetContact is enabled.
	*/
	void setDrawFeetContact(const BoolID& dfc){fprintf_s(mFile,"connectAttr \"");dfc.write(mFile);fprintf_s(mFile,"\" \"%s.fc.dfc\";\n",mName.c_str());}
	/*When enabled, prevents the feet from going through the floor.*/
	void setFeetContact(bool fec){if(fec == 0) return; fprintf_s(mFile, "setAttr \".fc.fec\" %i;\n", fec);}
	/*When enabled, prevents the feet from going through the floor.*/
	void setFeetContact(const BoolID& fec){fprintf_s(mFile,"connectAttr \"");fec.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fec\";\n",mName.c_str());}
	/*When enabled, prevents the fingers from going through the floor.*/
	void setFingersContact(bool fic){if(fic == 0) return; fprintf_s(mFile, "setAttr \".fc.fic\" %i;\n", fic);}
	/*When enabled, prevents the fingers from going through the floor.*/
	void setFingersContact(const BoolID& fic){fprintf_s(mFile,"connectAttr \"");fic.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fic\";\n",mName.c_str());}
	/*When enabled, prevents the toes from going through the floor.*/
	void setToesContact(bool tfc){if(tfc == 0) return; fprintf_s(mFile, "setAttr \".fc.tfc\" %i;\n", tfc);}
	/*When enabled, prevents the toes from going through the floor.*/
	void setToesContact(const BoolID& tfc){fprintf_s(mFile,"connectAttr \"");tfc.write(mFile);fprintf_s(mFile,"\" \"%s.fc.tfc\";\n",mName.c_str());}
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
	In "finger base" contact, four points define each contact. The hand floor
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
	In "finger base" contact, four points define each contact. The hand floor
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
	/*Define the location of the  pivot point for the feet when applying floor contact.*/
	void setFeetFloorPivot(unsigned int fpv){if(fpv == 0) return; fprintf_s(mFile, "setAttr \".fle.fpv\" %i;\n", fpv);}
	/*Define the location of the  pivot point for the feet when applying floor contact.*/
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
	/*
	Corrects unusual finger rotation when finger floor contact markers
	touch the floor.
	*/
	void setFingersContactRollStiffness(float hcr){if(hcr == 0.00) return; fprintf_s(mFile, "setAttr \".flg.hcr\" %f;\n", hcr);}
	/*
	Corrects unusual finger rotation when finger floor contact markers
	touch the floor.
	*/
	void setFingersContactRollStiffness(const FloatID& hcr){fprintf_s(mFile,"connectAttr \"");hcr.write(mFile);fprintf_s(mFile,"\" \"%s.flg.hcr\";\n",mName.c_str());}
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
	/*
	Corrects unusual toe rotation when toe floor contact markers
	touch the floor.
	*/
	void setToesContactRollStiffness(float fcr){if(fcr == 0.00) return; fprintf_s(mFile, "setAttr \".fli.fcr\" %f;\n", fcr);}
	/*
	Corrects unusual toe rotation when toe floor contact markers
	touch the floor.
	*/
	void setToesContactRollStiffness(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fli.fcr\";\n",mName.c_str());}
	/*Size to draw the contact markers.*/
	DoubleID getMarkerSize(){char buffer[4096];sprintf_s (buffer, "%s.msz",mName.c_str());return (const char*)buffer;}
	/*Folder for Floor Contacts controls*/
	FloorContactsID getFloorContacts(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*
	The hand contact markers are drawn when this attribute is true
	and handsContact is enabled.
	*/
	BoolID getDrawHandContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.dhc",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the hands from going through the floor.*/
	BoolID getHandsContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.hfc",mName.c_str());return (const char*)buffer;}
	/*
	The feet contact markers are drawn when this attribute is true
	and feetContact is enabled.
	*/
	BoolID getDrawFeetContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.dfc",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the feet from going through the floor.*/
	BoolID getFeetContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.fec",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the fingers from going through the floor.*/
	BoolID getFingersContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.fic",mName.c_str());return (const char*)buffer;}
	/*When enabled, prevents the toes from going through the floor.*/
	BoolID getToesContact(){char buffer[4096];sprintf_s (buffer, "%s.fc.tfc",mName.c_str());return (const char*)buffer;}
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
	In "finger base" contact, four points define each contact. The hand floor
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
	/*Define the location of the  pivot point for the feet when applying floor contact.*/
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
	/*
	Corrects unusual finger rotation when finger floor contact markers
	touch the floor.
	*/
	FloatID getFingersContactRollStiffness(){char buffer[4096];sprintf_s (buffer, "%s.flg.hcr",mName.c_str());return (const char*)buffer;}
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
	/*
	Corrects unusual toe rotation when toe floor contact markers
	touch the floor.
	*/
	FloatID getToesContactRollStiffness(){char buffer[4096];sprintf_s (buffer, "%s.fli.fcr",mName.c_str());return (const char*)buffer;}
protected:
	HikFloorContactMarker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Locator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HIKFLOORCONTACTMARKER_H__
