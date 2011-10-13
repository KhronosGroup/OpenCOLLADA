
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	if(NOT DEFINED WITH_IN_SOURCE_BUILD)
		message(FATAL_ERROR
			"CMake generation for OpenCollada is not allowed within the source directory!"
			"\n Remove the CMakeCache.txt file and try again from another folder, e.g.:"
			"\n "
			"\n rm CMakeCache.txt"
			"\n cd .."
			"\n mkdir cmake-make"
			"\n cd cmake-make"
			"\n cmake ../opencollada"
			"\n "
			"\n Alternately define WITH_IN_SOURCE_BUILD to force this option (not recommended!)"
		)
	endif()
endif()

cmake_minimum_required(VERSION 2.6)


#-----------------------------------------------------------------------------
# Set policy.

# see "cmake --help-policy CMP0003"
# So library linking is more sane
cmake_policy(SET CMP0003 NEW)

# So defines are automatically quoted
cmake_policy(SET CMP0005 NEW)

# So syntax problems are errors
cmake_policy(SET CMP0010 NEW)

# Input directories must have CMakeLists.txt
cmake_policy(SET CMP0014 NEW)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Externals/cmake-modules")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Only do Release and Debug" FORCE )
mark_as_advanced(CMAKE_CONFIGURATION_TYPES)


#-----------------------------------------------------------------------------
# Initialize project.

project(OPENCOLLADA)  # must be after setting cmake_configuration_types

# defines where specific parts of BRICS_MM are stored or created
set(LIBRARY_OUTPUT_PATH            ${CMAKE_HOME_DIRECTORY}/lib)  # static libraries 
set(EXECUTABLE_OUTPUT_PATH         ${CMAKE_HOME_DIRECTORY}/bin)  # executables 
set(EXTERNAL_LIBRARIES        	   ${CMAKE_HOME_DIRECTORY}/Externals)  # external libraries
set(CMAKE_MODULE_PATH "${EXTERNAL_LIBRARIES}/cmake-modules")

if (NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif ()

#-----------------------------------------------------------------------------
# Install vars

set(OPENCOLLADA_INST_INCLUDE ${CMAKE_INSTALL_PREFIX}/include/opencollada)
set(OPENCOLLADA_INST_LIBRARY ${CMAKE_INSTALL_PREFIX}/lib/opencollada)


#-----------------------------------------------------------------------------
# Redirect output files

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin CACHE INTERNAL "" FORCE )
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "" FORCE )


#-----------------------------------------------------------------------------
# Set default config options

option(USE_STATIC "Build static libraries"  ON)
option(USE_SHARED "Build shared libraries"  OFF)
option(USE_LIBXML "Use LibXml2 parser"      ON)
option(USE_EXPAT  "Use expat parser"        OFF)

#adding xml2
if (USE_LIBXML)
	add_definitions(
		-DGENERATEDSAXPARSER_XMLPARSER_LIBXML
		-DXMLPARSER_LIBXML
	)
	find_package(LibXml2)
	if (LIBXML2_FOUND)
		message(STATUS "SUCCESSFUL: LibXml2 found")
	else ()  # if xml2 not found building its local copy from ./Externals
		if (WIN32)
			message("WARNING: Native LibXml2 not found, taking LibXml from ./Externals")
			add_subdirectory(${EXTERNAL_LIBRARIES}/LibXML)
			set(LIBXML2_INCLUDE_DIR
				${libxml_include_dirs}				
			)
			set(LIBXML2_LIBRARIES xml)
		else ()
			message("ERROR: LibXml2 not found, please install xml2 library (for Debian libxml2-dev)")
		endif ()
	endif ()
endif ()

if (USE_EXPAT)
	add_definitions(-DGENERATEDSAXPARSER_XMLPARSER_EXPAT)
	message("FATAL: EXPAT support not implemented")
	# TODO:: use externals
endif ()

#adding PCRE
find_package(PCRE)
if (PCRE_FOUND)
	message(STATUS "SUCCESSFUL: PCRE found")
else ()  # if pcre not found building its local copy from ./Externals
	if (WIN32)
		message("WARNING: Native PCRE not found, taking PCRE from ./Externals")
		add_definitions(-DPCRE_STATIC)
		add_subdirectory(${EXTERNAL_LIBRARIES}/pcre)
		set(PCRE_INCLUDE_DIR ${libpcre_include_dirs})
		set(PCRE_LIBRARIES pcre)
	else ()
		message("ERROR: PCRE not found, please install pcre library")
	endif ()
endif ()

