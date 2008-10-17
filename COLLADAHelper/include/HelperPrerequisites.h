#ifndef __COLLADA_HELPER_PREREQUISITES_H__
#define __COLLADA_HELPER_PREREQUISITES_H__

#ifdef WIN32
# ifdef COLLADA_COLLADA_BREP_HELPER_EXPORTS
#  define _HelperExport __declspec(dllexport)
# else
#  define _HelperExport __declspec(dllimport)
# endif
#else
# define _HelperExport
#endif

typedef std::string String;

#endif //__COLLADA_HELPER_PREREQUISITES_H__
