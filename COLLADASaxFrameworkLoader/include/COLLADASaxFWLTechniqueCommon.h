/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_TECHNIQUE_COMMON_H__
#define __COLLADASAXFWL_TECHNIQUE_COMMON_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLAccessor.h"


namespace COLLADASaxFWL
{

    /** 
     * Specifies information for a specific element for the common profile that all COLLADA 
     * implementations must support. 
     * Specifies technique information that consuming applications can use if no technique specific 
     * to the application is provided in the COLLADA document.
     * In other words, if an element has <technique> child elements for one or more specific 
     * profiles, applications reading the COLLADA document should use the technique most 
     * appropriate for the application. If none of the specific <technique>s is appropriate, the 
     * application must use the element�s <technique_common> instead, if one is specified.
     * Each element�s <technique_common> attributes and children are unique. Refer to each parent 
     * element for details.
     */
    class TechniqueCommon
    {

    private:

        /**
         * Declares an access pattern to one of the array elements <float_array>,
         * <int_array>, <Name_array>, <bool_array>, and <IDREF_array>.
         */
        Accessor mAccessor;

    public:

        /** Constructor. */
        TechniqueCommon () {}

        /** Destructor. */
        virtual ~TechniqueCommon () {}

        /**
         * Declares an access pattern to one of the array elements <float_array>,
         * <int_array>, <Name_array>, <bool_array>, and <IDREF_array>.
         * @return const Accessor& Reference to the accessor.
         */
        const Accessor& getAccessor () const { return mAccessor; }

        /**
        * Declares an access pattern to one of the array elements <float_array>,
        * <int_array>, <Name_array>, <bool_array>, and <IDREF_array>.
        * @return const Accessor& Reference to the accessor.
        */
        Accessor& getAccessor () { return mAccessor; }

        /**
         * Declares an access pattern to one of the array elements <float_array>,
         * <int_array>, <Name_array>, <bool_array>, and <IDREF_array>.
         * @param accessor The accessor element to set.
         */
        void setAccessor ( const Accessor& accessor ) { mAccessor = accessor; }

    };
}

#endif // __COLLADASAXFWL_TECHNIQUE_COMMON_H__
