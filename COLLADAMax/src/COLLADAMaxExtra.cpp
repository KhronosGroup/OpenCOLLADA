/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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
