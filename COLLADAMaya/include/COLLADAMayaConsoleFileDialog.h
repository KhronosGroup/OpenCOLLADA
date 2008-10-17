/////////////////////////////////////////////////////////////////////////////////////////////
///	\file	FileDialog.h
///	\author	Robert	Bateman
/// \brief	This just provides some linux and win32 file dialogs. Under Linux it uses gtk2
///	\note	
/// 		This sourcefile is provided for free use for non-commercial purposes only. The
/// 		Software is provided 'as is' and no responsibility can be taken for any damages
/// 		that may be caused while using it. If you make use of this software within 
/// 		your code then it would be nice to have a small credit somewhere in your
/// 		finished product for my hard work :(
/// 		An e-mail saying you found it useful and possibly even a link to your product
/// 		would be really nice too ;)
///
///			Slip me a couple of quid and i might be kind enough to offer assistance in
/// 		sorting out your exporters ;) 
///
///				(C) 2004 Rob 'give me a job offer' Bateman 
///
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __NATIVE_FILE_DIALOGS__H__
#define __NATIVE_FILE_DIALOGS__H__

namespace COLLADAMaya
{
    /*!
    *	\brief	This function creates an open file dialog. This will either use WIN32
    *			Or it will make use of gtk2 if running on linux
    *	\param	Filename	-	this will hold the returned file name & path
    *	\return	1 if OK selected, zero otherwise
    */
    int openFileDialog ( char fileName[], char* fileExtensions );

    /*!
    *	\brief	This function creates an save file dialog. This will either use WIN32
    *			Or it will make use of gtk2 if running on linux
    *	\param	Filename	-	this will hold the returned file name & path
    *	\return	1 if OK selected, zero otherwise
    */
    int saveFileDialog ( char FileName[], char* fileExtensions, char* defaultExtension );
}

#endif
