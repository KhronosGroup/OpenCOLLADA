/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class HikFloorContactMarker : public Locator
{
public:
	struct FloorContacts{
		bool drawHandContact;
		bool handsContact;
		bool drawFeetContact;
		bool feetContact;
		bool fingersContact;
		bool toesContact;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", drawHandContact);
			fprintf(file,"%i ", handsContact);
			fprintf(file,"%i ", drawFeetContact);
			fprintf(file,"%i ", feetContact);
			fprintf(file,"%i ", fingersContact);
			fprintf(file,"%i", toesContact);
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
	struct ToesFloorContactSetup{
		unsigned int toesContactType;
		float toesContactRollStiffness;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", toesContactType);
			fprintf(file,"%f", toesContactRollStiffness);
		}
	};
public:

	HikFloorContactMarker():Locator(){}
	HikFloorContactMarker(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Locator(file, name, parent, "hikFloorContactMarker", shared, create){}
	virtual ~HikFloorContactMarker(){}

	void setMarkerSize(double msz)
	{
		if(msz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".msz\" %f;\n", msz);
	}
	void setFloorContacts(const FloorContacts& fc)
	{
		fprintf(mFile,"\tsetAttr \".fc\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDrawHandContact(bool dhc)
	{
		if(dhc == 1) return;
		fprintf(mFile,"\tsetAttr \".fc.dhc\" %i;\n", dhc);
	}
	void setHandsContact(bool hfc)
	{
		if(hfc == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.hfc\" %i;\n", hfc);
	}
	void setDrawFeetContact(bool dfc)
	{
		if(dfc == 1) return;
		fprintf(mFile,"\tsetAttr \".fc.dfc\" %i;\n", dfc);
	}
	void setFeetContact(bool fec)
	{
		if(fec == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.fec\" %i;\n", fec);
	}
	void setFingersContact(bool fic)
	{
		if(fic == 0) return;
		fprintf(mFile,"\tsetAttr \".fc.fic\" %i;\n", fic);
	}
	void setToesContact(bool tfc)
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
	void getMarkerSize()const
	{
		fprintf(mFile,"\"%s.msz\"",mName.c_str());
	}
	void getFloorContacts()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getDrawHandContact()const
	{
		fprintf(mFile,"\"%s.fc.dhc\"",mName.c_str());
	}
	void getHandsContact()const
	{
		fprintf(mFile,"\"%s.fc.hfc\"",mName.c_str());
	}
	void getDrawFeetContact()const
	{
		fprintf(mFile,"\"%s.fc.dfc\"",mName.c_str());
	}
	void getFeetContact()const
	{
		fprintf(mFile,"\"%s.fc.fec\"",mName.c_str());
	}
	void getFingersContact()const
	{
		fprintf(mFile,"\"%s.fc.fic\"",mName.c_str());
	}
	void getToesContact()const
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
protected:
	HikFloorContactMarker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Locator(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HIKFLOORCONTACTMARKER_H__