# building required libs
add_subdirectory(common/libftoa)
add_subdirectory(common/libBuffer)	
add_subdirectory(${EXTERNAL_LIBRARIES}/UTF)
add_subdirectory(${EXTERNAL_LIBRARIES}/MathMLSolver)

# building OpenCOLLADA libs
add_subdirectory(COLLADABaseUtils)
add_subdirectory(COLLADAFramework)
add_subdirectory(GeneratedSaxParser)
add_subdirectory(COLLADASaxFrameworkLoader)
add_subdirectory(COLLADAStreamWriter)

# building COLLADAValidator app
add_subdirectory(COLLADAValidator)


#-----------------------------------------------------------------------------
# Install
# - note, we may want to split this up into their separate projects

# COLLADABaseUtils
install(
	FILES
		COLLADABaseUtils/include/COLLADABUIDList.h
		COLLADABaseUtils/include/COLLADABUStableHeaders.h
		COLLADABaseUtils/include/COLLADABUNativeString.h
		COLLADABaseUtils/include/COLLADABUException.h
		COLLADABaseUtils/include/COLLADABU.h
		COLLADABaseUtils/include/COLLADABUhash_map.h
		COLLADABaseUtils/include/COLLADABUStringUtils.h
		COLLADABaseUtils/include/COLLADABUPrerequisites.h
		COLLADABaseUtils/include/COLLADABUPcreCompiledPattern.h
		COLLADABaseUtils/include/COLLADABUUtils.h
		COLLADABaseUtils/include/COLLADABUPlatform.h
		COLLADABaseUtils/include/COLLADABUURI.h
		COLLADABaseUtils/include/COLLADABUHashFunctions.h
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADABaseUtils
)
install(
	FILES
		COLLADABaseUtils/include/Math/COLLADABUMathUtils.h
		COLLADABaseUtils/include/Math/COLLADABUMathVector3.h
		COLLADABaseUtils/include/Math/COLLADABUMathMatrix3.h
		COLLADABaseUtils/include/Math/COLLADABUMathMatrix4.h
		COLLADABaseUtils/include/Math/COLLADABUMathQuaternion.h
		COLLADABaseUtils/include/Math/COLLADABUMathPrerequisites.h
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADABaseUtils/Math
)


