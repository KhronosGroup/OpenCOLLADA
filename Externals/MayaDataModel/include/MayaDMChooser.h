/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHOOSER_H__
#define __MayaDM_CHOOSER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node provides a way to control a large set of boolean attributes.
 In it's simplest form, this node passes each boolean input to its
 corresponding boolean output.

<p/>
 If inLevel[0] is true, then output[0] will be true.<br/>
 If inLevel[n] is true, then output[n] will be true.<br/>
 There is additional control for overriding the values
 that pass through the node.

<p/>
 You must initialize all multi attributes to the same, correct size.
 In the example below, notice that the displayLevel attribute is
 explicitly initialized to have the same number of elements as
 the output attribute.

<p/>
 For example, you want to simulate an LED pixel board where
 an array of lights/objects turn on and off.  You can connect each object's
 visibility to the chooser node and control the chooser node
 programmatically.  See the example.

<p/>
 Use the displayLevel attribute to override the connection between
 the inLevel and output attributes.  This is useful if
 there are connections on inLevel and you want to override
 the incoming values.  There are three values for displayLevel[n]:

<ol>
 <li>inLevel[n] will be passed to output[n]</li>
 <li>TRUE will be passed to output[n]; inLevel[n] will be ignored</li>
 <li>FALSE will be passed to output[n]; inLevel[n] will be ignored</li>
</ol>
<p/>
 Historical note: this node was originally created to accommodate
 the level-of-detail (lod) feature; hence the confusing names and
 references to "lod".
<p/>
 Examples:
<p/>

 <pre>
        polyCube; move -r 2 0 0;
        polyCone; move -r 4 0 0;
        polySphere; move -r 6 0 0;
        polyCylinder; move -r 8 0 0;

        createNode chooser;
        connectAttr chooser1.output[0] pCube1.visibility;
        connectAttr chooser1.output[1] pCone1.visibility;
        connectAttr chooser1.output[2] pSphere1.visibility;
        connectAttr chooser1.output[3] pCylinder1.visibility;
        int $num = `getAttr -size chooser1.output`;

        //
                Initialize this multi attribute to match the output attribute
                Initialize to 0 means the input attr will be passed to the output
        //
        for( $i = 0 ; $i < $num; $i ++ ) {
                setAttr chooser1.displayLevel[$i] 0;
        }

        //
                Make all objects visible by setting the inLevel attribute.
        //
        for( $i = 0 ; $i < $num; $i ++ ) {
                setAttr chooser1.inLevel[$i] 1;
        }

        //
                Make all objects invisible
        //
        for( $i = 0 ; $i < $num; $i ++ ) {
                setAttr chooser1.inLevel[$i] 0;
        }

        //
                Make every other object invisible
        //
        for( $i = 0 ; $i < $num; $i ++ ) {
                if( $i % 2 == 0 )
                        setAttr chooser1.inLevel[$i] 0;
                else
                        setAttr chooser1.inLevel[$i] 1;
        }
 </pre>
*/
class Chooser : public DependNode
{
public:
public:
	Chooser(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "chooser"){}
	virtual ~Chooser(){}
	/*Input multi attribute that will be passed to the the output multi attribute*/
	void setInLevel(size_t il_i,bool il){if(il == false) return; fprintf_s(mFile, "setAttr \".il[%i]\" %i;\n", il_i,il);}
	/*Input multi attribute that will be passed to the the output multi attribute*/
	void setInLevel(size_t il_i,const BoolID& il){fprintf_s(mFile,"connectAttr \"");il.write(mFile);fprintf_s(mFile,"\" \"%s.il[%i]\";\n",mName.c_str(),il_i);}
	/*
	Use this to override the input attributes.
	0 - inLevel[n] will be passed to output[n]
	1 - TRUE will be passed to output[n]; inLevel[n] will be ignored
	2 - FALSE will be passed to output[n]; inLevel[n] will be ignored
	*/
	void setDisplayLevel(size_t dl_i,unsigned int dl){if(dl == 0) return; fprintf_s(mFile, "setAttr \".dl[%i]\" %i;\n", dl_i,dl);}
	/*
	Use this to override the input attributes.
	0 - inLevel[n] will be passed to output[n]
	1 - TRUE will be passed to output[n]; inLevel[n] will be ignored
	2 - FALSE will be passed to output[n]; inLevel[n] will be ignored
	*/
	void setDisplayLevel(size_t dl_i,const UnsignedintID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl[%i]\";\n",mName.c_str(),dl_i);}
	/*Multi-attribute passed from the input multi attribute.*/
	void setOutput(size_t o_i,const BoolID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o[%i]\";\n",mName.c_str(),o_i);}
	/*Input multi attribute that will be passed to the the output multi attribute*/
	const BoolID& getInLevel(size_t il_i){char buffer[4096];sprintf_s (buffer, "%s.il[%i]",mName.c_str(),il_i);return (const char*)buffer;}
	/*
	Use this to override the input attributes.
	0 - inLevel[n] will be passed to output[n]
	1 - TRUE will be passed to output[n]; inLevel[n] will be ignored
	2 - FALSE will be passed to output[n]; inLevel[n] will be ignored
	*/
	const UnsignedintID& getDisplayLevel(size_t dl_i){char buffer[4096];sprintf_s (buffer, "%s.dl[%i]",mName.c_str(),dl_i);return (const char*)buffer;}
	/*Multi-attribute passed from the input multi attribute.*/
	const BoolID& getOutput(size_t o_i){char buffer[4096];sprintf_s (buffer, "%s.o[%i]",mName.c_str(),o_i);return (const char*)buffer;}
protected:
	Chooser(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CHOOSER_H__
