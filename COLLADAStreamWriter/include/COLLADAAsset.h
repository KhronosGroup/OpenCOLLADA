/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#ifndef __COLLADASTREAMWRITER_ASSET_H__
#define __COLLADASTREAMWRITER_ASSET_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"

namespace COLLADA
{


    /** A class to add an Asset to the stream*/

    class Asset : public ElementWriter
    {

    public:
        /** Data related to a contributor that worked on the parent element.*/

        struct Contributor
        {
            String mAuthor;
            String mAuthoringTool;
            String mComments;
            String mCopyright;
            String mSourceData;
        };

        /** Descriptive information about unit of measure. Its optional attributes are:*/

        struct Unit
        {
            /** The name of the unit.*/
            String mName;

            /** The measurement with respect to the meter.*/
            double mMeter;
        };

        /*Descriptive information about the coordinate system
        of the geometric data. All coordinates are righthanded
        by definition. Valid values are X_UP, Y_UP,
        or Z_UP. This element specifies which axis is
        considered upward, which is considered to the
        right, and which is considered inward.*/
        enum UpAxisType
        {
            NONE,
            X_UP,
            Y_UP,
            Z_UP
        };


    private:
        Contributor mContributor;

        /** A list of words used as search criteria for the parent element.*/
        String mKeywords;

        /** Revision information for the parent element.*/
        String mRevision;

        /** A description of the topical subject of the parent element.*/
        String mSubject;

        /** Title information for the parent element.*/
        String mTitle;

        Unit mUnit;

        UpAxisType mUpAxisType;


    public:
        /** Constructor that sets the stream the asset should be written to*/
        Asset ( StreamWriter * streamWriter );

        /** Adds the asset to the stream, i.e. performes the actual writing*/
        void add();

        /** Returns a reference to the contributor of th asset*/
        Contributor & getContributor()
        {
            return mContributor;
        }

        /** Sets the list of words used as search criteria for the parent element.*/
        void setKeywords ( const String & keywords )
        {
            mKeywords = keywords;
        }

        /** Returns a reference to the list of words used as search criteria for the parent element.*/
        const String & getKeywords() const
        {
            return mKeywords;
        }


        /** Sets the revision information for the parent element.*/
        void setRevision ( const String & revision )
        {
            mRevision = revision;
        }

        /** Returns a reference to the revision information for the parent element.*/
        const String & getRevision() const
        {
            return mRevision;
        }

        /** Sets the description of the topical subject of the parent element.*/
        void setSubject ( const String & subject )
        {
            mSubject = subject;
        }

        /** Returns a reference to the description of the topical subject of the parent element.*/
        const String & getSubject() const
        {
            return mSubject;
        }

        /** Sets the title information for the parent element.*/
        void setTitle ( const String & title )
        {
            mTitle = title;
        }

        /** Returns a reference to the title information for the parent element.*/
        const String & getTitle() const
        {
            return mTitle;
        }

        /** Sets the unit used by the document
        @param unit The unit to use.
        */
        void setUnit ( Unit unit )
        {
            mUnit = unit;
        }

        /** Sets the unit used by the document
        @param name The name of the unit to use.
        @param meter The length of one unit in meter, .e.g. 0.0254 for inch.
        */
        void setUnit ( String name, double meter )
        {
            mUnit.mName = name;
            mUnit.mMeter = meter;
        }

        /** Returns the unit*/
        Unit getUnit()
        {
            return mUnit;
        }

        /** Sets the up axis of the document*/
        void setUpAxisType ( UpAxisType upAxisType )
        {
            mUpAxisType = upAxisType;
        }

        /** Returns the up axis*/
        UpAxisType getUpAxisType()
        {
            return mUpAxisType;
        }


    };

} //namespace COLLADA



#endif //__COLLADASTREAMWRITER_ASSET_H__

