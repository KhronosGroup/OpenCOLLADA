#ifndef __COLLADAMAX_COLLADAIMPORTER_H__
#define __COLLADAMAX_COLLADAIMPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include <max.h>



namespace COLLADAMax 
{
	class ColladaImporter : public SceneImport
	{
	public:
		static const Class_ID COLLADAIMPORTER_CLASS_ID;
		static const String PROGRESSSTART;

	
		// public function declarations
	public:
		ColladaImporter();
		virtual ~ColladaImporter();

		// from SceneImport

		/** Returns the number of file name extensions supported by the plug-in.*/
		int ExtCount();    

		/**  Returns the 'n-th' file name extension (i.e. "3DS").
		@param n The index of the file name extension to return. */
		const TCHAR* Ext ( int n );  

		/** Long ASCII description (i.e. "Autodesk 3D Studio File")*/
		const TCHAR* LongDesc();     

		/** Short ASCII description (i.e. "3D Studio")*/
		const TCHAR* ShortDesc();    

		/** ASCII Author name.*/
		const TCHAR* AuthorName();

		/** ASCII Copyright message.*/
		const TCHAR* CopyrightMessage();

		/** Other message #1.*/
		const TCHAR* OtherMessage1();   

		/** Other message #2.*/
		const TCHAR* OtherMessage2();   

		/** Version number * 100 (i.e. v3.01 = 301).*/
		unsigned int Version();

		/** Show DLL's "About..." box.*/
		void ShowAbout ( HWND hWnd ); 

		BOOL SupportsOptions ( int ext, DWORD options );

		int DoImport (const TCHAR *name,ImpInterface *maxImportInterface,Interface *maxInterface, BOOL suppressPrompts=FALSE);

		static DWORD WINAPI fn ( LPVOID );

		// public static function declarations
	public:
	
		// protected function declarations
	protected:
	
		// private function declarations
	private:
        /** Disable default copy ctor. */
		ColladaImporter( const ColladaImporter& pre );
        /** Disable default assignment operator. */
		const ColladaImporter& operator= ( const ColladaImporter& pre );

	};


	ClassDesc2* getCOLLADAImporterDesc();


	//
	// ColladaImporterClassDesc
	//

	class ColladaImporterClassDesc : public ClassDesc2
	{

	public:
		int IsPublic()
		{
			return TRUE;
		}

		void * Create ( BOOL isLoading = FALSE )
		{
			isLoading;
			return new ColladaImporter();
		}

		const TCHAR * ClassName()
		{
			return "OpenCOLLADAImporter";
		}

		SClass_ID SuperClassID()
		{
			return SCENE_IMPORT_CLASS_ID;
		}

		Class_ID ClassID()
		{
			return ColladaImporter::COLLADAIMPORTER_CLASS_ID;
		}

		const TCHAR* Category()
		{
			return "Import";
		} //GetString(IDS_CATEGORY_E); }

		const TCHAR* InternalName()
		{
			return "OpenCOLLADAImporter";
		} // returns fixed parsable name (scripter-visible name)

		HINSTANCE HInstance()
		{
			return hInstance;
		}    // returns owning module handle

	};



} // namespace COLLADAMAX

#endif // __COLLADAMAX_COLLADAIMPORTER_H__
