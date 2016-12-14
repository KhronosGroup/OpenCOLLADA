COLLADAMaya is a new implementation of a Autodesk Maya plug-in to export a 
Maya scene or parts of it to a COLLADA file, released under the MIT-license. 

This plug-in does not store the COLLADA document in an intermidiate data 
model, it writes the data directly into file. This results in reduction of 
memory consumption and better performance.

For installation instructions please read the "INSTALL" file.


- General export options in OpenColladaMaya export plugin:

	. Encoding names
By default, All names (https://www.w3.org/TR/REC-xml/#NT-Name) will be UCS-2 encoded (https://msdn.microsoft.com/en-us/library/35577sxd(v=vs.80).aspx)
Any XML name character that does not conform to the XML 1.0 spec (fourth edition) recommendation is escaped as _xHHHH_
The HHHH string stands for the four-digit hexadecimal UCS-2 code for the character in most significant bit first order
For example, the name Order Details is encoded as Order_x0020_Details.

If you need backward compatible behavior (all non conformant characters will be replaced by '_' ) please turn off "Encode Names" option


	. Bezier/Baking Animation:
	
You can export animation into two different mode: Bezier or Baked (stacked matrix)
In Bezier mode, no sampling is use to get key animation value
In Baked mode, sampling is use to get animation value at constant sampling rate
use "Bake transforms" option if you want to bake animation, in the other case you will have bezier animation exported

	. Constant Key Bezier Animation Optimization:
	
If you export animations with "Bake transforms" options, constant key animation (same value for all keyframes) will be automatically removed
If you want to remove constant key frames in Bezier mode, use "Optimize Animations" options
When you export Bezier animation, you will have animation value for translation X,Y,Z and Rotation X,Y,Z even if the value is constant
When you use "Optimize Animations" in Bezier Animation mode, only useful (not constant value) from translation X,Y,Z or Rotation X,Y,Z will be exported

	. Pose Animation:
	
If you want to export Pose Animation (only 1 key frame animation), be careful to set Source Start = Source End = 0 in Animation Clip Attributes in Maya

	. Split animation/Mesh into two differents DAE files:
	
use Polygon Meshes and Skin and Joints options ( no Animations option) if you want to export only Mesh into one DAE
use Animations and Joints options (no Polygon Meshes and no Skin option) if you want to export only Animation into one DAE
if you want to export full animation and mesh into the same DAE, use Polygon Meshes and Skin and Joints and Animations options


- Extra Attributes

This plug-in currently supports export of Maya extra attributes for the following Maya node types:
	. Transform (in <node>)
	. Mesh shape (in <geometry>)
	. Light shape (in <light>)
	. PhysX RigidBody (in <rigid_body>)
	. PhysX PhysicsShape (in <shape>)
	. PhysX RigidConstraint (in <rigid_constraint>)

Extra attributes are exported in <extra>/<technique profile="OpenCOLLADAMaya"> section of corresponding COLLADA element with the following syntax:

<param name="attribute_name" type="attribute_type">attribute_value</param>

	. attribute_name is the name of the extra attribute.
	. attribute_type is the type of the extra attribute. Supported types are:
		. "int" (Maya extra attribute type: Integer)
		. "string" (Maya extra attribute type: String or Enum)
		. "float" (Maya extra attribute type: Float)
		. "bool" (Maya extra attribute type: Boolean)
		. "double3" (Maya extra attribute type: Vector)
	. attribute_value is the extra attribute value as text.