# COLLADAFramework
install(
	FILES
		COLLADAFramework/include/COLLADAFW.h
		COLLADAFramework/include/COLLADAFWAnimatable.h
		COLLADAFramework/include/COLLADAFWAnimatableFloat.h
		COLLADAFramework/include/COLLADAFWAnimation.h
		COLLADAFramework/include/COLLADAFWAnimationCurve.h
		COLLADAFramework/include/COLLADAFWAnimationList.h
		COLLADAFramework/include/COLLADAFWAnnotate.h
		COLLADAFramework/include/COLLADAFWArray.h
		COLLADAFramework/include/COLLADAFWArrayPrimitiveType.h
		COLLADAFramework/include/COLLADAFWAxisInfo.h
		COLLADAFramework/include/COLLADAFWCamera.h
		COLLADAFramework/include/COLLADAFWCode.h
		COLLADAFramework/include/COLLADAFWColor.h
		COLLADAFramework/include/COLLADAFWColorOrTexture.h
		COLLADAFramework/include/COLLADAFWConstants.h
		COLLADAFramework/include/COLLADAFWController.h
		COLLADAFramework/include/COLLADAFWEdge.h
		COLLADAFramework/include/COLLADAFWEffect.h
		COLLADAFramework/include/COLLADAFWEffectCommon.h
		COLLADAFramework/include/COLLADAFWException.h
		COLLADAFramework/include/COLLADAFWFileInfo.h
		COLLADAFramework/include/COLLADAFWFloatOrDoubleArray.h
		COLLADAFramework/include/COLLADAFWFloatOrParam.h
		COLLADAFramework/include/COLLADAFWFormula.h
		COLLADAFramework/include/COLLADAFWFormulaNewParam.h
		COLLADAFramework/include/COLLADAFWFormulas.h
		COLLADAFramework/include/COLLADAFWGeometry.h
		COLLADAFramework/include/COLLADAFWHashFunctions.h
		COLLADAFramework/include/COLLADAFWILoader.h
		COLLADAFramework/include/COLLADAFWIWriter.h
		COLLADAFramework/include/COLLADAFWImage.h
		COLLADAFramework/include/COLLADAFWImageSource.h
		COLLADAFramework/include/COLLADAFWInclude.h
		COLLADAFramework/include/COLLADAFWIndexList.h
		COLLADAFramework/include/COLLADAFWInstanceBase.h
		COLLADAFramework/include/COLLADAFWInstanceBindingBase.h
		COLLADAFramework/include/COLLADAFWInstanceCamera.h
		COLLADAFramework/include/COLLADAFWInstanceController.h
		COLLADAFramework/include/COLLADAFWInstanceGeometry.h
		COLLADAFramework/include/COLLADAFWInstanceKinematicsScene.h
		COLLADAFramework/include/COLLADAFWInstanceLight.h
		COLLADAFramework/include/COLLADAFWInstanceNode.h
		COLLADAFramework/include/COLLADAFWInstanceSceneGraph.h
		COLLADAFramework/include/COLLADAFWInstanceVisualScene.h
		COLLADAFramework/include/COLLADAFWJoint.h
		COLLADAFramework/include/COLLADAFWJointPrimitive.h
		COLLADAFramework/include/COLLADAFWKinematicsController.h
		COLLADAFramework/include/COLLADAFWKinematicsModel.h
		COLLADAFramework/include/COLLADAFWKinematicsScene.h
		COLLADAFramework/include/COLLADAFWLibraryNodes.h
		COLLADAFramework/include/COLLADAFWLight.h
		COLLADAFramework/include/COLLADAFWLines.h
		COLLADAFramework/include/COLLADAFWLinestrips.h
		COLLADAFramework/include/COLLADAFWLoaderUtils.h
		COLLADAFramework/include/COLLADAFWLookat.h
		COLLADAFramework/include/COLLADAFWMaterial.h
		COLLADAFramework/include/COLLADAFWMaterialBinding.h
		COLLADAFramework/include/COLLADAFWMatrix.h
		COLLADAFramework/include/COLLADAFWMesh.h
		COLLADAFramework/include/COLLADAFWMeshPrimitive.h
		COLLADAFramework/include/COLLADAFWMeshPrimitiveWithFaceVertexCount.h
		COLLADAFramework/include/COLLADAFWMeshVertexData.h
		COLLADAFramework/include/COLLADAFWModifier.h
		COLLADAFramework/include/COLLADAFWMorphController.h
		COLLADAFramework/include/COLLADAFWMotionProfile.h
		COLLADAFramework/include/COLLADAFWNewParam.h
		COLLADAFramework/include/COLLADAFWNode.h
		COLLADAFramework/include/COLLADAFWObject.h
		COLLADAFramework/include/COLLADAFWParam.h
		COLLADAFramework/include/COLLADAFWPass.h
		COLLADAFramework/include/COLLADAFWPassClear.h
		COLLADAFramework/include/COLLADAFWPassOutput.h
		COLLADAFramework/include/COLLADAFWPassTarget.h
		COLLADAFramework/include/COLLADAFWPointerArray.h
		COLLADAFramework/include/COLLADAFWPolygons.h
		COLLADAFramework/include/COLLADAFWPrerequisites.h
		COLLADAFramework/include/COLLADAFWRenderDraw.h
		COLLADAFramework/include/COLLADAFWRenderState.h
		COLLADAFramework/include/COLLADAFWRenderStateStatic.h
		COLLADAFramework/include/COLLADAFWRoot.h
		COLLADAFramework/include/COLLADAFWRotate.h
		COLLADAFramework/include/COLLADAFWSampler.h
		COLLADAFramework/include/COLLADAFWScale.h
		COLLADAFramework/include/COLLADAFWScene.h
		COLLADAFramework/include/COLLADAFWSemantic.h
		COLLADAFramework/include/COLLADAFWSetParam.h
		COLLADAFramework/include/COLLADAFWShader.h
		COLLADAFramework/include/COLLADAFWShaderBlinn.h
		COLLADAFramework/include/COLLADAFWShaderConstantFX.h
		COLLADAFramework/include/COLLADAFWShaderElement.h
		COLLADAFramework/include/COLLADAFWShaderLambert.h
		COLLADAFramework/include/COLLADAFWShaderPhong.h
		COLLADAFramework/include/COLLADAFWShear.h
		COLLADAFramework/include/COLLADAFWSkew.h
		COLLADAFramework/include/COLLADAFWSkinController.h
		COLLADAFramework/include/COLLADAFWSkinControllerData.h
		COLLADAFramework/include/COLLADAFWStableHeaders.h
		COLLADAFramework/include/COLLADAFWTarget.h
		COLLADAFramework/include/COLLADAFWTargetableValue.h
		COLLADAFramework/include/COLLADAFWTechnique.h
		COLLADAFramework/include/COLLADAFWTexture.h
		COLLADAFramework/include/COLLADAFWTextureCoordinateBinding.h
		COLLADAFramework/include/COLLADAFWTransformation.h
		COLLADAFramework/include/COLLADAFWTranslate.h
		COLLADAFramework/include/COLLADAFWTriangles.h
		COLLADAFramework/include/COLLADAFWTrifans.h
		COLLADAFramework/include/COLLADAFWTristrips.h
		COLLADAFramework/include/COLLADAFWTypes.h
		COLLADAFramework/include/COLLADAFWUniqueId.h
		COLLADAFramework/include/COLLADAFWValidate.h
		COLLADAFramework/include/COLLADAFWValueType.h
		COLLADAFramework/include/COLLADAFWVisualScene.h
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADAFramework
)


