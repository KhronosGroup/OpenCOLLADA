
dae23ds_lib3ds is based on dae23ds, and use lib3ds to make the 
conversion routine more concise.
You can contact me by <yaoyansi2@yahoo.com.cn>

FEATURES
- export mesh, material, light, camera.

NOTE:
- the 3ds file exported can be import to maya with 3dsimport.mll plugin, 
  but the transform information is lost. So, you can view the 3ds file exported through Deep Exploration.
  

LIMITS:
- No mesh splitting

COMPILE:
1. build Debug_Expat version.
open the configuration manager, and choose the following settings:
COLLADABaseUtils----------Debug
COLLADAFrameword----------Debug
COLLADASaxFrameworkLoader-Debug_Expat
dae23ds-------------------Debug
expat_static--------------Debug
GeneratedSaxParser--------Debug_Expat
LibXML--------------------Debug
MathMLSolver--------------Debug
pcre----------------------Debug

2.or build Release_Expat version
open the configuration manager, and choose the following settings:
COLLADABaseUtils------------Release
COLLADAFrameword------------Release
COLLADASaxFrameworkLoader---Release_Expat
dae23ds---------------------Release
expat_static----------------Release
GeneratedSaxParser----------Release_Expat
LibXML----------------------Release
MathMLSolver----------------Release
pcre------------------------Release
