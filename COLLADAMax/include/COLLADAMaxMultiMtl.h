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


#ifndef _COLLADAMAX_MULTI_MTL_H_
#define _COLLADAMAX_MULTI_MTL_H_

#include "COLLADAMaxPrerequisites.h"

namespace COLLADAMax
{

    // The information from this file comes from the MaxSDK sample: /material/multi.cpp.

    namespace MultiMaterial
    {
        const Class_ID classID ( MULTI_CLASS_ID, 0 );
        // Reference #s.
        const unsigned int PBLOCK_REF = 0;
        const unsigned int MTL_REF = 1;

        // multi_params param IDs
        enum
        {
            multi_mtls,
            multi_ons,
            multi_names,
            multi_ids,
        };
    }

    // From the SDK sample /material/composit.cpp

    namespace CompositeMap
    {
        const Class_ID classID ( COMPOSITE_CLASS_ID, 0 );

        // Parameter and ParamBlock IDs
        enum { comptex_params, };  // pblock ID
        // param IDs
        enum
        {
            comptex_tex, comptex_ons

        };
    }

    namespace MixMap
    {
        // Mix controller param IDs
        enum
        {
            mix_mix, mix_curvea, mix_curveb, mix_usecurve,
            mix_color1, mix_color2,
            mix_map1, mix_map2, mix_mask,
            mix_map1_on, mix_map2_on, mix_mask_on,      // main grad params
            mix_output
        };
    }

    namespace CompositeMtl
    {
        const Class_ID classID ( 0x61dc0cd7, 0x13640af6 );

        enum { compmat_params, };  // pblock ID

        enum
        {
            compmat_mtls,
            compmat_type,
            compmat_map_on,
            compmat_amount
        };
    }

    // This information is taken from the 'StdMat2' sample.

    namespace StandardMaterial
    {
        // reference numbers
        const unsigned int OLD_PBLOCK_REF = 0;
        const unsigned int TEXMAPS_REF = 1;
        const unsigned int SHADER_REF = 2;
        const unsigned int SHADER_PB_REF = 3;
        const unsigned int EXTENDED_PB_REF = 4;
        const unsigned int SAMPLING_PB_REF = 5;
        const unsigned int MAPS_PB_REF = 6;
        const unsigned int DYNAMICS_PB_REF = 7;  
        const unsigned int SAMPLER_REF = 8;

        // shdr_params param IDs
        enum
        {
            shdr_ambient, shdr_diffuse, shdr_specular,
            shdr_ad_texlock, shdr_ad_lock, shdr_ds_lock,
            shdr_use_self_illum_color, shdr_self_illum_amnt, shdr_self_illum_color,
            shdr_spec_lvl, shdr_glossiness, shdr_soften
        };

        // std2_shader param IDs
        enum
        {
            std2_shader_type, std2_wire, std2_two_sided, std2_face_map, std2_faceted,
            std2_shader_by_name,       // virtual param for accessing shader type by name
        };

        // std2_extended param IDs
        enum
        {
            std2_opacity_type, std2_opacity, std2_filter_color, std2_ep_filter_map,
            std2_falloff_type, std2_falloff_amnt,
            std2_ior,
            std2_wire_size, std2_wire_units,
            std2_apply_refl_dimming, std2_dim_lvl, std2_refl_lvl,
            std2_translucent_blur, std2_ep_translucent_blur_map,
            std2_translucent_color, std2_ep_translucent_color_map,
        };

        // std2_sampling param IDs
        enum
        {
            std2_ssampler, std2_ssampler_qual, std2_ssampler_enable,
            std2_ssampler_adapt_on, std2_ssampler_adapt_threshold, std2_ssampler_advanced,
            std2_ssampler_subsample_tex_on, std2_ssampler_by_name,
            std2_ssampler_param0, std2_ssampler_param1, std2_ssampler_useglobal
        };

        // std_maps param IDs
        enum
        {
            std2_map_enables, std2_maps, std2_map_amnts, std2_mp_ad_texlock,
        };

        // std2_dynamics param IDs
        enum
        {
            std2_bounce, std2_static_friction, std2_sliding_friction,
        };

        enum ShaderClassID
        {
            STD2_PHONG_CLASS_ID = 0x00000037,
            STD2_BLINN_SHADER_CLASS_ID = 0x00000038,
            STD2_METAL_SHADER_CLASS_ID = 0x00000039,
            STD2_ANISOTROPIC_SHADER_CLASS_ID = 0x2857f460,
            STD2_MULTI_LAYER_SHADER_CLASS_ID = 0x2857f470,
            STD2_OREN_NAYER_BLINN_CLASS_ID = 0x2857f421
        };
    }

    namespace StdUVGenEnums
    {
        enum { pblock };

        // paramblock subanims
        enum
        {
            u_offset,
            v_offset,
            u_tiling,
            v_tiling,
            u_angle,
            v_angle,
            w_angle,
            blur,
            noise_amt,
            noise_size,
            noise_level,
            phase,
            blur_offset,
            num_subs
        };
    }


    // All values in here were devined by trial and error

    namespace TextureOutputIDs
    {
        // Paramblock Ref Id
        enum RefIds
        {
            param_block_ref_id,
            unknown1,
            unknown2
        };

        enum ParamBlockIds
        {
            rgb_level,
            rgb_offset,
            output_amount,
            bump_amount,
        };
    }



}


#endif // _COLLADAMAX_MULTI_MTL_H_