# COLLADASaxFrameworkLoader
install(
	FILES
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLAccessor.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLArrayElement.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLAssetLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLCOLLADACsymbol.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLDocumentProcessor.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLException.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLExtraDataElementHandler.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLExtraDataLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLFileLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLFilePartLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLFormulasLinker.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLFormulasLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLGeometryLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLGeometryMaterialIdInfo.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLHelperLoaderBase.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIError.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIErrorHandler.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIExtraDataCallbackHandler.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIFilePartLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIParserImpl.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIParserImpl14.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIParserImpl15.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLInputShared.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLInputUnshared.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLInstanceArticulatedSystemLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLInstanceKinematicsModelLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLIntermediateTargetable.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLInterpolationTypeSource.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLJointsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLKinematicsIntermediateData.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLKinematicsSceneCreator.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryAnimationsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryArticulatedSystemsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryCamerasLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryControllersLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryEffectsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryFormulasLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryImagesLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryJointsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryKinematicsModelsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryKinematicsScenesLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryLightsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryMaterialsLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLibraryNodesLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLMeshLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLMeshPrimitiveInputList.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLNodeLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLPHElement.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLPolygons.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLPostProcessor.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLPrerequisites.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLPrimitiveBase.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLRootParser14.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLRootParser15.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSaxFWLError.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSaxParserError.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSaxParserErrorHandler.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSceneLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSidAddress.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSidTreeNode.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSource.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLSourceArrayLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLStableHeaders.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLTechniqueCommon.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLTransformationLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLTypes.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLUtils.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLVersionParser.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLVertices.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLVisualSceneLoader.h
		COLLADASaxFrameworkLoader/include/COLLADASaxFWLXmlTypes.h
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADASaxFrameworkLoader
)
install(
	DIRECTORY
		COLLADASaxFrameworkLoader/include/generated14
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADASaxFrameworkLoader
	PATTERN ".svn" EXCLUDE
)
install(
	DIRECTORY
		COLLADASaxFrameworkLoader/include/generated15
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADASaxFrameworkLoader
	PATTERN ".svn" EXCLUDE
)


