/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAFRAMEWORK_TECHNIQUE_H__
#define __COLLADAFRAMEWORK_TECHNIQUE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWAnnotate.h"
#include "COLLADAFWInclude.h"
#include "COLLADAFWCode.h"
#include "COLLADAFWNewParam.h"
#include "COLLADAFWSetParam.h"
#include "COLLADAFWImage.h"
#include "COLLADAFWShaderElement.h"
#include "COLLADAFWPass.h"


namespace COLLADAFW
{

    /** 
    Holds a description of the textures, samplers, shaders, parameters, and passes necessary 
    for rendering this effect using one method.
    For <technique> in elements other than <profile_*>, see "<technique> (core)."

    Techniques hold all the necessary elements required to render an effect. Each effect can 
    contain many techniques, each of which describes a different method for rendering that effect. 
    There are three different scenarios for which techniques are commonly used:
    • One technique might describe a high-LOD version while a second technique describes a low-LOD
    version of the same effect.
    • Describe an effect in different ways and use validation tools in the FX Runtime to find the 
    most efficient version of an effect for an unknown device that uses a standard API.
    • Describe an effect under different game states, for example, a daytime and a nighttime 
    technique, a normal technique, and a "magic-is-enabled" technique.

    Child elements vary by profile. See the parent element main entries for details. The following 
    list summarizes valid child elements. The child elements must appear in the following order if 
    present, with the following exceptions: <code> and <include>; <newparam>, <setparam>, and 
    <image> are choices, can appear in any order in that position; <blinn>, <constant>, <lambert>, 
    <phong> are choices, can appear in any order in that position:
    */
    class Technique
    {

    private:

        /** A text string containing the unique identifier of the element. This value must be 
        unique within the instance document. Optional. */
        String mId;

        /** A text string value containing the subidentifier of this element. This value must be
        unique within the scope of the parent element. Required. */
        String mSid;

        /** Adds a strongly typed annotation remark to the parent object.  No or multiple occurances. */
        Array<Annotate> mAnnotateArray;

        /** Imports source code or precompiled binary shaders into the FX Runtime by referencing 
        an external resource.  No or multiple occurances. */
        Array<Include> mIncludeArray;

        /** Provides an inline block of source code.  No or multiple occurances. */
        Array<Code> mCodeArray;

        /** Creates a new, named <param> (FX) object in the FX Runtime, and assigns it a type, 
        an initial value, and additional attributes at declaration time.  No or multiple occurances. */
        Array<NewParam> mNewParamArray;

        /** Assigns a new value to a previously defined parameter.  No or multiple occurances. */
        Array<SetParam> mSetParamArray;

        /** Declares the storage for the graphical representation of an object. No or multiple occurances. */
        Array<Image> mImageArray;

        /** blinn, constant, lambert, phong */
        ShaderElement* mShaderElement;

        /** Provides a static declaration of all the render states, shaders, and settings for one 
        rendering pipeline. One or more occurances. */
        Array<Pass> mPassArray;

        /** Provides arbitrary additional information about or related to its parent element. 
        No or multiple occurances. */
//        Array<Extra> mExtraArray;

    public:

        /** Constructor that sets the stream the asset should be written to*/
        Technique () {}

        /** Destructor. */
        virtual ~Technique () {};

        /** A text string containing the unique identifier of the element. This value must be 
        unique within the instance document. Optional. */
        const String getId () const { return mId; }

        /** A text string containing the unique identifier of the element. This value must be 
        unique within the instance document. Optional. */
        void setId ( const String Id ) { mId = Id; }

        /** A text string value containing the subidentifier of this element. This value must be
        unique within the scope of the parent element. Required. */
        const String getSid () const { return mSid; }

        /** A text string value containing the subidentifier of this element. This value must be
        unique within the scope of the parent element. Required. */
        void setSid ( const String Sid ) { mSid = Sid; }

    };

} //namespace COLLADAFW


#endif //__COLLADAFRAMEWORK_TECHNIQUE_H__

