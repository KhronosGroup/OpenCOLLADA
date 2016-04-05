#ifndef __COLLADAMAX_COLLADAPLUGIN_H__
#define __COLLADAMAX_COLLADAPLUGIN_H__

#include "COLLADAMaxPrerequisites.h"



namespace COLLADAMax
{
	class COLLADAPlugin 	
	{
	public:
		static const TCHAR* EXTENSIONNAME;
		static const TCHAR* LONGDESCRIPTION;
		static const TCHAR* SHORTDESCRIPTION;
		static const TCHAR* AUTHORNAME;
		static const TCHAR* COPYRIGHTMESSAGE;
		static const TCHAR* OTHERMESSAGE1;
		static const TCHAR* OTHERMESSAGE2;

		static const TCHAR* PLUGIN_VERSION_TCHAR;
		static const String PLUGIN_VERSION_STRING;
		static const String REVISION_STRING;


		static const TCHAR* FATALERROR;


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
