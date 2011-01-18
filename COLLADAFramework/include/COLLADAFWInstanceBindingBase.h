/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEBINDINGBASE_H__
#define __COLLADAFW_INSTANCEBINDINGBASE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceBase.h"
#include "COLLADAFWMaterialBinding.h"


namespace COLLADAFW
{

    /** Base class for instance objects with binding elements. */
    template<ClassId classId>
    class InstanceBindingBase : public InstanceBase<classId>
    {
    private:

        /** The list of all material bindings of this instance geometry. The Material bindings must be 
        order according to MaterialBinding::operator<.*/
        MaterialBindingArray mMaterialBindings;

	public:

        /** Constructor. Creates an instance geometry, that instantiates the geometry with 
        UniqueId @a instanciatedGeometryId.
        @param instanceGeometry The UniqueId of the geometry instantiated.*/ 
        InstanceBindingBase ( const UniqueId& uniqueId, const UniqueId& instanciatedObjectId ) 
            : InstanceBase<classId> ( uniqueId, instanciatedObjectId )
        {}

        /** Destructor. */
        virtual ~InstanceBindingBase() {}

        /** Clones the matrix.*/
        InstanceBindingBase* clone() const { return new InstanceBindingBase(*this); }

        /** Returns the list of all material bindings.*/
        MaterialBindingArray& getMaterialBindings() { return mMaterialBindings; }

        /** Returns the list of all material bindings.*/
        const MaterialBindingArray& getMaterialBindings() const { return mMaterialBindings; }

	private:

        /** Default copy constructor. */
		InstanceBindingBase( const InstanceBindingBase& pre )
            : InstanceBase<classId> ( pre )
            , mMaterialBindings ()
        {
            pre.mMaterialBindings.cloneArray ( mMaterialBindings );
        }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEBINDINGBASE_H__
