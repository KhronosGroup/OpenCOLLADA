/*
    Copyright (c) 2015 Starbreeze AB

	This file is part of COLLADAMaya.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_LIGHT_PROBE_EXPORTER_H__
#define __COLLADA_MAYA_LIGHT_PROBE_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWExtraTechnique.h"

namespace COLLADASW
{
    /** A class that holds informations of an @a \<instance_light_probe\> element and writes it to stream. */
    class InstanceLightProbe : public ElementWriter
    {

    private:

        /** The url to the light probe information (library_light_probes) */
        URI mUrl;
        String mSid;
        String mName;

    public:
        /** 
         * Constructor
         * @param url The url
         * @param sid The sid
         * @param name The name
        */
        InstanceLightProbe ( StreamWriter* streamWriter, const URI& url, String sid="", String name="" )  
        : ElementWriter ( streamWriter )
        , mUrl ( url )
        , mSid ( sid ) 
        , mName ( name )
        {}

        /** Returns the url */
        const URI& getUrl() const
        {
            return mUrl;
        }

        /** Returns the sid */
        const String& getSid() const
        {
            return mSid;
        }

        /** Returns the name */
        const String& getName() const
        {
            return mName;
        }

        /** Write the instance light probe to the stream*/
        void add();

    };

    /** A class that hold all information about a @a \<light_probe\> element.*/
    class LightProbe : public ElementWriter, public BaseExtraTechnique
    {
    private:

        friend class LibraryLightProbes;

        /** The id of the light probe.*/
        String mLightProbeId;

        /** The name of the light probe.*/
        String mLightProbeName;

    protected:

        /** Adds the light probe information. */
        void add() const;

    public:
 
        /** 
         * Constructor
         * @param lightProbeId The id of the light probe.
         * @param lightProbeName The name of the light probe.
         */
        LightProbe(
            StreamWriter* streamWriter,
            const String& lightProbeId,
            const String& lightProbeName = ElementWriter::EMPTY_STRING);

        /** Destructor */
        virtual ~LightProbe() {};

        /** Returns a reference to the light probe id */
        const String& getLightProbeId() const { return mLightProbeId; }

        /** Returns a reference to the light probe name */
        const String& getLightProbeName() const { return mLightProbeName; }

        /** The name of the light probe.*/
        void setLightProbeName ( const String& val ) { mLightProbeName = val; }
    };

    /** Class to simply the creation of @a \<library_lights\> and @a \<lights\>'s*/
    class LibraryLightProbes : public Library, public BaseExtraTechnique
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_light_probes\> and @a \<light_probe\>'s
        should be written to.
        */
        LibraryLightProbes(StreamWriter* streamWriter);

        /** Destructor */
        virtual ~LibraryLightProbes() {}

    protected:
        /** Adds @a \<light_probe\> element. If not already opened, it opens @a \<library_light_probes\>*/
        void addLightProbe(const LightProbe& lightProbe);

    };
}

namespace COLLADAMaya
{

    /** This class writes the <library_light_probes>. */
    class LightProbeExporter : public COLLADASW::LibraryLightProbes
    {
    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mLightProbeIdList;

        /**
        * A collada id for every maya id.
        */
        StringToStringMap mMayaIdColladaIdMap;

    public:

        /**
        * @param streamWriter The stream the output will be written to
        * @param documentExporter The document exporter this material exporter is used in
        */
        LightProbeExporter ( COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~LightProbeExporter() {};

        /** Exports the light probes in the scene graph. */
        void exportLightProbes (  );

        /** Exports the current scene element and all it's children. */
        void exportLightProbes ( SceneElement* sceneElement );

        /**
        * A collada id for every maya id.
        */
        const String findColladaLightProbeId ( const String& mayaLightProbeId );

    private:

        /** Exports the geometry data of the current object, if it is a valid mesh object to export. */
        bool exportLightProbe ( const MDagPath& dagPath );

    };

}

#endif //__COLLADA_MAYA_LIGHT_PROBE_EXPORTER_H__
