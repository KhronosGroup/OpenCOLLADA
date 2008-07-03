/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxGeometryExtra.h"

#include <max.h>
#include <simpobj.h>

// class ids of the non standard primitives
#define CHAMFERBOX_CLASS_ID Class_ID( 0x1AD73F40,0x48EA0F97 )
#define OILTANK_CLASS_ID Class_ID( 0x210E642A,0x22F11EF8 )
#define SPINDLE_CLASS_ID  Class_ID( 0x130B141B,0x04B35AFE )
#define GENGON_CLASS_ID  Class_ID( 0x49BF599F,0x35F945AB )
#define RINGWAVE_CLASS_ID  Class_ID( 0x28E41F64,0x124B5312 )
#define PRISM_CLASS_ID  Class_ID( 0x63705FAC,0x5C1F553F )
#define TORUSKNOT_CLASS_ID  Class_ID( 0x00000720,0x00000000 )
#define CHAMFERCYL_CLASS_ID  Class_ID( 0x7B9A546E,0x21A446A1 )
#define CAPSULE_CLASS_ID  Class_ID( 0x6D3D77AC,0x79C939A9 )
#define L_EXT_CLASS_ID  Class_ID( 0x09E73A08,0x08693067 )
#define C_EXT_CLASS_ID  Class_ID( 0x33B1284D,0x7AF0200D )
#define HOSE_CLASS_ID  Class_ID( 0x69F96A5D,0x235C430A )
#define LTYPESTAIR_CLASS_ID  Class_ID( 0x71EF1F8C,0x6C773E1F )
#define STRAIGHTSTAIR_CLASS_ID  Class_ID( 0x2C693321,0x63BE1109 )
#define SPIRALSTAIR_CLASS_ID  Class_ID( 0x589D2C12,0x3D713EC9 )
#define UTYPESTAIR_CLASS_ID  Class_ID( 0x5D56671C,0x20264CEB )



namespace COLLADAMax
{




    const String GeometryExtra::ELEMENT_BOX = "box";
    const String GeometryExtra::ELEMENT_SPHERE = "sphere";
    const String GeometryExtra::ELEMENT_CYLINDER = "cylinder";
    const String GeometryExtra::ELEMENT_TORUS = "torus";
    const String GeometryExtra::ELEMENT_TEAPOT = "teapot";
    const String GeometryExtra::ELEMENT_CONE = "cone";
    const String GeometryExtra::ELEMENT_TUBE = "tube";
    const String GeometryExtra::ELEMENT_GEOSPHERE = "geosphere";
    const String GeometryExtra::ELEMENT_PYRAMID = "pyramid";
    const String GeometryExtra::ELEMENT_PLANE = "plane";
    const String GeometryExtra::ELEMENT_HEDRA = "hedra";
    const String GeometryExtra::ELEMENT_CHAMFERBOX = "chamferbox";
    const String GeometryExtra::ELEMENT_OILTANK = "oiltank";
    const String GeometryExtra::ELEMENT_SPINDLE = "spindle";
    const String GeometryExtra::ELEMENT_GENGON = "gengon";
    const String GeometryExtra::ELEMENT_RINGWAVE = "ringwave";
    const String GeometryExtra::ELEMENT_PRISM = "prism";
    const String GeometryExtra::ELEMENT_TORUSKNOT = "torusknot";
    const String GeometryExtra::ELEMENT_CHAMFERCYL = "chamfercyl";
    const String GeometryExtra::ELEMENT_CAPSULE = "capsule";
    const String GeometryExtra::ELEMENT_L_EXT = "l_ext";
    const String GeometryExtra::ELEMENT_C_EXT = "c_ext";
    const String GeometryExtra::ELEMENT_HOSE = "hose";
    const String GeometryExtra::ELEMENT_LTYPESTAIR = "ltypestair";
    const String GeometryExtra::ELEMENT_STRAIGHTSTAIR = "straigthstair";
    const String GeometryExtra::ELEMENT_SPIRALSTAIR = "spiralstair";
    const String GeometryExtra::ELEMENT_UTYPESTAIR = "utypestair";



