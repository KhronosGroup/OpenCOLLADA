#include "COLLADAMayaStableHeaders.h"

#ifdef _WIN32
# pragma warning(disable: 4312)
#endif

#include "cgfxAttrDef.cpp"
#if MAYA_API_VERSION > 700
#include "cgfxEffectDef.cpp"
#endif // MAYA_API_VERSION > 700
#include "cgfxFindImage.cpp"
#include "cgfxShaderCmd.cpp"
#include "cgfxShaderNode.cpp"
#include "cgfxVector.cpp"
#include "nv_dds.cpp"

#ifdef _WIN32
# pragma warning(default: 4312)
#endif

