/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_EFFECTIMPORTER_H__
#define __COLLADAMAYA_EFFECTIMPORTER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
	class EffectImporter : public BaseImporter
    {
    public:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdDependNodeMap;

    private:
	
        /** The standard name for a effect without name. */
        static const String EFFECT_NAME;

    private:

        /**
        * The list of the unique maya effect names.
        */
        COLLADABU::IDList mEffectIdList;

        /** 
        * The map holds the unique ids of the nodes to the maya effect name. 
        */
        UniqueIdNamesMap mMayaEffectNamesMap;

        /**
        * The map holds the maya effect objects.
        */
        UniqueIdDependNodeMap mMayaEffectMap;

    public:

        /** Constructor. */
		EffectImporter (  DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~EffectImporter ();

        /** Imports the given material. */
        bool importEffect ( const COLLADAFW::Effect* effect );

        /**
        * The map holds the maya material objects.
        */
        MayaDM::DependNode* findMayaEffect ( const COLLADAFW::UniqueId& val ) const;

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdDependNodeMap& getMayaEffectMap () const { return mMayaEffectMap; }

	private:

        /**
        * The map holds the maya material objects.
        */
        void appendEffect ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* effectNode );

        /**
         * Imports a blinn shader effect.
         */
        void importBlinnShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports a phong shader effect.
        */
        void importPhongShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports a lambert shader effect.
        */
        void importLambertShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
         * Imports the shader attributes.
         */
        template<class T>
        void importShaderAttributes ( 
            T* lambert,
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect )
        {
            // TODO Textures!

            {
                const COLLADAFW::Color& color = effect->getStandardColor ();
                if ( color.isValid () )
                    lambert->setColor ( MayaDM::float3 (color.getRed (), color.getGreen (), color.getBlue ()) );
            }

            const COLLADAFW::ColorOrTexture& diffuse = commonEffect->getDiffuse ();
            if ( diffuse.isColor () )
            {
                const COLLADAFW::Color& color = diffuse.getColor ();
                if ( color.isValid () )
                    lambert->setColor ( MayaDM::float3 (color.getRed (), color.getGreen (), color.getBlue ()) );
            }

            const COLLADAFW::ColorOrTexture& emission = commonEffect->getEmission ();
            if ( emission.isColor () )
            {
                const COLLADAFW::Color& color = emission.getColor ();
                if ( color.isValid () )
                    lambert->setIncandescence ( MayaDM::float3 (color.getRed (), color.getGreen (), color.getBlue ()) );
            }

            // TODO 
            commonEffect->getIndexOfRefraction ();

            const COLLADAFW::ColorOrTexture& reflective = commonEffect->getReflective ();
            if ( reflective.isColor () )
            {
                const COLLADAFW::Color& color = reflective.getColor ();
                // TODO
            }

            // TODO
            commonEffect->getReflectivity ();
            commonEffect->getShininess ();

            const COLLADAFW::ColorOrTexture& specular = commonEffect->getSpecular ();
            if ( specular.isColor () )
            {
                const COLLADAFW::Color& color = specular.getColor ();
                // TODO
            }

            // TODO
            commonEffect->getTransparency ();

            const COLLADAFW::ColorOrTexture& transparent = commonEffect->getTransparent();
            if ( transparent.isColor () )
            {
                const COLLADAFW::Color& color = transparent.getColor ();
                if ( color.isValid () )
                    lambert->setTransparency ( MayaDM::float3 (color.getRed (), color.getGreen (), color.getBlue ()) );
            }
        }

        /** Disable default copy ctor. */
		EffectImporter( const EffectImporter& pre );

        /** Disable default assignment operator. */
		const EffectImporter& operator= ( const EffectImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_EFFECTIMPORTER_H__
