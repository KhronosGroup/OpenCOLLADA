/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef _COLLADA_SHAPEITERATOR_H
#define _COLLADA_SHAPEITERATOR_H

namespace COLLADADomHelper
{
    /** The ShapeIterator is the base class of some iterator that helps traverse over the COLLADA
     BREP DB
    */

    class ShapeIterator
    {
	public:
		enum 
		{
			FORWARD		= 0,
			REVERSED	= 1
		};

    public:
		ShapeIterator();
        /** virtual destructor to avoid warnings*/
        virtual ~ShapeIterator(){};
    
        /** Checks if there are already shapes.
        */
        virtual bool more() = 0;

    protected:
        static bool readDouble( const std::string &str, double &d );
        static bool readNDouble( const std::string &str, const int nD, double* d );
        static bool readNthDouble( const std::string &str, const int nD, double& d );

        static bool readInt( const std::string &str, int &d );
        static bool readNInt( const std::string &str, const int nD, int* d );
        static bool readNthInt( const std::string &str, const int nD, int& d );

        static void trim( std::string& str );
	
	protected:
		bool mValid;

    private:

    };
};

#endif //_COLLADA_EDGEITERATOR_H
