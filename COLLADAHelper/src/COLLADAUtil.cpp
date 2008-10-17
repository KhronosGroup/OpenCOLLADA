#include "HelperStableHeaders.h"
#include "COLLADAUtil.h"

namespace COLLADA
{

	//----------------------------------------------------------------
	//Reduced whitelist for NCName:
	// "_-.[0-9][A-Z][a-z]"
	// correct pattern of NCName is: [\i-[:]][\c-[:]]*
	// \i : NameCharStart (see: http://www.w3.org/TR/xml11/#NT-NameStartChar)
	// \c : NameChar (see: http://www.w3.org/TR/xml11/#NT-NameChar)
	//----------------------------------------------------------------
	std::string checkNCName(const std::string &ncName)
	{
		std::string copy = ncName;
		std::string::size_type size = copy.size();
		for (std::string::size_type i=0; i<size; ++i)
		{
			char c = copy[i];
			if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '-' || c == '.' )
			{
				continue;
			}
			copy.replace(i, 1, 1, '_');
		}

		if ( (copy[0] < 'a' || copy[0] > 'z') 
			&& (copy[0] < 'A' || copy[0] > 'Z')
			&& copy[0] != '_')
			copy.insert(copy.begin(), 1, '_');
        
		return copy;
	}

	std::string checkID( const std::string &id )
	{
		return checkNCName(id);
	}
}