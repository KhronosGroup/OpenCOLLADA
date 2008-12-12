/** Copyright &copy; 2008, NetAllied Systems GmbH, Ravensburg, Germany. */


#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGEN_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGEN_H__


#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserParserTemplate.h"


namespace COLLADASaxFWL
{
	typedef GeneratedSaxParser::StringHash StringHash;
	typedef GeneratedSaxParser::ParserChar ParserChar;
	typedef GeneratedSaxParser::ParserAttributes ParserAttributes;

	class ColladaParserAutoGen : public GeneratedSaxParser::ParserTemplate<ColladaParserAutoGen>
	{
	public:
		static const char* PARENT_CHILD_ELEMENT_SEPARATOR;

		ColladaParserAutoGen( GeneratedSaxParser::IErrorHandler* errorHandler = 0 );
		virtual ~ColladaParserAutoGen();


	public:
		static const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS = 262260019;
		static const StringHash HASH_ATTRIBUTE_ID = 1780;
		static const StringHash HASH_ATTRIBUTE_NAME = 477237;
		struct library_force_fields__AttributeData
		{
			static const library_force_fields__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_force_fields( const library_force_fields__AttributeData& attributeData ){return true;}
		virtual bool end__library_force_fields(){return true;}
	private:
		bool _begin__library_force_fields( void* attributeData ){return begin__library_force_fields(*static_cast<library_force_fields__AttributeData*>(attributeData));}
		bool _data__library_force_fields( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_force_fields( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_force_fields();

	public:
		static const StringHash HASH_ELEMENT_ASSET = 6859204;
		static const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__ASSET = 256178756;
		virtual bool begin__library_force_fields__asset(){return true;}
		virtual bool end__library_force_fields__asset(){return true;}
	private:
		bool _begin__library_force_fields__asset( void* attributeData ){return begin__library_force_fields__asset();}
		bool _data__library_force_fields__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_force_fields__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_force_fields__asset();

	public:
		static const StringHash HASH_ELEMENT_CONTRIBUTOR = 143896786;
		static const StringHash HASH_ELEMENT_ASSET__CONTRIBUTOR = 187503730;
		virtual bool begin__contributor(){return true;}
		virtual bool end__contributor(){return true;}
	private:
		bool _begin__contributor( void* attributeData ){return begin__contributor();}
		bool _data__contributor( const ParserChar* text, size_t textLength );
		bool _validateBegin__contributor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__contributor();

	public:
		static const StringHash HASH_ELEMENT_AUTHOR = 109883234;
		static const StringHash HASH_ELEMENT_CONTRIBUTOR__AUTHOR = 104615810;
		virtual bool begin__author(){return true;}
		virtual bool end__author(){return true;}
		virtual bool data__author( const void* data, size_t length ){return true;}
	private:
		bool _begin__author( void* attributeData ){return begin__author();}
		bool _data__author( const ParserChar* text, size_t textLength );
		bool _validateBegin__author( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__author();

	public:
		static const StringHash HASH_ELEMENT_AUTHORING_TOOL = 142204124;
		static const StringHash HASH_ELEMENT_CONTRIBUTOR__AUTHORING_TOOL = 144260236;
		virtual bool begin__authoring_tool(){return true;}
		virtual bool end__authoring_tool(){return true;}
		virtual bool data__authoring_tool( const void* data, size_t length ){return true;}
	private:
		bool _begin__authoring_tool( void* attributeData ){return begin__authoring_tool();}
		bool _data__authoring_tool( const ParserChar* text, size_t textLength );
		bool _validateBegin__authoring_tool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__authoring_tool();

	public:
		static const StringHash HASH_ELEMENT_COMMENTS = 105104147;
		static const StringHash HASH_ELEMENT_CONTRIBUTOR__COMMENTS = 115565443;
		virtual bool begin__comments(){return true;}
		virtual bool end__comments(){return true;}
		virtual bool data__comments( const void* data, size_t length ){return true;}
	private:
		bool _begin__comments( void* attributeData ){return begin__comments();}
		bool _data__comments( const ParserChar* text, size_t textLength );
		bool _validateBegin__comments( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__comments();

	public:
		static const StringHash HASH_ELEMENT_COPYRIGHT = 134780820;
		static const StringHash HASH_ELEMENT_CONTRIBUTOR__COPYRIGHT = 168205972;
		virtual bool begin__copyright(){return true;}
		virtual bool end__copyright(){return true;}
		virtual bool data__copyright( const void* data, size_t length ){return true;}
	private:
		bool _begin__copyright( void* attributeData ){return begin__copyright();}
		bool _data__copyright( const ParserChar* text, size_t textLength );
		bool _validateBegin__copyright( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__copyright();

	public:
		static const StringHash HASH_ELEMENT_SOURCE_DATA = 166708257;
		static const StringHash HASH_ELEMENT_CONTRIBUTOR__SOURCE_DATA = 134662689;
		virtual bool begin__source_data(){return true;}
		virtual bool end__source_data(){return true;}
		virtual bool data__source_data( const void* data, size_t length ){return true;}
	private:
		bool _begin__source_data( void* attributeData ){return begin__source_data();}
		bool _data__source_data( const ParserChar* text, size_t textLength );
		bool _validateBegin__source_data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source_data();

	public:
		static const StringHash HASH_ELEMENT_CREATED = 176917204;
		static const StringHash HASH_ELEMENT_ASSET__CREATED = 1517924;
		virtual bool begin__created(){return true;}
		virtual bool end__created(){return true;}
		virtual bool data__created( const void* data, size_t length ){return true;}
	private:
		bool _begin__created( void* attributeData ){return begin__created();}
		bool _data__created( const ParserChar* text, size_t textLength );
		bool _validateBegin__created( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__created();

	public:
		static const StringHash HASH_ELEMENT_KEYWORDS = 219049891;
		static const StringHash HASH_ELEMENT_ASSET__KEYWORDS = 113792515;
		virtual bool begin__keywords(){return true;}
		virtual bool end__keywords(){return true;}
		virtual bool data__keywords( const void* data, size_t length ){return true;}
	private:
		bool _begin__keywords( void* attributeData ){return begin__keywords();}
		bool _data__keywords( const ParserChar* text, size_t textLength );
		bool _validateBegin__keywords( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__keywords();

	public:
		static const StringHash HASH_ELEMENT_MODIFIED = 95406324;
		static const StringHash HASH_ELEMENT_ASSET__MODIFIED = 208007444;
		virtual bool begin__modified(){return true;}
		virtual bool end__modified(){return true;}
		virtual bool data__modified( const void* data, size_t length ){return true;}
	private:
		bool _begin__modified( void* attributeData ){return begin__modified();}
		bool _data__modified( const ParserChar* text, size_t textLength );
		bool _validateBegin__modified( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__modified();

	public:
		static const StringHash HASH_ELEMENT_REVISION = 214997470;
		static const StringHash HASH_ELEMENT_ASSET__REVISION = 85631614;
		virtual bool begin__revision(){return true;}
		virtual bool end__revision(){return true;}
		virtual bool data__revision( const void* data, size_t length ){return true;}
	private:
		bool _begin__revision( void* attributeData ){return begin__revision();}
		bool _data__revision( const ParserChar* text, size_t textLength );
		bool _validateBegin__revision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__revision();

	public:
		static const StringHash HASH_ELEMENT_SUBJECT = 179899348;
		static const StringHash HASH_ELEMENT_ASSET__SUBJECT = 2467908;
		virtual bool begin__subject(){return true;}
		virtual bool end__subject(){return true;}
		virtual bool data__subject( const void* data, size_t length ){return true;}
	private:
		bool _begin__subject( void* attributeData ){return begin__subject();}
		bool _data__subject( const ParserChar* text, size_t textLength );
		bool _validateBegin__subject( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__subject();

	public:
		static const StringHash HASH_ELEMENT_TITLE = 8063781;
		static const StringHash HASH_ELEMENT_ASSET__TITLE = 65116037;
		virtual bool begin__title(){return true;}
		virtual bool end__title(){return true;}
		virtual bool data__title( const void* data, size_t length ){return true;}
	private:
		bool _begin__title( void* attributeData ){return begin__title();}
		bool _data__title( const ParserChar* text, size_t textLength );
		bool _validateBegin__title( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__title();

	public:
		static const StringHash HASH_ELEMENT_UNIT = 509188;
		static const StringHash HASH_ELEMENT_ASSET__UNIT = 171847364;
		static const StringHash HASH_ATTRIBUTE_METER = 7588546;
		struct unit__AttributeData
		{
			static const unit__AttributeData DEFAULT;

			float meter;
			const ParserChar* name;
		};
		virtual bool begin__unit( const unit__AttributeData& attributeData ){return true;}
		virtual bool end__unit(){return true;}
	private:
		bool _begin__unit( void* attributeData ){return begin__unit(*static_cast<unit__AttributeData*>(attributeData));}
		bool _data__unit( const ParserChar* text, size_t textLength );
		bool _validateBegin__unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__unit();

	public:
		static const StringHash HASH_ELEMENT_UP_AXIS = 207982451;
		static const StringHash HASH_ELEMENT_ASSET__UP_AXIS = 114896611;
		virtual bool begin__up_axis(){return true;}
		virtual bool end__up_axis(){return true;}
		virtual bool data__up_axis( const void* data, size_t length ){return true;}
	private:
		bool _begin__up_axis( void* attributeData ){return begin__up_axis();}
		bool _data__up_axis( const ParserChar* text, size_t textLength );
		bool _validateBegin__up_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__up_axis();

	public:
		static const StringHash HASH_ELEMENT_FORCE_FIELD = 187798708;
		static const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__FORCE_FIELD = 102613300;
		struct force_field__AttributeData
		{
			static const force_field__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__force_field( const force_field__AttributeData& attributeData ){return true;}
		virtual bool end__force_field(){return true;}
	private:
		bool _begin__force_field( void* attributeData ){return begin__force_field(*static_cast<force_field__AttributeData*>(attributeData));}
		bool _data__force_field( const ParserChar* text, size_t textLength );
		bool _validateBegin__force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field();

	public:
		static const StringHash HASH_ELEMENT_FORCE_FIELD__ASSET = 138535668;
		virtual bool begin__force_field__asset(){return true;}
		virtual bool end__force_field__asset(){return true;}
	private:
		bool _begin__force_field__asset( void* attributeData ){return begin__force_field__asset();}
		bool _data__force_field__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__force_field__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field__asset();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE = 167080453;
		static const StringHash HASH_ELEMENT_FORCE_FIELD__TECHNIQUE = 49118021;
		static const StringHash HASH_ATTRIBUTE_PROFILE = 127258709;
		struct force_field__technique__AttributeData
		{
			static const force_field__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__force_field__technique( const force_field__technique__AttributeData& attributeData ){return true;}
		virtual bool end__force_field__technique(){return true;}
	private:
		bool _begin__force_field__technique( void* attributeData ){return begin__force_field__technique(*static_cast<force_field__technique__AttributeData*>(attributeData));}
		bool _data__force_field__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__force_field__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field__technique();

	public:
		static const StringHash HASH_ELEMENT_EXTRA = 7142273;
		static const StringHash HASH_ELEMENT_FORCE_FIELD__EXTRA = 138784945;
		static const StringHash HASH_ATTRIBUTE_TYPE = 508005;
		struct force_field__extra__AttributeData
		{
			static const force_field__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__force_field__extra( const force_field__extra__AttributeData& attributeData ){return true;}
		virtual bool end__force_field__extra(){return true;}
	private:
		bool _begin__force_field__extra( void* attributeData ){return begin__force_field__extra(*static_cast<force_field__extra__AttributeData*>(attributeData));}
		bool _data__force_field__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__force_field__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field__extra();

	public:
		static const StringHash HASH_ELEMENT_EXTRA__ASSET = 60232116;
		virtual bool begin__extra__asset(){return true;}
		virtual bool end__extra__asset(){return true;}
	private:
		bool _begin__extra__asset( void* attributeData ){return begin__extra__asset();}
		bool _data__extra__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__extra__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__extra__asset();

	public:
		static const StringHash HASH_ELEMENT_EXTRA__TECHNIQUE = 27831733;
		struct extra__technique__AttributeData
		{
			static const extra__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__extra__technique( const extra__technique__AttributeData& attributeData ){return true;}
		virtual bool end__extra__technique(){return true;}
	private:
		bool _begin__extra__technique( void* attributeData ){return begin__extra__technique(*static_cast<extra__technique__AttributeData*>(attributeData));}
		bool _data__extra__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__extra__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__extra__technique();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA = 255895553;
		struct library_force_fields__extra__AttributeData
		{
			static const library_force_fields__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_force_fields__extra( const library_force_fields__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_force_fields__extra(){return true;}
	private:
		bool _begin__library_force_fields__extra( void* attributeData ){return begin__library_force_fields__extra(*static_cast<library_force_fields__extra__AttributeData*>(attributeData));}
		bool _data__library_force_fields__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_force_fields__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_force_fields__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_EFFECT = 253030820;
		static const StringHash HASH_ATTRIBUTE_URL = 31884;
		static const StringHash HASH_ATTRIBUTE_SID = 31220;
		struct instance_effect__AttributeData
		{
			static const instance_effect__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_effect( const instance_effect__AttributeData& attributeData ){return true;}
		virtual bool end__instance_effect(){return true;}
	private:
		bool _begin__instance_effect( void* attributeData ){return begin__instance_effect(*static_cast<instance_effect__AttributeData*>(attributeData));}
		bool _data__instance_effect( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_effect();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE_HINT = 4897140;
		static const StringHash HASH_ELEMENT_INSTANCE_EFFECT__TECHNIQUE_HINT = 28302980;
		static const StringHash HASH_ATTRIBUTE_PLATFORM = 42652157;
		static const StringHash HASH_ATTRIBUTE_REF = 30902;
		struct technique_hint__AttributeData
		{
			static const technique_hint__AttributeData DEFAULT;

			const ParserChar* platform;
			const ParserChar* profile;
			const ParserChar* ref;
		};
		virtual bool begin__technique_hint( const technique_hint__AttributeData& attributeData ){return true;}
		virtual bool end__technique_hint(){return true;}
	private:
		bool _begin__technique_hint( void* attributeData ){return begin__technique_hint(*static_cast<technique_hint__AttributeData*>(attributeData));}
		bool _data__technique_hint( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_hint();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM = 213290989;
		static const StringHash HASH_ELEMENT_INSTANCE_EFFECT__SETPARAM = 219277853;
		struct instance_effect__setparam__AttributeData
		{
			static const instance_effect__setparam__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__instance_effect__setparam( const instance_effect__setparam__AttributeData& attributeData ){return true;}
		virtual bool end__instance_effect__setparam(){return true;}
	private:
		bool _begin__instance_effect__setparam( void* attributeData ){return begin__instance_effect__setparam(*static_cast<instance_effect__setparam__AttributeData*>(attributeData));}
		bool _data__instance_effect__setparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_effect__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_effect__setparam();

	public:
		static const StringHash HASH_ELEMENT_BOOL = 431708;
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL = 206428;
		virtual bool begin__setparam__bool(){return true;}
		virtual bool end__setparam__bool(){return true;}
		virtual bool data__setparam__bool( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool( void* attributeData ){return begin__setparam__bool();}
		bool _data__setparam__bool( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool();

	public:
		static const StringHash HASH_ELEMENT_BOOL2 = 6907378;
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL2 = 3302898;
		virtual bool begin__setparam__bool2(){return true;}
		virtual bool end__setparam__bool2(){return true;}
		virtual bool data__setparam__bool2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool2( void* attributeData ){return begin__setparam__bool2();}
		bool _data__setparam__bool2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2();

	public:
		static const StringHash HASH_ELEMENT_BOOL3 = 6907379;
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL3 = 3302899;
		virtual bool begin__setparam__bool3(){return true;}
		virtual bool end__setparam__bool3(){return true;}
		virtual bool data__setparam__bool3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool3( void* attributeData ){return begin__setparam__bool3();}
		bool _data__setparam__bool3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3();

	public:
		static const StringHash HASH_ELEMENT_BOOL4 = 6907380;
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL4 = 3302900;
		virtual bool begin__setparam__bool4(){return true;}
		virtual bool end__setparam__bool4(){return true;}
		virtual bool data__setparam__bool4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool4( void* attributeData ){return begin__setparam__bool4();}
		bool _data__setparam__bool4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4();

	public:
		static const StringHash HASH_ELEMENT_INT = 28756;
		static const StringHash HASH_ELEMENT_SETPARAM__INT = 14164;
		virtual bool begin__setparam__int(){return true;}
		virtual bool end__setparam__int(){return true;}
		virtual bool data__setparam__int( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int( void* attributeData ){return begin__setparam__int();}
		bool _data__setparam__int( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int();

	public:
		static const StringHash HASH_ELEMENT_INT2 = 460146;
		static const StringHash HASH_ELEMENT_SETPARAM__INT2 = 226674;
		virtual bool begin__setparam__int2(){return true;}
		virtual bool end__setparam__int2(){return true;}
		virtual bool data__setparam__int2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int2( void* attributeData ){return begin__setparam__int2();}
		bool _data__setparam__int2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2();

	public:
		static const StringHash HASH_ELEMENT_INT3 = 460147;
		static const StringHash HASH_ELEMENT_SETPARAM__INT3 = 226675;
		virtual bool begin__setparam__int3(){return true;}
		virtual bool end__setparam__int3(){return true;}
		virtual bool data__setparam__int3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int3( void* attributeData ){return begin__setparam__int3();}
		bool _data__setparam__int3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3();

	public:
		static const StringHash HASH_ELEMENT_INT4 = 460148;
		static const StringHash HASH_ELEMENT_SETPARAM__INT4 = 226676;
		virtual bool begin__setparam__int4(){return true;}
		virtual bool end__setparam__int4(){return true;}
		virtual bool data__setparam__int4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int4( void* attributeData ){return begin__setparam__int4();}
		bool _data__setparam__int4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4();

	public:
		static const StringHash HASH_ELEMENT_FLOAT = 7157124;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT = 3552644;
		virtual bool begin__setparam__float(){return true;}
		virtual bool end__setparam__float(){return true;}
		virtual bool data__setparam__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float( void* attributeData ){return begin__setparam__float();}
		bool _data__setparam__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float();

	public:
		static const StringHash HASH_ELEMENT_FLOAT2 = 114514034;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT2 = 56842354;
		virtual bool begin__setparam__float2(){return true;}
		virtual bool end__setparam__float2(){return true;}
		virtual bool data__setparam__float2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float2( void* attributeData ){return begin__setparam__float2();}
		bool _data__setparam__float2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2();

	public:
		static const StringHash HASH_ELEMENT_FLOAT3 = 114514035;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT3 = 56842355;
		virtual bool begin__setparam__float3(){return true;}
		virtual bool end__setparam__float3(){return true;}
		virtual bool data__setparam__float3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float3( void* attributeData ){return begin__setparam__float3();}
		bool _data__setparam__float3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3();

	public:
		static const StringHash HASH_ELEMENT_FLOAT4 = 114514036;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT4 = 56842356;
		virtual bool begin__setparam__float4(){return true;}
		virtual bool end__setparam__float4(){return true;}
		virtual bool data__setparam__float4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float4( void* attributeData ){return begin__setparam__float4();}
		bool _data__setparam__float4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4();

	public:
		static const StringHash HASH_ELEMENT_FLOAT1X1 = 56131169;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X1 = 56130513;
		virtual bool begin__setparam__float1x1(){return true;}
		virtual bool end__setparam__float1x1(){return true;}
		virtual bool data__setparam__float1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float1x1( void* attributeData ){return begin__setparam__float1x1();}
		bool _data__setparam__float1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x1();

	public:
		static const StringHash HASH_ELEMENT_FLOAT1X2 = 56131170;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X2 = 56130514;
		virtual bool begin__setparam__float1x2(){return true;}
		virtual bool end__setparam__float1x2(){return true;}
		virtual bool data__setparam__float1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float1x2( void* attributeData ){return begin__setparam__float1x2();}
		bool _data__setparam__float1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x2();

	public:
		static const StringHash HASH_ELEMENT_FLOAT1X3 = 56131171;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X3 = 56130515;
		virtual bool begin__setparam__float1x3(){return true;}
		virtual bool end__setparam__float1x3(){return true;}
		virtual bool data__setparam__float1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float1x3( void* attributeData ){return begin__setparam__float1x3();}
		bool _data__setparam__float1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x3();

	public:
		static const StringHash HASH_ELEMENT_FLOAT1X4 = 56131172;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X4 = 56130516;
		virtual bool begin__setparam__float1x4(){return true;}
		virtual bool end__setparam__float1x4(){return true;}
		virtual bool data__setparam__float1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float1x4( void* attributeData ){return begin__setparam__float1x4();}
		bool _data__setparam__float1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x4();

	public:
		static const StringHash HASH_ELEMENT_FLOAT2X1 = 56131425;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X1 = 56130257;
		virtual bool begin__setparam__float2x1(){return true;}
		virtual bool end__setparam__float2x1(){return true;}
		virtual bool data__setparam__float2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float2x1( void* attributeData ){return begin__setparam__float2x1();}
		bool _data__setparam__float2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x1();

	public:
		static const StringHash HASH_ELEMENT_FLOAT2X2 = 56131426;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X2 = 56130258;
		virtual bool begin__setparam__float2x2(){return true;}
		virtual bool end__setparam__float2x2(){return true;}
		virtual bool data__setparam__float2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float2x2( void* attributeData ){return begin__setparam__float2x2();}
		bool _data__setparam__float2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x2();

	public:
		static const StringHash HASH_ELEMENT_FLOAT2X3 = 56131427;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X3 = 56130259;
		virtual bool begin__setparam__float2x3(){return true;}
		virtual bool end__setparam__float2x3(){return true;}
		virtual bool data__setparam__float2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float2x3( void* attributeData ){return begin__setparam__float2x3();}
		bool _data__setparam__float2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x3();

	public:
		static const StringHash HASH_ELEMENT_FLOAT2X4 = 56131428;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X4 = 56130260;
		virtual bool begin__setparam__float2x4(){return true;}
		virtual bool end__setparam__float2x4(){return true;}
		virtual bool data__setparam__float2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float2x4( void* attributeData ){return begin__setparam__float2x4();}
		bool _data__setparam__float2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x4();

	public:
		static const StringHash HASH_ELEMENT_FLOAT3X1 = 56130657;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X1 = 56130001;
		virtual bool begin__setparam__float3x1(){return true;}
		virtual bool end__setparam__float3x1(){return true;}
		virtual bool data__setparam__float3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float3x1( void* attributeData ){return begin__setparam__float3x1();}
		bool _data__setparam__float3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x1();

	public:
		static const StringHash HASH_ELEMENT_FLOAT3X2 = 56130658;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X2 = 56130002;
		virtual bool begin__setparam__float3x2(){return true;}
		virtual bool end__setparam__float3x2(){return true;}
		virtual bool data__setparam__float3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float3x2( void* attributeData ){return begin__setparam__float3x2();}
		bool _data__setparam__float3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x2();

	public:
		static const StringHash HASH_ELEMENT_FLOAT3X3 = 56130659;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X3 = 56130003;
		virtual bool begin__setparam__float3x3(){return true;}
		virtual bool end__setparam__float3x3(){return true;}
		virtual bool data__setparam__float3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float3x3( void* attributeData ){return begin__setparam__float3x3();}
		bool _data__setparam__float3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x3();

	public:
		static const StringHash HASH_ELEMENT_FLOAT3X4 = 56130660;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X4 = 56130004;
		virtual bool begin__setparam__float3x4(){return true;}
		virtual bool end__setparam__float3x4(){return true;}
		virtual bool data__setparam__float3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float3x4( void* attributeData ){return begin__setparam__float3x4();}
		bool _data__setparam__float3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x4();

	public:
		static const StringHash HASH_ELEMENT_FLOAT4X1 = 56130913;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X1 = 56129745;
		virtual bool begin__setparam__float4x1(){return true;}
		virtual bool end__setparam__float4x1(){return true;}
		virtual bool data__setparam__float4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float4x1( void* attributeData ){return begin__setparam__float4x1();}
		bool _data__setparam__float4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x1();

	public:
		static const StringHash HASH_ELEMENT_FLOAT4X2 = 56130914;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X2 = 56129746;
		virtual bool begin__setparam__float4x2(){return true;}
		virtual bool end__setparam__float4x2(){return true;}
		virtual bool data__setparam__float4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float4x2( void* attributeData ){return begin__setparam__float4x2();}
		bool _data__setparam__float4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x2();

	public:
		static const StringHash HASH_ELEMENT_FLOAT4X3 = 56130915;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X3 = 56129747;
		virtual bool begin__setparam__float4x3(){return true;}
		virtual bool end__setparam__float4x3(){return true;}
		virtual bool data__setparam__float4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float4x3( void* attributeData ){return begin__setparam__float4x3();}
		bool _data__setparam__float4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x3();

	public:
		static const StringHash HASH_ELEMENT_FLOAT4X4 = 56130916;
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X4 = 56129748;
		virtual bool begin__setparam__float4x4(){return true;}
		virtual bool end__setparam__float4x4(){return true;}
		virtual bool data__setparam__float4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float4x4( void* attributeData ){return begin__setparam__float4x4();}
		bool _data__setparam__float4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x4();

	public:
		static const StringHash HASH_ELEMENT_SURFACE = 180930533;
		static const StringHash HASH_ELEMENT_SETPARAM__SURFACE = 63489941;
		struct setparam__surface__AttributeData
		{
			static const setparam__surface__AttributeData DEFAULT;

			const ParserChar* type;
		};
		virtual bool begin__setparam__surface( const setparam__surface__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__surface(){return true;}
	private:
		bool _begin__setparam__surface( void* attributeData ){return begin__setparam__surface(*static_cast<setparam__surface__AttributeData*>(attributeData));}
		bool _data__setparam__surface( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__surface();

	public:
		static const StringHash HASH_ELEMENT_INIT_AS_NULL = 261182076;
		static const StringHash HASH_ELEMENT_SURFACE__INIT_AS_NULL = 97694700;
		virtual bool begin__init_as_null(){return true;}
		virtual bool end__init_as_null(){return true;}
		virtual bool data__init_as_null( const void* data, size_t length ){return true;}
	private:
		bool _begin__init_as_null( void* attributeData ){return begin__init_as_null();}
		bool _data__init_as_null( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_as_null( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_as_null();

	public:
		static const StringHash HASH_ELEMENT_INIT_AS_TARGET = 61002324;
		static const StringHash HASH_ELEMENT_SURFACE__INIT_AS_TARGET = 37832724;
		virtual bool begin__init_as_target(){return true;}
		virtual bool end__init_as_target(){return true;}
		virtual bool data__init_as_target( const void* data, size_t length ){return true;}
	private:
		bool _begin__init_as_target( void* attributeData ){return begin__init_as_target();}
		bool _data__init_as_target( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_as_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_as_target();

	public:
		static const StringHash HASH_ELEMENT_INIT_CUBE = 10869717;
		static const StringHash HASH_ELEMENT_SURFACE__INIT_CUBE = 245137349;
		virtual bool begin__init_cube(){return true;}
		virtual bool end__init_cube(){return true;}
	private:
		bool _begin__init_cube( void* attributeData ){return begin__init_cube();}
		bool _data__init_cube( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_cube( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube();

	public:
		static const StringHash HASH_ELEMENT_ALL = 26668;
		static const StringHash HASH_ELEMENT_INIT_CUBE__ALL = 230624156;
		struct init_cube__all__AttributeData
		{
			static const init_cube__all__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__init_cube__all( const init_cube__all__AttributeData& attributeData ){return true;}
		virtual bool end__init_cube__all(){return true;}
	private:
		bool _begin__init_cube__all( void* attributeData ){return begin__init_cube__all(*static_cast<init_cube__all__AttributeData*>(attributeData));}
		bool _data__init_cube__all( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_cube__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube__all();

	public:
		static const StringHash HASH_ELEMENT_PRIMARY = 126892265;
		static const StringHash HASH_ELEMENT_INIT_CUBE__PRIMARY = 171149225;
		struct init_cube__primary__AttributeData
		{
			static const init_cube__primary__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__init_cube__primary( const init_cube__primary__AttributeData& attributeData ){return true;}
		virtual bool end__init_cube__primary(){return true;}
	private:
		bool _begin__init_cube__primary( void* attributeData ){return begin__init_cube__primary(*static_cast<init_cube__primary__AttributeData*>(attributeData));}
		bool _data__init_cube__primary( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_cube__primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube__primary();

	public:
		static const StringHash HASH_ELEMENT_ORDER = 7768770;
		static const StringHash HASH_ELEMENT_PRIMARY__ORDER = 241501282;
		virtual bool begin__order(){return true;}
		virtual bool end__order(){return true;}
		virtual bool data__order( const void* data, size_t length ){return true;}
	private:
		bool _begin__order( void* attributeData ){return begin__order();}
		bool _data__order( const ParserChar* text, size_t textLength );
		bool _validateBegin__order( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__order();

	public:
		static const StringHash HASH_ELEMENT_FACE = 444309;
		static const StringHash HASH_ELEMENT_INIT_CUBE__FACE = 200285253;
		struct init_cube__face__AttributeData
		{
			static const init_cube__face__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__init_cube__face( const init_cube__face__AttributeData& attributeData ){return true;}
		virtual bool end__init_cube__face(){return true;}
	private:
		bool _begin__init_cube__face( void* attributeData ){return begin__init_cube__face(*static_cast<init_cube__face__AttributeData*>(attributeData));}
		bool _data__init_cube__face( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_cube__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube__face();

	public:
		static const StringHash HASH_ELEMENT_INIT_VOLUME = 113667221;
		static const StringHash HASH_ELEMENT_SURFACE__INIT_VOLUME = 253916837;
		virtual bool begin__init_volume(){return true;}
		virtual bool end__init_volume(){return true;}
	private:
		bool _begin__init_volume( void* attributeData ){return begin__init_volume();}
		bool _data__init_volume( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_volume( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_volume();

	public:
		static const StringHash HASH_ELEMENT_INIT_VOLUME__ALL = 165229292;
		struct init_volume__all__AttributeData
		{
			static const init_volume__all__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__init_volume__all( const init_volume__all__AttributeData& attributeData ){return true;}
		virtual bool end__init_volume__all(){return true;}
	private:
		bool _begin__init_volume__all( void* attributeData ){return begin__init_volume__all(*static_cast<init_volume__all__AttributeData*>(attributeData));}
		bool _data__init_volume__all( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_volume__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_volume__all();

	public:
		static const StringHash HASH_ELEMENT_INIT_VOLUME__PRIMARY = 21488025;
		struct init_volume__primary__AttributeData
		{
			static const init_volume__primary__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__init_volume__primary( const init_volume__primary__AttributeData& attributeData ){return true;}
		virtual bool end__init_volume__primary(){return true;}
	private:
		bool _begin__init_volume__primary( void* attributeData ){return begin__init_volume__primary(*static_cast<init_volume__primary__AttributeData*>(attributeData));}
		bool _data__init_volume__primary( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_volume__primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_volume__primary();

	public:
		static const StringHash HASH_ELEMENT_INIT_PLANAR = 102904866;
		static const StringHash HASH_ELEMENT_SURFACE__INIT_PLANAR = 264653330;
		virtual bool begin__init_planar(){return true;}
		virtual bool end__init_planar(){return true;}
	private:
		bool _begin__init_planar( void* attributeData ){return begin__init_planar();}
		bool _data__init_planar( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_planar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_planar();

	public:
		static const StringHash HASH_ELEMENT_INIT_PLANAR__ALL = 36140396;
		struct init_planar__all__AttributeData
		{
			static const init_planar__all__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__init_planar__all( const init_planar__all__AttributeData& attributeData ){return true;}
		virtual bool end__init_planar__all(){return true;}
	private:
		bool _begin__init_planar__all( void* attributeData ){return begin__init_planar__all(*static_cast<init_planar__all__AttributeData*>(attributeData));}
		bool _data__init_planar__all( const ParserChar* text, size_t textLength );
		bool _validateBegin__init_planar__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_planar__all();

	public:
		static const StringHash HASH_ELEMENT_INIT_FROM = 10856717;
		static const StringHash HASH_ELEMENT_SURFACE__INIT_FROM = 245107997;
		static const StringHash HASH_ATTRIBUTE_MIP = 29696;
		static const StringHash HASH_ATTRIBUTE_SLICE = 8007573;
		static const StringHash HASH_ATTRIBUTE_FACE = 444309;
		struct surface__init_from__AttributeData
		{
			static const surface__init_from__AttributeData DEFAULT;

			unsigned long mip;
			unsigned long slice;
			const ParserChar* face;
		};
		virtual bool begin__surface__init_from( const surface__init_from__AttributeData& attributeData ){return true;}
		virtual bool end__surface__init_from(){return true;}
		virtual bool data__surface__init_from( const void* data, size_t length ){return true;}
	private:
		bool _begin__surface__init_from( void* attributeData ){return begin__surface__init_from(*static_cast<surface__init_from__AttributeData*>(attributeData));}
		bool _data__surface__init_from( const ParserChar* text, size_t textLength );
		bool _validateBegin__surface__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__surface__init_from();

	public:
		static const StringHash HASH_ELEMENT_FORMAT = 114725764;
		static const StringHash HASH_ELEMENT_SURFACE__FORMAT = 219247124;
		virtual bool begin__format(){return true;}
		virtual bool end__format(){return true;}
		virtual bool data__format( const void* data, size_t length ){return true;}
	private:
		bool _begin__format( void* attributeData ){return begin__format();}
		bool _data__format( const ParserChar* text, size_t textLength );
		bool _validateBegin__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__format();

	public:
		static const StringHash HASH_ELEMENT_FORMAT_HINT = 151553892;
		static const StringHash HASH_ELEMENT_SURFACE__FORMAT_HINT = 22346100;
		virtual bool begin__format_hint(){return true;}
		virtual bool end__format_hint(){return true;}
	private:
		bool _begin__format_hint( void* attributeData ){return begin__format_hint();}
		bool _data__format_hint( const ParserChar* text, size_t textLength );
		bool _validateBegin__format_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__format_hint();

	public:
		static const StringHash HASH_ELEMENT_CHANNELS = 243617443;
		static const StringHash HASH_ELEMENT_FORMAT_HINT__CHANNELS = 153491235;
		virtual bool begin__channels(){return true;}
		virtual bool end__channels(){return true;}
		virtual bool data__channels( const void* data, size_t length ){return true;}
	private:
		bool _begin__channels( void* attributeData ){return begin__channels();}
		bool _data__channels( const ParserChar* text, size_t textLength );
		bool _validateBegin__channels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__channels();

	public:
		static const StringHash HASH_ELEMENT_RANGE = 7898325;
		static const StringHash HASH_ELEMENT_FORMAT_HINT__RANGE = 98570949;
		virtual bool begin__range(){return true;}
		virtual bool end__range(){return true;}
		virtual bool data__range( const void* data, size_t length ){return true;}
	private:
		bool _begin__range( void* attributeData ){return begin__range();}
		bool _data__range( const ParserChar* text, size_t textLength );
		bool _validateBegin__range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__range();

	public:
		static const StringHash HASH_ELEMENT_PRECISION = 195095006;
		static const StringHash HASH_ELEMENT_FORMAT_HINT__PRECISION = 227897774;
		virtual bool begin__precision(){return true;}
		virtual bool end__precision(){return true;}
		virtual bool data__precision( const void* data, size_t length ){return true;}
	private:
		bool _begin__precision( void* attributeData ){return begin__precision();}
		bool _data__precision( const ParserChar* text, size_t textLength );
		bool _validateBegin__precision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__precision();

	public:
		static const StringHash HASH_ELEMENT_OPTION = 124235870;
		static const StringHash HASH_ELEMENT_FORMAT_HINT__OPTION = 249614094;
		virtual bool begin__option(){return true;}
		virtual bool end__option(){return true;}
		virtual bool data__option( const void* data, size_t length ){return true;}
	private:
		bool _begin__option( void* attributeData ){return begin__option();}
		bool _data__option( const ParserChar* text, size_t textLength );
		bool _validateBegin__option( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__option();

	public:
		static const StringHash HASH_ELEMENT_FORMAT_HINT__EXTRA = 97815953;
		struct format_hint__extra__AttributeData
		{
			static const format_hint__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__format_hint__extra( const format_hint__extra__AttributeData& attributeData ){return true;}
		virtual bool end__format_hint__extra(){return true;}
	private:
		bool _begin__format_hint__extra( void* attributeData ){return begin__format_hint__extra(*static_cast<format_hint__extra__AttributeData*>(attributeData));}
		bool _data__format_hint__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__format_hint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__format_hint__extra();

	public:
		static const StringHash HASH_ELEMENT_SIZE = 499973;
		static const StringHash HASH_ELEMENT_SURFACE__SIZE = 27158757;
		virtual bool begin__surface__size(){return true;}
		virtual bool end__surface__size(){return true;}
		virtual bool data__surface__size( const void* data, size_t length ){return true;}
	private:
		bool _begin__surface__size( void* attributeData ){return begin__surface__size();}
		bool _data__surface__size( const ParserChar* text, size_t textLength );
		bool _validateBegin__surface__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__surface__size();

	public:
		static const StringHash HASH_ELEMENT_VIEWPORT_RATIO = 128383919;
		static const StringHash HASH_ELEMENT_SURFACE__VIEWPORT_RATIO = 39354991;
		virtual bool begin__viewport_ratio(){return true;}
		virtual bool end__viewport_ratio(){return true;}
		virtual bool data__viewport_ratio( const void* data, size_t length ){return true;}
	private:
		bool _begin__viewport_ratio( void* attributeData ){return begin__viewport_ratio();}
		bool _data__viewport_ratio( const ParserChar* text, size_t textLength );
		bool _validateBegin__viewport_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__viewport_ratio();

	public:
		static const StringHash HASH_ELEMENT_MIP_LEVELS = 103517267;
		static const StringHash HASH_ELEMENT_SURFACE__MIP_LEVELS = 95669747;
		virtual bool begin__mip_levels(){return true;}
		virtual bool end__mip_levels(){return true;}
		virtual bool data__mip_levels( const void* data, size_t length ){return true;}
	private:
		bool _begin__mip_levels( void* attributeData ){return begin__mip_levels();}
		bool _data__mip_levels( const ParserChar* text, size_t textLength );
		bool _validateBegin__mip_levels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mip_levels();

	public:
		static const StringHash HASH_ELEMENT_MIPMAP_GENERATE = 225753461;
		static const StringHash HASH_ELEMENT_SURFACE__MIPMAP_GENERATE = 57490693;
		virtual bool begin__mipmap_generate(){return true;}
		virtual bool end__mipmap_generate(){return true;}
		virtual bool data__mipmap_generate( const void* data, size_t length ){return true;}
	private:
		bool _begin__mipmap_generate( void* attributeData ){return begin__mipmap_generate();}
		bool _data__mipmap_generate( const ParserChar* text, size_t textLength );
		bool _validateBegin__mipmap_generate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mipmap_generate();

	public:
		static const StringHash HASH_ELEMENT_SURFACE__EXTRA = 164660625;
		struct surface__extra__AttributeData
		{
			static const surface__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__surface__extra( const surface__extra__AttributeData& attributeData ){return true;}
		virtual bool end__surface__extra(){return true;}
	private:
		bool _begin__surface__extra( void* attributeData ){return begin__surface__extra(*static_cast<surface__extra__AttributeData*>(attributeData));}
		bool _data__surface__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__surface__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__surface__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER1D = 74628308;
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLER1D = 74630612;
		virtual bool begin__setparam__sampler1D(){return true;}
		virtual bool end__setparam__sampler1D(){return true;}
	private:
		bool _begin__setparam__sampler1D( void* attributeData ){return begin__setparam__sampler1D();}
		bool _data__setparam__sampler1D( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler1D();

	public:
		static const StringHash HASH_ELEMENT_SOURCE = 128370837;
		static const StringHash HASH_ELEMENT_SAMPLER1D__SOURCE = 70915797;
		virtual bool begin__sampler1D__source(){return true;}
		virtual bool end__sampler1D__source(){return true;}
		virtual bool data__sampler1D__source( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__source( void* attributeData ){return begin__sampler1D__source();}
		bool _data__sampler1D__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__source();

	public:
		static const StringHash HASH_ELEMENT_WRAP_S = 132679267;
		static const StringHash HASH_ELEMENT_SAMPLER1D__WRAP_S = 72637475;
		virtual bool begin__sampler1D__wrap_s(){return true;}
		virtual bool end__sampler1D__wrap_s(){return true;}
		virtual bool data__sampler1D__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__wrap_s( void* attributeData ){return begin__sampler1D__wrap_s();}
		bool _data__sampler1D__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_MINFILTER = 80760514;
		static const StringHash HASH_ELEMENT_SAMPLER1D__MINFILTER = 153924226;
		virtual bool begin__sampler1D__minfilter(){return true;}
		virtual bool end__sampler1D__minfilter(){return true;}
		virtual bool data__sampler1D__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__minfilter( void* attributeData ){return begin__sampler1D__minfilter();}
		bool _data__sampler1D__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__minfilter();

	public:
		static const StringHash HASH_ELEMENT_MAGFILTER = 231754162;
		static const StringHash HASH_ELEMENT_SAMPLER1D__MAGFILTER = 2929266;
		virtual bool begin__sampler1D__magfilter(){return true;}
		virtual bool end__sampler1D__magfilter(){return true;}
		virtual bool data__sampler1D__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__magfilter( void* attributeData ){return begin__sampler1D__magfilter();}
		bool _data__sampler1D__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__magfilter();

	public:
		static const StringHash HASH_ELEMENT_MIPFILTER = 114314946;
		static const StringHash HASH_ELEMENT_SAMPLER1D__MIPFILTER = 187478786;
		virtual bool begin__sampler1D__mipfilter(){return true;}
		virtual bool end__sampler1D__mipfilter(){return true;}
		virtual bool data__sampler1D__mipfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__mipfilter( void* attributeData ){return begin__sampler1D__mipfilter();}
		bool _data__sampler1D__mipfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__mipfilter();

	public:
		static const StringHash HASH_ELEMENT_BORDER_COLOR = 47245730;
		static const StringHash HASH_ELEMENT_SAMPLER1D__BORDER_COLOR = 18094050;
		virtual bool begin__sampler1D__border_color(){return true;}
		virtual bool end__sampler1D__border_color(){return true;}
		virtual bool data__sampler1D__border_color( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__border_color( void* attributeData ){return begin__sampler1D__border_color();}
		bool _data__sampler1D__border_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__border_color();

	public:
		static const StringHash HASH_ELEMENT_MIPMAP_MAXLEVEL = 267058828;
		static const StringHash HASH_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL = 72229196;
		virtual bool begin__sampler1D__mipmap_maxlevel(){return true;}
		virtual bool end__sampler1D__mipmap_maxlevel(){return true;}
		virtual bool data__sampler1D__mipmap_maxlevel( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__mipmap_maxlevel( void* attributeData ){return begin__sampler1D__mipmap_maxlevel();}
		bool _data__sampler1D__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__mipmap_maxlevel();

	public:
		static const StringHash HASH_ELEMENT_MIPMAP_BIAS = 137463987;
		static const StringHash HASH_ELEMENT_SAMPLER1D__MIPMAP_BIAS = 216810323;
		virtual bool begin__sampler1D__mipmap_bias(){return true;}
		virtual bool end__sampler1D__mipmap_bias(){return true;}
		virtual bool data__sampler1D__mipmap_bias( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler1D__mipmap_bias( void* attributeData ){return begin__sampler1D__mipmap_bias();}
		bool _data__sampler1D__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__mipmap_bias();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER1D__EXTRA = 74921569;
		struct sampler1D__extra__AttributeData
		{
			static const sampler1D__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__sampler1D__extra( const sampler1D__extra__AttributeData& attributeData ){return true;}
		virtual bool end__sampler1D__extra(){return true;}
	private:
		bool _begin__sampler1D__extra( void* attributeData ){return begin__sampler1D__extra(*static_cast<sampler1D__extra__AttributeData*>(attributeData));}
		bool _data__sampler1D__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler1D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D = 74628324;
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLER2D = 74630628;
		virtual bool begin__setparam__sampler2D(){return true;}
		virtual bool end__setparam__sampler2D(){return true;}
	private:
		bool _begin__setparam__sampler2D( void* attributeData ){return begin__setparam__sampler2D();}
		bool _data__setparam__sampler2D( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler2D();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__SOURCE = 70919893;
		virtual bool begin__sampler2D__source(){return true;}
		virtual bool end__sampler2D__source(){return true;}
		virtual bool data__sampler2D__source( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__source( void* attributeData ){return begin__sampler2D__source();}
		bool _data__sampler2D__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__source();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__WRAP_S = 72641571;
		virtual bool begin__sampler2D__wrap_s(){return true;}
		virtual bool end__sampler2D__wrap_s(){return true;}
		virtual bool data__sampler2D__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__wrap_s( void* attributeData ){return begin__sampler2D__wrap_s();}
		bool _data__sampler2D__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_WRAP_T = 132679268;
		static const StringHash HASH_ELEMENT_SAMPLER2D__WRAP_T = 72641572;
		virtual bool begin__sampler2D__wrap_t(){return true;}
		virtual bool end__sampler2D__wrap_t(){return true;}
		virtual bool data__sampler2D__wrap_t( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__wrap_t( void* attributeData ){return begin__sampler2D__wrap_t();}
		bool _data__sampler2D__wrap_t( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__wrap_t();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__MINFILTER = 170701442;
		virtual bool begin__sampler2D__minfilter(){return true;}
		virtual bool end__sampler2D__minfilter(){return true;}
		virtual bool data__sampler2D__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__minfilter( void* attributeData ){return begin__sampler2D__minfilter();}
		bool _data__sampler2D__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__minfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__MAGFILTER = 53260914;
		virtual bool begin__sampler2D__magfilter(){return true;}
		virtual bool end__sampler2D__magfilter(){return true;}
		virtual bool data__sampler2D__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__magfilter( void* attributeData ){return begin__sampler2D__magfilter();}
		bool _data__sampler2D__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__magfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__MIPFILTER = 137147138;
		virtual bool begin__sampler2D__mipfilter(){return true;}
		virtual bool end__sampler2D__mipfilter(){return true;}
		virtual bool data__sampler2D__mipfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__mipfilter( void* attributeData ){return begin__sampler2D__mipfilter();}
		bool _data__sampler2D__mipfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__mipfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__BORDER_COLOR = 18106338;
		virtual bool begin__sampler2D__border_color(){return true;}
		virtual bool end__sampler2D__border_color(){return true;}
		virtual bool data__sampler2D__border_color( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__border_color( void* attributeData ){return begin__sampler2D__border_color();}
		bool _data__sampler2D__border_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__border_color();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__MIPMAP_MAXLEVEL = 21897548;
		virtual bool begin__sampler2D__mipmap_maxlevel(){return true;}
		virtual bool end__sampler2D__mipmap_maxlevel(){return true;}
		virtual bool data__sampler2D__mipmap_maxlevel( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__mipmap_maxlevel( void* attributeData ){return begin__sampler2D__mipmap_maxlevel();}
		bool _data__sampler2D__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__mipmap_maxlevel();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__MIPMAP_BIAS = 216811091;
		virtual bool begin__sampler2D__mipmap_bias(){return true;}
		virtual bool end__sampler2D__mipmap_bias(){return true;}
		virtual bool data__sampler2D__mipmap_bias( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler2D__mipmap_bias( void* attributeData ){return begin__sampler2D__mipmap_bias();}
		bool _data__sampler2D__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__mipmap_bias();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER2D__EXTRA = 74921313;
		struct sampler2D__extra__AttributeData
		{
			static const sampler2D__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__sampler2D__extra( const sampler2D__extra__AttributeData& attributeData ){return true;}
		virtual bool end__sampler2D__extra(){return true;}
	private:
		bool _begin__sampler2D__extra( void* attributeData ){return begin__sampler2D__extra(*static_cast<sampler2D__extra__AttributeData*>(attributeData));}
		bool _data__sampler2D__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler2D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D = 74628340;
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLER3D = 74630644;
		virtual bool begin__setparam__sampler3D(){return true;}
		virtual bool end__setparam__sampler3D(){return true;}
	private:
		bool _begin__setparam__sampler3D( void* attributeData ){return begin__setparam__sampler3D();}
		bool _data__setparam__sampler3D( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler3D();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__SOURCE = 70923989;
		virtual bool begin__sampler3D__source(){return true;}
		virtual bool end__sampler3D__source(){return true;}
		virtual bool data__sampler3D__source( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__source( void* attributeData ){return begin__sampler3D__source();}
		bool _data__sampler3D__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__source();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_S = 72645667;
		virtual bool begin__sampler3D__wrap_s(){return true;}
		virtual bool end__sampler3D__wrap_s(){return true;}
		virtual bool data__sampler3D__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__wrap_s( void* attributeData ){return begin__sampler3D__wrap_s();}
		bool _data__sampler3D__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_T = 72645668;
		virtual bool begin__sampler3D__wrap_t(){return true;}
		virtual bool end__sampler3D__wrap_t(){return true;}
		virtual bool data__sampler3D__wrap_t( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__wrap_t( void* attributeData ){return begin__sampler3D__wrap_t();}
		bool _data__sampler3D__wrap_t( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__wrap_t();

	public:
		static const StringHash HASH_ELEMENT_WRAP_P = 132679264;
		static const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_P = 72645664;
		virtual bool begin__sampler3D__wrap_p(){return true;}
		virtual bool end__sampler3D__wrap_p(){return true;}
		virtual bool data__sampler3D__wrap_p( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__wrap_p( void* attributeData ){return begin__sampler3D__wrap_p();}
		bool _data__sampler3D__wrap_p( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__wrap_p();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__MINFILTER = 187478658;
		virtual bool begin__sampler3D__minfilter(){return true;}
		virtual bool end__sampler3D__minfilter(){return true;}
		virtual bool data__sampler3D__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__minfilter( void* attributeData ){return begin__sampler3D__minfilter();}
		bool _data__sampler3D__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__minfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__MAGFILTER = 36483698;
		virtual bool begin__sampler3D__magfilter(){return true;}
		virtual bool end__sampler3D__magfilter(){return true;}
		virtual bool data__sampler3D__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__magfilter( void* attributeData ){return begin__sampler3D__magfilter();}
		bool _data__sampler3D__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__magfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__MIPFILTER = 153924354;
		virtual bool begin__sampler3D__mipfilter(){return true;}
		virtual bool end__sampler3D__mipfilter(){return true;}
		virtual bool data__sampler3D__mipfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__mipfilter( void* attributeData ){return begin__sampler3D__mipfilter();}
		bool _data__sampler3D__mipfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__mipfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__BORDER_COLOR = 18102242;
		virtual bool begin__sampler3D__border_color(){return true;}
		virtual bool end__sampler3D__border_color(){return true;}
		virtual bool data__sampler3D__border_color( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__border_color( void* attributeData ){return begin__sampler3D__border_color();}
		bool _data__sampler3D__border_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__border_color();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__MIPMAP_MAXLEVEL = 38674764;
		virtual bool begin__sampler3D__mipmap_maxlevel(){return true;}
		virtual bool end__sampler3D__mipmap_maxlevel(){return true;}
		virtual bool data__sampler3D__mipmap_maxlevel( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__mipmap_maxlevel( void* attributeData ){return begin__sampler3D__mipmap_maxlevel();}
		bool _data__sampler3D__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__mipmap_maxlevel();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__MIPMAP_BIAS = 216810835;
		virtual bool begin__sampler3D__mipmap_bias(){return true;}
		virtual bool end__sampler3D__mipmap_bias(){return true;}
		virtual bool data__sampler3D__mipmap_bias( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler3D__mipmap_bias( void* attributeData ){return begin__sampler3D__mipmap_bias();}
		bool _data__sampler3D__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__mipmap_bias();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER3D__EXTRA = 74921057;
		struct sampler3D__extra__AttributeData
		{
			static const sampler3D__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__sampler3D__extra( const sampler3D__extra__AttributeData& attributeData ){return true;}
		virtual bool end__sampler3D__extra(){return true;}
	private:
		bool _begin__sampler3D__extra( void* attributeData ){return begin__sampler3D__extra(*static_cast<sampler3D__extra__AttributeData*>(attributeData));}
		bool _data__sampler3D__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler3D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE = 46075157;
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLERCUBE = 46533909;
		virtual bool begin__setparam__samplerCUBE(){return true;}
		virtual bool end__setparam__samplerCUBE(){return true;}
	private:
		bool _begin__setparam__samplerCUBE( void* attributeData ){return begin__setparam__samplerCUBE();}
		bool _data__setparam__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__samplerCUBE();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__SOURCE = 162255509;
		virtual bool begin__samplerCUBE__source(){return true;}
		virtual bool end__samplerCUBE__source(){return true;}
		virtual bool data__samplerCUBE__source( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__source( void* attributeData ){return begin__samplerCUBE__source();}
		bool _data__samplerCUBE__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__source();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__WRAP_S = 166043747;
		virtual bool begin__samplerCUBE__wrap_s(){return true;}
		virtual bool end__samplerCUBE__wrap_s(){return true;}
		virtual bool data__samplerCUBE__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__wrap_s( void* attributeData ){return begin__samplerCUBE__wrap_s();}
		bool _data__samplerCUBE__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__WRAP_T = 166043748;
		virtual bool begin__samplerCUBE__wrap_t(){return true;}
		virtual bool end__samplerCUBE__wrap_t(){return true;}
		virtual bool data__samplerCUBE__wrap_t( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__wrap_t( void* attributeData ){return begin__samplerCUBE__wrap_t();}
		bool _data__samplerCUBE__wrap_t( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__wrap_t();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__WRAP_P = 166043744;
		virtual bool begin__samplerCUBE__wrap_p(){return true;}
		virtual bool end__samplerCUBE__wrap_p(){return true;}
		virtual bool data__samplerCUBE__wrap_p( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__wrap_p( void* attributeData ){return begin__samplerCUBE__wrap_p();}
		bool _data__samplerCUBE__wrap_p( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__wrap_p();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__MINFILTER = 91261426;
		virtual bool begin__samplerCUBE__minfilter(){return true;}
		virtual bool end__samplerCUBE__minfilter(){return true;}
		virtual bool data__samplerCUBE__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__minfilter( void* attributeData ){return begin__samplerCUBE__minfilter();}
		bool _data__samplerCUBE__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__minfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__MAGFILTER = 208701794;
		virtual bool begin__samplerCUBE__magfilter(){return true;}
		virtual bool end__samplerCUBE__magfilter(){return true;}
		virtual bool data__samplerCUBE__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__magfilter( void* attributeData ){return begin__samplerCUBE__magfilter();}
		bool _data__samplerCUBE__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__magfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__MIPFILTER = 124816914;
		virtual bool begin__samplerCUBE__mipfilter(){return true;}
		virtual bool end__samplerCUBE__mipfilter(){return true;}
		virtual bool data__samplerCUBE__mipfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__mipfilter( void* attributeData ){return begin__samplerCUBE__mipfilter();}
		bool _data__samplerCUBE__mipfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__mipfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__BORDER_COLOR = 247714722;
		virtual bool begin__samplerCUBE__border_color(){return true;}
		virtual bool end__samplerCUBE__border_color(){return true;}
		virtual bool data__samplerCUBE__border_color( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__border_color( void* attributeData ){return begin__samplerCUBE__border_color();}
		bool _data__samplerCUBE__border_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__border_color();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__MIPMAP_MAXLEVEL = 9059932;
		virtual bool begin__samplerCUBE__mipmap_maxlevel(){return true;}
		virtual bool end__samplerCUBE__mipmap_maxlevel(){return true;}
		virtual bool data__samplerCUBE__mipmap_maxlevel( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__mipmap_maxlevel( void* attributeData ){return begin__samplerCUBE__mipmap_maxlevel();}
		bool _data__samplerCUBE__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__mipmap_maxlevel();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__MIPMAP_BIAS = 150034195;
		virtual bool begin__samplerCUBE__mipmap_bias(){return true;}
		virtual bool end__samplerCUBE__mipmap_bias(){return true;}
		virtual bool data__samplerCUBE__mipmap_bias( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerCUBE__mipmap_bias( void* attributeData ){return begin__samplerCUBE__mipmap_bias();}
		bool _data__samplerCUBE__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__mipmap_bias();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERCUBE__EXTRA = 11282977;
		struct samplerCUBE__extra__AttributeData
		{
			static const samplerCUBE__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__samplerCUBE__extra( const samplerCUBE__extra__AttributeData& attributeData ){return true;}
		virtual bool end__samplerCUBE__extra(){return true;}
	private:
		bool _begin__samplerCUBE__extra( void* attributeData ){return begin__samplerCUBE__extra(*static_cast<samplerCUBE__extra__AttributeData*>(attributeData));}
		bool _data__samplerCUBE__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerCUBE__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT = 46067188;
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLERRECT = 46657012;
		virtual bool begin__setparam__samplerRECT(){return true;}
		virtual bool end__setparam__samplerRECT(){return true;}
	private:
		bool _begin__setparam__samplerRECT( void* attributeData ){return begin__setparam__samplerRECT();}
		bool _data__setparam__samplerRECT( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__samplerRECT();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__SOURCE = 143340949;
		virtual bool begin__samplerRECT__source(){return true;}
		virtual bool end__samplerRECT__source(){return true;}
		virtual bool data__samplerRECT__source( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__source( void* attributeData ){return begin__samplerRECT__source();}
		bool _data__samplerRECT__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__source();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__WRAP_S = 134576483;
		virtual bool begin__samplerRECT__wrap_s(){return true;}
		virtual bool end__samplerRECT__wrap_s(){return true;}
		virtual bool data__samplerRECT__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__wrap_s( void* attributeData ){return begin__samplerRECT__wrap_s();}
		bool _data__samplerRECT__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__WRAP_T = 134576484;
		virtual bool begin__samplerRECT__wrap_t(){return true;}
		virtual bool end__samplerRECT__wrap_t(){return true;}
		virtual bool data__samplerRECT__wrap_t( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__wrap_t( void* attributeData ){return begin__samplerRECT__wrap_t();}
		bool _data__samplerRECT__wrap_t( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__wrap_t();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__MINFILTER = 186710002;
		virtual bool begin__samplerRECT__minfilter(){return true;}
		virtual bool end__samplerRECT__minfilter(){return true;}
		virtual bool data__samplerRECT__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__minfilter( void* attributeData ){return begin__samplerRECT__minfilter();}
		bool _data__samplerRECT__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__minfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__MAGFILTER = 35714914;
		virtual bool begin__samplerRECT__magfilter(){return true;}
		virtual bool end__samplerRECT__magfilter(){return true;}
		virtual bool data__samplerRECT__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__magfilter( void* attributeData ){return begin__samplerRECT__magfilter();}
		bool _data__samplerRECT__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__magfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__MIPFILTER = 153154578;
		virtual bool begin__samplerRECT__mipfilter(){return true;}
		virtual bool end__samplerRECT__mipfilter(){return true;}
		virtual bool data__samplerRECT__mipfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__mipfilter( void* attributeData ){return begin__samplerRECT__mipfilter();}
		bool _data__samplerRECT__mipfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__mipfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__BORDER_COLOR = 220411554;
		virtual bool begin__samplerRECT__border_color(){return true;}
		virtual bool end__samplerRECT__border_color(){return true;}
		virtual bool data__samplerRECT__border_color( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__border_color( void* attributeData ){return begin__samplerRECT__border_color();}
		bool _data__samplerRECT__border_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__border_color();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__MIPMAP_MAXLEVEL = 35283036;
		virtual bool begin__samplerRECT__mipmap_maxlevel(){return true;}
		virtual bool end__samplerRECT__mipmap_maxlevel(){return true;}
		virtual bool data__samplerRECT__mipmap_maxlevel( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__mipmap_maxlevel( void* attributeData ){return begin__samplerRECT__mipmap_maxlevel();}
		bool _data__samplerRECT__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__mipmap_maxlevel();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__MIPMAP_BIAS = 145446243;
		virtual bool begin__samplerRECT__mipmap_bias(){return true;}
		virtual bool end__samplerRECT__mipmap_bias(){return true;}
		virtual bool data__samplerRECT__mipmap_bias( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerRECT__mipmap_bias( void* attributeData ){return begin__samplerRECT__mipmap_bias();}
		bool _data__samplerRECT__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__mipmap_bias();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERRECT__EXTRA = 11674705;
		struct samplerRECT__extra__AttributeData
		{
			static const samplerRECT__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__samplerRECT__extra( const samplerRECT__extra__AttributeData& attributeData ){return true;}
		virtual bool end__samplerRECT__extra(){return true;}
	private:
		bool _begin__samplerRECT__extra( void* attributeData ){return begin__samplerRECT__extra(*static_cast<samplerRECT__extra__AttributeData*>(attributeData));}
		bool _data__samplerRECT__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerRECT__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH = 200336040;
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLERDEPTH = 207676072;
		virtual bool begin__setparam__samplerDEPTH(){return true;}
		virtual bool end__setparam__samplerDEPTH(){return true;}
	private:
		bool _begin__setparam__samplerDEPTH( void* attributeData ){return begin__setparam__samplerDEPTH();}
		bool _data__setparam__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__samplerDEPTH();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH__SOURCE = 109342549;
		virtual bool begin__samplerDEPTH__source(){return true;}
		virtual bool end__samplerDEPTH__source(){return true;}
		virtual bool data__samplerDEPTH__source( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerDEPTH__source( void* attributeData ){return begin__samplerDEPTH__source();}
		bool _data__samplerDEPTH__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerDEPTH__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__source();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH__WRAP_S = 101327779;
		virtual bool begin__samplerDEPTH__wrap_s(){return true;}
		virtual bool end__samplerDEPTH__wrap_s(){return true;}
		virtual bool data__samplerDEPTH__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerDEPTH__wrap_s( void* attributeData ){return begin__samplerDEPTH__wrap_s();}
		bool _data__samplerDEPTH__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerDEPTH__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH__WRAP_T = 101327780;
		virtual bool begin__samplerDEPTH__wrap_t(){return true;}
		virtual bool end__samplerDEPTH__wrap_t(){return true;}
		virtual bool data__samplerDEPTH__wrap_t( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerDEPTH__wrap_t( void* attributeData ){return begin__samplerDEPTH__wrap_t();}
		bool _data__samplerDEPTH__wrap_t( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerDEPTH__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__wrap_t();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH__MINFILTER = 246699810;
		virtual bool begin__samplerDEPTH__minfilter(){return true;}
		virtual bool end__samplerDEPTH__minfilter(){return true;}
		virtual bool data__samplerDEPTH__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerDEPTH__minfilter( void* attributeData ){return begin__samplerDEPTH__minfilter();}
		bool _data__samplerDEPTH__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerDEPTH__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__minfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH__MAGFILTER = 129259410;
		virtual bool begin__samplerDEPTH__magfilter(){return true;}
		virtual bool end__samplerDEPTH__magfilter(){return true;}
		virtual bool data__samplerDEPTH__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__samplerDEPTH__magfilter( void* attributeData ){return begin__samplerDEPTH__magfilter();}
		bool _data__samplerDEPTH__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerDEPTH__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__magfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLERDEPTH__EXTRA = 206754289;
		struct samplerDEPTH__extra__AttributeData
		{
			static const samplerDEPTH__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__samplerDEPTH__extra( const samplerDEPTH__extra__AttributeData& attributeData ){return true;}
		virtual bool end__samplerDEPTH__extra(){return true;}
	private:
		bool _begin__samplerDEPTH__extra( void* attributeData ){return begin__samplerDEPTH__extra(*static_cast<samplerDEPTH__extra__AttributeData*>(attributeData));}
		bool _data__samplerDEPTH__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__samplerDEPTH__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__extra();

	public:
		static const StringHash HASH_ELEMENT_ENUM = 443837;
		static const StringHash HASH_ELEMENT_SETPARAM__ENUM = 210365;
		virtual bool begin__setparam__enum(){return true;}
		virtual bool end__setparam__enum(){return true;}
		virtual bool data__setparam__enum( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__enum( void* attributeData ){return begin__setparam__enum();}
		bool _data__setparam__enum( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__enum();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_EFFECT__EXTRA = 101966321;
		struct instance_effect__extra__AttributeData
		{
			static const instance_effect__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_effect__extra( const instance_effect__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_effect__extra(){return true;}
	private:
		bool _begin__instance_effect__extra( void* attributeData ){return begin__instance_effect__extra(*static_cast<instance_effect__extra__AttributeData*>(attributeData));}
		bool _data__instance_effect__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_effect__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_effect__extra();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION = 3721230;
		struct animation__AttributeData
		{
			static const animation__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__animation( const animation__AttributeData& attributeData ){return true;}
		virtual bool end__animation(){return true;}
	private:
		bool _begin__animation( void* attributeData ){return begin__animation(*static_cast<animation__AttributeData*>(attributeData));}
		bool _data__animation( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION__ASSET = 148121732;
		virtual bool begin__animation__asset(){return true;}
		virtual bool end__animation__asset(){return true;}
	private:
		bool _begin__animation__asset( void* attributeData ){return begin__animation__asset();}
		bool _data__animation__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation__asset();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION__SOURCE = 242146325;
		struct animation__source__AttributeData
		{
			static const animation__source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__animation__source( const animation__source__AttributeData& attributeData ){return true;}
		virtual bool end__animation__source(){return true;}
	private:
		bool _begin__animation__source( void* attributeData ){return begin__animation__source(*static_cast<animation__source__AttributeData*>(attributeData));}
		bool _data__animation__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation__source();

	public:
		static const StringHash HASH_ELEMENT_SOURCE__ASSET = 255074340;
		virtual bool begin__source__asset(){return true;}
		virtual bool end__source__asset(){return true;}
	private:
		bool _begin__source__asset( void* attributeData ){return begin__source__asset();}
		bool _data__source__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__source__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source__asset();

	public:
		static const StringHash HASH_ELEMENT_IDREF_ARRAY = 202706457;
		static const StringHash HASH_ELEMENT_SOURCE__IDREF_ARRAY = 84510713;
		static const StringHash HASH_ATTRIBUTE_COUNT = 6974548;
		struct IDREF_array__AttributeData
		{
			static const IDREF_array__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* count;
		};
		virtual bool begin__IDREF_array( const IDREF_array__AttributeData& attributeData ){return true;}
		virtual bool end__IDREF_array(){return true;}
		virtual bool data__IDREF_array( const void* data, size_t length ){return true;}
	private:
		bool _begin__IDREF_array( void* attributeData ){return begin__IDREF_array(*static_cast<IDREF_array__AttributeData*>(attributeData));}
		bool _data__IDREF_array( const ParserChar* text, size_t textLength );
		bool _validateBegin__IDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__IDREF_array();

	public:
		static const StringHash HASH_ELEMENT_NAME_ARRAY = 190697657;
		static const StringHash HASH_ELEMENT_SOURCE__NAME_ARRAY = 95291433;
		struct Name_array__AttributeData
		{
			static const Name_array__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* count;
		};
		virtual bool begin__Name_array( const Name_array__AttributeData& attributeData ){return true;}
		virtual bool end__Name_array(){return true;}
		virtual bool data__Name_array( const void* data, size_t length ){return true;}
	private:
		bool _begin__Name_array( void* attributeData ){return begin__Name_array(*static_cast<Name_array__AttributeData*>(attributeData));}
		bool _data__Name_array( const ParserChar* text, size_t textLength );
		bool _validateBegin__Name_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__Name_array();

	public:
		static const StringHash HASH_ELEMENT_BOOL_ARRAY = 39718633;
		static const StringHash HASH_ELEMENT_SOURCE__BOOL_ARRAY = 11257449;
		struct bool_array__AttributeData
		{
			static const bool_array__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* count;
		};
		virtual bool begin__bool_array( const bool_array__AttributeData& attributeData ){return true;}
		virtual bool end__bool_array(){return true;}
		virtual bool data__bool_array( const void* data, size_t length ){return true;}
	private:
		bool _begin__bool_array( void* attributeData ){return begin__bool_array(*static_cast<bool_array__AttributeData*>(attributeData));}
		bool _data__bool_array( const ParserChar* text, size_t textLength );
		bool _validateBegin__bool_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bool_array();

	public:
		static const StringHash HASH_ELEMENT_FLOAT_ARRAY = 171289865;
		static const StringHash HASH_ELEMENT_SOURCE__FLOAT_ARRAY = 124331241;
		static const StringHash HASH_ATTRIBUTE_DIGITS = 112189619;
		static const StringHash HASH_ATTRIBUTE_MAGNITUDE = 240175317;
		struct float_array__AttributeData
		{
			static const float_array__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* count;
			int digits;
			int magnitude;
		};
		virtual bool begin__float_array( const float_array__AttributeData& attributeData ){return true;}
		virtual bool end__float_array(){return true;}
		virtual bool data__float_array( const void* data, size_t length ){return true;}
	private:
		bool _begin__float_array( void* attributeData ){return begin__float_array(*static_cast<float_array__AttributeData*>(attributeData));}
		bool _data__float_array( const ParserChar* text, size_t textLength );
		bool _validateBegin__float_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__float_array();

	public:
		static const StringHash HASH_ELEMENT_INT_ARRAY = 173598937;
		static const StringHash HASH_ELEMENT_SOURCE__INT_ARRAY = 28814425;
		static const StringHash HASH_ATTRIBUTE_MININCLUSIVE = 259829893;
		static const StringHash HASH_ATTRIBUTE_MAXINCLUSIVE = 251940997;
		struct int_array__AttributeData
		{
			static const int_array__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* count;
			long minInclusive;
			long maxInclusive;
		};
		virtual bool begin__int_array( const int_array__AttributeData& attributeData ){return true;}
		virtual bool end__int_array(){return true;}
		virtual bool data__int_array( const void* data, size_t length ){return true;}
	private:
		bool _begin__int_array( void* attributeData ){return begin__int_array(*static_cast<int_array__AttributeData*>(attributeData));}
		bool _data__int_array( const ParserChar* text, size_t textLength );
		bool _validateBegin__int_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__int_array();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON = 181609502;
		static const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE_COMMON = 73854190;
		virtual bool begin__source__technique_common(){return true;}
		virtual bool end__source__technique_common(){return true;}
	private:
		bool _begin__source__technique_common( void* attributeData ){return begin__source__technique_common();}
		bool _data__source__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__source__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source__technique_common();

	public:
		static const StringHash HASH_ELEMENT_ACCESSOR = 161263634;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ACCESSOR = 230035506;
		static const StringHash HASH_ATTRIBUTE_OFFSET = 123525572;
		static const StringHash HASH_ATTRIBUTE_SOURCE = 128370837;
		static const StringHash HASH_ATTRIBUTE_STRIDE = 128683941;
		struct accessor__AttributeData
		{
			static const accessor__AttributeData DEFAULT;

			const ParserChar* count;
			const ParserChar* offset;
			const ParserChar* source;
			const ParserChar* stride;
		};
		virtual bool begin__accessor( const accessor__AttributeData& attributeData ){return true;}
		virtual bool end__accessor(){return true;}
	private:
		bool _begin__accessor( void* attributeData ){return begin__accessor(*static_cast<accessor__AttributeData*>(attributeData));}
		bool _data__accessor( const ParserChar* text, size_t textLength );
		bool _validateBegin__accessor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__accessor();

	public:
		static const StringHash HASH_ELEMENT_PARAM = 7768189;
		static const StringHash HASH_ELEMENT_ACCESSOR__PARAM = 246253965;
		static const StringHash HASH_ATTRIBUTE_SEMANTIC = 205020515;
		struct accessor__param__AttributeData
		{
			static const accessor__param__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* sid;
			const ParserChar* semantic;
			const ParserChar* type;
		};
		virtual bool begin__accessor__param( const accessor__param__AttributeData& attributeData ){return true;}
		virtual bool end__accessor__param(){return true;}
		virtual bool data__accessor__param( const void* data, size_t length ){return true;}
	private:
		bool _begin__accessor__param( void* attributeData ){return begin__accessor__param(*static_cast<accessor__param__AttributeData*>(attributeData));}
		bool _data__accessor__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__accessor__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__accessor__param();

	public:
		static const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE = 1838725;
		struct source__technique__AttributeData
		{
			static const source__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__source__technique( const source__technique__AttributeData& attributeData ){return true;}
		virtual bool end__source__technique(){return true;}
	private:
		bool _begin__source__technique( void* attributeData ){return begin__source__technique(*static_cast<source__technique__AttributeData*>(attributeData));}
		bool _data__source__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__source__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source__technique();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER = 159675058;
		static const StringHash HASH_ELEMENT_ANIMATION__SAMPLER = 101005858;
		struct sampler__AttributeData
		{
			static const sampler__AttributeData DEFAULT;

			const ParserChar* id;
		};
		virtual bool begin__sampler( const sampler__AttributeData& attributeData ){return true;}
		virtual bool end__sampler(){return true;}
	private:
		bool _begin__sampler( void* attributeData ){return begin__sampler(*static_cast<sampler__AttributeData*>(attributeData));}
		bool _data__sampler( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler();

	public:
		static const StringHash HASH_ELEMENT_INPUT = 7362500;
		static const StringHash HASH_ELEMENT_SAMPLER__INPUT = 219774004;
		struct sampler__input__AttributeData
		{
			static const sampler__input__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* source;
		};
		virtual bool begin__sampler__input( const sampler__input__AttributeData& attributeData ){return true;}
		virtual bool end__sampler__input(){return true;}
	private:
		bool _begin__sampler__input( void* attributeData ){return begin__sampler__input(*static_cast<sampler__input__AttributeData*>(attributeData));}
		bool _data__sampler__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler__input();

	public:
		static const StringHash HASH_ELEMENT_CHANNEL = 166221020;
		static const StringHash HASH_ELEMENT_ANIMATION__CHANNEL = 90643564;
		static const StringHash HASH_ATTRIBUTE_TARGET = 128486852;
		struct channel__AttributeData
		{
			static const channel__AttributeData DEFAULT;

			const ParserChar* source;
			const ParserChar* target;
		};
		virtual bool begin__channel( const channel__AttributeData& attributeData ){return true;}
		virtual bool end__channel(){return true;}
	private:
		bool _begin__channel( void* attributeData ){return begin__channel(*static_cast<channel__AttributeData*>(attributeData));}
		bool _data__channel( const ParserChar* text, size_t textLength );
		bool _validateBegin__channel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__channel();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION__EXTRA = 147880641;
		struct animation__extra__AttributeData
		{
			static const animation__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__animation__extra( const animation__extra__AttributeData& attributeData ){return true;}
		virtual bool end__animation__extra(){return true;}
	private:
		bool _begin__animation__extra( void* attributeData ){return begin__animation__extra(*static_cast<animation__extra__AttributeData*>(attributeData));}
		bool _data__animation__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation__extra();

	public:
		static const StringHash HASH_ELEMENT_TRIFANS = 193972259;
		static const StringHash HASH_ATTRIBUTE_MATERIAL = 145524812;
		struct trifans__AttributeData
		{
			static const trifans__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__trifans( const trifans__AttributeData& attributeData ){return true;}
		virtual bool end__trifans(){return true;}
	private:
		bool _begin__trifans( void* attributeData ){return begin__trifans(*static_cast<trifans__AttributeData*>(attributeData));}
		bool _data__trifans( const ParserChar* text, size_t textLength );
		bool _validateBegin__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans();

	public:
		static const StringHash HASH_ELEMENT_TRIFANS__INPUT = 228906372;
		static const StringHash HASH_ATTRIBUTE_SET = 31172;
		struct trifans__input__AttributeData
		{
			static const trifans__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__trifans__input( const trifans__input__AttributeData& attributeData ){return true;}
		virtual bool end__trifans__input(){return true;}
	private:
		bool _begin__trifans__input( void* attributeData ){return begin__trifans__input(*static_cast<trifans__input__AttributeData*>(attributeData));}
		bool _data__trifans__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__trifans__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans__input();

	public:
		static const StringHash HASH_ELEMENT_P = 112;
		static const StringHash HASH_ELEMENT_TRIFANS__P = 209866128;
		virtual bool begin__trifans__p(){return true;}
		virtual bool end__trifans__p(){return true;}
		virtual bool data__trifans__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__trifans__p( void* attributeData ){return begin__trifans__p();}
		bool _data__trifans__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__trifans__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans__p();

	public:
		static const StringHash HASH_ELEMENT_TRIFANS__EXTRA = 228620737;
		struct trifans__extra__AttributeData
		{
			static const trifans__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__trifans__extra( const trifans__extra__AttributeData& attributeData ){return true;}
		virtual bool end__trifans__extra(){return true;}
	private:
		bool _begin__trifans__extra( void* attributeData ){return begin__trifans__extra(*static_cast<trifans__extra__AttributeData*>(attributeData));}
		bool _data__trifans__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__trifans__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans__extra();

	public:
		struct source__AttributeData
		{
			static const source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__source( const source__AttributeData& attributeData ){return true;}
		virtual bool end__source(){return true;}
	private:
		bool _begin__source( void* attributeData ){return begin__source(*static_cast<source__AttributeData*>(attributeData));}
		bool _data__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLES = 99286435;
		struct profile_GLES__AttributeData
		{
			static const profile_GLES__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* platform;
		};
		virtual bool begin__profile_GLES( const profile_GLES__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLES(){return true;}
	private:
		bool _begin__profile_GLES( void* attributeData ){return begin__profile_GLES(*static_cast<profile_GLES__AttributeData*>(attributeData));}
		bool _data__profile_GLES( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLES( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLES__ASSET = 200766244;
		virtual bool begin__profile_GLES__asset(){return true;}
		virtual bool end__profile_GLES__asset(){return true;}
	private:
		bool _begin__profile_GLES__asset( void* attributeData ){return begin__profile_GLES__asset();}
		bool _data__profile_GLES__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLES__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__asset();

	public:
		static const StringHash HASH_ELEMENT_IMAGE = 7354325;
		static const StringHash HASH_ELEMENT_PROFILE_GLES__IMAGE = 200404277;
		static const StringHash HASH_ATTRIBUTE_FORMAT = 114725764;
		static const StringHash HASH_ATTRIBUTE_HEIGHT = 116129268;
		static const StringHash HASH_ATTRIBUTE_WIDTH = 8256424;
		static const StringHash HASH_ATTRIBUTE_DEPTH = 6997928;
		struct profile_GLES__image__AttributeData
		{
			static const profile_GLES__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__profile_GLES__image( const profile_GLES__image__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLES__image(){return true;}
	private:
		bool _begin__profile_GLES__image( void* attributeData ){return begin__profile_GLES__image(*static_cast<profile_GLES__image__AttributeData*>(attributeData));}
		bool _data__profile_GLES__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLES__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__image();

	public:
		static const StringHash HASH_ELEMENT_IMAGE__ASSET = 73127028;
		virtual bool begin__image__asset(){return true;}
		virtual bool end__image__asset(){return true;}
	private:
		bool _begin__image__asset( void* attributeData ){return begin__image__asset();}
		bool _data__image__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__image__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image__asset();

	public:
		static const StringHash HASH_ELEMENT_DATA = 436385;
		static const StringHash HASH_ELEMENT_IMAGE__DATA = 189112177;
		virtual bool begin__data(){return true;}
		virtual bool end__data(){return true;}
		virtual bool data__data( const void* data, size_t length ){return true;}
	private:
		bool _begin__data( void* attributeData ){return begin__data();}
		bool _data__data( const ParserChar* text, size_t textLength );
		bool _validateBegin__data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__data();

	public:
		static const StringHash HASH_ELEMENT_IMAGE__INIT_FROM = 221349405;
		virtual bool begin__image__init_from(){return true;}
		virtual bool end__image__init_from(){return true;}
		virtual bool data__image__init_from( const void* data, size_t length ){return true;}
	private:
		bool _begin__image__init_from( void* attributeData ){return begin__image__init_from();}
		bool _data__image__init_from( const ParserChar* text, size_t textLength );
		bool _validateBegin__image__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image__init_from();

	public:
		static const StringHash HASH_ELEMENT_IMAGE__EXTRA = 73369137;
		struct image__extra__AttributeData
		{
			static const image__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__image__extra( const image__extra__AttributeData& attributeData ){return true;}
		virtual bool end__image__extra(){return true;}
	private:
		bool _begin__image__extra( void* attributeData ){return begin__image__extra(*static_cast<image__extra__AttributeData*>(attributeData));}
		bool _data__image__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__image__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image__extra();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM = 216436541;
		static const StringHash HASH_ELEMENT_PROFILE_GLES__NEWPARAM = 21514445;
		struct profile_GLES__newparam__AttributeData
		{
			static const profile_GLES__newparam__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__profile_GLES__newparam( const profile_GLES__newparam__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLES__newparam(){return true;}
	private:
		bool _begin__profile_GLES__newparam( void* attributeData ){return begin__profile_GLES__newparam(*static_cast<profile_GLES__newparam__AttributeData*>(attributeData));}
		bool _data__profile_GLES__newparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLES__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__newparam();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE = 89566757;
		static const StringHash HASH_ELEMENT_NEWPARAM__ANNOTATE = 202972325;
		struct newparam__annotate__AttributeData
		{
			static const newparam__annotate__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__newparam__annotate( const newparam__annotate__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__annotate(){return true;}
	private:
		bool _begin__newparam__annotate( void* attributeData ){return begin__newparam__annotate(*static_cast<newparam__annotate__AttributeData*>(attributeData));}
		bool _data__newparam__annotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__annotate();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__BOOL = 2309228;
		virtual bool begin__annotate__bool(){return true;}
		virtual bool end__annotate__bool(){return true;}
		virtual bool data__annotate__bool( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__bool( void* attributeData ){return begin__annotate__bool();}
		bool _data__annotate__bool( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__BOOL2 = 36947698;
		virtual bool begin__annotate__bool2(){return true;}
		virtual bool end__annotate__bool2(){return true;}
		virtual bool data__annotate__bool2( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__bool2( void* attributeData ){return begin__annotate__bool2();}
		bool _data__annotate__bool2( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool2();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__BOOL3 = 36947699;
		virtual bool begin__annotate__bool3(){return true;}
		virtual bool end__annotate__bool3(){return true;}
		virtual bool data__annotate__bool3( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__bool3( void* attributeData ){return begin__annotate__bool3();}
		bool _data__annotate__bool3( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool3();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__BOOL4 = 36947700;
		virtual bool begin__annotate__bool4(){return true;}
		virtual bool end__annotate__bool4(){return true;}
		virtual bool data__annotate__bool4( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__bool4( void* attributeData ){return begin__annotate__bool4();}
		bool _data__annotate__bool4( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool4();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__INT = 50476724;
		virtual bool begin__annotate__int(){return true;}
		virtual bool end__annotate__int(){return true;}
		virtual bool data__annotate__int( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__int( void* attributeData ){return begin__annotate__int();}
		bool _data__annotate__int( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__INT2 = 2321218;
		virtual bool begin__annotate__int2(){return true;}
		virtual bool end__annotate__int2(){return true;}
		virtual bool data__annotate__int2( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__int2( void* attributeData ){return begin__annotate__int2();}
		bool _data__annotate__int2( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int2();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__INT3 = 2321219;
		virtual bool begin__annotate__int3(){return true;}
		virtual bool end__annotate__int3(){return true;}
		virtual bool data__annotate__int3( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__int3( void* attributeData ){return begin__annotate__int3();}
		bool _data__annotate__int3( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int3();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__INT4 = 2321220;
		virtual bool begin__annotate__int4(){return true;}
		virtual bool end__annotate__int4(){return true;}
		virtual bool data__annotate__int4( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__int4( void* attributeData ){return begin__annotate__int4();}
		bool _data__annotate__int4( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int4();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT = 37213828;
		virtual bool begin__annotate__float(){return true;}
		virtual bool end__annotate__float(){return true;}
		virtual bool data__annotate__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float( void* attributeData ){return begin__annotate__float();}
		bool _data__annotate__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2 = 58550354;
		virtual bool begin__annotate__float2(){return true;}
		virtual bool end__annotate__float2(){return true;}
		virtual bool data__annotate__float2( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float2( void* attributeData ){return begin__annotate__float2();}
		bool _data__annotate__float2( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float2();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3 = 58550355;
		virtual bool begin__annotate__float3(){return true;}
		virtual bool end__annotate__float3(){return true;}
		virtual bool data__annotate__float3( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float3( void* attributeData ){return begin__annotate__float3();}
		bool _data__annotate__float3( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float3();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4 = 58550356;
		virtual bool begin__annotate__float4(){return true;}
		virtual bool end__annotate__float4(){return true;}
		virtual bool data__annotate__float4( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float4( void* attributeData ){return begin__annotate__float4();}
		bool _data__annotate__float4( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float4();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2X2 = 224942786;
		virtual bool begin__annotate__float2x2(){return true;}
		virtual bool end__annotate__float2x2(){return true;}
		virtual bool data__annotate__float2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float2x2( void* attributeData ){return begin__annotate__float2x2();}
		bool _data__annotate__float2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float2x2();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3X3 = 224942531;
		virtual bool begin__annotate__float3x3(){return true;}
		virtual bool end__annotate__float3x3(){return true;}
		virtual bool data__annotate__float3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float3x3( void* attributeData ){return begin__annotate__float3x3();}
		bool _data__annotate__float3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float3x3();

	public:
		static const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4X4 = 224942276;
		virtual bool begin__annotate__float4x4(){return true;}
		virtual bool end__annotate__float4x4(){return true;}
		virtual bool data__annotate__float4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__float4x4( void* attributeData ){return begin__annotate__float4x4();}
		bool _data__annotate__float4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float4x4();

	public:
		static const StringHash HASH_ELEMENT_STRING = 128684103;
		static const StringHash HASH_ELEMENT_ANNOTATE__STRING = 376935;
		virtual bool begin__annotate__string(){return true;}
		virtual bool end__annotate__string(){return true;}
		virtual bool data__annotate__string( const void* data, size_t length ){return true;}
	private:
		bool _begin__annotate__string( void* attributeData ){return begin__annotate__string();}
		bool _data__annotate__string( const ParserChar* text, size_t textLength );
		bool _validateBegin__annotate__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__string();

	public:
		static const StringHash HASH_ELEMENT_SEMANTIC = 205020515;
		static const StringHash HASH_ELEMENT_NEWPARAM__SEMANTIC = 91876067;
		virtual bool begin__semantic(){return true;}
		virtual bool end__semantic(){return true;}
		virtual bool data__semantic( const void* data, size_t length ){return true;}
	private:
		bool _begin__semantic( void* attributeData ){return begin__semantic();}
		bool _data__semantic( const ParserChar* text, size_t textLength );
		bool _validateBegin__semantic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__semantic();

	public:
		static const StringHash HASH_ELEMENT_MODIFIER = 95406210;
		static const StringHash HASH_ELEMENT_NEWPARAM__MODIFIER = 182483714;
		virtual bool begin__modifier(){return true;}
		virtual bool end__modifier(){return true;}
		virtual bool data__modifier( const void* data, size_t length ){return true;}
	private:
		bool _begin__modifier( void* attributeData ){return begin__modifier();}
		bool _data__modifier( const ParserChar* text, size_t textLength );
		bool _validateBegin__modifier( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__modifier();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL = 263396124;
		virtual bool begin__newparam__bool(){return true;}
		virtual bool end__newparam__bool(){return true;}
		virtual bool data__newparam__bool( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool( void* attributeData ){return begin__newparam__bool();}
		bool _data__newparam__bool( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL2 = 187805954;
		virtual bool begin__newparam__bool2(){return true;}
		virtual bool end__newparam__bool2(){return true;}
		virtual bool data__newparam__bool2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool2( void* attributeData ){return begin__newparam__bool2();}
		bool _data__newparam__bool2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL3 = 187805955;
		virtual bool begin__newparam__bool3(){return true;}
		virtual bool end__newparam__bool3(){return true;}
		virtual bool data__newparam__bool3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool3( void* attributeData ){return begin__newparam__bool3();}
		bool _data__newparam__bool3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL4 = 187805956;
		virtual bool begin__newparam__bool4(){return true;}
		virtual bool end__newparam__bool4(){return true;}
		virtual bool data__newparam__bool4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool4( void* attributeData ){return begin__newparam__bool4();}
		bool _data__newparam__bool4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__INT = 83572900;
		virtual bool begin__newparam__int(){return true;}
		virtual bool end__newparam__int(){return true;}
		virtual bool data__newparam__int( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int( void* attributeData ){return begin__newparam__int();}
		bool _data__newparam__int( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__INT2 = 263424562;
		virtual bool begin__newparam__int2(){return true;}
		virtual bool end__newparam__int2(){return true;}
		virtual bool data__newparam__int2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int2( void* attributeData ){return begin__newparam__int2();}
		bool _data__newparam__int2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__INT3 = 263424563;
		virtual bool begin__newparam__int3(){return true;}
		virtual bool end__newparam__int3(){return true;}
		virtual bool data__newparam__int3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int3( void* attributeData ){return begin__newparam__int3();}
		bool _data__newparam__int3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__INT4 = 263424564;
		virtual bool begin__newparam__int4(){return true;}
		virtual bool end__newparam__int4(){return true;}
		virtual bool data__newparam__int4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int4( void* attributeData ){return begin__newparam__int4();}
		bool _data__newparam__int4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT = 188080500;
		virtual bool begin__newparam__float(){return true;}
		virtual bool end__newparam__float(){return true;}
		virtual bool data__newparam__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float( void* attributeData ){return begin__newparam__float();}
		bool _data__newparam__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2 = 56498114;
		virtual bool begin__newparam__float2(){return true;}
		virtual bool end__newparam__float2(){return true;}
		virtual bool data__newparam__float2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float2( void* attributeData ){return begin__newparam__float2();}
		bool _data__newparam__float2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3 = 56498115;
		virtual bool begin__newparam__float3(){return true;}
		virtual bool end__newparam__float3(){return true;}
		virtual bool data__newparam__float3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float3( void* attributeData ){return begin__newparam__float3();}
		bool _data__newparam__float3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4 = 56498116;
		virtual bool begin__newparam__float4(){return true;}
		virtual bool end__newparam__float4(){return true;}
		virtual bool data__newparam__float4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float4( void* attributeData ){return begin__newparam__float4();}
		bool _data__newparam__float4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X1 = 236440545;
		virtual bool begin__newparam__float1x1(){return true;}
		virtual bool end__newparam__float1x1(){return true;}
		virtual bool data__newparam__float1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float1x1( void* attributeData ){return begin__newparam__float1x1();}
		bool _data__newparam__float1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x1();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X2 = 236440546;
		virtual bool begin__newparam__float1x2(){return true;}
		virtual bool end__newparam__float1x2(){return true;}
		virtual bool data__newparam__float1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float1x2( void* attributeData ){return begin__newparam__float1x2();}
		bool _data__newparam__float1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X3 = 236440547;
		virtual bool begin__newparam__float1x3(){return true;}
		virtual bool end__newparam__float1x3(){return true;}
		virtual bool data__newparam__float1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float1x3( void* attributeData ){return begin__newparam__float1x3();}
		bool _data__newparam__float1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X4 = 236440548;
		virtual bool begin__newparam__float1x4(){return true;}
		virtual bool end__newparam__float1x4(){return true;}
		virtual bool data__newparam__float1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float1x4( void* attributeData ){return begin__newparam__float1x4();}
		bool _data__newparam__float1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X1 = 236440289;
		virtual bool begin__newparam__float2x1(){return true;}
		virtual bool end__newparam__float2x1(){return true;}
		virtual bool data__newparam__float2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float2x1( void* attributeData ){return begin__newparam__float2x1();}
		bool _data__newparam__float2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x1();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X2 = 236440290;
		virtual bool begin__newparam__float2x2(){return true;}
		virtual bool end__newparam__float2x2(){return true;}
		virtual bool data__newparam__float2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float2x2( void* attributeData ){return begin__newparam__float2x2();}
		bool _data__newparam__float2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X3 = 236440291;
		virtual bool begin__newparam__float2x3(){return true;}
		virtual bool end__newparam__float2x3(){return true;}
		virtual bool data__newparam__float2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float2x3( void* attributeData ){return begin__newparam__float2x3();}
		bool _data__newparam__float2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X4 = 236440292;
		virtual bool begin__newparam__float2x4(){return true;}
		virtual bool end__newparam__float2x4(){return true;}
		virtual bool data__newparam__float2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float2x4( void* attributeData ){return begin__newparam__float2x4();}
		bool _data__newparam__float2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X1 = 236440033;
		virtual bool begin__newparam__float3x1(){return true;}
		virtual bool end__newparam__float3x1(){return true;}
		virtual bool data__newparam__float3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float3x1( void* attributeData ){return begin__newparam__float3x1();}
		bool _data__newparam__float3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x1();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X2 = 236440034;
		virtual bool begin__newparam__float3x2(){return true;}
		virtual bool end__newparam__float3x2(){return true;}
		virtual bool data__newparam__float3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float3x2( void* attributeData ){return begin__newparam__float3x2();}
		bool _data__newparam__float3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X3 = 236440035;
		virtual bool begin__newparam__float3x3(){return true;}
		virtual bool end__newparam__float3x3(){return true;}
		virtual bool data__newparam__float3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float3x3( void* attributeData ){return begin__newparam__float3x3();}
		bool _data__newparam__float3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X4 = 236440036;
		virtual bool begin__newparam__float3x4(){return true;}
		virtual bool end__newparam__float3x4(){return true;}
		virtual bool data__newparam__float3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float3x4( void* attributeData ){return begin__newparam__float3x4();}
		bool _data__newparam__float3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X1 = 236439777;
		virtual bool begin__newparam__float4x1(){return true;}
		virtual bool end__newparam__float4x1(){return true;}
		virtual bool data__newparam__float4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float4x1( void* attributeData ){return begin__newparam__float4x1();}
		bool _data__newparam__float4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x1();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X2 = 236439778;
		virtual bool begin__newparam__float4x2(){return true;}
		virtual bool end__newparam__float4x2(){return true;}
		virtual bool data__newparam__float4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float4x2( void* attributeData ){return begin__newparam__float4x2();}
		bool _data__newparam__float4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x2();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X3 = 236439779;
		virtual bool begin__newparam__float4x3(){return true;}
		virtual bool end__newparam__float4x3(){return true;}
		virtual bool data__newparam__float4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float4x3( void* attributeData ){return begin__newparam__float4x3();}
		bool _data__newparam__float4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x3();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X4 = 236439780;
		virtual bool begin__newparam__float4x4(){return true;}
		virtual bool end__newparam__float4x4(){return true;}
		virtual bool data__newparam__float4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float4x4( void* attributeData ){return begin__newparam__float4x4();}
		bool _data__newparam__float4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SURFACE = 37502101;
		struct newparam__surface__AttributeData
		{
			static const newparam__surface__AttributeData DEFAULT;

			const ParserChar* type;
		};
		virtual bool begin__newparam__surface( const newparam__surface__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__surface(){return true;}
	private:
		bool _begin__newparam__surface( void* attributeData ){return begin__newparam__surface(*static_cast<newparam__surface__AttributeData*>(attributeData));}
		bool _data__newparam__surface( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__surface();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_PIPELINE = 195376869;
		static const StringHash HASH_ELEMENT_NEWPARAM__TEXTURE_PIPELINE = 68467621;
		struct newparam__texture_pipeline__AttributeData
		{
			static const newparam__texture_pipeline__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__newparam__texture_pipeline( const newparam__texture_pipeline__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__texture_pipeline(){return true;}
	private:
		bool _begin__newparam__texture_pipeline( void* attributeData ){return begin__newparam__texture_pipeline(*static_cast<newparam__texture_pipeline__AttributeData*>(attributeData));}
		bool _data__newparam__texture_pipeline( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__texture_pipeline();

	public:
		static const StringHash HASH_ELEMENT_TEXCOMBINER = 105007714;
		static const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__TEXCOMBINER = 184640514;
		virtual bool begin__texture_pipeline__texcombiner(){return true;}
		virtual bool end__texture_pipeline__texcombiner(){return true;}
	private:
		bool _begin__texture_pipeline__texcombiner( void* attributeData ){return begin__texture_pipeline__texcombiner();}
		bool _data__texture_pipeline__texcombiner( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_pipeline__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__texcombiner();

	public:
		static const StringHash HASH_ELEMENT_CONSTANT = 106603252;
		static const StringHash HASH_ELEMENT_TEXCOMBINER__CONSTANT = 3715492;
		static const StringHash HASH_ATTRIBUTE_VALUE = 8160181;
		static const StringHash HASH_ATTRIBUTE_PARAM = 7768189;
		struct texcombiner__constant__AttributeData
		{
			static const texcombiner__constant__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__texcombiner__constant( const texcombiner__constant__AttributeData& attributeData ){return true;}
		virtual bool end__texcombiner__constant(){return true;}
	private:
		bool _begin__texcombiner__constant( void* attributeData ){return begin__texcombiner__constant(*static_cast<texcombiner__constant__AttributeData*>(attributeData));}
		bool _data__texcombiner__constant( const ParserChar* text, size_t textLength );
		bool _validateBegin__texcombiner__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texcombiner__constant();

	public:
		static const StringHash HASH_ELEMENT_RGB = 22194;
		static const StringHash HASH_ELEMENT_TEXCOMBINER__RGB = 102851090;
		static const StringHash HASH_ATTRIBUTE__OPERATOR = 113831170;
		static const StringHash HASH_ATTRIBUTE_SCALE = 7968805;
		struct RGB__AttributeData
		{
			static const RGB__AttributeData DEFAULT;

			const ParserChar* _operator;
			float scale;
		};
		virtual bool begin__RGB( const RGB__AttributeData& attributeData ){return true;}
		virtual bool end__RGB(){return true;}
	private:
		bool _begin__RGB( void* attributeData ){return begin__RGB(*static_cast<RGB__AttributeData*>(attributeData));}
		bool _data__RGB( const ParserChar* text, size_t textLength );
		bool _validateBegin__RGB( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__RGB();

	public:
		static const StringHash HASH_ELEMENT_ARGUMENT = 149700308;
		static const StringHash HASH_ELEMENT_RGB__ARGUMENT = 240414596;
		static const StringHash HASH_ATTRIBUTE_OPERAND = 107776052;
		static const StringHash HASH_ATTRIBUTE_UNIT = 509188;
		struct RGB__argument__AttributeData
		{
			static const RGB__argument__AttributeData DEFAULT;

			const ParserChar* source;
			const ParserChar* operand;
			const ParserChar* unit;
		};
		virtual bool begin__RGB__argument( const RGB__argument__AttributeData& attributeData ){return true;}
		virtual bool end__RGB__argument(){return true;}
	private:
		bool _begin__RGB__argument( void* attributeData ){return begin__RGB__argument(*static_cast<RGB__argument__AttributeData*>(attributeData));}
		bool _data__RGB__argument( const ParserChar* text, size_t textLength );
		bool _validateBegin__RGB__argument( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__RGB__argument();

	public:
		static const StringHash HASH_ELEMENT_ALPHA = 6829793;
		static const StringHash HASH_ELEMENT_TEXCOMBINER__ALPHA = 24416449;
		struct texcombiner__alpha__AttributeData
		{
			static const texcombiner__alpha__AttributeData DEFAULT;

			const ParserChar* _operator;
			float scale;
		};
		virtual bool begin__texcombiner__alpha( const texcombiner__alpha__AttributeData& attributeData ){return true;}
		virtual bool end__texcombiner__alpha(){return true;}
	private:
		bool _begin__texcombiner__alpha( void* attributeData ){return begin__texcombiner__alpha(*static_cast<texcombiner__alpha__AttributeData*>(attributeData));}
		bool _data__texcombiner__alpha( const ParserChar* text, size_t textLength );
		bool _validateBegin__texcombiner__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texcombiner__alpha();

	public:
		static const StringHash HASH_ELEMENT_ALPHA__ARGUMENT = 235735012;
		struct alpha__argument__AttributeData
		{
			static const alpha__argument__AttributeData DEFAULT;

			const ParserChar* source;
			const ParserChar* operand;
			const ParserChar* unit;
		};
		virtual bool begin__alpha__argument( const alpha__argument__AttributeData& attributeData ){return true;}
		virtual bool end__alpha__argument(){return true;}
	private:
		bool _begin__alpha__argument( void* attributeData ){return begin__alpha__argument(*static_cast<alpha__argument__AttributeData*>(attributeData));}
		bool _data__alpha__argument( const ParserChar* text, size_t textLength );
		bool _validateBegin__alpha__argument( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha__argument();

	public:
		static const StringHash HASH_ELEMENT_TEXENV = 128773206;
		static const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__TEXENV = 60426918;
		struct texture_pipeline__texenv__AttributeData
		{
			static const texture_pipeline__texenv__AttributeData DEFAULT;

			const ParserChar* _operator;
			const ParserChar* unit;
		};
		virtual bool begin__texture_pipeline__texenv( const texture_pipeline__texenv__AttributeData& attributeData ){return true;}
		virtual bool end__texture_pipeline__texenv(){return true;}
	private:
		bool _begin__texture_pipeline__texenv( void* attributeData ){return begin__texture_pipeline__texenv(*static_cast<texture_pipeline__texenv__AttributeData*>(attributeData));}
		bool _data__texture_pipeline__texenv( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_pipeline__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__texenv();

	public:
		static const StringHash HASH_ELEMENT_TEXENV__CONSTANT = 168255444;
		struct texenv__constant__AttributeData
		{
			static const texenv__constant__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__texenv__constant( const texenv__constant__AttributeData& attributeData ){return true;}
		virtual bool end__texenv__constant(){return true;}
	private:
		bool _begin__texenv__constant( void* attributeData ){return begin__texenv__constant(*static_cast<texenv__constant__AttributeData*>(attributeData));}
		bool _data__texenv__constant( const ParserChar* text, size_t textLength );
		bool _validateBegin__texenv__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texenv__constant();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__EXTRA = 252679585;
		struct texture_pipeline__extra__AttributeData
		{
			static const texture_pipeline__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__texture_pipeline__extra( const texture_pipeline__extra__AttributeData& attributeData ){return true;}
		virtual bool end__texture_pipeline__extra(){return true;}
	private:
		bool _begin__texture_pipeline__extra( void* attributeData ){return begin__texture_pipeline__extra(*static_cast<texture_pipeline__extra__AttributeData*>(attributeData));}
		bool _data__texture_pipeline__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_pipeline__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__extra();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE = 267311637;
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER_STATE = 133824869;
		struct newparam__sampler_state__AttributeData
		{
			static const newparam__sampler_state__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__newparam__sampler_state( const newparam__sampler_state__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__sampler_state(){return true;}
	private:
		bool _begin__newparam__sampler_state( void* attributeData ){return begin__newparam__sampler_state(*static_cast<newparam__sampler_state__AttributeData*>(attributeData));}
		bool _data__newparam__sampler_state( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler_state();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__WRAP_S = 137532627;
		virtual bool begin__sampler_state__wrap_s(){return true;}
		virtual bool end__sampler_state__wrap_s(){return true;}
		virtual bool data__sampler_state__wrap_s( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__wrap_s( void* attributeData ){return begin__sampler_state__wrap_s();}
		bool _data__sampler_state__wrap_s( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__wrap_s();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__WRAP_T = 137532628;
		virtual bool begin__sampler_state__wrap_t(){return true;}
		virtual bool end__sampler_state__wrap_t(){return true;}
		virtual bool data__sampler_state__wrap_t( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__wrap_t( void* attributeData ){return begin__sampler_state__wrap_t();}
		bool _data__sampler_state__wrap_t( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__wrap_t();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__MINFILTER = 94762146;
		virtual bool begin__sampler_state__minfilter(){return true;}
		virtual bool end__sampler_state__minfilter(){return true;}
		virtual bool data__sampler_state__minfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__minfilter( void* attributeData ){return begin__sampler_state__minfilter();}
		bool _data__sampler_state__minfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__minfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__MAGFILTER = 212202514;
		virtual bool begin__sampler_state__magfilter(){return true;}
		virtual bool end__sampler_state__magfilter(){return true;}
		virtual bool data__sampler_state__magfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__magfilter( void* attributeData ){return begin__sampler_state__magfilter();}
		bool _data__sampler_state__magfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__magfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__MIPFILTER = 128316770;
		virtual bool begin__sampler_state__mipfilter(){return true;}
		virtual bool end__sampler_state__mipfilter(){return true;}
		virtual bool data__sampler_state__mipfilter( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__mipfilter( void* attributeData ){return begin__sampler_state__mipfilter();}
		bool _data__sampler_state__mipfilter( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__mipfilter();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__MIPMAP_MAXLEVEL = 12674860;
		virtual bool begin__sampler_state__mipmap_maxlevel(){return true;}
		virtual bool end__sampler_state__mipmap_maxlevel(){return true;}
		virtual bool data__sampler_state__mipmap_maxlevel( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__mipmap_maxlevel( void* attributeData ){return begin__sampler_state__mipmap_maxlevel();}
		bool _data__sampler_state__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__mipmap_maxlevel();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__MIPMAP_BIAS = 61482963;
		virtual bool begin__sampler_state__mipmap_bias(){return true;}
		virtual bool end__sampler_state__mipmap_bias(){return true;}
		virtual bool data__sampler_state__mipmap_bias( const void* data, size_t length ){return true;}
	private:
		bool _begin__sampler_state__mipmap_bias( void* attributeData ){return begin__sampler_state__mipmap_bias();}
		bool _data__sampler_state__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__mipmap_bias();

	public:
		static const StringHash HASH_ELEMENT_SAMPLER_STATE__EXTRA = 196172513;
		struct sampler_state__extra__AttributeData
		{
			static const sampler_state__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__sampler_state__extra( const sampler_state__extra__AttributeData& attributeData ){return true;}
		virtual bool end__sampler_state__extra(){return true;}
	private:
		bool _begin__sampler_state__extra( void* attributeData ){return begin__sampler_state__extra(*static_cast<sampler_state__extra__AttributeData*>(attributeData));}
		bool _data__sampler_state__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__sampler_state__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__extra();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_UNIT = 253386948;
		static const StringHash HASH_ELEMENT_NEWPARAM__TEXTURE_UNIT = 143987060;
		struct newparam__texture_unit__AttributeData
		{
			static const newparam__texture_unit__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__newparam__texture_unit( const newparam__texture_unit__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__texture_unit(){return true;}
	private:
		bool _begin__newparam__texture_unit( void* attributeData ){return begin__newparam__texture_unit(*static_cast<newparam__texture_unit__AttributeData*>(attributeData));}
		bool _data__newparam__texture_unit( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__texture_unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__texture_unit();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_UNIT__SURFACE = 214217045;
		virtual bool begin__texture_unit__surface(){return true;}
		virtual bool end__texture_unit__surface(){return true;}
		virtual bool data__texture_unit__surface( const void* data, size_t length ){return true;}
	private:
		bool _begin__texture_unit__surface( void* attributeData ){return begin__texture_unit__surface();}
		bool _data__texture_unit__surface( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_unit__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_unit__surface();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_UNIT__SAMPLER_STATE = 165842085;
		virtual bool begin__texture_unit__sampler_state(){return true;}
		virtual bool end__texture_unit__sampler_state(){return true;}
		virtual bool data__texture_unit__sampler_state( const void* data, size_t length ){return true;}
	private:
		bool _begin__texture_unit__sampler_state( void* attributeData ){return begin__texture_unit__sampler_state();}
		bool _data__texture_unit__sampler_state( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_unit__sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_unit__sampler_state();

	public:
		static const StringHash HASH_ELEMENT_TEXCOORD = 216686884;
		static const StringHash HASH_ELEMENT_TEXTURE_UNIT__TEXCOORD = 204425796;
		struct texcoord__AttributeData
		{
			static const texcoord__AttributeData DEFAULT;

			const ParserChar* semantic;
		};
		virtual bool begin__texcoord( const texcoord__AttributeData& attributeData ){return true;}
		virtual bool end__texcoord(){return true;}
	private:
		bool _begin__texcoord( void* attributeData ){return begin__texcoord(*static_cast<texcoord__AttributeData*>(attributeData));}
		bool _data__texcoord( const ParserChar* text, size_t textLength );
		bool _validateBegin__texcoord( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texcoord();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_UNIT__EXTRA = 117110769;
		struct texture_unit__extra__AttributeData
		{
			static const texture_unit__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__texture_unit__extra( const texture_unit__extra__AttributeData& attributeData ){return true;}
		virtual bool end__texture_unit__extra(){return true;}
	private:
		bool _begin__texture_unit__extra( void* attributeData ){return begin__texture_unit__extra(*static_cast<texture_unit__extra__AttributeData*>(attributeData));}
		bool _data__texture_unit__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_unit__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_unit__extra();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__ENUM = 263408381;
		virtual bool begin__newparam__enum(){return true;}
		virtual bool end__newparam__enum(){return true;}
		virtual bool data__newparam__enum( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__enum( void* attributeData ){return begin__newparam__enum();}
		bool _data__newparam__enum( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__enum();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE = 52481493;
		struct profile_GLES__technique__AttributeData
		{
			static const profile_GLES__technique__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* sid;
		};
		virtual bool begin__profile_GLES__technique( const profile_GLES__technique__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLES__technique(){return true;}
	private:
		bool _begin__profile_GLES__technique( void* attributeData ){return begin__profile_GLES__technique(*static_cast<profile_GLES__technique__AttributeData*>(attributeData));}
		bool _data__profile_GLES__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLES__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__technique();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__ASSET = 202344836;
		virtual bool begin__technique__asset(){return true;}
		virtual bool end__technique__asset(){return true;}
	private:
		bool _begin__technique__asset( void* attributeData ){return begin__technique__asset();}
		bool _data__technique__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__asset();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__ANNOTATE = 122841269;
		struct technique__annotate__AttributeData
		{
			static const technique__annotate__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__technique__annotate( const technique__annotate__AttributeData& attributeData ){return true;}
		virtual bool end__technique__annotate(){return true;}
	private:
		bool _begin__technique__annotate( void* attributeData ){return begin__technique__annotate(*static_cast<technique__annotate__AttributeData*>(attributeData));}
		bool _data__technique__annotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__annotate();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__IMAGE = 201922453;
		struct technique__image__AttributeData
		{
			static const technique__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__technique__image( const technique__image__AttributeData& attributeData ){return true;}
		virtual bool end__technique__image(){return true;}
	private:
		bool _begin__technique__image( void* attributeData ){return begin__technique__image(*static_cast<technique__image__AttributeData*>(attributeData));}
		bool _data__technique__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__image();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__NEWPARAM = 249710925;
		struct technique__newparam__AttributeData
		{
			static const technique__newparam__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__technique__newparam( const technique__newparam__AttributeData& attributeData ){return true;}
		virtual bool end__technique__newparam(){return true;}
	private:
		bool _begin__technique__newparam( void* attributeData ){return begin__technique__newparam(*static_cast<technique__newparam__AttributeData*>(attributeData));}
		bool _data__technique__newparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__newparam();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__SETPARAM = 246565789;
		struct technique__setparam__AttributeData
		{
			static const technique__setparam__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__technique__setparam( const technique__setparam__AttributeData& attributeData ){return true;}
		virtual bool end__technique__setparam(){return true;}
	private:
		bool _begin__technique__setparam( void* attributeData ){return begin__technique__setparam(*static_cast<technique__setparam__AttributeData*>(attributeData));}
		bool _data__technique__setparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__setparam();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__ANNOTATE = 89566037;
		struct setparam__annotate__AttributeData
		{
			static const setparam__annotate__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__setparam__annotate( const setparam__annotate__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__annotate(){return true;}
	private:
		bool _begin__setparam__annotate( void* attributeData ){return begin__setparam__annotate(*static_cast<setparam__annotate__AttributeData*>(attributeData));}
		bool _data__setparam__annotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__annotate();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__TEXTURE_PIPELINE = 195331813;
		struct setparam__texture_pipeline__AttributeData
		{
			static const setparam__texture_pipeline__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__setparam__texture_pipeline( const setparam__texture_pipeline__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__texture_pipeline(){return true;}
	private:
		bool _begin__setparam__texture_pipeline( void* attributeData ){return begin__setparam__texture_pipeline(*static_cast<setparam__texture_pipeline__AttributeData*>(attributeData));}
		bool _data__setparam__texture_pipeline( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__texture_pipeline();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__SAMPLER_STATE = 149871205;
		struct setparam__sampler_state__AttributeData
		{
			static const setparam__sampler_state__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__setparam__sampler_state( const setparam__sampler_state__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__sampler_state(){return true;}
	private:
		bool _begin__setparam__sampler_state( void* attributeData ){return begin__setparam__sampler_state(*static_cast<setparam__sampler_state__AttributeData*>(attributeData));}
		bool _data__setparam__sampler_state( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler_state();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__TEXTURE_UNIT = 145383620;
		struct setparam__texture_unit__AttributeData
		{
			static const setparam__texture_unit__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__setparam__texture_unit( const setparam__texture_unit__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__texture_unit(){return true;}
	private:
		bool _begin__setparam__texture_unit( void* attributeData ){return begin__setparam__texture_unit(*static_cast<setparam__texture_unit__AttributeData*>(attributeData));}
		bool _data__setparam__texture_unit( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__texture_unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__texture_unit();

	public:
		static const StringHash HASH_ELEMENT_PASS = 485539;
		static const StringHash HASH_ELEMENT_TECHNIQUE__PASS = 79895203;
		struct pass__AttributeData
		{
			static const pass__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__pass( const pass__AttributeData& attributeData ){return true;}
		virtual bool end__pass(){return true;}
	private:
		bool _begin__pass( void* attributeData ){return begin__pass(*static_cast<pass__AttributeData*>(attributeData));}
		bool _data__pass( const ParserChar* text, size_t textLength );
		bool _validateBegin__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass();

	public:
		static const StringHash HASH_ELEMENT_PASS__ANNOTATE = 234879621;
		struct pass__annotate__AttributeData
		{
			static const pass__annotate__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__pass__annotate( const pass__annotate__AttributeData& attributeData ){return true;}
		virtual bool end__pass__annotate(){return true;}
	private:
		bool _begin__pass__annotate( void* attributeData ){return begin__pass__annotate(*static_cast<pass__annotate__AttributeData*>(attributeData));}
		bool _data__pass__annotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__pass__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass__annotate();

	public:
		static const StringHash HASH_ELEMENT_COLOR_TARGET = 965444;
		static const StringHash HASH_ELEMENT_PASS__COLOR_TARGET = 94769908;
		virtual bool begin__color_target(){return true;}
		virtual bool end__color_target(){return true;}
		virtual bool data__color_target( const void* data, size_t length ){return true;}
	private:
		bool _begin__color_target( void* attributeData ){return begin__color_target();}
		bool _data__color_target( const ParserChar* text, size_t textLength );
		bool _validateBegin__color_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_target();

	public:
		static const StringHash HASH_ELEMENT_DEPTH_TARGET = 325412;
		static const StringHash HASH_ELEMENT_PASS__DEPTH_TARGET = 74210900;
		virtual bool begin__depth_target(){return true;}
		virtual bool end__depth_target(){return true;}
		virtual bool data__depth_target( const void* data, size_t length ){return true;}
	private:
		bool _begin__depth_target( void* attributeData ){return begin__depth_target();}
		bool _data__depth_target( const ParserChar* text, size_t textLength );
		bool _validateBegin__depth_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_target();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_TARGET = 208409604;
		static const StringHash HASH_ELEMENT_PASS__STENCIL_TARGET = 75842084;
		virtual bool begin__stencil_target(){return true;}
		virtual bool end__stencil_target(){return true;}
		virtual bool data__stencil_target( const void* data, size_t length ){return true;}
	private:
		bool _begin__stencil_target( void* attributeData ){return begin__stencil_target();}
		bool _data__stencil_target( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_target();

	public:
		static const StringHash HASH_ELEMENT_COLOR_CLEAR = 137644258;
		static const StringHash HASH_ELEMENT_PASS__COLOR_CLEAR = 57328242;
		virtual bool begin__color_clear(){return true;}
		virtual bool end__color_clear(){return true;}
		virtual bool data__color_clear( const void* data, size_t length ){return true;}
	private:
		bool _begin__color_clear( void* attributeData ){return begin__color_clear();}
		bool _data__color_clear( const ParserChar* text, size_t textLength );
		bool _validateBegin__color_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_clear();

	public:
		static const StringHash HASH_ELEMENT_DEPTH_CLEAR = 238349346;
		static const StringHash HASH_ELEMENT_PASS__DEPTH_CLEAR = 158754482;
		virtual bool begin__depth_clear(){return true;}
		virtual bool end__depth_clear(){return true;}
		virtual bool data__depth_clear( const void* data, size_t length ){return true;}
	private:
		bool _begin__depth_clear( void* attributeData ){return begin__depth_clear();}
		bool _data__depth_clear( const ParserChar* text, size_t textLength );
		bool _validateBegin__depth_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_clear();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_CLEAR = 217473554;
		static const StringHash HASH_ELEMENT_PASS__STENCIL_CLEAR = 243070834;
		virtual bool begin__stencil_clear(){return true;}
		virtual bool end__stencil_clear(){return true;}
		virtual bool data__stencil_clear( const void* data, size_t length ){return true;}
	private:
		bool _begin__stencil_clear( void* attributeData ){return begin__stencil_clear();}
		bool _data__stencil_clear( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_clear();

	public:
		static const StringHash HASH_ELEMENT_DRAW = 440455;
		static const StringHash HASH_ELEMENT_PASS__DRAW = 156422183;
		virtual bool begin__draw(){return true;}
		virtual bool end__draw(){return true;}
		virtual bool data__draw( const void* data, size_t length ){return true;}
	private:
		bool _begin__draw( void* attributeData ){return begin__draw();}
		bool _data__draw( const ParserChar* text, size_t textLength );
		bool _validateBegin__draw( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__draw();

	public:
		static const StringHash HASH_ELEMENT_ALPHA_FUNC = 242440483;
		static const StringHash HASH_ELEMENT_PASS__ALPHA_FUNC = 122155395;
		virtual bool begin__alpha_func(){return true;}
		virtual bool end__alpha_func(){return true;}
	private:
		bool _begin__alpha_func( void* attributeData ){return begin__alpha_func();}
		bool _data__alpha_func( const ParserChar* text, size_t textLength );
		bool _validateBegin__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_func();

	public:
		static const StringHash HASH_ELEMENT_FUNC = 449603;
		static const StringHash HASH_ELEMENT_ALPHA_FUNC__FUNC = 122061667;
		struct alpha_func__func__AttributeData
		{
			static const alpha_func__func__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__alpha_func__func( const alpha_func__func__AttributeData& attributeData ){return true;}
		virtual bool end__alpha_func__func(){return true;}
	private:
		bool _begin__alpha_func__func( void* attributeData ){return begin__alpha_func__func(*static_cast<alpha_func__func__AttributeData*>(attributeData));}
		bool _data__alpha_func__func( const ParserChar* text, size_t textLength );
		bool _validateBegin__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_func__func();

	public:
		static const StringHash HASH_ELEMENT_VALUE = 8160181;
		static const StringHash HASH_ELEMENT_ALPHA_FUNC__VALUE = 73003461;
		struct alpha_func__value__AttributeData
		{
			static const alpha_func__value__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__alpha_func__value( const alpha_func__value__AttributeData& attributeData ){return true;}
		virtual bool end__alpha_func__value(){return true;}
	private:
		bool _begin__alpha_func__value( void* attributeData ){return begin__alpha_func__value(*static_cast<alpha_func__value__AttributeData*>(attributeData));}
		bool _data__alpha_func__value( const ParserChar* text, size_t textLength );
		bool _validateBegin__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_func__value();

	public:
		static const StringHash HASH_ELEMENT_BLEND_FUNC = 77810307;
		static const StringHash HASH_ELEMENT_PASS__BLEND_FUNC = 232202851;
		virtual bool begin__blend_func(){return true;}
		virtual bool end__blend_func(){return true;}
	private:
		bool _begin__blend_func( void* attributeData ){return begin__blend_func();}
		bool _data__blend_func( const ParserChar* text, size_t textLength );
		bool _validateBegin__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blend_func();

	public:
		static const StringHash HASH_ELEMENT_SRC = 31363;
		static const StringHash HASH_ELEMENT_BLEND_FUNC__SRC = 148856355;
		struct src__AttributeData
		{
			static const src__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__src( const src__AttributeData& attributeData ){return true;}
		virtual bool end__src(){return true;}
	private:
		bool _begin__src( void* attributeData ){return begin__src(*static_cast<src__AttributeData*>(attributeData));}
		bool _data__src( const ParserChar* text, size_t textLength );
		bool _validateBegin__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__src();

	public:
		static const StringHash HASH_ELEMENT_DEST = 437412;
		static const StringHash HASH_ELEMENT_BLEND_FUNC__DEST = 234284580;
		struct dest__AttributeData
		{
			static const dest__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__dest( const dest__AttributeData& attributeData ){return true;}
		virtual bool end__dest(){return true;}
	private:
		bool _begin__dest( void* attributeData ){return begin__dest(*static_cast<dest__AttributeData*>(attributeData));}
		bool _data__dest( const ParserChar* text, size_t textLength );
		bool _validateBegin__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dest();

	public:
		static const StringHash HASH_ELEMENT_CLEAR_COLOR = 137661154;
		static const StringHash HASH_ELEMENT_PASS__CLEAR_COLOR = 57345138;
		struct clear_color__AttributeData
		{
			static const clear_color__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__clear_color( const clear_color__AttributeData& attributeData ){return true;}
		virtual bool end__clear_color(){return true;}
	private:
		bool _begin__clear_color( void* attributeData ){return begin__clear_color(*static_cast<clear_color__AttributeData*>(attributeData));}
		bool _data__clear_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__clear_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clear_color();

	public:
		static const StringHash HASH_ELEMENT_CLEAR_STENCIL = 8503804;
		static const StringHash HASH_ELEMENT_PASS__CLEAR_STENCIL = 168516268;
		struct clear_stencil__AttributeData
		{
			static const clear_stencil__AttributeData DEFAULT;

			long value;
			const ParserChar* param;
		};
		virtual bool begin__clear_stencil( const clear_stencil__AttributeData& attributeData ){return true;}
		virtual bool end__clear_stencil(){return true;}
	private:
		bool _begin__clear_stencil( void* attributeData ){return begin__clear_stencil(*static_cast<clear_stencil__AttributeData*>(attributeData));}
		bool _data__clear_stencil( const ParserChar* text, size_t textLength );
		bool _validateBegin__clear_stencil( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clear_stencil();

	public:
		static const StringHash HASH_ELEMENT_CLEAR_DEPTH = 137423912;
		static const StringHash HASH_ELEMENT_PASS__CLEAR_DEPTH = 57304760;
		struct clear_depth__AttributeData
		{
			static const clear_depth__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__clear_depth( const clear_depth__AttributeData& attributeData ){return true;}
		virtual bool end__clear_depth(){return true;}
	private:
		bool _begin__clear_depth( void* attributeData ){return begin__clear_depth(*static_cast<clear_depth__AttributeData*>(attributeData));}
		bool _data__clear_depth( const ParserChar* text, size_t textLength );
		bool _validateBegin__clear_depth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clear_depth();

	public:
		static const StringHash HASH_ELEMENT_CLIP_PLANE = 107054405;
		static const StringHash HASH_ELEMENT_PASS__CLIP_PLANE = 221654501;
		static const StringHash HASH_ATTRIBUTE_INDEX = 7359176;
		struct clip_plane__AttributeData
		{
			static const clip_plane__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__clip_plane( const clip_plane__AttributeData& attributeData ){return true;}
		virtual bool end__clip_plane(){return true;}
	private:
		bool _begin__clip_plane( void* attributeData ){return begin__clip_plane(*static_cast<clip_plane__AttributeData*>(attributeData));}
		bool _data__clip_plane( const ParserChar* text, size_t textLength );
		bool _validateBegin__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clip_plane();

	public:
		static const StringHash HASH_ELEMENT_COLOR_MASK = 109354667;
		static const StringHash HASH_ELEMENT_PASS__COLOR_MASK = 255276555;
		struct color_mask__AttributeData
		{
			static const color_mask__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__color_mask( const color_mask__AttributeData& attributeData ){return true;}
		virtual bool end__color_mask(){return true;}
	private:
		bool _begin__color_mask( void* attributeData ){return begin__color_mask(*static_cast<color_mask__AttributeData*>(attributeData));}
		bool _data__color_mask( const ParserChar* text, size_t textLength );
		bool _validateBegin__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_mask();

	public:
		static const StringHash HASH_ELEMENT_CULL_FACE = 52800853;
		static const StringHash HASH_ELEMENT_PASS__CULL_FACE = 160492501;
		struct cull_face__AttributeData
		{
			static const cull_face__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__cull_face( const cull_face__AttributeData& attributeData ){return true;}
		virtual bool end__cull_face(){return true;}
	private:
		bool _begin__cull_face( void* attributeData ){return begin__cull_face(*static_cast<cull_face__AttributeData*>(attributeData));}
		bool _data__cull_face( const ParserChar* text, size_t textLength );
		bool _validateBegin__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cull_face();

	public:
		static const StringHash HASH_ELEMENT_DEPTH_FUNC = 182679603;
		static const StringHash HASH_ELEMENT_PASS__DEPTH_FUNC = 60235923;
		struct depth_func__AttributeData
		{
			static const depth_func__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__depth_func( const depth_func__AttributeData& attributeData ){return true;}
		virtual bool end__depth_func(){return true;}
	private:
		bool _begin__depth_func( void* attributeData ){return begin__depth_func(*static_cast<depth_func__AttributeData*>(attributeData));}
		bool _data__depth_func( const ParserChar* text, size_t textLength );
		bool _validateBegin__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_func();

	public:
		static const StringHash HASH_ELEMENT_DEPTH_MASK = 182752491;
		static const StringHash HASH_ELEMENT_PASS__DEPTH_MASK = 60357707;
		struct depth_mask__AttributeData
		{
			static const depth_mask__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__depth_mask( const depth_mask__AttributeData& attributeData ){return true;}
		virtual bool end__depth_mask(){return true;}
	private:
		bool _begin__depth_mask( void* attributeData ){return begin__depth_mask(*static_cast<depth_mask__AttributeData*>(attributeData));}
		bool _data__depth_mask( const ParserChar* text, size_t textLength );
		bool _validateBegin__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_mask();

	public:
		static const StringHash HASH_ELEMENT_DEPTH_RANGE = 235062133;
		static const StringHash HASH_ELEMENT_PASS__DEPTH_RANGE = 155470309;
		struct depth_range__AttributeData
		{
			static const depth_range__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__depth_range( const depth_range__AttributeData& attributeData ){return true;}
		virtual bool end__depth_range(){return true;}
	private:
		bool _begin__depth_range( void* attributeData ){return begin__depth_range(*static_cast<depth_range__AttributeData*>(attributeData));}
		bool _data__depth_range( const ParserChar* text, size_t textLength );
		bool _validateBegin__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_range();

	public:
		static const StringHash HASH_ELEMENT_FOG_COLOR = 224022578;
		static const StringHash HASH_ELEMENT_PASS__FOG_COLOR = 130910898;
		struct fog_color__AttributeData
		{
			static const fog_color__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__fog_color( const fog_color__AttributeData& attributeData ){return true;}
		virtual bool end__fog_color(){return true;}
	private:
		bool _begin__fog_color( void* attributeData ){return begin__fog_color(*static_cast<fog_color__AttributeData*>(attributeData));}
		bool _data__fog_color( const ParserChar* text, size_t textLength );
		bool _validateBegin__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_color();

	public:
		static const StringHash HASH_ELEMENT_FOG_DENSITY = 183033321;
		static const StringHash HASH_ELEMENT_PASS__FOG_DENSITY = 263083897;
		struct fog_density__AttributeData
		{
			static const fog_density__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__fog_density( const fog_density__AttributeData& attributeData ){return true;}
		virtual bool end__fog_density(){return true;}
	private:
		bool _begin__fog_density( void* attributeData ){return begin__fog_density(*static_cast<fog_density__AttributeData*>(attributeData));}
		bool _data__fog_density( const ParserChar* text, size_t textLength );
		bool _validateBegin__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_density();

	public:
		static const StringHash HASH_ELEMENT_FOG_MODE = 97928053;
		static const StringHash HASH_ELEMENT_PASS__FOG_MODE = 226326293;
		struct fog_mode__AttributeData
		{
			static const fog_mode__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__fog_mode( const fog_mode__AttributeData& attributeData ){return true;}
		virtual bool end__fog_mode(){return true;}
	private:
		bool _begin__fog_mode( void* attributeData ){return begin__fog_mode(*static_cast<fog_mode__AttributeData*>(attributeData));}
		bool _data__fog_mode( const ParserChar* text, size_t textLength );
		bool _validateBegin__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_mode();

	public:
		static const StringHash HASH_ELEMENT_FOG_START = 225101252;
		static const StringHash HASH_ELEMENT_PASS__FOG_START = 134185796;
		struct fog_start__AttributeData
		{
			static const fog_start__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__fog_start( const fog_start__AttributeData& attributeData ){return true;}
		virtual bool end__fog_start(){return true;}
	private:
		bool _begin__fog_start( void* attributeData ){return begin__fog_start(*static_cast<fog_start__AttributeData*>(attributeData));}
		bool _data__fog_start( const ParserChar* text, size_t textLength );
		bool _validateBegin__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_start();

	public:
		static const StringHash HASH_ELEMENT_FOG_END = 224222244;
		static const StringHash HASH_ELEMENT_PASS__FOG_END = 198692708;
		struct fog_end__AttributeData
		{
			static const fog_end__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__fog_end( const fog_end__AttributeData& attributeData ){return true;}
		virtual bool end__fog_end(){return true;}
	private:
		bool _begin__fog_end( void* attributeData ){return begin__fog_end(*static_cast<fog_end__AttributeData*>(attributeData));}
		bool _data__fog_end( const ParserChar* text, size_t textLength );
		bool _validateBegin__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_end();

	public:
		static const StringHash HASH_ELEMENT_FRONT_FACE = 94576373;
		static const StringHash HASH_ELEMENT_PASS__FRONT_FACE = 215446933;
		struct front_face__AttributeData
		{
			static const front_face__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__front_face( const front_face__AttributeData& attributeData ){return true;}
		virtual bool end__front_face(){return true;}
	private:
		bool _begin__front_face( void* attributeData ){return begin__front_face(*static_cast<front_face__AttributeData*>(attributeData));}
		bool _data__front_face( const ParserChar* text, size_t textLength );
		bool _validateBegin__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__front_face();

	public:
		static const StringHash HASH_ELEMENT_PASS__TEXTURE_PIPELINE = 49503749;
		struct pass__texture_pipeline__AttributeData
		{
			static const pass__texture_pipeline__AttributeData DEFAULT;

			const ParserChar* param;
		};
		virtual bool begin__pass__texture_pipeline( const pass__texture_pipeline__AttributeData& attributeData ){return true;}
		virtual bool end__pass__texture_pipeline(){return true;}
	private:
		bool _begin__pass__texture_pipeline( void* attributeData ){return begin__pass__texture_pipeline(*static_cast<pass__texture_pipeline__AttributeData*>(attributeData));}
		bool _data__pass__texture_pipeline( const ParserChar* text, size_t textLength );
		bool _validateBegin__pass__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass__texture_pipeline();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__VALUE = 255798677;
		struct texture_pipeline__value__AttributeData
		{
			static const texture_pipeline__value__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__texture_pipeline__value( const texture_pipeline__value__AttributeData& attributeData ){return true;}
		virtual bool end__texture_pipeline__value(){return true;}
	private:
		bool _begin__texture_pipeline__value( void* attributeData ){return begin__texture_pipeline__value(*static_cast<texture_pipeline__value__AttributeData*>(attributeData));}
		bool _data__texture_pipeline__value( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_pipeline__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__value();

	public:
		static const StringHash HASH_ELEMENT_VALUE__TEXCOMBINER = 43651570;
		virtual bool begin__value__texcombiner(){return true;}
		virtual bool end__value__texcombiner(){return true;}
	private:
		bool _begin__value__texcombiner( void* attributeData ){return begin__value__texcombiner();}
		bool _data__value__texcombiner( const ParserChar* text, size_t textLength );
		bool _validateBegin__value__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__value__texcombiner();

	public:
		static const StringHash HASH_ELEMENT_VALUE__TEXENV = 170873110;
		struct value__texenv__AttributeData
		{
			static const value__texenv__AttributeData DEFAULT;

			const ParserChar* _operator;
			const ParserChar* unit;
		};
		virtual bool begin__value__texenv( const value__texenv__AttributeData& attributeData ){return true;}
		virtual bool end__value__texenv(){return true;}
	private:
		bool _begin__value__texenv( void* attributeData ){return begin__value__texenv(*static_cast<value__texenv__AttributeData*>(attributeData));}
		bool _data__value__texenv( const ParserChar* text, size_t textLength );
		bool _validateBegin__value__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__value__texenv();

	public:
		static const StringHash HASH_ELEMENT_VALUE__EXTRA = 76857393;
		struct value__extra__AttributeData
		{
			static const value__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__value__extra( const value__extra__AttributeData& attributeData ){return true;}
		virtual bool end__value__extra(){return true;}
	private:
		bool _begin__value__extra( void* attributeData ){return begin__value__extra(*static_cast<value__extra__AttributeData*>(attributeData));}
		bool _data__value__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__value__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__value__extra();

	public:
		static const StringHash HASH_ELEMENT_LOGIC_OP = 98538320;
		static const StringHash HASH_ELEMENT_PASS__LOGIC_OP = 225896240;
		struct logic_op__AttributeData
		{
			static const logic_op__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__logic_op( const logic_op__AttributeData& attributeData ){return true;}
		virtual bool end__logic_op(){return true;}
	private:
		bool _begin__logic_op( void* attributeData ){return begin__logic_op(*static_cast<logic_op__AttributeData*>(attributeData));}
		bool _data__logic_op( const ParserChar* text, size_t textLength );
		bool _validateBegin__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__logic_op();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_AMBIENT = 113574516;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_AMBIENT = 72324916;
		struct light_ambient__AttributeData
		{
			static const light_ambient__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_ambient( const light_ambient__AttributeData& attributeData ){return true;}
		virtual bool end__light_ambient(){return true;}
	private:
		bool _begin__light_ambient( void* attributeData ){return begin__light_ambient(*static_cast<light_ambient__AttributeData*>(attributeData));}
		bool _data__light_ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_ambient();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_DIFFUSE = 134293173;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_DIFFUSE = 244036085;
		struct light_diffuse__AttributeData
		{
			static const light_diffuse__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_diffuse( const light_diffuse__AttributeData& attributeData ){return true;}
		virtual bool end__light_diffuse(){return true;}
	private:
		bool _begin__light_diffuse( void* attributeData ){return begin__light_diffuse(*static_cast<light_diffuse__AttributeData*>(attributeData));}
		bool _data__light_diffuse( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_diffuse();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_SPECULAR = 157623042;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_SPECULAR = 30177122;
		struct light_specular__AttributeData
		{
			static const light_specular__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_specular( const light_specular__AttributeData& attributeData ){return true;}
		virtual bool end__light_specular(){return true;}
	private:
		bool _begin__light_specular( void* attributeData ){return begin__light_specular(*static_cast<light_specular__AttributeData*>(attributeData));}
		bool _data__light_specular( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_specular();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_POSITION = 157224718;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_POSITION = 32930670;
		struct light_position__AttributeData
		{
			static const light_position__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_position( const light_position__AttributeData& attributeData ){return true;}
		virtual bool end__light_position(){return true;}
	private:
		bool _begin__light_position( void* attributeData ){return begin__light_position(*static_cast<light_position__AttributeData*>(attributeData));}
		bool _data__light_position( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_position();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_CONSTANT_ATTENUATION = 107287662;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_CONSTANT_ATTENUATION = 248277070;
		struct light_constant_attenuation__AttributeData
		{
			static const light_constant_attenuation__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_constant_attenuation( const light_constant_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__light_constant_attenuation(){return true;}
	private:
		bool _begin__light_constant_attenuation( void* attributeData ){return begin__light_constant_attenuation(*static_cast<light_constant_attenuation__AttributeData*>(attributeData));}
		bool _data__light_constant_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_constant_attenuation();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_LINEAR_ATTENUTATION = 154814046;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_LINEAR_ATTENUTATION = 263246110;
		struct light_linear_attenutation__AttributeData
		{
			static const light_linear_attenutation__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_linear_attenutation( const light_linear_attenutation__AttributeData& attributeData ){return true;}
		virtual bool end__light_linear_attenutation(){return true;}
	private:
		bool _begin__light_linear_attenutation( void* attributeData ){return begin__light_linear_attenutation(*static_cast<light_linear_attenutation__AttributeData*>(attributeData));}
		bool _data__light_linear_attenutation( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_linear_attenutation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_linear_attenutation();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_QUADRATIC_ATTENUATION = 111314510;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_QUADRATIC_ATTENUATION = 204850382;
		struct light_quadratic_attenuation__AttributeData
		{
			static const light_quadratic_attenuation__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_quadratic_attenuation( const light_quadratic_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__light_quadratic_attenuation(){return true;}
	private:
		bool _begin__light_quadratic_attenuation( void* attributeData ){return begin__light_quadratic_attenuation(*static_cast<light_quadratic_attenuation__AttributeData*>(attributeData));}
		bool _data__light_quadratic_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_quadratic_attenuation();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_SPOT_CUTOFF = 263462582;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_CUTOFF = 150116294;
		struct light_spot_cutoff__AttributeData
		{
			static const light_spot_cutoff__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_spot_cutoff( const light_spot_cutoff__AttributeData& attributeData ){return true;}
		virtual bool end__light_spot_cutoff(){return true;}
	private:
		bool _begin__light_spot_cutoff( void* attributeData ){return begin__light_spot_cutoff(*static_cast<light_spot_cutoff__AttributeData*>(attributeData));}
		bool _data__light_spot_cutoff( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_spot_cutoff();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_SPOT_DIRECTION = 34428126;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_DIRECTION = 177881278;
		struct light_spot_direction__AttributeData
		{
			static const light_spot_direction__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_spot_direction( const light_spot_direction__AttributeData& attributeData ){return true;}
		virtual bool end__light_spot_direction(){return true;}
	private:
		bool _begin__light_spot_direction( void* attributeData ){return begin__light_spot_direction(*static_cast<light_spot_direction__AttributeData*>(attributeData));}
		bool _data__light_spot_direction( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_spot_direction();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_SPOT_EXPONENT = 132068740;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_EXPONENT = 22561988;
		struct light_spot_exponent__AttributeData
		{
			static const light_spot_exponent__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_spot_exponent( const light_spot_exponent__AttributeData& attributeData ){return true;}
		virtual bool end__light_spot_exponent(){return true;}
	private:
		bool _begin__light_spot_exponent( void* attributeData ){return begin__light_spot_exponent(*static_cast<light_spot_exponent__AttributeData*>(attributeData));}
		bool _data__light_spot_exponent( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_spot_exponent();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_MODEL_AMBIENT = 111126580;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_AMBIENT = 1382244;
		struct light_model_ambient__AttributeData
		{
			static const light_model_ambient__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__light_model_ambient( const light_model_ambient__AttributeData& attributeData ){return true;}
		virtual bool end__light_model_ambient(){return true;}
	private:
		bool _begin__light_model_ambient( void* attributeData ){return begin__light_model_ambient(*static_cast<light_model_ambient__AttributeData*>(attributeData));}
		bool _data__light_model_ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_model_ambient();

	public:
		static const StringHash HASH_ELEMENT_LINE_WIDTH = 191548392;
		static const StringHash HASH_ELEMENT_PASS__LINE_WIDTH = 71217992;
		struct line_width__AttributeData
		{
			static const line_width__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__line_width( const line_width__AttributeData& attributeData ){return true;}
		virtual bool end__line_width(){return true;}
	private:
		bool _begin__line_width( void* attributeData ){return begin__line_width(*static_cast<line_width__AttributeData*>(attributeData));}
		bool _data__line_width( const ParserChar* text, size_t textLength );
		bool _validateBegin__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__line_width();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL_AMBIENT = 212902564;
		static const StringHash HASH_ELEMENT_PASS__MATERIAL_AMBIENT = 65325572;
		struct material_ambient__AttributeData
		{
			static const material_ambient__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__material_ambient( const material_ambient__AttributeData& attributeData ){return true;}
		virtual bool end__material_ambient(){return true;}
	private:
		bool _begin__material_ambient( void* attributeData ){return begin__material_ambient(*static_cast<material_ambient__AttributeData*>(attributeData));}
		bool _data__material_ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_ambient();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL_DIFFUSE = 108299877;
		static const StringHash HASH_ELEMENT_PASS__MATERIAL_DIFFUSE = 253816517;
		struct material_diffuse__AttributeData
		{
			static const material_diffuse__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__material_diffuse( const material_diffuse__AttributeData& attributeData ){return true;}
		virtual bool end__material_diffuse(){return true;}
	private:
		bool _begin__material_diffuse( void* attributeData ){return begin__material_diffuse(*static_cast<material_diffuse__AttributeData*>(attributeData));}
		bool _data__material_diffuse( const ParserChar* text, size_t textLength );
		bool _validateBegin__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_diffuse();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL_EMISSION = 210711006;
		static const StringHash HASH_ELEMENT_PASS__MATERIAL_EMISSION = 264879022;
		struct material_emission__AttributeData
		{
			static const material_emission__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__material_emission( const material_emission__AttributeData& attributeData ){return true;}
		virtual bool end__material_emission(){return true;}
	private:
		bool _begin__material_emission( void* attributeData ){return begin__material_emission(*static_cast<material_emission__AttributeData*>(attributeData));}
		bool _data__material_emission( const ParserChar* text, size_t textLength );
		bool _validateBegin__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_emission();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL_SHININESS = 135694787;
		static const StringHash HASH_ELEMENT_PASS__MATERIAL_SHININESS = 75374739;
		struct material_shininess__AttributeData
		{
			static const material_shininess__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__material_shininess( const material_shininess__AttributeData& attributeData ){return true;}
		virtual bool end__material_shininess(){return true;}
	private:
		bool _begin__material_shininess( void* attributeData ){return begin__material_shininess(*static_cast<material_shininess__AttributeData*>(attributeData));}
		bool _data__material_shininess( const ParserChar* text, size_t textLength );
		bool _validateBegin__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_shininess();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL_SPECULAR = 239021794;
		static const StringHash HASH_ELEMENT_PASS__MATERIAL_SPECULAR = 192521330;
		struct material_specular__AttributeData
		{
			static const material_specular__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__material_specular( const material_specular__AttributeData& attributeData ){return true;}
		virtual bool end__material_specular(){return true;}
	private:
		bool _begin__material_specular( void* attributeData ){return begin__material_specular(*static_cast<material_specular__AttributeData*>(attributeData));}
		bool _data__material_specular( const ParserChar* text, size_t textLength );
		bool _validateBegin__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_specular();

	public:
		static const StringHash HASH_ELEMENT_MODEL_VIEW_MATRIX = 136322840;
		static const StringHash HASH_ELEMENT_PASS__MODEL_VIEW_MATRIX = 23238152;
		struct model_view_matrix__AttributeData
		{
			static const model_view_matrix__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__model_view_matrix( const model_view_matrix__AttributeData& attributeData ){return true;}
		virtual bool end__model_view_matrix(){return true;}
	private:
		bool _begin__model_view_matrix( void* attributeData ){return begin__model_view_matrix(*static_cast<model_view_matrix__AttributeData*>(attributeData));}
		bool _data__model_view_matrix( const ParserChar* text, size_t textLength );
		bool _validateBegin__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__model_view_matrix();

	public:
		static const StringHash HASH_ELEMENT_POINT_DISTANCE_ATTENUATION = 139457678;
		static const StringHash HASH_ELEMENT_PASS__POINT_DISTANCE_ATTENUATION = 220636846;
		struct point_distance_attenuation__AttributeData
		{
			static const point_distance_attenuation__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__point_distance_attenuation( const point_distance_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__point_distance_attenuation(){return true;}
	private:
		bool _begin__point_distance_attenuation( void* attributeData ){return begin__point_distance_attenuation(*static_cast<point_distance_attenuation__AttributeData*>(attributeData));}
		bool _data__point_distance_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_distance_attenuation();

	public:
		static const StringHash HASH_ELEMENT_POINT_FADE_THRESHOLD_SIZE = 101782757;
		static const StringHash HASH_ELEMENT_PASS__POINT_FADE_THRESHOLD_SIZE = 13010885;
		struct point_fade_threshold_size__AttributeData
		{
			static const point_fade_threshold_size__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__point_fade_threshold_size( const point_fade_threshold_size__AttributeData& attributeData ){return true;}
		virtual bool end__point_fade_threshold_size(){return true;}
	private:
		bool _begin__point_fade_threshold_size( void* attributeData ){return begin__point_fade_threshold_size(*static_cast<point_fade_threshold_size__AttributeData*>(attributeData));}
		bool _data__point_fade_threshold_size( const ParserChar* text, size_t textLength );
		bool _validateBegin__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_fade_threshold_size();

	public:
		static const StringHash HASH_ELEMENT_POINT_SIZE = 94500613;
		static const StringHash HASH_ELEMENT_PASS__POINT_SIZE = 215457381;
		struct point_size__AttributeData
		{
			static const point_size__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__point_size( const point_size__AttributeData& attributeData ){return true;}
		virtual bool end__point_size(){return true;}
	private:
		bool _begin__point_size( void* attributeData ){return begin__point_size(*static_cast<point_size__AttributeData*>(attributeData));}
		bool _data__point_size( const ParserChar* text, size_t textLength );
		bool _validateBegin__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_size();

	public:
		static const StringHash HASH_ELEMENT_POINT_SIZE_MIN = 118555150;
		static const StringHash HASH_ELEMENT_PASS__POINT_SIZE_MIN = 241669230;
		struct point_size_min__AttributeData
		{
			static const point_size_min__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__point_size_min( const point_size_min__AttributeData& attributeData ){return true;}
		virtual bool end__point_size_min(){return true;}
	private:
		bool _begin__point_size_min( void* attributeData ){return begin__point_size_min(*static_cast<point_size_min__AttributeData*>(attributeData));}
		bool _data__point_size_min( const ParserChar* text, size_t textLength );
		bool _validateBegin__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_size_min();

	public:
		static const StringHash HASH_ELEMENT_POINT_SIZE_MAX = 118555256;
		static const StringHash HASH_ELEMENT_PASS__POINT_SIZE_MAX = 241669144;
		struct point_size_max__AttributeData
		{
			static const point_size_max__AttributeData DEFAULT;

			float value;
			const ParserChar* param;
		};
		virtual bool begin__point_size_max( const point_size_max__AttributeData& attributeData ){return true;}
		virtual bool end__point_size_max(){return true;}
	private:
		bool _begin__point_size_max( void* attributeData ){return begin__point_size_max(*static_cast<point_size_max__AttributeData*>(attributeData));}
		bool _data__point_size_max( const ParserChar* text, size_t textLength );
		bool _validateBegin__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_size_max();

	public:
		static const StringHash HASH_ELEMENT_POLYGON_OFFSET = 73611924;
		static const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET = 214584564;
		struct polygon_offset__AttributeData
		{
			static const polygon_offset__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__polygon_offset( const polygon_offset__AttributeData& attributeData ){return true;}
		virtual bool end__polygon_offset(){return true;}
	private:
		bool _begin__polygon_offset( void* attributeData ){return begin__polygon_offset(*static_cast<polygon_offset__AttributeData*>(attributeData));}
		bool _data__polygon_offset( const ParserChar* text, size_t textLength );
		bool _validateBegin__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygon_offset();

	public:
		static const StringHash HASH_ELEMENT_PROJECTION_MATRIX = 266718536;
		static const StringHash HASH_ELEMENT_PASS__PROJECTION_MATRIX = 209936312;
		struct projection_matrix__AttributeData
		{
			static const projection_matrix__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__projection_matrix( const projection_matrix__AttributeData& attributeData ){return true;}
		virtual bool end__projection_matrix(){return true;}
	private:
		bool _begin__projection_matrix( void* attributeData ){return begin__projection_matrix(*static_cast<projection_matrix__AttributeData*>(attributeData));}
		bool _data__projection_matrix( const ParserChar* text, size_t textLength );
		bool _validateBegin__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__projection_matrix();

	public:
		static const StringHash HASH_ELEMENT_SCISSOR = 161524242;
		static const StringHash HASH_ELEMENT_PASS__SCISSOR = 254426482;
		struct scissor__AttributeData
		{
			static const scissor__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__scissor( const scissor__AttributeData& attributeData ){return true;}
		virtual bool end__scissor(){return true;}
	private:
		bool _begin__scissor( void* attributeData ){return begin__scissor(*static_cast<scissor__AttributeData*>(attributeData));}
		bool _data__scissor( const ParserChar* text, size_t textLength );
		bool _validateBegin__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scissor();

	public:
		static const StringHash HASH_ELEMENT_SHADE_MODEL = 188464412;
		static const StringHash HASH_ELEMENT_PASS__SHADE_MODEL = 6109180;
		struct shade_model__AttributeData
		{
			static const shade_model__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__shade_model( const shade_model__AttributeData& attributeData ){return true;}
		virtual bool end__shade_model(){return true;}
	private:
		bool _begin__shade_model( void* attributeData ){return begin__shade_model(*static_cast<shade_model__AttributeData*>(attributeData));}
		bool _data__shade_model( const ParserChar* text, size_t textLength );
		bool _validateBegin__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shade_model();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_FUNC = 164569299;
		static const StringHash HASH_ELEMENT_PASS__STENCIL_FUNC = 266860419;
		virtual bool begin__stencil_func(){return true;}
		virtual bool end__stencil_func(){return true;}
	private:
		bool _begin__stencil_func( void* attributeData ){return begin__stencil_func();}
		bool _data__stencil_func( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_FUNC__FUNC = 43711635;
		struct stencil_func__func__AttributeData
		{
			static const stencil_func__func__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_func__func( const stencil_func__func__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_func__func(){return true;}
	private:
		bool _begin__stencil_func__func( void* attributeData ){return begin__stencil_func__func(*static_cast<stencil_func__func__AttributeData*>(attributeData));}
		bool _data__stencil_func__func( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func__func();

	public:
		static const StringHash HASH_ELEMENT_REF = 30902;
		static const StringHash HASH_ELEMENT_STENCIL_FUNC__REF = 220830390;
		struct stencil_func__ref__AttributeData
		{
			static const stencil_func__ref__AttributeData DEFAULT;

			unsigned short value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_func__ref( const stencil_func__ref__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_func__ref(){return true;}
	private:
		bool _begin__stencil_func__ref( void* attributeData ){return begin__stencil_func__ref(*static_cast<stencil_func__ref__AttributeData*>(attributeData));}
		bool _data__stencil_func__ref( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func__ref();

	public:
		static const StringHash HASH_ELEMENT_MASK = 473243;
		static const StringHash HASH_ELEMENT_STENCIL_FUNC__MASK = 43718731;
		struct stencil_func__mask__AttributeData
		{
			static const stencil_func__mask__AttributeData DEFAULT;

			unsigned short value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_func__mask( const stencil_func__mask__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_func__mask(){return true;}
	private:
		bool _begin__stencil_func__mask( void* attributeData ){return begin__stencil_func__mask(*static_cast<stencil_func__mask__AttributeData*>(attributeData));}
		bool _data__stencil_func__mask( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func__mask();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_MASK = 164690955;
		static const StringHash HASH_ELEMENT_PASS__STENCIL_MASK = 266868059;
		struct stencil_mask__AttributeData
		{
			static const stencil_mask__AttributeData DEFAULT;

			long value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_mask( const stencil_mask__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_mask(){return true;}
	private:
		bool _begin__stencil_mask( void* attributeData ){return begin__stencil_mask(*static_cast<stencil_mask__AttributeData*>(attributeData));}
		bool _data__stencil_mask( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_mask();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_OP = 77189280;
		static const StringHash HASH_ELEMENT_PASS__STENCIL_OP = 231729216;
		virtual bool begin__stencil_op(){return true;}
		virtual bool end__stencil_op(){return true;}
	private:
		bool _begin__stencil_op( void* attributeData ){return begin__stencil_op();}
		bool _data__stencil_op( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op();

	public:
		static const StringHash HASH_ELEMENT_FAIL = 444412;
		static const StringHash HASH_ELEMENT_STENCIL_OP__FAIL = 49026908;
		struct stencil_op__fail__AttributeData
		{
			static const stencil_op__fail__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_op__fail( const stencil_op__fail__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_op__fail(){return true;}
	private:
		bool _begin__stencil_op__fail( void* attributeData ){return begin__stencil_op__fail(*static_cast<stencil_op__fail__AttributeData*>(attributeData));}
		bool _data__stencil_op__fail( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op__fail();

	public:
		static const StringHash HASH_ELEMENT_ZFAIL = 8439804;
		static const StringHash HASH_ELEMENT_STENCIL_OP__ZFAIL = 252562908;
		struct stencil_op__zfail__AttributeData
		{
			static const stencil_op__zfail__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_op__zfail( const stencil_op__zfail__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_op__zfail(){return true;}
	private:
		bool _begin__stencil_op__zfail( void* attributeData ){return begin__stencil_op__zfail(*static_cast<stencil_op__zfail__AttributeData*>(attributeData));}
		bool _data__stencil_op__zfail( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op__zfail();

	public:
		static const StringHash HASH_ELEMENT_ZPASS = 8480931;
		static const StringHash HASH_ELEMENT_STENCIL_OP__ZPASS = 252469891;
		struct stencil_op__zpass__AttributeData
		{
			static const stencil_op__zpass__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_op__zpass( const stencil_op__zpass__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_op__zpass(){return true;}
	private:
		bool _begin__stencil_op__zpass( void* attributeData ){return begin__stencil_op__zpass(*static_cast<stencil_op__zpass__AttributeData*>(attributeData));}
		bool _data__stencil_op__zpass( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op__zpass();

	public:
		static const StringHash HASH_ELEMENT_ALPHA_TEST_ENABLE = 46564773;
		static const StringHash HASH_ELEMENT_PASS__ALPHA_TEST_ENABLE = 34344917;
		struct alpha_test_enable__AttributeData
		{
			static const alpha_test_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__alpha_test_enable( const alpha_test_enable__AttributeData& attributeData ){return true;}
		virtual bool end__alpha_test_enable(){return true;}
	private:
		bool _begin__alpha_test_enable( void* attributeData ){return begin__alpha_test_enable(*static_cast<alpha_test_enable__AttributeData*>(attributeData));}
		bool _data__alpha_test_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_test_enable();

	public:
		static const StringHash HASH_ELEMENT_BLEND_ENABLE = 53919109;
		static const StringHash HASH_ELEMENT_PASS__BLEND_ENABLE = 123623157;
		struct blend_enable__AttributeData
		{
			static const blend_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__blend_enable( const blend_enable__AttributeData& attributeData ){return true;}
		virtual bool end__blend_enable(){return true;}
	private:
		bool _begin__blend_enable( void* attributeData ){return begin__blend_enable(*static_cast<blend_enable__AttributeData*>(attributeData));}
		bool _data__blend_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blend_enable();

	public:
		static const StringHash HASH_ELEMENT_CLIP_PLANE_ENABLE = 62664181;
		static const StringHash HASH_ELEMENT_PASS__CLIP_PLANE_ENABLE = 115779493;
		struct clip_plane_enable__AttributeData
		{
			static const clip_plane_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__clip_plane_enable( const clip_plane_enable__AttributeData& attributeData ){return true;}
		virtual bool end__clip_plane_enable(){return true;}
	private:
		bool _begin__clip_plane_enable( void* attributeData ){return begin__clip_plane_enable(*static_cast<clip_plane_enable__AttributeData*>(attributeData));}
		bool _data__clip_plane_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clip_plane_enable();

	public:
		static const StringHash HASH_ELEMENT_COLOR_LOGIC_OP_ENABLE = 188045397;
		static const StringHash HASH_ELEMENT_PASS__COLOR_LOGIC_OP_ENABLE = 29904597;
		struct color_logic_op_enable__AttributeData
		{
			static const color_logic_op_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__color_logic_op_enable( const color_logic_op_enable__AttributeData& attributeData ){return true;}
		virtual bool end__color_logic_op_enable(){return true;}
	private:
		bool _begin__color_logic_op_enable( void* attributeData ){return begin__color_logic_op_enable(*static_cast<color_logic_op_enable__AttributeData*>(attributeData));}
		bool _data__color_logic_op_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_logic_op_enable();

	public:
		static const StringHash HASH_ELEMENT_COLOR_MATERIAL_ENABLE = 203733285;
		static const StringHash HASH_ELEMENT_PASS__COLOR_MATERIAL_ENABLE = 111148709;
		struct color_material_enable__AttributeData
		{
			static const color_material_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__color_material_enable( const color_material_enable__AttributeData& attributeData ){return true;}
		virtual bool end__color_material_enable(){return true;}
	private:
		bool _begin__color_material_enable( void* attributeData ){return begin__color_material_enable(*static_cast<color_material_enable__AttributeData*>(attributeData));}
		bool _data__color_material_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_material_enable();

	public:
		static const StringHash HASH_ELEMENT_CULL_FACE_ENABLE = 134131333;
		static const StringHash HASH_ELEMENT_PASS__CULL_FACE_ENABLE = 214615653;
		struct cull_face_enable__AttributeData
		{
			static const cull_face_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__cull_face_enable( const cull_face_enable__AttributeData& attributeData ){return true;}
		virtual bool end__cull_face_enable(){return true;}
	private:
		bool _begin__cull_face_enable( void* attributeData ){return begin__cull_face_enable(*static_cast<cull_face_enable__AttributeData*>(attributeData));}
		bool _data__cull_face_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cull_face_enable();

	public:
		static const StringHash HASH_ELEMENT_DEPTH_TEST_ENABLE = 197424741;
		static const StringHash HASH_ELEMENT_PASS__DEPTH_TEST_ENABLE = 218300565;
		struct depth_test_enable__AttributeData
		{
			static const depth_test_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__depth_test_enable( const depth_test_enable__AttributeData& attributeData ){return true;}
		virtual bool end__depth_test_enable(){return true;}
	private:
		bool _begin__depth_test_enable( void* attributeData ){return begin__depth_test_enable(*static_cast<depth_test_enable__AttributeData*>(attributeData));}
		bool _data__depth_test_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_test_enable();

	public:
		static const StringHash HASH_ELEMENT_DITHER_ENABLE = 248419589;
		static const StringHash HASH_ELEMENT_PASS__DITHER_ENABLE = 138674757;
		struct dither_enable__AttributeData
		{
			static const dither_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__dither_enable( const dither_enable__AttributeData& attributeData ){return true;}
		virtual bool end__dither_enable(){return true;}
	private:
		bool _begin__dither_enable( void* attributeData ){return begin__dither_enable(*static_cast<dither_enable__AttributeData*>(attributeData));}
		bool _data__dither_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dither_enable();

	public:
		static const StringHash HASH_ELEMENT_FOG_ENABLE = 96644853;
		static const StringHash HASH_ELEMENT_PASS__FOG_ENABLE = 217499221;
		struct fog_enable__AttributeData
		{
			static const fog_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__fog_enable( const fog_enable__AttributeData& attributeData ){return true;}
		virtual bool end__fog_enable(){return true;}
	private:
		bool _begin__fog_enable( void* attributeData ){return begin__fog_enable(*static_cast<fog_enable__AttributeData*>(attributeData));}
		bool _data__fog_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_enable();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE_PIPELINE_ENABLE = 267851525;
		static const StringHash HASH_ELEMENT_PASS__TEXTURE_PIPELINE_ENABLE = 177314229;
		struct texture_pipeline_enable__AttributeData
		{
			static const texture_pipeline_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__texture_pipeline_enable( const texture_pipeline_enable__AttributeData& attributeData ){return true;}
		virtual bool end__texture_pipeline_enable(){return true;}
	private:
		bool _begin__texture_pipeline_enable( void* attributeData ){return begin__texture_pipeline_enable(*static_cast<texture_pipeline_enable__AttributeData*>(attributeData));}
		bool _data__texture_pipeline_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture_pipeline_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline_enable();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_ENABLE = 44804229;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_ENABLE = 117641205;
		struct light_enable__AttributeData
		{
			static const light_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
			long long index;
		};
		virtual bool begin__light_enable( const light_enable__AttributeData& attributeData ){return true;}
		virtual bool end__light_enable(){return true;}
	private:
		bool _begin__light_enable( void* attributeData ){return begin__light_enable(*static_cast<light_enable__AttributeData*>(attributeData));}
		bool _data__light_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_enable();

	public:
		static const StringHash HASH_ELEMENT_LIGHTING_ENABLE = 140439397;
		static const StringHash HASH_ELEMENT_PASS__LIGHTING_ENABLE = 48998885;
		struct lighting_enable__AttributeData
		{
			static const lighting_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__lighting_enable( const lighting_enable__AttributeData& attributeData ){return true;}
		virtual bool end__lighting_enable(){return true;}
	private:
		bool _begin__lighting_enable( void* attributeData ){return begin__lighting_enable(*static_cast<lighting_enable__AttributeData*>(attributeData));}
		bool _data__lighting_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lighting_enable();

	public:
		static const StringHash HASH_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE = 26336277;
		static const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_TWO_SIDE_ENABLE = 255891349;
		struct light_model_two_side_enable__AttributeData
		{
			static const light_model_two_side_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__light_model_two_side_enable( const light_model_two_side_enable__AttributeData& attributeData ){return true;}
		virtual bool end__light_model_two_side_enable(){return true;}
	private:
		bool _begin__light_model_two_side_enable( void* attributeData ){return begin__light_model_two_side_enable(*static_cast<light_model_two_side_enable__AttributeData*>(attributeData));}
		bool _data__light_model_two_side_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_model_two_side_enable();

	public:
		static const StringHash HASH_ELEMENT_LINE_SMOOTH_ENABLE = 179460837;
		static const StringHash HASH_ELEMENT_PASS__LINE_SMOOTH_ENABLE = 239794133;
		struct line_smooth_enable__AttributeData
		{
			static const line_smooth_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__line_smooth_enable( const line_smooth_enable__AttributeData& attributeData ){return true;}
		virtual bool end__line_smooth_enable(){return true;}
	private:
		bool _begin__line_smooth_enable( void* attributeData ){return begin__line_smooth_enable(*static_cast<line_smooth_enable__AttributeData*>(attributeData));}
		bool _data__line_smooth_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__line_smooth_enable();

	public:
		static const StringHash HASH_ELEMENT_MULTISAMPLE_ENABLE = 202117781;
		static const StringHash HASH_ELEMENT_PASS__MULTISAMPLE_ENABLE = 266698789;
		struct multisample_enable__AttributeData
		{
			static const multisample_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__multisample_enable( const multisample_enable__AttributeData& attributeData ){return true;}
		virtual bool end__multisample_enable(){return true;}
	private:
		bool _begin__multisample_enable( void* attributeData ){return begin__multisample_enable(*static_cast<multisample_enable__AttributeData*>(attributeData));}
		bool _data__multisample_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__multisample_enable();

	public:
		static const StringHash HASH_ELEMENT_NORMALIZE_ENABLE = 104996709;
		static const StringHash HASH_ELEMENT_PASS__NORMALIZE_ENABLE = 261502853;
		struct normalize_enable__AttributeData
		{
			static const normalize_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__normalize_enable( const normalize_enable__AttributeData& attributeData ){return true;}
		virtual bool end__normalize_enable(){return true;}
	private:
		bool _begin__normalize_enable( void* attributeData ){return begin__normalize_enable(*static_cast<normalize_enable__AttributeData*>(attributeData));}
		bool _data__normalize_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__normalize_enable();

	public:
		static const StringHash HASH_ELEMENT_POINT_SMOOTH_ENABLE = 182602229;
		static const StringHash HASH_ELEMENT_PASS__POINT_SMOOTH_ENABLE = 206626965;
		struct point_smooth_enable__AttributeData
		{
			static const point_smooth_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__point_smooth_enable( const point_smooth_enable__AttributeData& attributeData ){return true;}
		virtual bool end__point_smooth_enable(){return true;}
	private:
		bool _begin__point_smooth_enable( void* attributeData ){return begin__point_smooth_enable(*static_cast<point_smooth_enable__AttributeData*>(attributeData));}
		bool _data__point_smooth_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_smooth_enable();

	public:
		static const StringHash HASH_ELEMENT_POLYGON_OFFSET_FILL_ENABLE = 194749109;
		static const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET_FILL_ENABLE = 53655765;
		struct polygon_offset_fill_enable__AttributeData
		{
			static const polygon_offset_fill_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__polygon_offset_fill_enable( const polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
		virtual bool end__polygon_offset_fill_enable(){return true;}
	private:
		bool _begin__polygon_offset_fill_enable( void* attributeData ){return begin__polygon_offset_fill_enable(*static_cast<polygon_offset_fill_enable__AttributeData*>(attributeData));}
		bool _data__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygon_offset_fill_enable();

	public:
		static const StringHash HASH_ELEMENT_RESCALE_NORMAL_ENABLE = 190127845;
		static const StringHash HASH_ELEMENT_PASS__RESCALE_NORMAL_ENABLE = 233340005;
		struct rescale_normal_enable__AttributeData
		{
			static const rescale_normal_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__rescale_normal_enable( const rescale_normal_enable__AttributeData& attributeData ){return true;}
		virtual bool end__rescale_normal_enable(){return true;}
	private:
		bool _begin__rescale_normal_enable( void* attributeData ){return begin__rescale_normal_enable(*static_cast<rescale_normal_enable__AttributeData*>(attributeData));}
		bool _data__rescale_normal_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rescale_normal_enable();

	public:
		static const StringHash HASH_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 47727685;
		static const StringHash HASH_ELEMENT_PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 173355765;
		struct sample_alpha_to_coverage_enable__AttributeData
		{
			static const sample_alpha_to_coverage_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__sample_alpha_to_coverage_enable( const sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
		virtual bool end__sample_alpha_to_coverage_enable(){return true;}
	private:
		bool _begin__sample_alpha_to_coverage_enable( void* attributeData ){return begin__sample_alpha_to_coverage_enable(*static_cast<sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
		bool _data__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sample_alpha_to_coverage_enable();

	public:
		static const StringHash HASH_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE = 251778565;
		static const StringHash HASH_ELEMENT_PASS__SAMPLE_ALPHA_TO_ONE_ENABLE = 103906693;
		struct sample_alpha_to_one_enable__AttributeData
		{
			static const sample_alpha_to_one_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__sample_alpha_to_one_enable( const sample_alpha_to_one_enable__AttributeData& attributeData ){return true;}
		virtual bool end__sample_alpha_to_one_enable(){return true;}
	private:
		bool _begin__sample_alpha_to_one_enable( void* attributeData ){return begin__sample_alpha_to_one_enable(*static_cast<sample_alpha_to_one_enable__AttributeData*>(attributeData));}
		bool _data__sample_alpha_to_one_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sample_alpha_to_one_enable();

	public:
		static const StringHash HASH_ELEMENT_SAMPLE_COVERAGE_ENABLE = 241354933;
		static const StringHash HASH_ELEMENT_PASS__SAMPLE_COVERAGE_ENABLE = 152395877;
		struct sample_coverage_enable__AttributeData
		{
			static const sample_coverage_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__sample_coverage_enable( const sample_coverage_enable__AttributeData& attributeData ){return true;}
		virtual bool end__sample_coverage_enable(){return true;}
	private:
		bool _begin__sample_coverage_enable( void* attributeData ){return begin__sample_coverage_enable(*static_cast<sample_coverage_enable__AttributeData*>(attributeData));}
		bool _data__sample_coverage_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sample_coverage_enable();

	public:
		static const StringHash HASH_ELEMENT_SCISSOR_TEST_ENABLE = 177084853;
		static const StringHash HASH_ELEMENT_PASS__SCISSOR_TEST_ENABLE = 218403029;
		struct scissor_test_enable__AttributeData
		{
			static const scissor_test_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__scissor_test_enable( const scissor_test_enable__AttributeData& attributeData ){return true;}
		virtual bool end__scissor_test_enable(){return true;}
	private:
		bool _begin__scissor_test_enable( void* attributeData ){return begin__scissor_test_enable(*static_cast<scissor_test_enable__AttributeData*>(attributeData));}
		bool _data__scissor_test_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scissor_test_enable();

	public:
		static const StringHash HASH_ELEMENT_STENCIL_TEST_ENABLE = 159579189;
		static const StringHash HASH_ELEMENT_PASS__STENCIL_TEST_ENABLE = 202141525;
		struct stencil_test_enable__AttributeData
		{
			static const stencil_test_enable__AttributeData DEFAULT;

			const ParserChar* value;
			const ParserChar* param;
		};
		virtual bool begin__stencil_test_enable( const stencil_test_enable__AttributeData& attributeData ){return true;}
		virtual bool end__stencil_test_enable(){return true;}
	private:
		bool _begin__stencil_test_enable( void* attributeData ){return begin__stencil_test_enable(*static_cast<stencil_test_enable__AttributeData*>(attributeData));}
		bool _data__stencil_test_enable( const ParserChar* text, size_t textLength );
		bool _validateBegin__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_test_enable();

	public:
		static const StringHash HASH_ELEMENT_PASS__EXTRA = 86667537;
		struct pass__extra__AttributeData
		{
			static const pass__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__pass__extra( const pass__extra__AttributeData& attributeData ){return true;}
		virtual bool end__pass__extra(){return true;}
	private:
		bool _begin__pass__extra( void* attributeData ){return begin__pass__extra(*static_cast<pass__extra__AttributeData*>(attributeData));}
		bool _data__pass__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__pass__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass__extra();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__EXTRA = 202103745;
		struct technique__extra__AttributeData
		{
			static const technique__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__technique__extra( const technique__extra__AttributeData& attributeData ){return true;}
		virtual bool end__technique__extra(){return true;}
	private:
		bool _begin__technique__extra( void* attributeData ){return begin__technique__extra(*static_cast<technique__extra__AttributeData*>(attributeData));}
		bool _data__technique__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__extra();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLES__EXTRA = 200483169;
		struct profile_GLES__extra__AttributeData
		{
			static const profile_GLES__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__profile_GLES__extra( const profile_GLES__extra__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLES__extra(){return true;}
	private:
		bool _begin__profile_GLES__extra( void* attributeData ){return begin__profile_GLES__extra(*static_cast<profile_GLES__extra__AttributeData*>(attributeData));}
		bool _data__profile_GLES__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLES__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__extra();

	public:
		static const StringHash HASH_ELEMENT_FX_PROFILE_ABSTRACT = 143616996;
		virtual bool begin__fx_profile_abstract(){return true;}
		virtual bool end__fx_profile_abstract(){return true;}
		virtual bool data__fx_profile_abstract( const void* data, size_t length ){return true;}
	private:
		bool _begin__fx_profile_abstract( void* attributeData ){return begin__fx_profile_abstract();}
		bool _data__fx_profile_abstract( const ParserChar* text, size_t textLength );
		bool _validateBegin__fx_profile_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fx_profile_abstract();

	public:
		static const StringHash HASH_ELEMENT_MESH = 474264;
		virtual bool begin__mesh(){return true;}
		virtual bool end__mesh(){return true;}
	private:
		bool _begin__mesh( void* attributeData ){return begin__mesh();}
		bool _data__mesh( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh();

	public:
		static const StringHash HASH_ELEMENT_MESH__SOURCE = 28989125;
		struct mesh__source__AttributeData
		{
			static const mesh__source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__mesh__source( const mesh__source__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__source(){return true;}
	private:
		bool _begin__mesh__source( void* attributeData ){return begin__mesh__source(*static_cast<mesh__source__AttributeData*>(attributeData));}
		bool _data__mesh__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__source();

	public:
		static const StringHash HASH_ELEMENT_VERTICES = 211484163;
		static const StringHash HASH_ELEMENT_MESH__VERTICES = 305203;
		struct mesh__vertices__AttributeData
		{
			static const mesh__vertices__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__mesh__vertices( const mesh__vertices__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__vertices(){return true;}
	private:
		bool _begin__mesh__vertices( void* attributeData ){return begin__mesh__vertices(*static_cast<mesh__vertices__AttributeData*>(attributeData));}
		bool _data__mesh__vertices( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__vertices();

	public:
		static const StringHash HASH_ELEMENT_VERTICES__INPUT = 250722196;
		struct vertices__input__AttributeData
		{
			static const vertices__input__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* source;
		};
		virtual bool begin__vertices__input( const vertices__input__AttributeData& attributeData ){return true;}
		virtual bool end__vertices__input(){return true;}
	private:
		bool _begin__vertices__input( void* attributeData ){return begin__vertices__input(*static_cast<vertices__input__AttributeData*>(attributeData));}
		bool _data__vertices__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertices__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertices__input();

	public:
		static const StringHash HASH_ELEMENT_VERTICES__EXTRA = 250813393;
		struct vertices__extra__AttributeData
		{
			static const vertices__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__vertices__extra( const vertices__extra__AttributeData& attributeData ){return true;}
		virtual bool end__vertices__extra(){return true;}
	private:
		bool _begin__vertices__extra( void* attributeData ){return begin__vertices__extra(*static_cast<vertices__extra__AttributeData*>(attributeData));}
		bool _data__vertices__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertices__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertices__extra();

	public:
		static const StringHash HASH_ELEMENT_LINES = 7537859;
		static const StringHash HASH_ELEMENT_MESH__LINES = 87117091;
		struct mesh__lines__AttributeData
		{
			static const mesh__lines__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__lines( const mesh__lines__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__lines(){return true;}
	private:
		bool _begin__mesh__lines( void* attributeData ){return begin__mesh__lines(*static_cast<mesh__lines__AttributeData*>(attributeData));}
		bool _data__mesh__lines( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__lines();

	public:
		static const StringHash HASH_ELEMENT_LINES__INPUT = 74455892;
		struct lines__input__AttributeData
		{
			static const lines__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__lines__input( const lines__input__AttributeData& attributeData ){return true;}
		virtual bool end__lines__input(){return true;}
	private:
		bool _begin__lines__input( void* attributeData ){return begin__lines__input(*static_cast<lines__input__AttributeData*>(attributeData));}
		bool _data__lines__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__lines__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines__input();

	public:
		static const StringHash HASH_ELEMENT_LINES__P = 5018704;
		virtual bool begin__lines__p(){return true;}
		virtual bool end__lines__p(){return true;}
		virtual bool data__lines__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__lines__p( void* attributeData ){return begin__lines__p();}
		bool _data__lines__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__lines__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines__p();

	public:
		static const StringHash HASH_ELEMENT_LINES__EXTRA = 74233617;
		struct lines__extra__AttributeData
		{
			static const lines__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__lines__extra( const lines__extra__AttributeData& attributeData ){return true;}
		virtual bool end__lines__extra(){return true;}
	private:
		bool _begin__lines__extra( void* attributeData ){return begin__lines__extra(*static_cast<lines__extra__AttributeData*>(attributeData));}
		bool _data__lines__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__lines__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines__extra();

	public:
		static const StringHash HASH_ELEMENT_LINESTRIPS = 212647987;
		static const StringHash HASH_ELEMENT_MESH__LINESTRIPS = 49849507;
		struct mesh__linestrips__AttributeData
		{
			static const mesh__linestrips__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__linestrips( const mesh__linestrips__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__linestrips(){return true;}
	private:
		bool _begin__mesh__linestrips( void* attributeData ){return begin__mesh__linestrips(*static_cast<mesh__linestrips__AttributeData*>(attributeData));}
		bool _data__mesh__linestrips( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__linestrips();

	public:
		static const StringHash HASH_ELEMENT_LINESTRIPS__INPUT = 261379220;
		struct linestrips__input__AttributeData
		{
			static const linestrips__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__linestrips__input( const linestrips__input__AttributeData& attributeData ){return true;}
		virtual bool end__linestrips__input(){return true;}
	private:
		bool _begin__linestrips__input( void* attributeData ){return begin__linestrips__input(*static_cast<linestrips__input__AttributeData*>(attributeData));}
		bool _data__linestrips__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__linestrips__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips__input();

	public:
		static const StringHash HASH_ELEMENT_LINESTRIPS__P = 201547680;
		virtual bool begin__linestrips__p(){return true;}
		virtual bool end__linestrips__p(){return true;}
		virtual bool data__linestrips__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__linestrips__p( void* attributeData ){return begin__linestrips__p();}
		bool _data__linestrips__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__linestrips__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips__p();

	public:
		static const StringHash HASH_ELEMENT_LINESTRIPS__EXTRA = 261159121;
		struct linestrips__extra__AttributeData
		{
			static const linestrips__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__linestrips__extra( const linestrips__extra__AttributeData& attributeData ){return true;}
		virtual bool end__linestrips__extra(){return true;}
	private:
		bool _begin__linestrips__extra( void* attributeData ){return begin__linestrips__extra(*static_cast<linestrips__extra__AttributeData*>(attributeData));}
		bool _data__linestrips__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__linestrips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips__extra();

	public:
		static const StringHash HASH_ELEMENT_POLYGONS = 104850211;
		static const StringHash HASH_ELEMENT_MESH__POLYGONS = 178361651;
		struct mesh__polygons__AttributeData
		{
			static const mesh__polygons__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__polygons( const mesh__polygons__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__polygons(){return true;}
	private:
		bool _begin__mesh__polygons( void* attributeData ){return begin__mesh__polygons(*static_cast<mesh__polygons__AttributeData*>(attributeData));}
		bool _data__mesh__polygons( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__polygons();

	public:
		static const StringHash HASH_ELEMENT_POLYGONS__INPUT = 144860468;
		struct polygons__input__AttributeData
		{
			static const polygons__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__polygons__input( const polygons__input__AttributeData& attributeData ){return true;}
		virtual bool end__polygons__input(){return true;}
	private:
		bool _begin__polygons__input( void* attributeData ){return begin__polygons__input(*static_cast<polygons__input__AttributeData*>(attributeData));}
		bool _data__polygons__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__polygons__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons__input();

	public:
		static const StringHash HASH_ELEMENT_POLYGONS__P = 238221456;
		virtual bool begin__polygons__p(){return true;}
		virtual bool end__polygons__p(){return true;}
		virtual bool data__polygons__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__polygons__p( void* attributeData ){return begin__polygons__p();}
		bool _data__polygons__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__polygons__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons__p();

	public:
		static const StringHash HASH_ELEMENT_PH = 1896;
		static const StringHash HASH_ELEMENT_POLYGONS__PH = 53447048;
		virtual bool begin__ph(){return true;}
		virtual bool end__ph(){return true;}
	private:
		bool _begin__ph( void* attributeData ){return begin__ph();}
		bool _data__ph( const ParserChar* text, size_t textLength );
		bool _validateBegin__ph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ph();

	public:
		static const StringHash HASH_ELEMENT_PH__P = 7791968;
		virtual bool begin__ph__p(){return true;}
		virtual bool end__ph__p(){return true;}
		virtual bool data__ph__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__ph__p( void* attributeData ){return begin__ph__p();}
		bool _data__ph__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__ph__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ph__p();

	public:
		static const StringHash HASH_ELEMENT_H = 104;
		static const StringHash HASH_ELEMENT_PH__H = 7791960;
		virtual bool begin__h(){return true;}
		virtual bool end__h(){return true;}
		virtual bool data__h( const void* data, size_t length ){return true;}
	private:
		bool _begin__h( void* attributeData ){return begin__h();}
		bool _data__h( const ParserChar* text, size_t textLength );
		bool _validateBegin__h( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__h();

	public:
		static const StringHash HASH_ELEMENT_POLYGONS__EXTRA = 144886129;
		struct polygons__extra__AttributeData
		{
			static const polygons__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__polygons__extra( const polygons__extra__AttributeData& attributeData ){return true;}
		virtual bool end__polygons__extra(){return true;}
	private:
		bool _begin__polygons__extra( void* attributeData ){return begin__polygons__extra(*static_cast<polygons__extra__AttributeData*>(attributeData));}
		bool _data__polygons__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__polygons__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons__extra();

	public:
		static const StringHash HASH_ELEMENT_POLYLIST = 104871892;
		static const StringHash HASH_ELEMENT_MESH__POLYLIST = 178422212;
		struct mesh__polylist__AttributeData
		{
			static const mesh__polylist__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__polylist( const mesh__polylist__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__polylist(){return true;}
	private:
		bool _begin__mesh__polylist( void* attributeData ){return begin__mesh__polylist(*static_cast<mesh__polylist__AttributeData*>(attributeData));}
		bool _data__mesh__polylist( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__polylist();

	public:
		static const StringHash HASH_ELEMENT_POLYLIST__INPUT = 22882756;
		struct polylist__input__AttributeData
		{
			static const polylist__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__polylist__input( const polylist__input__AttributeData& attributeData ){return true;}
		virtual bool end__polylist__input(){return true;}
	private:
		bool _begin__polylist__input( void* attributeData ){return begin__polylist__input(*static_cast<polylist__input__AttributeData*>(attributeData));}
		bool _data__polylist__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__polylist__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__input();

	public:
		static const StringHash HASH_ELEMENT_VCOUNT = 130706516;
		static const StringHash HASH_ELEMENT_POLYLIST__VCOUNT = 117410884;
		virtual bool begin__polylist__vcount(){return true;}
		virtual bool end__polylist__vcount(){return true;}
		virtual bool data__polylist__vcount( const void* data, size_t length ){return true;}
	private:
		bool _begin__polylist__vcount( void* attributeData ){return begin__polylist__vcount();}
		bool _data__polylist__vcount( const ParserChar* text, size_t textLength );
		bool _validateBegin__polylist__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__vcount();

	public:
		static const StringHash HASH_ELEMENT_POLYLIST__P = 58589536;
		virtual bool begin__polylist__p(){return true;}
		virtual bool end__polylist__p(){return true;}
		virtual bool data__polylist__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__polylist__p( void* attributeData ){return begin__polylist__p();}
		bool _data__polylist__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__polylist__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__p();

	public:
		static const StringHash HASH_ELEMENT_POLYLIST__EXTRA = 23037313;
		struct polylist__extra__AttributeData
		{
			static const polylist__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__polylist__extra( const polylist__extra__AttributeData& attributeData ){return true;}
		virtual bool end__polylist__extra(){return true;}
	private:
		bool _begin__polylist__extra( void* attributeData ){return begin__polylist__extra(*static_cast<polylist__extra__AttributeData*>(attributeData));}
		bool _data__polylist__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__polylist__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__extra();

	public:
		static const StringHash HASH_ELEMENT_TRIANGLES = 260356419;
		static const StringHash HASH_ELEMENT_MESH__TRIANGLES = 111270531;
		struct mesh__triangles__AttributeData
		{
			static const mesh__triangles__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__triangles( const mesh__triangles__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__triangles(){return true;}
	private:
		bool _begin__mesh__triangles( void* attributeData ){return begin__mesh__triangles(*static_cast<mesh__triangles__AttributeData*>(attributeData));}
		bool _data__mesh__triangles( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__triangles();

	public:
		static const StringHash HASH_ELEMENT_TRIANGLES__INPUT = 219530052;
		struct triangles__input__AttributeData
		{
			static const triangles__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__triangles__input( const triangles__input__AttributeData& attributeData ){return true;}
		virtual bool end__triangles__input(){return true;}
	private:
		bool _begin__triangles__input( void* attributeData ){return begin__triangles__input(*static_cast<triangles__input__AttributeData*>(attributeData));}
		bool _data__triangles__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__triangles__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles__input();

	public:
		static const StringHash HASH_ELEMENT_TRIANGLES__P = 194284832;
		virtual bool begin__triangles__p(){return true;}
		virtual bool end__triangles__p(){return true;}
		virtual bool data__triangles__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__triangles__p( void* attributeData ){return begin__triangles__p();}
		bool _data__triangles__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__triangles__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles__p();

	public:
		static const StringHash HASH_ELEMENT_TRIANGLES__EXTRA = 219639553;
		struct triangles__extra__AttributeData
		{
			static const triangles__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__triangles__extra( const triangles__extra__AttributeData& attributeData ){return true;}
		virtual bool end__triangles__extra(){return true;}
	private:
		bool _begin__triangles__extra( void* attributeData ){return begin__triangles__extra(*static_cast<triangles__extra__AttributeData*>(attributeData));}
		bool _data__triangles__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__triangles__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles__extra();

	public:
		static const StringHash HASH_ELEMENT_MESH__TRIFANS = 138814275;
		struct mesh__trifans__AttributeData
		{
			static const mesh__trifans__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__trifans( const mesh__trifans__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__trifans(){return true;}
	private:
		bool _begin__mesh__trifans( void* attributeData ){return begin__mesh__trifans(*static_cast<mesh__trifans__AttributeData*>(attributeData));}
		bool _data__mesh__trifans( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__trifans();

	public:
		static const StringHash HASH_ELEMENT_TRISTRIPS = 11275235;
		static const StringHash HASH_ELEMENT_MESH__TRISTRIPS = 156149795;
		struct mesh__tristrips__AttributeData
		{
			static const mesh__tristrips__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__mesh__tristrips( const mesh__tristrips__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__tristrips(){return true;}
	private:
		bool _begin__mesh__tristrips( void* attributeData ){return begin__mesh__tristrips(*static_cast<mesh__tristrips__AttributeData*>(attributeData));}
		bool _data__mesh__tristrips( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__tristrips();

	public:
		static const StringHash HASH_ELEMENT_TRISTRIPS__INPUT = 262203732;
		struct tristrips__input__AttributeData
		{
			static const tristrips__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__tristrips__input( const tristrips__input__AttributeData& attributeData ){return true;}
		virtual bool end__tristrips__input(){return true;}
	private:
		bool _begin__tristrips__input( void* attributeData ){return begin__tristrips__input(*static_cast<tristrips__input__AttributeData*>(attributeData));}
		bool _data__tristrips__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__tristrips__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips__input();

	public:
		static const StringHash HASH_ELEMENT_TRISTRIPS__P = 12492704;
		virtual bool begin__tristrips__p(){return true;}
		virtual bool end__tristrips__p(){return true;}
		virtual bool data__tristrips__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__tristrips__p( void* attributeData ){return begin__tristrips__p();}
		bool _data__tristrips__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__tristrips__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips__p();

	public:
		static const StringHash HASH_ELEMENT_TRISTRIPS__EXTRA = 261899537;
		struct tristrips__extra__AttributeData
		{
			static const tristrips__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__tristrips__extra( const tristrips__extra__AttributeData& attributeData ){return true;}
		virtual bool end__tristrips__extra(){return true;}
	private:
		bool _begin__tristrips__extra( void* attributeData ){return begin__tristrips__extra(*static_cast<tristrips__extra__AttributeData*>(attributeData));}
		bool _data__tristrips__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__tristrips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips__extra();

	public:
		static const StringHash HASH_ELEMENT_MESH__EXTRA = 86979169;
		struct mesh__extra__AttributeData
		{
			static const mesh__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__mesh__extra( const mesh__extra__AttributeData& attributeData ){return true;}
		virtual bool end__mesh__extra(){return true;}
	private:
		bool _begin__mesh__extra( void* attributeData ){return begin__mesh__extra(*static_cast<mesh__extra__AttributeData*>(attributeData));}
		bool _data__mesh__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__mesh__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__extra();

	public:
		struct lines__AttributeData
		{
			static const lines__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__lines( const lines__AttributeData& attributeData ){return true;}
		virtual bool end__lines(){return true;}
	private:
		bool _begin__lines( void* attributeData ){return begin__lines(*static_cast<lines__AttributeData*>(attributeData));}
		bool _data__lines( const ParserChar* text, size_t textLength );
		bool _validateBegin__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_NODE = 168885653;
		struct instance_node__AttributeData
		{
			static const instance_node__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_node( const instance_node__AttributeData& attributeData ){return true;}
		virtual bool end__instance_node(){return true;}
	private:
		bool _begin__instance_node( void* attributeData ){return begin__instance_node(*static_cast<instance_node__AttributeData*>(attributeData));}
		bool _data__instance_node( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_node();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_NODE__EXTRA = 106111633;
		struct instance_node__extra__AttributeData
		{
			static const instance_node__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_node__extra( const instance_node__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_node__extra(){return true;}
	private:
		bool _begin__instance_node__extra( void* attributeData ){return begin__instance_node__extra(*static_cast<instance_node__extra__AttributeData*>(attributeData));}
		bool _data__instance_node__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_node__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_node__extra();

	public:
		static const StringHash HASH_ELEMENT_VISUAL_SCENE = 129577413;
		struct visual_scene__AttributeData
		{
			static const visual_scene__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__visual_scene( const visual_scene__AttributeData& attributeData ){return true;}
		virtual bool end__visual_scene(){return true;}
	private:
		bool _begin__visual_scene( void* attributeData ){return begin__visual_scene(*static_cast<visual_scene__AttributeData*>(attributeData));}
		bool _data__visual_scene( const ParserChar* text, size_t textLength );
		bool _validateBegin__visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene();

	public:
		static const StringHash HASH_ELEMENT_VISUAL_SCENE__ASSET = 13350196;
		virtual bool begin__visual_scene__asset(){return true;}
		virtual bool end__visual_scene__asset(){return true;}
	private:
		bool _begin__visual_scene__asset( void* attributeData ){return begin__visual_scene__asset();}
		bool _data__visual_scene__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__visual_scene__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene__asset();

	public:
		static const StringHash HASH_ELEMENT_NODE = 480677;
		static const StringHash HASH_ELEMENT_VISUAL_SCENE__NODE = 252544101;
		static const StringHash HASH_ATTRIBUTE_LAYER = 7507906;
		struct visual_scene__node__AttributeData
		{
			static const visual_scene__node__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* sid;
			const ParserChar* type;
			const ParserChar* layer;
		};
		virtual bool begin__visual_scene__node( const visual_scene__node__AttributeData& attributeData ){return true;}
		virtual bool end__visual_scene__node(){return true;}
	private:
		bool _begin__visual_scene__node( void* attributeData ){return begin__visual_scene__node(*static_cast<visual_scene__node__AttributeData*>(attributeData));}
		bool _data__visual_scene__node( const ParserChar* text, size_t textLength );
		bool _validateBegin__visual_scene__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene__node();

	public:
		static const StringHash HASH_ELEMENT_NODE__ASSET = 86897524;
		virtual bool begin__node__asset(){return true;}
		virtual bool end__node__asset(){return true;}
	private:
		bool _begin__node__asset( void* attributeData ){return begin__node__asset();}
		bool _data__node__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__node__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__asset();

	public:
		static const StringHash HASH_ELEMENT_LOOKAT = 121004420;
		static const StringHash HASH_ELEMENT_NODE__LOOKAT = 58854100;
		struct lookat__AttributeData
		{
			static const lookat__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__lookat( const lookat__AttributeData& attributeData ){return true;}
		virtual bool end__lookat(){return true;}
		virtual bool data__lookat( const void* data, size_t length ){return true;}
	private:
		bool _begin__lookat( void* attributeData ){return begin__lookat(*static_cast<lookat__AttributeData*>(attributeData));}
		bool _data__lookat( const ParserChar* text, size_t textLength );
		bool _validateBegin__lookat( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lookat();

	public:
		static const StringHash HASH_ELEMENT_MATRIX = 121157896;
		static const StringHash HASH_ELEMENT_NODE__MATRIX = 57480280;
		struct matrix__AttributeData
		{
			static const matrix__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__matrix( const matrix__AttributeData& attributeData ){return true;}
		virtual bool end__matrix(){return true;}
		virtual bool data__matrix( const void* data, size_t length ){return true;}
	private:
		bool _begin__matrix( void* attributeData ){return begin__matrix(*static_cast<matrix__AttributeData*>(attributeData));}
		bool _data__matrix( const ParserChar* text, size_t textLength );
		bool _validateBegin__matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__matrix();

	public:
		static const StringHash HASH_ELEMENT_ROTATE = 127314085;
		static const StringHash HASH_ELEMENT_NODE__ROTATE = 31654901;
		struct node__rotate__AttributeData
		{
			static const node__rotate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__node__rotate( const node__rotate__AttributeData& attributeData ){return true;}
		virtual bool end__node__rotate(){return true;}
		virtual bool data__node__rotate( const void* data, size_t length ){return true;}
	private:
		bool _begin__node__rotate( void* attributeData ){return begin__node__rotate(*static_cast<node__rotate__AttributeData*>(attributeData));}
		bool _data__node__rotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__node__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__rotate();

	public:
		static const StringHash HASH_ELEMENT_SCALE = 7968805;
		static const StringHash HASH_ELEMENT_NODE__SCALE = 85773973;
		struct scale__AttributeData
		{
			static const scale__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__scale( const scale__AttributeData& attributeData ){return true;}
		virtual bool end__scale(){return true;}
		virtual bool data__scale( const void* data, size_t length ){return true;}
	private:
		bool _begin__scale( void* attributeData ){return begin__scale(*static_cast<scale__AttributeData*>(attributeData));}
		bool _data__scale( const ParserChar* text, size_t textLength );
		bool _validateBegin__scale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scale();

	public:
		static const StringHash HASH_ELEMENT_SKEW = 500167;
		static const StringHash HASH_ELEMENT_NODE__SKEW = 189912167;
		struct skew__AttributeData
		{
			static const skew__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__skew( const skew__AttributeData& attributeData ){return true;}
		virtual bool end__skew(){return true;}
		virtual bool data__skew( const void* data, size_t length ){return true;}
	private:
		bool _begin__skew( void* attributeData ){return begin__skew(*static_cast<skew__AttributeData*>(attributeData));}
		bool _data__skew( const ParserChar* text, size_t textLength );
		bool _validateBegin__skew( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skew();

	public:
		static const StringHash HASH_ELEMENT_TRANSLATE = 140137253;
		static const StringHash HASH_ELEMENT_NODE__TRANSLATE = 250426997;
		struct node__translate__AttributeData
		{
			static const node__translate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__node__translate( const node__translate__AttributeData& attributeData ){return true;}
		virtual bool end__node__translate(){return true;}
		virtual bool data__node__translate( const void* data, size_t length ){return true;}
	private:
		bool _begin__node__translate( void* attributeData ){return begin__node__translate(*static_cast<node__translate__AttributeData*>(attributeData));}
		bool _data__node__translate( const ParserChar* text, size_t textLength );
		bool _validateBegin__node__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__translate();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_CAMERA = 255854209;
		static const StringHash HASH_ELEMENT_NODE__INSTANCE_CAMERA = 92626481;
		struct instance_camera__AttributeData
		{
			static const instance_camera__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_camera( const instance_camera__AttributeData& attributeData ){return true;}
		virtual bool end__instance_camera(){return true;}
	private:
		bool _begin__instance_camera( void* attributeData ){return begin__instance_camera(*static_cast<instance_camera__AttributeData*>(attributeData));}
		bool _data__instance_camera( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_camera();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_CAMERA__EXTRA = 22844193;
		struct instance_camera__extra__AttributeData
		{
			static const instance_camera__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_camera__extra( const instance_camera__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_camera__extra(){return true;}
	private:
		bool _begin__instance_camera__extra( void* attributeData ){return begin__instance_camera__extra(*static_cast<instance_camera__extra__AttributeData*>(attributeData));}
		bool _data__instance_camera__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_camera__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_camera__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER = 26967202;
		static const StringHash HASH_ELEMENT_NODE__INSTANCE_CONTROLLER = 155305458;
		struct instance_controller__AttributeData
		{
			static const instance_controller__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_controller( const instance_controller__AttributeData& attributeData ){return true;}
		virtual bool end__instance_controller(){return true;}
	private:
		bool _begin__instance_controller( void* attributeData ){return begin__instance_controller(*static_cast<instance_controller__AttributeData*>(attributeData));}
		bool _data__instance_controller( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_controller();

	public:
		static const StringHash HASH_ELEMENT_SKELETON = 29544190;
		static const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__SKELETON = 220539054;
		virtual bool begin__skeleton(){return true;}
		virtual bool end__skeleton(){return true;}
		virtual bool data__skeleton( const void* data, size_t length ){return true;}
	private:
		bool _begin__skeleton( void* attributeData ){return begin__skeleton();}
		bool _data__skeleton( const ParserChar* text, size_t textLength );
		bool _validateBegin__skeleton( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skeleton();

	public:
		static const StringHash HASH_ELEMENT_BIND_MATERIAL = 27797804;
		static const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__BIND_MATERIAL = 132281260;
		virtual bool begin__instance_controller__bind_material(){return true;}
		virtual bool end__instance_controller__bind_material(){return true;}
	private:
		bool _begin__instance_controller__bind_material( void* attributeData ){return begin__instance_controller__bind_material();}
		bool _data__instance_controller__bind_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_controller__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_controller__bind_material();

	public:
		static const StringHash HASH_ELEMENT_BIND_MATERIAL__PARAM = 266607469;
		struct bind_material__param__AttributeData
		{
			static const bind_material__param__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* sid;
			const ParserChar* semantic;
			const ParserChar* type;
		};
		virtual bool begin__bind_material__param( const bind_material__param__AttributeData& attributeData ){return true;}
		virtual bool end__bind_material__param(){return true;}
		virtual bool data__bind_material__param( const void* data, size_t length ){return true;}
	private:
		bool _begin__bind_material__param( void* attributeData ){return begin__bind_material__param(*static_cast<bind_material__param__AttributeData*>(attributeData));}
		bool _data__bind_material__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_material__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__param();

	public:
		static const StringHash HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON = 90983294;
		virtual bool begin__bind_material__technique_common(){return true;}
		virtual bool end__bind_material__technique_common(){return true;}
	private:
		bool _begin__bind_material__technique_common( void* attributeData ){return begin__bind_material__technique_common();}
		bool _data__bind_material__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__technique_common();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_MATERIAL = 9871340;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_MATERIAL = 109789516;
		static const StringHash HASH_ATTRIBUTE_SYMBOL = 128989532;
		struct instance_material__AttributeData
		{
			static const instance_material__AttributeData DEFAULT;

			const ParserChar* symbol;
			const ParserChar* target;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_material( const instance_material__AttributeData& attributeData ){return true;}
		virtual bool end__instance_material(){return true;}
	private:
		bool _begin__instance_material( void* attributeData ){return begin__instance_material(*static_cast<instance_material__AttributeData*>(attributeData));}
		bool _data__instance_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_material();

	public:
		static const StringHash HASH_ELEMENT_BIND = 430148;
		static const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__BIND = 48435636;
		struct instance_material__bind__AttributeData
		{
			static const instance_material__bind__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* target;
		};
		virtual bool begin__instance_material__bind( const instance_material__bind__AttributeData& attributeData ){return true;}
		virtual bool end__instance_material__bind(){return true;}
	private:
		bool _begin__instance_material__bind( void* attributeData ){return begin__instance_material__bind(*static_cast<instance_material__bind__AttributeData*>(attributeData));}
		bool _data__instance_material__bind( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_material__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_material__bind();

	public:
		static const StringHash HASH_ELEMENT_BIND_VERTEX_INPUT = 217827748;
		static const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__BIND_VERTEX_INPUT = 111400644;
		static const StringHash HASH_ATTRIBUTE_INPUT_SEMANTIC = 256703331;
		static const StringHash HASH_ATTRIBUTE_INPUT_SET = 130685332;
		struct bind_vertex_input__AttributeData
		{
			static const bind_vertex_input__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* input_semantic;
			const ParserChar* input_set;
		};
		virtual bool begin__bind_vertex_input( const bind_vertex_input__AttributeData& attributeData ){return true;}
		virtual bool end__bind_vertex_input(){return true;}
	private:
		bool _begin__bind_vertex_input( void* attributeData ){return begin__bind_vertex_input(*static_cast<bind_vertex_input__AttributeData*>(attributeData));}
		bool _data__bind_vertex_input( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_vertex_input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_vertex_input();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__EXTRA = 238355617;
		struct instance_material__extra__AttributeData
		{
			static const instance_material__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_material__extra( const instance_material__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_material__extra(){return true;}
	private:
		bool _begin__instance_material__extra( void* attributeData ){return begin__instance_material__extra(*static_cast<instance_material__extra__AttributeData*>(attributeData));}
		bool _data__instance_material__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_material__extra();

	public:
		static const StringHash HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE = 185393301;
		struct bind_material__technique__AttributeData
		{
			static const bind_material__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__bind_material__technique( const bind_material__technique__AttributeData& attributeData ){return true;}
		virtual bool end__bind_material__technique(){return true;}
	private:
		bool _begin__bind_material__technique( void* attributeData ){return begin__bind_material__technique(*static_cast<bind_material__technique__AttributeData*>(attributeData));}
		bool _data__bind_material__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_material__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__technique();

	public:
		static const StringHash HASH_ELEMENT_BIND_MATERIAL__EXTRA = 266234001;
		struct bind_material__extra__AttributeData
		{
			static const bind_material__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__bind_material__extra( const bind_material__extra__AttributeData& attributeData ){return true;}
		virtual bool end__bind_material__extra(){return true;}
	private:
		bool _begin__bind_material__extra( void* attributeData ){return begin__bind_material__extra(*static_cast<bind_material__extra__AttributeData*>(attributeData));}
		bool _data__bind_material__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__EXTRA = 250294769;
		struct instance_controller__extra__AttributeData
		{
			static const instance_controller__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_controller__extra( const instance_controller__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_controller__extra(){return true;}
	private:
		bool _begin__instance_controller__extra( void* attributeData ){return begin__instance_controller__extra(*static_cast<instance_controller__extra__AttributeData*>(attributeData));}
		bool _data__instance_controller__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_controller__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_controller__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY = 75089129;
		static const StringHash HASH_ELEMENT_NODE__INSTANCE_GEOMETRY = 155287129;
		struct node__instance_geometry__AttributeData
		{
			static const node__instance_geometry__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__node__instance_geometry( const node__instance_geometry__AttributeData& attributeData ){return true;}
		virtual bool end__node__instance_geometry(){return true;}
	private:
		bool _begin__node__instance_geometry( void* attributeData ){return begin__node__instance_geometry(*static_cast<node__instance_geometry__AttributeData*>(attributeData));}
		bool _data__node__instance_geometry( const ParserChar* text, size_t textLength );
		bool _validateBegin__node__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__instance_geometry();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY__BIND_MATERIAL = 208059788;
		virtual bool begin__instance_geometry__bind_material(){return true;}
		virtual bool end__instance_geometry__bind_material(){return true;}
	private:
		bool _begin__instance_geometry__bind_material( void* attributeData ){return begin__instance_geometry__bind_material();}
		bool _data__instance_geometry__bind_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_geometry__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_geometry__bind_material();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY__EXTRA = 79738161;
		struct instance_geometry__extra__AttributeData
		{
			static const instance_geometry__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_geometry__extra( const instance_geometry__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_geometry__extra(){return true;}
	private:
		bool _begin__instance_geometry__extra( void* attributeData ){return begin__instance_geometry__extra(*static_cast<instance_geometry__extra__AttributeData*>(attributeData));}
		bool _data__instance_geometry__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_geometry__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_geometry__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_LIGHT = 17333844;
		static const StringHash HASH_ELEMENT_NODE__INSTANCE_LIGHT = 191089620;
		struct instance_light__AttributeData
		{
			static const instance_light__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_light( const instance_light__AttributeData& attributeData ){return true;}
		virtual bool end__instance_light(){return true;}
	private:
		bool _begin__instance_light( void* attributeData ){return begin__instance_light(*static_cast<instance_light__AttributeData*>(attributeData));}
		bool _data__instance_light( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_light();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_LIGHT__EXTRA = 98246161;
		struct instance_light__extra__AttributeData
		{
			static const instance_light__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_light__extra( const instance_light__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_light__extra(){return true;}
	private:
		bool _begin__instance_light__extra( void* attributeData ){return begin__instance_light__extra(*static_cast<instance_light__extra__AttributeData*>(attributeData));}
		bool _data__instance_light__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_light__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_light__extra();

	public:
		static const StringHash HASH_ELEMENT_NODE__EXTRA = 86614321;
		struct node__extra__AttributeData
		{
			static const node__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__node__extra( const node__extra__AttributeData& attributeData ){return true;}
		virtual bool end__node__extra(){return true;}
	private:
		bool _begin__node__extra( void* attributeData ){return begin__node__extra(*static_cast<node__extra__AttributeData*>(attributeData));}
		bool _data__node__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__node__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__extra();

	public:
		static const StringHash HASH_ELEMENT_EVALUATE_SCENE = 132785701;
		static const StringHash HASH_ELEMENT_VISUAL_SCENE__EVALUATE_SCENE = 145043477;
		struct evaluate_scene__AttributeData
		{
			static const evaluate_scene__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__evaluate_scene( const evaluate_scene__AttributeData& attributeData ){return true;}
		virtual bool end__evaluate_scene(){return true;}
	private:
		bool _begin__evaluate_scene( void* attributeData ){return begin__evaluate_scene(*static_cast<evaluate_scene__AttributeData*>(attributeData));}
		bool _data__evaluate_scene( const ParserChar* text, size_t textLength );
		bool _validateBegin__evaluate_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__evaluate_scene();

	public:
		static const StringHash HASH_ELEMENT_RENDER = 126634690;
		static const StringHash HASH_ELEMENT_EVALUATE_SCENE__RENDER = 212755570;
		static const StringHash HASH_ATTRIBUTE_CAMERA_NODE = 136173157;
		struct render__AttributeData
		{
			static const render__AttributeData DEFAULT;

			const ParserChar* camera_node;
		};
		virtual bool begin__render( const render__AttributeData& attributeData ){return true;}
		virtual bool end__render(){return true;}
	private:
		bool _begin__render( void* attributeData ){return begin__render(*static_cast<render__AttributeData*>(attributeData));}
		bool _data__render( const ParserChar* text, size_t textLength );
		bool _validateBegin__render( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__render();

	public:
		static const StringHash HASH_ELEMENT_LAYER = 7507906;
		static const StringHash HASH_ELEMENT_RENDER__LAYER = 228991954;
		virtual bool begin__layer(){return true;}
		virtual bool end__layer(){return true;}
		virtual bool data__layer( const void* data, size_t length ){return true;}
	private:
		bool _begin__layer( void* attributeData ){return begin__layer();}
		bool _data__layer( const ParserChar* text, size_t textLength );
		bool _validateBegin__layer( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__layer();

	public:
		static const StringHash HASH_ELEMENT_RENDER__INSTANCE_EFFECT = 50798276;
		struct render__instance_effect__AttributeData
		{
			static const render__instance_effect__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__render__instance_effect( const render__instance_effect__AttributeData& attributeData ){return true;}
		virtual bool end__render__instance_effect(){return true;}
	private:
		bool _begin__render__instance_effect( void* attributeData ){return begin__render__instance_effect(*static_cast<render__instance_effect__AttributeData*>(attributeData));}
		bool _data__render__instance_effect( const ParserChar* text, size_t textLength );
		bool _validateBegin__render__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__render__instance_effect();

	public:
		static const StringHash HASH_ELEMENT_VISUAL_SCENE__EXTRA = 13625201;
		struct visual_scene__extra__AttributeData
		{
			static const visual_scene__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__visual_scene__extra( const visual_scene__extra__AttributeData& attributeData ){return true;}
		virtual bool end__visual_scene__extra(){return true;}
	private:
		bool _begin__visual_scene__extra( void* attributeData ){return begin__visual_scene__extra(*static_cast<visual_scene__extra__AttributeData*>(attributeData));}
		bool _data__visual_scene__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__visual_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene__extra();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL = 145524812;
		struct material__AttributeData
		{
			static const material__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__material( const material__AttributeData& attributeData ){return true;}
		virtual bool end__material(){return true;}
	private:
		bool _begin__material( void* attributeData ){return begin__material(*static_cast<material__AttributeData*>(attributeData));}
		bool _data__material( const ParserChar* text, size_t textLength );
		bool _validateBegin__material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL__ASSET = 261106788;
		virtual bool begin__material__asset(){return true;}
		virtual bool end__material__asset(){return true;}
	private:
		bool _begin__material__asset( void* attributeData ){return begin__material__asset();}
		bool _data__material__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__material__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material__asset();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL__INSTANCE_EFFECT = 179640868;
		struct material__instance_effect__AttributeData
		{
			static const material__instance_effect__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__material__instance_effect( const material__instance_effect__AttributeData& attributeData ){return true;}
		virtual bool end__material__instance_effect(){return true;}
	private:
		bool _begin__material__instance_effect( void* attributeData ){return begin__material__instance_effect(*static_cast<material__instance_effect__AttributeData*>(attributeData));}
		bool _data__material__instance_effect( const ParserChar* text, size_t textLength );
		bool _validateBegin__material__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material__instance_effect();

	public:
		static const StringHash HASH_ELEMENT_MATERIAL__EXTRA = 261389857;
		struct material__extra__AttributeData
		{
			static const material__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__material__extra( const material__extra__AttributeData& attributeData ){return true;}
		virtual bool end__material__extra(){return true;}
	private:
		bool _begin__material__extra( void* attributeData ){return begin__material__extra(*static_cast<material__extra__AttributeData*>(attributeData));}
		bool _data__material__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material__extra();

	public:
		static const StringHash HASH_ELEMENT_CAPSULE = 159886405;
		virtual bool begin__capsule(){return true;}
		virtual bool end__capsule(){return true;}
	private:
		bool _begin__capsule( void* attributeData ){return begin__capsule();}
		bool _data__capsule( const ParserChar* text, size_t textLength );
		bool _validateBegin__capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule();

	public:
		static const StringHash HASH_ELEMENT_HEIGHT = 116129268;
		static const StringHash HASH_ELEMENT_CAPSULE__HEIGHT = 38254884;
		virtual bool begin__capsule__height(){return true;}
		virtual bool end__capsule__height(){return true;}
		virtual bool data__capsule__height( const void* data, size_t length ){return true;}
	private:
		bool _begin__capsule__height( void* attributeData ){return begin__capsule__height();}
		bool _data__capsule__height( const ParserChar* text, size_t textLength );
		bool _validateBegin__capsule__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule__height();

	public:
		static const StringHash HASH_ELEMENT_RADIUS = 126333123;
		static const StringHash HASH_ELEMENT_CAPSULE__RADIUS = 19657747;
		virtual bool begin__capsule__radius(){return true;}
		virtual bool end__capsule__radius(){return true;}
		virtual bool data__capsule__radius( const void* data, size_t length ){return true;}
	private:
		bool _begin__capsule__radius( void* attributeData ){return begin__capsule__radius();}
		bool _data__capsule__radius( const ParserChar* text, size_t textLength );
		bool _validateBegin__capsule__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule__radius();

	public:
		static const StringHash HASH_ELEMENT_CAPSULE__EXTRA = 220610497;
		struct capsule__extra__AttributeData
		{
			static const capsule__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__capsule__extra( const capsule__extra__AttributeData& attributeData ){return true;}
		virtual bool end__capsule__extra(){return true;}
	private:
		bool _begin__capsule__extra( void* attributeData ){return begin__capsule__extra(*static_cast<capsule__extra__AttributeData*>(attributeData));}
		bool _data__capsule__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__capsule__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule__extra();

	public:
		virtual bool begin__p(){return true;}
		virtual bool end__p(){return true;}
		virtual bool data__p( const void* data, size_t length ){return true;}
	private:
		bool _begin__p( void* attributeData ){return begin__p();}
		bool _data__p( const ParserChar* text, size_t textLength );
		bool _validateBegin__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__p();

	public:
		static const StringHash HASH_ELEMENT_ELLIPSOID = 50858436;
		virtual bool begin__ellipsoid(){return true;}
		virtual bool end__ellipsoid(){return true;}
	private:
		bool _begin__ellipsoid( void* attributeData ){return begin__ellipsoid();}
		bool _data__ellipsoid( const ParserChar* text, size_t textLength );
		bool _validateBegin__ellipsoid( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ellipsoid();

	public:
		static const StringHash HASH_ELEMENT_ELLIPSOID__SIZE = 190753477;
		virtual bool begin__ellipsoid__size(){return true;}
		virtual bool end__ellipsoid__size(){return true;}
		virtual bool data__ellipsoid__size( const void* data, size_t length ){return true;}
	private:
		bool _begin__ellipsoid__size( void* attributeData ){return begin__ellipsoid__size();}
		bool _data__ellipsoid__size( const ParserChar* text, size_t textLength );
		bool _validateBegin__ellipsoid__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ellipsoid__size();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES = 236889923;
		struct library_physics_scenes__AttributeData
		{
			static const library_physics_scenes__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_physics_scenes( const library_physics_scenes__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_scenes(){return true;}
	private:
		bool _begin__library_physics_scenes( void* attributeData ){return begin__library_physics_scenes(*static_cast<library_physics_scenes__AttributeData*>(attributeData));}
		bool _data__library_physics_scenes( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_scenes();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__ASSET = 112385460;
		virtual bool begin__library_physics_scenes__asset(){return true;}
		virtual bool end__library_physics_scenes__asset(){return true;}
	private:
		bool _begin__library_physics_scenes__asset( void* attributeData ){return begin__library_physics_scenes__asset();}
		bool _data__library_physics_scenes__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_scenes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_scenes__asset();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE = 6882725;
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__PHYSICS_SCENE = 100496229;
		struct physics_scene__AttributeData
		{
			static const physics_scene__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__physics_scene( const physics_scene__AttributeData& attributeData ){return true;}
		virtual bool end__physics_scene(){return true;}
	private:
		bool _begin__physics_scene( void* attributeData ){return begin__physics_scene(*static_cast<physics_scene__AttributeData*>(attributeData));}
		bool _data__physics_scene( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE__ASSET = 63501172;
		virtual bool begin__physics_scene__asset(){return true;}
		virtual bool end__physics_scene__asset(){return true;}
	private:
		bool _begin__physics_scene__asset( void* attributeData ){return begin__physics_scene__asset();}
		bool _data__physics_scene__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__asset();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD = 195760404;
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD = 33737508;
		struct physics_scene__instance_force_field__AttributeData
		{
			static const physics_scene__instance_force_field__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__physics_scene__instance_force_field( const physics_scene__instance_force_field__AttributeData& attributeData ){return true;}
		virtual bool end__physics_scene__instance_force_field(){return true;}
	private:
		bool _begin__physics_scene__instance_force_field( void* attributeData ){return begin__physics_scene__instance_force_field(*static_cast<physics_scene__instance_force_field__AttributeData*>(attributeData));}
		bool _data__physics_scene__instance_force_field( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__instance_force_field();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA = 267250353;
		struct instance_force_field__extra__AttributeData
		{
			static const instance_force_field__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_force_field__extra( const instance_force_field__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_force_field__extra(){return true;}
	private:
		bool _begin__instance_force_field__extra( void* attributeData ){return begin__instance_force_field__extra(*static_cast<instance_force_field__extra__AttributeData*>(attributeData));}
		bool _data__instance_force_field__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_force_field__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_force_field__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL = 98657756;
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL = 16473708;
		static const StringHash HASH_ATTRIBUTE_PARENT = 124292180;
		struct physics_scene__instance_physics_model__AttributeData
		{
			static const physics_scene__instance_physics_model__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
			const ParserChar* parent;
		};
		virtual bool begin__physics_scene__instance_physics_model( const physics_scene__instance_physics_model__AttributeData& attributeData ){return true;}
		virtual bool end__physics_scene__instance_physics_model(){return true;}
	private:
		bool _begin__physics_scene__instance_physics_model( void* attributeData ){return begin__physics_scene__instance_physics_model(*static_cast<physics_scene__instance_physics_model__AttributeData*>(attributeData));}
		bool _data__physics_scene__instance_physics_model( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__instance_physics_model();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD = 38290564;
		struct instance_physics_model__instance_force_field__AttributeData
		{
			static const instance_physics_model__instance_force_field__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_physics_model__instance_force_field( const instance_physics_model__instance_force_field__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_model__instance_force_field(){return true;}
	private:
		bool _begin__instance_physics_model__instance_force_field( void* attributeData ){return begin__instance_physics_model__instance_force_field(*static_cast<instance_physics_model__instance_force_field__AttributeData*>(attributeData));}
		bool _data__instance_physics_model__instance_force_field( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_model__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_model__instance_force_field();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY = 95007321;
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_BODY = 204998505;
		static const StringHash HASH_ATTRIBUTE_BODY = 431545;
		struct instance_rigid_body__AttributeData
		{
			static const instance_rigid_body__AttributeData DEFAULT;

			const ParserChar* body;
			const ParserChar* sid;
			const ParserChar* name;
			const ParserChar* target;
		};
		virtual bool begin__instance_rigid_body( const instance_rigid_body__AttributeData& attributeData ){return true;}
		virtual bool end__instance_rigid_body(){return true;}
	private:
		bool _begin__instance_rigid_body( void* attributeData ){return begin__instance_rigid_body(*static_cast<instance_rigid_body__AttributeData*>(attributeData));}
		bool _data__instance_rigid_body( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON = 107721262;
		virtual bool begin__instance_rigid_body__technique_common(){return true;}
		virtual bool end__instance_rigid_body__technique_common(){return true;}
	private:
		bool _begin__instance_rigid_body__technique_common( void* attributeData ){return begin__instance_rigid_body__technique_common();}
		bool _data__instance_rigid_body__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body__technique_common();

	public:
		static const StringHash HASH_ELEMENT_ANGULAR_VELOCITY = 135963289;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ANGULAR_VELOCITY = 180078265;
		virtual bool begin__angular_velocity(){return true;}
		virtual bool end__angular_velocity(){return true;}
		virtual bool data__angular_velocity( const void* data, size_t length ){return true;}
	private:
		bool _begin__angular_velocity( void* attributeData ){return begin__angular_velocity();}
		bool _data__angular_velocity( const ParserChar* text, size_t textLength );
		bool _validateBegin__angular_velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular_velocity();

	public:
		static const StringHash HASH_ELEMENT_VELOCITY = 204842873;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__VELOCITY = 2049353;
		virtual bool begin__velocity(){return true;}
		virtual bool end__velocity(){return true;}
		virtual bool data__velocity( const void* data, size_t length ){return true;}
	private:
		bool _begin__velocity( void* attributeData ){return begin__velocity();}
		bool _data__velocity( const ParserChar* text, size_t textLength );
		bool _validateBegin__velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__velocity();

	public:
		static const StringHash HASH_ELEMENT_DYNAMIC = 201622419;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DYNAMIC = 164030867;
		struct dynamic__AttributeData
		{
			static const dynamic__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__dynamic( const dynamic__AttributeData& attributeData ){return true;}
		virtual bool end__dynamic(){return true;}
		virtual bool data__dynamic( const void* data, size_t length ){return true;}
	private:
		bool _begin__dynamic( void* attributeData ){return begin__dynamic(*static_cast<dynamic__AttributeData*>(attributeData));}
		bool _data__dynamic( const ParserChar* text, size_t textLength );
		bool _validateBegin__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dynamic();

	public:
		static const StringHash HASH_ELEMENT_MASS = 473251;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS = 178723971;
		struct technique_common__mass__AttributeData
		{
			static const technique_common__mass__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__technique_common__mass( const technique_common__mass__AttributeData& attributeData ){return true;}
		virtual bool end__technique_common__mass(){return true;}
		virtual bool data__technique_common__mass( const void* data, size_t length ){return true;}
	private:
		bool _begin__technique_common__mass( void* attributeData ){return begin__technique_common__mass(*static_cast<technique_common__mass__AttributeData*>(attributeData));}
		bool _data__technique_common__mass( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique_common__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__mass();

	public:
		static const StringHash HASH_ELEMENT_MASS_FRAME = 156942485;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME = 66755765;
		virtual bool begin__mass_frame(){return true;}
		virtual bool end__mass_frame(){return true;}
	private:
		bool _begin__mass_frame( void* attributeData ){return begin__mass_frame();}
		bool _data__mass_frame( const ParserChar* text, size_t textLength );
		bool _validateBegin__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mass_frame();

	public:
		static const StringHash HASH_ELEMENT_MASS_FRAME__TRANSLATE = 253554469;
		struct mass_frame__translate__AttributeData
		{
			static const mass_frame__translate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__mass_frame__translate( const mass_frame__translate__AttributeData& attributeData ){return true;}
		virtual bool end__mass_frame__translate(){return true;}
		virtual bool data__mass_frame__translate( const void* data, size_t length ){return true;}
	private:
		bool _begin__mass_frame__translate( void* attributeData ){return begin__mass_frame__translate(*static_cast<mass_frame__translate__AttributeData*>(attributeData));}
		bool _data__mass_frame__translate( const ParserChar* text, size_t textLength );
		bool _validateBegin__mass_frame__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mass_frame__translate();

	public:
		static const StringHash HASH_ELEMENT_MASS_FRAME__ROTATE = 206978181;
		struct mass_frame__rotate__AttributeData
		{
			static const mass_frame__rotate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__mass_frame__rotate( const mass_frame__rotate__AttributeData& attributeData ){return true;}
		virtual bool end__mass_frame__rotate(){return true;}
		virtual bool data__mass_frame__rotate( const void* data, size_t length ){return true;}
	private:
		bool _begin__mass_frame__rotate( void* attributeData ){return begin__mass_frame__rotate(*static_cast<mass_frame__rotate__AttributeData*>(attributeData));}
		bool _data__mass_frame__rotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__mass_frame__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mass_frame__rotate();

	public:
		static const StringHash HASH_ELEMENT_INERTIA = 5020289;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INERTIA = 235810961;
		struct inertia__AttributeData
		{
			static const inertia__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__inertia( const inertia__AttributeData& attributeData ){return true;}
		virtual bool end__inertia(){return true;}
		virtual bool data__inertia( const void* data, size_t length ){return true;}
	private:
		bool _begin__inertia( void* attributeData ){return begin__inertia(*static_cast<inertia__AttributeData*>(attributeData));}
		bool _data__inertia( const ParserChar* text, size_t textLength );
		bool _validateBegin__inertia( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__inertia();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL = 190501244;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL = 110655340;
		struct technique_common__instance_physics_material__AttributeData
		{
			static const technique_common__instance_physics_material__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__technique_common__instance_physics_material( const technique_common__instance_physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__technique_common__instance_physics_material(){return true;}
	private:
		bool _begin__technique_common__instance_physics_material( void* attributeData ){return begin__technique_common__instance_physics_material(*static_cast<technique_common__instance_physics_material__AttributeData*>(attributeData));}
		bool _data__technique_common__instance_physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique_common__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__instance_physics_material();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA = 49406769;
		struct instance_physics_material__extra__AttributeData
		{
			static const instance_physics_material__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_physics_material__extra( const instance_physics_material__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_material__extra(){return true;}
	private:
		bool _begin__instance_physics_material__extra( void* attributeData ){return begin__instance_physics_material__extra(*static_cast<instance_physics_material__extra__AttributeData*>(attributeData));}
		bool _data__instance_physics_material__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_material__extra();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MATERIAL = 22186316;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL = 200496492;
		struct technique_common__physics_material__AttributeData
		{
			static const technique_common__physics_material__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__technique_common__physics_material( const technique_common__physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__technique_common__physics_material(){return true;}
	private:
		bool _begin__technique_common__physics_material( void* attributeData ){return begin__technique_common__physics_material(*static_cast<technique_common__physics_material__AttributeData*>(attributeData));}
		bool _data__technique_common__physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique_common__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__physics_material();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__ASSET = 40910036;
		virtual bool begin__physics_material__asset(){return true;}
		virtual bool end__physics_material__asset(){return true;}
	private:
		bool _begin__physics_material__asset( void* attributeData ){return begin__physics_material__asset();}
		bool _data__physics_material__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_material__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__asset();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON = 99789790;
		virtual bool begin__physics_material__technique_common(){return true;}
		virtual bool end__physics_material__technique_common(){return true;}
	private:
		bool _begin__physics_material__technique_common( void* attributeData ){return begin__physics_material__technique_common();}
		bool _data__physics_material__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__technique_common();

	public:
		static const StringHash HASH_ELEMENT_DYNAMIC_FRICTION = 12843982;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DYNAMIC_FRICTION = 107186158;
		struct dynamic_friction__AttributeData
		{
			static const dynamic_friction__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__dynamic_friction( const dynamic_friction__AttributeData& attributeData ){return true;}
		virtual bool end__dynamic_friction(){return true;}
		virtual bool data__dynamic_friction( const void* data, size_t length ){return true;}
	private:
		bool _begin__dynamic_friction( void* attributeData ){return begin__dynamic_friction(*static_cast<dynamic_friction__AttributeData*>(attributeData));}
		bool _data__dynamic_friction( const ParserChar* text, size_t textLength );
		bool _validateBegin__dynamic_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dynamic_friction();

	public:
		static const StringHash HASH_ELEMENT_RESTITUTION = 12871406;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__RESTITUTION = 182855758;
		struct restitution__AttributeData
		{
			static const restitution__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__restitution( const restitution__AttributeData& attributeData ){return true;}
		virtual bool end__restitution(){return true;}
		virtual bool data__restitution( const void* data, size_t length ){return true;}
	private:
		bool _begin__restitution( void* attributeData ){return begin__restitution(*static_cast<restitution__AttributeData*>(attributeData));}
		bool _data__restitution( const ParserChar* text, size_t textLength );
		bool _validateBegin__restitution( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__restitution();

	public:
		static const StringHash HASH_ELEMENT_STATIC_FRICTION = 4890926;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__STATIC_FRICTION = 50283374;
		struct static_friction__AttributeData
		{
			static const static_friction__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__static_friction( const static_friction__AttributeData& attributeData ){return true;}
		virtual bool end__static_friction(){return true;}
		virtual bool data__static_friction( const void* data, size_t length ){return true;}
	private:
		bool _begin__static_friction( void* attributeData ){return begin__static_friction(*static_cast<static_friction__AttributeData*>(attributeData));}
		bool _data__static_friction( const ParserChar* text, size_t textLength );
		bool _validateBegin__static_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__static_friction();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE = 218581653;
		struct physics_material__technique__AttributeData
		{
			static const physics_material__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__physics_material__technique( const physics_material__technique__AttributeData& attributeData ){return true;}
		virtual bool end__physics_material__technique(){return true;}
	private:
		bool _begin__physics_material__technique( void* attributeData ){return begin__physics_material__technique(*static_cast<physics_material__technique__AttributeData*>(attributeData));}
		bool _data__physics_material__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_material__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__technique();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__EXTRA = 41184913;
		struct physics_material__extra__AttributeData
		{
			static const physics_material__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__physics_material__extra( const physics_material__extra__AttributeData& attributeData ){return true;}
		virtual bool end__physics_material__extra(){return true;}
	private:
		bool _begin__physics_material__extra( void* attributeData ){return begin__physics_material__extra(*static_cast<physics_material__extra__AttributeData*>(attributeData));}
		bool _data__physics_material__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__extra();

	public:
		static const StringHash HASH_ELEMENT_SHAPE = 7989349;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SHAPE = 173779653;
		virtual bool begin__shape(){return true;}
		virtual bool end__shape(){return true;}
	private:
		bool _begin__shape( void* attributeData ){return begin__shape();}
		bool _data__shape( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape();

	public:
		static const StringHash HASH_ELEMENT_HOLLOW = 116798311;
		static const StringHash HASH_ELEMENT_SHAPE__HOLLOW = 203315751;
		struct hollow__AttributeData
		{
			static const hollow__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__hollow( const hollow__AttributeData& attributeData ){return true;}
		virtual bool end__hollow(){return true;}
		virtual bool data__hollow( const void* data, size_t length ){return true;}
	private:
		bool _begin__hollow( void* attributeData ){return begin__hollow(*static_cast<hollow__AttributeData*>(attributeData));}
		bool _data__hollow( const ParserChar* text, size_t textLength );
		bool _validateBegin__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__hollow();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__MASS = 189649091;
		struct shape__mass__AttributeData
		{
			static const shape__mass__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__shape__mass( const shape__mass__AttributeData& attributeData ){return true;}
		virtual bool end__shape__mass(){return true;}
		virtual bool data__shape__mass( const void* data, size_t length ){return true;}
	private:
		bool _begin__shape__mass( void* attributeData ){return begin__shape__mass(*static_cast<shape__mass__AttributeData*>(attributeData));}
		bool _data__shape__mass( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__mass();

	public:
		static const StringHash HASH_ELEMENT_DENSITY = 180723929;
		static const StringHash HASH_ELEMENT_SHAPE__DENSITY = 71513209;
		struct density__AttributeData
		{
			static const density__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__density( const density__AttributeData& attributeData ){return true;}
		virtual bool end__density(){return true;}
		virtual bool data__density( const void* data, size_t length ){return true;}
	private:
		bool _begin__density( void* attributeData ){return begin__density(*static_cast<density__AttributeData*>(attributeData));}
		bool _data__density( const ParserChar* text, size_t textLength );
		bool _validateBegin__density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__density();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__INSTANCE_PHYSICS_MATERIAL = 182289868;
		struct shape__instance_physics_material__AttributeData
		{
			static const shape__instance_physics_material__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__shape__instance_physics_material( const shape__instance_physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__shape__instance_physics_material(){return true;}
	private:
		bool _begin__shape__instance_physics_material( void* attributeData ){return begin__shape__instance_physics_material(*static_cast<shape__instance_physics_material__AttributeData*>(attributeData));}
		bool _data__shape__instance_physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__instance_physics_material();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__PHYSICS_MATERIAL = 169447724;
		struct shape__physics_material__AttributeData
		{
			static const shape__physics_material__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__shape__physics_material( const shape__physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__shape__physics_material(){return true;}
	private:
		bool _begin__shape__physics_material( void* attributeData ){return begin__shape__physics_material(*static_cast<shape__physics_material__AttributeData*>(attributeData));}
		bool _data__shape__physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__physics_material();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__INSTANCE_GEOMETRY = 15221321;
		struct shape__instance_geometry__AttributeData
		{
			static const shape__instance_geometry__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__shape__instance_geometry( const shape__instance_geometry__AttributeData& attributeData ){return true;}
		virtual bool end__shape__instance_geometry(){return true;}
	private:
		bool _begin__shape__instance_geometry( void* attributeData ){return begin__shape__instance_geometry(*static_cast<shape__instance_geometry__AttributeData*>(attributeData));}
		bool _data__shape__instance_geometry( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__instance_geometry();

	public:
		static const StringHash HASH_ELEMENT_PLANE = 7809093;
		static const StringHash HASH_ELEMENT_SHAPE__PLANE = 83469045;
		virtual bool begin__plane(){return true;}
		virtual bool end__plane(){return true;}
	private:
		bool _begin__plane( void* attributeData ){return begin__plane();}
		bool _data__plane( const ParserChar* text, size_t textLength );
		bool _validateBegin__plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__plane();

	public:
		static const StringHash HASH_ELEMENT_EQUATION = 146320030;
		static const StringHash HASH_ELEMENT_PLANE__EQUATION = 15986366;
		virtual bool begin__equation(){return true;}
		virtual bool end__equation(){return true;}
		virtual bool data__equation( const void* data, size_t length ){return true;}
	private:
		bool _begin__equation( void* attributeData ){return begin__equation();}
		bool _data__equation( const ParserChar* text, size_t textLength );
		bool _validateBegin__equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__equation();

	public:
		static const StringHash HASH_ELEMENT_PLANE__EXTRA = 70156081;
		struct plane__extra__AttributeData
		{
			static const plane__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__plane__extra( const plane__extra__AttributeData& attributeData ){return true;}
		virtual bool end__plane__extra(){return true;}
	private:
		bool _begin__plane__extra( void* attributeData ){return begin__plane__extra(*static_cast<plane__extra__AttributeData*>(attributeData));}
		bool _data__plane__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__plane__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__plane__extra();

	public:
		static const StringHash HASH_ELEMENT_BOX = 26984;
		static const StringHash HASH_ELEMENT_SHAPE__BOX = 112510952;
		virtual bool begin__box(){return true;}
		virtual bool end__box(){return true;}
	private:
		bool _begin__box( void* attributeData ){return begin__box();}
		bool _data__box( const ParserChar* text, size_t textLength );
		bool _validateBegin__box( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__box();

	public:
		static const StringHash HASH_ELEMENT_HALF_EXTENTS = 168995299;
		static const StringHash HASH_ELEMENT_BOX__HALF_EXTENTS = 158729139;
		virtual bool begin__half_extents(){return true;}
		virtual bool end__half_extents(){return true;}
		virtual bool data__half_extents( const void* data, size_t length ){return true;}
	private:
		bool _begin__half_extents( void* attributeData ){return begin__half_extents();}
		bool _data__half_extents( const ParserChar* text, size_t textLength );
		bool _validateBegin__half_extents( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__half_extents();

	public:
		static const StringHash HASH_ELEMENT_BOX__EXTRA = 89812321;
		struct box__extra__AttributeData
		{
			static const box__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__box__extra( const box__extra__AttributeData& attributeData ){return true;}
		virtual bool end__box__extra(){return true;}
	private:
		bool _begin__box__extra( void* attributeData ){return begin__box__extra(*static_cast<box__extra__AttributeData*>(attributeData));}
		bool _data__box__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__box__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__box__extra();

	public:
		static const StringHash HASH_ELEMENT_SPHERE = 128380037;
		static const StringHash HASH_ELEMENT_SHAPE__SPHERE = 256804805;
		virtual bool begin__sphere(){return true;}
		virtual bool end__sphere(){return true;}
	private:
		bool _begin__sphere( void* attributeData ){return begin__sphere();}
		bool _data__sphere( const ParserChar* text, size_t textLength );
		bool _validateBegin__sphere( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sphere();

	public:
		static const StringHash HASH_ELEMENT_SPHERE__RADIUS = 7028275;
		virtual bool begin__sphere__radius(){return true;}
		virtual bool end__sphere__radius(){return true;}
		virtual bool data__sphere__radius( const void* data, size_t length ){return true;}
	private:
		bool _begin__sphere__radius( void* attributeData ){return begin__sphere__radius();}
		bool _data__sphere__radius( const ParserChar* text, size_t textLength );
		bool _validateBegin__sphere__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sphere__radius();

	public:
		static const StringHash HASH_ELEMENT_SPHERE__EXTRA = 254948193;
		struct sphere__extra__AttributeData
		{
			static const sphere__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__sphere__extra( const sphere__extra__AttributeData& attributeData ){return true;}
		virtual bool end__sphere__extra(){return true;}
	private:
		bool _begin__sphere__extra( void* attributeData ){return begin__sphere__extra(*static_cast<sphere__extra__AttributeData*>(attributeData));}
		bool _data__sphere__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__sphere__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sphere__extra();

	public:
		static const StringHash HASH_ELEMENT_CYLINDER = 3165298;
		static const StringHash HASH_ELEMENT_SHAPE__CYLINDER = 138741378;
		virtual bool begin__cylinder(){return true;}
		virtual bool end__cylinder(){return true;}
	private:
		bool _begin__cylinder( void* attributeData ){return begin__cylinder();}
		bool _data__cylinder( const ParserChar* text, size_t textLength );
		bool _validateBegin__cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder();

	public:
		static const StringHash HASH_ELEMENT_CYLINDER__HEIGHT = 94864756;
		virtual bool begin__cylinder__height(){return true;}
		virtual bool end__cylinder__height(){return true;}
		virtual bool data__cylinder__height( const void* data, size_t length ){return true;}
	private:
		bool _begin__cylinder__height( void* attributeData ){return begin__cylinder__height();}
		bool _data__cylinder__height( const ParserChar* text, size_t textLength );
		bool _validateBegin__cylinder__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder__height();

	public:
		static const StringHash HASH_ELEMENT_CYLINDER__RADIUS = 114026563;
		virtual bool begin__cylinder__radius(){return true;}
		virtual bool end__cylinder__radius(){return true;}
		virtual bool data__cylinder__radius( const void* data, size_t length ){return true;}
	private:
		bool _begin__cylinder__radius( void* attributeData ){return begin__cylinder__radius();}
		bool _data__cylinder__radius( const ParserChar* text, size_t textLength );
		bool _validateBegin__cylinder__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder__radius();

	public:
		static const StringHash HASH_ELEMENT_CYLINDER__EXTRA = 140000257;
		struct cylinder__extra__AttributeData
		{
			static const cylinder__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__cylinder__extra( const cylinder__extra__AttributeData& attributeData ){return true;}
		virtual bool end__cylinder__extra(){return true;}
	private:
		bool _begin__cylinder__extra( void* attributeData ){return begin__cylinder__extra(*static_cast<cylinder__extra__AttributeData*>(attributeData));}
		bool _data__cylinder__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__cylinder__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder__extra();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CYLINDER = 77858562;
		static const StringHash HASH_ELEMENT_SHAPE__TAPERED_CYLINDER = 166506338;
		virtual bool begin__tapered_cylinder(){return true;}
		virtual bool end__tapered_cylinder(){return true;}
	private:
		bool _begin__tapered_cylinder( void* attributeData ){return begin__tapered_cylinder();}
		bool _data__tapered_cylinder( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CYLINDER__HEIGHT = 32307460;
		virtual bool begin__tapered_cylinder__height(){return true;}
		virtual bool end__tapered_cylinder__height(){return true;}
		virtual bool data__tapered_cylinder__height( const void* data, size_t length ){return true;}
	private:
		bool _begin__tapered_cylinder__height( void* attributeData ){return begin__tapered_cylinder__height();}
		bool _data__tapered_cylinder__height( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_cylinder__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__height();

	public:
		static const StringHash HASH_ELEMENT_RADIUS1 = 142281745;
		static const StringHash HASH_ELEMENT_TAPERED_CYLINDER__RADIUS1 = 134955841;
		virtual bool begin__tapered_cylinder__radius1(){return true;}
		virtual bool end__tapered_cylinder__radius1(){return true;}
		virtual bool data__tapered_cylinder__radius1( const void* data, size_t length ){return true;}
	private:
		bool _begin__tapered_cylinder__radius1( void* attributeData ){return begin__tapered_cylinder__radius1();}
		bool _data__tapered_cylinder__radius1( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_cylinder__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__radius1();

	public:
		static const StringHash HASH_ELEMENT_RADIUS2 = 142281746;
		static const StringHash HASH_ELEMENT_TAPERED_CYLINDER__RADIUS2 = 134955842;
		virtual bool begin__tapered_cylinder__radius2(){return true;}
		virtual bool end__tapered_cylinder__radius2(){return true;}
		virtual bool data__tapered_cylinder__radius2( const void* data, size_t length ){return true;}
	private:
		bool _begin__tapered_cylinder__radius2( void* attributeData ){return begin__tapered_cylinder__radius2();}
		bool _data__tapered_cylinder__radius2( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_cylinder__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__radius2();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CYLINDER__EXTRA = 253529025;
		struct tapered_cylinder__extra__AttributeData
		{
			static const tapered_cylinder__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__tapered_cylinder__extra( const tapered_cylinder__extra__AttributeData& attributeData ){return true;}
		virtual bool end__tapered_cylinder__extra(){return true;}
	private:
		bool _begin__tapered_cylinder__extra( void* attributeData ){return begin__tapered_cylinder__extra(*static_cast<tapered_cylinder__extra__AttributeData*>(attributeData));}
		bool _data__tapered_cylinder__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_cylinder__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__extra();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CAPSULE = 256864501;
		static const StringHash HASH_ELEMENT_SHAPE__TAPERED_CAPSULE = 167503477;
		virtual bool begin__tapered_capsule(){return true;}
		virtual bool end__tapered_capsule(){return true;}
	private:
		bool _begin__tapered_capsule( void* attributeData ){return begin__tapered_capsule();}
		bool _data__tapered_capsule( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CAPSULE__HEIGHT = 177933284;
		virtual bool begin__tapered_capsule__height(){return true;}
		virtual bool end__tapered_capsule__height(){return true;}
		virtual bool data__tapered_capsule__height( const void* data, size_t length ){return true;}
	private:
		bool _begin__tapered_capsule__height( void* attributeData ){return begin__tapered_capsule__height();}
		bool _data__tapered_capsule__height( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_capsule__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__height();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CAPSULE__RADIUS1 = 259419633;
		virtual bool begin__tapered_capsule__radius1(){return true;}
		virtual bool end__tapered_capsule__radius1(){return true;}
		virtual bool data__tapered_capsule__radius1( const void* data, size_t length ){return true;}
	private:
		bool _begin__tapered_capsule__radius1( void* attributeData ){return begin__tapered_capsule__radius1();}
		bool _data__tapered_capsule__radius1( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_capsule__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__radius1();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CAPSULE__RADIUS2 = 259419634;
		virtual bool begin__tapered_capsule__radius2(){return true;}
		virtual bool end__tapered_capsule__radius2(){return true;}
		virtual bool data__tapered_capsule__radius2( const void* data, size_t length ){return true;}
	private:
		bool _begin__tapered_capsule__radius2( void* attributeData ){return begin__tapered_capsule__radius2();}
		bool _data__tapered_capsule__radius2( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_capsule__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__radius2();

	public:
		static const StringHash HASH_ELEMENT_TAPERED_CAPSULE__EXTRA = 28046561;
		struct tapered_capsule__extra__AttributeData
		{
			static const tapered_capsule__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__tapered_capsule__extra( const tapered_capsule__extra__AttributeData& attributeData ){return true;}
		virtual bool end__tapered_capsule__extra(){return true;}
	private:
		bool _begin__tapered_capsule__extra( void* attributeData ){return begin__tapered_capsule__extra(*static_cast<tapered_capsule__extra__AttributeData*>(attributeData));}
		bool _data__tapered_capsule__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__tapered_capsule__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__extra();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__TRANSLATE = 49208741;
		struct shape__translate__AttributeData
		{
			static const shape__translate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__shape__translate( const shape__translate__AttributeData& attributeData ){return true;}
		virtual bool end__shape__translate(){return true;}
		virtual bool data__shape__translate( const void* data, size_t length ){return true;}
	private:
		bool _begin__shape__translate( void* attributeData ){return begin__shape__translate(*static_cast<shape__translate__AttributeData*>(attributeData));}
		bool _data__shape__translate( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__translate();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__ROTATE = 259965925;
		struct shape__rotate__AttributeData
		{
			static const shape__rotate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__shape__rotate( const shape__rotate__AttributeData& attributeData ){return true;}
		virtual bool end__shape__rotate(){return true;}
		virtual bool data__shape__rotate( const void* data, size_t length ){return true;}
	private:
		bool _begin__shape__rotate( void* attributeData ){return begin__shape__rotate(*static_cast<shape__rotate__AttributeData*>(attributeData));}
		bool _data__shape__rotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__rotate();

	public:
		static const StringHash HASH_ELEMENT_SHAPE__EXTRA = 79854897;
		struct shape__extra__AttributeData
		{
			static const shape__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__shape__extra( const shape__extra__AttributeData& attributeData ){return true;}
		virtual bool end__shape__extra(){return true;}
	private:
		bool _begin__shape__extra( void* attributeData ){return begin__shape__extra(*static_cast<shape__extra__AttributeData*>(attributeData));}
		bool _data__shape__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__shape__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE = 205322533;
		struct instance_rigid_body__technique__AttributeData
		{
			static const instance_rigid_body__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__instance_rigid_body__technique( const instance_rigid_body__technique__AttributeData& attributeData ){return true;}
		virtual bool end__instance_rigid_body__technique(){return true;}
	private:
		bool _begin__instance_rigid_body__technique( void* attributeData ){return begin__instance_rigid_body__technique(*static_cast<instance_rigid_body__technique__AttributeData*>(attributeData));}
		bool _data__instance_rigid_body__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_rigid_body__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body__technique();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__EXTRA = 264756801;
		struct instance_rigid_body__extra__AttributeData
		{
			static const instance_rigid_body__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_rigid_body__extra( const instance_rigid_body__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_rigid_body__extra(){return true;}
	private:
		bool _begin__instance_rigid_body__extra( void* attributeData ){return begin__instance_rigid_body__extra(*static_cast<instance_rigid_body__extra__AttributeData*>(attributeData));}
		bool _data__instance_rigid_body__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_rigid_body__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT = 252820964;
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_CONSTRAINT = 110069972;
		static const StringHash HASH_ATTRIBUTE_CONSTRAINT = 180279812;
		struct instance_rigid_constraint__AttributeData
		{
			static const instance_rigid_constraint__AttributeData DEFAULT;

			const ParserChar* constraint;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_rigid_constraint( const instance_rigid_constraint__AttributeData& attributeData ){return true;}
		virtual bool end__instance_rigid_constraint(){return true;}
	private:
		bool _begin__instance_rigid_constraint( void* attributeData ){return begin__instance_rigid_constraint(*static_cast<instance_rigid_constraint__AttributeData*>(attributeData));}
		bool _data__instance_rigid_constraint( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_constraint();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT__EXTRA = 105326065;
		struct instance_rigid_constraint__extra__AttributeData
		{
			static const instance_rigid_constraint__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_rigid_constraint__extra( const instance_rigid_constraint__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_rigid_constraint__extra(){return true;}
	private:
		bool _begin__instance_rigid_constraint__extra( void* attributeData ){return begin__instance_rigid_constraint__extra(*static_cast<instance_rigid_constraint__extra__AttributeData*>(attributeData));}
		bool _data__instance_rigid_constraint__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_rigid_constraint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_constraint__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA = 189441489;
		struct instance_physics_model__extra__AttributeData
		{
			static const instance_physics_model__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_physics_model__extra( const instance_physics_model__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_model__extra(){return true;}
	private:
		bool _begin__instance_physics_model__extra( void* attributeData ){return begin__instance_physics_model__extra(*static_cast<instance_physics_model__extra__AttributeData*>(attributeData));}
		bool _data__instance_physics_model__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_model__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_model__extra();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON = 53159934;
		virtual bool begin__physics_scene__technique_common(){return true;}
		virtual bool end__physics_scene__technique_common(){return true;}
	private:
		bool _begin__physics_scene__technique_common( void* attributeData ){return begin__physics_scene__technique_common();}
		bool _data__physics_scene__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__technique_common();

	public:
		static const StringHash HASH_ELEMENT_GRAVITY = 243847385;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__GRAVITY = 214596313;
		struct gravity__AttributeData
		{
			static const gravity__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__gravity( const gravity__AttributeData& attributeData ){return true;}
		virtual bool end__gravity(){return true;}
		virtual bool data__gravity( const void* data, size_t length ){return true;}
	private:
		bool _begin__gravity( void* attributeData ){return begin__gravity(*static_cast<gravity__AttributeData*>(attributeData));}
		bool _data__gravity( const ParserChar* text, size_t textLength );
		bool _validateBegin__gravity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__gravity();

	public:
		static const StringHash HASH_ELEMENT_TIME_STEP = 62312896;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__TIME_STEP = 18674176;
		struct time_step__AttributeData
		{
			static const time_step__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__time_step( const time_step__AttributeData& attributeData ){return true;}
		virtual bool end__time_step(){return true;}
		virtual bool data__time_step( const void* data, size_t length ){return true;}
	private:
		bool _begin__time_step( void* attributeData ){return begin__time_step(*static_cast<time_step__AttributeData*>(attributeData));}
		bool _data__time_step( const ParserChar* text, size_t textLength );
		bool _validateBegin__time_step( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__time_step();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE = 57209429;
		struct physics_scene__technique__AttributeData
		{
			static const physics_scene__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__physics_scene__technique( const physics_scene__technique__AttributeData& attributeData ){return true;}
		virtual bool end__physics_scene__technique(){return true;}
	private:
		bool _begin__physics_scene__technique( void* attributeData ){return begin__physics_scene__technique(*static_cast<physics_scene__technique__AttributeData*>(attributeData));}
		bool _data__physics_scene__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__technique();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_SCENE__EXTRA = 63742257;
		struct physics_scene__extra__AttributeData
		{
			static const physics_scene__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__physics_scene__extra( const physics_scene__extra__AttributeData& attributeData ){return true;}
		virtual bool end__physics_scene__extra(){return true;}
	private:
		bool _begin__physics_scene__extra( void* attributeData ){return begin__physics_scene__extra(*static_cast<physics_scene__extra__AttributeData*>(attributeData));}
		bool _data__physics_scene__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA = 112627697;
		struct library_physics_scenes__extra__AttributeData
		{
			static const library_physics_scenes__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_physics_scenes__extra( const library_physics_scenes__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_scenes__extra(){return true;}
	private:
		bool _begin__library_physics_scenes__extra( void* attributeData ){return begin__library_physics_scenes__extra(*static_cast<library_physics_scenes__extra__AttributeData*>(attributeData));}
		bool _data__library_physics_scenes__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_scenes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_scenes__extra();

	public:
		static const StringHash HASH_ELEMENT_COLLADA = 138479041;
		static const StringHash HASH_ATTRIBUTE_VERSION = 214540334;
		static const StringHash HASH_ATTRIBUTE_BASE = 428181;
		struct COLLADA__AttributeData
		{
			static const COLLADA__AttributeData DEFAULT;

			const ParserChar* version;
			const ParserChar* base;
		};
		virtual bool begin__COLLADA( const COLLADA__AttributeData& attributeData ){return true;}
		virtual bool end__COLLADA(){return true;}
	private:
		bool _begin__COLLADA( void* attributeData ){return begin__COLLADA(*static_cast<COLLADA__AttributeData*>(attributeData));}
		bool _data__COLLADA( const ParserChar* text, size_t textLength );
		bool _validateBegin__COLLADA( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__COLLADA();

	public:
		static const StringHash HASH_ELEMENT_COLLADA__ASSET = 21558580;
		virtual bool begin__COLLADA__asset(){return true;}
		virtual bool end__COLLADA__asset(){return true;}
	private:
		bool _begin__COLLADA__asset( void* attributeData ){return begin__COLLADA__asset();}
		bool _data__COLLADA__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__COLLADA__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__COLLADA__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS = 223353555;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_ANIMATIONS = 257283875;
		struct library_animations__AttributeData
		{
			static const library_animations__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_animations( const library_animations__AttributeData& attributeData ){return true;}
		virtual bool end__library_animations(){return true;}
	private:
		bool _begin__library_animations( void* attributeData ){return begin__library_animations(*static_cast<library_animations__AttributeData*>(attributeData));}
		bool _data__library_animations( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_animations( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animations();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__ASSET = 39388324;
		virtual bool begin__library_animations__asset(){return true;}
		virtual bool end__library_animations__asset(){return true;}
	private:
		bool _begin__library_animations__asset( void* attributeData ){return begin__library_animations__asset();}
		bool _data__library_animations__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_animations__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animations__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__EXTRA = 39671521;
		struct library_animations__extra__AttributeData
		{
			static const library_animations__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_animations__extra( const library_animations__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_animations__extra(){return true;}
	private:
		bool _begin__library_animations__extra( void* attributeData ){return begin__library_animations__extra(*static_cast<library_animations__extra__AttributeData*>(attributeData));}
		bool _data__library_animations__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_animations__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animations__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS = 210579923;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_ANIMATION_CLIPS = 95259907;
		struct library_animation_clips__AttributeData
		{
			static const library_animation_clips__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_animation_clips( const library_animation_clips__AttributeData& attributeData ){return true;}
		virtual bool end__library_animation_clips(){return true;}
	private:
		bool _begin__library_animation_clips( void* attributeData ){return begin__library_animation_clips(*static_cast<library_animation_clips__AttributeData*>(attributeData));}
		bool _data__library_animation_clips( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_animation_clips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animation_clips();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__ASSET = 227259540;
		virtual bool begin__library_animation_clips__asset(){return true;}
		virtual bool end__library_animation_clips__asset(){return true;}
	private:
		bool _begin__library_animation_clips__asset( void* attributeData ){return begin__library_animation_clips__asset();}
		bool _data__library_animation_clips__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_animation_clips__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animation_clips__asset();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION_CLIP = 21376896;
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__ANIMATION_CLIP = 18076080;
		static const StringHash HASH_ATTRIBUTE_START = 8038548;
		static const StringHash HASH_ATTRIBUTE_END = 27716;
		struct animation_clip__AttributeData
		{
			static const animation_clip__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			double start;
			double end;
		};
		virtual bool begin__animation_clip( const animation_clip__AttributeData& attributeData ){return true;}
		virtual bool end__animation_clip(){return true;}
	private:
		bool _begin__animation_clip( void* attributeData ){return begin__animation_clip(*static_cast<animation_clip__AttributeData*>(attributeData));}
		bool _data__animation_clip( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation_clip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation_clip();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION_CLIP__ASSET = 20599188;
		virtual bool begin__animation_clip__asset(){return true;}
		virtual bool end__animation_clip__asset(){return true;}
	private:
		bool _begin__animation_clip__asset( void* attributeData ){return begin__animation_clip__asset();}
		bool _data__animation_clip__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation_clip__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation_clip__asset();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_ANIMATION = 228086430;
		static const StringHash HASH_ELEMENT_ANIMATION_CLIP__INSTANCE_ANIMATION = 155834222;
		struct instance_animation__AttributeData
		{
			static const instance_animation__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_animation( const instance_animation__AttributeData& attributeData ){return true;}
		virtual bool end__instance_animation(){return true;}
	private:
		bool _begin__instance_animation( void* attributeData ){return begin__instance_animation(*static_cast<instance_animation__AttributeData*>(attributeData));}
		bool _data__instance_animation( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_animation();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_ANIMATION__EXTRA = 249155953;
		struct instance_animation__extra__AttributeData
		{
			static const instance_animation__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_animation__extra( const instance_animation__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_animation__extra(){return true;}
	private:
		bool _begin__instance_animation__extra( void* attributeData ){return begin__instance_animation__extra(*static_cast<instance_animation__extra__AttributeData*>(attributeData));}
		bool _data__instance_animation__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_animation__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_animation__extra();

	public:
		static const StringHash HASH_ELEMENT_ANIMATION_CLIP__EXTRA = 20841425;
		struct animation_clip__extra__AttributeData
		{
			static const animation_clip__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__animation_clip__extra( const animation_clip__extra__AttributeData& attributeData ){return true;}
		virtual bool end__animation_clip__extra(){return true;}
	private:
		bool _begin__animation_clip__extra( void* attributeData ){return begin__animation_clip__extra(*static_cast<animation_clip__extra__AttributeData*>(attributeData));}
		bool _data__animation_clip__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__animation_clip__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation_clip__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA = 227534545;
		struct library_animation_clips__extra__AttributeData
		{
			static const library_animation_clips__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_animation_clips__extra( const library_animation_clips__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_animation_clips__extra(){return true;}
	private:
		bool _begin__library_animation_clips__extra( void* attributeData ){return begin__library_animation_clips__extra(*static_cast<library_animation_clips__extra__AttributeData*>(attributeData));}
		bool _data__library_animation_clips__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_animation_clips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animation_clips__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_CAMERAS = 17507619;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_CAMERAS = 203031923;
		struct library_cameras__AttributeData
		{
			static const library_cameras__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_cameras( const library_cameras__AttributeData& attributeData ){return true;}
		virtual bool end__library_cameras(){return true;}
	private:
		bool _begin__library_cameras( void* attributeData ){return begin__library_cameras(*static_cast<library_cameras__AttributeData*>(attributeData));}
		bool _data__library_cameras( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_cameras( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_cameras();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__ASSET = 99285860;
		virtual bool begin__library_cameras__asset(){return true;}
		virtual bool end__library_cameras__asset(){return true;}
	private:
		bool _begin__library_cameras__asset( void* attributeData ){return begin__library_cameras__asset();}
		bool _data__library_cameras__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_cameras__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_cameras__asset();

	public:
		static const StringHash HASH_ELEMENT_CAMERA = 110640257;
		static const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__CAMERA = 246617809;
		struct camera__AttributeData
		{
			static const camera__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__camera( const camera__AttributeData& attributeData ){return true;}
		virtual bool end__camera(){return true;}
	private:
		bool _begin__camera( void* attributeData ){return begin__camera(*static_cast<camera__AttributeData*>(attributeData));}
		bool _data__camera( const ParserChar* text, size_t textLength );
		bool _validateBegin__camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__camera();

	public:
		static const StringHash HASH_ELEMENT_CAMERA__ASSET = 249258452;
		virtual bool begin__camera__asset(){return true;}
		virtual bool end__camera__asset(){return true;}
	private:
		bool _begin__camera__asset( void* attributeData ){return begin__camera__asset();}
		bool _data__camera__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__camera__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__camera__asset();

	public:
		static const StringHash HASH_ELEMENT_OPTICS = 124235683;
		static const StringHash HASH_ELEMENT_CAMERA__OPTICS = 240856643;
		virtual bool begin__optics(){return true;}
		virtual bool end__optics(){return true;}
	private:
		bool _begin__optics( void* attributeData ){return begin__optics();}
		bool _data__optics( const ParserChar* text, size_t textLength );
		bool _validateBegin__optics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics();

	public:
		static const StringHash HASH_ELEMENT_OPTICS__TECHNIQUE_COMMON = 170249678;
		virtual bool begin__optics__technique_common(){return true;}
		virtual bool end__optics__technique_common(){return true;}
	private:
		bool _begin__optics__technique_common( void* attributeData ){return begin__optics__technique_common();}
		bool _data__optics__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__optics__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics__technique_common();

	public:
		static const StringHash HASH_ELEMENT_ORTHOGRAPHIC = 165790115;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ORTHOGRAPHIC = 163965699;
		virtual bool begin__orthographic(){return true;}
		virtual bool end__orthographic(){return true;}
	private:
		bool _begin__orthographic( void* attributeData ){return begin__orthographic();}
		bool _data__orthographic( const ParserChar* text, size_t textLength );
		bool _validateBegin__orthographic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic();

	public:
		static const StringHash HASH_ELEMENT_XMAG = 521079;
		static const StringHash HASH_ELEMENT_ORTHOGRAPHIC__XMAG = 45560535;
		struct xmag__AttributeData
		{
			static const xmag__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__xmag( const xmag__AttributeData& attributeData ){return true;}
		virtual bool end__xmag(){return true;}
		virtual bool data__xmag( const void* data, size_t length ){return true;}
	private:
		bool _begin__xmag( void* attributeData ){return begin__xmag(*static_cast<xmag__AttributeData*>(attributeData));}
		bool _data__xmag( const ParserChar* text, size_t textLength );
		bool _validateBegin__xmag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__xmag();

	public:
		static const StringHash HASH_ELEMENT_YMAG = 525175;
		static const StringHash HASH_ELEMENT_ORTHOGRAPHIC__YMAG = 45564631;
		struct ymag__AttributeData
		{
			static const ymag__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__ymag( const ymag__AttributeData& attributeData ){return true;}
		virtual bool end__ymag(){return true;}
		virtual bool data__ymag( const void* data, size_t length ){return true;}
	private:
		bool _begin__ymag( void* attributeData ){return begin__ymag(*static_cast<ymag__AttributeData*>(attributeData));}
		bool _data__ymag( const ParserChar* text, size_t textLength );
		bool _validateBegin__ymag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ymag();

	public:
		static const StringHash HASH_ELEMENT_ASPECT_RATIO = 14868815;
		static const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO = 237192175;
		struct orthographic__aspect_ratio__AttributeData
		{
			static const orthographic__aspect_ratio__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__orthographic__aspect_ratio( const orthographic__aspect_ratio__AttributeData& attributeData ){return true;}
		virtual bool end__orthographic__aspect_ratio(){return true;}
		virtual bool data__orthographic__aspect_ratio( const void* data, size_t length ){return true;}
	private:
		bool _begin__orthographic__aspect_ratio( void* attributeData ){return begin__orthographic__aspect_ratio(*static_cast<orthographic__aspect_ratio__AttributeData*>(attributeData));}
		bool _data__orthographic__aspect_ratio( const ParserChar* text, size_t textLength );
		bool _validateBegin__orthographic__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic__aspect_ratio();

	public:
		static const StringHash HASH_ELEMENT_ZNEAR = 8473474;
		static const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZNEAR = 193810850;
		struct orthographic__znear__AttributeData
		{
			static const orthographic__znear__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__orthographic__znear( const orthographic__znear__AttributeData& attributeData ){return true;}
		virtual bool end__orthographic__znear(){return true;}
		virtual bool data__orthographic__znear( const void* data, size_t length ){return true;}
	private:
		bool _begin__orthographic__znear( void* attributeData ){return begin__orthographic__znear(*static_cast<orthographic__znear__AttributeData*>(attributeData));}
		bool _data__orthographic__znear( const ParserChar* text, size_t textLength );
		bool _validateBegin__orthographic__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic__znear();

	public:
		static const StringHash HASH_ELEMENT_ZFAR = 527490;
		static const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZFAR = 45665570;
		struct orthographic__zfar__AttributeData
		{
			static const orthographic__zfar__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__orthographic__zfar( const orthographic__zfar__AttributeData& attributeData ){return true;}
		virtual bool end__orthographic__zfar(){return true;}
		virtual bool data__orthographic__zfar( const void* data, size_t length ){return true;}
	private:
		bool _begin__orthographic__zfar( void* attributeData ){return begin__orthographic__zfar(*static_cast<orthographic__zfar__AttributeData*>(attributeData));}
		bool _data__orthographic__zfar( const ParserChar* text, size_t textLength );
		bool _validateBegin__orthographic__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic__zfar();

	public:
		static const StringHash HASH_ELEMENT_PERSPECTIVE = 114063717;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__PERSPECTIVE = 216939461;
		virtual bool begin__perspective(){return true;}
		virtual bool end__perspective(){return true;}
	private:
		bool _begin__perspective( void* attributeData ){return begin__perspective();}
		bool _data__perspective( const ParserChar* text, size_t textLength );
		bool _validateBegin__perspective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective();

	public:
		static const StringHash HASH_ELEMENT_XFOV = 519526;
		static const StringHash HASH_ELEMENT_PERSPECTIVE__XFOV = 228234758;
		struct xfov__AttributeData
		{
			static const xfov__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__xfov( const xfov__AttributeData& attributeData ){return true;}
		virtual bool end__xfov(){return true;}
		virtual bool data__xfov( const void* data, size_t length ){return true;}
	private:
		bool _begin__xfov( void* attributeData ){return begin__xfov(*static_cast<xfov__AttributeData*>(attributeData));}
		bool _data__xfov( const ParserChar* text, size_t textLength );
		bool _validateBegin__xfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__xfov();

	public:
		static const StringHash HASH_ELEMENT_YFOV = 523622;
		static const StringHash HASH_ELEMENT_PERSPECTIVE__YFOV = 228230662;
		struct yfov__AttributeData
		{
			static const yfov__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__yfov( const yfov__AttributeData& attributeData ){return true;}
		virtual bool end__yfov(){return true;}
		virtual bool data__yfov( const void* data, size_t length ){return true;}
	private:
		bool _begin__yfov( void* attributeData ){return begin__yfov(*static_cast<yfov__AttributeData*>(attributeData));}
		bool _data__yfov( const ParserChar* text, size_t textLength );
		bool _validateBegin__yfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__yfov();

	public:
		static const StringHash HASH_ELEMENT_PERSPECTIVE__ASPECT_RATIO = 26971343;
		struct perspective__aspect_ratio__AttributeData
		{
			static const perspective__aspect_ratio__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__perspective__aspect_ratio( const perspective__aspect_ratio__AttributeData& attributeData ){return true;}
		virtual bool end__perspective__aspect_ratio(){return true;}
		virtual bool data__perspective__aspect_ratio( const void* data, size_t length ){return true;}
	private:
		bool _begin__perspective__aspect_ratio( void* attributeData ){return begin__perspective__aspect_ratio(*static_cast<perspective__aspect_ratio__AttributeData*>(attributeData));}
		bool _data__perspective__aspect_ratio( const ParserChar* text, size_t textLength );
		bool _validateBegin__perspective__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective__aspect_ratio();

	public:
		static const StringHash HASH_ELEMENT_PERSPECTIVE__ZNEAR = 163110226;
		struct perspective__znear__AttributeData
		{
			static const perspective__znear__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__perspective__znear( const perspective__znear__AttributeData& attributeData ){return true;}
		virtual bool end__perspective__znear(){return true;}
		virtual bool data__perspective__znear( const void* data, size_t length ){return true;}
	private:
		bool _begin__perspective__znear( void* attributeData ){return begin__perspective__znear(*static_cast<perspective__znear__AttributeData*>(attributeData));}
		bool _data__perspective__znear( const ParserChar* text, size_t textLength );
		bool _validateBegin__perspective__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective__znear();

	public:
		static const StringHash HASH_ELEMENT_PERSPECTIVE__ZFAR = 228292066;
		struct perspective__zfar__AttributeData
		{
			static const perspective__zfar__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__perspective__zfar( const perspective__zfar__AttributeData& attributeData ){return true;}
		virtual bool end__perspective__zfar(){return true;}
		virtual bool data__perspective__zfar( const void* data, size_t length ){return true;}
	private:
		bool _begin__perspective__zfar( void* attributeData ){return begin__perspective__zfar(*static_cast<perspective__zfar__AttributeData*>(attributeData));}
		bool _data__perspective__zfar( const ParserChar* text, size_t textLength );
		bool _validateBegin__perspective__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective__zfar();

	public:
		static const StringHash HASH_ELEMENT_OPTICS__TECHNIQUE = 49813749;
		struct optics__technique__AttributeData
		{
			static const optics__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__optics__technique( const optics__technique__AttributeData& attributeData ){return true;}
		virtual bool end__optics__technique(){return true;}
	private:
		bool _begin__optics__technique( void* attributeData ){return begin__optics__technique(*static_cast<optics__technique__AttributeData*>(attributeData));}
		bool _data__optics__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__optics__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics__technique();

	public:
		static const StringHash HASH_ELEMENT_OPTICS__EXTRA = 52822145;
		struct optics__extra__AttributeData
		{
			static const optics__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__optics__extra( const optics__extra__AttributeData& attributeData ){return true;}
		virtual bool end__optics__extra(){return true;}
	private:
		bool _begin__optics__extra( void* attributeData ){return begin__optics__extra(*static_cast<optics__extra__AttributeData*>(attributeData));}
		bool _data__optics__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__optics__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics__extra();

	public:
		static const StringHash HASH_ELEMENT_IMAGER = 117669314;
		static const StringHash HASH_ELEMENT_CAMERA__IMAGER = 232782882;
		virtual bool begin__imager(){return true;}
		virtual bool end__imager(){return true;}
	private:
		bool _begin__imager( void* attributeData ){return begin__imager();}
		bool _data__imager( const ParserChar* text, size_t textLength );
		bool _validateBegin__imager( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__imager();

	public:
		static const StringHash HASH_ELEMENT_IMAGER__TECHNIQUE = 100816341;
		struct imager__technique__AttributeData
		{
			static const imager__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__imager__technique( const imager__technique__AttributeData& attributeData ){return true;}
		virtual bool end__imager__technique(){return true;}
	private:
		bool _begin__imager__technique( void* attributeData ){return begin__imager__technique(*static_cast<imager__technique__AttributeData*>(attributeData));}
		bool _data__imager__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__imager__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__imager__technique();

	public:
		static const StringHash HASH_ELEMENT_IMAGER__EXTRA = 90908561;
		struct imager__extra__AttributeData
		{
			static const imager__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__imager__extra( const imager__extra__AttributeData& attributeData ){return true;}
		virtual bool end__imager__extra(){return true;}
	private:
		bool _begin__imager__extra( void* attributeData ){return begin__imager__extra(*static_cast<imager__extra__AttributeData*>(attributeData));}
		bool _data__imager__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__imager__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__imager__extra();

	public:
		static const StringHash HASH_ELEMENT_CAMERA__EXTRA = 249508753;
		struct camera__extra__AttributeData
		{
			static const camera__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__camera__extra( const camera__extra__AttributeData& attributeData ){return true;}
		virtual bool end__camera__extra(){return true;}
	private:
		bool _begin__camera__extra( void* attributeData ){return begin__camera__extra(*static_cast<camera__extra__AttributeData*>(attributeData));}
		bool _data__camera__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__camera__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__camera__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__EXTRA = 99526945;
		struct library_cameras__extra__AttributeData
		{
			static const library_cameras__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_cameras__extra( const library_cameras__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_cameras__extra(){return true;}
	private:
		bool _begin__library_cameras__extra( void* attributeData ){return begin__library_cameras__extra(*static_cast<library_cameras__extra__AttributeData*>(attributeData));}
		bool _data__library_cameras__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_cameras__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_cameras__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS = 117752259;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_CONTROLLERS = 113250531;
		struct library_controllers__AttributeData
		{
			static const library_controllers__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_controllers( const library_controllers__AttributeData& attributeData ){return true;}
		virtual bool end__library_controllers(){return true;}
	private:
		bool _begin__library_controllers( void* attributeData ){return begin__library_controllers(*static_cast<library_controllers__AttributeData*>(attributeData));}
		bool _data__library_controllers( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_controllers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_controllers();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__ASSET = 85243076;
		virtual bool begin__library_controllers__asset(){return true;}
		virtual bool end__library_controllers__asset(){return true;}
	private:
		bool _begin__library_controllers__asset( void* attributeData ){return begin__library_controllers__asset();}
		bool _data__library_controllers__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_controllers__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_controllers__asset();

	public:
		static const StringHash HASH_ELEMENT_CONTROLLER = 194286738;
		static const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__CONTROLLER = 199579458;
		struct controller__AttributeData
		{
			static const controller__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__controller( const controller__AttributeData& attributeData ){return true;}
		virtual bool end__controller(){return true;}
	private:
		bool _begin__controller( void* attributeData ){return begin__controller(*static_cast<controller__AttributeData*>(attributeData));}
		bool _data__controller( const ParserChar* text, size_t textLength );
		bool _validateBegin__controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__controller();

	public:
		static const StringHash HASH_ELEMENT_CONTROLLER__ASSET = 236052500;
		virtual bool begin__controller__asset(){return true;}
		virtual bool end__controller__asset(){return true;}
	private:
		bool _begin__controller__asset( void* attributeData ){return begin__controller__asset();}
		bool _data__controller__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__controller__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__controller__asset();

	public:
		static const StringHash HASH_ELEMENT_SKIN = 500222;
		static const StringHash HASH_ELEMENT_CONTROLLER__SKIN = 232920430;
		struct skin__AttributeData
		{
			static const skin__AttributeData DEFAULT;

			const ParserChar* source;
		};
		virtual bool begin__skin( const skin__AttributeData& attributeData ){return true;}
		virtual bool end__skin(){return true;}
	private:
		bool _begin__skin( void* attributeData ){return begin__skin(*static_cast<skin__AttributeData*>(attributeData));}
		bool _data__skin( const ParserChar* text, size_t textLength );
		bool _validateBegin__skin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skin();

	public:
		static const StringHash HASH_ELEMENT_BIND_SHAPE_MATRIX = 80689944;
		static const StringHash HASH_ELEMENT_SKIN__BIND_SHAPE_MATRIX = 126147416;
		virtual bool begin__bind_shape_matrix(){return true;}
		virtual bool end__bind_shape_matrix(){return true;}
		virtual bool data__bind_shape_matrix( const void* data, size_t length ){return true;}
	private:
		bool _begin__bind_shape_matrix( void* attributeData ){return begin__bind_shape_matrix();}
		bool _data__bind_shape_matrix( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_shape_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_shape_matrix();

	public:
		static const StringHash HASH_ELEMENT_SKIN__SOURCE = 21286085;
		struct skin__source__AttributeData
		{
			static const skin__source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__skin__source( const skin__source__AttributeData& attributeData ){return true;}
		virtual bool end__skin__source(){return true;}
	private:
		bool _begin__skin__source( void* attributeData ){return begin__skin__source(*static_cast<skin__source__AttributeData*>(attributeData));}
		bool _data__skin__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__skin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skin__source();

	public:
		static const StringHash HASH_ELEMENT_JOINTS = 118883763;
		static const StringHash HASH_ELEMENT_SKIN__JOINTS = 62390755;
		virtual bool begin__joints(){return true;}
		virtual bool end__joints(){return true;}
	private:
		bool _begin__joints( void* attributeData ){return begin__joints();}
		bool _data__joints( const ParserChar* text, size_t textLength );
		bool _validateBegin__joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__joints();

	public:
		static const StringHash HASH_ELEMENT_JOINTS__INPUT = 104860612;
		struct joints__input__AttributeData
		{
			static const joints__input__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* source;
		};
		virtual bool begin__joints__input( const joints__input__AttributeData& attributeData ){return true;}
		virtual bool end__joints__input(){return true;}
	private:
		bool _begin__joints__input( void* attributeData ){return begin__joints__input(*static_cast<joints__input__AttributeData*>(attributeData));}
		bool _data__joints__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__joints__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__joints__input();

	public:
		static const StringHash HASH_ELEMENT_JOINTS__EXTRA = 104638337;
		struct joints__extra__AttributeData
		{
			static const joints__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__joints__extra( const joints__extra__AttributeData& attributeData ){return true;}
		virtual bool end__joints__extra(){return true;}
	private:
		bool _begin__joints__extra( void* attributeData ){return begin__joints__extra(*static_cast<joints__extra__AttributeData*>(attributeData));}
		bool _data__joints__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__joints__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__joints__extra();

	public:
		static const StringHash HASH_ELEMENT_VERTEX_WEIGHTS = 19207187;
		static const StringHash HASH_ELEMENT_SKIN__VERTEX_WEIGHTS = 52511411;
		struct vertex_weights__AttributeData
		{
			static const vertex_weights__AttributeData DEFAULT;

			const ParserChar* count;
		};
		virtual bool begin__vertex_weights( const vertex_weights__AttributeData& attributeData ){return true;}
		virtual bool end__vertex_weights(){return true;}
	private:
		bool _begin__vertex_weights( void* attributeData ){return begin__vertex_weights(*static_cast<vertex_weights__AttributeData*>(attributeData));}
		bool _data__vertex_weights( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertex_weights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights();

	public:
		static const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__INPUT = 118429284;
		struct vertex_weights__input__AttributeData
		{
			static const vertex_weights__input__AttributeData DEFAULT;

			const ParserChar* offset;
			const ParserChar* semantic;
			const ParserChar* source;
			const ParserChar* set;
		};
		virtual bool begin__vertex_weights__input( const vertex_weights__input__AttributeData& attributeData ){return true;}
		virtual bool end__vertex_weights__input(){return true;}
	private:
		bool _begin__vertex_weights__input( void* attributeData ){return begin__vertex_weights__input(*static_cast<vertex_weights__input__AttributeData*>(attributeData));}
		bool _data__vertex_weights__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertex_weights__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights__input();

	public:
		static const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__VCOUNT = 64909860;
		virtual bool begin__vertex_weights__vcount(){return true;}
		virtual bool end__vertex_weights__vcount(){return true;}
		virtual bool data__vertex_weights__vcount( const void* data, size_t length ){return true;}
	private:
		bool _begin__vertex_weights__vcount( void* attributeData ){return begin__vertex_weights__vcount();}
		bool _data__vertex_weights__vcount( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertex_weights__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights__vcount();

	public:
		static const StringHash HASH_ELEMENT_V = 118;
		static const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__V = 21079862;
		virtual bool begin__v(){return true;}
		virtual bool end__v(){return true;}
		virtual bool data__v( const void* data, size_t length ){return true;}
	private:
		bool _begin__v( void* attributeData ){return begin__v();}
		bool _data__v( const ParserChar* text, size_t textLength );
		bool _validateBegin__v( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__v();

	public:
		static const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__EXTRA = 118340129;
		struct vertex_weights__extra__AttributeData
		{
			static const vertex_weights__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__vertex_weights__extra( const vertex_weights__extra__AttributeData& attributeData ){return true;}
		virtual bool end__vertex_weights__extra(){return true;}
	private:
		bool _begin__vertex_weights__extra( void* attributeData ){return begin__vertex_weights__extra(*static_cast<vertex_weights__extra__AttributeData*>(attributeData));}
		bool _data__vertex_weights__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertex_weights__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights__extra();

	public:
		static const StringHash HASH_ELEMENT_SKIN__EXTRA = 86432705;
		struct skin__extra__AttributeData
		{
			static const skin__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__skin__extra( const skin__extra__AttributeData& attributeData ){return true;}
		virtual bool end__skin__extra(){return true;}
	private:
		bool _begin__skin__extra( void* attributeData ){return begin__skin__extra(*static_cast<skin__extra__AttributeData*>(attributeData));}
		bool _data__skin__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__skin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skin__extra();

	public:
		static const StringHash HASH_ELEMENT_MORPH = 7629160;
		static const StringHash HASH_ELEMENT_CONTROLLER__MORPH = 237707448;
		static const StringHash HASH_ATTRIBUTE_METHOD = 121417556;
		struct morph__AttributeData
		{
			static const morph__AttributeData DEFAULT;

			const ParserChar* method;
			const ParserChar* source;
		};
		virtual bool begin__morph( const morph__AttributeData& attributeData ){return true;}
		virtual bool end__morph(){return true;}
	private:
		bool _begin__morph( void* attributeData ){return begin__morph(*static_cast<morph__AttributeData*>(attributeData));}
		bool _data__morph( const ParserChar* text, size_t textLength );
		bool _validateBegin__morph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__morph();

	public:
		static const StringHash HASH_ELEMENT_MORPH__SOURCE = 51357397;
		struct morph__source__AttributeData
		{
			static const morph__source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__morph__source( const morph__source__AttributeData& attributeData ){return true;}
		virtual bool end__morph__source(){return true;}
	private:
		bool _begin__morph__source( void* attributeData ){return begin__morph__source(*static_cast<morph__source__AttributeData*>(attributeData));}
		bool _data__morph__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__morph__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__morph__source();

	public:
		static const StringHash HASH_ELEMENT_TARGETS = 176741571;
		static const StringHash HASH_ELEMENT_MORPH__TARGETS = 203307155;
		virtual bool begin__targets(){return true;}
		virtual bool end__targets(){return true;}
	private:
		bool _begin__targets( void* attributeData ){return begin__targets();}
		bool _data__targets( const ParserChar* text, size_t textLength );
		bool _validateBegin__targets( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__targets();

	public:
		static const StringHash HASH_ELEMENT_TARGETS__INPUT = 231971828;
		struct targets__input__AttributeData
		{
			static const targets__input__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* source;
		};
		virtual bool begin__targets__input( const targets__input__AttributeData& attributeData ){return true;}
		virtual bool end__targets__input(){return true;}
	private:
		bool _begin__targets__input( void* attributeData ){return begin__targets__input(*static_cast<targets__input__AttributeData*>(attributeData));}
		bool _data__targets__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__targets__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__targets__input();

	public:
		static const StringHash HASH_ELEMENT_TARGETS__EXTRA = 231815089;
		struct targets__extra__AttributeData
		{
			static const targets__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__targets__extra( const targets__extra__AttributeData& attributeData ){return true;}
		virtual bool end__targets__extra(){return true;}
	private:
		bool _begin__targets__extra( void* attributeData ){return begin__targets__extra(*static_cast<targets__extra__AttributeData*>(attributeData));}
		bool _data__targets__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__targets__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__targets__extra();

	public:
		static const StringHash HASH_ELEMENT_MORPH__EXTRA = 68840801;
		struct morph__extra__AttributeData
		{
			static const morph__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__morph__extra( const morph__extra__AttributeData& attributeData ){return true;}
		virtual bool end__morph__extra(){return true;}
	private:
		bool _begin__morph__extra( void* attributeData ){return begin__morph__extra(*static_cast<morph__extra__AttributeData*>(attributeData));}
		bool _data__morph__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__morph__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__morph__extra();

	public:
		static const StringHash HASH_ELEMENT_CONTROLLER__EXTRA = 236302929;
		struct controller__extra__AttributeData
		{
			static const controller__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__controller__extra( const controller__extra__AttributeData& attributeData ){return true;}
		virtual bool end__controller__extra(){return true;}
	private:
		bool _begin__controller__extra( void* attributeData ){return begin__controller__extra(*static_cast<controller__extra__AttributeData*>(attributeData));}
		bool _data__controller__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__controller__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__controller__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__EXTRA = 84993665;
		struct library_controllers__extra__AttributeData
		{
			static const library_controllers__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_controllers__extra( const library_controllers__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_controllers__extra(){return true;}
	private:
		bool _begin__library_controllers__extra( void* attributeData ){return begin__library_controllers__extra(*static_cast<library_controllers__extra__AttributeData*>(attributeData));}
		bool _data__library_controllers__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_controllers__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_controllers__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES = 219269923;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_GEOMETRIES = 252969491;
		struct library_geometries__AttributeData
		{
			static const library_geometries__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_geometries( const library_geometries__AttributeData& attributeData ){return true;}
		virtual bool end__library_geometries(){return true;}
	private:
		bool _begin__library_geometries( void* attributeData ){return begin__library_geometries(*static_cast<library_geometries__AttributeData*>(attributeData));}
		bool _data__library_geometries( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_geometries( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_geometries();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__ASSET = 105126820;
		virtual bool begin__library_geometries__asset(){return true;}
		virtual bool end__library_geometries__asset(){return true;}
	private:
		bool _begin__library_geometries__asset( void* attributeData ){return begin__library_geometries__asset();}
		bool _data__library_geometries__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_geometries__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_geometries__asset();

	public:
		static const StringHash HASH_ELEMENT_GEOMETRY = 207867209;
		static const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__GEOMETRY = 25538441;
		struct geometry__AttributeData
		{
			static const geometry__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__geometry( const geometry__AttributeData& attributeData ){return true;}
		virtual bool end__geometry(){return true;}
	private:
		bool _begin__geometry( void* attributeData ){return begin__geometry(*static_cast<geometry__AttributeData*>(attributeData));}
		bool _data__geometry( const ParserChar* text, size_t textLength );
		bool _validateBegin__geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__geometry();

	public:
		static const StringHash HASH_ELEMENT_GEOMETRY__ASSET = 56917492;
		virtual bool begin__geometry__asset(){return true;}
		virtual bool end__geometry__asset(){return true;}
	private:
		bool _begin__geometry__asset( void* attributeData ){return begin__geometry__asset();}
		bool _data__geometry__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__geometry__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__geometry__asset();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH = 214980952;
		static const StringHash HASH_ELEMENT_GEOMETRY__CONVEX_MESH = 264547688;
		static const StringHash HASH_ATTRIBUTE_CONVEX_HULL_OF = 167766694;
		struct convex_mesh__AttributeData
		{
			static const convex_mesh__AttributeData DEFAULT;

			const ParserChar* convex_hull_of;
		};
		virtual bool begin__convex_mesh( const convex_mesh__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh(){return true;}
	private:
		bool _begin__convex_mesh( void* attributeData ){return begin__convex_mesh(*static_cast<convex_mesh__AttributeData*>(attributeData));}
		bool _data__convex_mesh( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__SOURCE = 115317301;
		struct convex_mesh__source__AttributeData
		{
			static const convex_mesh__source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__convex_mesh__source( const convex_mesh__source__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__source(){return true;}
	private:
		bool _begin__convex_mesh__source( void* attributeData ){return begin__convex_mesh__source(*static_cast<convex_mesh__source__AttributeData*>(attributeData));}
		bool _data__convex_mesh__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__source();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__VERTICES = 97017683;
		struct convex_mesh__vertices__AttributeData
		{
			static const convex_mesh__vertices__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__convex_mesh__vertices( const convex_mesh__vertices__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__vertices(){return true;}
	private:
		bool _begin__convex_mesh__vertices( void* attributeData ){return begin__convex_mesh__vertices(*static_cast<convex_mesh__vertices__AttributeData*>(attributeData));}
		bool _data__convex_mesh__vertices( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__vertices();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__LINES = 174551523;
		struct convex_mesh__lines__AttributeData
		{
			static const convex_mesh__lines__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__lines( const convex_mesh__lines__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__lines(){return true;}
	private:
		bool _begin__convex_mesh__lines( void* attributeData ){return begin__convex_mesh__lines(*static_cast<convex_mesh__lines__AttributeData*>(attributeData));}
		bool _data__convex_mesh__lines( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__lines();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__LINESTRIPS = 235800419;
		struct convex_mesh__linestrips__AttributeData
		{
			static const convex_mesh__linestrips__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__linestrips( const convex_mesh__linestrips__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__linestrips(){return true;}
	private:
		bool _begin__convex_mesh__linestrips( void* attributeData ){return begin__convex_mesh__linestrips(*static_cast<convex_mesh__linestrips__AttributeData*>(attributeData));}
		bool _data__convex_mesh__linestrips( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__linestrips();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__POLYGONS = 225281043;
		struct convex_mesh__polygons__AttributeData
		{
			static const convex_mesh__polygons__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__polygons( const convex_mesh__polygons__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__polygons(){return true;}
	private:
		bool _begin__convex_mesh__polygons( void* attributeData ){return begin__convex_mesh__polygons(*static_cast<convex_mesh__polygons__AttributeData*>(attributeData));}
		bool _data__convex_mesh__polygons( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__polygons();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__POLYLIST = 225351396;
		struct convex_mesh__polylist__AttributeData
		{
			static const convex_mesh__polylist__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__polylist( const convex_mesh__polylist__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__polylist(){return true;}
	private:
		bool _begin__convex_mesh__polylist( void* attributeData ){return begin__convex_mesh__polylist(*static_cast<convex_mesh__polylist__AttributeData*>(attributeData));}
		bool _data__convex_mesh__polylist( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__polylist();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__TRIANGLES = 175033555;
		struct convex_mesh__triangles__AttributeData
		{
			static const convex_mesh__triangles__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__triangles( const convex_mesh__triangles__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__triangles(){return true;}
	private:
		bool _begin__convex_mesh__triangles( void* attributeData ){return begin__convex_mesh__triangles(*static_cast<convex_mesh__triangles__AttributeData*>(attributeData));}
		bool _data__convex_mesh__triangles( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__triangles();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__TRIFANS = 236645939;
		struct convex_mesh__trifans__AttributeData
		{
			static const convex_mesh__trifans__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__trifans( const convex_mesh__trifans__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__trifans(){return true;}
	private:
		bool _begin__convex_mesh__trifans( void* attributeData ){return begin__convex_mesh__trifans(*static_cast<convex_mesh__trifans__AttributeData*>(attributeData));}
		bool _data__convex_mesh__trifans( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__trifans();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__TRISTRIPS = 92405331;
		struct convex_mesh__tristrips__AttributeData
		{
			static const convex_mesh__tristrips__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__convex_mesh__tristrips( const convex_mesh__tristrips__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__tristrips(){return true;}
	private:
		bool _begin__convex_mesh__tristrips( void* attributeData ){return begin__convex_mesh__tristrips(*static_cast<convex_mesh__tristrips__AttributeData*>(attributeData));}
		bool _data__convex_mesh__tristrips( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__tristrips();

	public:
		static const StringHash HASH_ELEMENT_CONVEX_MESH__EXTRA = 173633185;
		struct convex_mesh__extra__AttributeData
		{
			static const convex_mesh__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__convex_mesh__extra( const convex_mesh__extra__AttributeData& attributeData ){return true;}
		virtual bool end__convex_mesh__extra(){return true;}
	private:
		bool _begin__convex_mesh__extra( void* attributeData ){return begin__convex_mesh__extra(*static_cast<convex_mesh__extra__AttributeData*>(attributeData));}
		bool _data__convex_mesh__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__convex_mesh__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__extra();

	public:
		static const StringHash HASH_ELEMENT_SPLINE = 128397381;
		static const StringHash HASH_ELEMENT_GEOMETRY__SPLINE = 90991989;
		static const StringHash HASH_ATTRIBUTE_CLOSED = 111372724;
		struct spline__AttributeData
		{
			static const spline__AttributeData DEFAULT;

			const ParserChar* closed;
		};
		virtual bool begin__spline( const spline__AttributeData& attributeData ){return true;}
		virtual bool end__spline(){return true;}
	private:
		bool _begin__spline( void* attributeData ){return begin__spline(*static_cast<spline__AttributeData*>(attributeData));}
		bool _data__spline( const ParserChar* text, size_t textLength );
		bool _validateBegin__spline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spline();

	public:
		static const StringHash HASH_ELEMENT_SPLINE__SOURCE = 28739173;
		struct spline__source__AttributeData
		{
			static const spline__source__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__spline__source( const spline__source__AttributeData& attributeData ){return true;}
		virtual bool end__spline__source(){return true;}
	private:
		bool _begin__spline__source( void* attributeData ){return begin__spline__source(*static_cast<spline__source__AttributeData*>(attributeData));}
		bool _data__spline__source( const ParserChar* text, size_t textLength );
		bool _validateBegin__spline__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spline__source();

	public:
		static const StringHash HASH_ELEMENT_CONTROL_VERTICES = 118372691;
		static const StringHash HASH_ELEMENT_SPLINE__CONTROL_VERTICES = 152193299;
		virtual bool begin__control_vertices(){return true;}
		virtual bool end__control_vertices(){return true;}
	private:
		bool _begin__control_vertices( void* attributeData ){return begin__control_vertices();}
		bool _data__control_vertices( const ParserChar* text, size_t textLength );
		bool _validateBegin__control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__control_vertices();

	public:
		static const StringHash HASH_ELEMENT_CONTROL_VERTICES__INPUT = 96321988;
		struct control_vertices__input__AttributeData
		{
			static const control_vertices__input__AttributeData DEFAULT;

			const ParserChar* semantic;
			const ParserChar* source;
		};
		virtual bool begin__control_vertices__input( const control_vertices__input__AttributeData& attributeData ){return true;}
		virtual bool end__control_vertices__input(){return true;}
	private:
		bool _begin__control_vertices__input( void* attributeData ){return begin__control_vertices__input(*static_cast<control_vertices__input__AttributeData*>(attributeData));}
		bool _data__control_vertices__input( const ParserChar* text, size_t textLength );
		bool _validateBegin__control_vertices__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__control_vertices__input();

	public:
		static const StringHash HASH_ELEMENT_CONTROL_VERTICES__EXTRA = 96431489;
		struct control_vertices__extra__AttributeData
		{
			static const control_vertices__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__control_vertices__extra( const control_vertices__extra__AttributeData& attributeData ){return true;}
		virtual bool end__control_vertices__extra(){return true;}
	private:
		bool _begin__control_vertices__extra( void* attributeData ){return begin__control_vertices__extra(*static_cast<control_vertices__extra__AttributeData*>(attributeData));}
		bool _data__control_vertices__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__control_vertices__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__control_vertices__extra();

	public:
		static const StringHash HASH_ELEMENT_SPLINE__EXTRA = 254803809;
		struct spline__extra__AttributeData
		{
			static const spline__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__spline__extra( const spline__extra__AttributeData& attributeData ){return true;}
		virtual bool end__spline__extra(){return true;}
	private:
		bool _begin__spline__extra( void* attributeData ){return begin__spline__extra(*static_cast<spline__extra__AttributeData*>(attributeData));}
		bool _data__spline__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__spline__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spline__extra();

	public:
		static const StringHash HASH_ELEMENT_GEOMETRY__EXTRA = 56635313;
		struct geometry__extra__AttributeData
		{
			static const geometry__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__geometry__extra( const geometry__extra__AttributeData& attributeData ){return true;}
		virtual bool end__geometry__extra(){return true;}
	private:
		bool _begin__geometry__extra( void* attributeData ){return begin__geometry__extra(*static_cast<geometry__extra__AttributeData*>(attributeData));}
		bool _data__geometry__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__geometry__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__geometry__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__EXTRA = 104876513;
		struct library_geometries__extra__AttributeData
		{
			static const library_geometries__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_geometries__extra( const library_geometries__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_geometries__extra(){return true;}
	private:
		bool _begin__library_geometries__extra( void* attributeData ){return begin__library_geometries__extra(*static_cast<library_geometries__extra__AttributeData*>(attributeData));}
		bool _data__library_geometries__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_geometries__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_geometries__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_EFFECTS = 38033171;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_EFFECTS = 246773571;
		struct library_effects__AttributeData
		{
			static const library_effects__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_effects( const library_effects__AttributeData& attributeData ){return true;}
		virtual bool end__library_effects(){return true;}
	private:
		bool _begin__library_effects( void* attributeData ){return begin__library_effects(*static_cast<library_effects__AttributeData*>(attributeData));}
		bool _data__library_effects( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_effects( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_effects();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__ASSET = 18733172;
		virtual bool begin__library_effects__asset(){return true;}
		virtual bool end__library_effects__asset(){return true;}
	private:
		bool _begin__library_effects__asset( void* attributeData ){return begin__library_effects__asset();}
		bool _data__library_effects__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_effects__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_effects__asset();

	public:
		static const StringHash HASH_ELEMENT_EFFECT = 113036196;
		static const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__EFFECT = 32231604;
		struct effect__AttributeData
		{
			static const effect__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__effect( const effect__AttributeData& attributeData ){return true;}
		virtual bool end__effect(){return true;}
	private:
		bool _begin__effect( void* attributeData ){return begin__effect(*static_cast<effect__AttributeData*>(attributeData));}
		bool _data__effect( const ParserChar* text, size_t textLength );
		bool _validateBegin__effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect();

	public:
		static const StringHash HASH_ELEMENT_EFFECT__ASSET = 9704148;
		virtual bool begin__effect__asset(){return true;}
		virtual bool end__effect__asset(){return true;}
	private:
		bool _begin__effect__asset( void* attributeData ){return begin__effect__asset();}
		bool _data__effect__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__effect__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__asset();

	public:
		static const StringHash HASH_ELEMENT_EFFECT__ANNOTATE = 17277301;
		struct effect__annotate__AttributeData
		{
			static const effect__annotate__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__effect__annotate( const effect__annotate__AttributeData& attributeData ){return true;}
		virtual bool end__effect__annotate(){return true;}
	private:
		bool _begin__effect__annotate( void* attributeData ){return begin__effect__annotate(*static_cast<effect__annotate__AttributeData*>(attributeData));}
		bool _data__effect__annotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__effect__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__annotate();

	public:
		static const StringHash HASH_ELEMENT_EFFECT__IMAGE = 9735365;
		struct effect__image__AttributeData
		{
			static const effect__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__effect__image( const effect__image__AttributeData& attributeData ){return true;}
		virtual bool end__effect__image(){return true;}
	private:
		bool _begin__effect__image( void* attributeData ){return begin__effect__image(*static_cast<effect__image__AttributeData*>(attributeData));}
		bool _data__effect__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__effect__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__image();

	public:
		static const StringHash HASH_ELEMENT_EFFECT__NEWPARAM = 123175677;
		struct effect__newparam__AttributeData
		{
			static const effect__newparam__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__effect__newparam( const effect__newparam__AttributeData& attributeData ){return true;}
		virtual bool end__effect__newparam(){return true;}
	private:
		bool _begin__effect__newparam( void* attributeData ){return begin__effect__newparam(*static_cast<effect__newparam__AttributeData*>(attributeData));}
		bool _data__effect__newparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__effect__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__newparam();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER1D = 11125956;
		virtual bool begin__newparam__sampler1D(){return true;}
		virtual bool end__newparam__sampler1D(){return true;}
	private:
		bool _begin__newparam__sampler1D( void* attributeData ){return begin__newparam__sampler1D();}
		bool _data__newparam__sampler1D( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler1D();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER2D = 11126004;
		virtual bool begin__newparam__sampler2D(){return true;}
		virtual bool end__newparam__sampler2D(){return true;}
	private:
		bool _begin__newparam__sampler2D( void* attributeData ){return begin__newparam__sampler2D();}
		bool _data__newparam__sampler2D( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler2D();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER3D = 11125988;
		virtual bool begin__newparam__sampler3D(){return true;}
		virtual bool end__newparam__sampler3D(){return true;}
	private:
		bool _begin__newparam__sampler3D( void* attributeData ){return begin__newparam__sampler3D();}
		bool _data__newparam__sampler3D( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler3D();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERCUBE = 164043205;
		virtual bool begin__newparam__samplerCUBE(){return true;}
		virtual bool end__newparam__samplerCUBE(){return true;}
	private:
		bool _begin__newparam__samplerCUBE( void* attributeData ){return begin__newparam__samplerCUBE();}
		bool _data__newparam__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__samplerCUBE();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERRECT = 164034852;
		virtual bool begin__newparam__samplerRECT(){return true;}
		virtual bool end__newparam__samplerRECT(){return true;}
	private:
		bool _begin__newparam__samplerRECT( void* attributeData ){return begin__newparam__samplerRECT();}
		bool _data__newparam__samplerRECT( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__samplerRECT();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERDEPTH = 208776984;
		virtual bool begin__newparam__samplerDEPTH(){return true;}
		virtual bool end__newparam__samplerDEPTH(){return true;}
	private:
		bool _begin__newparam__samplerDEPTH( void* attributeData ){return begin__newparam__samplerDEPTH();}
		bool _data__newparam__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__samplerDEPTH();

	public:
		static const StringHash HASH_ELEMENT_EFFECT__EXTRA = 9453713;
		struct effect__extra__AttributeData
		{
			static const effect__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__effect__extra( const effect__extra__AttributeData& attributeData ){return true;}
		virtual bool end__effect__extra(){return true;}
	private:
		bool _begin__effect__extra( void* attributeData ){return begin__effect__extra(*static_cast<effect__extra__AttributeData*>(attributeData));}
		bool _data__effect__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__effect__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__EXTRA = 18450993;
		struct library_effects__extra__AttributeData
		{
			static const library_effects__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_effects__extra( const library_effects__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_effects__extra(){return true;}
	private:
		bool _begin__library_effects__extra( void* attributeData ){return begin__library_effects__extra(*static_cast<library_effects__extra__AttributeData*>(attributeData));}
		bool _data__library_effects__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_effects__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_effects__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_IMAGES = 175895315;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_IMAGES = 263512339;
		struct library_images__AttributeData
		{
			static const library_images__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_images( const library_images__AttributeData& attributeData ){return true;}
		virtual bool end__library_images(){return true;}
	private:
		bool _begin__library_images( void* attributeData ){return begin__library_images(*static_cast<library_images__AttributeData*>(attributeData));}
		bool _data__library_images( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_images( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_IMAGES__ASSET = 82286836;
		virtual bool begin__library_images__asset(){return true;}
		virtual bool end__library_images__asset(){return true;}
	private:
		bool _begin__library_images__asset( void* attributeData ){return begin__library_images__asset();}
		bool _data__library_images__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_images__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_IMAGES__IMAGE = 81856229;
		struct library_images__image__AttributeData
		{
			static const library_images__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__library_images__image( const library_images__image__AttributeData& attributeData ){return true;}
		virtual bool end__library_images__image(){return true;}
	private:
		bool _begin__library_images__image( void* attributeData ){return begin__library_images__image(*static_cast<library_images__image__AttributeData*>(attributeData));}
		bool _data__library_images__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_images__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images__image();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_IMAGES__EXTRA = 82037425;
		struct library_images__extra__AttributeData
		{
			static const library_images__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_images__extra( const library_images__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_images__extra(){return true;}
	private:
		bool _begin__library_images__extra( void* attributeData ){return begin__library_images__extra(*static_cast<library_images__extra__AttributeData*>(attributeData));}
		bool _data__library_images__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_images__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_LIGHTS = 196563299;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_LIGHTS = 7881555;
		struct library_lights__AttributeData
		{
			static const library_lights__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_lights( const library_lights__AttributeData& attributeData ){return true;}
		virtual bool end__library_lights(){return true;}
	private:
		bool _begin__library_lights( void* attributeData ){return begin__library_lights(*static_cast<library_lights__AttributeData*>(attributeData));}
		bool _data__library_lights( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_lights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_lights();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__ASSET = 2998164;
		virtual bool begin__library_lights__asset(){return true;}
		virtual bool end__library_lights__asset(){return true;}
	private:
		bool _begin__library_lights__asset( void* attributeData ){return begin__library_lights__asset();}
		bool _data__library_lights__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_lights__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_lights__asset();

	public:
		static const StringHash HASH_ELEMENT_LIGHT = 7536116;
		static const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__LIGHT = 3664804;
		struct light__AttributeData
		{
			static const light__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__light( const light__AttributeData& attributeData ){return true;}
		virtual bool end__light(){return true;}
	private:
		bool _begin__light( void* attributeData ){return begin__light(*static_cast<light__AttributeData*>(attributeData));}
		bool _data__light( const ParserChar* text, size_t textLength );
		bool _validateBegin__light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light();

	public:
		static const StringHash HASH_ELEMENT_LIGHT__ASSET = 74937956;
		virtual bool begin__light__asset(){return true;}
		virtual bool end__light__asset(){return true;}
	private:
		bool _begin__light__asset( void* attributeData ){return begin__light__asset();}
		bool _data__light__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__light__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__asset();

	public:
		static const StringHash HASH_ELEMENT_LIGHT__TECHNIQUE_COMMON = 9633678;
		virtual bool begin__light__technique_common(){return true;}
		virtual bool end__light__technique_common(){return true;}
	private:
		bool _begin__light__technique_common( void* attributeData ){return begin__light__technique_common();}
		bool _data__light__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__light__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__technique_common();

	public:
		static const StringHash HASH_ELEMENT_AMBIENT = 137952308;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__AMBIENT = 108679732;
		virtual bool begin__technique_common__ambient(){return true;}
		virtual bool end__technique_common__ambient(){return true;}
	private:
		bool _begin__technique_common__ambient( void* attributeData ){return begin__technique_common__ambient();}
		bool _data__technique_common__ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique_common__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__ambient();

	public:
		static const StringHash HASH_ELEMENT_COLOR = 6972258;
		static const StringHash HASH_ELEMENT_AMBIENT__COLOR = 148349506;
		struct ambient__color__AttributeData
		{
			static const ambient__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__ambient__color( const ambient__color__AttributeData& attributeData ){return true;}
		virtual bool end__ambient__color(){return true;}
		virtual bool data__ambient__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__ambient__color( void* attributeData ){return begin__ambient__color(*static_cast<ambient__color__AttributeData*>(attributeData));}
		bool _data__ambient__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__ambient__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ambient__color();

	public:
		static const StringHash HASH_ELEMENT_DIRECTIONAL = 180710604;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DIRECTIONAL = 13053548;
		virtual bool begin__directional(){return true;}
		virtual bool end__directional(){return true;}
	private:
		bool _begin__directional( void* attributeData ){return begin__directional();}
		bool _data__directional( const ParserChar* text, size_t textLength );
		bool _validateBegin__directional( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__directional();

	public:
		static const StringHash HASH_ELEMENT_DIRECTIONAL__COLOR = 152088738;
		struct directional__color__AttributeData
		{
			static const directional__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__directional__color( const directional__color__AttributeData& attributeData ){return true;}
		virtual bool end__directional__color(){return true;}
		virtual bool data__directional__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__directional__color( void* attributeData ){return begin__directional__color(*static_cast<directional__color__AttributeData*>(attributeData));}
		bool _data__directional__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__directional__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__directional__color();

	public:
		static const StringHash HASH_ELEMENT_POINT = 7823444;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__POINT = 173350644;
		virtual bool begin__point(){return true;}
		virtual bool end__point(){return true;}
	private:
		bool _begin__point( void* attributeData ){return begin__point();}
		bool _data__point( const ParserChar* text, size_t textLength );
		bool _validateBegin__point( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point();

	public:
		static const StringHash HASH_ELEMENT_POINT__COLOR = 70281410;
		struct point__color__AttributeData
		{
			static const point__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__point__color( const point__color__AttributeData& attributeData ){return true;}
		virtual bool end__point__color(){return true;}
		virtual bool data__point__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__point__color( void* attributeData ){return begin__point__color(*static_cast<point__color__AttributeData*>(attributeData));}
		bool _data__point__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__point__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__color();

	public:
		static const StringHash HASH_ELEMENT_CONSTANT_ATTENUATION = 96122782;
		static const StringHash HASH_ELEMENT_POINT__CONSTANT_ATTENUATION = 98628030;
		struct point__constant_attenuation__AttributeData
		{
			static const point__constant_attenuation__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__point__constant_attenuation( const point__constant_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__point__constant_attenuation(){return true;}
		virtual bool data__point__constant_attenuation( const void* data, size_t length ){return true;}
	private:
		bool _begin__point__constant_attenuation( void* attributeData ){return begin__point__constant_attenuation(*static_cast<point__constant_attenuation__AttributeData*>(attributeData));}
		bool _data__point__constant_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__point__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__constant_attenuation();

	public:
		static const StringHash HASH_ELEMENT_LINEAR_ATTENUATION = 80764702;
		static const StringHash HASH_ELEMENT_POINT__LINEAR_ATTENUATION = 11535838;
		struct point__linear_attenuation__AttributeData
		{
			static const point__linear_attenuation__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__point__linear_attenuation( const point__linear_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__point__linear_attenuation(){return true;}
		virtual bool data__point__linear_attenuation( const void* data, size_t length ){return true;}
	private:
		bool _begin__point__linear_attenuation( void* attributeData ){return begin__point__linear_attenuation(*static_cast<point__linear_attenuation__AttributeData*>(attributeData));}
		bool _data__point__linear_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__point__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__linear_attenuation();

	public:
		static const StringHash HASH_ELEMENT_QUADRATIC_ATTENUATION = 89712814;
		static const StringHash HASH_ELEMENT_POINT__QUADRATIC_ATTENUATION = 251429214;
		struct point__quadratic_attenuation__AttributeData
		{
			static const point__quadratic_attenuation__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__point__quadratic_attenuation( const point__quadratic_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__point__quadratic_attenuation(){return true;}
		virtual bool data__point__quadratic_attenuation( const void* data, size_t length ){return true;}
	private:
		bool _begin__point__quadratic_attenuation( void* attributeData ){return begin__point__quadratic_attenuation(*static_cast<point__quadratic_attenuation__AttributeData*>(attributeData));}
		bool _data__point__quadratic_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__point__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__quadratic_attenuation();

	public:
		static const StringHash HASH_ELEMENT_SPOT = 501604;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPOT = 178619204;
		virtual bool begin__spot(){return true;}
		virtual bool end__spot(){return true;}
	private:
		bool _begin__spot( void* attributeData ){return begin__spot();}
		bool _data__spot( const ParserChar* text, size_t textLength );
		bool _validateBegin__spot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot();

	public:
		static const StringHash HASH_ELEMENT_SPOT__COLOR = 86259138;
		struct spot__color__AttributeData
		{
			static const spot__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__spot__color( const spot__color__AttributeData& attributeData ){return true;}
		virtual bool end__spot__color(){return true;}
		virtual bool data__spot__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__spot__color( void* attributeData ){return begin__spot__color(*static_cast<spot__color__AttributeData*>(attributeData));}
		bool _data__spot__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__spot__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__color();

	public:
		static const StringHash HASH_ELEMENT_SPOT__CONSTANT_ATTENUATION = 248571118;
		struct spot__constant_attenuation__AttributeData
		{
			static const spot__constant_attenuation__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__spot__constant_attenuation( const spot__constant_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__spot__constant_attenuation(){return true;}
		virtual bool data__spot__constant_attenuation( const void* data, size_t length ){return true;}
	private:
		bool _begin__spot__constant_attenuation( void* attributeData ){return begin__spot__constant_attenuation(*static_cast<spot__constant_attenuation__AttributeData*>(attributeData));}
		bool _data__spot__constant_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__spot__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__constant_attenuation();

	public:
		static const StringHash HASH_ELEMENT_SPOT__LINEAR_ATTENUATION = 6894894;
		struct spot__linear_attenuation__AttributeData
		{
			static const spot__linear_attenuation__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__spot__linear_attenuation( const spot__linear_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__spot__linear_attenuation(){return true;}
		virtual bool data__spot__linear_attenuation( const void* data, size_t length ){return true;}
	private:
		bool _begin__spot__linear_attenuation( void* attributeData ){return begin__spot__linear_attenuation(*static_cast<spot__linear_attenuation__AttributeData*>(attributeData));}
		bool _data__spot__linear_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__spot__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__linear_attenuation();

	public:
		static const StringHash HASH_ELEMENT_SPOT__QUADRATIC_ATTENUATION = 268275406;
		struct spot__quadratic_attenuation__AttributeData
		{
			static const spot__quadratic_attenuation__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__spot__quadratic_attenuation( const spot__quadratic_attenuation__AttributeData& attributeData ){return true;}
		virtual bool end__spot__quadratic_attenuation(){return true;}
		virtual bool data__spot__quadratic_attenuation( const void* data, size_t length ){return true;}
	private:
		bool _begin__spot__quadratic_attenuation( void* attributeData ){return begin__spot__quadratic_attenuation(*static_cast<spot__quadratic_attenuation__AttributeData*>(attributeData));}
		bool _data__spot__quadratic_attenuation( const ParserChar* text, size_t textLength );
		bool _validateBegin__spot__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__quadratic_attenuation();

	public:
		static const StringHash HASH_ELEMENT_FALLOFF_ANGLE = 148208005;
		static const StringHash HASH_ELEMENT_SPOT__FALLOFF_ANGLE = 239328965;
		struct falloff_angle__AttributeData
		{
			static const falloff_angle__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__falloff_angle( const falloff_angle__AttributeData& attributeData ){return true;}
		virtual bool end__falloff_angle(){return true;}
		virtual bool data__falloff_angle( const void* data, size_t length ){return true;}
	private:
		bool _begin__falloff_angle( void* attributeData ){return begin__falloff_angle(*static_cast<falloff_angle__AttributeData*>(attributeData));}
		bool _data__falloff_angle( const ParserChar* text, size_t textLength );
		bool _validateBegin__falloff_angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__falloff_angle();

	public:
		static const StringHash HASH_ELEMENT_FALLOFF_EXPONENT = 206620580;
		static const StringHash HASH_ELEMENT_SPOT__FALLOFF_EXPONENT = 108835012;
		struct falloff_exponent__AttributeData
		{
			static const falloff_exponent__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__falloff_exponent( const falloff_exponent__AttributeData& attributeData ){return true;}
		virtual bool end__falloff_exponent(){return true;}
		virtual bool data__falloff_exponent( const void* data, size_t length ){return true;}
	private:
		bool _begin__falloff_exponent( void* attributeData ){return begin__falloff_exponent(*static_cast<falloff_exponent__AttributeData*>(attributeData));}
		bool _data__falloff_exponent( const ParserChar* text, size_t textLength );
		bool _validateBegin__falloff_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__falloff_exponent();

	public:
		static const StringHash HASH_ELEMENT_LIGHT__TECHNIQUE = 105991637;
		struct light__technique__AttributeData
		{
			static const light__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__light__technique( const light__technique__AttributeData& attributeData ){return true;}
		virtual bool end__light__technique(){return true;}
	private:
		bool _begin__light__technique( void* attributeData ){return begin__light__technique(*static_cast<light__technique__AttributeData*>(attributeData));}
		bool _data__light__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__light__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__technique();

	public:
		static const StringHash HASH_ELEMENT_LIGHT__EXTRA = 74654753;
		struct light__extra__AttributeData
		{
			static const light__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__light__extra( const light__extra__AttributeData& attributeData ){return true;}
		virtual bool end__light__extra(){return true;}
	private:
		bool _begin__light__extra( void* attributeData ){return begin__light__extra(*static_cast<light__extra__AttributeData*>(attributeData));}
		bool _data__light__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__light__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__EXTRA = 2747857;
		struct library_lights__extra__AttributeData
		{
			static const library_lights__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_lights__extra( const library_lights__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_lights__extra(){return true;}
	private:
		bool _begin__library_lights__extra( void* attributeData ){return begin__library_lights__extra(*static_cast<library_lights__extra__AttributeData*>(attributeData));}
		bool _data__library_lights__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_lights__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_lights__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_MATERIALS = 35999283;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_MATERIALS = 50787011;
		struct library_materials__AttributeData
		{
			static const library_materials__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_materials( const library_materials__AttributeData& attributeData ){return true;}
		virtual bool end__library_materials(){return true;}
	private:
		bool _begin__library_materials( void* attributeData ){return begin__library_materials(*static_cast<library_materials__AttributeData*>(attributeData));}
		bool _data__library_materials( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_materials();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__ASSET = 118246004;
		virtual bool begin__library_materials__asset(){return true;}
		virtual bool end__library_materials__asset(){return true;}
	private:
		bool _begin__library_materials__asset( void* attributeData ){return begin__library_materials__asset();}
		bool _data__library_materials__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_materials__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_materials__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__EXTRA = 117970993;
		struct library_materials__extra__AttributeData
		{
			static const library_materials__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_materials__extra( const library_materials__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_materials__extra(){return true;}
	private:
		bool _begin__library_materials__extra( void* attributeData ){return begin__library_materials__extra(*static_cast<library_materials__extra__AttributeData*>(attributeData));}
		bool _data__library_materials__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_materials__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_materials__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_NODES = 230609443;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_NODES = 235021059;
		struct library_nodes__AttributeData
		{
			static const library_nodes__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_nodes( const library_nodes__AttributeData& attributeData ){return true;}
		virtual bool end__library_nodes(){return true;}
	private:
		bool _begin__library_nodes( void* attributeData ){return begin__library_nodes(*static_cast<library_nodes__AttributeData*>(attributeData));}
		bool _data__library_nodes( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_nodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_NODES__ASSET = 11897780;
		virtual bool begin__library_nodes__asset(){return true;}
		virtual bool end__library_nodes__asset(){return true;}
	private:
		bool _begin__library_nodes__asset( void* attributeData ){return begin__library_nodes__asset();}
		bool _data__library_nodes__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_nodes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_NODES__NODE = 118269829;
		struct library_nodes__node__AttributeData
		{
			static const library_nodes__node__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* sid;
			const ParserChar* type;
			const ParserChar* layer;
		};
		virtual bool begin__library_nodes__node( const library_nodes__node__AttributeData& attributeData ){return true;}
		virtual bool end__library_nodes__node(){return true;}
	private:
		bool _begin__library_nodes__node( void* attributeData ){return begin__library_nodes__node(*static_cast<library_nodes__node__AttributeData*>(attributeData));}
		bool _data__library_nodes__node( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_nodes__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes__node();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_NODES__EXTRA = 11655665;
		struct library_nodes__extra__AttributeData
		{
			static const library_nodes__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_nodes__extra( const library_nodes__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_nodes__extra(){return true;}
	private:
		bool _begin__library_nodes__extra( void* attributeData ){return begin__library_nodes__extra(*static_cast<library_nodes__extra__AttributeData*>(attributeData));}
		bool _data__library_nodes__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_nodes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS = 149953987;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_MATERIALS = 144977635;
		struct library_physics_materials__AttributeData
		{
			static const library_physics_materials__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_physics_materials( const library_physics_materials__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_materials(){return true;}
	private:
		bool _begin__library_physics_materials( void* attributeData ){return begin__library_physics_materials(*static_cast<library_physics_materials__AttributeData*>(attributeData));}
		bool _data__library_physics_materials( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__ASSET = 207189460;
		virtual bool begin__library_physics_materials__asset(){return true;}
		virtual bool end__library_physics_materials__asset(){return true;}
	private:
		bool _begin__library_physics_materials__asset( void* attributeData ){return begin__library_physics_materials__asset();}
		bool _data__library_physics_materials__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_materials__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL = 9537676;
		struct library_physics_materials__physics_material__AttributeData
		{
			static const library_physics_materials__physics_material__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_physics_materials__physics_material( const library_physics_materials__physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_materials__physics_material(){return true;}
	private:
		bool _begin__library_physics_materials__physics_material( void* attributeData ){return begin__library_physics_materials__physics_material(*static_cast<library_physics_materials__physics_material__AttributeData*>(attributeData));}
		bool _data__library_physics_materials__physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_materials__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials__physics_material();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA = 207431569;
		struct library_physics_materials__extra__AttributeData
		{
			static const library_physics_materials__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_physics_materials__extra( const library_physics_materials__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_materials__extra(){return true;}
	private:
		bool _begin__library_physics_materials__extra( void* attributeData ){return begin__library_physics_materials__extra(*static_cast<library_physics_materials__extra__AttributeData*>(attributeData));}
		bool _data__library_physics_materials__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_materials__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS = 247630259;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_MODELS = 229674739;
		struct library_physics_models__AttributeData
		{
			static const library_physics_models__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_physics_models( const library_physics_models__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_models(){return true;}
	private:
		bool _begin__library_physics_models( void* attributeData ){return begin__library_physics_models(*static_cast<library_physics_models__AttributeData*>(attributeData));}
		bool _data__library_physics_models( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_models();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__ASSET = 158347956;
		virtual bool begin__library_physics_models__asset(){return true;}
		virtual bool end__library_physics_models__asset(){return true;}
	private:
		bool _begin__library_physics_models__asset( void* attributeData ){return begin__library_physics_models__asset();}
		bool _data__library_physics_models__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_models__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_models__asset();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MODEL = 6604124;
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__PHYSICS_MODEL = 121224284;
		struct physics_model__AttributeData
		{
			static const physics_model__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__physics_model( const physics_model__AttributeData& attributeData ){return true;}
		virtual bool end__physics_model(){return true;}
	private:
		bool _begin__physics_model( void* attributeData ){return begin__physics_model(*static_cast<physics_model__AttributeData*>(attributeData));}
		bool _data__physics_model( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MODEL__ASSET = 51707876;
		virtual bool begin__physics_model__asset(){return true;}
		virtual bool end__physics_model__asset(){return true;}
	private:
		bool _begin__physics_model__asset( void* attributeData ){return begin__physics_model__asset();}
		bool _data__physics_model__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_model__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model__asset();

	public:
		static const StringHash HASH_ELEMENT_RIGID_BODY = 262281833;
		static const StringHash HASH_ELEMENT_PHYSICS_MODEL__RIGID_BODY = 230153993;
		struct rigid_body__AttributeData
		{
			static const rigid_body__AttributeData DEFAULT;

			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__rigid_body( const rigid_body__AttributeData& attributeData ){return true;}
		virtual bool end__rigid_body(){return true;}
	private:
		bool _begin__rigid_body( void* attributeData ){return begin__rigid_body(*static_cast<rigid_body__AttributeData*>(attributeData));}
		bool _data__rigid_body( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body();

	public:
		static const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON = 140646974;
		virtual bool begin__rigid_body__technique_common(){return true;}
		virtual bool end__rigid_body__technique_common(){return true;}
	private:
		bool _begin__rigid_body__technique_common( void* attributeData ){return begin__rigid_body__technique_common();}
		bool _data__rigid_body__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body__technique_common();

	public:
		static const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE = 266093477;
		struct rigid_body__technique__AttributeData
		{
			static const rigid_body__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__rigid_body__technique( const rigid_body__technique__AttributeData& attributeData ){return true;}
		virtual bool end__rigid_body__technique(){return true;}
	private:
		bool _begin__rigid_body__technique( void* attributeData ){return begin__rigid_body__technique(*static_cast<rigid_body__technique__AttributeData*>(attributeData));}
		bool _data__rigid_body__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_body__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body__technique();

	public:
		static const StringHash HASH_ELEMENT_RIGID_BODY__EXTRA = 259874209;
		struct rigid_body__extra__AttributeData
		{
			static const rigid_body__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__rigid_body__extra( const rigid_body__extra__AttributeData& attributeData ){return true;}
		virtual bool end__rigid_body__extra(){return true;}
	private:
		bool _begin__rigid_body__extra( void* attributeData ){return begin__rigid_body__extra(*static_cast<rigid_body__extra__AttributeData*>(attributeData));}
		bool _data__rigid_body__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_body__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body__extra();

	public:
		static const StringHash HASH_ELEMENT_RIGID_CONSTRAINT = 85611988;
		static const StringHash HASH_ELEMENT_PHYSICS_MODEL__RIGID_CONSTRAINT = 118460596;
		struct rigid_constraint__AttributeData
		{
			static const rigid_constraint__AttributeData DEFAULT;

			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__rigid_constraint( const rigid_constraint__AttributeData& attributeData ){return true;}
		virtual bool end__rigid_constraint(){return true;}
	private:
		bool _begin__rigid_constraint( void* attributeData ){return begin__rigid_constraint(*static_cast<rigid_constraint__AttributeData*>(attributeData));}
		bool _data__rigid_constraint( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint();

	public:
		static const StringHash HASH_ELEMENT_REF_ATTACHMENT = 207403124;
		static const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__REF_ATTACHMENT = 166190372;
		static const StringHash HASH_ATTRIBUTE_RIGID_BODY = 262281833;
		struct ref_attachment__AttributeData
		{
			static const ref_attachment__AttributeData DEFAULT;

			const ParserChar* rigid_body;
		};
		virtual bool begin__ref_attachment( const ref_attachment__AttributeData& attributeData ){return true;}
		virtual bool end__ref_attachment(){return true;}
	private:
		bool _begin__ref_attachment( void* attributeData ){return begin__ref_attachment(*static_cast<ref_attachment__AttributeData*>(attributeData));}
		bool _data__ref_attachment( const ParserChar* text, size_t textLength );
		bool _validateBegin__ref_attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment();

	public:
		static const StringHash HASH_ELEMENT_REF_ATTACHMENT__TRANSLATE = 20744357;
		struct ref_attachment__translate__AttributeData
		{
			static const ref_attachment__translate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__ref_attachment__translate( const ref_attachment__translate__AttributeData& attributeData ){return true;}
		virtual bool end__ref_attachment__translate(){return true;}
		virtual bool data__ref_attachment__translate( const void* data, size_t length ){return true;}
	private:
		bool _begin__ref_attachment__translate( void* attributeData ){return begin__ref_attachment__translate(*static_cast<ref_attachment__translate__AttributeData*>(attributeData));}
		bool _data__ref_attachment__translate( const ParserChar* text, size_t textLength );
		bool _validateBegin__ref_attachment__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment__translate();

	public:
		static const StringHash HASH_ELEMENT_REF_ATTACHMENT__ROTATE = 172940933;
		struct ref_attachment__rotate__AttributeData
		{
			static const ref_attachment__rotate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__ref_attachment__rotate( const ref_attachment__rotate__AttributeData& attributeData ){return true;}
		virtual bool end__ref_attachment__rotate(){return true;}
		virtual bool data__ref_attachment__rotate( const void* data, size_t length ){return true;}
	private:
		bool _begin__ref_attachment__rotate( void* attributeData ){return begin__ref_attachment__rotate(*static_cast<ref_attachment__rotate__AttributeData*>(attributeData));}
		bool _data__ref_attachment__rotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__ref_attachment__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment__rotate();

	public:
		static const StringHash HASH_ELEMENT_REF_ATTACHMENT__EXTRA = 43482337;
		struct ref_attachment__extra__AttributeData
		{
			static const ref_attachment__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__ref_attachment__extra( const ref_attachment__extra__AttributeData& attributeData ){return true;}
		virtual bool end__ref_attachment__extra(){return true;}
	private:
		bool _begin__ref_attachment__extra( void* attributeData ){return begin__ref_attachment__extra(*static_cast<ref_attachment__extra__AttributeData*>(attributeData));}
		bool _data__ref_attachment__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__ref_attachment__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment__extra();

	public:
		static const StringHash HASH_ELEMENT_ATTACHMENT = 127513076;
		static const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__ATTACHMENT = 183690788;
		struct attachment__AttributeData
		{
			static const attachment__AttributeData DEFAULT;

			const ParserChar* rigid_body;
		};
		virtual bool begin__attachment( const attachment__AttributeData& attributeData ){return true;}
		virtual bool end__attachment(){return true;}
	private:
		bool _begin__attachment( void* attributeData ){return begin__attachment(*static_cast<attachment__AttributeData*>(attributeData));}
		bool _data__attachment( const ParserChar* text, size_t textLength );
		bool _validateBegin__attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment();

	public:
		static const StringHash HASH_ELEMENT_ATTACHMENT__TRANSLATE = 162060341;
		struct attachment__translate__AttributeData
		{
			static const attachment__translate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__attachment__translate( const attachment__translate__AttributeData& attributeData ){return true;}
		virtual bool end__attachment__translate(){return true;}
		virtual bool data__attachment__translate( const void* data, size_t length ){return true;}
	private:
		bool _begin__attachment__translate( void* attributeData ){return begin__attachment__translate(*static_cast<attachment__translate__AttributeData*>(attributeData));}
		bool _data__attachment__translate( const ParserChar* text, size_t textLength );
		bool _validateBegin__attachment__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment__translate();

	public:
		static const StringHash HASH_ELEMENT_ATTACHMENT__ROTATE = 256333637;
		struct attachment__rotate__AttributeData
		{
			static const attachment__rotate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__attachment__rotate( const attachment__rotate__AttributeData& attributeData ){return true;}
		virtual bool end__attachment__rotate(){return true;}
		virtual bool data__attachment__rotate( const void* data, size_t length ){return true;}
	private:
		bool _begin__attachment__rotate( void* attributeData ){return begin__attachment__rotate(*static_cast<attachment__rotate__AttributeData*>(attributeData));}
		bool _data__attachment__rotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__attachment__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment__rotate();

	public:
		static const StringHash HASH_ELEMENT_ATTACHMENT__EXTRA = 247981169;
		struct attachment__extra__AttributeData
		{
			static const attachment__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__attachment__extra( const attachment__extra__AttributeData& attributeData ){return true;}
		virtual bool end__attachment__extra(){return true;}
	private:
		bool _begin__attachment__extra( void* attributeData ){return begin__attachment__extra(*static_cast<attachment__extra__AttributeData*>(attributeData));}
		bool _data__attachment__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__attachment__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment__extra();

	public:
		static const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON = 28989358;
		virtual bool begin__rigid_constraint__technique_common(){return true;}
		virtual bool end__rigid_constraint__technique_common(){return true;}
	private:
		bool _begin__rigid_constraint__technique_common( void* attributeData ){return begin__rigid_constraint__technique_common();}
		bool _data__rigid_constraint__technique_common( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_constraint__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint__technique_common();

	public:
		static const StringHash HASH_ELEMENT_ENABLED = 206017236;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ENABLED = 168114388;
		struct enabled__AttributeData
		{
			static const enabled__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__enabled( const enabled__AttributeData& attributeData ){return true;}
		virtual bool end__enabled(){return true;}
		virtual bool data__enabled( const void* data, size_t length ){return true;}
	private:
		bool _begin__enabled( void* attributeData ){return begin__enabled(*static_cast<enabled__AttributeData*>(attributeData));}
		bool _data__enabled( const ParserChar* text, size_t textLength );
		bool _validateBegin__enabled( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__enabled();

	public:
		static const StringHash HASH_ELEMENT_INTERPENETRATE = 23533925;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INTERPENETRATE = 88979653;
		struct interpenetrate__AttributeData
		{
			static const interpenetrate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__interpenetrate( const interpenetrate__AttributeData& attributeData ){return true;}
		virtual bool end__interpenetrate(){return true;}
		virtual bool data__interpenetrate( const void* data, size_t length ){return true;}
	private:
		bool _begin__interpenetrate( void* attributeData ){return begin__interpenetrate(*static_cast<interpenetrate__AttributeData*>(attributeData));}
		bool _data__interpenetrate( const ParserChar* text, size_t textLength );
		bool _validateBegin__interpenetrate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__interpenetrate();

	public:
		static const StringHash HASH_ELEMENT_LIMITS = 120602803;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__LIMITS = 118237715;
		virtual bool begin__limits(){return true;}
		virtual bool end__limits(){return true;}
	private:
		bool _begin__limits( void* attributeData ){return begin__limits();}
		bool _data__limits( const ParserChar* text, size_t textLength );
		bool _validateBegin__limits( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__limits();

	public:
		static const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST = 103048868;
		static const StringHash HASH_ELEMENT_LIMITS__SWING_CONE_AND_TWIST = 23389540;
		virtual bool begin__swing_cone_and_twist(){return true;}
		virtual bool end__swing_cone_and_twist(){return true;}
	private:
		bool _begin__swing_cone_and_twist( void* attributeData ){return begin__swing_cone_and_twist();}
		bool _data__swing_cone_and_twist( const ParserChar* text, size_t textLength );
		bool _validateBegin__swing_cone_and_twist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__swing_cone_and_twist();

	public:
		static const StringHash HASH_ELEMENT_MIN = 29694;
		static const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MIN = 185017758;
		struct swing_cone_and_twist__min__AttributeData
		{
			static const swing_cone_and_twist__min__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__swing_cone_and_twist__min( const swing_cone_and_twist__min__AttributeData& attributeData ){return true;}
		virtual bool end__swing_cone_and_twist__min(){return true;}
		virtual bool data__swing_cone_and_twist__min( const void* data, size_t length ){return true;}
	private:
		bool _begin__swing_cone_and_twist__min( void* attributeData ){return begin__swing_cone_and_twist__min(*static_cast<swing_cone_and_twist__min__AttributeData*>(attributeData));}
		bool _data__swing_cone_and_twist__min( const ParserChar* text, size_t textLength );
		bool _validateBegin__swing_cone_and_twist__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__swing_cone_and_twist__min();

	public:
		static const StringHash HASH_ELEMENT_MAX = 29576;
		static const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MAX = 185017832;
		struct swing_cone_and_twist__max__AttributeData
		{
			static const swing_cone_and_twist__max__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__swing_cone_and_twist__max( const swing_cone_and_twist__max__AttributeData& attributeData ){return true;}
		virtual bool end__swing_cone_and_twist__max(){return true;}
		virtual bool data__swing_cone_and_twist__max( const void* data, size_t length ){return true;}
	private:
		bool _begin__swing_cone_and_twist__max( void* attributeData ){return begin__swing_cone_and_twist__max(*static_cast<swing_cone_and_twist__max__AttributeData*>(attributeData));}
		bool _data__swing_cone_and_twist__max( const ParserChar* text, size_t textLength );
		bool _validateBegin__swing_cone_and_twist__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__swing_cone_and_twist__max();

	public:
		static const StringHash HASH_ELEMENT_LINEAR = 120605570;
		static const StringHash HASH_ELEMENT_LIMITS__LINEAR = 108038914;
		virtual bool begin__limits__linear(){return true;}
		virtual bool end__limits__linear(){return true;}
	private:
		bool _begin__limits__linear( void* attributeData ){return begin__limits__linear();}
		bool _data__limits__linear( const ParserChar* text, size_t textLength );
		bool _validateBegin__limits__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__limits__linear();

	public:
		static const StringHash HASH_ELEMENT_LINEAR__MIN = 135817038;
		struct linear__min__AttributeData
		{
			static const linear__min__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__linear__min( const linear__min__AttributeData& attributeData ){return true;}
		virtual bool end__linear__min(){return true;}
		virtual bool data__linear__min( const void* data, size_t length ){return true;}
	private:
		bool _begin__linear__min( void* attributeData ){return begin__linear__min(*static_cast<linear__min__AttributeData*>(attributeData));}
		bool _data__linear__min( const ParserChar* text, size_t textLength );
		bool _validateBegin__linear__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__min();

	public:
		static const StringHash HASH_ELEMENT_LINEAR__MAX = 135817016;
		struct linear__max__AttributeData
		{
			static const linear__max__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__linear__max( const linear__max__AttributeData& attributeData ){return true;}
		virtual bool end__linear__max(){return true;}
		virtual bool data__linear__max( const void* data, size_t length ){return true;}
	private:
		bool _begin__linear__max( void* attributeData ){return begin__linear__max(*static_cast<linear__max__AttributeData*>(attributeData));}
		bool _data__linear__max( const ParserChar* text, size_t textLength );
		bool _validateBegin__linear__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__max();

	public:
		static const StringHash HASH_ELEMENT_SPRING = 128421959;
		static const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPRING = 92514023;
		virtual bool begin__spring(){return true;}
		virtual bool end__spring(){return true;}
	private:
		bool _begin__spring( void* attributeData ){return begin__spring();}
		bool _data__spring( const ParserChar* text, size_t textLength );
		bool _validateBegin__spring( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spring();

	public:
		static const StringHash HASH_ELEMENT_ANGULAR = 139379426;
		static const StringHash HASH_ELEMENT_SPRING__ANGULAR = 256544162;
		virtual bool begin__angular(){return true;}
		virtual bool end__angular(){return true;}
	private:
		bool _begin__angular( void* attributeData ){return begin__angular();}
		bool _data__angular( const ParserChar* text, size_t textLength );
		bool _validateBegin__angular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular();

	public:
		static const StringHash HASH_ELEMENT_STIFFNESS = 265106947;
		static const StringHash HASH_ELEMENT_ANGULAR__STIFFNESS = 13552163;
		struct angular__stiffness__AttributeData
		{
			static const angular__stiffness__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__angular__stiffness( const angular__stiffness__AttributeData& attributeData ){return true;}
		virtual bool end__angular__stiffness(){return true;}
		virtual bool data__angular__stiffness( const void* data, size_t length ){return true;}
	private:
		bool _begin__angular__stiffness( void* attributeData ){return begin__angular__stiffness(*static_cast<angular__stiffness__AttributeData*>(attributeData));}
		bool _data__angular__stiffness( const ParserChar* text, size_t textLength );
		bool _validateBegin__angular__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular__stiffness();

	public:
		static const StringHash HASH_ELEMENT_DAMPING = 176451623;
		static const StringHash HASH_ELEMENT_ANGULAR__DAMPING = 107704311;
		struct angular__damping__AttributeData
		{
			static const angular__damping__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__angular__damping( const angular__damping__AttributeData& attributeData ){return true;}
		virtual bool end__angular__damping(){return true;}
		virtual bool data__angular__damping( const void* data, size_t length ){return true;}
	private:
		bool _begin__angular__damping( void* attributeData ){return begin__angular__damping(*static_cast<angular__damping__AttributeData*>(attributeData));}
		bool _data__angular__damping( const ParserChar* text, size_t textLength );
		bool _validateBegin__angular__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular__damping();

	public:
		static const StringHash HASH_ELEMENT_TARGET_VALUE = 264572533;
		static const StringHash HASH_ELEMENT_ANGULAR__TARGET_VALUE = 33955429;
		struct angular__target_value__AttributeData
		{
			static const angular__target_value__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__angular__target_value( const angular__target_value__AttributeData& attributeData ){return true;}
		virtual bool end__angular__target_value(){return true;}
		virtual bool data__angular__target_value( const void* data, size_t length ){return true;}
	private:
		bool _begin__angular__target_value( void* attributeData ){return begin__angular__target_value(*static_cast<angular__target_value__AttributeData*>(attributeData));}
		bool _data__angular__target_value( const ParserChar* text, size_t textLength );
		bool _validateBegin__angular__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular__target_value();

	public:
		static const StringHash HASH_ELEMENT_SPRING__LINEAR = 62916466;
		virtual bool begin__spring__linear(){return true;}
		virtual bool end__spring__linear(){return true;}
	private:
		bool _begin__spring__linear( void* attributeData ){return begin__spring__linear();}
		bool _data__spring__linear( const ParserChar* text, size_t textLength );
		bool _validateBegin__spring__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spring__linear();

	public:
		static const StringHash HASH_ELEMENT_LINEAR__STIFFNESS = 131408563;
		struct linear__stiffness__AttributeData
		{
			static const linear__stiffness__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__linear__stiffness( const linear__stiffness__AttributeData& attributeData ){return true;}
		virtual bool end__linear__stiffness(){return true;}
		virtual bool data__linear__stiffness( const void* data, size_t length ){return true;}
	private:
		bool _begin__linear__stiffness( void* attributeData ){return begin__linear__stiffness(*static_cast<linear__stiffness__AttributeData*>(attributeData));}
		bool _data__linear__stiffness( const ParserChar* text, size_t textLength );
		bool _validateBegin__linear__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__stiffness();

	public:
		static const StringHash HASH_ELEMENT_LINEAR__DAMPING = 249329687;
		struct linear__damping__AttributeData
		{
			static const linear__damping__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__linear__damping( const linear__damping__AttributeData& attributeData ){return true;}
		virtual bool end__linear__damping(){return true;}
		virtual bool data__linear__damping( const void* data, size_t length ){return true;}
	private:
		bool _begin__linear__damping( void* attributeData ){return begin__linear__damping(*static_cast<linear__damping__AttributeData*>(attributeData));}
		bool _data__linear__damping( const ParserChar* text, size_t textLength );
		bool _validateBegin__linear__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__damping();

	public:
		static const StringHash HASH_ELEMENT_LINEAR__TARGET_VALUE = 9408485;
		struct linear__target_value__AttributeData
		{
			static const linear__target_value__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__linear__target_value( const linear__target_value__AttributeData& attributeData ){return true;}
		virtual bool end__linear__target_value(){return true;}
		virtual bool data__linear__target_value( const void* data, size_t length ){return true;}
	private:
		bool _begin__linear__target_value( void* attributeData ){return begin__linear__target_value(*static_cast<linear__target_value__AttributeData*>(attributeData));}
		bool _data__linear__target_value( const ParserChar* text, size_t textLength );
		bool _validateBegin__linear__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__target_value();

	public:
		static const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE = 71550805;
		struct rigid_constraint__technique__AttributeData
		{
			static const rigid_constraint__technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__rigid_constraint__technique( const rigid_constraint__technique__AttributeData& attributeData ){return true;}
		virtual bool end__rigid_constraint__technique(){return true;}
	private:
		bool _begin__rigid_constraint__technique( void* attributeData ){return begin__rigid_constraint__technique(*static_cast<rigid_constraint__technique__AttributeData*>(attributeData));}
		bool _data__rigid_constraint__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_constraint__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint__technique();

	public:
		static const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__EXTRA = 117024337;
		struct rigid_constraint__extra__AttributeData
		{
			static const rigid_constraint__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__rigid_constraint__extra( const rigid_constraint__extra__AttributeData& attributeData ){return true;}
		virtual bool end__rigid_constraint__extra(){return true;}
	private:
		bool _begin__rigid_constraint__extra( void* attributeData ){return begin__rigid_constraint__extra(*static_cast<rigid_constraint__extra__AttributeData*>(attributeData));}
		bool _data__rigid_constraint__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__rigid_constraint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint__extra();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL = 133635772;
		struct physics_model__instance_physics_model__AttributeData
		{
			static const physics_model__instance_physics_model__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
			const ParserChar* parent;
		};
		virtual bool begin__physics_model__instance_physics_model( const physics_model__instance_physics_model__AttributeData& attributeData ){return true;}
		virtual bool end__physics_model__instance_physics_model(){return true;}
	private:
		bool _begin__physics_model__instance_physics_model( void* attributeData ){return begin__physics_model__instance_physics_model(*static_cast<physics_model__instance_physics_model__AttributeData*>(attributeData));}
		bool _data__physics_model__instance_physics_model( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_model__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model__instance_physics_model();

	public:
		static const StringHash HASH_ELEMENT_PHYSICS_MODEL__EXTRA = 51424673;
		struct physics_model__extra__AttributeData
		{
			static const physics_model__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__physics_model__extra( const physics_model__extra__AttributeData& attributeData ){return true;}
		virtual bool end__physics_model__extra(){return true;}
	private:
		bool _begin__physics_model__extra( void* attributeData ){return begin__physics_model__extra(*static_cast<physics_model__extra__AttributeData*>(attributeData));}
		bool _data__physics_model__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_model__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA = 158621937;
		struct library_physics_models__extra__AttributeData
		{
			static const library_physics_models__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_physics_models__extra( const library_physics_models__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_physics_models__extra(){return true;}
	private:
		bool _begin__library_physics_models__extra( void* attributeData ){return begin__library_physics_models__extra(*static_cast<library_physics_models__extra__AttributeData*>(attributeData));}
		bool _data__library_physics_models__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_physics_models__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_models__extra();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES = 1834835;
		static const StringHash HASH_ELEMENT_COLLADA__LIBRARY_VISUAL_SCENES = 216719139;
		struct library_visual_scenes__AttributeData
		{
			static const library_visual_scenes__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__library_visual_scenes( const library_visual_scenes__AttributeData& attributeData ){return true;}
		virtual bool end__library_visual_scenes(){return true;}
	private:
		bool _begin__library_visual_scenes( void* attributeData ){return begin__library_visual_scenes(*static_cast<library_visual_scenes__AttributeData*>(attributeData));}
		bool _data__library_visual_scenes( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_visual_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_visual_scenes();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__ASSET = 115825748;
		virtual bool begin__library_visual_scenes__asset(){return true;}
		virtual bool end__library_visual_scenes__asset(){return true;}
	private:
		bool _begin__library_visual_scenes__asset( void* attributeData ){return begin__library_visual_scenes__asset();}
		bool _data__library_visual_scenes__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_visual_scenes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_visual_scenes__asset();

	public:
		static const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA = 115543569;
		struct library_visual_scenes__extra__AttributeData
		{
			static const library_visual_scenes__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__library_visual_scenes__extra( const library_visual_scenes__extra__AttributeData& attributeData ){return true;}
		virtual bool end__library_visual_scenes__extra(){return true;}
	private:
		bool _begin__library_visual_scenes__extra( void* attributeData ){return begin__library_visual_scenes__extra(*static_cast<library_visual_scenes__extra__AttributeData*>(attributeData));}
		bool _data__library_visual_scenes__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__library_visual_scenes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_visual_scenes__extra();

	public:
		static const StringHash HASH_ELEMENT_SCENE = 7969861;
		static const StringHash HASH_ELEMENT_COLLADA__SCENE = 24758453;
		virtual bool begin__scene(){return true;}
		virtual bool end__scene(){return true;}
	private:
		bool _begin__scene( void* attributeData ){return begin__scene();}
		bool _data__scene( const ParserChar* text, size_t textLength );
		bool _validateBegin__scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scene();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_SCENE = 99263781;
		static const StringHash HASH_ELEMENT_SCENE__INSTANCE_PHYSICS_SCENE = 10609013;
		struct instance_physics_scene__AttributeData
		{
			static const instance_physics_scene__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_physics_scene( const instance_physics_scene__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_scene(){return true;}
	private:
		bool _begin__instance_physics_scene( void* attributeData ){return begin__instance_physics_scene(*static_cast<instance_physics_scene__AttributeData*>(attributeData));}
		bool _data__instance_physics_scene( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_scene();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_SCENE__EXTRA = 200714369;
		struct instance_physics_scene__extra__AttributeData
		{
			static const instance_physics_scene__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_physics_scene__extra( const instance_physics_scene__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_scene__extra(){return true;}
	private:
		bool _begin__instance_physics_scene__extra( void* attributeData ){return begin__instance_physics_scene__extra(*static_cast<instance_physics_scene__extra__AttributeData*>(attributeData));}
		bool _data__instance_physics_scene__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_scene__extra();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_VISUAL_SCENE = 235998149;
		static const StringHash HASH_ELEMENT_SCENE__INSTANCE_VISUAL_SCENE = 177061637;
		struct instance_visual_scene__AttributeData
		{
			static const instance_visual_scene__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_visual_scene( const instance_visual_scene__AttributeData& attributeData ){return true;}
		virtual bool end__instance_visual_scene(){return true;}
	private:
		bool _begin__instance_visual_scene( void* attributeData ){return begin__instance_visual_scene(*static_cast<instance_visual_scene__AttributeData*>(attributeData));}
		bool _data__instance_visual_scene( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_visual_scene();

	public:
		static const StringHash HASH_ELEMENT_INSTANCE_VISUAL_SCENE__EXTRA = 105662417;
		struct instance_visual_scene__extra__AttributeData
		{
			static const instance_visual_scene__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__instance_visual_scene__extra( const instance_visual_scene__extra__AttributeData& attributeData ){return true;}
		virtual bool end__instance_visual_scene__extra(){return true;}
	private:
		bool _begin__instance_visual_scene__extra( void* attributeData ){return begin__instance_visual_scene__extra(*static_cast<instance_visual_scene__extra__AttributeData*>(attributeData));}
		bool _data__instance_visual_scene__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_visual_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_visual_scene__extra();

	public:
		static const StringHash HASH_ELEMENT_SCENE__EXTRA = 80035633;
		struct scene__extra__AttributeData
		{
			static const scene__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__scene__extra( const scene__extra__AttributeData& attributeData ){return true;}
		virtual bool end__scene__extra(){return true;}
	private:
		bool _begin__scene__extra( void* attributeData ){return begin__scene__extra(*static_cast<scene__extra__AttributeData*>(attributeData));}
		bool _data__scene__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scene__extra();

	public:
		static const StringHash HASH_ELEMENT_COLLADA__EXTRA = 21800817;
		struct COLLADA__extra__AttributeData
		{
			static const COLLADA__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__COLLADA__extra( const COLLADA__extra__AttributeData& attributeData ){return true;}
		virtual bool end__COLLADA__extra(){return true;}
	private:
		bool _begin__COLLADA__extra( void* attributeData ){return begin__COLLADA__extra(*static_cast<COLLADA__extra__AttributeData*>(attributeData));}
		bool _data__COLLADA__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__COLLADA__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__COLLADA__extra();

	public:
		struct param__AttributeData
		{
			static const param__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* sid;
			const ParserChar* semantic;
			const ParserChar* type;
		};
		virtual bool begin__param( const param__AttributeData& attributeData ){return true;}
		virtual bool end__param(){return true;}
		virtual bool data__param( const void* data, size_t length ){return true;}
	private:
		bool _begin__param( void* attributeData ){return begin__param(*static_cast<param__AttributeData*>(attributeData));}
		bool _data__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__param();

	public:
		struct instance_geometry__AttributeData
		{
			static const instance_geometry__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_geometry( const instance_geometry__AttributeData& attributeData ){return true;}
		virtual bool end__instance_geometry(){return true;}
	private:
		bool _begin__instance_geometry( void* attributeData ){return begin__instance_geometry(*static_cast<instance_geometry__AttributeData*>(attributeData));}
		bool _data__instance_geometry( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_geometry();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLSL = 99286140;
		struct profile_GLSL__AttributeData
		{
			static const profile_GLSL__AttributeData DEFAULT;

			const ParserChar* id;
		};
		virtual bool begin__profile_GLSL( const profile_GLSL__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL(){return true;}
	private:
		bool _begin__profile_GLSL( void* attributeData ){return begin__profile_GLSL(*static_cast<profile_GLSL__AttributeData*>(attributeData));}
		bool _data__profile_GLSL( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__ASSET = 200761748;
		virtual bool begin__profile_GLSL__asset(){return true;}
		virtual bool end__profile_GLSL__asset(){return true;}
	private:
		bool _begin__profile_GLSL__asset( void* attributeData ){return begin__profile_GLSL__asset();}
		bool _data__profile_GLSL__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__asset();

	public:
		static const StringHash HASH_ELEMENT_CODE = 435621;
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__CODE = 96434469;
		struct profile_GLSL__code__AttributeData
		{
			static const profile_GLSL__code__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__profile_GLSL__code( const profile_GLSL__code__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL__code(){return true;}
		virtual bool data__profile_GLSL__code( const void* data, size_t length ){return true;}
	private:
		bool _begin__profile_GLSL__code( void* attributeData ){return begin__profile_GLSL__code(*static_cast<profile_GLSL__code__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__code( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__code();

	public:
		static const StringHash HASH_ELEMENT_INCLUDE = 4864981;
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__INCLUDE = 25321557;
		struct profile_GLSL__include__AttributeData
		{
			static const profile_GLSL__include__AttributeData DEFAULT;

			const ParserChar* sid;
			const ParserChar* url;
		};
		virtual bool begin__profile_GLSL__include( const profile_GLSL__include__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL__include(){return true;}
	private:
		bool _begin__profile_GLSL__include( void* attributeData ){return begin__profile_GLSL__include(*static_cast<profile_GLSL__include__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__include( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__include();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__IMAGE = 200408965;
		struct profile_GLSL__image__AttributeData
		{
			static const profile_GLSL__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__profile_GLSL__image( const profile_GLSL__image__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL__image(){return true;}
	private:
		bool _begin__profile_GLSL__image( void* attributeData ){return begin__profile_GLSL__image(*static_cast<profile_GLSL__image__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__image();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__NEWPARAM = 6506701;
		struct profile_GLSL__newparam__AttributeData
		{
			static const profile_GLSL__newparam__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__profile_GLSL__newparam( const profile_GLSL__newparam__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL__newparam(){return true;}
	private:
		bool _begin__profile_GLSL__newparam( void* attributeData ){return begin__profile_GLSL__newparam(*static_cast<profile_GLSL__newparam__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__newparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__newparam();

	public:
		static const StringHash HASH_ELEMENT_ARRAY = 6854793;
		static const StringHash HASH_ELEMENT_NEWPARAM__ARRAY = 187722873;
		static const StringHash HASH_ATTRIBUTE_LENGTH = 120344232;
		struct newparam__array__AttributeData
		{
			static const newparam__array__AttributeData DEFAULT;

			long length;
		};
		virtual bool begin__newparam__array( const newparam__array__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__array(){return true;}
	private:
		bool _begin__newparam__array( void* attributeData ){return begin__newparam__array(*static_cast<newparam__array__AttributeData*>(attributeData));}
		bool _data__newparam__array( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__array();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL = 255667932;
		virtual bool begin__array__bool(){return true;}
		virtual bool end__array__bool(){return true;}
		virtual bool data__array__bool( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool( void* attributeData ){return begin__array__bool();}
		bool _data__array__bool( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL2 = 64154882;
		virtual bool begin__array__bool2(){return true;}
		virtual bool end__array__bool2(){return true;}
		virtual bool data__array__bool2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool2( void* attributeData ){return begin__array__bool2();}
		bool _data__array__bool2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL3 = 64154883;
		virtual bool begin__array__bool3(){return true;}
		virtual bool end__array__bool3(){return true;}
		virtual bool data__array__bool3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool3( void* attributeData ){return begin__array__bool3();}
		bool _data__array__bool3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL4 = 64154884;
		virtual bool begin__array__bool4(){return true;}
		virtual bool end__array__bool4(){return true;}
		virtual bool data__array__bool4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool4( void* attributeData ){return begin__array__bool4();}
		bool _data__array__bool4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT = 64404852;
		virtual bool begin__array__float(){return true;}
		virtual bool end__array__float(){return true;}
		virtual bool data__array__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float( void* attributeData ){return begin__array__float();}
		bool _data__array__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT2 = 225171266;
		virtual bool begin__array__float2(){return true;}
		virtual bool end__array__float2(){return true;}
		virtual bool data__array__float2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float2( void* attributeData ){return begin__array__float2();}
		bool _data__array__float2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT3 = 225171267;
		virtual bool begin__array__float3(){return true;}
		virtual bool end__array__float3(){return true;}
		virtual bool data__array__float3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float3( void* attributeData ){return begin__array__float3();}
		bool _data__array__float3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT4 = 225171268;
		virtual bool begin__array__float4(){return true;}
		virtual bool end__array__float4(){return true;}
		virtual bool data__array__float4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float4( void* attributeData ){return begin__array__float4();}
		bool _data__array__float4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT2X2 = 198657234;
		virtual bool begin__array__float2x2(){return true;}
		virtual bool end__array__float2x2(){return true;}
		virtual bool data__array__float2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float2x2( void* attributeData ){return begin__array__float2x2();}
		bool _data__array__float2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT3X3 = 198658003;
		virtual bool begin__array__float3x3(){return true;}
		virtual bool end__array__float3x3(){return true;}
		virtual bool data__array__float3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float3x3( void* attributeData ){return begin__array__float3x3();}
		bool _data__array__float3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT4X4 = 198657748;
		virtual bool begin__array__float4x4(){return true;}
		virtual bool end__array__float4x4(){return true;}
		virtual bool data__array__float4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float4x4( void* attributeData ){return begin__array__float4x4();}
		bool _data__array__float4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT = 150198228;
		virtual bool begin__array__int(){return true;}
		virtual bool end__array__int(){return true;}
		virtual bool data__array__int( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int( void* attributeData ){return begin__array__int();}
		bool _data__array__int( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT2 = 255688178;
		virtual bool begin__array__int2(){return true;}
		virtual bool end__array__int2(){return true;}
		virtual bool data__array__int2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int2( void* attributeData ){return begin__array__int2();}
		bool _data__array__int2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT3 = 255688179;
		virtual bool begin__array__int3(){return true;}
		virtual bool end__array__int3(){return true;}
		virtual bool data__array__int3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int3( void* attributeData ){return begin__array__int3();}
		bool _data__array__int3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT4 = 255688180;
		virtual bool begin__array__int4(){return true;}
		virtual bool end__array__int4(){return true;}
		virtual bool data__array__int4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int4( void* attributeData ){return begin__array__int4();}
		bool _data__array__int4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SURFACE = 54539381;
		struct array__surface__AttributeData
		{
			static const array__surface__AttributeData DEFAULT;

			const ParserChar* type;
		};
		virtual bool begin__array__surface( const array__surface__AttributeData& attributeData ){return true;}
		virtual bool end__array__surface(){return true;}
	private:
		bool _begin__array__surface( void* attributeData ){return begin__array__surface(*static_cast<array__surface__AttributeData*>(attributeData));}
		bool _data__array__surface( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__surface();

	public:
		static const StringHash HASH_ELEMENT_GENERATOR = 80275618;
		static const StringHash HASH_ELEMENT_SURFACE__GENERATOR = 181492914;
		virtual bool begin__generator(){return true;}
		virtual bool end__generator(){return true;}
	private:
		bool _begin__generator( void* attributeData ){return begin__generator();}
		bool _data__generator( const ParserChar* text, size_t textLength );
		bool _validateBegin__generator( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator();

	public:
		static const StringHash HASH_ELEMENT_GENERATOR__ANNOTATE = 233977093;
		struct generator__annotate__AttributeData
		{
			static const generator__annotate__AttributeData DEFAULT;

			const ParserChar* name;
		};
		virtual bool begin__generator__annotate( const generator__annotate__AttributeData& attributeData ){return true;}
		virtual bool end__generator__annotate(){return true;}
	private:
		bool _begin__generator__annotate( void* attributeData ){return begin__generator__annotate(*static_cast<generator__annotate__AttributeData*>(attributeData));}
		bool _data__generator__annotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__generator__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__annotate();

	public:
		static const StringHash HASH_ELEMENT_GENERATOR__CODE = 77434117;
		struct generator__code__AttributeData
		{
			static const generator__code__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__generator__code( const generator__code__AttributeData& attributeData ){return true;}
		virtual bool end__generator__code(){return true;}
		virtual bool data__generator__code( const void* data, size_t length ){return true;}
	private:
		bool _begin__generator__code( void* attributeData ){return begin__generator__code(*static_cast<generator__code__AttributeData*>(attributeData));}
		bool _data__generator__code( const ParserChar* text, size_t textLength );
		bool _validateBegin__generator__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__code();

	public:
		static const StringHash HASH_ELEMENT_GENERATOR__INCLUDE = 46428789;
		struct generator__include__AttributeData
		{
			static const generator__include__AttributeData DEFAULT;

			const ParserChar* sid;
			const ParserChar* url;
		};
		virtual bool begin__generator__include( const generator__include__AttributeData& attributeData ){return true;}
		virtual bool end__generator__include(){return true;}
	private:
		bool _begin__generator__include( void* attributeData ){return begin__generator__include(*static_cast<generator__include__AttributeData*>(attributeData));}
		bool _data__generator__include( const ParserChar* text, size_t textLength );
		bool _validateBegin__generator__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__include();

	public:
		static const StringHash HASH_ELEMENT_NAME = 477237;
		static const StringHash HASH_ELEMENT_GENERATOR__NAME = 77508757;
		struct generator__name__AttributeData
		{
			static const generator__name__AttributeData DEFAULT;

			const ParserChar* source;
		};
		virtual bool begin__generator__name( const generator__name__AttributeData& attributeData ){return true;}
		virtual bool end__generator__name(){return true;}
		virtual bool data__generator__name( const void* data, size_t length ){return true;}
	private:
		bool _begin__generator__name( void* attributeData ){return begin__generator__name(*static_cast<generator__name__AttributeData*>(attributeData));}
		bool _data__generator__name( const ParserChar* text, size_t textLength );
		bool _validateBegin__generator__name( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__name();

	public:
		static const StringHash HASH_ELEMENT_GENERATOR__SETPARAM = 68294157;
		struct generator__setparam__AttributeData
		{
			static const generator__setparam__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__generator__setparam( const generator__setparam__AttributeData& attributeData ){return true;}
		virtual bool end__generator__setparam(){return true;}
	private:
		bool _begin__generator__setparam( void* attributeData ){return begin__generator__setparam(*static_cast<generator__setparam__AttributeData*>(attributeData));}
		bool _data__generator__setparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__generator__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__setparam();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SAMPLER1D = 211887188;
		virtual bool begin__array__sampler1D(){return true;}
		virtual bool end__array__sampler1D(){return true;}
	private:
		bool _begin__array__sampler1D( void* attributeData ){return begin__array__sampler1D();}
		bool _data__array__sampler1D( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__sampler1D();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SAMPLER2D = 211887204;
		virtual bool begin__array__sampler2D(){return true;}
		virtual bool end__array__sampler2D(){return true;}
	private:
		bool _begin__array__sampler2D( void* attributeData ){return begin__array__sampler2D();}
		bool _data__array__sampler2D( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__sampler2D();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SAMPLER3D = 211887220;
		virtual bool begin__array__sampler3D(){return true;}
		virtual bool end__array__sampler3D(){return true;}
	private:
		bool _begin__array__sampler3D( void* attributeData ){return begin__array__sampler3D();}
		bool _data__array__sampler3D( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__sampler3D();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SAMPLERCUBE = 19367365;
		virtual bool begin__array__samplerCUBE(){return true;}
		virtual bool end__array__samplerCUBE(){return true;}
	private:
		bool _begin__array__samplerCUBE( void* attributeData ){return begin__array__samplerCUBE();}
		bool _data__array__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__samplerCUBE();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SAMPLERRECT = 19293476;
		virtual bool begin__array__samplerRECT(){return true;}
		virtual bool end__array__samplerRECT(){return true;}
	private:
		bool _begin__array__samplerRECT( void* attributeData ){return begin__array__samplerRECT();}
		bool _data__array__samplerRECT( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__samplerRECT();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__SAMPLERDEPTH = 41447320;
		virtual bool begin__array__samplerDEPTH(){return true;}
		virtual bool end__array__samplerDEPTH(){return true;}
	private:
		bool _begin__array__samplerDEPTH( void* attributeData ){return begin__array__samplerDEPTH();}
		bool _data__array__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__samplerDEPTH();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__ENUM = 255671613;
		virtual bool begin__array__enum(){return true;}
		virtual bool end__array__enum(){return true;}
		virtual bool data__array__enum( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__enum( void* attributeData ){return begin__array__enum();}
		bool _data__array__enum( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__enum();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__ARRAY = 64032889;
		struct array__array__AttributeData
		{
			static const array__array__AttributeData DEFAULT;

			long length;
		};
		virtual bool begin__array__array( const array__array__AttributeData& attributeData ){return true;}
		virtual bool end__array__array(){return true;}
	private:
		bool _begin__array__array( void* attributeData ){return begin__array__array(*static_cast<array__array__AttributeData*>(attributeData));}
		bool _data__array__array( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__array();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE = 30461381;
		struct profile_GLSL__technique__AttributeData
		{
			static const profile_GLSL__technique__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* sid;
		};
		virtual bool begin__profile_GLSL__technique( const profile_GLSL__technique__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL__technique(){return true;}
	private:
		bool _begin__profile_GLSL__technique( void* attributeData ){return begin__profile_GLSL__technique(*static_cast<profile_GLSL__technique__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__technique();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__CODE = 79755173;
		struct technique__code__AttributeData
		{
			static const technique__code__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__technique__code( const technique__code__AttributeData& attributeData ){return true;}
		virtual bool end__technique__code(){return true;}
		virtual bool data__technique__code( const void* data, size_t length ){return true;}
	private:
		bool _begin__technique__code( void* attributeData ){return begin__technique__code(*static_cast<technique__code__AttributeData*>(attributeData));}
		bool _data__technique__code( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__code();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__INCLUDE = 157972389;
		struct technique__include__AttributeData
		{
			static const technique__include__AttributeData DEFAULT;

			const ParserChar* sid;
			const ParserChar* url;
		};
		virtual bool begin__technique__include( const technique__include__AttributeData& attributeData ){return true;}
		virtual bool end__technique__include(){return true;}
	private:
		bool _begin__technique__include( void* attributeData ){return begin__technique__include(*static_cast<technique__include__AttributeData*>(attributeData));}
		bool _data__technique__include( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__include();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_GLSL__EXTRA = 200487889;
		struct profile_GLSL__extra__AttributeData
		{
			static const profile_GLSL__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__profile_GLSL__extra( const profile_GLSL__extra__AttributeData& attributeData ){return true;}
		virtual bool end__profile_GLSL__extra(){return true;}
	private:
		bool _begin__profile_GLSL__extra( void* attributeData ){return begin__profile_GLSL__extra(*static_cast<profile_GLSL__extra__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_GLSL__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__extra();

	public:
		struct image__AttributeData
		{
			static const image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__image( const image__AttributeData& attributeData ){return true;}
		virtual bool end__image(){return true;}
	private:
		bool _begin__image( void* attributeData ){return begin__image(*static_cast<image__AttributeData*>(attributeData));}
		bool _data__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image();

	public:
		struct instance_physics_model__AttributeData
		{
			static const instance_physics_model__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
			const ParserChar* parent;
		};
		virtual bool begin__instance_physics_model( const instance_physics_model__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_model(){return true;}
	private:
		bool _begin__instance_physics_model( void* attributeData ){return begin__instance_physics_model(*static_cast<instance_physics_model__AttributeData*>(attributeData));}
		bool _data__instance_physics_model( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_model();

	public:
		struct physics_material__AttributeData
		{
			static const physics_material__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__physics_material( const physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__physics_material(){return true;}
	private:
		bool _begin__physics_material( void* attributeData ){return begin__physics_material(*static_cast<physics_material__AttributeData*>(attributeData));}
		bool _data__physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material();

	public:
		struct linestrips__AttributeData
		{
			static const linestrips__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__linestrips( const linestrips__AttributeData& attributeData ){return true;}
		virtual bool end__linestrips(){return true;}
	private:
		bool _begin__linestrips( void* attributeData ){return begin__linestrips(*static_cast<linestrips__AttributeData*>(attributeData));}
		bool _data__linestrips( const ParserChar* text, size_t textLength );
		bool _validateBegin__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips();

	public:
		static const StringHash HASH_ELEMENT_GL_HOOK_ABSTRACT = 114258052;
		virtual bool begin__gl_hook_abstract(){return true;}
		virtual bool end__gl_hook_abstract(){return true;}
		virtual bool data__gl_hook_abstract( const void* data, size_t length ){return true;}
	private:
		bool _begin__gl_hook_abstract( void* attributeData ){return begin__gl_hook_abstract();}
		bool _data__gl_hook_abstract( const ParserChar* text, size_t textLength );
		bool _validateBegin__gl_hook_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__gl_hook_abstract();

	public:
		struct node__AttributeData
		{
			static const node__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* sid;
			const ParserChar* type;
			const ParserChar* layer;
		};
		virtual bool begin__node( const node__AttributeData& attributeData ){return true;}
		virtual bool end__node(){return true;}
	private:
		bool _begin__node( void* attributeData ){return begin__node(*static_cast<node__AttributeData*>(attributeData));}
		bool _data__node( const ParserChar* text, size_t textLength );
		bool _validateBegin__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node();

	public:
		struct technique__AttributeData
		{
			static const technique__AttributeData DEFAULT;

			const ParserChar* profile;
		};
		virtual bool begin__technique( const technique__AttributeData& attributeData ){return true;}
		virtual bool end__technique(){return true;}
	private:
		bool _begin__technique( void* attributeData ){return begin__technique(*static_cast<technique__AttributeData*>(attributeData));}
		bool _data__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique();

	public:
		struct tristrips__AttributeData
		{
			static const tristrips__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__tristrips( const tristrips__AttributeData& attributeData ){return true;}
		virtual bool end__tristrips(){return true;}
	private:
		bool _begin__tristrips( void* attributeData ){return begin__tristrips(*static_cast<tristrips__AttributeData*>(attributeData));}
		bool _data__tristrips( const ParserChar* text, size_t textLength );
		bool _validateBegin__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG = 218491431;
		struct profile_CG__AttributeData
		{
			static const profile_CG__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* platform;
		};
		virtual bool begin__profile_CG( const profile_CG__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG(){return true;}
	private:
		bool _begin__profile_CG( void* attributeData ){return begin__profile_CG(*static_cast<profile_CG__AttributeData*>(attributeData));}
		bool _data__profile_CG( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__ASSET = 84282340;
		virtual bool begin__profile_CG__asset(){return true;}
		virtual bool end__profile_CG__asset(){return true;}
	private:
		bool _begin__profile_CG__asset( void* attributeData ){return begin__profile_CG__asset();}
		bool _data__profile_CG__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__asset();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__CODE = 38834053;
		struct profile_CG__code__AttributeData
		{
			static const profile_CG__code__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__profile_CG__code( const profile_CG__code__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG__code(){return true;}
		virtual bool data__profile_CG__code( const void* data, size_t length ){return true;}
	private:
		bool _begin__profile_CG__code( void* attributeData ){return begin__profile_CG__code(*static_cast<profile_CG__code__AttributeData*>(attributeData));}
		bool _data__profile_CG__code( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__code();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__INCLUDE = 49028773;
		struct profile_CG__include__AttributeData
		{
			static const profile_CG__include__AttributeData DEFAULT;

			const ParserChar* sid;
			const ParserChar* url;
		};
		virtual bool begin__profile_CG__include( const profile_CG__include__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG__include(){return true;}
	private:
		bool _begin__profile_CG__include( void* attributeData ){return begin__profile_CG__include(*static_cast<profile_CG__include__AttributeData*>(attributeData));}
		bool _data__profile_CG__include( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__include();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__IMAGE = 84055541;
		struct profile_CG__image__AttributeData
		{
			static const profile_CG__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__profile_CG__image( const profile_CG__image__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG__image(){return true;}
	private:
		bool _begin__profile_CG__image( void* attributeData ){return begin__profile_CG__image(*static_cast<profile_CG__image__AttributeData*>(attributeData));}
		bool _data__profile_CG__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__image();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__NEWPARAM = 113564125;
		struct profile_CG__newparam__AttributeData
		{
			static const profile_CG__newparam__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__profile_CG__newparam( const profile_CG__newparam__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG__newparam(){return true;}
	private:
		bool _begin__profile_CG__newparam( void* attributeData ){return begin__profile_CG__newparam(*static_cast<profile_CG__newparam__AttributeData*>(attributeData));}
		bool _data__profile_CG__newparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__newparam();

	public:
		static const StringHash HASH_ELEMENT_BOOL1 = 6907377;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL1 = 187805953;
		virtual bool begin__newparam__bool1(){return true;}
		virtual bool end__newparam__bool1(){return true;}
		virtual bool data__newparam__bool1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool1( void* attributeData ){return begin__newparam__bool1();}
		bool _data__newparam__bool1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1();

	public:
		static const StringHash HASH_ELEMENT_BOOL1X1 = 157677777;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X1 = 28377985;
		virtual bool begin__newparam__bool1x1(){return true;}
		virtual bool end__newparam__bool1x1(){return true;}
		virtual bool data__newparam__bool1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool1x1( void* attributeData ){return begin__newparam__bool1x1();}
		bool _data__newparam__bool1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x1();

	public:
		static const StringHash HASH_ELEMENT_BOOL1X2 = 157677778;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X2 = 28377986;
		virtual bool begin__newparam__bool1x2(){return true;}
		virtual bool end__newparam__bool1x2(){return true;}
		virtual bool data__newparam__bool1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool1x2( void* attributeData ){return begin__newparam__bool1x2();}
		bool _data__newparam__bool1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x2();

	public:
		static const StringHash HASH_ELEMENT_BOOL1X3 = 157677779;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X3 = 28377987;
		virtual bool begin__newparam__bool1x3(){return true;}
		virtual bool end__newparam__bool1x3(){return true;}
		virtual bool data__newparam__bool1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool1x3( void* attributeData ){return begin__newparam__bool1x3();}
		bool _data__newparam__bool1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x3();

	public:
		static const StringHash HASH_ELEMENT_BOOL1X4 = 157677780;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X4 = 28377988;
		virtual bool begin__newparam__bool1x4(){return true;}
		virtual bool end__newparam__bool1x4(){return true;}
		virtual bool data__newparam__bool1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool1x4( void* attributeData ){return begin__newparam__bool1x4();}
		bool _data__newparam__bool1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x4();

	public:
		static const StringHash HASH_ELEMENT_BOOL2X1 = 157678033;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X1 = 28377729;
		virtual bool begin__newparam__bool2x1(){return true;}
		virtual bool end__newparam__bool2x1(){return true;}
		virtual bool data__newparam__bool2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool2x1( void* attributeData ){return begin__newparam__bool2x1();}
		bool _data__newparam__bool2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x1();

	public:
		static const StringHash HASH_ELEMENT_BOOL2X2 = 157678034;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X2 = 28377730;
		virtual bool begin__newparam__bool2x2(){return true;}
		virtual bool end__newparam__bool2x2(){return true;}
		virtual bool data__newparam__bool2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool2x2( void* attributeData ){return begin__newparam__bool2x2();}
		bool _data__newparam__bool2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x2();

	public:
		static const StringHash HASH_ELEMENT_BOOL2X3 = 157678035;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X3 = 28377731;
		virtual bool begin__newparam__bool2x3(){return true;}
		virtual bool end__newparam__bool2x3(){return true;}
		virtual bool data__newparam__bool2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool2x3( void* attributeData ){return begin__newparam__bool2x3();}
		bool _data__newparam__bool2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x3();

	public:
		static const StringHash HASH_ELEMENT_BOOL2X4 = 157678036;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X4 = 28377732;
		virtual bool begin__newparam__bool2x4(){return true;}
		virtual bool end__newparam__bool2x4(){return true;}
		virtual bool data__newparam__bool2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool2x4( void* attributeData ){return begin__newparam__bool2x4();}
		bool _data__newparam__bool2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x4();

	public:
		static const StringHash HASH_ELEMENT_BOOL3X1 = 157678289;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X1 = 28377473;
		virtual bool begin__newparam__bool3x1(){return true;}
		virtual bool end__newparam__bool3x1(){return true;}
		virtual bool data__newparam__bool3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool3x1( void* attributeData ){return begin__newparam__bool3x1();}
		bool _data__newparam__bool3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x1();

	public:
		static const StringHash HASH_ELEMENT_BOOL3X2 = 157678290;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X2 = 28377474;
		virtual bool begin__newparam__bool3x2(){return true;}
		virtual bool end__newparam__bool3x2(){return true;}
		virtual bool data__newparam__bool3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool3x2( void* attributeData ){return begin__newparam__bool3x2();}
		bool _data__newparam__bool3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x2();

	public:
		static const StringHash HASH_ELEMENT_BOOL3X3 = 157678291;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X3 = 28377475;
		virtual bool begin__newparam__bool3x3(){return true;}
		virtual bool end__newparam__bool3x3(){return true;}
		virtual bool data__newparam__bool3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool3x3( void* attributeData ){return begin__newparam__bool3x3();}
		bool _data__newparam__bool3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x3();

	public:
		static const StringHash HASH_ELEMENT_BOOL3X4 = 157678292;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X4 = 28377476;
		virtual bool begin__newparam__bool3x4(){return true;}
		virtual bool end__newparam__bool3x4(){return true;}
		virtual bool data__newparam__bool3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool3x4( void* attributeData ){return begin__newparam__bool3x4();}
		bool _data__newparam__bool3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x4();

	public:
		static const StringHash HASH_ELEMENT_BOOL4X1 = 157678545;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X1 = 28377217;
		virtual bool begin__newparam__bool4x1(){return true;}
		virtual bool end__newparam__bool4x1(){return true;}
		virtual bool data__newparam__bool4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool4x1( void* attributeData ){return begin__newparam__bool4x1();}
		bool _data__newparam__bool4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x1();

	public:
		static const StringHash HASH_ELEMENT_BOOL4X2 = 157678546;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X2 = 28377218;
		virtual bool begin__newparam__bool4x2(){return true;}
		virtual bool end__newparam__bool4x2(){return true;}
		virtual bool data__newparam__bool4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool4x2( void* attributeData ){return begin__newparam__bool4x2();}
		bool _data__newparam__bool4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x2();

	public:
		static const StringHash HASH_ELEMENT_BOOL4X3 = 157678547;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X3 = 28377219;
		virtual bool begin__newparam__bool4x3(){return true;}
		virtual bool end__newparam__bool4x3(){return true;}
		virtual bool data__newparam__bool4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool4x3( void* attributeData ){return begin__newparam__bool4x3();}
		bool _data__newparam__bool4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x3();

	public:
		static const StringHash HASH_ELEMENT_BOOL4X4 = 157678548;
		static const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X4 = 28377220;
		virtual bool begin__newparam__bool4x4(){return true;}
		virtual bool end__newparam__bool4x4(){return true;}
		virtual bool data__newparam__bool4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__bool4x4( void* attributeData ){return begin__newparam__bool4x4();}
		bool _data__newparam__bool4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x4();

	public:
		static const StringHash HASH_ELEMENT_FLOAT1 = 114514033;
		static const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1 = 56498113;
		virtual bool begin__newparam__float1(){return true;}
		virtual bool end__newparam__float1(){return true;}
		virtual bool data__newparam__float1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__float1( void* attributeData ){return begin__newparam__float1();}
		bool _data__newparam__float1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1();

	public:
		static const StringHash HASH_ELEMENT_INT1 = 460145;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT1 = 263424561;
		virtual bool begin__newparam__int1(){return true;}
		virtual bool end__newparam__int1(){return true;}
		virtual bool data__newparam__int1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int1( void* attributeData ){return begin__newparam__int1();}
		bool _data__newparam__int1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1();

	public:
		static const StringHash HASH_ELEMENT_INT1X1 = 117799089;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT1X1 = 59389697;
		virtual bool begin__newparam__int1x1(){return true;}
		virtual bool end__newparam__int1x1(){return true;}
		virtual bool data__newparam__int1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int1x1( void* attributeData ){return begin__newparam__int1x1();}
		bool _data__newparam__int1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x1();

	public:
		static const StringHash HASH_ELEMENT_INT1X2 = 117799090;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT1X2 = 59389698;
		virtual bool begin__newparam__int1x2(){return true;}
		virtual bool end__newparam__int1x2(){return true;}
		virtual bool data__newparam__int1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int1x2( void* attributeData ){return begin__newparam__int1x2();}
		bool _data__newparam__int1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x2();

	public:
		static const StringHash HASH_ELEMENT_INT1X3 = 117799091;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT1X3 = 59389699;
		virtual bool begin__newparam__int1x3(){return true;}
		virtual bool end__newparam__int1x3(){return true;}
		virtual bool data__newparam__int1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int1x3( void* attributeData ){return begin__newparam__int1x3();}
		bool _data__newparam__int1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x3();

	public:
		static const StringHash HASH_ELEMENT_INT1X4 = 117799092;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT1X4 = 59389700;
		virtual bool begin__newparam__int1x4(){return true;}
		virtual bool end__newparam__int1x4(){return true;}
		virtual bool data__newparam__int1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int1x4( void* attributeData ){return begin__newparam__int1x4();}
		bool _data__newparam__int1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x4();

	public:
		static const StringHash HASH_ELEMENT_INT2X1 = 117799345;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT2X1 = 59389441;
		virtual bool begin__newparam__int2x1(){return true;}
		virtual bool end__newparam__int2x1(){return true;}
		virtual bool data__newparam__int2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int2x1( void* attributeData ){return begin__newparam__int2x1();}
		bool _data__newparam__int2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x1();

	public:
		static const StringHash HASH_ELEMENT_INT2X2 = 117799346;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT2X2 = 59389442;
		virtual bool begin__newparam__int2x2(){return true;}
		virtual bool end__newparam__int2x2(){return true;}
		virtual bool data__newparam__int2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int2x2( void* attributeData ){return begin__newparam__int2x2();}
		bool _data__newparam__int2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x2();

	public:
		static const StringHash HASH_ELEMENT_INT2X3 = 117799347;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT2X3 = 59389443;
		virtual bool begin__newparam__int2x3(){return true;}
		virtual bool end__newparam__int2x3(){return true;}
		virtual bool data__newparam__int2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int2x3( void* attributeData ){return begin__newparam__int2x3();}
		bool _data__newparam__int2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x3();

	public:
		static const StringHash HASH_ELEMENT_INT2X4 = 117799348;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT2X4 = 59389444;
		virtual bool begin__newparam__int2x4(){return true;}
		virtual bool end__newparam__int2x4(){return true;}
		virtual bool data__newparam__int2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int2x4( void* attributeData ){return begin__newparam__int2x4();}
		bool _data__newparam__int2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x4();

	public:
		static const StringHash HASH_ELEMENT_INT3X1 = 117799601;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT3X1 = 59389185;
		virtual bool begin__newparam__int3x1(){return true;}
		virtual bool end__newparam__int3x1(){return true;}
		virtual bool data__newparam__int3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int3x1( void* attributeData ){return begin__newparam__int3x1();}
		bool _data__newparam__int3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x1();

	public:
		static const StringHash HASH_ELEMENT_INT3X2 = 117799602;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT3X2 = 59389186;
		virtual bool begin__newparam__int3x2(){return true;}
		virtual bool end__newparam__int3x2(){return true;}
		virtual bool data__newparam__int3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int3x2( void* attributeData ){return begin__newparam__int3x2();}
		bool _data__newparam__int3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x2();

	public:
		static const StringHash HASH_ELEMENT_INT3X3 = 117799603;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT3X3 = 59389187;
		virtual bool begin__newparam__int3x3(){return true;}
		virtual bool end__newparam__int3x3(){return true;}
		virtual bool data__newparam__int3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int3x3( void* attributeData ){return begin__newparam__int3x3();}
		bool _data__newparam__int3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x3();

	public:
		static const StringHash HASH_ELEMENT_INT3X4 = 117799604;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT3X4 = 59389188;
		virtual bool begin__newparam__int3x4(){return true;}
		virtual bool end__newparam__int3x4(){return true;}
		virtual bool data__newparam__int3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int3x4( void* attributeData ){return begin__newparam__int3x4();}
		bool _data__newparam__int3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x4();

	public:
		static const StringHash HASH_ELEMENT_INT4X1 = 117799857;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT4X1 = 59388929;
		virtual bool begin__newparam__int4x1(){return true;}
		virtual bool end__newparam__int4x1(){return true;}
		virtual bool data__newparam__int4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int4x1( void* attributeData ){return begin__newparam__int4x1();}
		bool _data__newparam__int4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x1();

	public:
		static const StringHash HASH_ELEMENT_INT4X2 = 117799858;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT4X2 = 59388930;
		virtual bool begin__newparam__int4x2(){return true;}
		virtual bool end__newparam__int4x2(){return true;}
		virtual bool data__newparam__int4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int4x2( void* attributeData ){return begin__newparam__int4x2();}
		bool _data__newparam__int4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x2();

	public:
		static const StringHash HASH_ELEMENT_INT4X3 = 117799859;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT4X3 = 59388931;
		virtual bool begin__newparam__int4x3(){return true;}
		virtual bool end__newparam__int4x3(){return true;}
		virtual bool data__newparam__int4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int4x3( void* attributeData ){return begin__newparam__int4x3();}
		bool _data__newparam__int4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x3();

	public:
		static const StringHash HASH_ELEMENT_INT4X4 = 117799860;
		static const StringHash HASH_ELEMENT_NEWPARAM__INT4X4 = 59388932;
		virtual bool begin__newparam__int4x4(){return true;}
		virtual bool end__newparam__int4x4(){return true;}
		virtual bool data__newparam__int4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__int4x4( void* attributeData ){return begin__newparam__int4x4();}
		bool _data__newparam__int4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x4();

	public:
		static const StringHash HASH_ELEMENT_HALF = 452646;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF = 263416166;
		virtual bool begin__newparam__half(){return true;}
		virtual bool end__newparam__half(){return true;}
		virtual bool data__newparam__half( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half( void* attributeData ){return begin__newparam__half();}
		bool _data__newparam__half( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half();

	public:
		static const StringHash HASH_ELEMENT_HALF1 = 7242385;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF1 = 188126817;
		virtual bool begin__newparam__half1(){return true;}
		virtual bool end__newparam__half1(){return true;}
		virtual bool data__newparam__half1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half1( void* attributeData ){return begin__newparam__half1();}
		bool _data__newparam__half1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1();

	public:
		static const StringHash HASH_ELEMENT_HALF2 = 7242386;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF2 = 188126818;
		virtual bool begin__newparam__half2(){return true;}
		virtual bool end__newparam__half2(){return true;}
		virtual bool data__newparam__half2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half2( void* attributeData ){return begin__newparam__half2();}
		bool _data__newparam__half2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2();

	public:
		static const StringHash HASH_ELEMENT_HALF3 = 7242387;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF3 = 188126819;
		virtual bool begin__newparam__half3(){return true;}
		virtual bool end__newparam__half3(){return true;}
		virtual bool data__newparam__half3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half3( void* attributeData ){return begin__newparam__half3();}
		bool _data__newparam__half3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3();

	public:
		static const StringHash HASH_ELEMENT_HALF4 = 7242388;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF4 = 188126820;
		virtual bool begin__newparam__half4(){return true;}
		virtual bool end__newparam__half4(){return true;}
		virtual bool data__newparam__half4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half4( void* attributeData ){return begin__newparam__half4();}
		bool _data__newparam__half4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4();

	public:
		static const StringHash HASH_ELEMENT_HALF1X1 = 243439825;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF1X1 = 110519169;
		virtual bool begin__newparam__half1x1(){return true;}
		virtual bool end__newparam__half1x1(){return true;}
		virtual bool data__newparam__half1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half1x1( void* attributeData ){return begin__newparam__half1x1();}
		bool _data__newparam__half1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x1();

	public:
		static const StringHash HASH_ELEMENT_HALF1X2 = 243439826;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF1X2 = 110519170;
		virtual bool begin__newparam__half1x2(){return true;}
		virtual bool end__newparam__half1x2(){return true;}
		virtual bool data__newparam__half1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half1x2( void* attributeData ){return begin__newparam__half1x2();}
		bool _data__newparam__half1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x2();

	public:
		static const StringHash HASH_ELEMENT_HALF1X3 = 243439827;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF1X3 = 110519171;
		virtual bool begin__newparam__half1x3(){return true;}
		virtual bool end__newparam__half1x3(){return true;}
		virtual bool data__newparam__half1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half1x3( void* attributeData ){return begin__newparam__half1x3();}
		bool _data__newparam__half1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x3();

	public:
		static const StringHash HASH_ELEMENT_HALF1X4 = 243439828;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF1X4 = 110519172;
		virtual bool begin__newparam__half1x4(){return true;}
		virtual bool end__newparam__half1x4(){return true;}
		virtual bool data__newparam__half1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half1x4( void* attributeData ){return begin__newparam__half1x4();}
		bool _data__newparam__half1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x4();

	public:
		static const StringHash HASH_ELEMENT_HALF2X1 = 243440081;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF2X1 = 110518913;
		virtual bool begin__newparam__half2x1(){return true;}
		virtual bool end__newparam__half2x1(){return true;}
		virtual bool data__newparam__half2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half2x1( void* attributeData ){return begin__newparam__half2x1();}
		bool _data__newparam__half2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x1();

	public:
		static const StringHash HASH_ELEMENT_HALF2X2 = 243440082;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF2X2 = 110518914;
		virtual bool begin__newparam__half2x2(){return true;}
		virtual bool end__newparam__half2x2(){return true;}
		virtual bool data__newparam__half2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half2x2( void* attributeData ){return begin__newparam__half2x2();}
		bool _data__newparam__half2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x2();

	public:
		static const StringHash HASH_ELEMENT_HALF2X3 = 243440083;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF2X3 = 110518915;
		virtual bool begin__newparam__half2x3(){return true;}
		virtual bool end__newparam__half2x3(){return true;}
		virtual bool data__newparam__half2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half2x3( void* attributeData ){return begin__newparam__half2x3();}
		bool _data__newparam__half2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x3();

	public:
		static const StringHash HASH_ELEMENT_HALF2X4 = 243440084;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF2X4 = 110518916;
		virtual bool begin__newparam__half2x4(){return true;}
		virtual bool end__newparam__half2x4(){return true;}
		virtual bool data__newparam__half2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half2x4( void* attributeData ){return begin__newparam__half2x4();}
		bool _data__newparam__half2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x4();

	public:
		static const StringHash HASH_ELEMENT_HALF3X1 = 243440337;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF3X1 = 110518657;
		virtual bool begin__newparam__half3x1(){return true;}
		virtual bool end__newparam__half3x1(){return true;}
		virtual bool data__newparam__half3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half3x1( void* attributeData ){return begin__newparam__half3x1();}
		bool _data__newparam__half3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x1();

	public:
		static const StringHash HASH_ELEMENT_HALF3X2 = 243440338;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF3X2 = 110518658;
		virtual bool begin__newparam__half3x2(){return true;}
		virtual bool end__newparam__half3x2(){return true;}
		virtual bool data__newparam__half3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half3x2( void* attributeData ){return begin__newparam__half3x2();}
		bool _data__newparam__half3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x2();

	public:
		static const StringHash HASH_ELEMENT_HALF3X3 = 243440339;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF3X3 = 110518659;
		virtual bool begin__newparam__half3x3(){return true;}
		virtual bool end__newparam__half3x3(){return true;}
		virtual bool data__newparam__half3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half3x3( void* attributeData ){return begin__newparam__half3x3();}
		bool _data__newparam__half3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x3();

	public:
		static const StringHash HASH_ELEMENT_HALF3X4 = 243440340;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF3X4 = 110518660;
		virtual bool begin__newparam__half3x4(){return true;}
		virtual bool end__newparam__half3x4(){return true;}
		virtual bool data__newparam__half3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half3x4( void* attributeData ){return begin__newparam__half3x4();}
		bool _data__newparam__half3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x4();

	public:
		static const StringHash HASH_ELEMENT_HALF4X1 = 243440593;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF4X1 = 110518401;
		virtual bool begin__newparam__half4x1(){return true;}
		virtual bool end__newparam__half4x1(){return true;}
		virtual bool data__newparam__half4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half4x1( void* attributeData ){return begin__newparam__half4x1();}
		bool _data__newparam__half4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x1();

	public:
		static const StringHash HASH_ELEMENT_HALF4X2 = 243440594;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF4X2 = 110518402;
		virtual bool begin__newparam__half4x2(){return true;}
		virtual bool end__newparam__half4x2(){return true;}
		virtual bool data__newparam__half4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half4x2( void* attributeData ){return begin__newparam__half4x2();}
		bool _data__newparam__half4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x2();

	public:
		static const StringHash HASH_ELEMENT_HALF4X3 = 243440595;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF4X3 = 110518403;
		virtual bool begin__newparam__half4x3(){return true;}
		virtual bool end__newparam__half4x3(){return true;}
		virtual bool data__newparam__half4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half4x3( void* attributeData ){return begin__newparam__half4x3();}
		bool _data__newparam__half4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x3();

	public:
		static const StringHash HASH_ELEMENT_HALF4X4 = 243440596;
		static const StringHash HASH_ELEMENT_NEWPARAM__HALF4X4 = 110518404;
		virtual bool begin__newparam__half4x4(){return true;}
		virtual bool end__newparam__half4x4(){return true;}
		virtual bool data__newparam__half4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__half4x4( void* attributeData ){return begin__newparam__half4x4();}
		bool _data__newparam__half4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x4();

	public:
		static const StringHash HASH_ELEMENT_FIXED = 7147188;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED = 188086852;
		virtual bool begin__newparam__fixed(){return true;}
		virtual bool end__newparam__fixed(){return true;}
		virtual bool data__newparam__fixed( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed( void* attributeData ){return begin__newparam__fixed();}
		bool _data__newparam__fixed( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed();

	public:
		static const StringHash HASH_ELEMENT_FIXED1 = 114355057;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED1 = 56599745;
		virtual bool begin__newparam__fixed1(){return true;}
		virtual bool end__newparam__fixed1(){return true;}
		virtual bool data__newparam__fixed1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed1( void* attributeData ){return begin__newparam__fixed1();}
		bool _data__newparam__fixed1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1();

	public:
		static const StringHash HASH_ELEMENT_FIXED2 = 114355058;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED2 = 56599746;
		virtual bool begin__newparam__fixed2(){return true;}
		virtual bool end__newparam__fixed2(){return true;}
		virtual bool data__newparam__fixed2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed2( void* attributeData ){return begin__newparam__fixed2();}
		bool _data__newparam__fixed2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2();

	public:
		static const StringHash HASH_ELEMENT_FIXED3 = 114355059;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED3 = 56599747;
		virtual bool begin__newparam__fixed3(){return true;}
		virtual bool end__newparam__fixed3(){return true;}
		virtual bool data__newparam__fixed3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed3( void* attributeData ){return begin__newparam__fixed3();}
		bool _data__newparam__fixed3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3();

	public:
		static const StringHash HASH_ELEMENT_FIXED4 = 114355060;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED4 = 56599748;
		virtual bool begin__newparam__fixed4(){return true;}
		virtual bool end__newparam__fixed4(){return true;}
		virtual bool data__newparam__fixed4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed4( void* attributeData ){return begin__newparam__fixed4();}
		bool _data__newparam__fixed4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4();

	public:
		static const StringHash HASH_ELEMENT_FIXED1X1 = 15433313;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X1 = 262458337;
		virtual bool begin__newparam__fixed1x1(){return true;}
		virtual bool end__newparam__fixed1x1(){return true;}
		virtual bool data__newparam__fixed1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed1x1( void* attributeData ){return begin__newparam__fixed1x1();}
		bool _data__newparam__fixed1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x1();

	public:
		static const StringHash HASH_ELEMENT_FIXED1X2 = 15433314;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X2 = 262458338;
		virtual bool begin__newparam__fixed1x2(){return true;}
		virtual bool end__newparam__fixed1x2(){return true;}
		virtual bool data__newparam__fixed1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed1x2( void* attributeData ){return begin__newparam__fixed1x2();}
		bool _data__newparam__fixed1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x2();

	public:
		static const StringHash HASH_ELEMENT_FIXED1X3 = 15433315;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X3 = 262458339;
		virtual bool begin__newparam__fixed1x3(){return true;}
		virtual bool end__newparam__fixed1x3(){return true;}
		virtual bool data__newparam__fixed1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed1x3( void* attributeData ){return begin__newparam__fixed1x3();}
		bool _data__newparam__fixed1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x3();

	public:
		static const StringHash HASH_ELEMENT_FIXED1X4 = 15433316;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X4 = 262458340;
		virtual bool begin__newparam__fixed1x4(){return true;}
		virtual bool end__newparam__fixed1x4(){return true;}
		virtual bool data__newparam__fixed1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed1x4( void* attributeData ){return begin__newparam__fixed1x4();}
		bool _data__newparam__fixed1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x4();

	public:
		static const StringHash HASH_ELEMENT_FIXED2X1 = 15433569;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X1 = 262458081;
		virtual bool begin__newparam__fixed2x1(){return true;}
		virtual bool end__newparam__fixed2x1(){return true;}
		virtual bool data__newparam__fixed2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed2x1( void* attributeData ){return begin__newparam__fixed2x1();}
		bool _data__newparam__fixed2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x1();

	public:
		static const StringHash HASH_ELEMENT_FIXED2X2 = 15433570;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X2 = 262458082;
		virtual bool begin__newparam__fixed2x2(){return true;}
		virtual bool end__newparam__fixed2x2(){return true;}
		virtual bool data__newparam__fixed2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed2x2( void* attributeData ){return begin__newparam__fixed2x2();}
		bool _data__newparam__fixed2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x2();

	public:
		static const StringHash HASH_ELEMENT_FIXED2X3 = 15433571;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X3 = 262458083;
		virtual bool begin__newparam__fixed2x3(){return true;}
		virtual bool end__newparam__fixed2x3(){return true;}
		virtual bool data__newparam__fixed2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed2x3( void* attributeData ){return begin__newparam__fixed2x3();}
		bool _data__newparam__fixed2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x3();

	public:
		static const StringHash HASH_ELEMENT_FIXED2X4 = 15433572;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X4 = 262458084;
		virtual bool begin__newparam__fixed2x4(){return true;}
		virtual bool end__newparam__fixed2x4(){return true;}
		virtual bool data__newparam__fixed2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed2x4( void* attributeData ){return begin__newparam__fixed2x4();}
		bool _data__newparam__fixed2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x4();

	public:
		static const StringHash HASH_ELEMENT_FIXED3X1 = 15432801;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X1 = 262457825;
		virtual bool begin__newparam__fixed3x1(){return true;}
		virtual bool end__newparam__fixed3x1(){return true;}
		virtual bool data__newparam__fixed3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed3x1( void* attributeData ){return begin__newparam__fixed3x1();}
		bool _data__newparam__fixed3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x1();

	public:
		static const StringHash HASH_ELEMENT_FIXED3X2 = 15432802;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X2 = 262457826;
		virtual bool begin__newparam__fixed3x2(){return true;}
		virtual bool end__newparam__fixed3x2(){return true;}
		virtual bool data__newparam__fixed3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed3x2( void* attributeData ){return begin__newparam__fixed3x2();}
		bool _data__newparam__fixed3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x2();

	public:
		static const StringHash HASH_ELEMENT_FIXED3X3 = 15432803;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X3 = 262457827;
		virtual bool begin__newparam__fixed3x3(){return true;}
		virtual bool end__newparam__fixed3x3(){return true;}
		virtual bool data__newparam__fixed3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed3x3( void* attributeData ){return begin__newparam__fixed3x3();}
		bool _data__newparam__fixed3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x3();

	public:
		static const StringHash HASH_ELEMENT_FIXED3X4 = 15432804;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X4 = 262457828;
		virtual bool begin__newparam__fixed3x4(){return true;}
		virtual bool end__newparam__fixed3x4(){return true;}
		virtual bool data__newparam__fixed3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed3x4( void* attributeData ){return begin__newparam__fixed3x4();}
		bool _data__newparam__fixed3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x4();

	public:
		static const StringHash HASH_ELEMENT_FIXED4X1 = 15433057;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X1 = 262457569;
		virtual bool begin__newparam__fixed4x1(){return true;}
		virtual bool end__newparam__fixed4x1(){return true;}
		virtual bool data__newparam__fixed4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed4x1( void* attributeData ){return begin__newparam__fixed4x1();}
		bool _data__newparam__fixed4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x1();

	public:
		static const StringHash HASH_ELEMENT_FIXED4X2 = 15433058;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X2 = 262457570;
		virtual bool begin__newparam__fixed4x2(){return true;}
		virtual bool end__newparam__fixed4x2(){return true;}
		virtual bool data__newparam__fixed4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed4x2( void* attributeData ){return begin__newparam__fixed4x2();}
		bool _data__newparam__fixed4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x2();

	public:
		static const StringHash HASH_ELEMENT_FIXED4X3 = 15433059;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X3 = 262457571;
		virtual bool begin__newparam__fixed4x3(){return true;}
		virtual bool end__newparam__fixed4x3(){return true;}
		virtual bool data__newparam__fixed4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed4x3( void* attributeData ){return begin__newparam__fixed4x3();}
		bool _data__newparam__fixed4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x3();

	public:
		static const StringHash HASH_ELEMENT_FIXED4X4 = 15433060;
		static const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X4 = 262457572;
		virtual bool begin__newparam__fixed4x4(){return true;}
		virtual bool end__newparam__fixed4x4(){return true;}
		virtual bool data__newparam__fixed4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__fixed4x4( void* attributeData ){return begin__newparam__fixed4x4();}
		bool _data__newparam__fixed4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x4();

	public:
		static const StringHash HASH_ELEMENT_NEWPARAM__STRING = 2408951;
		virtual bool begin__newparam__string(){return true;}
		virtual bool end__newparam__string(){return true;}
		virtual bool data__newparam__string( const void* data, size_t length ){return true;}
	private:
		bool _begin__newparam__string( void* attributeData ){return begin__newparam__string();}
		bool _data__newparam__string( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__string();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE = 164218789;
		static const StringHash HASH_ELEMENT_NEWPARAM__USERTYPE = 109449253;
		struct newparam__usertype__AttributeData
		{
			static const newparam__usertype__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* source;
		};
		virtual bool begin__newparam__usertype( const newparam__usertype__AttributeData& attributeData ){return true;}
		virtual bool end__newparam__usertype(){return true;}
	private:
		bool _begin__newparam__usertype( void* attributeData ){return begin__newparam__usertype(*static_cast<newparam__usertype__AttributeData*>(attributeData));}
		bool _data__newparam__usertype( const ParserChar* text, size_t textLength );
		bool _validateBegin__newparam__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__usertype();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL = 77353980;
		virtual bool begin__usertype__bool(){return true;}
		virtual bool end__usertype__bool(){return true;}
		virtual bool data__usertype__bool( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool( void* attributeData ){return begin__usertype__bool();}
		bool _data__usertype__bool( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL1 = 163921841;
		virtual bool begin__usertype__bool1(){return true;}
		virtual bool end__usertype__bool1(){return true;}
		virtual bool data__usertype__bool1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool1( void* attributeData ){return begin__usertype__bool1();}
		bool _data__usertype__bool1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL2 = 163921842;
		virtual bool begin__usertype__bool2(){return true;}
		virtual bool end__usertype__bool2(){return true;}
		virtual bool data__usertype__bool2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool2( void* attributeData ){return begin__usertype__bool2();}
		bool _data__usertype__bool2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL3 = 163921843;
		virtual bool begin__usertype__bool3(){return true;}
		virtual bool end__usertype__bool3(){return true;}
		virtual bool data__usertype__bool3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool3( void* attributeData ){return begin__usertype__bool3();}
		bool _data__usertype__bool3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL4 = 163921844;
		virtual bool begin__usertype__bool4(){return true;}
		virtual bool end__usertype__bool4(){return true;}
		virtual bool data__usertype__bool4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool4( void* attributeData ){return begin__usertype__bool4();}
		bool _data__usertype__bool4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL1X1 = 88060273;
		virtual bool begin__usertype__bool1x1(){return true;}
		virtual bool end__usertype__bool1x1(){return true;}
		virtual bool data__usertype__bool1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool1x1( void* attributeData ){return begin__usertype__bool1x1();}
		bool _data__usertype__bool1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL1X2 = 88060274;
		virtual bool begin__usertype__bool1x2(){return true;}
		virtual bool end__usertype__bool1x2(){return true;}
		virtual bool data__usertype__bool1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool1x2( void* attributeData ){return begin__usertype__bool1x2();}
		bool _data__usertype__bool1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL1X3 = 88060275;
		virtual bool begin__usertype__bool1x3(){return true;}
		virtual bool end__usertype__bool1x3(){return true;}
		virtual bool data__usertype__bool1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool1x3( void* attributeData ){return begin__usertype__bool1x3();}
		bool _data__usertype__bool1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL1X4 = 88060276;
		virtual bool begin__usertype__bool1x4(){return true;}
		virtual bool end__usertype__bool1x4(){return true;}
		virtual bool data__usertype__bool1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool1x4( void* attributeData ){return begin__usertype__bool1x4();}
		bool _data__usertype__bool1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL2X1 = 88060017;
		virtual bool begin__usertype__bool2x1(){return true;}
		virtual bool end__usertype__bool2x1(){return true;}
		virtual bool data__usertype__bool2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool2x1( void* attributeData ){return begin__usertype__bool2x1();}
		bool _data__usertype__bool2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL2X2 = 88060018;
		virtual bool begin__usertype__bool2x2(){return true;}
		virtual bool end__usertype__bool2x2(){return true;}
		virtual bool data__usertype__bool2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool2x2( void* attributeData ){return begin__usertype__bool2x2();}
		bool _data__usertype__bool2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL2X3 = 88060019;
		virtual bool begin__usertype__bool2x3(){return true;}
		virtual bool end__usertype__bool2x3(){return true;}
		virtual bool data__usertype__bool2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool2x3( void* attributeData ){return begin__usertype__bool2x3();}
		bool _data__usertype__bool2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL2X4 = 88060020;
		virtual bool begin__usertype__bool2x4(){return true;}
		virtual bool end__usertype__bool2x4(){return true;}
		virtual bool data__usertype__bool2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool2x4( void* attributeData ){return begin__usertype__bool2x4();}
		bool _data__usertype__bool2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL3X1 = 88060785;
		virtual bool begin__usertype__bool3x1(){return true;}
		virtual bool end__usertype__bool3x1(){return true;}
		virtual bool data__usertype__bool3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool3x1( void* attributeData ){return begin__usertype__bool3x1();}
		bool _data__usertype__bool3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL3X2 = 88060786;
		virtual bool begin__usertype__bool3x2(){return true;}
		virtual bool end__usertype__bool3x2(){return true;}
		virtual bool data__usertype__bool3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool3x2( void* attributeData ){return begin__usertype__bool3x2();}
		bool _data__usertype__bool3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL3X3 = 88060787;
		virtual bool begin__usertype__bool3x3(){return true;}
		virtual bool end__usertype__bool3x3(){return true;}
		virtual bool data__usertype__bool3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool3x3( void* attributeData ){return begin__usertype__bool3x3();}
		bool _data__usertype__bool3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL3X4 = 88060788;
		virtual bool begin__usertype__bool3x4(){return true;}
		virtual bool end__usertype__bool3x4(){return true;}
		virtual bool data__usertype__bool3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool3x4( void* attributeData ){return begin__usertype__bool3x4();}
		bool _data__usertype__bool3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL4X1 = 88060529;
		virtual bool begin__usertype__bool4x1(){return true;}
		virtual bool end__usertype__bool4x1(){return true;}
		virtual bool data__usertype__bool4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool4x1( void* attributeData ){return begin__usertype__bool4x1();}
		bool _data__usertype__bool4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL4X2 = 88060530;
		virtual bool begin__usertype__bool4x2(){return true;}
		virtual bool end__usertype__bool4x2(){return true;}
		virtual bool data__usertype__bool4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool4x2( void* attributeData ){return begin__usertype__bool4x2();}
		bool _data__usertype__bool4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL4X3 = 88060531;
		virtual bool begin__usertype__bool4x3(){return true;}
		virtual bool end__usertype__bool4x3(){return true;}
		virtual bool data__usertype__bool4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool4x3( void* attributeData ){return begin__usertype__bool4x3();}
		bool _data__usertype__bool4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__BOOL4X4 = 88060532;
		virtual bool begin__usertype__bool4x4(){return true;}
		virtual bool end__usertype__bool4x4(){return true;}
		virtual bool data__usertype__bool4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__bool4x4( void* attributeData ){return begin__usertype__bool4x4();}
		bool _data__usertype__bool4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT = 163672004;
		virtual bool begin__usertype__float(){return true;}
		virtual bool end__usertype__float(){return true;}
		virtual bool data__usertype__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float( void* attributeData ){return begin__usertype__float();}
		bool _data__usertype__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT1 = 202833121;
		virtual bool begin__usertype__float1(){return true;}
		virtual bool end__usertype__float1(){return true;}
		virtual bool data__usertype__float1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float1( void* attributeData ){return begin__usertype__float1();}
		bool _data__usertype__float1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT2 = 202833122;
		virtual bool begin__usertype__float2(){return true;}
		virtual bool end__usertype__float2(){return true;}
		virtual bool data__usertype__float2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float2( void* attributeData ){return begin__usertype__float2();}
		bool _data__usertype__float2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT3 = 202833123;
		virtual bool begin__usertype__float3(){return true;}
		virtual bool end__usertype__float3(){return true;}
		virtual bool data__usertype__float3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float3( void* attributeData ){return begin__usertype__float3();}
		bool _data__usertype__float3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT4 = 202833124;
		virtual bool begin__usertype__float4(){return true;}
		virtual bool end__usertype__float4(){return true;}
		virtual bool data__usertype__float4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float4( void* attributeData ){return begin__usertype__float4();}
		bool _data__usertype__float4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X1 = 117236897;
		virtual bool begin__usertype__float1x1(){return true;}
		virtual bool end__usertype__float1x1(){return true;}
		virtual bool data__usertype__float1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float1x1( void* attributeData ){return begin__usertype__float1x1();}
		bool _data__usertype__float1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X2 = 117236898;
		virtual bool begin__usertype__float1x2(){return true;}
		virtual bool end__usertype__float1x2(){return true;}
		virtual bool data__usertype__float1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float1x2( void* attributeData ){return begin__usertype__float1x2();}
		bool _data__usertype__float1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X3 = 117236899;
		virtual bool begin__usertype__float1x3(){return true;}
		virtual bool end__usertype__float1x3(){return true;}
		virtual bool data__usertype__float1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float1x3( void* attributeData ){return begin__usertype__float1x3();}
		bool _data__usertype__float1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X4 = 117236900;
		virtual bool begin__usertype__float1x4(){return true;}
		virtual bool end__usertype__float1x4(){return true;}
		virtual bool data__usertype__float1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float1x4( void* attributeData ){return begin__usertype__float1x4();}
		bool _data__usertype__float1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X1 = 117237153;
		virtual bool begin__usertype__float2x1(){return true;}
		virtual bool end__usertype__float2x1(){return true;}
		virtual bool data__usertype__float2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float2x1( void* attributeData ){return begin__usertype__float2x1();}
		bool _data__usertype__float2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X2 = 117237154;
		virtual bool begin__usertype__float2x2(){return true;}
		virtual bool end__usertype__float2x2(){return true;}
		virtual bool data__usertype__float2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float2x2( void* attributeData ){return begin__usertype__float2x2();}
		bool _data__usertype__float2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X3 = 117237155;
		virtual bool begin__usertype__float2x3(){return true;}
		virtual bool end__usertype__float2x3(){return true;}
		virtual bool data__usertype__float2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float2x3( void* attributeData ){return begin__usertype__float2x3();}
		bool _data__usertype__float2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X4 = 117237156;
		virtual bool begin__usertype__float2x4(){return true;}
		virtual bool end__usertype__float2x4(){return true;}
		virtual bool data__usertype__float2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float2x4( void* attributeData ){return begin__usertype__float2x4();}
		bool _data__usertype__float2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X1 = 117237409;
		virtual bool begin__usertype__float3x1(){return true;}
		virtual bool end__usertype__float3x1(){return true;}
		virtual bool data__usertype__float3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float3x1( void* attributeData ){return begin__usertype__float3x1();}
		bool _data__usertype__float3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X2 = 117237410;
		virtual bool begin__usertype__float3x2(){return true;}
		virtual bool end__usertype__float3x2(){return true;}
		virtual bool data__usertype__float3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float3x2( void* attributeData ){return begin__usertype__float3x2();}
		bool _data__usertype__float3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X3 = 117237411;
		virtual bool begin__usertype__float3x3(){return true;}
		virtual bool end__usertype__float3x3(){return true;}
		virtual bool data__usertype__float3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float3x3( void* attributeData ){return begin__usertype__float3x3();}
		bool _data__usertype__float3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X4 = 117237412;
		virtual bool begin__usertype__float3x4(){return true;}
		virtual bool end__usertype__float3x4(){return true;}
		virtual bool data__usertype__float3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float3x4( void* attributeData ){return begin__usertype__float3x4();}
		bool _data__usertype__float3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X1 = 117237665;
		virtual bool begin__usertype__float4x1(){return true;}
		virtual bool end__usertype__float4x1(){return true;}
		virtual bool data__usertype__float4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float4x1( void* attributeData ){return begin__usertype__float4x1();}
		bool _data__usertype__float4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X2 = 117237666;
		virtual bool begin__usertype__float4x2(){return true;}
		virtual bool end__usertype__float4x2(){return true;}
		virtual bool data__usertype__float4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float4x2( void* attributeData ){return begin__usertype__float4x2();}
		bool _data__usertype__float4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X3 = 117237667;
		virtual bool begin__usertype__float4x3(){return true;}
		virtual bool end__usertype__float4x3(){return true;}
		virtual bool data__usertype__float4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float4x3( void* attributeData ){return begin__usertype__float4x3();}
		bool _data__usertype__float4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X4 = 117237668;
		virtual bool begin__usertype__float4x4(){return true;}
		virtual bool end__usertype__float4x4(){return true;}
		virtual bool data__usertype__float4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__float4x4( void* attributeData ){return begin__usertype__float4x4();}
		bool _data__usertype__float4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT = 172606500;
		virtual bool begin__usertype__int(){return true;}
		virtual bool end__usertype__int(){return true;}
		virtual bool data__usertype__int( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int( void* attributeData ){return begin__usertype__int();}
		bool _data__usertype__int( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT1 = 77349585;
		virtual bool begin__usertype__int1(){return true;}
		virtual bool end__usertype__int1(){return true;}
		virtual bool data__usertype__int1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int1( void* attributeData ){return begin__usertype__int1();}
		bool _data__usertype__int1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT2 = 77349586;
		virtual bool begin__usertype__int2(){return true;}
		virtual bool end__usertype__int2(){return true;}
		virtual bool data__usertype__int2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int2( void* attributeData ){return begin__usertype__int2();}
		bool _data__usertype__int2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT3 = 77349587;
		virtual bool begin__usertype__int3(){return true;}
		virtual bool end__usertype__int3(){return true;}
		virtual bool data__usertype__int3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int3( void* attributeData ){return begin__usertype__int3();}
		bool _data__usertype__int3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT4 = 77349588;
		virtual bool begin__usertype__int4(){return true;}
		virtual bool end__usertype__int4(){return true;}
		virtual bool data__usertype__int4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int4( void* attributeData ){return begin__usertype__int4();}
		bool _data__usertype__int4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT1X1 = 205708321;
		virtual bool begin__usertype__int1x1(){return true;}
		virtual bool end__usertype__int1x1(){return true;}
		virtual bool data__usertype__int1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int1x1( void* attributeData ){return begin__usertype__int1x1();}
		bool _data__usertype__int1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT1X2 = 205708322;
		virtual bool begin__usertype__int1x2(){return true;}
		virtual bool end__usertype__int1x2(){return true;}
		virtual bool data__usertype__int1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int1x2( void* attributeData ){return begin__usertype__int1x2();}
		bool _data__usertype__int1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT1X3 = 205708323;
		virtual bool begin__usertype__int1x3(){return true;}
		virtual bool end__usertype__int1x3(){return true;}
		virtual bool data__usertype__int1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int1x3( void* attributeData ){return begin__usertype__int1x3();}
		bool _data__usertype__int1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT1X4 = 205708324;
		virtual bool begin__usertype__int1x4(){return true;}
		virtual bool end__usertype__int1x4(){return true;}
		virtual bool data__usertype__int1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int1x4( void* attributeData ){return begin__usertype__int1x4();}
		bool _data__usertype__int1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT2X1 = 205708577;
		virtual bool begin__usertype__int2x1(){return true;}
		virtual bool end__usertype__int2x1(){return true;}
		virtual bool data__usertype__int2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int2x1( void* attributeData ){return begin__usertype__int2x1();}
		bool _data__usertype__int2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT2X2 = 205708578;
		virtual bool begin__usertype__int2x2(){return true;}
		virtual bool end__usertype__int2x2(){return true;}
		virtual bool data__usertype__int2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int2x2( void* attributeData ){return begin__usertype__int2x2();}
		bool _data__usertype__int2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT2X3 = 205708579;
		virtual bool begin__usertype__int2x3(){return true;}
		virtual bool end__usertype__int2x3(){return true;}
		virtual bool data__usertype__int2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int2x3( void* attributeData ){return begin__usertype__int2x3();}
		bool _data__usertype__int2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT2X4 = 205708580;
		virtual bool begin__usertype__int2x4(){return true;}
		virtual bool end__usertype__int2x4(){return true;}
		virtual bool data__usertype__int2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int2x4( void* attributeData ){return begin__usertype__int2x4();}
		bool _data__usertype__int2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT3X1 = 205708833;
		virtual bool begin__usertype__int3x1(){return true;}
		virtual bool end__usertype__int3x1(){return true;}
		virtual bool data__usertype__int3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int3x1( void* attributeData ){return begin__usertype__int3x1();}
		bool _data__usertype__int3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT3X2 = 205708834;
		virtual bool begin__usertype__int3x2(){return true;}
		virtual bool end__usertype__int3x2(){return true;}
		virtual bool data__usertype__int3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int3x2( void* attributeData ){return begin__usertype__int3x2();}
		bool _data__usertype__int3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT3X3 = 205708835;
		virtual bool begin__usertype__int3x3(){return true;}
		virtual bool end__usertype__int3x3(){return true;}
		virtual bool data__usertype__int3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int3x3( void* attributeData ){return begin__usertype__int3x3();}
		bool _data__usertype__int3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT3X4 = 205708836;
		virtual bool begin__usertype__int3x4(){return true;}
		virtual bool end__usertype__int3x4(){return true;}
		virtual bool data__usertype__int3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int3x4( void* attributeData ){return begin__usertype__int3x4();}
		bool _data__usertype__int3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT4X1 = 205709089;
		virtual bool begin__usertype__int4x1(){return true;}
		virtual bool end__usertype__int4x1(){return true;}
		virtual bool data__usertype__int4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int4x1( void* attributeData ){return begin__usertype__int4x1();}
		bool _data__usertype__int4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT4X2 = 205709090;
		virtual bool begin__usertype__int4x2(){return true;}
		virtual bool end__usertype__int4x2(){return true;}
		virtual bool data__usertype__int4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int4x2( void* attributeData ){return begin__usertype__int4x2();}
		bool _data__usertype__int4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT4X3 = 205709091;
		virtual bool begin__usertype__int4x3(){return true;}
		virtual bool end__usertype__int4x3(){return true;}
		virtual bool data__usertype__int4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int4x3( void* attributeData ){return begin__usertype__int4x3();}
		bool _data__usertype__int4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__INT4X4 = 205709092;
		virtual bool begin__usertype__int4x4(){return true;}
		virtual bool end__usertype__int4x4(){return true;}
		virtual bool data__usertype__int4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__int4x4( void* attributeData ){return begin__usertype__int4x4();}
		bool _data__usertype__int4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF = 77341062;
		virtual bool begin__usertype__half(){return true;}
		virtual bool end__usertype__half(){return true;}
		virtual bool data__usertype__half( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half( void* attributeData ){return begin__usertype__half();}
		bool _data__usertype__half( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF1 = 163715281;
		virtual bool begin__usertype__half1(){return true;}
		virtual bool end__usertype__half1(){return true;}
		virtual bool data__usertype__half1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half1( void* attributeData ){return begin__usertype__half1();}
		bool _data__usertype__half1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF2 = 163715282;
		virtual bool begin__usertype__half2(){return true;}
		virtual bool end__usertype__half2(){return true;}
		virtual bool data__usertype__half2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half2( void* attributeData ){return begin__usertype__half2();}
		bool _data__usertype__half2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF3 = 163715283;
		virtual bool begin__usertype__half3(){return true;}
		virtual bool end__usertype__half3(){return true;}
		virtual bool data__usertype__half3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half3( void* attributeData ){return begin__usertype__half3();}
		bool _data__usertype__half3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF4 = 163715284;
		virtual bool begin__usertype__half4(){return true;}
		virtual bool end__usertype__half4(){return true;}
		virtual bool data__usertype__half4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half4( void* attributeData ){return begin__usertype__half4();}
		bool _data__usertype__half4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF1X1 = 35180913;
		virtual bool begin__usertype__half1x1(){return true;}
		virtual bool end__usertype__half1x1(){return true;}
		virtual bool data__usertype__half1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half1x1( void* attributeData ){return begin__usertype__half1x1();}
		bool _data__usertype__half1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF1X2 = 35180914;
		virtual bool begin__usertype__half1x2(){return true;}
		virtual bool end__usertype__half1x2(){return true;}
		virtual bool data__usertype__half1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half1x2( void* attributeData ){return begin__usertype__half1x2();}
		bool _data__usertype__half1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF1X3 = 35180915;
		virtual bool begin__usertype__half1x3(){return true;}
		virtual bool end__usertype__half1x3(){return true;}
		virtual bool data__usertype__half1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half1x3( void* attributeData ){return begin__usertype__half1x3();}
		bool _data__usertype__half1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF1X4 = 35180916;
		virtual bool begin__usertype__half1x4(){return true;}
		virtual bool end__usertype__half1x4(){return true;}
		virtual bool data__usertype__half1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half1x4( void* attributeData ){return begin__usertype__half1x4();}
		bool _data__usertype__half1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF2X1 = 35180657;
		virtual bool begin__usertype__half2x1(){return true;}
		virtual bool end__usertype__half2x1(){return true;}
		virtual bool data__usertype__half2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half2x1( void* attributeData ){return begin__usertype__half2x1();}
		bool _data__usertype__half2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF2X2 = 35180658;
		virtual bool begin__usertype__half2x2(){return true;}
		virtual bool end__usertype__half2x2(){return true;}
		virtual bool data__usertype__half2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half2x2( void* attributeData ){return begin__usertype__half2x2();}
		bool _data__usertype__half2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF2X3 = 35180659;
		virtual bool begin__usertype__half2x3(){return true;}
		virtual bool end__usertype__half2x3(){return true;}
		virtual bool data__usertype__half2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half2x3( void* attributeData ){return begin__usertype__half2x3();}
		bool _data__usertype__half2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF2X4 = 35180660;
		virtual bool begin__usertype__half2x4(){return true;}
		virtual bool end__usertype__half2x4(){return true;}
		virtual bool data__usertype__half2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half2x4( void* attributeData ){return begin__usertype__half2x4();}
		bool _data__usertype__half2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF3X1 = 35181425;
		virtual bool begin__usertype__half3x1(){return true;}
		virtual bool end__usertype__half3x1(){return true;}
		virtual bool data__usertype__half3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half3x1( void* attributeData ){return begin__usertype__half3x1();}
		bool _data__usertype__half3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF3X2 = 35181426;
		virtual bool begin__usertype__half3x2(){return true;}
		virtual bool end__usertype__half3x2(){return true;}
		virtual bool data__usertype__half3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half3x2( void* attributeData ){return begin__usertype__half3x2();}
		bool _data__usertype__half3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF3X3 = 35181427;
		virtual bool begin__usertype__half3x3(){return true;}
		virtual bool end__usertype__half3x3(){return true;}
		virtual bool data__usertype__half3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half3x3( void* attributeData ){return begin__usertype__half3x3();}
		bool _data__usertype__half3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF3X4 = 35181428;
		virtual bool begin__usertype__half3x4(){return true;}
		virtual bool end__usertype__half3x4(){return true;}
		virtual bool data__usertype__half3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half3x4( void* attributeData ){return begin__usertype__half3x4();}
		bool _data__usertype__half3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF4X1 = 35181169;
		virtual bool begin__usertype__half4x1(){return true;}
		virtual bool end__usertype__half4x1(){return true;}
		virtual bool data__usertype__half4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half4x1( void* attributeData ){return begin__usertype__half4x1();}
		bool _data__usertype__half4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF4X2 = 35181170;
		virtual bool begin__usertype__half4x2(){return true;}
		virtual bool end__usertype__half4x2(){return true;}
		virtual bool data__usertype__half4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half4x2( void* attributeData ){return begin__usertype__half4x2();}
		bool _data__usertype__half4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF4X3 = 35181171;
		virtual bool begin__usertype__half4x3(){return true;}
		virtual bool end__usertype__half4x3(){return true;}
		virtual bool data__usertype__half4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half4x3( void* attributeData ){return begin__usertype__half4x3();}
		bool _data__usertype__half4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__HALF4X4 = 35181172;
		virtual bool begin__usertype__half4x4(){return true;}
		virtual bool end__usertype__half4x4(){return true;}
		virtual bool data__usertype__half4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__half4x4( void* attributeData ){return begin__usertype__half4x4();}
		bool _data__usertype__half4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED = 163673332;
		virtual bool begin__usertype__fixed(){return true;}
		virtual bool end__usertype__fixed(){return true;}
		virtual bool data__usertype__fixed( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed( void* attributeData ){return begin__usertype__fixed();}
		bool _data__usertype__fixed( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED1 = 202854369;
		virtual bool begin__usertype__fixed1(){return true;}
		virtual bool end__usertype__fixed1(){return true;}
		virtual bool data__usertype__fixed1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed1( void* attributeData ){return begin__usertype__fixed1();}
		bool _data__usertype__fixed1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED2 = 202854370;
		virtual bool begin__usertype__fixed2(){return true;}
		virtual bool end__usertype__fixed2(){return true;}
		virtual bool data__usertype__fixed2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed2( void* attributeData ){return begin__usertype__fixed2();}
		bool _data__usertype__fixed2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED3 = 202854371;
		virtual bool begin__usertype__fixed3(){return true;}
		virtual bool end__usertype__fixed3(){return true;}
		virtual bool data__usertype__fixed3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed3( void* attributeData ){return begin__usertype__fixed3();}
		bool _data__usertype__fixed3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED4 = 202854372;
		virtual bool begin__usertype__fixed4(){return true;}
		virtual bool end__usertype__fixed4(){return true;}
		virtual bool data__usertype__fixed4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed4( void* attributeData ){return begin__usertype__fixed4();}
		bool _data__usertype__fixed4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED1X1 = 122676385;
		virtual bool begin__usertype__fixed1x1(){return true;}
		virtual bool end__usertype__fixed1x1(){return true;}
		virtual bool data__usertype__fixed1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed1x1( void* attributeData ){return begin__usertype__fixed1x1();}
		bool _data__usertype__fixed1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED1X2 = 122676386;
		virtual bool begin__usertype__fixed1x2(){return true;}
		virtual bool end__usertype__fixed1x2(){return true;}
		virtual bool data__usertype__fixed1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed1x2( void* attributeData ){return begin__usertype__fixed1x2();}
		bool _data__usertype__fixed1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED1X3 = 122676387;
		virtual bool begin__usertype__fixed1x3(){return true;}
		virtual bool end__usertype__fixed1x3(){return true;}
		virtual bool data__usertype__fixed1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed1x3( void* attributeData ){return begin__usertype__fixed1x3();}
		bool _data__usertype__fixed1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED1X4 = 122676388;
		virtual bool begin__usertype__fixed1x4(){return true;}
		virtual bool end__usertype__fixed1x4(){return true;}
		virtual bool data__usertype__fixed1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed1x4( void* attributeData ){return begin__usertype__fixed1x4();}
		bool _data__usertype__fixed1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED2X1 = 122676641;
		virtual bool begin__usertype__fixed2x1(){return true;}
		virtual bool end__usertype__fixed2x1(){return true;}
		virtual bool data__usertype__fixed2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed2x1( void* attributeData ){return begin__usertype__fixed2x1();}
		bool _data__usertype__fixed2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED2X2 = 122676642;
		virtual bool begin__usertype__fixed2x2(){return true;}
		virtual bool end__usertype__fixed2x2(){return true;}
		virtual bool data__usertype__fixed2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed2x2( void* attributeData ){return begin__usertype__fixed2x2();}
		bool _data__usertype__fixed2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED2X3 = 122676643;
		virtual bool begin__usertype__fixed2x3(){return true;}
		virtual bool end__usertype__fixed2x3(){return true;}
		virtual bool data__usertype__fixed2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed2x3( void* attributeData ){return begin__usertype__fixed2x3();}
		bool _data__usertype__fixed2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED2X4 = 122676644;
		virtual bool begin__usertype__fixed2x4(){return true;}
		virtual bool end__usertype__fixed2x4(){return true;}
		virtual bool data__usertype__fixed2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed2x4( void* attributeData ){return begin__usertype__fixed2x4();}
		bool _data__usertype__fixed2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED3X1 = 122676897;
		virtual bool begin__usertype__fixed3x1(){return true;}
		virtual bool end__usertype__fixed3x1(){return true;}
		virtual bool data__usertype__fixed3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed3x1( void* attributeData ){return begin__usertype__fixed3x1();}
		bool _data__usertype__fixed3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED3X2 = 122676898;
		virtual bool begin__usertype__fixed3x2(){return true;}
		virtual bool end__usertype__fixed3x2(){return true;}
		virtual bool data__usertype__fixed3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed3x2( void* attributeData ){return begin__usertype__fixed3x2();}
		bool _data__usertype__fixed3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED3X3 = 122676899;
		virtual bool begin__usertype__fixed3x3(){return true;}
		virtual bool end__usertype__fixed3x3(){return true;}
		virtual bool data__usertype__fixed3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed3x3( void* attributeData ){return begin__usertype__fixed3x3();}
		bool _data__usertype__fixed3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED3X4 = 122676900;
		virtual bool begin__usertype__fixed3x4(){return true;}
		virtual bool end__usertype__fixed3x4(){return true;}
		virtual bool data__usertype__fixed3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed3x4( void* attributeData ){return begin__usertype__fixed3x4();}
		bool _data__usertype__fixed3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED4X1 = 122677153;
		virtual bool begin__usertype__fixed4x1(){return true;}
		virtual bool end__usertype__fixed4x1(){return true;}
		virtual bool data__usertype__fixed4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed4x1( void* attributeData ){return begin__usertype__fixed4x1();}
		bool _data__usertype__fixed4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x1();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED4X2 = 122677154;
		virtual bool begin__usertype__fixed4x2(){return true;}
		virtual bool end__usertype__fixed4x2(){return true;}
		virtual bool data__usertype__fixed4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed4x2( void* attributeData ){return begin__usertype__fixed4x2();}
		bool _data__usertype__fixed4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x2();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED4X3 = 122677155;
		virtual bool begin__usertype__fixed4x3(){return true;}
		virtual bool end__usertype__fixed4x3(){return true;}
		virtual bool data__usertype__fixed4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed4x3( void* attributeData ){return begin__usertype__fixed4x3();}
		bool _data__usertype__fixed4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x3();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__FIXED4X4 = 122677156;
		virtual bool begin__usertype__fixed4x4(){return true;}
		virtual bool end__usertype__fixed4x4(){return true;}
		virtual bool data__usertype__fixed4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__fixed4x4( void* attributeData ){return begin__usertype__fixed4x4();}
		bool _data__usertype__fixed4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x4();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SURFACE = 112365157;
		struct usertype__surface__AttributeData
		{
			static const usertype__surface__AttributeData DEFAULT;

			const ParserChar* type;
		};
		virtual bool begin__usertype__surface( const usertype__surface__AttributeData& attributeData ){return true;}
		virtual bool end__usertype__surface(){return true;}
	private:
		bool _begin__usertype__surface( void* attributeData ){return begin__usertype__surface(*static_cast<usertype__surface__AttributeData*>(attributeData));}
		bool _data__usertype__surface( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__surface();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SAMPLER1D = 238760004;
		virtual bool begin__usertype__sampler1D(){return true;}
		virtual bool end__usertype__sampler1D(){return true;}
	private:
		bool _begin__usertype__sampler1D( void* attributeData ){return begin__usertype__sampler1D();}
		bool _data__usertype__sampler1D( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__sampler1D();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SAMPLER2D = 238760052;
		virtual bool begin__usertype__sampler2D(){return true;}
		virtual bool end__usertype__sampler2D(){return true;}
	private:
		bool _begin__usertype__sampler2D( void* attributeData ){return begin__usertype__sampler2D();}
		bool _data__usertype__sampler2D( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__sampler2D();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SAMPLER3D = 238760036;
		virtual bool begin__usertype__sampler3D(){return true;}
		virtual bool end__usertype__sampler3D(){return true;}
	private:
		bool _begin__usertype__sampler3D( void* attributeData ){return begin__usertype__sampler3D();}
		bool _data__usertype__sampler3D( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__sampler3D();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SAMPLERRECT = 187856820;
		virtual bool begin__usertype__samplerRECT(){return true;}
		virtual bool end__usertype__samplerRECT(){return true;}
	private:
		bool _begin__usertype__samplerRECT( void* attributeData ){return begin__usertype__samplerRECT();}
		bool _data__usertype__samplerRECT( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__samplerRECT();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SAMPLERCUBE = 187930453;
		virtual bool begin__usertype__samplerCUBE(){return true;}
		virtual bool end__usertype__samplerCUBE(){return true;}
	private:
		bool _begin__usertype__samplerCUBE( void* attributeData ){return begin__usertype__samplerCUBE();}
		bool _data__usertype__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__samplerCUBE();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SAMPLERDEPTH = 54085176;
		virtual bool begin__usertype__samplerDEPTH(){return true;}
		virtual bool end__usertype__samplerDEPTH(){return true;}
	private:
		bool _begin__usertype__samplerDEPTH( void* attributeData ){return begin__usertype__samplerDEPTH();}
		bool _data__usertype__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__samplerDEPTH();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__STRING = 258747607;
		virtual bool begin__usertype__string(){return true;}
		virtual bool end__usertype__string(){return true;}
		virtual bool data__usertype__string( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__string( void* attributeData ){return begin__usertype__string();}
		bool _data__usertype__string( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__string();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__ENUM = 77365789;
		virtual bool begin__usertype__enum(){return true;}
		virtual bool end__usertype__enum(){return true;}
		virtual bool data__usertype__enum( const void* data, size_t length ){return true;}
	private:
		bool _begin__usertype__enum( void* attributeData ){return begin__usertype__enum();}
		bool _data__usertype__enum( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__enum();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__ARRAY = 163898057;
		struct usertype__array__AttributeData
		{
			static const usertype__array__AttributeData DEFAULT;

			long length;
		};
		virtual bool begin__usertype__array( const usertype__array__AttributeData& attributeData ){return true;}
		virtual bool end__usertype__array(){return true;}
	private:
		bool _begin__usertype__array( void* attributeData ){return begin__usertype__array(*static_cast<usertype__array__AttributeData*>(attributeData));}
		bool _data__usertype__array( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__array();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL1 = 64154881;
		virtual bool begin__array__bool1(){return true;}
		virtual bool end__array__bool1(){return true;}
		virtual bool data__array__bool1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool1( void* attributeData ){return begin__array__bool1();}
		bool _data__array__bool1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL1X1 = 49089377;
		virtual bool begin__array__bool1x1(){return true;}
		virtual bool end__array__bool1x1(){return true;}
		virtual bool data__array__bool1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool1x1( void* attributeData ){return begin__array__bool1x1();}
		bool _data__array__bool1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL1X2 = 49089378;
		virtual bool begin__array__bool1x2(){return true;}
		virtual bool end__array__bool1x2(){return true;}
		virtual bool data__array__bool1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool1x2( void* attributeData ){return begin__array__bool1x2();}
		bool _data__array__bool1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL1X3 = 49089379;
		virtual bool begin__array__bool1x3(){return true;}
		virtual bool end__array__bool1x3(){return true;}
		virtual bool data__array__bool1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool1x3( void* attributeData ){return begin__array__bool1x3();}
		bool _data__array__bool1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL1X4 = 49089380;
		virtual bool begin__array__bool1x4(){return true;}
		virtual bool end__array__bool1x4(){return true;}
		virtual bool data__array__bool1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool1x4( void* attributeData ){return begin__array__bool1x4();}
		bool _data__array__bool1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL2X1 = 49089121;
		virtual bool begin__array__bool2x1(){return true;}
		virtual bool end__array__bool2x1(){return true;}
		virtual bool data__array__bool2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool2x1( void* attributeData ){return begin__array__bool2x1();}
		bool _data__array__bool2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL2X2 = 49089122;
		virtual bool begin__array__bool2x2(){return true;}
		virtual bool end__array__bool2x2(){return true;}
		virtual bool data__array__bool2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool2x2( void* attributeData ){return begin__array__bool2x2();}
		bool _data__array__bool2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL2X3 = 49089123;
		virtual bool begin__array__bool2x3(){return true;}
		virtual bool end__array__bool2x3(){return true;}
		virtual bool data__array__bool2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool2x3( void* attributeData ){return begin__array__bool2x3();}
		bool _data__array__bool2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL2X4 = 49089124;
		virtual bool begin__array__bool2x4(){return true;}
		virtual bool end__array__bool2x4(){return true;}
		virtual bool data__array__bool2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool2x4( void* attributeData ){return begin__array__bool2x4();}
		bool _data__array__bool2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL3X1 = 49088865;
		virtual bool begin__array__bool3x1(){return true;}
		virtual bool end__array__bool3x1(){return true;}
		virtual bool data__array__bool3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool3x1( void* attributeData ){return begin__array__bool3x1();}
		bool _data__array__bool3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL3X2 = 49088866;
		virtual bool begin__array__bool3x2(){return true;}
		virtual bool end__array__bool3x2(){return true;}
		virtual bool data__array__bool3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool3x2( void* attributeData ){return begin__array__bool3x2();}
		bool _data__array__bool3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL3X3 = 49088867;
		virtual bool begin__array__bool3x3(){return true;}
		virtual bool end__array__bool3x3(){return true;}
		virtual bool data__array__bool3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool3x3( void* attributeData ){return begin__array__bool3x3();}
		bool _data__array__bool3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL3X4 = 49088868;
		virtual bool begin__array__bool3x4(){return true;}
		virtual bool end__array__bool3x4(){return true;}
		virtual bool data__array__bool3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool3x4( void* attributeData ){return begin__array__bool3x4();}
		bool _data__array__bool3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL4X1 = 49088609;
		virtual bool begin__array__bool4x1(){return true;}
		virtual bool end__array__bool4x1(){return true;}
		virtual bool data__array__bool4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool4x1( void* attributeData ){return begin__array__bool4x1();}
		bool _data__array__bool4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL4X2 = 49088610;
		virtual bool begin__array__bool4x2(){return true;}
		virtual bool end__array__bool4x2(){return true;}
		virtual bool data__array__bool4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool4x2( void* attributeData ){return begin__array__bool4x2();}
		bool _data__array__bool4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL4X3 = 49088611;
		virtual bool begin__array__bool4x3(){return true;}
		virtual bool end__array__bool4x3(){return true;}
		virtual bool data__array__bool4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool4x3( void* attributeData ){return begin__array__bool4x3();}
		bool _data__array__bool4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__BOOL4X4 = 49088612;
		virtual bool begin__array__bool4x4(){return true;}
		virtual bool end__array__bool4x4(){return true;}
		virtual bool data__array__bool4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__bool4x4( void* attributeData ){return begin__array__bool4x4();}
		bool _data__array__bool4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT1 = 225171265;
		virtual bool begin__array__float1(){return true;}
		virtual bool end__array__float1(){return true;}
		virtual bool data__array__float1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float1( void* attributeData ){return begin__array__float1();}
		bool _data__array__float1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT1X1 = 198657489;
		virtual bool begin__array__float1x1(){return true;}
		virtual bool end__array__float1x1(){return true;}
		virtual bool data__array__float1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float1x1( void* attributeData ){return begin__array__float1x1();}
		bool _data__array__float1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT1X2 = 198657490;
		virtual bool begin__array__float1x2(){return true;}
		virtual bool end__array__float1x2(){return true;}
		virtual bool data__array__float1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float1x2( void* attributeData ){return begin__array__float1x2();}
		bool _data__array__float1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT1X3 = 198657491;
		virtual bool begin__array__float1x3(){return true;}
		virtual bool end__array__float1x3(){return true;}
		virtual bool data__array__float1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float1x3( void* attributeData ){return begin__array__float1x3();}
		bool _data__array__float1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT1X4 = 198657492;
		virtual bool begin__array__float1x4(){return true;}
		virtual bool end__array__float1x4(){return true;}
		virtual bool data__array__float1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float1x4( void* attributeData ){return begin__array__float1x4();}
		bool _data__array__float1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT2X1 = 198657233;
		virtual bool begin__array__float2x1(){return true;}
		virtual bool end__array__float2x1(){return true;}
		virtual bool data__array__float2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float2x1( void* attributeData ){return begin__array__float2x1();}
		bool _data__array__float2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT2X3 = 198657235;
		virtual bool begin__array__float2x3(){return true;}
		virtual bool end__array__float2x3(){return true;}
		virtual bool data__array__float2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float2x3( void* attributeData ){return begin__array__float2x3();}
		bool _data__array__float2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT2X4 = 198657236;
		virtual bool begin__array__float2x4(){return true;}
		virtual bool end__array__float2x4(){return true;}
		virtual bool data__array__float2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float2x4( void* attributeData ){return begin__array__float2x4();}
		bool _data__array__float2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT3X1 = 198658001;
		virtual bool begin__array__float3x1(){return true;}
		virtual bool end__array__float3x1(){return true;}
		virtual bool data__array__float3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float3x1( void* attributeData ){return begin__array__float3x1();}
		bool _data__array__float3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT3X2 = 198658002;
		virtual bool begin__array__float3x2(){return true;}
		virtual bool end__array__float3x2(){return true;}
		virtual bool data__array__float3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float3x2( void* attributeData ){return begin__array__float3x2();}
		bool _data__array__float3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT3X4 = 198658004;
		virtual bool begin__array__float3x4(){return true;}
		virtual bool end__array__float3x4(){return true;}
		virtual bool data__array__float3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float3x4( void* attributeData ){return begin__array__float3x4();}
		bool _data__array__float3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT4X1 = 198657745;
		virtual bool begin__array__float4x1(){return true;}
		virtual bool end__array__float4x1(){return true;}
		virtual bool data__array__float4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float4x1( void* attributeData ){return begin__array__float4x1();}
		bool _data__array__float4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT4X2 = 198657746;
		virtual bool begin__array__float4x2(){return true;}
		virtual bool end__array__float4x2(){return true;}
		virtual bool data__array__float4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float4x2( void* attributeData ){return begin__array__float4x2();}
		bool _data__array__float4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FLOAT4X3 = 198657747;
		virtual bool begin__array__float4x3(){return true;}
		virtual bool end__array__float4x3(){return true;}
		virtual bool data__array__float4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__float4x3( void* attributeData ){return begin__array__float4x3();}
		bool _data__array__float4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT1 = 255688177;
		virtual bool begin__array__int1(){return true;}
		virtual bool end__array__int1(){return true;}
		virtual bool data__array__int1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int1( void* attributeData ){return begin__array__int1();}
		bool _data__array__int1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT1X1 = 226359169;
		virtual bool begin__array__int1x1(){return true;}
		virtual bool end__array__int1x1(){return true;}
		virtual bool data__array__int1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int1x1( void* attributeData ){return begin__array__int1x1();}
		bool _data__array__int1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT1X2 = 226359170;
		virtual bool begin__array__int1x2(){return true;}
		virtual bool end__array__int1x2(){return true;}
		virtual bool data__array__int1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int1x2( void* attributeData ){return begin__array__int1x2();}
		bool _data__array__int1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT1X3 = 226359171;
		virtual bool begin__array__int1x3(){return true;}
		virtual bool end__array__int1x3(){return true;}
		virtual bool data__array__int1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int1x3( void* attributeData ){return begin__array__int1x3();}
		bool _data__array__int1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT1X4 = 226359172;
		virtual bool begin__array__int1x4(){return true;}
		virtual bool end__array__int1x4(){return true;}
		virtual bool data__array__int1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int1x4( void* attributeData ){return begin__array__int1x4();}
		bool _data__array__int1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT2X1 = 226358913;
		virtual bool begin__array__int2x1(){return true;}
		virtual bool end__array__int2x1(){return true;}
		virtual bool data__array__int2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int2x1( void* attributeData ){return begin__array__int2x1();}
		bool _data__array__int2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT2X2 = 226358914;
		virtual bool begin__array__int2x2(){return true;}
		virtual bool end__array__int2x2(){return true;}
		virtual bool data__array__int2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int2x2( void* attributeData ){return begin__array__int2x2();}
		bool _data__array__int2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT2X3 = 226358915;
		virtual bool begin__array__int2x3(){return true;}
		virtual bool end__array__int2x3(){return true;}
		virtual bool data__array__int2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int2x3( void* attributeData ){return begin__array__int2x3();}
		bool _data__array__int2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT2X4 = 226358916;
		virtual bool begin__array__int2x4(){return true;}
		virtual bool end__array__int2x4(){return true;}
		virtual bool data__array__int2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int2x4( void* attributeData ){return begin__array__int2x4();}
		bool _data__array__int2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT3X1 = 226358657;
		virtual bool begin__array__int3x1(){return true;}
		virtual bool end__array__int3x1(){return true;}
		virtual bool data__array__int3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int3x1( void* attributeData ){return begin__array__int3x1();}
		bool _data__array__int3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT3X2 = 226358658;
		virtual bool begin__array__int3x2(){return true;}
		virtual bool end__array__int3x2(){return true;}
		virtual bool data__array__int3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int3x2( void* attributeData ){return begin__array__int3x2();}
		bool _data__array__int3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT3X3 = 226358659;
		virtual bool begin__array__int3x3(){return true;}
		virtual bool end__array__int3x3(){return true;}
		virtual bool data__array__int3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int3x3( void* attributeData ){return begin__array__int3x3();}
		bool _data__array__int3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT3X4 = 226358660;
		virtual bool begin__array__int3x4(){return true;}
		virtual bool end__array__int3x4(){return true;}
		virtual bool data__array__int3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int3x4( void* attributeData ){return begin__array__int3x4();}
		bool _data__array__int3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT4X1 = 226358401;
		virtual bool begin__array__int4x1(){return true;}
		virtual bool end__array__int4x1(){return true;}
		virtual bool data__array__int4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int4x1( void* attributeData ){return begin__array__int4x1();}
		bool _data__array__int4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT4X2 = 226358402;
		virtual bool begin__array__int4x2(){return true;}
		virtual bool end__array__int4x2(){return true;}
		virtual bool data__array__int4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int4x2( void* attributeData ){return begin__array__int4x2();}
		bool _data__array__int4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT4X3 = 226358403;
		virtual bool begin__array__int4x3(){return true;}
		virtual bool end__array__int4x3(){return true;}
		virtual bool data__array__int4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int4x3( void* attributeData ){return begin__array__int4x3();}
		bool _data__array__int4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__INT4X4 = 226358404;
		virtual bool begin__array__int4x4(){return true;}
		virtual bool end__array__int4x4(){return true;}
		virtual bool data__array__int4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__int4x4( void* attributeData ){return begin__array__int4x4();}
		bool _data__array__int4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF = 255688870;
		virtual bool begin__array__half(){return true;}
		virtual bool end__array__half(){return true;}
		virtual bool data__array__half( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half( void* attributeData ){return begin__array__half();}
		bool _data__array__half( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF1 = 64490081;
		virtual bool begin__array__half1(){return true;}
		virtual bool end__array__half1(){return true;}
		virtual bool data__array__half1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half1( void* attributeData ){return begin__array__half1();}
		bool _data__array__half1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF2 = 64490082;
		virtual bool begin__array__half2(){return true;}
		virtual bool end__array__half2(){return true;}
		virtual bool data__array__half2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half2( void* attributeData ){return begin__array__half2();}
		bool _data__array__half2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF3 = 64490083;
		virtual bool begin__array__half3(){return true;}
		virtual bool end__array__half3(){return true;}
		virtual bool data__array__half3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half3( void* attributeData ){return begin__array__half3();}
		bool _data__array__half3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF4 = 64490084;
		virtual bool begin__array__half4(){return true;}
		virtual bool end__array__half4(){return true;}
		virtual bool data__array__half4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half4( void* attributeData ){return begin__array__half4();}
		bool _data__array__half4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF1X1 = 134900577;
		virtual bool begin__array__half1x1(){return true;}
		virtual bool end__array__half1x1(){return true;}
		virtual bool data__array__half1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half1x1( void* attributeData ){return begin__array__half1x1();}
		bool _data__array__half1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF1X2 = 134900578;
		virtual bool begin__array__half1x2(){return true;}
		virtual bool end__array__half1x2(){return true;}
		virtual bool data__array__half1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half1x2( void* attributeData ){return begin__array__half1x2();}
		bool _data__array__half1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF1X3 = 134900579;
		virtual bool begin__array__half1x3(){return true;}
		virtual bool end__array__half1x3(){return true;}
		virtual bool data__array__half1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half1x3( void* attributeData ){return begin__array__half1x3();}
		bool _data__array__half1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF1X4 = 134900580;
		virtual bool begin__array__half1x4(){return true;}
		virtual bool end__array__half1x4(){return true;}
		virtual bool data__array__half1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half1x4( void* attributeData ){return begin__array__half1x4();}
		bool _data__array__half1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF2X1 = 134900321;
		virtual bool begin__array__half2x1(){return true;}
		virtual bool end__array__half2x1(){return true;}
		virtual bool data__array__half2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half2x1( void* attributeData ){return begin__array__half2x1();}
		bool _data__array__half2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF2X2 = 134900322;
		virtual bool begin__array__half2x2(){return true;}
		virtual bool end__array__half2x2(){return true;}
		virtual bool data__array__half2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half2x2( void* attributeData ){return begin__array__half2x2();}
		bool _data__array__half2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF2X3 = 134900323;
		virtual bool begin__array__half2x3(){return true;}
		virtual bool end__array__half2x3(){return true;}
		virtual bool data__array__half2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half2x3( void* attributeData ){return begin__array__half2x3();}
		bool _data__array__half2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF2X4 = 134900324;
		virtual bool begin__array__half2x4(){return true;}
		virtual bool end__array__half2x4(){return true;}
		virtual bool data__array__half2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half2x4( void* attributeData ){return begin__array__half2x4();}
		bool _data__array__half2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF3X1 = 134900065;
		virtual bool begin__array__half3x1(){return true;}
		virtual bool end__array__half3x1(){return true;}
		virtual bool data__array__half3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half3x1( void* attributeData ){return begin__array__half3x1();}
		bool _data__array__half3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF3X2 = 134900066;
		virtual bool begin__array__half3x2(){return true;}
		virtual bool end__array__half3x2(){return true;}
		virtual bool data__array__half3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half3x2( void* attributeData ){return begin__array__half3x2();}
		bool _data__array__half3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF3X3 = 134900067;
		virtual bool begin__array__half3x3(){return true;}
		virtual bool end__array__half3x3(){return true;}
		virtual bool data__array__half3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half3x3( void* attributeData ){return begin__array__half3x3();}
		bool _data__array__half3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF3X4 = 134900068;
		virtual bool begin__array__half3x4(){return true;}
		virtual bool end__array__half3x4(){return true;}
		virtual bool data__array__half3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half3x4( void* attributeData ){return begin__array__half3x4();}
		bool _data__array__half3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF4X1 = 134899809;
		virtual bool begin__array__half4x1(){return true;}
		virtual bool end__array__half4x1(){return true;}
		virtual bool data__array__half4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half4x1( void* attributeData ){return begin__array__half4x1();}
		bool _data__array__half4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF4X2 = 134899810;
		virtual bool begin__array__half4x2(){return true;}
		virtual bool end__array__half4x2(){return true;}
		virtual bool data__array__half4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half4x2( void* attributeData ){return begin__array__half4x2();}
		bool _data__array__half4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF4X3 = 134899811;
		virtual bool begin__array__half4x3(){return true;}
		virtual bool end__array__half4x3(){return true;}
		virtual bool data__array__half4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half4x3( void* attributeData ){return begin__array__half4x3();}
		bool _data__array__half4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__HALF4X4 = 134899812;
		virtual bool begin__array__half4x4(){return true;}
		virtual bool end__array__half4x4(){return true;}
		virtual bool data__array__half4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__half4x4( void* attributeData ){return begin__array__half4x4();}
		bool _data__array__half4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED = 64390724;
		virtual bool begin__array__fixed(){return true;}
		virtual bool end__array__fixed(){return true;}
		virtual bool data__array__fixed( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed( void* attributeData ){return begin__array__fixed();}
		bool _data__array__fixed( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED1 = 224945217;
		virtual bool begin__array__fixed1(){return true;}
		virtual bool end__array__fixed1(){return true;}
		virtual bool data__array__fixed1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed1( void* attributeData ){return begin__array__fixed1();}
		bool _data__array__fixed1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED2 = 224945218;
		virtual bool begin__array__fixed2(){return true;}
		virtual bool end__array__fixed2(){return true;}
		virtual bool data__array__fixed2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed2( void* attributeData ){return begin__array__fixed2();}
		bool _data__array__fixed2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED3 = 224945219;
		virtual bool begin__array__fixed3(){return true;}
		virtual bool end__array__fixed3(){return true;}
		virtual bool data__array__fixed3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed3( void* attributeData ){return begin__array__fixed3();}
		bool _data__array__fixed3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED4 = 224945220;
		virtual bool begin__array__fixed4(){return true;}
		virtual bool end__array__fixed4(){return true;}
		virtual bool data__array__fixed4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed4( void* attributeData ){return begin__array__fixed4();}
		bool _data__array__fixed4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED1X1 = 140789201;
		virtual bool begin__array__fixed1x1(){return true;}
		virtual bool end__array__fixed1x1(){return true;}
		virtual bool data__array__fixed1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed1x1( void* attributeData ){return begin__array__fixed1x1();}
		bool _data__array__fixed1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED1X2 = 140789202;
		virtual bool begin__array__fixed1x2(){return true;}
		virtual bool end__array__fixed1x2(){return true;}
		virtual bool data__array__fixed1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed1x2( void* attributeData ){return begin__array__fixed1x2();}
		bool _data__array__fixed1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED1X3 = 140789203;
		virtual bool begin__array__fixed1x3(){return true;}
		virtual bool end__array__fixed1x3(){return true;}
		virtual bool data__array__fixed1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed1x3( void* attributeData ){return begin__array__fixed1x3();}
		bool _data__array__fixed1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED1X4 = 140789204;
		virtual bool begin__array__fixed1x4(){return true;}
		virtual bool end__array__fixed1x4(){return true;}
		virtual bool data__array__fixed1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed1x4( void* attributeData ){return begin__array__fixed1x4();}
		bool _data__array__fixed1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED2X1 = 140788945;
		virtual bool begin__array__fixed2x1(){return true;}
		virtual bool end__array__fixed2x1(){return true;}
		virtual bool data__array__fixed2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed2x1( void* attributeData ){return begin__array__fixed2x1();}
		bool _data__array__fixed2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED2X2 = 140788946;
		virtual bool begin__array__fixed2x2(){return true;}
		virtual bool end__array__fixed2x2(){return true;}
		virtual bool data__array__fixed2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed2x2( void* attributeData ){return begin__array__fixed2x2();}
		bool _data__array__fixed2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED2X3 = 140788947;
		virtual bool begin__array__fixed2x3(){return true;}
		virtual bool end__array__fixed2x3(){return true;}
		virtual bool data__array__fixed2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed2x3( void* attributeData ){return begin__array__fixed2x3();}
		bool _data__array__fixed2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED2X4 = 140788948;
		virtual bool begin__array__fixed2x4(){return true;}
		virtual bool end__array__fixed2x4(){return true;}
		virtual bool data__array__fixed2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed2x4( void* attributeData ){return begin__array__fixed2x4();}
		bool _data__array__fixed2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED3X1 = 140789713;
		virtual bool begin__array__fixed3x1(){return true;}
		virtual bool end__array__fixed3x1(){return true;}
		virtual bool data__array__fixed3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed3x1( void* attributeData ){return begin__array__fixed3x1();}
		bool _data__array__fixed3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED3X2 = 140789714;
		virtual bool begin__array__fixed3x2(){return true;}
		virtual bool end__array__fixed3x2(){return true;}
		virtual bool data__array__fixed3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed3x2( void* attributeData ){return begin__array__fixed3x2();}
		bool _data__array__fixed3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED3X3 = 140789715;
		virtual bool begin__array__fixed3x3(){return true;}
		virtual bool end__array__fixed3x3(){return true;}
		virtual bool data__array__fixed3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed3x3( void* attributeData ){return begin__array__fixed3x3();}
		bool _data__array__fixed3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED3X4 = 140789716;
		virtual bool begin__array__fixed3x4(){return true;}
		virtual bool end__array__fixed3x4(){return true;}
		virtual bool data__array__fixed3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed3x4( void* attributeData ){return begin__array__fixed3x4();}
		bool _data__array__fixed3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED4X1 = 140789457;
		virtual bool begin__array__fixed4x1(){return true;}
		virtual bool end__array__fixed4x1(){return true;}
		virtual bool data__array__fixed4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed4x1( void* attributeData ){return begin__array__fixed4x1();}
		bool _data__array__fixed4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x1();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED4X2 = 140789458;
		virtual bool begin__array__fixed4x2(){return true;}
		virtual bool end__array__fixed4x2(){return true;}
		virtual bool data__array__fixed4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed4x2( void* attributeData ){return begin__array__fixed4x2();}
		bool _data__array__fixed4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x2();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED4X3 = 140789459;
		virtual bool begin__array__fixed4x3(){return true;}
		virtual bool end__array__fixed4x3(){return true;}
		virtual bool data__array__fixed4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed4x3( void* attributeData ){return begin__array__fixed4x3();}
		bool _data__array__fixed4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x3();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__FIXED4X4 = 140789460;
		virtual bool begin__array__fixed4x4(){return true;}
		virtual bool end__array__fixed4x4(){return true;}
		virtual bool data__array__fixed4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__fixed4x4( void* attributeData ){return begin__array__fixed4x4();}
		bool _data__array__fixed4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x4();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__STRING = 238223735;
		virtual bool begin__array__string(){return true;}
		virtual bool end__array__string(){return true;}
		virtual bool data__array__string( const void* data, size_t length ){return true;}
	private:
		bool _begin__array__string( void* attributeData ){return begin__array__string();}
		bool _data__array__string( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__string();

	public:
		static const StringHash HASH_ELEMENT_ARRAY__USERTYPE = 21405237;
		struct array__usertype__AttributeData
		{
			static const array__usertype__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* source;
		};
		virtual bool begin__array__usertype( const array__usertype__AttributeData& attributeData ){return true;}
		virtual bool end__array__usertype(){return true;}
	private:
		bool _begin__array__usertype( void* attributeData ){return begin__array__usertype(*static_cast<array__usertype__AttributeData*>(attributeData));}
		bool _data__array__usertype( const ParserChar* text, size_t textLength );
		bool _validateBegin__array__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__usertype();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__USERTYPE = 242040677;
		struct usertype__usertype__AttributeData
		{
			static const usertype__usertype__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* source;
		};
		virtual bool begin__usertype__usertype( const usertype__usertype__AttributeData& attributeData ){return true;}
		virtual bool end__usertype__usertype(){return true;}
	private:
		bool _begin__usertype__usertype( void* attributeData ){return begin__usertype__usertype(*static_cast<usertype__usertype__AttributeData*>(attributeData));}
		bool _data__usertype__usertype( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__usertype();

	public:
		static const StringHash HASH_ELEMENT_CONNECT_PARAM = 67355581;
		static const StringHash HASH_ELEMENT_USERTYPE__CONNECT_PARAM = 5868045;
		struct usertype__connect_param__AttributeData
		{
			static const usertype__connect_param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__usertype__connect_param( const usertype__connect_param__AttributeData& attributeData ){return true;}
		virtual bool end__usertype__connect_param(){return true;}
	private:
		bool _begin__usertype__connect_param( void* attributeData ){return begin__usertype__connect_param(*static_cast<usertype__connect_param__AttributeData*>(attributeData));}
		bool _data__usertype__connect_param( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__connect_param();

	public:
		static const StringHash HASH_ELEMENT_USERTYPE__SETPARAM = 185734957;
		static const StringHash HASH_ATTRIBUTE_PROGRAM = 127264781;
		struct usertype__setparam__AttributeData
		{
			static const usertype__setparam__AttributeData DEFAULT;

			const ParserChar* ref;
			const ParserChar* program;
		};
		virtual bool begin__usertype__setparam( const usertype__setparam__AttributeData& attributeData ){return true;}
		virtual bool end__usertype__setparam(){return true;}
	private:
		bool _begin__usertype__setparam( void* attributeData ){return begin__usertype__setparam(*static_cast<usertype__setparam__AttributeData*>(attributeData));}
		bool _data__usertype__setparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__usertype__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__setparam();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL1 = 3302897;
		virtual bool begin__setparam__bool1(){return true;}
		virtual bool end__setparam__bool1(){return true;}
		virtual bool data__setparam__bool1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool1( void* attributeData ){return begin__setparam__bool1();}
		bool _data__setparam__bool1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL1X1 = 40237185;
		virtual bool begin__setparam__bool1x1(){return true;}
		virtual bool end__setparam__bool1x1(){return true;}
		virtual bool data__setparam__bool1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool1x1( void* attributeData ){return begin__setparam__bool1x1();}
		bool _data__setparam__bool1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL1X2 = 40237186;
		virtual bool begin__setparam__bool1x2(){return true;}
		virtual bool end__setparam__bool1x2(){return true;}
		virtual bool data__setparam__bool1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool1x2( void* attributeData ){return begin__setparam__bool1x2();}
		bool _data__setparam__bool1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL1X3 = 40237187;
		virtual bool begin__setparam__bool1x3(){return true;}
		virtual bool end__setparam__bool1x3(){return true;}
		virtual bool data__setparam__bool1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool1x3( void* attributeData ){return begin__setparam__bool1x3();}
		bool _data__setparam__bool1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL1X4 = 40237188;
		virtual bool begin__setparam__bool1x4(){return true;}
		virtual bool end__setparam__bool1x4(){return true;}
		virtual bool data__setparam__bool1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool1x4( void* attributeData ){return begin__setparam__bool1x4();}
		bool _data__setparam__bool1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL2X1 = 40237441;
		virtual bool begin__setparam__bool2x1(){return true;}
		virtual bool end__setparam__bool2x1(){return true;}
		virtual bool data__setparam__bool2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool2x1( void* attributeData ){return begin__setparam__bool2x1();}
		bool _data__setparam__bool2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL2X2 = 40237442;
		virtual bool begin__setparam__bool2x2(){return true;}
		virtual bool end__setparam__bool2x2(){return true;}
		virtual bool data__setparam__bool2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool2x2( void* attributeData ){return begin__setparam__bool2x2();}
		bool _data__setparam__bool2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL2X3 = 40237443;
		virtual bool begin__setparam__bool2x3(){return true;}
		virtual bool end__setparam__bool2x3(){return true;}
		virtual bool data__setparam__bool2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool2x3( void* attributeData ){return begin__setparam__bool2x3();}
		bool _data__setparam__bool2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL2X4 = 40237444;
		virtual bool begin__setparam__bool2x4(){return true;}
		virtual bool end__setparam__bool2x4(){return true;}
		virtual bool data__setparam__bool2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool2x4( void* attributeData ){return begin__setparam__bool2x4();}
		bool _data__setparam__bool2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL3X1 = 40237697;
		virtual bool begin__setparam__bool3x1(){return true;}
		virtual bool end__setparam__bool3x1(){return true;}
		virtual bool data__setparam__bool3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool3x1( void* attributeData ){return begin__setparam__bool3x1();}
		bool _data__setparam__bool3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL3X2 = 40237698;
		virtual bool begin__setparam__bool3x2(){return true;}
		virtual bool end__setparam__bool3x2(){return true;}
		virtual bool data__setparam__bool3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool3x2( void* attributeData ){return begin__setparam__bool3x2();}
		bool _data__setparam__bool3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL3X3 = 40237699;
		virtual bool begin__setparam__bool3x3(){return true;}
		virtual bool end__setparam__bool3x3(){return true;}
		virtual bool data__setparam__bool3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool3x3( void* attributeData ){return begin__setparam__bool3x3();}
		bool _data__setparam__bool3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL3X4 = 40237700;
		virtual bool begin__setparam__bool3x4(){return true;}
		virtual bool end__setparam__bool3x4(){return true;}
		virtual bool data__setparam__bool3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool3x4( void* attributeData ){return begin__setparam__bool3x4();}
		bool _data__setparam__bool3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL4X1 = 40237953;
		virtual bool begin__setparam__bool4x1(){return true;}
		virtual bool end__setparam__bool4x1(){return true;}
		virtual bool data__setparam__bool4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool4x1( void* attributeData ){return begin__setparam__bool4x1();}
		bool _data__setparam__bool4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL4X2 = 40237954;
		virtual bool begin__setparam__bool4x2(){return true;}
		virtual bool end__setparam__bool4x2(){return true;}
		virtual bool data__setparam__bool4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool4x2( void* attributeData ){return begin__setparam__bool4x2();}
		bool _data__setparam__bool4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL4X3 = 40237955;
		virtual bool begin__setparam__bool4x3(){return true;}
		virtual bool end__setparam__bool4x3(){return true;}
		virtual bool data__setparam__bool4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool4x3( void* attributeData ){return begin__setparam__bool4x3();}
		bool _data__setparam__bool4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__BOOL4X4 = 40237956;
		virtual bool begin__setparam__bool4x4(){return true;}
		virtual bool end__setparam__bool4x4(){return true;}
		virtual bool data__setparam__bool4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__bool4x4( void* attributeData ){return begin__setparam__bool4x4();}
		bool _data__setparam__bool4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FLOAT1 = 56842353;
		virtual bool begin__setparam__float1(){return true;}
		virtual bool end__setparam__float1(){return true;}
		virtual bool data__setparam__float1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__float1( void* attributeData ){return begin__setparam__float1();}
		bool _data__setparam__float1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT1 = 226673;
		virtual bool begin__setparam__int1(){return true;}
		virtual bool end__setparam__int1(){return true;}
		virtual bool data__setparam__int1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int1( void* attributeData ){return begin__setparam__int1();}
		bool _data__setparam__int1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT1X1 = 58030257;
		virtual bool begin__setparam__int1x1(){return true;}
		virtual bool end__setparam__int1x1(){return true;}
		virtual bool data__setparam__int1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int1x1( void* attributeData ){return begin__setparam__int1x1();}
		bool _data__setparam__int1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT1X2 = 58030258;
		virtual bool begin__setparam__int1x2(){return true;}
		virtual bool end__setparam__int1x2(){return true;}
		virtual bool data__setparam__int1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int1x2( void* attributeData ){return begin__setparam__int1x2();}
		bool _data__setparam__int1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT1X3 = 58030259;
		virtual bool begin__setparam__int1x3(){return true;}
		virtual bool end__setparam__int1x3(){return true;}
		virtual bool data__setparam__int1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int1x3( void* attributeData ){return begin__setparam__int1x3();}
		bool _data__setparam__int1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT1X4 = 58030260;
		virtual bool begin__setparam__int1x4(){return true;}
		virtual bool end__setparam__int1x4(){return true;}
		virtual bool data__setparam__int1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int1x4( void* attributeData ){return begin__setparam__int1x4();}
		bool _data__setparam__int1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT2X1 = 58030513;
		virtual bool begin__setparam__int2x1(){return true;}
		virtual bool end__setparam__int2x1(){return true;}
		virtual bool data__setparam__int2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int2x1( void* attributeData ){return begin__setparam__int2x1();}
		bool _data__setparam__int2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT2X2 = 58030514;
		virtual bool begin__setparam__int2x2(){return true;}
		virtual bool end__setparam__int2x2(){return true;}
		virtual bool data__setparam__int2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int2x2( void* attributeData ){return begin__setparam__int2x2();}
		bool _data__setparam__int2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT2X3 = 58030515;
		virtual bool begin__setparam__int2x3(){return true;}
		virtual bool end__setparam__int2x3(){return true;}
		virtual bool data__setparam__int2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int2x3( void* attributeData ){return begin__setparam__int2x3();}
		bool _data__setparam__int2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT2X4 = 58030516;
		virtual bool begin__setparam__int2x4(){return true;}
		virtual bool end__setparam__int2x4(){return true;}
		virtual bool data__setparam__int2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int2x4( void* attributeData ){return begin__setparam__int2x4();}
		bool _data__setparam__int2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT3X1 = 58030769;
		virtual bool begin__setparam__int3x1(){return true;}
		virtual bool end__setparam__int3x1(){return true;}
		virtual bool data__setparam__int3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int3x1( void* attributeData ){return begin__setparam__int3x1();}
		bool _data__setparam__int3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT3X2 = 58030770;
		virtual bool begin__setparam__int3x2(){return true;}
		virtual bool end__setparam__int3x2(){return true;}
		virtual bool data__setparam__int3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int3x2( void* attributeData ){return begin__setparam__int3x2();}
		bool _data__setparam__int3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT3X3 = 58030771;
		virtual bool begin__setparam__int3x3(){return true;}
		virtual bool end__setparam__int3x3(){return true;}
		virtual bool data__setparam__int3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int3x3( void* attributeData ){return begin__setparam__int3x3();}
		bool _data__setparam__int3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT3X4 = 58030772;
		virtual bool begin__setparam__int3x4(){return true;}
		virtual bool end__setparam__int3x4(){return true;}
		virtual bool data__setparam__int3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int3x4( void* attributeData ){return begin__setparam__int3x4();}
		bool _data__setparam__int3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT4X1 = 58031025;
		virtual bool begin__setparam__int4x1(){return true;}
		virtual bool end__setparam__int4x1(){return true;}
		virtual bool data__setparam__int4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int4x1( void* attributeData ){return begin__setparam__int4x1();}
		bool _data__setparam__int4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT4X2 = 58031026;
		virtual bool begin__setparam__int4x2(){return true;}
		virtual bool end__setparam__int4x2(){return true;}
		virtual bool data__setparam__int4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int4x2( void* attributeData ){return begin__setparam__int4x2();}
		bool _data__setparam__int4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT4X3 = 58031027;
		virtual bool begin__setparam__int4x3(){return true;}
		virtual bool end__setparam__int4x3(){return true;}
		virtual bool data__setparam__int4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int4x3( void* attributeData ){return begin__setparam__int4x3();}
		bool _data__setparam__int4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__INT4X4 = 58031028;
		virtual bool begin__setparam__int4x4(){return true;}
		virtual bool end__setparam__int4x4(){return true;}
		virtual bool data__setparam__int4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__int4x4( void* attributeData ){return begin__setparam__int4x4();}
		bool _data__setparam__int4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF = 227366;
		virtual bool begin__setparam__half(){return true;}
		virtual bool end__setparam__half(){return true;}
		virtual bool data__setparam__half( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half( void* attributeData ){return begin__setparam__half();}
		bool _data__setparam__half( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF1 = 3637905;
		virtual bool begin__setparam__half1(){return true;}
		virtual bool end__setparam__half1(){return true;}
		virtual bool data__setparam__half1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half1( void* attributeData ){return begin__setparam__half1();}
		bool _data__setparam__half1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF2 = 3637906;
		virtual bool begin__setparam__half2(){return true;}
		virtual bool end__setparam__half2(){return true;}
		virtual bool data__setparam__half2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half2( void* attributeData ){return begin__setparam__half2();}
		bool _data__setparam__half2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF3 = 3637907;
		virtual bool begin__setparam__half3(){return true;}
		virtual bool end__setparam__half3(){return true;}
		virtual bool data__setparam__half3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half3( void* attributeData ){return begin__setparam__half3();}
		bool _data__setparam__half3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF4 = 3637908;
		virtual bool begin__setparam__half4(){return true;}
		virtual bool end__setparam__half4(){return true;}
		virtual bool data__setparam__half4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half4( void* attributeData ){return begin__setparam__half4();}
		bool _data__setparam__half4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF1X1 = 125999233;
		virtual bool begin__setparam__half1x1(){return true;}
		virtual bool end__setparam__half1x1(){return true;}
		virtual bool data__setparam__half1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half1x1( void* attributeData ){return begin__setparam__half1x1();}
		bool _data__setparam__half1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF1X2 = 125999234;
		virtual bool begin__setparam__half1x2(){return true;}
		virtual bool end__setparam__half1x2(){return true;}
		virtual bool data__setparam__half1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half1x2( void* attributeData ){return begin__setparam__half1x2();}
		bool _data__setparam__half1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF1X3 = 125999235;
		virtual bool begin__setparam__half1x3(){return true;}
		virtual bool end__setparam__half1x3(){return true;}
		virtual bool data__setparam__half1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half1x3( void* attributeData ){return begin__setparam__half1x3();}
		bool _data__setparam__half1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF1X4 = 125999236;
		virtual bool begin__setparam__half1x4(){return true;}
		virtual bool end__setparam__half1x4(){return true;}
		virtual bool data__setparam__half1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half1x4( void* attributeData ){return begin__setparam__half1x4();}
		bool _data__setparam__half1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF2X1 = 125999489;
		virtual bool begin__setparam__half2x1(){return true;}
		virtual bool end__setparam__half2x1(){return true;}
		virtual bool data__setparam__half2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half2x1( void* attributeData ){return begin__setparam__half2x1();}
		bool _data__setparam__half2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF2X2 = 125999490;
		virtual bool begin__setparam__half2x2(){return true;}
		virtual bool end__setparam__half2x2(){return true;}
		virtual bool data__setparam__half2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half2x2( void* attributeData ){return begin__setparam__half2x2();}
		bool _data__setparam__half2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF2X3 = 125999491;
		virtual bool begin__setparam__half2x3(){return true;}
		virtual bool end__setparam__half2x3(){return true;}
		virtual bool data__setparam__half2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half2x3( void* attributeData ){return begin__setparam__half2x3();}
		bool _data__setparam__half2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF2X4 = 125999492;
		virtual bool begin__setparam__half2x4(){return true;}
		virtual bool end__setparam__half2x4(){return true;}
		virtual bool data__setparam__half2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half2x4( void* attributeData ){return begin__setparam__half2x4();}
		bool _data__setparam__half2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF3X1 = 125999745;
		virtual bool begin__setparam__half3x1(){return true;}
		virtual bool end__setparam__half3x1(){return true;}
		virtual bool data__setparam__half3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half3x1( void* attributeData ){return begin__setparam__half3x1();}
		bool _data__setparam__half3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF3X2 = 125999746;
		virtual bool begin__setparam__half3x2(){return true;}
		virtual bool end__setparam__half3x2(){return true;}
		virtual bool data__setparam__half3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half3x2( void* attributeData ){return begin__setparam__half3x2();}
		bool _data__setparam__half3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF3X3 = 125999747;
		virtual bool begin__setparam__half3x3(){return true;}
		virtual bool end__setparam__half3x3(){return true;}
		virtual bool data__setparam__half3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half3x3( void* attributeData ){return begin__setparam__half3x3();}
		bool _data__setparam__half3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF3X4 = 125999748;
		virtual bool begin__setparam__half3x4(){return true;}
		virtual bool end__setparam__half3x4(){return true;}
		virtual bool data__setparam__half3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half3x4( void* attributeData ){return begin__setparam__half3x4();}
		bool _data__setparam__half3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF4X1 = 126000001;
		virtual bool begin__setparam__half4x1(){return true;}
		virtual bool end__setparam__half4x1(){return true;}
		virtual bool data__setparam__half4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half4x1( void* attributeData ){return begin__setparam__half4x1();}
		bool _data__setparam__half4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF4X2 = 126000002;
		virtual bool begin__setparam__half4x2(){return true;}
		virtual bool end__setparam__half4x2(){return true;}
		virtual bool data__setparam__half4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half4x2( void* attributeData ){return begin__setparam__half4x2();}
		bool _data__setparam__half4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF4X3 = 126000003;
		virtual bool begin__setparam__half4x3(){return true;}
		virtual bool end__setparam__half4x3(){return true;}
		virtual bool data__setparam__half4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half4x3( void* attributeData ){return begin__setparam__half4x3();}
		bool _data__setparam__half4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__HALF4X4 = 126000004;
		virtual bool begin__setparam__half4x4(){return true;}
		virtual bool end__setparam__half4x4(){return true;}
		virtual bool data__setparam__half4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__half4x4( void* attributeData ){return begin__setparam__half4x4();}
		bool _data__setparam__half4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED = 3542708;
		virtual bool begin__setparam__fixed(){return true;}
		virtual bool end__setparam__fixed(){return true;}
		virtual bool data__setparam__fixed( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed( void* attributeData ){return begin__setparam__fixed();}
		bool _data__setparam__fixed( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED1 = 56683377;
		virtual bool begin__setparam__fixed1(){return true;}
		virtual bool end__setparam__fixed1(){return true;}
		virtual bool data__setparam__fixed1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed1( void* attributeData ){return begin__setparam__fixed1();}
		bool _data__setparam__fixed1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED2 = 56683378;
		virtual bool begin__setparam__fixed2(){return true;}
		virtual bool end__setparam__fixed2(){return true;}
		virtual bool data__setparam__fixed2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed2( void* attributeData ){return begin__setparam__fixed2();}
		bool _data__setparam__fixed2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED3 = 56683379;
		virtual bool begin__setparam__fixed3(){return true;}
		virtual bool end__setparam__fixed3(){return true;}
		virtual bool data__setparam__fixed3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed3( void* attributeData ){return begin__setparam__fixed3();}
		bool _data__setparam__fixed3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED4 = 56683380;
		virtual bool begin__setparam__fixed4(){return true;}
		virtual bool end__setparam__fixed4(){return true;}
		virtual bool data__setparam__fixed4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed4( void* attributeData ){return begin__setparam__fixed4();}
		bool _data__setparam__fixed4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED1X1 = 15432657;
		virtual bool begin__setparam__fixed1x1(){return true;}
		virtual bool end__setparam__fixed1x1(){return true;}
		virtual bool data__setparam__fixed1x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed1x1( void* attributeData ){return begin__setparam__fixed1x1();}
		bool _data__setparam__fixed1x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED1X2 = 15432658;
		virtual bool begin__setparam__fixed1x2(){return true;}
		virtual bool end__setparam__fixed1x2(){return true;}
		virtual bool data__setparam__fixed1x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed1x2( void* attributeData ){return begin__setparam__fixed1x2();}
		bool _data__setparam__fixed1x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED1X3 = 15432659;
		virtual bool begin__setparam__fixed1x3(){return true;}
		virtual bool end__setparam__fixed1x3(){return true;}
		virtual bool data__setparam__fixed1x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed1x3( void* attributeData ){return begin__setparam__fixed1x3();}
		bool _data__setparam__fixed1x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED1X4 = 15432660;
		virtual bool begin__setparam__fixed1x4(){return true;}
		virtual bool end__setparam__fixed1x4(){return true;}
		virtual bool data__setparam__fixed1x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed1x4( void* attributeData ){return begin__setparam__fixed1x4();}
		bool _data__setparam__fixed1x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED2X1 = 15432401;
		virtual bool begin__setparam__fixed2x1(){return true;}
		virtual bool end__setparam__fixed2x1(){return true;}
		virtual bool data__setparam__fixed2x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed2x1( void* attributeData ){return begin__setparam__fixed2x1();}
		bool _data__setparam__fixed2x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED2X2 = 15432402;
		virtual bool begin__setparam__fixed2x2(){return true;}
		virtual bool end__setparam__fixed2x2(){return true;}
		virtual bool data__setparam__fixed2x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed2x2( void* attributeData ){return begin__setparam__fixed2x2();}
		bool _data__setparam__fixed2x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED2X3 = 15432403;
		virtual bool begin__setparam__fixed2x3(){return true;}
		virtual bool end__setparam__fixed2x3(){return true;}
		virtual bool data__setparam__fixed2x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed2x3( void* attributeData ){return begin__setparam__fixed2x3();}
		bool _data__setparam__fixed2x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED2X4 = 15432404;
		virtual bool begin__setparam__fixed2x4(){return true;}
		virtual bool end__setparam__fixed2x4(){return true;}
		virtual bool data__setparam__fixed2x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed2x4( void* attributeData ){return begin__setparam__fixed2x4();}
		bool _data__setparam__fixed2x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED3X1 = 15432145;
		virtual bool begin__setparam__fixed3x1(){return true;}
		virtual bool end__setparam__fixed3x1(){return true;}
		virtual bool data__setparam__fixed3x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed3x1( void* attributeData ){return begin__setparam__fixed3x1();}
		bool _data__setparam__fixed3x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED3X2 = 15432146;
		virtual bool begin__setparam__fixed3x2(){return true;}
		virtual bool end__setparam__fixed3x2(){return true;}
		virtual bool data__setparam__fixed3x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed3x2( void* attributeData ){return begin__setparam__fixed3x2();}
		bool _data__setparam__fixed3x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED3X3 = 15432147;
		virtual bool begin__setparam__fixed3x3(){return true;}
		virtual bool end__setparam__fixed3x3(){return true;}
		virtual bool data__setparam__fixed3x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed3x3( void* attributeData ){return begin__setparam__fixed3x3();}
		bool _data__setparam__fixed3x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED3X4 = 15432148;
		virtual bool begin__setparam__fixed3x4(){return true;}
		virtual bool end__setparam__fixed3x4(){return true;}
		virtual bool data__setparam__fixed3x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed3x4( void* attributeData ){return begin__setparam__fixed3x4();}
		bool _data__setparam__fixed3x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED4X1 = 15431889;
		virtual bool begin__setparam__fixed4x1(){return true;}
		virtual bool end__setparam__fixed4x1(){return true;}
		virtual bool data__setparam__fixed4x1( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed4x1( void* attributeData ){return begin__setparam__fixed4x1();}
		bool _data__setparam__fixed4x1( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x1();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED4X2 = 15431890;
		virtual bool begin__setparam__fixed4x2(){return true;}
		virtual bool end__setparam__fixed4x2(){return true;}
		virtual bool data__setparam__fixed4x2( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed4x2( void* attributeData ){return begin__setparam__fixed4x2();}
		bool _data__setparam__fixed4x2( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x2();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED4X3 = 15431891;
		virtual bool begin__setparam__fixed4x3(){return true;}
		virtual bool end__setparam__fixed4x3(){return true;}
		virtual bool data__setparam__fixed4x3( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed4x3( void* attributeData ){return begin__setparam__fixed4x3();}
		bool _data__setparam__fixed4x3( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x3();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__FIXED4X4 = 15431892;
		virtual bool begin__setparam__fixed4x4(){return true;}
		virtual bool end__setparam__fixed4x4(){return true;}
		virtual bool data__setparam__fixed4x4( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__fixed4x4( void* attributeData ){return begin__setparam__fixed4x4();}
		bool _data__setparam__fixed4x4( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x4();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__STRING = 3903559;
		virtual bool begin__setparam__string(){return true;}
		virtual bool end__setparam__string(){return true;}
		virtual bool data__setparam__string( const void* data, size_t length ){return true;}
	private:
		bool _begin__setparam__string( void* attributeData ){return begin__setparam__string();}
		bool _data__setparam__string( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__string();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__USERTYPE = 164216885;
		struct setparam__usertype__AttributeData
		{
			static const setparam__usertype__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* source;
		};
		virtual bool begin__setparam__usertype( const setparam__usertype__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__usertype(){return true;}
	private:
		bool _begin__setparam__usertype( void* attributeData ){return begin__setparam__usertype(*static_cast<setparam__usertype__AttributeData*>(attributeData));}
		bool _data__setparam__usertype( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__usertype();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__ARRAY = 3250313;
		struct setparam__array__AttributeData
		{
			static const setparam__array__AttributeData DEFAULT;

			long length;
		};
		virtual bool begin__setparam__array( const setparam__array__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__array(){return true;}
	private:
		bool _begin__setparam__array( void* attributeData ){return begin__setparam__array(*static_cast<setparam__array__AttributeData*>(attributeData));}
		bool _data__setparam__array( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__array();

	public:
		static const StringHash HASH_ELEMENT_SETPARAM__CONNECT_PARAM = 151241709;
		struct setparam__connect_param__AttributeData
		{
			static const setparam__connect_param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__setparam__connect_param( const setparam__connect_param__AttributeData& attributeData ){return true;}
		virtual bool end__setparam__connect_param(){return true;}
	private:
		bool _begin__setparam__connect_param( void* attributeData ){return begin__setparam__connect_param(*static_cast<setparam__connect_param__AttributeData*>(attributeData));}
		bool _data__setparam__connect_param( const ParserChar* text, size_t textLength );
		bool _validateBegin__setparam__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__connect_param();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE = 198327461;
		struct profile_CG__technique__AttributeData
		{
			static const profile_CG__technique__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* sid;
		};
		virtual bool begin__profile_CG__technique( const profile_CG__technique__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG__technique(){return true;}
	private:
		bool _begin__profile_CG__technique( void* attributeData ){return begin__profile_CG__technique(*static_cast<profile_CG__technique__AttributeData*>(attributeData));}
		bool _data__profile_CG__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__technique();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_CG__EXTRA = 84040097;
		struct profile_CG__extra__AttributeData
		{
			static const profile_CG__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__profile_CG__extra( const profile_CG__extra__AttributeData& attributeData ){return true;}
		virtual bool end__profile_CG__extra(){return true;}
	private:
		bool _begin__profile_CG__extra( void* attributeData ){return begin__profile_CG__extra(*static_cast<profile_CG__extra__AttributeData*>(attributeData));}
		bool _data__profile_CG__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_CG__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__extra();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_COMMON = 171910622;
		struct profile_COMMON__AttributeData
		{
			static const profile_COMMON__AttributeData DEFAULT;

			const ParserChar* id;
		};
		virtual bool begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData ){return true;}
		virtual bool end__profile_COMMON(){return true;}
	private:
		bool _begin__profile_COMMON( void* attributeData ){return begin__profile_COMMON(*static_cast<profile_COMMON__AttributeData*>(attributeData));}
		bool _data__profile_COMMON( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_COMMON( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_COMMON__ASSET = 145422180;
		virtual bool begin__profile_COMMON__asset(){return true;}
		virtual bool end__profile_COMMON__asset(){return true;}
	private:
		bool _begin__profile_COMMON__asset( void* attributeData ){return begin__profile_COMMON__asset();}
		bool _data__profile_COMMON__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_COMMON__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__asset();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_COMMON__IMAGE = 145647989;
		struct profile_COMMON__image__AttributeData
		{
			static const profile_COMMON__image__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* format;
			const ParserChar* height;
			const ParserChar* width;
			const ParserChar* depth;
		};
		virtual bool begin__profile_COMMON__image( const profile_COMMON__image__AttributeData& attributeData ){return true;}
		virtual bool end__profile_COMMON__image(){return true;}
	private:
		bool _begin__profile_COMMON__image( void* attributeData ){return begin__profile_COMMON__image(*static_cast<profile_COMMON__image__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__image( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_COMMON__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__image();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_COMMON__NEWPARAM = 151782173;
		struct profile_COMMON__newparam__AttributeData
		{
			static const profile_COMMON__newparam__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__profile_COMMON__newparam( const profile_COMMON__newparam__AttributeData& attributeData ){return true;}
		virtual bool end__profile_COMMON__newparam(){return true;}
	private:
		bool _begin__profile_COMMON__newparam( void* attributeData ){return begin__profile_COMMON__newparam(*static_cast<profile_COMMON__newparam__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__newparam( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_COMMON__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__newparam();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_COMMON__TECHNIQUE = 123572309;
		struct profile_COMMON__technique__AttributeData
		{
			static const profile_COMMON__technique__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* sid;
		};
		virtual bool begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData ){return true;}
		virtual bool end__profile_COMMON__technique(){return true;}
	private:
		bool _begin__profile_COMMON__technique( void* attributeData ){return begin__profile_COMMON__technique(*static_cast<profile_COMMON__technique__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__technique( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_COMMON__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__technique();

	public:
		static const StringHash HASH_ELEMENT_TECHNIQUE__CONSTANT = 140404900;
		virtual bool begin__technique__constant(){return true;}
		virtual bool end__technique__constant(){return true;}
	private:
		bool _begin__technique__constant( void* attributeData ){return begin__technique__constant();}
		bool _data__technique__constant( const ParserChar* text, size_t textLength );
		bool _validateBegin__technique__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__constant();

	public:
		static const StringHash HASH_ELEMENT_EMISSION = 67803806;
		static const StringHash HASH_ELEMENT_CONSTANT__EMISSION = 17478014;
		virtual bool begin__constant__emission(){return true;}
		virtual bool end__constant__emission(){return true;}
	private:
		bool _begin__constant__emission( void* attributeData ){return begin__constant__emission();}
		bool _data__constant__emission( const ParserChar* text, size_t textLength );
		bool _validateBegin__constant__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__emission();

	public:
		static const StringHash HASH_ELEMENT_EMISSION__COLOR = 99748322;
		struct emission__color__AttributeData
		{
			static const emission__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__emission__color( const emission__color__AttributeData& attributeData ){return true;}
		virtual bool end__emission__color(){return true;}
		virtual bool data__emission__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__emission__color( void* attributeData ){return begin__emission__color(*static_cast<emission__color__AttributeData*>(attributeData));}
		bool _data__emission__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__emission__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__emission__color();

	public:
		static const StringHash HASH_ELEMENT_EMISSION__PARAM = 97460989;
		struct emission__param__AttributeData
		{
			static const emission__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__emission__param( const emission__param__AttributeData& attributeData ){return true;}
		virtual bool end__emission__param(){return true;}
	private:
		bool _begin__emission__param( void* attributeData ){return begin__emission__param(*static_cast<emission__param__AttributeData*>(attributeData));}
		bool _data__emission__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__emission__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__emission__param();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE = 181386485;
		static const StringHash HASH_ELEMENT_EMISSION__TEXTURE = 56965445;
		static const StringHash HASH_ATTRIBUTE_TEXTURE = 181386485;
		static const StringHash HASH_ATTRIBUTE_TEXCOORD = 216686884;
		struct emission__texture__AttributeData
		{
			static const emission__texture__AttributeData DEFAULT;

			const ParserChar* texture;
			const ParserChar* texcoord;
		};
		virtual bool begin__emission__texture( const emission__texture__AttributeData& attributeData ){return true;}
		virtual bool end__emission__texture(){return true;}
	private:
		bool _begin__emission__texture( void* attributeData ){return begin__emission__texture(*static_cast<emission__texture__AttributeData*>(attributeData));}
		bool _data__emission__texture( const ParserChar* text, size_t textLength );
		bool _validateBegin__emission__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__emission__texture();

	public:
		static const StringHash HASH_ELEMENT_TEXTURE__EXTRA = 161952913;
		struct texture__extra__AttributeData
		{
			static const texture__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__texture__extra( const texture__extra__AttributeData& attributeData ){return true;}
		virtual bool end__texture__extra(){return true;}
	private:
		bool _begin__texture__extra( void* attributeData ){return begin__texture__extra(*static_cast<texture__extra__AttributeData*>(attributeData));}
		bool _data__texture__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__texture__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture__extra();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVE = 45955861;
		static const StringHash HASH_ELEMENT_CONSTANT__REFLECTIVE = 43423765;
		virtual bool begin__constant__reflective(){return true;}
		virtual bool end__constant__reflective(){return true;}
	private:
		bool _begin__constant__reflective( void* attributeData ){return begin__constant__reflective();}
		bool _data__constant__reflective( const ParserChar* text, size_t textLength );
		bool _validateBegin__constant__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__reflective();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVE__COLOR = 9172162;
		struct reflective__color__AttributeData
		{
			static const reflective__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__reflective__color( const reflective__color__AttributeData& attributeData ){return true;}
		virtual bool end__reflective__color(){return true;}
		virtual bool data__reflective__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__reflective__color( void* attributeData ){return begin__reflective__color(*static_cast<reflective__color__AttributeData*>(attributeData));}
		bool _data__reflective__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__reflective__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflective__color();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVE__PARAM = 11876829;
		struct reflective__param__AttributeData
		{
			static const reflective__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__reflective__param( const reflective__param__AttributeData& attributeData ){return true;}
		virtual bool end__reflective__param(){return true;}
	private:
		bool _begin__reflective__param( void* attributeData ){return begin__reflective__param(*static_cast<reflective__param__AttributeData*>(attributeData));}
		bool _data__reflective__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__reflective__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflective__param();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVE__TEXTURE = 159259701;
		struct reflective__texture__AttributeData
		{
			static const reflective__texture__AttributeData DEFAULT;

			const ParserChar* texture;
			const ParserChar* texcoord;
		};
		virtual bool begin__reflective__texture( const reflective__texture__AttributeData& attributeData ){return true;}
		virtual bool end__reflective__texture(){return true;}
	private:
		bool _begin__reflective__texture( void* attributeData ){return begin__reflective__texture(*static_cast<reflective__texture__AttributeData*>(attributeData));}
		bool _data__reflective__texture( const ParserChar* text, size_t textLength );
		bool _validateBegin__reflective__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflective__texture();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVITY = 221979145;
		static const StringHash HASH_ELEMENT_CONSTANT__REFLECTIVITY = 110633513;
		virtual bool begin__constant__reflectivity(){return true;}
		virtual bool end__constant__reflectivity(){return true;}
	private:
		bool _begin__constant__reflectivity( void* attributeData ){return begin__constant__reflectivity();}
		bool _data__constant__reflectivity( const ParserChar* text, size_t textLength );
		bool _validateBegin__constant__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__reflectivity();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVITY__FLOAT = 149886404;
		struct reflectivity__float__AttributeData
		{
			static const reflectivity__float__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__reflectivity__float( const reflectivity__float__AttributeData& attributeData ){return true;}
		virtual bool end__reflectivity__float(){return true;}
		virtual bool data__reflectivity__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__reflectivity__float( void* attributeData ){return begin__reflectivity__float(*static_cast<reflectivity__float__AttributeData*>(attributeData));}
		bool _data__reflectivity__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__reflectivity__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflectivity__float();

	public:
		static const StringHash HASH_ELEMENT_REFLECTIVITY__PARAM = 148154429;
		struct reflectivity__param__AttributeData
		{
			static const reflectivity__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__reflectivity__param( const reflectivity__param__AttributeData& attributeData ){return true;}
		virtual bool end__reflectivity__param(){return true;}
	private:
		bool _begin__reflectivity__param( void* attributeData ){return begin__reflectivity__param(*static_cast<reflectivity__param__AttributeData*>(attributeData));}
		bool _data__reflectivity__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__reflectivity__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflectivity__param();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENT = 169018372;
		static const StringHash HASH_ELEMENT_CONSTANT__TRANSPARENT = 145306628;
		static const StringHash HASH_ATTRIBUTE_OPAQUE = 124160181;
		struct constant__transparent__AttributeData
		{
			static const constant__transparent__AttributeData DEFAULT;

			const ParserChar* opaque;
		};
		virtual bool begin__constant__transparent( const constant__transparent__AttributeData& attributeData ){return true;}
		virtual bool end__constant__transparent(){return true;}
	private:
		bool _begin__constant__transparent( void* attributeData ){return begin__constant__transparent(*static_cast<constant__transparent__AttributeData*>(attributeData));}
		bool _data__constant__transparent( const ParserChar* text, size_t textLength );
		bool _validateBegin__constant__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__transparent();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENT__COLOR = 107619106;
		struct transparent__color__AttributeData
		{
			static const transparent__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__transparent__color( const transparent__color__AttributeData& attributeData ){return true;}
		virtual bool end__transparent__color(){return true;}
		virtual bool data__transparent__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__transparent__color( void* attributeData ){return begin__transparent__color(*static_cast<transparent__color__AttributeData*>(attributeData));}
		bool _data__transparent__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__transparent__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparent__color();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENT__PARAM = 106350653;
		struct transparent__param__AttributeData
		{
			static const transparent__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__transparent__param( const transparent__param__AttributeData& attributeData ){return true;}
		virtual bool end__transparent__param(){return true;}
	private:
		bool _begin__transparent__param( void* attributeData ){return begin__transparent__param(*static_cast<transparent__param__AttributeData*>(attributeData));}
		bool _data__transparent__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__transparent__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparent__param();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENT__TEXTURE = 177208021;
		struct transparent__texture__AttributeData
		{
			static const transparent__texture__AttributeData DEFAULT;

			const ParserChar* texture;
			const ParserChar* texcoord;
		};
		virtual bool begin__transparent__texture( const transparent__texture__AttributeData& attributeData ){return true;}
		virtual bool end__transparent__texture(){return true;}
	private:
		bool _begin__transparent__texture( void* attributeData ){return begin__transparent__texture(*static_cast<transparent__texture__AttributeData*>(attributeData));}
		bool _data__transparent__texture( const ParserChar* text, size_t textLength );
		bool _validateBegin__transparent__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparent__texture();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENCY = 19939593;
		static const StringHash HASH_ELEMENT_CONSTANT__TRANSPARENCY = 177422633;
		virtual bool begin__constant__transparency(){return true;}
		virtual bool end__constant__transparency(){return true;}
	private:
		bool _begin__constant__transparency( void* attributeData ){return begin__constant__transparency();}
		bool _data__constant__transparency( const ParserChar* text, size_t textLength );
		bool _validateBegin__constant__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__transparency();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENCY__FLOAT = 140067972;
		struct transparency__float__AttributeData
		{
			static const transparency__float__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__transparency__float( const transparency__float__AttributeData& attributeData ){return true;}
		virtual bool end__transparency__float(){return true;}
		virtual bool data__transparency__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__transparency__float( void* attributeData ){return begin__transparency__float(*static_cast<transparency__float__AttributeData*>(attributeData));}
		bool _data__transparency__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__transparency__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparency__float();

	public:
		static const StringHash HASH_ELEMENT_TRANSPARENCY__PARAM = 140679549;
		struct transparency__param__AttributeData
		{
			static const transparency__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__transparency__param( const transparency__param__AttributeData& attributeData ){return true;}
		virtual bool end__transparency__param(){return true;}
	private:
		bool _begin__transparency__param( void* attributeData ){return begin__transparency__param(*static_cast<transparency__param__AttributeData*>(attributeData));}
		bool _data__transparency__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__transparency__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparency__param();

	public:
		static const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION = 242674622;
		static const StringHash HASH_ELEMENT_CONSTANT__INDEX_OF_REFRACTION = 195491134;
		virtual bool begin__constant__index_of_refraction(){return true;}
		virtual bool end__constant__index_of_refraction(){return true;}
	private:
		bool _begin__constant__index_of_refraction( void* attributeData ){return begin__constant__index_of_refraction();}
		bool _data__constant__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _validateBegin__constant__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__index_of_refraction();

	public:
		static const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION__FLOAT = 70494564;
		struct index_of_refraction__float__AttributeData
		{
			static const index_of_refraction__float__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__index_of_refraction__float( const index_of_refraction__float__AttributeData& attributeData ){return true;}
		virtual bool end__index_of_refraction__float(){return true;}
		virtual bool data__index_of_refraction__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__index_of_refraction__float( void* attributeData ){return begin__index_of_refraction__float(*static_cast<index_of_refraction__float__AttributeData*>(attributeData));}
		bool _data__index_of_refraction__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__index_of_refraction__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__index_of_refraction__float();

	public:
		static const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION__PARAM = 67646621;
		struct index_of_refraction__param__AttributeData
		{
			static const index_of_refraction__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__index_of_refraction__param( const index_of_refraction__param__AttributeData& attributeData ){return true;}
		virtual bool end__index_of_refraction__param(){return true;}
	private:
		bool _begin__index_of_refraction__param( void* attributeData ){return begin__index_of_refraction__param(*static_cast<index_of_refraction__param__AttributeData*>(attributeData));}
		bool _data__index_of_refraction__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__index_of_refraction__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__index_of_refraction__param();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT = 42175716;
		static const StringHash HASH_ELEMENT_TECHNIQUE__LAMBERT = 90423428;
		virtual bool begin__lambert(){return true;}
		virtual bool end__lambert(){return true;}
	private:
		bool _begin__lambert( void* attributeData ){return begin__lambert();}
		bool _data__lambert( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__EMISSION = 15092238;
		virtual bool begin__lambert__emission(){return true;}
		virtual bool end__lambert__emission(){return true;}
	private:
		bool _begin__lambert__emission( void* attributeData ){return begin__lambert__emission();}
		bool _data__lambert__emission( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__emission();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__AMBIENT = 16135972;
		virtual bool begin__lambert__ambient(){return true;}
		virtual bool end__lambert__ambient(){return true;}
	private:
		bool _begin__lambert__ambient( void* attributeData ){return begin__lambert__ambient();}
		bool _data__lambert__ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__ambient();

	public:
		static const StringHash HASH_ELEMENT_AMBIENT__PARAM = 149506909;
		struct ambient__param__AttributeData
		{
			static const ambient__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__ambient__param( const ambient__param__AttributeData& attributeData ){return true;}
		virtual bool end__ambient__param(){return true;}
	private:
		bool _begin__ambient__param( void* attributeData ){return begin__ambient__param(*static_cast<ambient__param__AttributeData*>(attributeData));}
		bool _data__ambient__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__ambient__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ambient__param();

	public:
		static const StringHash HASH_ELEMENT_AMBIENT__TEXTURE = 84710501;
		struct ambient__texture__AttributeData
		{
			static const ambient__texture__AttributeData DEFAULT;

			const ParserChar* texture;
			const ParserChar* texcoord;
		};
		virtual bool begin__ambient__texture( const ambient__texture__AttributeData& attributeData ){return true;}
		virtual bool end__ambient__texture(){return true;}
	private:
		bool _begin__ambient__texture( void* attributeData ){return begin__ambient__texture(*static_cast<ambient__texture__AttributeData*>(attributeData));}
		bool _data__ambient__texture( const ParserChar* text, size_t textLength );
		bool _validateBegin__ambient__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ambient__texture();

	public:
		static const StringHash HASH_ELEMENT_DIFFUSE = 184343797;
		static const StringHash HASH_ELEMENT_LAMBERT__DIFFUSE = 36835829;
		virtual bool begin__lambert__diffuse(){return true;}
		virtual bool end__lambert__diffuse(){return true;}
	private:
		bool _begin__lambert__diffuse( void* attributeData ){return begin__lambert__diffuse();}
		bool _data__lambert__diffuse( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__diffuse();

	public:
		static const StringHash HASH_ELEMENT_DIFFUSE__COLOR = 211136114;
		struct diffuse__color__AttributeData
		{
			static const diffuse__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__diffuse__color( const diffuse__color__AttributeData& attributeData ){return true;}
		virtual bool end__diffuse__color(){return true;}
		virtual bool data__diffuse__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__diffuse__color( void* attributeData ){return begin__diffuse__color(*static_cast<diffuse__color__AttributeData*>(attributeData));}
		bool _data__diffuse__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__diffuse__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__diffuse__color();

	public:
		static const StringHash HASH_ELEMENT_DIFFUSE__PARAM = 212551533;
		struct diffuse__param__AttributeData
		{
			static const diffuse__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__diffuse__param( const diffuse__param__AttributeData& attributeData ){return true;}
		virtual bool end__diffuse__param(){return true;}
	private:
		bool _begin__diffuse__param( void* attributeData ){return begin__diffuse__param(*static_cast<diffuse__param__AttributeData*>(attributeData));}
		bool _data__diffuse__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__diffuse__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__diffuse__param();

	public:
		static const StringHash HASH_ELEMENT_DIFFUSE__TEXTURE = 117481509;
		struct diffuse__texture__AttributeData
		{
			static const diffuse__texture__AttributeData DEFAULT;

			const ParserChar* texture;
			const ParserChar* texcoord;
		};
		virtual bool begin__diffuse__texture( const diffuse__texture__AttributeData& attributeData ){return true;}
		virtual bool end__diffuse__texture(){return true;}
	private:
		bool _begin__diffuse__texture( void* attributeData ){return begin__diffuse__texture(*static_cast<diffuse__texture__AttributeData*>(attributeData));}
		bool _data__diffuse__texture( const ParserChar* text, size_t textLength );
		bool _validateBegin__diffuse__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__diffuse__texture();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__REFLECTIVE = 242202613;
		virtual bool begin__lambert__reflective(){return true;}
		virtual bool end__lambert__reflective(){return true;}
	private:
		bool _begin__lambert__reflective( void* attributeData ){return begin__lambert__reflective();}
		bool _data__lambert__reflective( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__reflective();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__REFLECTIVITY = 263720665;
		virtual bool begin__lambert__reflectivity(){return true;}
		virtual bool end__lambert__reflectivity(){return true;}
	private:
		bool _begin__lambert__reflectivity( void* attributeData ){return begin__lambert__reflectivity();}
		bool _data__lambert__reflectivity( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__reflectivity();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__TRANSPARENT = 121356996;
		struct lambert__transparent__AttributeData
		{
			static const lambert__transparent__AttributeData DEFAULT;

			const ParserChar* opaque;
		};
		virtual bool begin__lambert__transparent( const lambert__transparent__AttributeData& attributeData ){return true;}
		virtual bool end__lambert__transparent(){return true;}
	private:
		bool _begin__lambert__transparent( void* attributeData ){return begin__lambert__transparent(*static_cast<lambert__transparent__AttributeData*>(attributeData));}
		bool _data__lambert__transparent( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__transparent();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__TRANSPARENCY = 62664153;
		virtual bool begin__lambert__transparency(){return true;}
		virtual bool end__lambert__transparency(){return true;}
	private:
		bool _begin__lambert__transparency( void* attributeData ){return begin__lambert__transparency();}
		bool _data__lambert__transparency( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__transparency();

	public:
		static const StringHash HASH_ELEMENT_LAMBERT__INDEX_OF_REFRACTION = 87566030;
		virtual bool begin__lambert__index_of_refraction(){return true;}
		virtual bool end__lambert__index_of_refraction(){return true;}
	private:
		bool _begin__lambert__index_of_refraction( void* attributeData ){return begin__lambert__index_of_refraction();}
		bool _data__lambert__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _validateBegin__lambert__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__index_of_refraction();

	public:
		static const StringHash HASH_ELEMENT_PHONG = 7796295;
		static const StringHash HASH_ELEMENT_TECHNIQUE__PHONG = 204592647;
		virtual bool begin__phong(){return true;}
		virtual bool end__phong(){return true;}
	private:
		bool _begin__phong( void* attributeData ){return begin__phong();}
		bool _data__phong( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong();

	public:
		static const StringHash HASH_ELEMENT_PHONG__EMISSION = 105372942;
		virtual bool begin__phong__emission(){return true;}
		virtual bool end__phong__emission(){return true;}
	private:
		bool _begin__phong__emission( void* attributeData ){return begin__phong__emission();}
		bool _data__phong__emission( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__emission();

	public:
		static const StringHash HASH_ELEMENT_PHONG__AMBIENT = 157036644;
		virtual bool begin__phong__ambient(){return true;}
		virtual bool end__phong__ambient(){return true;}
	private:
		bool _begin__phong__ambient( void* attributeData ){return begin__phong__ambient();}
		bool _data__phong__ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__ambient();

	public:
		static const StringHash HASH_ELEMENT_PHONG__DIFFUSE = 93849765;
		virtual bool begin__phong__diffuse(){return true;}
		virtual bool end__phong__diffuse(){return true;}
	private:
		bool _begin__phong__diffuse( void* attributeData ){return begin__phong__diffuse();}
		bool _data__phong__diffuse( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__diffuse();

	public:
		static const StringHash HASH_ELEMENT_SPECULAR = 112903458;
		static const StringHash HASH_ELEMENT_PHONG__SPECULAR = 16253650;
		virtual bool begin__phong__specular(){return true;}
		virtual bool end__phong__specular(){return true;}
	private:
		bool _begin__phong__specular( void* attributeData ){return begin__phong__specular();}
		bool _data__phong__specular( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__specular();

	public:
		static const StringHash HASH_ELEMENT_SPECULAR__COLOR = 16126290;
		struct specular__color__AttributeData
		{
			static const specular__color__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__specular__color( const specular__color__AttributeData& attributeData ){return true;}
		virtual bool end__specular__color(){return true;}
		virtual bool data__specular__color( const void* data, size_t length ){return true;}
	private:
		bool _begin__specular__color( void* attributeData ){return begin__specular__color(*static_cast<specular__color__AttributeData*>(attributeData));}
		bool _data__specular__color( const ParserChar* text, size_t textLength );
		bool _validateBegin__specular__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__specular__color();

	public:
		static const StringHash HASH_ELEMENT_SPECULAR__PARAM = 13294157;
		struct specular__param__AttributeData
		{
			static const specular__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__specular__param( const specular__param__AttributeData& attributeData ){return true;}
		virtual bool end__specular__param(){return true;}
	private:
		bool _begin__specular__param( void* attributeData ){return begin__specular__param(*static_cast<specular__param__AttributeData*>(attributeData));}
		bool _data__specular__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__specular__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__specular__param();

	public:
		static const StringHash HASH_ELEMENT_SPECULAR__TEXTURE = 110988357;
		struct specular__texture__AttributeData
		{
			static const specular__texture__AttributeData DEFAULT;

			const ParserChar* texture;
			const ParserChar* texcoord;
		};
		virtual bool begin__specular__texture( const specular__texture__AttributeData& attributeData ){return true;}
		virtual bool end__specular__texture(){return true;}
	private:
		bool _begin__specular__texture( void* attributeData ){return begin__specular__texture(*static_cast<specular__texture__AttributeData*>(attributeData));}
		bool _data__specular__texture( const ParserChar* text, size_t textLength );
		bool _validateBegin__specular__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__specular__texture();

	public:
		static const StringHash HASH_ELEMENT_SHININESS = 5256531;
		static const StringHash HASH_ELEMENT_PHONG__SHININESS = 211569187;
		virtual bool begin__phong__shininess(){return true;}
		virtual bool end__phong__shininess(){return true;}
	private:
		bool _begin__phong__shininess( void* attributeData ){return begin__phong__shininess();}
		bool _data__phong__shininess( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__shininess();

	public:
		static const StringHash HASH_ELEMENT_SHININESS__FLOAT = 39878676;
		struct shininess__float__AttributeData
		{
			static const shininess__float__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__shininess__float( const shininess__float__AttributeData& attributeData ){return true;}
		virtual bool end__shininess__float(){return true;}
		virtual bool data__shininess__float( const void* data, size_t length ){return true;}
	private:
		bool _begin__shininess__float( void* attributeData ){return begin__shininess__float(*static_cast<shininess__float__AttributeData*>(attributeData));}
		bool _data__shininess__float( const ParserChar* text, size_t textLength );
		bool _validateBegin__shininess__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shininess__float();

	public:
		static const StringHash HASH_ELEMENT_SHININESS__PARAM = 40230381;
		struct shininess__param__AttributeData
		{
			static const shininess__param__AttributeData DEFAULT;

			const ParserChar* ref;
		};
		virtual bool begin__shininess__param( const shininess__param__AttributeData& attributeData ){return true;}
		virtual bool end__shininess__param(){return true;}
	private:
		bool _begin__shininess__param( void* attributeData ){return begin__shininess__param(*static_cast<shininess__param__AttributeData*>(attributeData));}
		bool _data__shininess__param( const ParserChar* text, size_t textLength );
		bool _validateBegin__shininess__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shininess__param();

	public:
		static const StringHash HASH_ELEMENT_PHONG__REFLECTIVE = 268102997;
		virtual bool begin__phong__reflective(){return true;}
		virtual bool end__phong__reflective(){return true;}
	private:
		bool _begin__phong__reflective( void* attributeData ){return begin__phong__reflective();}
		bool _data__phong__reflective( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__reflective();

	public:
		static const StringHash HASH_ELEMENT_PHONG__REFLECTIVITY = 183332681;
		virtual bool begin__phong__reflectivity(){return true;}
		virtual bool end__phong__reflectivity(){return true;}
	private:
		bool _begin__phong__reflectivity( void* attributeData ){return begin__phong__reflectivity();}
		bool _data__phong__reflectivity( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__reflectivity();

	public:
		static const StringHash HASH_ELEMENT_PHONG__TRANSPARENT = 241987796;
		struct phong__transparent__AttributeData
		{
			static const phong__transparent__AttributeData DEFAULT;

			const ParserChar* opaque;
		};
		virtual bool begin__phong__transparent( const phong__transparent__AttributeData& attributeData ){return true;}
		virtual bool end__phong__transparent(){return true;}
	private:
		bool _begin__phong__transparent( void* attributeData ){return begin__phong__transparent(*static_cast<phong__transparent__AttributeData*>(attributeData));}
		bool _data__phong__transparent( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__transparent();

	public:
		static const StringHash HASH_ELEMENT_PHONG__TRANSPARENCY = 113708105;
		virtual bool begin__phong__transparency(){return true;}
		virtual bool end__phong__transparency(){return true;}
	private:
		bool _begin__phong__transparency( void* attributeData ){return begin__phong__transparency();}
		bool _data__phong__transparency( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__transparency();

	public:
		static const StringHash HASH_ELEMENT_PHONG__INDEX_OF_REFRACTION = 215105534;
		virtual bool begin__phong__index_of_refraction(){return true;}
		virtual bool end__phong__index_of_refraction(){return true;}
	private:
		bool _begin__phong__index_of_refraction( void* attributeData ){return begin__phong__index_of_refraction();}
		bool _data__phong__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _validateBegin__phong__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__index_of_refraction();

	public:
		static const StringHash HASH_ELEMENT_BLINN = 6893646;
		static const StringHash HASH_ELEMENT_TECHNIQUE__BLINN = 202379278;
		virtual bool begin__blinn(){return true;}
		virtual bool end__blinn(){return true;}
	private:
		bool _begin__blinn( void* attributeData ){return begin__blinn();}
		bool _data__blinn( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn();

	public:
		static const StringHash HASH_ELEMENT_BLINN__EMISSION = 73311438;
		virtual bool begin__blinn__emission(){return true;}
		virtual bool end__blinn__emission(){return true;}
	private:
		bool _begin__blinn__emission( void* attributeData ){return begin__blinn__emission();}
		bool _data__blinn__emission( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__emission();

	public:
		static const StringHash HASH_ELEMENT_BLINN__AMBIENT = 87931284;
		virtual bool begin__blinn__ambient(){return true;}
		virtual bool end__blinn__ambient(){return true;}
	private:
		bool _begin__blinn__ambient( void* attributeData ){return begin__blinn__ambient();}
		bool _data__blinn__ambient( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__ambient();

	public:
		static const StringHash HASH_ELEMENT_BLINN__DIFFUSE = 167354197;
		virtual bool begin__blinn__diffuse(){return true;}
		virtual bool end__blinn__diffuse(){return true;}
	private:
		bool _begin__blinn__diffuse( void* attributeData ){return begin__blinn__diffuse();}
		bool _data__blinn__diffuse( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__diffuse();

	public:
		static const StringHash HASH_ELEMENT_BLINN__SPECULAR = 116301074;
		virtual bool begin__blinn__specular(){return true;}
		virtual bool end__blinn__specular(){return true;}
	private:
		bool _begin__blinn__specular( void* attributeData ){return begin__blinn__specular();}
		bool _data__blinn__specular( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__specular();

	public:
		static const StringHash HASH_ELEMENT_BLINN__SHININESS = 185448003;
		virtual bool begin__blinn__shininess(){return true;}
		virtual bool end__blinn__shininess(){return true;}
	private:
		bool _begin__blinn__shininess( void* attributeData ){return begin__blinn__shininess();}
		bool _data__blinn__shininess( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__shininess();

	public:
		static const StringHash HASH_ELEMENT_BLINN__REFLECTIVE = 109390693;
		virtual bool begin__blinn__reflective(){return true;}
		virtual bool end__blinn__reflective(){return true;}
	private:
		bool _begin__blinn__reflective( void* attributeData ){return begin__blinn__reflective();}
		bool _data__blinn__reflective( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__reflective();

	public:
		static const StringHash HASH_ELEMENT_BLINN__REFLECTIVITY = 86734393;
		virtual bool begin__blinn__reflectivity(){return true;}
		virtual bool end__blinn__reflectivity(){return true;}
	private:
		bool _begin__blinn__reflectivity( void* attributeData ){return begin__blinn__reflectivity();}
		bool _data__blinn__reflectivity( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__reflectivity();

	public:
		static const StringHash HASH_ELEMENT_BLINN__TRANSPARENT = 160434500;
		struct blinn__transparent__AttributeData
		{
			static const blinn__transparent__AttributeData DEFAULT;

			const ParserChar* opaque;
		};
		virtual bool begin__blinn__transparent( const blinn__transparent__AttributeData& attributeData ){return true;}
		virtual bool end__blinn__transparent(){return true;}
	private:
		bool _begin__blinn__transparent( void* attributeData ){return begin__blinn__transparent(*static_cast<blinn__transparent__AttributeData*>(attributeData));}
		bool _data__blinn__transparent( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__transparent();

	public:
		static const StringHash HASH_ELEMENT_BLINN__TRANSPARENCY = 151033145;
		virtual bool begin__blinn__transparency(){return true;}
		virtual bool end__blinn__transparency(){return true;}
	private:
		bool _begin__blinn__transparency( void* attributeData ){return begin__blinn__transparency();}
		bool _data__blinn__transparency( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__transparency();

	public:
		static const StringHash HASH_ELEMENT_BLINN__INDEX_OF_REFRACTION = 24357934;
		virtual bool begin__blinn__index_of_refraction(){return true;}
		virtual bool end__blinn__index_of_refraction(){return true;}
	private:
		bool _begin__blinn__index_of_refraction( void* attributeData ){return begin__blinn__index_of_refraction();}
		bool _data__blinn__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _validateBegin__blinn__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__index_of_refraction();

	public:
		static const StringHash HASH_ELEMENT_PROFILE_COMMON__EXTRA = 145663265;
		struct profile_COMMON__extra__AttributeData
		{
			static const profile_COMMON__extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__profile_COMMON__extra( const profile_COMMON__extra__AttributeData& attributeData ){return true;}
		virtual bool end__profile_COMMON__extra(){return true;}
	private:
		bool _begin__profile_COMMON__extra( void* attributeData ){return begin__profile_COMMON__extra(*static_cast<profile_COMMON__extra__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__profile_COMMON__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__extra();

	public:
		struct triangles__AttributeData
		{
			static const triangles__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__triangles( const triangles__AttributeData& attributeData ){return true;}
		virtual bool end__triangles(){return true;}
	private:
		bool _begin__triangles( void* attributeData ){return begin__triangles(*static_cast<triangles__AttributeData*>(attributeData));}
		bool _data__triangles( const ParserChar* text, size_t textLength );
		bool _validateBegin__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles();

	public:
		struct rotate__AttributeData
		{
			static const rotate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__rotate( const rotate__AttributeData& attributeData ){return true;}
		virtual bool end__rotate(){return true;}
		virtual bool data__rotate( const void* data, size_t length ){return true;}
	private:
		bool _begin__rotate( void* attributeData ){return begin__rotate(*static_cast<rotate__AttributeData*>(attributeData));}
		bool _data__rotate( const ParserChar* text, size_t textLength );
		bool _validateBegin__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rotate();

	public:
		virtual bool begin__bind_material(){return true;}
		virtual bool end__bind_material(){return true;}
	private:
		bool _begin__bind_material( void* attributeData ){return begin__bind_material();}
		bool _data__bind_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material();

	public:
		struct instance_force_field__AttributeData
		{
			static const instance_force_field__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_force_field( const instance_force_field__AttributeData& attributeData ){return true;}
		virtual bool end__instance_force_field(){return true;}
	private:
		bool _begin__instance_force_field( void* attributeData ){return begin__instance_force_field(*static_cast<instance_force_field__AttributeData*>(attributeData));}
		bool _data__instance_force_field( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_force_field();

	public:
		virtual bool begin__asset(){return true;}
		virtual bool end__asset(){return true;}
	private:
		bool _begin__asset( void* attributeData ){return begin__asset();}
		bool _data__asset( const ParserChar* text, size_t textLength );
		bool _validateBegin__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__asset();

	public:
		struct polygons__AttributeData
		{
			static const polygons__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__polygons( const polygons__AttributeData& attributeData ){return true;}
		virtual bool end__polygons(){return true;}
	private:
		bool _begin__polygons( void* attributeData ){return begin__polygons(*static_cast<polygons__AttributeData*>(attributeData));}
		bool _data__polygons( const ParserChar* text, size_t textLength );
		bool _validateBegin__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons();

	public:
		struct vertices__AttributeData
		{
			static const vertices__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
		};
		virtual bool begin__vertices( const vertices__AttributeData& attributeData ){return true;}
		virtual bool end__vertices(){return true;}
	private:
		bool _begin__vertices( void* attributeData ){return begin__vertices(*static_cast<vertices__AttributeData*>(attributeData));}
		bool _data__vertices( const ParserChar* text, size_t textLength );
		bool _validateBegin__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertices();

	public:
		struct extra__AttributeData
		{
			static const extra__AttributeData DEFAULT;

			const ParserChar* id;
			const ParserChar* name;
			const ParserChar* type;
		};
		virtual bool begin__extra( const extra__AttributeData& attributeData ){return true;}
		virtual bool end__extra(){return true;}
	private:
		bool _begin__extra( void* attributeData ){return begin__extra(*static_cast<extra__AttributeData*>(attributeData));}
		bool _data__extra( const ParserChar* text, size_t textLength );
		bool _validateBegin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__extra();

	public:
		struct instance_physics_material__AttributeData
		{
			static const instance_physics_material__AttributeData DEFAULT;

			const ParserChar* url;
			const ParserChar* sid;
			const ParserChar* name;
		};
		virtual bool begin__instance_physics_material( const instance_physics_material__AttributeData& attributeData ){return true;}
		virtual bool end__instance_physics_material(){return true;}
	private:
		bool _begin__instance_physics_material( void* attributeData ){return begin__instance_physics_material(*static_cast<instance_physics_material__AttributeData*>(attributeData));}
		bool _data__instance_physics_material( const ParserChar* text, size_t textLength );
		bool _validateBegin__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_material();

	public:
		struct polylist__AttributeData
		{
			static const polylist__AttributeData DEFAULT;

			const ParserChar* name;
			const ParserChar* count;
			const ParserChar* material;
		};
		virtual bool begin__polylist( const polylist__AttributeData& attributeData ){return true;}
		virtual bool end__polylist(){return true;}
	private:
		bool _begin__polylist( void* attributeData ){return begin__polylist(*static_cast<polylist__AttributeData*>(attributeData));}
		bool _data__polylist( const ParserChar* text, size_t textLength );
		bool _validateBegin__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist();

	public:
		struct translate__AttributeData
		{
			static const translate__AttributeData DEFAULT;

			const ParserChar* sid;
		};
		virtual bool begin__translate( const translate__AttributeData& attributeData ){return true;}
		virtual bool end__translate(){return true;}
		virtual bool data__translate( const void* data, size_t length ){return true;}
	private:
		bool _begin__translate( void* attributeData ){return begin__translate(*static_cast<translate__AttributeData*>(attributeData));}
		bool _data__translate( const ParserChar* text, size_t textLength );
		bool _validateBegin__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__translate();



	private:
		/** Disable default copy ctor. */
		ColladaParserAutoGen( const ColladaParserAutoGen& pre );
		/** Disable default assignment operator. */
		const ColladaParserAutoGen& operator= ( const ColladaParserAutoGen& pre );

		void initFunctionMap();
		void initNameMap(){};

	};

}
#endif
