/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_GEOMETRYEXTRA_H__
#define __COLLADAMAX_GEOMETRYEXTRA_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADAMaxExtra.h"

#include <max.h>

class Object;

namespace COLLADAMax
{
    /** Class to export extra tags of geometries. Currently extra tags for primitives
    like box, sphere... are exported.*/

	class GeometryExtra : public Extra , public COLLADASW::BaseExtraTechnique
    {

    private:
        /** The object which extra tag should be exported.*/
        Object * mObject;

		/** The id of the geometry the extra tags are exported for.*/
		const String mGeometryId;

		COLLADASW::StreamWriter * mStreamWriter;

        /* Element names of the primitives*/
        static const String ELEMENT_BOX;
        static const String ELEMENT_SPHERE;
        static const String ELEMENT_CYLINDER;
        static const String ELEMENT_TORUS;
        static const String ELEMENT_TEAPOT;
        static const String ELEMENT_CONE;
        static const String ELEMENT_TUBE;
        static const String ELEMENT_GEOSPHERE;
        static const String ELEMENT_PYRAMID;
        static const String ELEMENT_PLANE;
        static const String ELEMENT_HEDRA;
        static const String ELEMENT_CHAMFERBOX;
        static const String ELEMENT_OILTANK;
        static const String ELEMENT_SPINDLE;
        static const String ELEMENT_GENGON;
        static const String ELEMENT_RINGWAVE;
        static const String ELEMENT_PRISM;
        static const String ELEMENT_TORUSKNOT;
        static const String ELEMENT_CHAMFERCYL;
        static const String ELEMENT_CAPSULE;
        static const String ELEMENT_L_EXT;
        static const String ELEMENT_C_EXT;
        static const String ELEMENT_HOSE;
        static const String ELEMENT_LTYPESTAIR;
        static const String ELEMENT_STRAIGHTSTAIR;
        static const String ELEMENT_SPIRALSTAIR;
        static const String ELEMENT_UTYPESTAIR;


        /* Parameter count and parameter list of the primitives extra tags.*/
        static const int BOXPARAMETERSCOUNT;
        static const ExtraParameter BOXPARAMETERS[];

        static const int SPHEREPARAMETERSCOUNT;
        static const ExtraParameter SPHEREPARAMETERS[];

        static const int CYLINDERPARAMETERSCOUNT;
        static const ExtraParameter CYLINDERPARAMETERS[];

        static const int TORUSPARAMETERSCOUNT;
        static const ExtraParameter TORUSPARAMETERS[];

        static const int TEAPOTPARAMETERSCOUNT;
        static const ExtraParameter TEAPOTPARAMETERS[];

        static const int CONEPARAMETERSCOUNT;
        static const ExtraParameter CONEPARAMETERS[];

        static const int TUBEPARAMETERSCOUNT;
        static const ExtraParameter TUBEPARAMETERS[];

        static const int GEOSPHEREPARAMETERSCOUNT;
        static const ExtraParameter GEOSPHEREPARAMETERS[];

        static const int PYRAMIDPARAMETERSCOUNT;
        static const ExtraParameter PYRAMIDPARAMETERS[];

        static const int PLANEPARAMETERSCOUNT;
        static const ExtraParameter PLANEPARAMETERS[];

        static const int HEDRAPARAMETERSCOUNT;
        static const ExtraParameter HEDRAPARAMETERS[];

        static const int CHAMFERBOXPARAMETERSCOUNT;
        static const ExtraParameter CHAMFERBOXPARAMETERS[];

        static const int OILTANKPARAMETERSCOUNT;
        static const ExtraParameter OILTANKPARAMETERS[];

        static const int SPINDLEPARAMETERSCOUNT;
        static const ExtraParameter SPINDLEPARAMETERS[];

        static const int GENGONPARAMETERSCOUNT;
        static const ExtraParameter GENGONPARAMETERS[];

        static const int RINGWAVEPARAMETERSCOUNT;
        static const ExtraParameter RINGWAVEPARAMETERS[];

        static const int PRISMPARAMETERSCOUNT;
        static const ExtraParameter PRISMPARAMETERS[];

        static const int TORUSKNOTPARAMETERSCOUNT;
        static const ExtraParameter TORUSKNOTPARAMETERS[];

        static const int CHAMFERCYLPARAMETERSCOUNT;
        static const ExtraParameter CHAMFERCYLPARAMETERS[];

        static const int CAPSULEPARAMETERSCOUNT;
        static const ExtraParameter CAPSULEPARAMETERS[];

        static const int L_EXTPARAMETERSCOUNT;
        static const ExtraParameter L_EXTPARAMETERS[];

        static const int C_EXTPARAMETERSCOUNT;
        static const ExtraParameter C_EXTPARAMETERS[];

        static const int HOSEPARAMETERSCOUNT;
        static const ExtraParameter HOSEPARAMETERS[];

        static const int LTYPESTAIRPARAMETERSCOUNT;
        static const ExtraParameter LTYPESTAIRPARAMETERS[];

        static const int STRAIGHTSTAIRPARAMETERSCOUNT;
        static const ExtraParameter STRAIGHTSTAIRPARAMETERS[];

        static const int SPIRALSTAIRPARAMETERSCOUNT;
        static const ExtraParameter SPIRALSTAIRPARAMETERS[];

        static const int UTYPESTAIRPARAMETERSCOUNT;
        static const ExtraParameter UTYPESTAIRPARAMETERS[];


    public:
        /** Constructor
        @param streamWriter The stream the extra tags should be written to
        @param object The object which extra tag should be exported
        */
        GeometryExtra ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter, Object * object, const String& geometryId );

        /** Performs the actual export.*/
        void doExport();

    private:

        /** Exports all known parameters of the parameter block associated with the current object in to an extra tag.*/
        void exportParamBlock ( const String & elementName, const ExtraParameter extraParameters[], int extraParametersCount );

        /** Exports all known parameters of the parameter block 2 associated with the current object in to an extra tag.*/
        void exportParamBlock2 ( const String & elementName, const ExtraParameter extraParameters[], int extraParametersCount );

    };
}


#endif //__COLLADAMAX_GEOMETRYEXTRA_H__

