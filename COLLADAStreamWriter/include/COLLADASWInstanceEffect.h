/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_EFFECT_H__
#define __COLLADASTREAMWRITER_INSTANCE_EFFECT_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"
#include "COLLADABUURI.h"

namespace COLLADASW
{

    /** Adds a hint for a platform of which technique to use in this effect.
    Shader editors require information on which technique to use by default 
    when an effect is instantiated. Subject to validation, the suggested 
    technique should be used if your FX Runtime recognizes the platform 
    string. */
    class TechniqueHint
    {

    private:

        /** A reference to the name of the platform. Required. */
        String mRefNC;

        /** Defines a string that specifies for which platform this hint is intended. Optional. */
        String mPlatform;

        /** A string that specifies for which API profile this hint is intended. It is the name of the
        profile within the effect that contains the technique. Profiles are constructed by
        appending this attribute’s value to "profile_". For example, to select
        profile_CG, specify profile="CG". Optional. */
        String mProfileNC;

    public:

        /** Constructor. */
        TechniqueHint ( const String &refe, const String &platform = "" )
            : mRefNC ( Utils::checkNCName( refe ) )
            , mPlatform ( platform )
            , mProfileNC ( "" )
        {}

        /** Constructor. */
        TechniqueHint ( const String &refe, const String &platform, const String &profile )
            : mRefNC ( Utils::checkNCName( refe ) )
            , mPlatform ( platform )
            , mProfileNC ( Utils::checkNCName( profile ) )
        {}

        /** Writes the technique hint into the collada document. */
        void add ( StreamWriter* sw );

    };

    /** A class that holds informations of an @a \<instance_effect\> element*/
    class InstanceEffect  : public ElementWriter, public BaseExtraTechnique
    {

    private:

        /** Used to close the current effect */
        TagCloser mTagCloser;   

        /** Identifier for this source code block or binary shader. Required. */
        String mSid;

        /** The URI of the location of the <effect> element to instantiate. 
        Required. Can refer to a local instance or external reference.
        For a local instance, this is a relative URI fragment identifier that 
        begins with the "#" character. The fragment identifier is an XPointer 
        shorthand pointer that consists of the ID of the element to instantiate.
        For an external reference, this is an absolute or relative URL. */
        URI mTargetURI;

        /** The text string name of this element. Optional. */
        String mName;

    public:

        /** Constructor
        @param sid The sid
        @param target The target
        */
        InstanceEffect ( 
            StreamWriter *streamWriter, 
            const URI& targetURI, 
            const String& sid = "", 
            const String& name = "" );

        /** Opens the current effect instance. */
        void open ();

        /** Writes the technique hint into the collada document. */
        void addTechniqueHint ( const String &refe, const String &platform = "" );

        /** Writes the technique hint into the collada document. */
        void addTechniqueHint ( const String &refe, const String &platform, const String &profile );

        /** Closes the current effect instance. */
        void close ();

        /** Returns the symbol*/
        const String& getSid() const;

        /** Returns the target*/
        const URI& getTargetURI() const;

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_EFFECT_H__
