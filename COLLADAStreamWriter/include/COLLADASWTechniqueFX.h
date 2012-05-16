/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_TECHNIQUE_FX_H__
#define __COLLADASTREAMWRITER_TECHNIQUE_FX_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWAnnotation.h"
#include "COLLADASWInclude.h"
#include "COLLADASWCode.h"

namespace COLLADASW
{

    /** 
    Introduction:
    Holds a description of the textures, samplers, shaders, parameters, 
    and passes necessary for rendering this effect using one method. 
    Concepts:
    Techniques hold all the necessary elements required to render an effect. 
    Each effect can contain many techniques, each of which describes a 
    different method for rendering that effect. There are three different
    scenarios for which techniques are commonly used:
    � One technique might describe a high-LOD version while a second technique 
    describes a low-LOD version of the same effect.
    � Describe an effect in different ways and use validation tools in the FX 
    Runtime to find the most efficient version of an effect for an unknown 
    device that uses a standard API.
    � Describe an effect under different game states, for example, a daytime 
    and a nighttime technique, a normal technique, and a "magic-is-enabled" 
    technique.

    Parent elements:
    profile_CG, profile_COMMON, profile_GLSL, profile_GLES

    Child Elements
    Child elements vary by profile. See the parent element main entries 
    for details. The following list summarizes valid child elements. The 
    child elements must appear in the following order if present, with the
    following exceptions: <code> and <include>; <newparam>, <setparam>, 
    and <image> are choices, can appear in any order in that position; 
    <blinn>, <constant>, <lambert>, <phong> are choices, can appear in any 
    order in that position: 
    Name            profile_CG  profile_COMMON  profile_GLES    profile_GLSL    Occurrences
    <asset>         yes         yes             yes             -               0 or 1
    <annotate>      yes         -               yes             yes             0 or more
    <include>       yes         -               -               yes             0 or more
    <code>          yes         -               -               yes             0 or more
    <newparam>      yes         yes             yes             yes             0 or more
    <setparam>      yes         -               yes             yes             0 or more
    <image>         yes         yes             yes             yes             0 or more
    <blinn>         -           yes             -               -               1
    <constant>(FX)  -           yes             -               -
    <lambert>       -           yes             -               -
    <phong>         -           yes             -               -
    <pass>          yes         -               yes             yes             1 or more
    <extra>         yes         yes             yes             yes             0 or more
    */
    class TechniqueFX : public ElementWriter //, public template <class T>Annotation, public Include, public Code
    {

    private:

        /** A text string containing the unique identifier of the element. 
        This value must be unique within the instance document. Optional. */
        String mId;

        /** A text string value containing the subidentifier of this element. 
        This value must be unique within the scope of the parent element. Required. */
        String mSidNC;

    public:

        /** Constructor. */
        TechniqueFX ( StreamWriter *sw, const String &sid, const String &id = "" );

        /** Destructor. */
        virtual ~TechniqueFX () {}

        /** Writes a description of the textures, samplers, shaders, 
        parameters, and passes necessary for rendering this effect 
        using one method. 
        @param sidNC A text string value containing the subidentifier of this 
                element. This value must be unique within the scope of the 
                parent element. Required.
        @param id A text string containing the unique identifier of the element. 
                This value must be unique within the instance document. Optional.
        */
        void openTechniqueFX ( const String &sidNC, const String id = "" );

        /** Close the current technique element. */
        void closeTechniqueFX ();
    };
}

#endif // __COLLADASTREAMWRITER_TECHNIQUE_FX_H__
