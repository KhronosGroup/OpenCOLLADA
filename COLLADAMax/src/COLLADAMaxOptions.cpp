/*
   Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

   Portions of the code are:
   Copyright (c) 2005-2007 Feeling Software Inc.
   Copyright (c) 2005-2007 Sony Computer Entertainment America
   
   Based on the 3dsMax COLLADA Tools:
   Copyright (c) 2005-2006 Autodesk Media Entertainment
	
   Licensed under the MIT Open Source License, 
   for details please see LICENSE file or the website
   http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxOptions.h"

#include <max.h>
#include <maxapi.h>
#include <custcont.h> 

#include "resource.h"

namespace COLLADAMax
{

	const String Options::OPTION_NORMALS_NAME = "normals";
	const String Options::OPTION_TRIANGULAT_NAME = "triangulate";
	const String Options::OPTION_XREFS_NAME = "xrefs";
	const String Options::OPTION_TANGENTS_NAME =  "tangents";
	const String Options::OPTION_ANIMATIONS_NAME =  "animations";
	const String Options::OPTION_SAMPLEANIMATIONS_NAME =  "sampleAnim";
	const String Options::OPTION_CREATECLIP_NAME =  "createClip";
	const String Options::OPTION_BAKEMATRICES_NAME =  "bakeMatrices";
	const String Options::OPTION_RELATIVEPATHS_NAME =  "relativePaths";
	const String Options::OPTION_CHECKIFANIMATIONISANIMATED_NAME =  "checkIfAnimationIsAnimated";
	const String Options::OPTION_ANIMATIONSTART_NAME =  "animStart";
	const String Options::OPTION_ANIMATIONEND_NAME =  "animEnd";



	static void EnableDlgControl(HWND window, int controlId, BOOL enabled)
	{
		HWND control = GetDlgItem(window, controlId);
		if (control) 
			EnableWindow(control, enabled);
	}

	template<class OptionType>
	void writeOption(FILE* file, const String & optionName, OptionType optionValue)
	{
		String optionString = optionName + "=%d\r\n";
		fprintf_s(file, optionString.c_str(), optionValue);
	}

	template<class OptionType>
	bool readOption(char* token, const String & optionName, char* value, OptionType &optionValue)
	{
		bool match = strcmp(token, optionName.c_str()) == 0;
		if ( match )
			optionValue = (OptionType) atoi(value);
		return match;
	}

	template<>
	bool readOption<bool>(char* token, const String & optionName, char* value, bool &optionValue)
	{
		bool match = strcmp(token, optionName.c_str()) == 0;
		if ( match )
			optionValue = atoi(value) != false;
		return match;
	}


	const String Options::CONFIGURATION_FILE_NAME = "NewColladaMax.ini";
	const String Options::CONFIGURATION_HEADER_NAME = "NewColladaMax";

	Options::Options(Interface* maxInterface)
		:
		mMaxInterface(maxInterface),
		// Set the option values to their default
		mNormals(true),
		mTriangulate(true),
		mXrefs(true),
		mTangents(false),
		mAnimations(true),
		mSampleAnimation(false),
		mCreateClip(false),
		mBakeMatrices(false),
		mRelativePaths(true),
		mCheckIfAnimationIsAnimated(false),
		importUnits(true),
		importUpAxis(true),
		mSelectionOnly(false),

		mAnimationStart(TIME_INITIAL_POSE),
		mAnimationEnd(TIME_PosInfinity)
	{

		// Load the export options from the configuration file
	//	LoadOptions();
	}

	// Displays the exporter options dialog to allow the user to change the options.
	bool Options::ShowDialog()
	{

		// Prompt the user with our dialogbox, and get all the options.
		bool doExport = DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_EXPORT_OPTIONS), mMaxInterface->GetMAXHWnd(), ExportOptionsDlgProcS, (LPARAM)this) != FALSE;
		
		if (!doExport) 
			return false;

		// Save the export options to the configuration file
		SaveOptions();

		return true;
	}


	// options dialog message handler
	INT_PTR Options::ExportOptionsDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM)
	{
		ISpinnerControl* spin;
		//	int ticksPerFrame = GetTicksPerFrame();
		Interval animRange = mMaxInterface->GetAnimRange();
		int sceneStart = animRange.Start();
		int sceneEnd = animRange.End();

		switch (message)
		{
		case WM_INITDIALOG: {
			CenterWindow(hWnd, GetParent(hWnd)); 

			// grab scene timing details & clip anim start & end if needed
			if (mAnimationStart < sceneStart) 
				mAnimationStart = sceneStart;

			if (mAnimationStart > sceneEnd) 
				mAnimationStart = sceneEnd;

			if (mAnimationEnd < sceneStart) 
				mAnimationEnd = sceneStart;

			if (mAnimationEnd > sceneEnd) 
				mAnimationEnd = sceneEnd;

			// setup checkboxes
			CheckDlgButton(hWnd, IDC_GEOM_NORMALS, mNormals);
			CheckDlgButton(hWnd, IDC_GEOM_TRIANGLES, mTriangulate);
			CheckDlgButton(hWnd, IDC_GEOM_XREFS, mXrefs);
			CheckDlgButton(hWnd, IDC_GEOM_TANGENTS, mTangents);
			CheckDlgButton(hWnd, IDC_ANIM_ENABLE, mAnimations);
			CheckDlgButton(hWnd, IDC_ANIM_SAMPLE, mSampleAnimation);
			CheckDlgButton(hWnd, IDC_ANIM_CLIP, mCreateClip);
			CheckDlgButton(hWnd, IDC_BAKE_MATRICES, mBakeMatrices);
			CheckDlgButton(hWnd, IDC_RELATIVE_PATHS, mRelativePaths);

			// Animation checkboxes depend on the enable button.
			EnableDlgControl(hWnd, IDC_ANIM_SAMPLE, mAnimations);
			EnableDlgControl(hWnd, IDC_ANIM_CLIP, mAnimations);

			// setup spinners
			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_START_SPIN)); 
			spin->LinkToEdit(GetDlgItem(hWnd,IDC_ANIM_START), EDITTYPE_TIME);
			spin->SetLimits(sceneStart, sceneEnd, true); 
			spin->SetScale(1.0f);
			spin->SetValue(mAnimationStart, true);
			spin->Enable(mSampleAnimation && mAnimations);
			EnableWindow(GetDlgItem(hWnd, IDC_START_LABEL), mSampleAnimation && mAnimations);
			ReleaseISpinner(spin);

			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_END_SPIN)); 
			spin->LinkToEdit(GetDlgItem(hWnd,IDC_ANIM_END), EDITTYPE_TIME); 
			spin->SetLimits(sceneStart, sceneEnd, true); 
			spin->SetScale(1.0f);
			spin->SetValue(mAnimationEnd, false);
			spin->Enable(mSampleAnimation && mAnimations);
			EnableWindow(GetDlgItem(hWnd, IDC_END_LABEL), mSampleAnimation && mAnimations);
			ReleaseISpinner(spin);

			return true;
							}

		case WM_COMMAND:
			switch (LOWORD(wParam)) {
		case IDC_ANIM_ENABLE:
			mAnimations = IsDlgButtonChecked(hWnd, IDC_ANIM_ENABLE) == BST_CHECKED;
			EnableDlgControl(hWnd, IDC_ANIM_SAMPLE, mAnimations);
			EnableDlgControl(hWnd, IDC_ANIM_CLIP, mAnimations);

			/*spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_START_SPIN)); 
			//spin->LinkToEdit(GetDlgItem(hWnd,IDC_ANIM_START), EDITTYPE_INT);
			spin->Enable(sampleAnim && animations);
			EnableWindow(GetDlgItem(hWnd, IDC_START_LABEL), sampleAnim && animations);
			ReleaseISpinner(spin);

			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_END_SPIN)); 
			//spin->LinkToEdit(GetDlgItem(hWnd,IDC_ANIM_END), EDITTYPE_INT);
			spin->Enable(sampleAnim && animations);
			EnableWindow(GetDlgItem(hWnd, IDC_END_LABEL), sampleAnim && animations);
			ReleaseISpinner(spin);
			break; */

		case IDC_ANIM_SAMPLE:
			mSampleAnimation = IsDlgButtonChecked(hWnd, IDC_ANIM_SAMPLE) == BST_CHECKED;

			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_START_SPIN)); 
			spin->Enable(mSampleAnimation && mAnimations);
			EnableWindow(GetDlgItem(hWnd, IDC_START_LABEL), mSampleAnimation && mAnimations);
			ReleaseISpinner(spin);

			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_END_SPIN)); 
			spin->Enable(mSampleAnimation && mAnimations);
			EnableWindow(GetDlgItem(hWnd, IDC_END_LABEL), mSampleAnimation && mAnimations);
			ReleaseISpinner(spin);
			break;

		case IDOK:
			// hit OK, pick up control values & end dialog
			mBakeMatrices = IsDlgButtonChecked(hWnd, IDC_BAKE_MATRICES) == BST_CHECKED;
			mRelativePaths = IsDlgButtonChecked(hWnd, IDC_RELATIVE_PATHS) == BST_CHECKED;
			mAnimations = IsDlgButtonChecked(hWnd, IDC_ANIM_ENABLE) == BST_CHECKED;
			mSampleAnimation = IsDlgButtonChecked(hWnd, IDC_ANIM_SAMPLE) == BST_CHECKED;
			mCreateClip = IsDlgButtonChecked(hWnd, IDC_ANIM_CLIP) == BST_CHECKED;
			mNormals = IsDlgButtonChecked(hWnd, IDC_GEOM_NORMALS) == BST_CHECKED;
			mTriangulate = IsDlgButtonChecked(hWnd, IDC_GEOM_TRIANGLES) == BST_CHECKED;
			mXrefs = IsDlgButtonChecked(hWnd, IDC_GEOM_XREFS) == BST_CHECKED;
			mTangents = IsDlgButtonChecked(hWnd, IDC_GEOM_TANGENTS) == BST_CHECKED;

			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_START_SPIN)); 
			mAnimationStart = mSampleAnimation ? spin->GetIVal() : sceneStart;
			ReleaseISpinner(spin);
			spin = GetISpinner(GetDlgItem(hWnd, IDC_ANIM_END_SPIN)); 
			mAnimationEnd = mSampleAnimation ? spin->GetIVal() : sceneEnd; 
			ReleaseISpinner(spin);

			EndDialog(hWnd, 1);
			break;

		case IDCANCEL:
			EndDialog(hWnd, 0);
			break;
			}
		default:
			return false;
		}
		return true;
	}



	// options dialog proc
	INT_PTR CALLBACK Options::ExportOptionsDlgProcS(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
	{
		Options* exp;
		if (message == WM_INITDIALOG)
		{
			// record exp instance pointer for subsequent callbacks
			exp = (Options*) lParam;
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG)lParam); 
		}
		else
		{
			exp = (Options*)(size_t) GetWindowLongPtr(hWnd, GWLP_USERDATA);
		}
		// hand off to message-handler method
		return exp ? exp->ExportOptionsDlgProc(hWnd, message, wParam, lParam) : false;
	}



	void Options::SaveOptions()
	{
		String configurationPath = mMaxInterface->GetDir(APP_PLUGCFG_DIR);
		String filename = configurationPath + "\\" + CONFIGURATION_FILE_NAME;
		FILE* file;
		errno_t error = fopen_s(&file, filename.c_str(), "wb");
		if ( error )
			return;



		// Write down a standard INI header to allow MaxScript edition.
		String headerString("[" + CONFIGURATION_HEADER_NAME + "]\r\n");
		fwrite(headerString.data(), headerString.length(), 1, file);

		// Write down the options, one by one, in the form: 'option=X\n'
		writeOption(file, OPTION_NORMALS_NAME, mNormals );

		writeOption(file, OPTION_TRIANGULAT_NAME, mTriangulate );
		writeOption(file, OPTION_XREFS_NAME, mXrefs );
		writeOption(file, OPTION_TANGENTS_NAME, mTangents );
		writeOption(file, OPTION_ANIMATIONS_NAME, mAnimations );
		writeOption(file, OPTION_SAMPLEANIMATIONS_NAME, mSampleAnimation );
		writeOption(file, OPTION_CREATECLIP_NAME, mCreateClip );
		writeOption(file, OPTION_BAKEMATRICES_NAME, mBakeMatrices );
		writeOption(file, OPTION_RELATIVEPATHS_NAME, mRelativePaths );
		writeOption(file, OPTION_CHECKIFANIMATIONISANIMATED_NAME, mCheckIfAnimationIsAnimated );
		writeOption(file, OPTION_ANIMATIONSTART_NAME, mAnimationStart );
		writeOption(file, OPTION_ANIMATIONEND_NAME, mAnimationEnd );

		fclose(file);
	}



	void Options::LoadOptions()
	{
		String configurationPath =  mMaxInterface->GetDir(APP_PLUGCFG_DIR);
		String filename = configurationPath + "\\" + CONFIGURATION_FILE_NAME;

		FILE* file;
		errno_t error = fopen_s(&file, filename.c_str(), "rb");
		if ( error )
			return;

		// Read the whole configuration file
		fseek(file, 0, SEEK_END);
		int fileLength = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* wholeFile = new char[fileLength + 1];
		fread(wholeFile, 1, fileLength, file);
		fclose(file);
		wholeFile[fileLength] = 0;

		// Read in the options, one by one, in the form: 'option=X\n'
		char* token = strtok_s(wholeFile, "\n",0);
		while (token )
		{
			// Skip whitespaces
			while (*token != 0 && (*token == ' ' || *token == '\r' || *token == '\t')) ++token;
			if (*token != 0)
			{
				if (*token == '[') {} // Standard INI header. Just skip the line for now.

				// Read in the Property=Value lines.
				char* value = strchr(token, '=');
				if (value )
				{
					*(value++) = 0;
					while (*value != 0 && (*value == ' ' || *value == '\r' || *value == '\t')) ++value;
					if (*value != 0) // skip empty lines.
					{
						// Look for/read in the ColladaMax options.
						readOption<bool>(token, OPTION_NORMALS_NAME, value, mNormals) ||
						readOption<bool>(token, OPTION_TRIANGULAT_NAME, value, mTriangulate) ||
						readOption<bool>(token, OPTION_XREFS_NAME, value, mXrefs) ||
						readOption<bool>(token, OPTION_TRIANGULAT_NAME, value, mTangents) ||
						readOption<bool>(token, OPTION_SAMPLEANIMATIONS_NAME, value, mSampleAnimation) ||
						readOption<bool>(token, OPTION_ANIMATIONS_NAME, value, mAnimations) ||
						readOption<bool>(token, OPTION_CREATECLIP_NAME, value, mCreateClip) ||
						readOption<bool>(token, OPTION_BAKEMATRICES_NAME, value, mBakeMatrices) ||
						readOption<bool>(token, OPTION_RELATIVEPATHS_NAME, value, mRelativePaths) ||
						readOption<bool>(token, OPTION_CHECKIFANIMATIONISANIMATED_NAME, value, mCheckIfAnimationIsAnimated) ||
						readOption<int>(token, OPTION_ANIMATIONSTART_NAME, value, mAnimationStart) ||
						readOption<int>(token, OPTION_ANIMATIONEND_NAME, value, mAnimationEnd);

						{
							// Handle unknown option here.
						}
					}
				}
			}

			token = strtok_s(0, "\n", 0);
		}
		delete[] wholeFile;
	}




}
