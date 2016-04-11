COLLADAMaya is a new implementation of a Autodesk Maya plug-in to export a 
Maya scene or parts of it to a COLLADA file, released under the MIT-license. 

This plug-in does not store the COLLADA document in an intermidiate data 
model, it writes the data directly into file. This results in reduction of 
memory consumption and better performance.

For installation instructions please read the "INSTALL" file.




General export options in OpenColladaMaya export plugin:


Bezier/Baking Animation:
You can export animation into two different mode: Bezier or Baked (stacked matrix)
In Bezier mode, no sampling is use to get key animation value
In Baked mode, sampling is use to get animation value at constant sampling rate
use "Bake transforms" option if you want to bake animation, in the other case you will have bezier animation exported

Constant Key Bezier Animation Optimization:
If you export animations with "Bake transforms" options, constant key animation (same value for all keyframes) will be automatically removed
If you want to remove constant key frames in Bezier mode, use "Optimize Animations" options
When you export Bezier animation, you will have animation value for translation X,Y,Z and Rotation X,Y,Z even if the value is constant
When you use "Optimize Animations" in Bezier Animation mode, only useful (not constant value) from translation X,Y,Z or Rotation X,Y,Z will be exported


Pose Animation :
If you want to export Pose Animation (only 1 key frame animation), be careful to set Source Start = Source End = 0 in Animation Clip Attributes in Maya


Split animation/Mesh into two differents DAE files:
use Polygon Meshes and Skin and Joints options ( no Animations option) if you want to export only Mesh into one DAE
use Animations and Joints options (no Polygon Meshes and no Skin option) if you want to export only Animation into one DAE
if you want to export full animation and mesh into the same DAE, use Polygon Meshes and Skin and Joints and Animations options
