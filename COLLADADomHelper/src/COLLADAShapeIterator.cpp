/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAShapeIterator.h"

namespace COLLADADomHelper
{
	ShapeIterator::ShapeIterator()
		: mValid(true)
	{

	}
    //-----------------------------------------------------------------------
    bool ShapeIterator::readDouble( const std::string &str, double &d )
    {
        bool bRet = false;

        if ( str.length() > 0 )
        {
            d = atof( str.c_str() );
            bRet = true;
        }

        return bRet;
    }

    //-----------------------------------------------------------------------
    bool ShapeIterator::readNDouble( const std::string &str, const int nD, double *d )
    {
        bool bRet = true;

        size_t space = str.find_last_of( " " );

        if ( nD > 1 )
        {
            bRet |= readNDouble( str.substr( 0, space ), nD - 1, d );
        }

        bRet |= readDouble( str.substr( space + 1 ), d[ nD - 1 ] );

        return bRet;
    }

    //-----------------------------------------------------------------------
    bool ShapeIterator::readNthDouble( const std::string &str, const int nD, double &d )
    {
        bool bRet = false;

        std::string copy = str;
        trim( copy );
        copy += " ";

        size_t space = std::string::npos;
		size_t last = std::string::npos;

        for ( int i = 0; i < nD; i++ )
        {
            if ( space != std::string::npos )
                last = space;

            space = copy.find( " ", last + 1 );
        }

		if ( last == std::string::npos && space >= 0 && space != std::string::npos)
		{
			bRet = readDouble( str.substr( 0, space ), d );
		}
		else if (space > last && space != std::string::npos)
        {
            bRet = readDouble( str.substr( last + 1, space - last - 1 ), d );
        }

        //else if (last > -1)
        // bRet = readDouble(str.substr(last + 1), d);
        return bRet;
    }

    //-----------------------------------------------------------------------
    bool ShapeIterator::readInt( const std::string &str, int &d )
    {
        bool bRet = false;

        if ( str.length() > 0 )
        {
            d = atoi( str.c_str() );
            bRet = true;
        }

        return bRet;
    }

    //-----------------------------------------------------------------------
    bool ShapeIterator::readNInt( const std::string &str, const int nD, int *d )
    {
        bool bRet = true;

        size_t space = str.find_last_of( " " );

        if ( nD > 1 )
        {
            bRet |= readNInt( str.substr( 0, space ), nD - 1, d );
        }

        bRet |= readInt( str.substr( space + 1 ), d[ nD - 1 ] );

        return bRet;
    }

    //-----------------------------------------------------------------------
    bool ShapeIterator::readNthInt( const std::string &str, const int nD, int &d )
    {
        bool bRet = false;

        std::string copy = str;
        trim( copy );
        copy += " ";

		size_t space = std::string::npos;
        size_t last = std::string::npos;

        for ( int i = 0; i < nD; i++ )
        {
			if ( space != std::string::npos )
                last = space;

            space = copy.find( " ", last + 1 );
        }

		if ( last == std::string::npos && space >= 0 && space != std::string::npos)
		{
			bRet = readInt( str.substr( 0, space ), d );
		}
		else if (space > last && space != std::string::npos)
        {
            bRet = readInt( str.substr( last + 1, space - last - 1 ), d );
        }

        //else if (last > -1 && space > -1)
        // bRet = readInt(str.substr(last + 1), d);
        return bRet;
    }

    //-----------------------------------------------------------------------
    void ShapeIterator::trim( std::string& str )
    {
        std::string::size_type pos = str.find_last_not_of( ' ' );

        if ( pos != std::string::npos )
        {
            str.erase( pos + 1 );
            pos = str.find_first_not_of( ' ' );

            if ( pos != std::string::npos )
                str.erase( 0, pos );
        }

        else
            str.erase( str.begin(), str.end() );
    }


}
