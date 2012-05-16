#ifndef __COLLADAMAX_COLLADAPLUGIN_H__
#define __COLLADAMAX_COLLADAPLUGIN_H__

#include "COLLADAMaxPrerequisites.h"



namespace COLLADAMax
{
	class COLLADAPlugin 	
	{
	public:
		static const String EXTENSIONNAME;
		static const String LONGDESCRIPTION;
		static const String SHORTDESCRIPTION;
		static const String AUTHORNAME;
		static const String COPYRIGHTMESSAGE;
		static const String OTHERMESSAGE1;
		static const String OTHERMESSAGE2;

		static const String PLUGIN_VERSION_STRING;
		static const String REVISION_STRING;
		static const String PLATFORM_STRING;
		static const String CONFIGURATION_STRING;


		static const String FATALERROR;


		static const unsigned int PLUGINVERSION;

	
		// public function declarations
	public:
		COLLADAPlugin();
		virtual ~COLLADAPlugin();

		// public static function declarations
	public:
	
		// protected function declarations
	protected:
	
		// private function declarations
	private:
        /** Disable default copy ctor. */
		COLLADAPlugin( const COLLADAPlugin& pre );
        /** Disable default assignment operator. */
		const COLLADAPlugin& operator= ( const COLLADAPlugin& pre );

	};
} // namespace COLLADAMAX

#endif // __COLLADAMAX_COLLADAPLUGIN_H__
