/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FOURBYFOURMATRIX_H__
#define __MayaDM_FOURBYFOURMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node outputs a 4x4 matrix based on 16 input values.  This
        output matrix attribute can be connected to any attribute that
        is type "matrix".<p/>
  The first row of the matrix is defined by in00, in01, in02, in03.<br/>
  The 2nd row of the matrix is defined by in10, in11, in12, in13.<br/>
  The 3rd row of the matrix is defined by in20, in21, in22, in23.<br/>
  The 4th row of the matrix is defined by in30, in31, in32, in33.
*/
class FourByFourMatrix : public DependNode
{
public:
public:
	FourByFourMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "fourByFourMatrix"){}
	virtual ~FourByFourMatrix(){}
	/*matrix[0][0]*/
	void setIn00(double i00){if(i00 == 1.0) return; fprintf_s(mFile, "setAttr \".i00\" %f;\n", i00);}
	/*matrix[0][0]*/
	void setIn00(const DoubleID& i00){fprintf_s(mFile,"connectAttr \"");i00.write(mFile);fprintf_s(mFile,"\" \"%s.i00\";\n",mName.c_str());}
	/*matrix[0][1]*/
	void setIn01(double i01){if(i01 == 0.0) return; fprintf_s(mFile, "setAttr \".i01\" %f;\n", i01);}
	/*matrix[0][1]*/
	void setIn01(const DoubleID& i01){fprintf_s(mFile,"connectAttr \"");i01.write(mFile);fprintf_s(mFile,"\" \"%s.i01\";\n",mName.c_str());}
	/*matrix[0][2]*/
	void setIn02(double i02){if(i02 == 0.0) return; fprintf_s(mFile, "setAttr \".i02\" %f;\n", i02);}
	/*matrix[0][2]*/
	void setIn02(const DoubleID& i02){fprintf_s(mFile,"connectAttr \"");i02.write(mFile);fprintf_s(mFile,"\" \"%s.i02\";\n",mName.c_str());}
	/*matrix[0][3]*/
	void setIn03(double i03){if(i03 == 0.0) return; fprintf_s(mFile, "setAttr \".i03\" %f;\n", i03);}
	/*matrix[0][3]*/
	void setIn03(const DoubleID& i03){fprintf_s(mFile,"connectAttr \"");i03.write(mFile);fprintf_s(mFile,"\" \"%s.i03\";\n",mName.c_str());}
	/*matrix[1][0]*/
	void setIn10(double i10){if(i10 == 0.0) return; fprintf_s(mFile, "setAttr \".i10\" %f;\n", i10);}
	/*matrix[1][0]*/
	void setIn10(const DoubleID& i10){fprintf_s(mFile,"connectAttr \"");i10.write(mFile);fprintf_s(mFile,"\" \"%s.i10\";\n",mName.c_str());}
	/*matrix[1][1]*/
	void setIn11(double i11){if(i11 == 1.0) return; fprintf_s(mFile, "setAttr \".i11\" %f;\n", i11);}
	/*matrix[1][1]*/
	void setIn11(const DoubleID& i11){fprintf_s(mFile,"connectAttr \"");i11.write(mFile);fprintf_s(mFile,"\" \"%s.i11\";\n",mName.c_str());}
	/*matrix[1][2]*/
	void setIn12(double i12){if(i12 == 0.0) return; fprintf_s(mFile, "setAttr \".i12\" %f;\n", i12);}
	/*matrix[1][2]*/
	void setIn12(const DoubleID& i12){fprintf_s(mFile,"connectAttr \"");i12.write(mFile);fprintf_s(mFile,"\" \"%s.i12\";\n",mName.c_str());}
	/*matrix[1][3]*/
	void setIn13(double i13){if(i13 == 0.0) return; fprintf_s(mFile, "setAttr \".i13\" %f;\n", i13);}
	/*matrix[1][3]*/
	void setIn13(const DoubleID& i13){fprintf_s(mFile,"connectAttr \"");i13.write(mFile);fprintf_s(mFile,"\" \"%s.i13\";\n",mName.c_str());}
	/*matrix[2][0]*/
	void setIn20(double i20){if(i20 == 0.0) return; fprintf_s(mFile, "setAttr \".i20\" %f;\n", i20);}
	/*matrix[2][0]*/
	void setIn20(const DoubleID& i20){fprintf_s(mFile,"connectAttr \"");i20.write(mFile);fprintf_s(mFile,"\" \"%s.i20\";\n",mName.c_str());}
	/*matrix[2][1]*/
	void setIn21(double i21){if(i21 == 0.0) return; fprintf_s(mFile, "setAttr \".i21\" %f;\n", i21);}
	/*matrix[2][1]*/
	void setIn21(const DoubleID& i21){fprintf_s(mFile,"connectAttr \"");i21.write(mFile);fprintf_s(mFile,"\" \"%s.i21\";\n",mName.c_str());}
	/*matrix[2][2]*/
	void setIn22(double i22){if(i22 == 1.0) return; fprintf_s(mFile, "setAttr \".i22\" %f;\n", i22);}
	/*matrix[2][2]*/
	void setIn22(const DoubleID& i22){fprintf_s(mFile,"connectAttr \"");i22.write(mFile);fprintf_s(mFile,"\" \"%s.i22\";\n",mName.c_str());}
	/*matrix[2][3]*/
	void setIn23(double i23){if(i23 == 0.0) return; fprintf_s(mFile, "setAttr \".i23\" %f;\n", i23);}
	/*matrix[2][3]*/
	void setIn23(const DoubleID& i23){fprintf_s(mFile,"connectAttr \"");i23.write(mFile);fprintf_s(mFile,"\" \"%s.i23\";\n",mName.c_str());}
	/*matrix[3][0]*/
	void setIn30(double i30){if(i30 == 0.0) return; fprintf_s(mFile, "setAttr \".i30\" %f;\n", i30);}
	/*matrix[3][0]*/
	void setIn30(const DoubleID& i30){fprintf_s(mFile,"connectAttr \"");i30.write(mFile);fprintf_s(mFile,"\" \"%s.i30\";\n",mName.c_str());}
	/*matrix[3][1]*/
	void setIn31(double i31){if(i31 == 0.0) return; fprintf_s(mFile, "setAttr \".i31\" %f;\n", i31);}
	/*matrix[3][1]*/
	void setIn31(const DoubleID& i31){fprintf_s(mFile,"connectAttr \"");i31.write(mFile);fprintf_s(mFile,"\" \"%s.i31\";\n",mName.c_str());}
	/*matrix[3][2]*/
	void setIn32(double i32){if(i32 == 0.0) return; fprintf_s(mFile, "setAttr \".i32\" %f;\n", i32);}
	/*matrix[3][2]*/
	void setIn32(const DoubleID& i32){fprintf_s(mFile,"connectAttr \"");i32.write(mFile);fprintf_s(mFile,"\" \"%s.i32\";\n",mName.c_str());}
	/*matrix[3][3]*/
	void setIn33(double i33){if(i33 == 1.0) return; fprintf_s(mFile, "setAttr \".i33\" %f;\n", i33);}
	/*matrix[3][3]*/
	void setIn33(const DoubleID& i33){fprintf_s(mFile,"connectAttr \"");i33.write(mFile);fprintf_s(mFile,"\" \"%s.i33\";\n",mName.c_str());}
	/*A 4x4 matrix made from the 16 input values*/
	void setOutput(const MatrixID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*matrix[0][0]*/
	DoubleID getIn00(){char buffer[4096];sprintf_s (buffer, "%s.i00",mName.c_str());return (const char*)buffer;}
	/*matrix[0][1]*/
	DoubleID getIn01(){char buffer[4096];sprintf_s (buffer, "%s.i01",mName.c_str());return (const char*)buffer;}
	/*matrix[0][2]*/
	DoubleID getIn02(){char buffer[4096];sprintf_s (buffer, "%s.i02",mName.c_str());return (const char*)buffer;}
	/*matrix[0][3]*/
	DoubleID getIn03(){char buffer[4096];sprintf_s (buffer, "%s.i03",mName.c_str());return (const char*)buffer;}
	/*matrix[1][0]*/
	DoubleID getIn10(){char buffer[4096];sprintf_s (buffer, "%s.i10",mName.c_str());return (const char*)buffer;}
	/*matrix[1][1]*/
	DoubleID getIn11(){char buffer[4096];sprintf_s (buffer, "%s.i11",mName.c_str());return (const char*)buffer;}
	/*matrix[1][2]*/
	DoubleID getIn12(){char buffer[4096];sprintf_s (buffer, "%s.i12",mName.c_str());return (const char*)buffer;}
	/*matrix[1][3]*/
	DoubleID getIn13(){char buffer[4096];sprintf_s (buffer, "%s.i13",mName.c_str());return (const char*)buffer;}
	/*matrix[2][0]*/
	DoubleID getIn20(){char buffer[4096];sprintf_s (buffer, "%s.i20",mName.c_str());return (const char*)buffer;}
	/*matrix[2][1]*/
	DoubleID getIn21(){char buffer[4096];sprintf_s (buffer, "%s.i21",mName.c_str());return (const char*)buffer;}
	/*matrix[2][2]*/
	DoubleID getIn22(){char buffer[4096];sprintf_s (buffer, "%s.i22",mName.c_str());return (const char*)buffer;}
	/*matrix[2][3]*/
	DoubleID getIn23(){char buffer[4096];sprintf_s (buffer, "%s.i23",mName.c_str());return (const char*)buffer;}
	/*matrix[3][0]*/
	DoubleID getIn30(){char buffer[4096];sprintf_s (buffer, "%s.i30",mName.c_str());return (const char*)buffer;}
	/*matrix[3][1]*/
	DoubleID getIn31(){char buffer[4096];sprintf_s (buffer, "%s.i31",mName.c_str());return (const char*)buffer;}
	/*matrix[3][2]*/
	DoubleID getIn32(){char buffer[4096];sprintf_s (buffer, "%s.i32",mName.c_str());return (const char*)buffer;}
	/*matrix[3][3]*/
	DoubleID getIn33(){char buffer[4096];sprintf_s (buffer, "%s.i33",mName.c_str());return (const char*)buffer;}
	/*A 4x4 matrix made from the 16 input values*/
	MatrixID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	FourByFourMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FOURBYFOURMATRIX_H__
