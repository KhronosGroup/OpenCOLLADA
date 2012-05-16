#include "MathMLSolverStableHeaders.h"
#include "MathMLString.h"

#ifdef _WIN32
# include <windows.h>
#endif

namespace MathML
{
    //-----------------------------------------------------------------------
    String::size_type StringUtil::lastIndexOf( const String& str, const String& pattern )
    {
        String::size_type pos = String::npos;

        for ( String::size_type i = str.find( pattern );
                i != std::string::npos;
                i = str.find( pattern, i + 1 )
            )
        {
            pos = i;
        }

        return pos;
    }

    //-----------------------------------------------------------------------
    String::size_type StringUtil::lastIndexOf( const String& str, const char character )
    {
        String::size_type pos = String::npos;

        for ( String::size_type i = str.find( character );
                i != std::string::npos;
                i = str.find( character, i + 1 )
            )
        {
            pos = i;
        }

        return pos;
    }

    //-----------------------------------------------------------------------
    bool StringUtil::startsWith( const String& str, const String& pattern )
    {
        String::size_type pos = str.find( pattern );
        return pos == 0 ? true : false;
    }

    //-----------------------------------------------------------------------
    bool StringUtil::startsWith( const String& str, char character )
    {
        String::size_type pos = str.find( character );
        return pos == 0 ? true : false;
    }

    //-----------------------------------------------------------------------
    bool StringUtil::endsWith( const String& str, const String& pattern )
    {
        String::size_type pos = str.find( pattern );

        if ( pos == String::npos )
            return false;

        return pos == ( str.size() - pattern.size() ) ? true : false;
    }

    //-----------------------------------------------------------------------
    bool StringUtil::endsWith( const String& str, char character )
    {
        String::size_type pos = str.find( character );
        return pos == ( str.size() - 1 ) ? true : false;
    }

    //-----------------------------------------------------------------
    String StringUtil::replaceAll( const String& str, char character, const String& replacement )
    {
        String string = str;
        String::size_type position = string.find_last_of( character );

        while ( position != String::npos )
        {
            string.replace( position, 1, replacement );
            position = string.find_last_of( character );
        }

        return string;
    }

    //-----------------------------------------------------------------
    String StringUtil::replaceAll( const String& str, const String& pattern, const String& replacement )
    {
        String string = str;

        size_t position = string.find( pattern );

        while ( position != String::npos )
        {
            string.replace( position, pattern.size(), replacement );
            position = string.find( pattern );
        }

        return string;
    }

    //-----------------------------------------------------------------
    String StringUtil::replaceAll( const String& str, const String& pattern, char replacement )
    {
        String replaceStr;
        replaceStr += replacement;
        return replaceAll( str, pattern, replaceStr );
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::replaceAll( const String& str, char pattern, char replacement )
    {
        String string = str;

        size_t position = string.find( pattern );

        while ( position != String::npos )
        {
            string[ position ] = replacement;
            position = string.find( pattern );
        }

        return string;
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( unsigned char value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( unsigned short value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( unsigned int value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( unsigned long value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( unsigned long long value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( char value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( short value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( int value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( long value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( long long value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( float value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    MathML::String StringUtil::valueOf( double value )
    {
        std::stringstream ss;
        ss << value << std::ends;
        return ss.str();
    }

    //-----------------------------------------------------------------------
    int StringUtil::caseCompare( const String& str1, const String& str2 )
    {
        String tmp1( str1 );
        toLowerCase( tmp1 );
        String tmp2( str2 );
        toLowerCase( tmp2 );

        return tmp1.compare( str2 );

    }

    //-----------------------------------------------------------------------
    void StringUtil::toLowerCase( String& str )
    {
        std::transform(
            str.begin(),
            str.end(),
            str.begin(),
            tolower );
    }

    //-----------------------------------------------------------------------
    void StringUtil::toUpperCase( String& str )
    {
        std::transform(
            str.begin(),
            str.end(),
            str.begin(),
            toupper );
    }

    //-----------------------------------------------------------------------
    unsigned short StringUtil::parseUnsignedShort( const String& str )
    {
        unsigned short value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------------
    unsigned int StringUtil::parseUnsignedInt( const String& str )
    {
        unsigned int value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------------
    unsigned long StringUtil::parseUnsignedLong( const String& str )
    {
        unsigned long value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------------
    short StringUtil::parseShort( const String& str )
    {
        short value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------------
    int StringUtil::parseInt( const String& str )
    {
        int value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------------
    long StringUtil::parseLong( const String& str )
    {
        long value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------------
    double StringUtil::parseDouble( const String& str )
    {
        double value;
        std::istringstream inStream( str );
        inStream >> value;
        return value;
    }

    //-----------------------------------------------------------------
    String StringUtil::removeWhitespaces( const String &string )
    {
        String whitespaces ( " \t\f\v\n\r" );
        String result = string;

        String::size_type found = string.find_first_of( whitespaces );

        while ( found != String::npos )
        {
            result.erase( found, 1 );
            found = result.find_first_of( whitespaces );
        }

        return result;
    }

    //-----------------------------------------------------------------
    MathML::String StringUtil::valueOfUnfinalized( int value )
    {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
}
