#include "HelperStableHeaders.h"
#include "COLLADAInstanceGeometryUtil.h"

namespace COLLADADomHelper {

    //-----------------------------------------------------------------------
    void InstanceGeometryUtil::getSymbolMaterialMapping( const domInstance_geometryRef& instance, SymbolMaterialMap& map )
    {
        getSymbolMaterialMapping(instance.cast(), map);
    }
	//-----------------------------------------------------------------------
	void InstanceGeometryUtil::getSymbolMaterialMapping( const domInstance_geometry* instance, SymbolMaterialMap& map )
	{
		domBind_materialRef bind = instance->getBind_material();
		if(bind == 0)
		{
			return;
		}

		domBind_material::domTechnique_commonRef technique = bind->getTechnique_common();
		if(technique == 0)
		{
			return;
		}

		domInstance_material_Array& materialInstances = technique->getInstance_material_array();
		for(size_t m=0, count=materialInstances.getCount(); m<count; ++m)
		{
			const domInstance_materialRef& materialInstance = materialInstances.get(m);            
			domMaterialRef material = daeSafeCast<domMaterial>(materialInstance->getTarget().getElement());
			if(material == 0)
			{
				continue;
			}
			map.insert(std::make_pair(materialInstance->getSymbol(), material));
		}
	}
	//-----------------------------------------------------------------------
	void InstanceGeometryUtil::getSymbolMaterialMapping( const domInstance_geometry& instance, SymbolMaterialMap& map )
	{
		getSymbolMaterialMapping(&instance, map);
	}
}
