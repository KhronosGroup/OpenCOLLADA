#include "HelperStableHeaders.h"
#include "COLLADAException.h"

//#include "CPFLogManager.h"

namespace COLLADADomHelper
{
    //-----------------------------------------------------------------------
    Exception::Exception( int num, const String& desc, const String& src ) :
            mLine( 0 ),
            mNumber( num ),
            mDescription( desc ),
            mSource( src )
    {
        // Log this error - not any more, allow catchers to do it
        //LogManager::getSingleton().logMessage(this->getFullDescription());
    }

    //-----------------------------------------------------------------------
    Exception::Exception( int num, const String& desc, const String& src,
                          const char* typ, const char* fil, long lin ) :
            mLine( lin ),
            mNumber( num ),
            mTypeName( typ ),
            mDescription( desc ),
            mSource( src ),
            mFile( fil )
    {
        // Log this error, mask it from debug though since it may be caught and ignored

//         if ( LogManager::getSingletonPtr() )
//         {
//             LogManager::getSingleton().logMessage(
//                 this->getFullDescription(),
//                 LML_CRITICAL, true );
//         }

    }

    //-----------------------------------------------------------------------
    Exception::Exception( const Exception& rhs )
            : mLine( rhs.mLine ), mNumber( rhs.mNumber ), mDescription( rhs.mDescription ), mSource( rhs.mSource ), mFile( rhs.mFile )
    {}

    //-----------------------------------------------------------------------
    void Exception::operator = ( const Exception& rhs )
    {
        mDescription = rhs.mDescription;
        mNumber = rhs.mNumber;
        mSource = rhs.mSource;
        mFile = rhs.mFile;
        mLine = rhs.mLine;
        mTypeName = rhs.mTypeName;
    }

    //-----------------------------------------------------------------------
    const String& Exception::getFullDescription( void ) const
    {
        if ( mFullDesc.empty() )
        {

            std::stringstream desc;

            desc << "CPF EXCEPTION(" << mNumber << ":" << mTypeName << "): "
            << mDescription
            << " in " << mSource;

            if ( mLine > 0 )
            {
                desc << " at " << mFile << " (line " << mLine << ")";
            }

            mFullDesc = desc.str();
        }

        return mFullDesc;
    }

    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    int Exception::getNumber( void ) const throw()
    {
        return mNumber;
    }

    //-----------------------------------------------------------------------
    const char* Exception::what() const throw()
    {
        return getFullDescription().c_str();
    }
}

