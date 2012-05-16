/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_OPTIONS_H__
#define __COLLADAMAX_OPTIONS_H__

#include "COLLADAMaxPrerequisites.h"

#include "maxtypes.h"

namespace COLLADAMax
{


    /** A class that stores all the options available for the export.
    */

    class Options
    {

	public:
		static const String CONFIGURATION_FILE_NAME;
		static const String CONFIGURATION_HEADER_NAME;

		static const String OPTION_NORMALS_NAME;
		static const String OPTION_TRIANGULAT_NAME;
		static const String OPTION_XREFS_NAME;
		static const String OPTION_TANGENTS_NAME;
		static const String OPTION_ANIMATIONS_NAME;
		static const String OPTION_SAMPLEANIMATIONS_NAME;
		static const String OPTION_CREATECLIP_NAME;
		static const String OPTION_BAKEMATRICES_NAME;
		static const String OPTION_RELATIVEPATHS_NAME;
		static const String OPTION_CHECKIFANIMATIONISANIMATED_NAME;
		static const String OPTION_ANIMATIONSTART_NAME;
		static const String OPTION_ANIMATIONEND_NAME;
		static const String OPTION_COPY_IMAGES_NAME;
		static const String OPTION_EXPORT_USERDEFINED_PROPERTIES_NAME;


	private:
		// options dialog state
		Interface* mMaxInterface;
		bool mNormals;						//!< export normals
		bool mTriangulate;					//!< convert Editable Polygons to triangles
		bool mIncludeXrefs;					//!< export external references
		bool mTangents;						//!< export tangents and binormals
		bool mAnimations;					//!< export animations;
		bool mSampleAnimation;				//!< export sampled animation
		bool mCreateClip;					//!< create one animation clip with all the animations of the scene
		bool mBakeMatrices;					//!< export transforms as matrices
		bool mRelativePaths;				//!< export relative paths
		bool mCopyImages;			     	//!< copy images
		String mImageDirectory;			    //!< The directory of the copied images, relative to the output file
		bool importUnits;					//!< import assets in their units
		bool importUpAxis;					//!< import assets in their up-axis
		bool mCheckIfAnimationIsAnimated;   //!< export animations only if it is really animated (time consuming)
		TimeValue mAnimationStart;			//!< start sample TimeValue(frame * GetTicksPerFrame)
		TimeValue mAnimationEnd;			//!< end sample TimeValue  (frame * GetTicksPerFrame)
		bool mSelectionOnly;				//!< export only selected nodes/objects
		String mXRefOutputDir;              //!< The directory where all the xref scenes should be exported to

		bool mExportUserDefinedProperties;	//!< export user defined properties

	
	public:
        /** Constructor*/
        Options(Interface* maxInterface);

        /** Destructor*/
        ~Options()
        {}

        // Displays the exporter options dialog to allow the user to change the options.
        //bool ShowDialog(bool exporter);

        /** Returns if the normals are exported */
        bool getExportNormals() const
        {
            return mNormals;
        }

        /** Returns, if the editable polygons are exported as triangles.*/
        bool getExportEPolyAsTriangles() const  { return mTriangulate; }

        /** Returns, if XRef are exported.*/
        bool getIncludeXRefs() const { return mIncludeXrefs; }

        /** Returns, if tangents are exported.*/
        bool getExportTangents() const { return mTangents; }

        /** Returns, if animations are exported.*/
        bool getExportAnimations() const { return mAnimations; }

        /** Returns, if animations are sampled.*/
        bool getSampleAnimation() const { return mSampleAnimation; }

        /** Returns, if an animation clip is exported.*/
        bool getExportAnimClip() const { return mCreateClip; }

        /** Returns, if the transformations are exported as matrices.*/
        bool getBakeMatrices() const { return mBakeMatrices; }

		/** Returns, if paths are exported as relative paths.*/
		bool getExportRelativePaths() const { return mRelativePaths; }

		/** Returns, if images should be copied.*/
		bool getCopyImages() const { return mCopyImages; }

		/** The directory of the copied images, relative to the output file.*/
		String getImageDirectory() const { return mImageDirectory; }


		/** Returns, if animations are checked if they are really animated*/
		bool getCheckIfAnimationsIsAnimated() const { return mCheckIfAnimationIsAnimated;}


        /** Returns if only the selected parts are exported.*/
        bool getExportSelected() const { return mSelectionOnly; }

        /** Returns the animation start time.*/
        TimeValue getAnimationStart() const { return mAnimationStart; }

        /** Returns the animation end time.*/
        TimeValue getAnimationEnd() const { return mAnimationEnd; }

		/** Returns the directory where the XRef files should be exported to.*/
		const String& getXRefOutputDir() const { return mXRefOutputDir; }

		/** Change the animation start/end for sampling*/
		void setAnimBounds(int start, int end) { mAnimationStart = start; mAnimationEnd = end; }

		/** Returns if user defined properties are exported.*/
		bool getExportUserDefinedProperties() const { return mExportUserDefinedProperties; }

		bool ShowDialog();

		INT_PTR ExportOptionsDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		static INT_PTR CALLBACK ExportOptionsDlgProcS(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


		/** Save the export options to an .ini file, located in the APP_PLUGCFG_DIR directory*/
		void SaveOptions();

		void LoadOptions();

    };

}


#endif //__COLLADAMAX_OPTIONS_H__
