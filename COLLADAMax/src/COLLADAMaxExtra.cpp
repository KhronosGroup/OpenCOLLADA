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

#include "COLLADAMaxExtra.h"



namespace COLLADAMax
{


    const String Extra::TECHNIQUE_PROFILE = "MAX3D";


    //---------------------------------------------------------------
    Extra::Extra ( COLLADA::StreamWriter * streamWriter )
            : COLLADA::ElementWriter ( streamWriter ),
            mExtra ( streamWriter ),
            mTechnique ( streamWriter )
    {}


    //---------------------------------------------------------------
    void Extra::openTechnique()
    {
        mExtra.openExtra();
        mTechnique.openTechnique ( TECHNIQUE_PROFILE );
    }

    //---------------------------------------------------------------
    void Extra::closeExtra()
    {
        mExtra.closeExtra();
    }
}
