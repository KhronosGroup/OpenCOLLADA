/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#include "COLLADAAsset.h"
#include "COLLADASWC.h"

#include <sstream>
#include <time.h>


namespace COLLADA
{

    //---------------------------------------------------------------
    Asset::Asset ( StreamWriter * streamWriter )
            : ElementWriter ( streamWriter ),
            mUpAxisType ( NONE )
    {}


    //---------------------------------------------------------------
    void Asset::add()
    {
        TagCloser asset = mSW->openElement ( CSWC::COLLADA_ELEMENT_ASSET );

        // add contributor only if at least one attribute is not empty

        if ( !mContributor.mAuthor.empty()   ||
                !mContributor.mAuthoringTool.empty() ||
                !mContributor.mComments.empty()  ||
                !mContributor.mCopyright.empty()  ||
                !mContributor.mSourceData.empty()
           )
        {
            TagCloser contributor = mSW->openElement ( CSWC::COLLADA_ELEMENT_CONTRIBUTOR );

            if ( !mContributor.mAuthor.empty() )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_AUTHOR, mContributor.mAuthor );

            if ( !mContributor.mAuthoringTool.empty() )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_AUTHORING_TOOL, mContributor.mAuthoringTool );

            if ( !mContributor.mComments.empty() )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_COMMENTS, mContributor.mComments );

            if ( !mContributor.mCopyright.empty() )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_COPYRIGHT, mContributor.mCopyright );

            if ( !mContributor.mSourceData.empty() )
                mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_SOURCE_DATA, mContributor.mSourceData );

            contributor.close();
        }


        // create a stringstream containing the current date and time in ISO 8601 format
        std::stringstream curDate;

        time_t _t;

        time ( &_t );

        struct tm *t = localtime ( &_t );

        curDate << t->tm_year + 1900 << "-" << ( t->tm_mon < 9 ? "0" : "" ) << t->tm_mon + 1
        << "-" << ( t->tm_mday <= 9 ? "0" : "" ) << t->tm_mday
        << "T" << ( t->tm_hour <= 9 ? "0" : "" ) << t->tm_hour
        << ":" << ( t->tm_min <= 9 ? "0" : "" ) << t->tm_min
        << ":" << ( t->tm_sec <= 9 ? "0" : "" ) << t->tm_sec << "Z";


        mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_CREATED, curDate.str() );


        if ( !mKeywords.empty() )
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_KEYWORDS, mKeywords );

        mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_MODIFIED, curDate.str() );

        if ( !mRevision.empty() )
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_REVISION, mRevision );

        if ( !mSubject.empty() )
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_SUBJECT, mSubject );

        if ( !mTitle.empty() )
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_TITLE, mTitle );

        mSW->openElement ( CSWC::COLLADA_ELEMENT_UNIT );

        if ( !mUnit.mName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, mUnit.mName );

        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_METER, mUnit.mMeter );

        mSW->closeElement();

        switch ( mUpAxisType )
        {

        case X_UP :
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_UP_AXIS, CSWC::COLLADA_TEXT_X_UP );
            break;

        case Y_UP :
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_UP_AXIS, CSWC::COLLADA_TEXT_Y_UP );
            break;

        case Z_UP :
            mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_UP_AXIS, CSWC::COLLADA_TEXT_Z_UP );
            break;
        }

        asset.close();

    }

} //namespace COLLADA