    const int GeometryExtra::BOXPARAMETERSCOUNT = 7;
    const GeometryExtra::ExtraParameter GeometryExtra::BOXPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "length"
        },

        {TYPE_FLOAT, 1, "width"},
        {TYPE_FLOAT, 2, "height"},
        {TYPE_INT, 3, "widthsegments"},
        {TYPE_INT, 4, "lengthsegments"},
        {TYPE_INT, 5, "heightsegments"},
        {TYPE_INT, 6, "generateuvs"}
    };

    const int GeometryExtra::SPHEREPARAMETERSCOUNT = 10;
    const GeometryExtra::ExtraParameter GeometryExtra::SPHEREPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius"
        },

        {TYPE_INT, 1, "segments"},
        {TYPE_BOOL, 2, "smooth"},
        {TYPE_FLOAT, 3, "hemisphere"},
        {TYPE_FLOAT, 4, "squash"},
        {TYPE_INT, 5, "recenter"},
        {TYPE_INT, 6, "generateuvs"},
        {TYPE_INT, 7, "sliceon"},
        {TYPE_FLOAT, 8, "slicefrom"},
        {TYPE_FLOAT, 9, "sliceto"}
    };

    const int GeometryExtra::CYLINDERPARAMETERSCOUNT = 10;
    const GeometryExtra::ExtraParameter GeometryExtra::CYLINDERPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius"
        },

        {TYPE_FLOAT, 1, "height"},
        {TYPE_INT, 2, "heightsegments"},
        {TYPE_INT, 3, "capsegments"},
        {TYPE_INT, 4, "sides"},
        {TYPE_BOOL, 5, "smooth"},
        {TYPE_INT, 6, "sliceon"},
        {TYPE_FLOAT, 7, "slicefrom"},
        {TYPE_FLOAT, 8, "sliceto"},
        {TYPE_INT, 9, "generateuvs"}
    };

    const int GeometryExtra::TORUSPARAMETERSCOUNT = 11;
    const GeometryExtra::ExtraParameter GeometryExtra::TORUSPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius1"
        },

        {TYPE_FLOAT, 1, "radius2"},
        {TYPE_FLOAT, 2, "rotation"},
        {TYPE_FLOAT, 3, "twist"},
        {TYPE_INT, 4, "segments"},
        {TYPE_INT, 5, "sides"},
        {TYPE_INT, 6, "smooth"},
        {TYPE_INT, 7, "sliceon"},
        {TYPE_FLOAT, 8, "sliceto"},
        {TYPE_FLOAT, 9, "slicefrom"},
        {TYPE_INT, 10, "generateuvs"}
    };

    const int GeometryExtra::TEAPOTPARAMETERSCOUNT = 9;
    const GeometryExtra::ExtraParameter GeometryExtra::TEAPOTPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius"
        },

        {TYPE_INT, 1, "segments"},
        {TYPE_BOOL, 2, "smooth"},
        // {TYPE_INT, 3, "unknown"},
        {TYPE_BOOL, 4, "body"},
        {TYPE_BOOL, 5, "handle"},
        {TYPE_BOOL, 6, "spout"},
        {TYPE_BOOL, 7, "lid"},
        {TYPE_BOOL, 8, "generateuvs"}
    };

    const int GeometryExtra::CONEPARAMETERSCOUNT = 11;
    const GeometryExtra::ExtraParameter GeometryExtra::CONEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius1"
        },

        {TYPE_FLOAT, 1, "radius2"},
        {TYPE_FLOAT, 2, "height"},
        {TYPE_INT, 3, "heightsegments"},
        {TYPE_INT, 4, "capsegments"},
        {TYPE_INT, 5, "sides"},
        {TYPE_BOOL, 6, "smooth"},
        {TYPE_INT, 7, "sliceon"},
        {TYPE_FLOAT, 8, "slicefrom"},
        {TYPE_FLOAT, 9, "sliceto"},
        {TYPE_INT, 10, "generateuvs"}
    };

    const int GeometryExtra::TUBEPARAMETERSCOUNT = 11;
    const GeometryExtra::ExtraParameter GeometryExtra::TUBEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius1"
        },

        {TYPE_FLOAT, 1, "radius2"},
        {TYPE_FLOAT, 2, "height"},
        {TYPE_INT, 3, "sides"},
        {TYPE_INT, 4, "capsegments"},
        {TYPE_INT, 5, "heightsegments"},
        {TYPE_BOOL, 6, "smooth"},
        {TYPE_INT, 7, "sliceon"},
        {TYPE_FLOAT, 8, "slicefrom"},
        {TYPE_FLOAT, 9, "sliceto"},
        {TYPE_INT, 10, "generateuvs"}
    };

    const int GeometryExtra::GEOSPHEREPARAMETERSCOUNT = 7;
    const GeometryExtra::ExtraParameter GeometryExtra::GEOSPHEREPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "radius"
        },

        {TYPE_INT, 1, "segments"},
        {TYPE_INT, 2, "geodesicbasetype"},
        {TYPE_BOOL, 3, "hemisphere"},
        {TYPE_BOOL, 4, "smooth"},
        {TYPE_BOOL, 5, "basetopivot"},
        {TYPE_BOOL, 6, "generateuvs"}
    };

    const int GeometryExtra::PYRAMIDPARAMETERSCOUNT = 7;
    const GeometryExtra::ExtraParameter GeometryExtra::PYRAMIDPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "width"
        },

        {TYPE_FLOAT, 1, "depth"},
        {TYPE_FLOAT, 2, "height"},
        {TYPE_INT, 3, "widthsegments"},
        {TYPE_INT, 4, "depthsegments"},
        {TYPE_INT, 5, "heightsegments"},
        {TYPE_INT, 6, "generateuvs"}
    };

    const int GeometryExtra::PLANEPARAMETERSCOUNT = 7;
    const GeometryExtra::ExtraParameter GeometryExtra::PLANEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, "lenght"
        },

        {TYPE_FLOAT, 1, "width"},
        {TYPE_INT, 2, "widthsegments"},
        {TYPE_INT, 3, "lenghtsegments"},
        {TYPE_FLOAT, 4, "density"},
        {TYPE_FLOAT, 5, "scale"},
        {TYPE_INT, 6, "generateuvs"}
    };

    const int GeometryExtra::HEDRAPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::HEDRAPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::CHAMFERBOXPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::CHAMFERBOXPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::OILTANKPARAMETERSCOUNT = 0;
    const GeometryExtra:: ExtraParameter GeometryExtra::OILTANKPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::SPINDLEPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::SPINDLEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::GENGONPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::GENGONPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::RINGWAVEPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::RINGWAVEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::PRISMPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::PRISMPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::TORUSKNOTPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::TORUSKNOTPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::CHAMFERCYLPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::CHAMFERCYLPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::CAPSULEPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::CAPSULEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::L_EXTPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::L_EXTPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::C_EXTPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::C_EXTPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::HOSEPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::HOSEPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::LTYPESTAIRPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::LTYPESTAIRPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::STRAIGHTSTAIRPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::STRAIGHTSTAIRPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::SPIRALSTAIRPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::SPIRALSTAIRPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    const int GeometryExtra::UTYPESTAIRPARAMETERSCOUNT = 0;
    const GeometryExtra::ExtraParameter GeometryExtra::UTYPESTAIRPARAMETERS[] =
    {
        {
            TYPE_FLOAT, 0, ""
        }
    };

    //---------------------------------------------------------------
    GeometryExtra::GeometryExtra ( COLLADA::StreamWriter * streamWriter, Object * object )
            : Extra ( streamWriter ),
            mTimeValue ( 0 ),
            mInterval ( FOREVER ),
            mObject ( object )
    {}

    //---------------------------------------------------------------
    void GeometryExtra::doExport()
    {
        Class_ID id = mObject->ClassID();


        if ( id == Class_ID ( BOXOBJ_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_BOX, BOXPARAMETERS, BOXPARAMETERSCOUNT );
        else if ( id == Class_ID ( SPHERE_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_SPHERE, SPHEREPARAMETERS, SPHEREPARAMETERSCOUNT );
        else if ( id == Class_ID ( CYLINDER_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_CYLINDER, CYLINDERPARAMETERS, CYLINDERPARAMETERSCOUNT );
        else if ( id == Class_ID ( TORUS_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_TORUS, TORUSPARAMETERS, TORUSPARAMETERSCOUNT );
        else if ( id == Class_ID ( TEAPOT_CLASS_ID1, TEAPOT_CLASS_ID2 ) )
            exportParamBlock ( ELEMENT_TEAPOT, TEAPOTPARAMETERS, TEAPOTPARAMETERSCOUNT );
        else if ( id == Class_ID ( CONE_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_CONE, CONEPARAMETERS, CONEPARAMETERSCOUNT );
        else if ( id == Class_ID ( TUBE_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_TUBE, TUBEPARAMETERS, TUBEPARAMETERSCOUNT );
        else if ( id == Class_ID ( HEDRA_CLASS_ID, 0 ) )
            exportParamBlock ( ELEMENT_HEDRA, HEDRAPARAMETERS, HEDRAPARAMETERSCOUNT );
        else if ( id == CHAMFERBOX_CLASS_ID )
            exportParamBlock ( ELEMENT_CHAMFERBOX, CHAMFERBOXPARAMETERS, CHAMFERBOXPARAMETERSCOUNT );
        else if ( id == OILTANK_CLASS_ID )
            exportParamBlock ( ELEMENT_OILTANK, OILTANKPARAMETERS, OILTANKPARAMETERSCOUNT );
        else if ( id == SPINDLE_CLASS_ID )
            exportParamBlock ( ELEMENT_SPINDLE, SPINDLEPARAMETERS, SPINDLEPARAMETERSCOUNT );
        else if ( id == GENGON_CLASS_ID )
            exportParamBlock ( ELEMENT_GENGON, GENGONPARAMETERS, GENGONPARAMETERSCOUNT );
        else if ( id == RINGWAVE_CLASS_ID )
            exportParamBlock2 ( ELEMENT_RINGWAVE, RINGWAVEPARAMETERS, RINGWAVEPARAMETERSCOUNT );
        else if ( id == PRISM_CLASS_ID )
            exportParamBlock ( ELEMENT_PRISM, PRISMPARAMETERS, PRISMPARAMETERSCOUNT );
        else if ( id == TORUSKNOT_CLASS_ID )
            exportParamBlock ( ELEMENT_TORUSKNOT, TORUSKNOTPARAMETERS, TORUSKNOTPARAMETERSCOUNT );
        else if ( id == CHAMFERCYL_CLASS_ID )
            exportParamBlock ( ELEMENT_CHAMFERCYL, CHAMFERCYLPARAMETERS, CHAMFERCYLPARAMETERSCOUNT );
        else if ( id == CAPSULE_CLASS_ID )
            exportParamBlock ( ELEMENT_CAPSULE, CAPSULEPARAMETERS, CAPSULEPARAMETERSCOUNT );
        else if ( id == L_EXT_CLASS_ID )
            exportParamBlock ( ELEMENT_L_EXT, L_EXTPARAMETERS, L_EXTPARAMETERSCOUNT );
        else if ( id == C_EXT_CLASS_ID )
            exportParamBlock ( ELEMENT_C_EXT, C_EXTPARAMETERS, C_EXTPARAMETERSCOUNT );
        else if ( id == HOSE_CLASS_ID )
            exportParamBlock ( ELEMENT_HOSE, HOSEPARAMETERS, HOSEPARAMETERSCOUNT );
        else if ( id == LTYPESTAIR_CLASS_ID )
            exportParamBlock ( ELEMENT_LTYPESTAIR, LTYPESTAIRPARAMETERS, LTYPESTAIRPARAMETERSCOUNT );
        else if ( id == STRAIGHTSTAIR_CLASS_ID )
            exportParamBlock ( ELEMENT_STRAIGHTSTAIR, STRAIGHTSTAIRPARAMETERS, STRAIGHTSTAIRPARAMETERSCOUNT );
        else if ( id == SPIRALSTAIR_CLASS_ID )
            exportParamBlock ( ELEMENT_SPIRALSTAIR, SPIRALSTAIRPARAMETERS, SPIRALSTAIRPARAMETERSCOUNT );
        else if ( id == UTYPESTAIR_CLASS_ID )
            exportParamBlock ( ELEMENT_UTYPESTAIR, UTYPESTAIRPARAMETERS, UTYPESTAIRPARAMETERSCOUNT );

#if (MAX_VERSION_MAJOR >= 8)
#ifndef NO_OBJECT_STANDARD_PRIMITIVES

        else if ( id == PLANE_CLASS_ID )
            exportParamBlock2 ( ELEMENT_PLANE, PLANEPARAMETERS, PLANEPARAMETERSCOUNT );
        else if ( id == PYRAMID_CLASS_ID )
            exportParamBlock ( ELEMENT_PYRAMID, PYRAMIDPARAMETERS, PYRAMIDPARAMETERSCOUNT );
        else if ( id == GSPHERE_CLASS_ID )
            exportParamBlock2 ( ELEMENT_GEOSPHERE, GEOSPHEREPARAMETERS, GEOSPHEREPARAMETERSCOUNT );

#endif // NO_OBJECT_STANDARD_PRIMITIVES
#endif // USE_MAX_8


#if 0
        //for testing only
        std::filebuf fb;

        fb.open ( "c:\\temp\\primitive.txt", std::ios::app );

        std::ostream os ( &fb );

        os << mObject->GetObjectName() << std::endl << std::endl;

        os << "( " << ( void * ) id.PartA() << "," << ( void * ) id.PartB() << " )" << std::endl << std::endl << std::endl;

        IParamBlock2 * paramBlock2 = 0;

        IParamBlock * paramBlock = 0;


        IParamArray * paramarray = mObject->GetParamBlock();


        try
        {
            mObject->GetParamBlock();
            paramBlock = mObject->GetParamBlock() ->GetParamBlock();
        }

        catch ( ... )
        {
            paramBlock2 = ( ( SimpleObject2 * ) mObject ) ->pblock2;
        }


        int paramBlockSize = paramBlock2 ? paramBlock2->NumParams() : paramBlock->NumParams();


        int type;

        for ( int i = 0; i < paramBlockSize; ++i )
        {
            type = paramBlock2 ? paramBlock2->GetParameterType ( i ) : paramBlock->GetParameterType ( i );
            int intVal = paramBlock2 ? paramBlock2->GetInt ( i ) : paramBlock->GetInt ( i );
            float floatVal = paramBlock2 ? paramBlock2->GetFloat ( i ) : paramBlock->GetFloat ( i );
            os << i << " ";

            switch ( type )
            {

            case TYPE_BOOL:
                os << "TYPE_BOOL " << intVal << " ";
                break;

            case TYPE_FLOAT:
                os << "TYPE_FLOAT " << floatVal << " ";
                break;

            case TYPE_INT:
                os << "TYPE_INT " << intVal << " ";
                break;

            }

            if ( paramBlock2 )
                os << paramBlock2->GetLocalName ( i );

            os << std::endl;

            int g = 5;
        }

        fb.close();

#endif

    }

    //---------------------------------------------------------------
    void GeometryExtra::openPrimitive ( const String & primitive )
    {
        openTechnique();
        mSW->openElement ( primitive );
    }

    //---------------------------------------------------------------
    void GeometryExtra::exportParamBlock ( const String & elementName, const ExtraParameter extraParameters[], int extraParametersCount )
    {
        openPrimitive ( elementName );
        IParamBlock * paramBlock = mObject->GetParamBlock() ->GetParamBlock();

        for ( int i = 0; i < extraParametersCount; ++i )
        {
            const ExtraParameter & parameter = extraParameters[ i ];
            addParamBlockParameter ( parameter.type, parameter.paramId, parameter.paramName, paramBlock );
        }

        closeExtra();
    }

    //---------------------------------------------------------------
    void GeometryExtra::exportParamBlock2 ( const String & elementName, const ExtraParameter extraParameters[], int extraParametersCount )
    {
        openPrimitive ( elementName );
        IParamBlock2 * paramBlock = ( ( SimpleObject2 * ) mObject ) ->pblock2;

        for ( int i = 0; i < extraParametersCount; ++i )
        {
            const ExtraParameter & parameter = extraParameters[ i ];
            addParamBlockParameter ( parameter.type, parameter.paramId, parameter.paramName, paramBlock );
        }

        closeExtra();
    }

}
