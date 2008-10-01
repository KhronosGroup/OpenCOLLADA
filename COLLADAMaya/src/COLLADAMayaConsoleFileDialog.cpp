/////////////////////////////////////////////////////////////////////////////////////////////
///	\file	FileDialog.cpp
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
#include "COLLADAMayaStableHeaders.h"
//#ifndef WIN32
#ifdef LINUX
#include <gtk/gtk.h>
#include <string.h>
#include <assert.h>

extern int   g_argc;
extern char** g_argv;

char g_FileName[512];

/* Get the selected filename and print it to the console */
static void file_ok_sel( GtkWidget        *w,
                         GtkFileSelection *fs )
{
	strcpy(g_FileName,gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
}

int OpenFileDialog(char FileName[])
{
    GtkWidget *filew;

	g_FileName[0] = '\0';

    gtk_init (&g_argc, &g_argv);

    /* Create a new file selection widget */
    filew = gtk_file_selection_new ("File selection");

    g_signal_connect (G_OBJECT (filew), "destroy",
	              G_CALLBACK (gtk_main_quit), NULL);

    /* Connect the ok_button to file_ok_sel function */
    g_signal_connect (G_OBJECT (GTK_FILE_SELECTION (filew)->ok_button),
		      "clicked", G_CALLBACK (file_ok_sel), (gpointer) filew);

    /* Connect the cancel_button to destroy the widget */
    g_signal_connect_swapped (G_OBJECT (GTK_FILE_SELECTION (filew)->cancel_button),
							 "clicked",
							 G_CALLBACK (gtk_widget_destroy),
			      			 G_OBJECT (filew));
    /* Connect the cancel_button to destroy the widget */
    g_signal_connect_swapped (G_OBJECT (GTK_FILE_SELECTION (filew)->ok_button),
							 "clicked",
							 G_CALLBACK (gtk_widget_destroy),
			      			 G_OBJECT (filew));

    gtk_widget_show (filew);
    gtk_main ();

	if(g_FileName[0] != '\0') {
		strcpy(FileName,g_FileName);
		return 1;
	}

    return 0;
}

int SaveFileDialog(char FileName[]) {
	return OpenFileDialog(FileName);
}


#else
#ifdef WIN32
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

namespace COLLADAMaya
{

    int OpenFileDialog(char FileName[])
    {
	    char Dir[512];
	    char fn[512] = {0};
	    OPENFILENAME ofn;
	    memset(&ofn,0,sizeof(OPENFILENAME));
	    ofn.lStructSize = sizeof(OPENFILENAME);
	    ofn.lpstrFile = fn;
	    ofn.nMaxFile = 512;
	    ofn.lpstrTitle = "Open File";


	    GetCurrentDirectory(512,Dir);
	    if( GetOpenFileName(&ofn) )
	    {
		    int i;
		    for (i=0;i<512;++i)
		    {
			    if( fn[i] == '\\' )
				    fn[i] = '/';
		    }
		    strcpy(FileName,fn);
		    SetCurrentDirectory(Dir);
		    return 1;
	    }
	    FileName[0] = '\0';
	    SetCurrentDirectory(Dir);
	    return 0;
    }

    int SaveFileDialog(char FileName[])
    {
	    char Dir[512];
	    char fn[512] = {0};
	    OPENFILENAME ofn;
	    memset(&ofn,0,sizeof(OPENFILENAME));
	    ofn.lStructSize = sizeof(OPENFILENAME);
	    ofn.lpstrFile = fn;
	    ofn.nMaxFile = 512;
	    ofn.lpstrTitle = "Save File";
	    GetCurrentDirectory(512,Dir);
	    if( GetSaveFileName(&ofn) )
	    {
		    int i;
		    for (i=0;i<512;++i)
		    {
			    if( fn[i] == '\\' )
				    fn[i] = '/';
		    }
		    strcpy(FileName,fn);
		    SetCurrentDirectory(Dir);
		    return 1;
	    }
	    FileName[0] = '\0';
	    SetCurrentDirectory(Dir);
	    return 0;
    }
}

#endif
#endif