# COLLADAStreamWriter
install(
	FILES
		COLLADAStreamWriter/include/COLLADASWAnnotation.h
		COLLADAStreamWriter/include/COLLADASWAsset.h
		COLLADAStreamWriter/include/COLLADASWBaseElement.h
		COLLADAStreamWriter/include/COLLADASWBaseInputElement.h
		COLLADAStreamWriter/include/COLLADASWBindMaterial.h
		COLLADAStreamWriter/include/COLLADASWBuffer.h
		COLLADAStreamWriter/include/COLLADASWCamera.h
		COLLADAStreamWriter/include/COLLADASWCameraOptic.h
		COLLADAStreamWriter/include/COLLADASWCode.h
		COLLADAStreamWriter/include/COLLADASWColor.h
		COLLADAStreamWriter/include/COLLADASWColorOrTexture.h
		COLLADAStreamWriter/include/COLLADASWConstants.h
		COLLADAStreamWriter/include/COLLADASWControlVertices.h
		COLLADAStreamWriter/include/COLLADASWEffectProfile.h
		COLLADAStreamWriter/include/COLLADASWElementWriter.h
		COLLADAStreamWriter/include/COLLADASWException.h
		COLLADAStreamWriter/include/COLLADASWExtra.h
		COLLADAStreamWriter/include/COLLADASWExtraTechnique.h
		COLLADAStreamWriter/include/COLLADASWFormatHint.h
		COLLADAStreamWriter/include/COLLADASWImage.h
		COLLADAStreamWriter/include/COLLADASWInclude.h
		COLLADAStreamWriter/include/COLLADASWInputList.h
		COLLADAStreamWriter/include/COLLADASWInstanceCamera.h
		COLLADAStreamWriter/include/COLLADASWInstanceController.h
		COLLADAStreamWriter/include/COLLADASWInstanceEffect.h
		COLLADAStreamWriter/include/COLLADASWInstanceGeometry.h
		COLLADAStreamWriter/include/COLLADASWInstanceLight.h
		COLLADAStreamWriter/include/COLLADASWInstanceMaterial.h
		COLLADAStreamWriter/include/COLLADASWInstanceNode.h
		COLLADAStreamWriter/include/COLLADASWLibrary.h
		COLLADAStreamWriter/include/COLLADASWLibraryAnimationClips.h
		COLLADAStreamWriter/include/COLLADASWLibraryAnimations.h
		COLLADAStreamWriter/include/COLLADASWLibraryCameras.h
		COLLADAStreamWriter/include/COLLADASWLibraryControllers.h
		COLLADAStreamWriter/include/COLLADASWLibraryEffects.h
		COLLADAStreamWriter/include/COLLADASWLibraryGeometries.h
		COLLADAStreamWriter/include/COLLADASWLibraryImages.h
		COLLADAStreamWriter/include/COLLADASWLibraryLights.h
		COLLADAStreamWriter/include/COLLADASWLibraryMaterials.h
		COLLADAStreamWriter/include/COLLADASWLibraryVisualScenes.h
		COLLADAStreamWriter/include/COLLADASWLight.h
		COLLADAStreamWriter/include/COLLADASWNode.h
		COLLADAStreamWriter/include/COLLADASWOpenGLConstants.h
		COLLADAStreamWriter/include/COLLADASWParamBase.h
		COLLADAStreamWriter/include/COLLADASWParamTemplate.h
		COLLADAStreamWriter/include/COLLADASWPass.h
		COLLADAStreamWriter/include/COLLADASWPlatform.h
		COLLADAStreamWriter/include/COLLADASWPrerequisites.h
		COLLADAStreamWriter/include/COLLADASWPrimitves.h
		COLLADAStreamWriter/include/COLLADASWRenderState.h
		COLLADAStreamWriter/include/COLLADASWRenderStateStatic.h
		COLLADAStreamWriter/include/COLLADASWSampler.h
		COLLADAStreamWriter/include/COLLADASWScene.h
		COLLADAStreamWriter/include/COLLADASWShader.h
		COLLADAStreamWriter/include/COLLADASWSource.h
		COLLADAStreamWriter/include/COLLADASWStreamWriter.h
		COLLADAStreamWriter/include/COLLADASWSurfaceInitOption.h
		COLLADAStreamWriter/include/COLLADASWTechnique.h
		COLLADAStreamWriter/include/COLLADASWTechniqueFX.h
		COLLADAStreamWriter/include/COLLADASWTexture.h
		COLLADAStreamWriter/include/COLLADASWValueType.h
		COLLADAStreamWriter/include/COLLADASWVertices.h
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/COLLADABaseUtils/Math
)


# GeneratedSaxParser
install(
	FILES
		GeneratedSaxParser/include/GeneratedSaxParser.h
		GeneratedSaxParser/include/GeneratedSaxParserCoutErrorHandler.h
		GeneratedSaxParser/include/GeneratedSaxParserExpatSaxParser.h
		GeneratedSaxParser/include/GeneratedSaxParserIErrorHandler.h
		GeneratedSaxParser/include/GeneratedSaxParserINamespaceHandler.h
		GeneratedSaxParser/include/GeneratedSaxParserIUnknownElementHandler.h
		GeneratedSaxParser/include/GeneratedSaxParserLibxmlSaxParser.h
		GeneratedSaxParser/include/GeneratedSaxParserNamespaceStack.h
		GeneratedSaxParser/include/GeneratedSaxParserParser.h
		GeneratedSaxParser/include/GeneratedSaxParserParserError.h
		GeneratedSaxParser/include/GeneratedSaxParserParserTemplate.h
		GeneratedSaxParser/include/GeneratedSaxParserParserTemplateBase.h
		GeneratedSaxParser/include/GeneratedSaxParserPrerequisites.h
		GeneratedSaxParser/include/GeneratedSaxParserRawUnknownElementHandler.h
		GeneratedSaxParser/include/GeneratedSaxParserSaxParser.h
		GeneratedSaxParser/include/GeneratedSaxParserStackMemoryManager.h
		GeneratedSaxParser/include/GeneratedSaxParserTypes.h
		GeneratedSaxParser/include/GeneratedSaxParserUtils.h
	DESTINATION
		${OPENCOLLADA_INST_INCLUDE}/GeneratedSaxParser
)
