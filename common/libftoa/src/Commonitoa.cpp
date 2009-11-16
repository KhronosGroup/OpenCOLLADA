/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libftoa.
    
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "Commonitoa.h"

namespace Common
{

    size_t itoa( signed char value       , char* buffer, unsigned char radix) { return itoaImplSigned<signed char      >( value, buffer, radix );}
    size_t itoa( unsigned char value     , char* buffer, unsigned char radix) { return itoaImpl<unsigned char          >( value, buffer, radix );}
    size_t itoa( signed short value      , char* buffer, unsigned char radix) { return itoaImplSigned<signed short     >( value, buffer, radix );}
    size_t itoa( unsigned short value    , char* buffer, unsigned char radix) { return itoaImpl<unsigned short         >( value, buffer, radix );}
    size_t itoa( signed int value        , char* buffer, unsigned char radix) { return itoaImplSigned<signed int       >( value, buffer, radix );}
    size_t itoa( unsigned int value      , char* buffer, unsigned char radix) { return itoaImpl<unsigned int           >( value, buffer, radix );}
    size_t itoa( signed long value       , char* buffer, unsigned char radix) { return itoaImplSigned<signed long      >( value, buffer, radix );}
    size_t itoa( unsigned long value     , char* buffer, unsigned char radix) { return itoaImpl<unsigned long          >( value, buffer, radix );}
    size_t itoa( signed long long value  , char* buffer, unsigned char radix) { return itoaImplSigned<signed long long >( value, buffer, radix );}
    size_t itoa( unsigned long long value, char* buffer, unsigned char radix) { return itoaImpl<unsigned long long     >( value, buffer, radix );}

}