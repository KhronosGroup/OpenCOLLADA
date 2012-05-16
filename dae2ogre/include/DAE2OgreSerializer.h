/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

You may alternatively use this source under the terms of a specific version of
the OGRE Unrestricted License provided you have obtained such a license from
Torus Knot Software Ltd.
-----------------------------------------------------------------------------
*/

#ifndef __DAE2OGRE_OGRESERIALIZER_H__
#define __DAE2OGRE_OGRESERIALIZER_H__

#include "DAE2OgrePrerequisites.h"
#include <cstdio>

namespace DAE2Ogre
{

    /** Generic class for serialising data to / from binary stream-based files.
    @remarks
        This class provides a number of useful methods for exporting / importing data
        from stream-oriented binary files (e.g. .mesh and .skeleton).
    @todo replace fputs, fopen etc with std::ifstream functions.
    */

    class OgreSerializer
    {

	public:
		static const size_t STREAM_OVERHEAD_SIZE;
		static const uint16 HEADER_STREAM_ID;
		static const uint16 OTHER_ENDIAN_HEADER_STREAM_ID;

    public:
        OgreSerializer();
        virtual ~OgreSerializer();

        /// The endianness of written files
        enum Endian
        {
            /// Use the platform native endian
            ENDIAN_NATIVE,
            /// Use big endian (0x1000 is serialised as 0x10 0x00)
            ENDIAN_BIG,
            /// Use little endian (0x1000 is serialised as 0x00 0x10)
            ENDIAN_LITTLE
        };


    protected:

        uint32 mCurrentstreamLen;
        FILE* mpfFile;
        std::string mVersion;
        bool mFlipEndian; // default to native endian, derive from header

        // Internal methods
        virtual void writeFileHeader( void );
        virtual void writeChunkHeader( uint16 id, size_t size );

        void writeFloats( const float* const pfloat, size_t count );
        void writeFloats( const double* const pfloat, size_t count );
        void writeShorts( const uint16* const pShort, size_t count );
        void writeInts( const uint32* const pInt, size_t count );
        void writeBools( const bool* const pLong, size_t count );

        void writeString( const std::string& string );
        void writeData( const void* const buf, size_t size, size_t count );

		fpos_t getPos();

		bool setPos(fpos_t pos);

        virtual void flipToLittleEndian( void* pData, size_t size, size_t count = 1 );
        virtual void flipFromLittleEndian( void* pData, size_t size, size_t count = 1 );

        virtual void flipEndian( void * pData, size_t size, size_t count );
        virtual void flipEndian( void * pData, size_t size );

        /// Determine the endianness to write with based on option
        virtual void determineEndianness( Endian requestedEndian );
    };

}


#endif  //__DAE2OGRE_OGRESERIALIZER_H__
