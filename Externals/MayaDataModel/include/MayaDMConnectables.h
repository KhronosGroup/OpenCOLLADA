/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONNECTABLES_H__
#define __MayaDM_CONNECTABLES_H__
#include <string>
namespace MayaDM
{
struct DoubleID
{
	std::string ID;
	DoubleID(const std::string& id):ID(id){}
	DoubleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct MatrixID
{
	std::string ID;
	MatrixID(const std::string& id):ID(id){}
	MatrixID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TargetID
{
	std::string ID;
	TargetID(const std::string& id):ID(id){}
	TargetID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Double3ID
{
	std::string ID;
	Double3ID(const std::string& id):ID(id){}
	Double3ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct UnsignedintID
{
	std::string ID;
	UnsignedintID(const std::string& id):ID(id){}
	UnsignedintID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BoolID
{
	std::string ID;
	BoolID(const std::string& id):ID(id){}
	BoolID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DirectionID
{
	std::string ID;
	DirectionID(const std::string& id):ID(id){}
	DirectionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NurbsCurveID
{
	std::string ID;
	NurbsCurveID(const std::string& id):ID(id){}
	NurbsCurveID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FloatID
{
	std::string ID;
	FloatID(const std::string& id):ID(id){}
	FloatID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NurbsSurfaceID
{
	std::string ID;
	NurbsSurfaceID(const std::string& id):ID(id){}
	NurbsSurfaceID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AxisAngleID
{
	std::string ID;
	AxisAngleID(const std::string& id):ID(id){}
	AxisAngleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FunctionID
{
	std::string ID;
	FunctionID(const std::string& id):ID(id){}
	FunctionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TimeID
{
	std::string ID;
	TimeID(const std::string& id):ID(id){}
	TimeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct MessageID
{
	std::string ID;
	MessageID(const std::string& id):ID(id){}
	MessageID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DoubleArrayID
{
	std::string ID;
	DoubleArrayID(const std::string& id):ID(id){}
	DoubleArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Float3ID
{
	std::string ID;
	Float3ID(const std::string& id):ID(id){}
	Float3ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ShortID
{
	std::string ID;
	ShortID(const std::string& id):ID(id){}
	ShortID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StringID
{
	std::string ID;
	StringID(const std::string& id):ID(id){}
	StringID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct MentalRayControlsID
{
	std::string ID;
	MentalRayControlsID(const std::string& id):ID(id){}
	MentalRayControlsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GenerictypeddataID
{
	std::string ID;
	GenerictypeddataID(const std::string& id):ID(id){}
	GenerictypeddataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct IntID
{
	std::string ID;
	IntID(const std::string& id):ID(id){}
	IntID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SmapWindowID
{
	std::string ID;
	SmapWindowID(const std::string& id):ID(id){}
	SmapWindowID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct VectorArrayID
{
	std::string ID;
	VectorArrayID(const std::string& id):ID(id){}
	VectorArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ResultID
{
	std::string ID;
	ResultID(const std::string& id):ID(id){}
	ResultID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AddrID
{
	std::string ID;
	AddrID(const std::string& id):ID(id){}
	AddrID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct MeshID
{
	std::string ID;
	MeshID(const std::string& id):ID(id){}
	MeshID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputTargetID
{
	std::string ID;
	InputTargetID(const std::string& id):ID(id){}
	InputTargetID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputTargetGroupID
{
	std::string ID;
	InputTargetGroupID(const std::string& id):ID(id){}
	InputTargetGroupID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputTargetItemID
{
	std::string ID;
	InputTargetItemID(const std::string& id):ID(id){}
	InputTargetItemID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GeometryID
{
	std::string ID;
	GeometryID(const std::string& id):ID(id){}
	GeometryID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PointArrayID
{
	std::string ID;
	PointArrayID(const std::string& id):ID(id){}
	PointArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ComponentListID
{
	std::string ID;
	ComponentListID(const std::string& id):ID(id){}
	ComponentListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NurbsShellID
{
	std::string ID;
	NurbsShellID(const std::string& id):ID(id){}
	NurbsShellID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DynBrushID
{
	std::string ID;
	DynBrushID(const std::string& id):ID(id){}
	DynBrushID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LeafCurlID
{
	std::string ID;
	LeafCurlID(const std::string& id):ID(id){}
	LeafCurlID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PetalCurlID
{
	std::string ID;
	PetalCurlID(const std::string& id):ID(id){}
	PetalCurlID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct WidthScaleID
{
	std::string ID;
	WidthScaleID(const std::string& id):ID(id){}
	WidthScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LeafWidthScaleID
{
	std::string ID;
	LeafWidthScaleID(const std::string& id):ID(id){}
	LeafWidthScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PetalWidthScaleID
{
	std::string ID;
	PetalWidthScaleID(const std::string& id):ID(id){}
	PetalWidthScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TwigLengthScaleID
{
	std::string ID;
	TwigLengthScaleID(const std::string& id):ID(id){}
	TwigLengthScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EnvironmentID
{
	std::string ID;
	EnvironmentID(const std::string& id):ID(id){}
	EnvironmentID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ReflectionRolloffID
{
	std::string ID;
	ReflectionRolloffID(const std::string& id):ID(id){}
	ReflectionRolloffID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Float2ID
{
	std::string ID;
	Float2ID(const std::string& id):ID(id){}
	Float2ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GenericID
{
	std::string ID;
	GenericID(const std::string& id):ID(id){}
	GenericID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InCacheID
{
	std::string ID;
	InCacheID(const std::string& id):ID(id){}
	InCacheID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CacheDataID
{
	std::string ID;
	CacheDataID(const std::string& id):ID(id){}
	CacheDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Double2ID
{
	std::string ID;
	Double2ID(const std::string& id):ID(id){}
	Double2ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PostProjectionID
{
	std::string ID;
	PostProjectionID(const std::string& id):ID(id){}
	PostProjectionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FilmRollControlID
{
	std::string ID;
	FilmRollControlID(const std::string& id):ID(id){}
	FilmRollControlID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEvaluateID
{
	std::string ID;
	ClipEvaluateID(const std::string& id):ID(id){}
	ClipEvaluateID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEvaluate_InmapID
{
	std::string ID;
	ClipEvaluate_InmapID(const std::string& id):ID(id){}
	ClipEvaluate_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEvaluate_OutmapID
{
	std::string ID;
	ClipEvaluate_OutmapID(const std::string& id):ID(id){}
	ClipEvaluate_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CharacterMappingID
{
	std::string ID;
	CharacterMappingID(const std::string& id):ID(id){}
	CharacterMappingID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEvalListID
{
	std::string ID;
	ClipEvalListID(const std::string& id):ID(id){}
	ClipEvalListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEvalID
{
	std::string ID;
	ClipEvalID(const std::string& id):ID(id){}
	ClipEvalID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEval_InmapID
{
	std::string ID;
	ClipEval_InmapID(const std::string& id):ID(id){}
	ClipEval_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipEval_OutmapID
{
	std::string ID;
	ClipEval_OutmapID(const std::string& id):ID(id){}
	ClipEval_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CharacterdataID
{
	std::string ID;
	CharacterdataID(const std::string& id):ID(id){}
	CharacterdataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct IntArrayID
{
	std::string ID;
	IntArrayID(const std::string& id):ID(id){}
	IntArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BlendListID
{
	std::string ID;
	BlendListID(const std::string& id):ID(id){}
	BlendListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BlendList_InmapID
{
	std::string ID;
	BlendList_InmapID(const std::string& id):ID(id){}
	BlendList_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BlendList_OutmapID
{
	std::string ID;
	BlendList_OutmapID(const std::string& id):ID(id){}
	BlendList_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipFunctionID
{
	std::string ID;
	ClipFunctionID(const std::string& id):ID(id){}
	ClipFunctionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipFunction_InmapID
{
	std::string ID;
	ClipFunction_InmapID(const std::string& id):ID(id){}
	ClipFunction_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClipFunction_OutmapID
{
	std::string ID;
	ClipFunction_OutmapID(const std::string& id):ID(id){}
	ClipFunction_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FltMatrixID
{
	std::string ID;
	FltMatrixID(const std::string& id):ID(id){}
	FltMatrixID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClusterXformsID
{
	std::string ID;
	ClusterXformsID(const std::string& id):ID(id){}
	ClusterXformsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClusterTransformsID
{
	std::string ID;
	ClusterTransformsID(const std::string& id):ID(id){}
	ClusterTransformsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct UvSetID
{
	std::string ID;
	UvSetID(const std::string& id):ID(id){}
	UvSetID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorSetID
{
	std::string ID;
	ColorSetID(const std::string& id):ID(id){}
	ColorSetID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorSetPointsID
{
	std::string ID;
	ColorSetPointsID(const std::string& id):ID(id){}
	ColorSetPointsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SubdivisionSurfaceID
{
	std::string ID;
	SubdivisionSurfaceID(const std::string& id):ID(id){}
	SubdivisionSurfaceID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BoundingBoxID
{
	std::string ID;
	BoundingBoxID(const std::string& id):ID(id){}
	BoundingBoxID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InstObjGroupsID
{
	std::string ID;
	InstObjGroupsID(const std::string& id):ID(id){}
	InstObjGroupsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ObjectGroupsID
{
	std::string ID;
	ObjectGroupsID(const std::string& id):ID(id){}
	ObjectGroupsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DrawOverrideID
{
	std::string ID;
	DrawOverrideID(const std::string& id):ID(id){}
	DrawOverrideID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct UnsignedcharID
{
	std::string ID;
	UnsignedcharID(const std::string& id):ID(id){}
	UnsignedcharID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RenderInfoID
{
	std::string ID;
	RenderInfoID(const std::string& id):ID(id){}
	RenderInfoID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RenderLayerInfoID
{
	std::string ID;
	RenderLayerInfoID(const std::string& id):ID(id){}
	RenderLayerInfoID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GhostCustomStepsID
{
	std::string ID;
	GhostCustomStepsID(const std::string& id):ID(id){}
	GhostCustomStepsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LightDataID
{
	std::string ID;
	LightDataID(const std::string& id):ID(id){}
	LightDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DrawInfoID
{
	std::string ID;
	DrawInfoID(const std::string& id):ID(id){}
	DrawInfoID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputID
{
	std::string ID;
	InputID(const std::string& id):ID(id){}
	InputID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NIdID
{
	std::string ID;
	NIdID(const std::string& id):ID(id){}
	NIdID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ConnectionDensityRangeID
{
	std::string ID;
	ConnectionDensityRangeID(const std::string& id):ID(id){}
	ConnectionDensityRangeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StrengthDropoffID
{
	std::string ID;
	StrengthDropoffID(const std::string& id):ID(id){}
	StrengthDropoffID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RadiusMapUSamplesID
{
	std::string ID;
	RadiusMapUSamplesID(const std::string& id):ID(id){}
	RadiusMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RadiusMapVSamplesID
{
	std::string ID;
	RadiusMapVSamplesID(const std::string& id):ID(id){}
	RadiusMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PowerMapUSamplesID
{
	std::string ID;
	PowerMapUSamplesID(const std::string& id):ID(id){}
	PowerMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PowerMapVSamplesID
{
	std::string ID;
	PowerMapVSamplesID(const std::string& id):ID(id){}
	PowerMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InfluenceMapUSamplesID
{
	std::string ID;
	InfluenceMapUSamplesID(const std::string& id):ID(id){}
	InfluenceMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InfluenceMapVSamplesID
{
	std::string ID;
	InfluenceMapVSamplesID(const std::string& id):ID(id){}
	InfluenceMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StartLengthMapUSamplesID
{
	std::string ID;
	StartLengthMapUSamplesID(const std::string& id):ID(id){}
	StartLengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StartLengthMapVSamplesID
{
	std::string ID;
	StartLengthMapVSamplesID(const std::string& id):ID(id){}
	StartLengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EndLengthMapUSamplesID
{
	std::string ID;
	EndLengthMapUSamplesID(const std::string& id):ID(id){}
	EndLengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EndLengthMapVSamplesID
{
	std::string ID;
	EndLengthMapVSamplesID(const std::string& id):ID(id){}
	EndLengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ThresholdLengthMapUSamplesID
{
	std::string ID;
	ThresholdLengthMapUSamplesID(const std::string& id):ID(id){}
	ThresholdLengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ThresholdLengthMapVSamplesID
{
	std::string ID;
	ThresholdLengthMapVSamplesID(const std::string& id):ID(id){}
	ThresholdLengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveRadiusMapUSamplesID
{
	std::string ID;
	CurveRadiusMapUSamplesID(const std::string& id):ID(id){}
	CurveRadiusMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveRadiusMapVSamplesID
{
	std::string ID;
	CurveRadiusMapVSamplesID(const std::string& id):ID(id){}
	CurveRadiusMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurvePowerMapUSamplesID
{
	std::string ID;
	CurvePowerMapUSamplesID(const std::string& id):ID(id){}
	CurvePowerMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurvePowerMapVSamplesID
{
	std::string ID;
	CurvePowerMapVSamplesID(const std::string& id):ID(id){}
	CurvePowerMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveInfluenceMapUSamplesID
{
	std::string ID;
	CurveInfluenceMapUSamplesID(const std::string& id):ID(id){}
	CurveInfluenceMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveInfluenceMapVSamplesID
{
	std::string ID;
	CurveInfluenceMapVSamplesID(const std::string& id):ID(id){}
	CurveInfluenceMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveStartLengthMapUSamplesID
{
	std::string ID;
	CurveStartLengthMapUSamplesID(const std::string& id):ID(id){}
	CurveStartLengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveStartLengthMapVSamplesID
{
	std::string ID;
	CurveStartLengthMapVSamplesID(const std::string& id):ID(id){}
	CurveStartLengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveEndLengthMapUSamplesID
{
	std::string ID;
	CurveEndLengthMapUSamplesID(const std::string& id):ID(id){}
	CurveEndLengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveEndLengthMapVSamplesID
{
	std::string ID;
	CurveEndLengthMapVSamplesID(const std::string& id):ID(id){}
	CurveEndLengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveThresholdLengthMapUSamplesID
{
	std::string ID;
	CurveThresholdLengthMapUSamplesID(const std::string& id):ID(id){}
	CurveThresholdLengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurveThresholdLengthMapVSamplesID
{
	std::string ID;
	CurveThresholdLengthMapVSamplesID(const std::string& id):ID(id){}
	CurveThresholdLengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseColorMapUSamplesID
{
	std::string ID;
	BaseColorMapUSamplesID(const std::string& id):ID(id){}
	BaseColorMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseColorMapVSamplesID
{
	std::string ID;
	BaseColorMapVSamplesID(const std::string& id):ID(id){}
	BaseColorMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipColorMapUSamplesID
{
	std::string ID;
	TipColorMapUSamplesID(const std::string& id):ID(id){}
	TipColorMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipColorMapVSamplesID
{
	std::string ID;
	TipColorMapVSamplesID(const std::string& id):ID(id){}
	TipColorMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseAmbientColorMapUSamplesID
{
	std::string ID;
	BaseAmbientColorMapUSamplesID(const std::string& id):ID(id){}
	BaseAmbientColorMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseAmbientColorMapVSamplesID
{
	std::string ID;
	BaseAmbientColorMapVSamplesID(const std::string& id):ID(id){}
	BaseAmbientColorMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipAmbientColorMapUSamplesID
{
	std::string ID;
	TipAmbientColorMapUSamplesID(const std::string& id):ID(id){}
	TipAmbientColorMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipAmbientColorMapVSamplesID
{
	std::string ID;
	TipAmbientColorMapVSamplesID(const std::string& id):ID(id){}
	TipAmbientColorMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SpecularColorMapUSamplesID
{
	std::string ID;
	SpecularColorMapUSamplesID(const std::string& id):ID(id){}
	SpecularColorMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SpecularColorMapVSamplesID
{
	std::string ID;
	SpecularColorMapVSamplesID(const std::string& id):ID(id){}
	SpecularColorMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LengthMapUSamplesID
{
	std::string ID;
	LengthMapUSamplesID(const std::string& id):ID(id){}
	LengthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LengthMapVSamplesID
{
	std::string ID;
	LengthMapVSamplesID(const std::string& id):ID(id){}
	LengthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SpecularSharpnessMapUSamplesID
{
	std::string ID;
	SpecularSharpnessMapUSamplesID(const std::string& id):ID(id){}
	SpecularSharpnessMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SpecularSharpnessMapVSamplesID
{
	std::string ID;
	SpecularSharpnessMapVSamplesID(const std::string& id):ID(id){}
	SpecularSharpnessMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaldnessMapUSamplesID
{
	std::string ID;
	BaldnessMapUSamplesID(const std::string& id):ID(id){}
	BaldnessMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaldnessMapVSamplesID
{
	std::string ID;
	BaldnessMapVSamplesID(const std::string& id):ID(id){}
	BaldnessMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseOpacityMapUSamplesID
{
	std::string ID;
	BaseOpacityMapUSamplesID(const std::string& id):ID(id){}
	BaseOpacityMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseOpacityMapVSamplesID
{
	std::string ID;
	BaseOpacityMapVSamplesID(const std::string& id):ID(id){}
	BaseOpacityMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipOpacityMapUSamplesID
{
	std::string ID;
	TipOpacityMapUSamplesID(const std::string& id):ID(id){}
	TipOpacityMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipOpacityMapVSamplesID
{
	std::string ID;
	TipOpacityMapVSamplesID(const std::string& id):ID(id){}
	TipOpacityMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseWidthMapUSamplesID
{
	std::string ID;
	BaseWidthMapUSamplesID(const std::string& id):ID(id){}
	BaseWidthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseWidthMapVSamplesID
{
	std::string ID;
	BaseWidthMapVSamplesID(const std::string& id):ID(id){}
	BaseWidthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipWidthMapUSamplesID
{
	std::string ID;
	TipWidthMapUSamplesID(const std::string& id):ID(id){}
	TipWidthMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipWidthMapVSamplesID
{
	std::string ID;
	TipWidthMapVSamplesID(const std::string& id):ID(id){}
	TipWidthMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SegmentsMapUSamplesID
{
	std::string ID;
	SegmentsMapUSamplesID(const std::string& id):ID(id){}
	SegmentsMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SegmentsMapVSamplesID
{
	std::string ID;
	SegmentsMapVSamplesID(const std::string& id):ID(id){}
	SegmentsMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseCurlMapUSamplesID
{
	std::string ID;
	BaseCurlMapUSamplesID(const std::string& id):ID(id){}
	BaseCurlMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseCurlMapVSamplesID
{
	std::string ID;
	BaseCurlMapVSamplesID(const std::string& id):ID(id){}
	BaseCurlMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipCurlMapUSamplesID
{
	std::string ID;
	TipCurlMapUSamplesID(const std::string& id):ID(id){}
	TipCurlMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TipCurlMapVSamplesID
{
	std::string ID;
	TipCurlMapVSamplesID(const std::string& id):ID(id){}
	TipCurlMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ScraggleMapUSamplesID
{
	std::string ID;
	ScraggleMapUSamplesID(const std::string& id):ID(id){}
	ScraggleMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ScraggleMapVSamplesID
{
	std::string ID;
	ScraggleMapVSamplesID(const std::string& id):ID(id){}
	ScraggleMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ScraggleFrequencyMapUSamplesID
{
	std::string ID;
	ScraggleFrequencyMapUSamplesID(const std::string& id):ID(id){}
	ScraggleFrequencyMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ScraggleFrequencyMapVSamplesID
{
	std::string ID;
	ScraggleFrequencyMapVSamplesID(const std::string& id):ID(id){}
	ScraggleFrequencyMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ScraggleCorrelationMapUSamplesID
{
	std::string ID;
	ScraggleCorrelationMapUSamplesID(const std::string& id):ID(id){}
	ScraggleCorrelationMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ScraggleCorrelationMapVSamplesID
{
	std::string ID;
	ScraggleCorrelationMapVSamplesID(const std::string& id):ID(id){}
	ScraggleCorrelationMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InclinationMapUSamplesID
{
	std::string ID;
	InclinationMapUSamplesID(const std::string& id):ID(id){}
	InclinationMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InclinationMapVSamplesID
{
	std::string ID;
	InclinationMapVSamplesID(const std::string& id):ID(id){}
	InclinationMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RollMapUSamplesID
{
	std::string ID;
	RollMapUSamplesID(const std::string& id):ID(id){}
	RollMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RollMapVSamplesID
{
	std::string ID;
	RollMapVSamplesID(const std::string& id):ID(id){}
	RollMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PolarMapUSamplesID
{
	std::string ID;
	PolarMapUSamplesID(const std::string& id):ID(id){}
	PolarMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PolarMapVSamplesID
{
	std::string ID;
	PolarMapVSamplesID(const std::string& id):ID(id){}
	PolarMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AttractionMapUSamplesID
{
	std::string ID;
	AttractionMapUSamplesID(const std::string& id):ID(id){}
	AttractionMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AttractionMapVSamplesID
{
	std::string ID;
	AttractionMapVSamplesID(const std::string& id):ID(id){}
	AttractionMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct OffsetMapUSamplesID
{
	std::string ID;
	OffsetMapUSamplesID(const std::string& id):ID(id){}
	OffsetMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct OffsetMapVSamplesID
{
	std::string ID;
	OffsetMapVSamplesID(const std::string& id):ID(id){}
	OffsetMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpingMapUSamplesID
{
	std::string ID;
	ClumpingMapUSamplesID(const std::string& id):ID(id){}
	ClumpingMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpingMapVSamplesID
{
	std::string ID;
	ClumpingMapVSamplesID(const std::string& id):ID(id){}
	ClumpingMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpingFrequencyMapUSamplesID
{
	std::string ID;
	ClumpingFrequencyMapUSamplesID(const std::string& id):ID(id){}
	ClumpingFrequencyMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpingFrequencyMapVSamplesID
{
	std::string ID;
	ClumpingFrequencyMapVSamplesID(const std::string& id):ID(id){}
	ClumpingFrequencyMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpShapeMapUSamplesID
{
	std::string ID;
	ClumpShapeMapUSamplesID(const std::string& id):ID(id){}
	ClumpShapeMapUSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpShapeMapVSamplesID
{
	std::string ID;
	ClumpShapeMapVSamplesID(const std::string& id):ID(id){}
	ClumpShapeMapVSamplesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AttractorsID
{
	std::string ID;
	AttractorsID(const std::string& id):ID(id){}
	AttractorsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DeformedLatticeID
{
	std::string ID;
	DeformedLatticeID(const std::string& id):ID(id){}
	DeformedLatticeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LatticeID
{
	std::string ID;
	LatticeID(const std::string& id):ID(id){}
	LatticeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BaseLatticeID
{
	std::string ID;
	BaseLatticeID(const std::string& id):ID(id){}
	BaseLatticeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StuCacheListID
{
	std::string ID;
	StuCacheListID(const std::string& id):ID(id){}
	StuCacheListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputDataID
{
	std::string ID;
	InputDataID(const std::string& id):ID(id){}
	InputDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GenericArrayID
{
	std::string ID;
	GenericArrayID(const std::string& id):ID(id){}
	GenericArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FalloffCurveID
{
	std::string ID;
	FalloffCurveID(const std::string& id):ID(id){}
	FalloffCurveID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CharID
{
	std::string ID;
	CharID(const std::string& id):ID(id){}
	CharID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FluidID
{
	std::string ID;
	FluidID(const std::string& id):ID(id){}
	FluidID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ResolutionID
{
	std::string ID;
	ResolutionID(const std::string& id):ID(id){}
	ResolutionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DimensionsID
{
	std::string ID;
	DimensionsID(const std::string& id):ID(id){}
	DimensionsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FieldDataID
{
	std::string ID;
	FieldDataID(const std::string& id):ID(id){}
	FieldDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FieldListID
{
	std::string ID;
	FieldListID(const std::string& id):ID(id){}
	FieldListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FieldFunctionID
{
	std::string ID;
	FieldFunctionID(const std::string& id):ID(id){}
	FieldFunctionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FieldFunction_InmapID
{
	std::string ID;
	FieldFunction_InmapID(const std::string& id):ID(id){}
	FieldFunction_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FieldFunction_OutmapID
{
	std::string ID;
	FieldFunction_OutmapID(const std::string& id):ID(id){}
	FieldFunction_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EmissionListID
{
	std::string ID;
	EmissionListID(const std::string& id):ID(id){}
	EmissionListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EmissionFunctionID
{
	std::string ID;
	EmissionFunctionID(const std::string& id):ID(id){}
	EmissionFunctionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EmissionFunction_InmapID
{
	std::string ID;
	EmissionFunction_InmapID(const std::string& id):ID(id){}
	EmissionFunction_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EmissionFunction_OutmapID
{
	std::string ID;
	EmissionFunction_OutmapID(const std::string& id):ID(id){}
	EmissionFunction_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SubVolumeCenterID
{
	std::string ID;
	SubVolumeCenterID(const std::string& id):ID(id){}
	SubVolumeCenterID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SubVolumeSizeID
{
	std::string ID;
	SubVolumeSizeID(const std::string& id):ID(id){}
	SubVolumeSizeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorID
{
	std::string ID;
	ColorID(const std::string& id):ID(id){}
	ColorID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct OpacityID
{
	std::string ID;
	OpacityID(const std::string& id):ID(id){}
	OpacityID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct IncandescenceID
{
	std::string ID;
	IncandescenceID(const std::string& id):ID(id){}
	IncandescenceID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StiffnessScaleID
{
	std::string ID;
	StiffnessScaleID(const std::string& id):ID(id){}
	StiffnessScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpWidthScaleID
{
	std::string ID;
	ClumpWidthScaleID(const std::string& id):ID(id){}
	ClumpWidthScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AttractionScaleID
{
	std::string ID;
	AttractionScaleID(const std::string& id):ID(id){}
	AttractionScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HairCurveID
{
	std::string ID;
	HairCurveID(const std::string& id):ID(id){}
	HairCurveID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FaceIndexID
{
	std::string ID;
	FaceIndexID(const std::string& id):ID(id){}
	FaceIndexID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FaceFirstID
{
	std::string ID;
	FaceFirstID(const std::string& id):ID(id){}
	FaceFirstID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FaceSecondID
{
	std::string ID;
	FaceSecondID(const std::string& id):ID(id){}
	FaceSecondID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct IdMappingID
{
	std::string ID;
	IdMappingID(const std::string& id):ID(id){}
	IdMappingID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SweptGeometryID
{
	std::string ID;
	SweptGeometryID(const std::string& id):ID(id){}
	SweptGeometryID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LongArrayID
{
	std::string ID;
	LongArrayID(const std::string& id):ID(id){}
	LongArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CompInstObjGroupsID
{
	std::string ID;
	CompInstObjGroupsID(const std::string& id):ID(id){}
	CompInstObjGroupsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CompObjectGroupsID
{
	std::string ID;
	CompObjectGroupsID(const std::string& id):ID(id){}
	CompObjectGroupsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HairPinID
{
	std::string ID;
	HairPinID(const std::string& id):ID(id){}
	HairPinID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpCurlID
{
	std::string ID;
	ClumpCurlID(const std::string& id):ID(id){}
	ClumpCurlID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ClumpFlatnessID
{
	std::string ID;
	ClumpFlatnessID(const std::string& id):ID(id){}
	ClumpFlatnessID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HairWidthScaleID
{
	std::string ID;
	HairWidthScaleID(const std::string& id):ID(id){}
	HairWidthScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HairColorScaleID
{
	std::string ID;
	HairColorScaleID(const std::string& id):ID(id){}
	HairColorScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DisplacementScaleID
{
	std::string ID;
	DisplacementScaleID(const std::string& id):ID(id){}
	DisplacementScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HairRenderInfoID
{
	std::string ID;
	HairRenderInfoID(const std::string& id):ID(id){}
	HairRenderInfoID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorScaleID
{
	std::string ID;
	ColorScaleID(const std::string& id):ID(id){}
	ColorScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FloorContactsID
{
	std::string ID;
	FloorContactsID(const std::string& id):ID(id){}
	FloorContactsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HandsFloorContactSetupID
{
	std::string ID;
	HandsFloorContactSetupID(const std::string& id):ID(id){}
	HandsFloorContactSetupID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ContactsPositionID
{
	std::string ID;
	ContactsPositionID(const std::string& id):ID(id){}
	ContactsPositionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FeetFloorContactSetupID
{
	std::string ID;
	FeetFloorContactSetupID(const std::string& id):ID(id){}
	FeetFloorContactSetupID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FeetContactPositionID
{
	std::string ID;
	FeetContactPositionID(const std::string& id):ID(id){}
	FeetContactPositionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FingersFloorContactSetupID
{
	std::string ID;
	FingersFloorContactSetupID(const std::string& id):ID(id){}
	FingersFloorContactSetupID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ToesFloorContactSetupID
{
	std::string ID;
	ToesFloorContactSetupID(const std::string& id):ID(id){}
	ToesFloorContactSetupID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SolvingID
{
	std::string ID;
	SolvingID(const std::string& id):ID(id){}
	SolvingID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct FingerTipsSizesID
{
	std::string ID;
	FingerTipsSizesID(const std::string& id):ID(id){}
	FingerTipsSizesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ToeTipsSizesID
{
	std::string ID;
	ToeTipsSizesID(const std::string& id):ID(id){}
	ToeTipsSizesID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HeadID
{
	std::string ID;
	HeadID(const std::string& id):ID(id){}
	HeadID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LeftArmID
{
	std::string ID;
	LeftArmID(const std::string& id):ID(id){}
	LeftArmID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RightArmID
{
	std::string ID;
	RightArmID(const std::string& id):ID(id){}
	RightArmID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ChestID
{
	std::string ID;
	ChestID(const std::string& id):ID(id){}
	ChestID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HipsID
{
	std::string ID;
	HipsID(const std::string& id):ID(id){}
	HipsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LeftLegID
{
	std::string ID;
	LeftLegID(const std::string& id):ID(id){}
	LeftLegID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RightLegID
{
	std::string ID;
	RightLegID(const std::string& id):ID(id){}
	RightLegID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ExtraID
{
	std::string ID;
	ExtraID(const std::string& id):ID(id){}
	ExtraID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StiffnessID
{
	std::string ID;
	StiffnessID(const std::string& id):ID(id){}
	StiffnessID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct KillPitchID
{
	std::string ID;
	KillPitchID(const std::string& id):ID(id){}
	KillPitchID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RollExtractionID
{
	std::string ID;
	RollExtractionID(const std::string& id):ID(id){}
	RollExtractionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct StringArrayID
{
	std::string ID;
	StringArrayID(const std::string& id):ID(id){}
	StringArrayID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HyperPositionID
{
	std::string ID;
	HyperPositionID(const std::string& id):ID(id){}
	HyperPositionID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Short2ID
{
	std::string ID;
	Short2ID(const std::string& id):ID(id){}
	Short2ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BoxID
{
	std::string ID;
	BoxID(const std::string& id):ID(id){}
	BoxID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SphereID
{
	std::string ID;
	SphereID(const std::string& id):ID(id){}
	SphereID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ChildJointClusterXformsID
{
	std::string ID;
	ChildJointClusterXformsID(const std::string& id):ID(id){}
	ChildJointClusterXformsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NextJointClusterXformsID
{
	std::string ID;
	NextJointClusterXformsID(const std::string& id):ID(id){}
	NextJointClusterXformsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DistanceListID
{
	std::string ID;
	DistanceListID(const std::string& id):ID(id){}
	DistanceListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputsID
{
	std::string ID;
	InputsID(const std::string& id):ID(id){}
	InputsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LinkID
{
	std::string ID;
	LinkID(const std::string& id):ID(id){}
	LinkID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct IgnoreID
{
	std::string ID;
	IgnoreID(const std::string& id):ID(id){}
	IgnoreID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ShadowLinkID
{
	std::string ID;
	ShadowLinkID(const std::string& id):ID(id){}
	ShadowLinkID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ShadowIgnoreID
{
	std::string ID;
	ShadowIgnoreID(const std::string& id):ID(id){}
	ShadowIgnoreID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DropoffID
{
	std::string ID;
	DropoffID(const std::string& id):ID(id){}
	DropoffID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct LineModifierID
{
	std::string ID;
	LineModifierID(const std::string& id):ID(id){}
	LineModifierID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct MiFileSizeID
{
	std::string ID;
	MiFileSizeID(const std::string& id):ID(id){}
	MiFileSizeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorPerVertexID
{
	std::string ID;
	ColorPerVertexID(const std::string& id):ID(id){}
	ColorPerVertexID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct VertexColorID
{
	std::string ID;
	VertexColorID(const std::string& id):ID(id){}
	VertexColorID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct VertexFaceColorID
{
	std::string ID;
	VertexFaceColorID(const std::string& id):ID(id){}
	VertexFaceColorID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NurbsPatchUVIdsID
{
	std::string ID;
	NurbsPatchUVIdsID(const std::string& id):ID(id){}
	NurbsPatchUVIdsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Long2ID
{
	std::string ID;
	Long2ID(const std::string& id):ID(id){}
	Long2ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SelectionListID
{
	std::string ID;
	SelectionListID(const std::string& id):ID(id){}
	SelectionListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct WaveHeightID
{
	std::string ID;
	WaveHeightID(const std::string& id):ID(id){}
	WaveHeightID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct WaveTurbulenceID
{
	std::string ID;
	WaveTurbulenceID(const std::string& id):ID(id){}
	WaveTurbulenceID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct WavePeakingID
{
	std::string ID;
	WavePeakingID(const std::string& id):ID(id){}
	WavePeakingID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct EmitterDataID
{
	std::string ID;
	EmitterDataID(const std::string& id):ID(id){}
	EmitterDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CollisionDataID
{
	std::string ID;
	CollisionDataID(const std::string& id):ID(id){}
	CollisionDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InstanceDataID
{
	std::string ID;
	InstanceDataID(const std::string& id):ID(id){}
	InstanceDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InputSurfaceID
{
	std::string ID;
	InputSurfaceID(const std::string& id):ID(id){}
	InputSurfaceID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CurvatureWidthID
{
	std::string ID;
	CurvatureWidthID(const std::string& id):ID(id){}
	CurvatureWidthID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TaperCurveID
{
	std::string ID;
	TaperCurveID(const std::string& id):ID(id){}
	TaperCurveID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RedScaleID
{
	std::string ID;
	RedScaleID(const std::string& id):ID(id){}
	RedScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GreenScaleID
{
	std::string ID;
	GreenScaleID(const std::string& id):ID(id){}
	GreenScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BlueScaleID
{
	std::string ID;
	BlueScaleID(const std::string& id):ID(id){}
	BlueScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AlphaScaleID
{
	std::string ID;
	AlphaScaleID(const std::string& id):ID(id){}
	AlphaScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct IntensityScaleID
{
	std::string ID;
	IntensityScaleID(const std::string& id):ID(id){}
	IntensityScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ProfileCurveID
{
	std::string ID;
	ProfileCurveID(const std::string& id):ID(id){}
	ProfileCurveID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CachedUVsID
{
	std::string ID;
	CachedUVsID(const std::string& id):ID(id){}
	CachedUVsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct NewUVID
{
	std::string ID;
	NewUVID(const std::string& id):ID(id){}
	NewUVID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct InQuadID
{
	std::string ID;
	InQuadID(const std::string& id):ID(id){}
	InQuadID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct DefaultID
{
	std::string ID;
	DefaultID(const std::string& id):ID(id){}
	DefaultID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct OutputID
{
	std::string ID;
	OutputID(const std::string& id):ID(id){}
	OutputID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorEntryListID
{
	std::string ID;
	ColorEntryListID(const std::string& id):ID(id){}
	ColorEntryListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct TransparencyID
{
	std::string ID;
	TransparencyID(const std::string& id):ID(id){}
	TransparencyID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SpecularRollOffID
{
	std::string ID;
	SpecularRollOffID(const std::string& id):ID(id){}
	SpecularRollOffID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SpecularColorID
{
	std::string ID;
	SpecularColorID(const std::string& id):ID(id){}
	SpecularColorID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ReflectivityID
{
	std::string ID;
	ReflectivityID(const std::string& id):ID(id){}
	ReflectivityID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ConnectionListID
{
	std::string ID;
	ConnectionListID(const std::string& id):ID(id){}
	ConnectionListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct MultiParentListID
{
	std::string ID;
	MultiParentListID(const std::string& id):ID(id){}
	MultiParentListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ReferenceEditsID
{
	std::string ID;
	ReferenceEditsID(const std::string& id):ID(id){}
	ReferenceEditsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RedID
{
	std::string ID;
	RedID(const std::string& id):ID(id){}
	RedID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GreenID
{
	std::string ID;
	GreenID(const std::string& id):ID(id){}
	GreenID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct BlueID
{
	std::string ID;
	BlueID(const std::string& id):ID(id){}
	BlueID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct HueID
{
	std::string ID;
	HueID(const std::string& id):ID(id){}
	HueID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SaturationID
{
	std::string ID;
	SaturationID(const std::string& id):ID(id){}
	SaturationID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ValueID
{
	std::string ID;
	ValueID(const std::string& id):ID(id){}
	ValueID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct RenderPassInfoID
{
	std::string ID;
	RenderPassInfoID(const std::string& id):ID(id){}
	RenderPassInfoID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AdjustmentsID
{
	std::string ID;
	AdjustmentsID(const std::string& id):ID(id){}
	AdjustmentsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct OutAdjustmentsID
{
	std::string ID;
	OutAdjustmentsID(const std::string& id):ID(id){}
	OutAdjustmentsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct GeneralForceID
{
	std::string ID;
	GeneralForceID(const std::string& id):ID(id){}
	GeneralForceID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Function_InmapID
{
	std::string ID;
	Function_InmapID(const std::string& id):ID(id){}
	Function_InmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Function_OutmapID
{
	std::string ID;
	Function_OutmapID(const std::string& id):ID(id){}
	Function_OutmapID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct WeightListID
{
	std::string ID;
	WeightListID(const std::string& id):ID(id){}
	WeightListID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SoftModXformsID
{
	std::string ID;
	SoftModXformsID(const std::string& id):ID(id){}
	SoftModXformsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SoftModTransformsID
{
	std::string ID;
	SoftModTransformsID(const std::string& id):ID(id){}
	SoftModTransformsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PathCurveID
{
	std::string ID;
	PathCurveID(const std::string& id):ID(id){}
	PathCurveID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PressureScaleID
{
	std::string ID;
	PressureScaleID(const std::string& id):ID(id){}
	PressureScaleID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct VertexID
{
	std::string ID;
	VertexID(const std::string& id):ID(id){}
	VertexID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct VertexTweakID
{
	std::string ID;
	VertexTweakID(const std::string& id):ID(id){}
	VertexTweakID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SubdivEdgeCreaseID
{
	std::string ID;
	SubdivEdgeCreaseID(const std::string& id):ID(id){}
	SubdivEdgeCreaseID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SubdivTextCoordID
{
	std::string ID;
	SubdivTextCoordID(const std::string& id):ID(id){}
	SubdivTextCoordID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct SubdivFaceUVIdsID
{
	std::string ID;
	SubdivFaceUVIdsID(const std::string& id):ID(id){}
	SubdivFaceUVIdsID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CollisionOffsetVelocityIncrementID
{
	std::string ID;
	CollisionOffsetVelocityIncrementID(const std::string& id):ID(id){}
	CollisionOffsetVelocityIncrementID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CollisionDepthVelocityIncrementID
{
	std::string ID;
	CollisionDepthVelocityIncrementID(const std::string& id):ID(id){}
	CollisionDepthVelocityIncrementID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CollisionOffsetVelocityMultiplierID
{
	std::string ID;
	CollisionOffsetVelocityMultiplierID(const std::string& id):ID(id){}
	CollisionOffsetVelocityMultiplierID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct CollisionDepthVelocityMultiplierID
{
	std::string ID;
	CollisionDepthVelocityMultiplierID(const std::string& id):ID(id){}
	CollisionDepthVelocityMultiplierID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct OutColorDataID
{
	std::string ID;
	OutColorDataID(const std::string& id):ID(id){}
	OutColorDataID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct Double4ID
{
	std::string ID;
	Double4ID(const std::string& id):ID(id){}
	Double4ID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PlistID
{
	std::string ID;
	PlistID(const std::string& id):ID(id){}
	PlistID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct VlistID
{
	std::string ID;
	VlistID(const std::string& id):ID(id){}
	VlistID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorRampID
{
	std::string ID;
	ColorRampID(const std::string& id):ID(id){}
	ColorRampID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct ColorRangeID
{
	std::string ID;
	ColorRangeID(const std::string& id):ID(id){}
	ColorRangeID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct PenumbraID
{
	std::string ID;
	PenumbraID(const std::string& id):ID(id){}
	PenumbraID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct AxisID
{
	std::string ID;
	AxisID(const std::string& id):ID(id){}
	AxisID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
struct WtMatrixID
{
	std::string ID;
	WtMatrixID(const std::string& id):ID(id){}
	WtMatrixID(const char* id):ID(id){}
	void write(FILE* file)const{fprintf_s(file,"%s",ID.c_str());}
};
}//namespace MayaDM
#endif//__MayaDM_CONNECTABLES_H__
