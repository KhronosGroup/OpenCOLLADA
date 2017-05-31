#pragma once

#if defined(__GNUC__)
#define IS_GNUC_AND_GNUC_VERSION_LT(major,minor,patch_level) (__GNUC__ < major || (__GNUC__ == major && (__GNUC_MINOR__ < minor || (__GNUC_MINOR__ == minor && __GNUC_PATCHLEVEL__ < patch_level))))
#else
#define IS_GNUC_AND_GNUC_VERSION_LT(major,minor,patch_level) 0
#endif

#if defined(_MSC_VER)
#define IS_MSVC_AND_MSVC_VERSION_LT(version) (_MSC_VER < version)
#define IS_MSVC_AND_MSVC_VERSION_GTE(version) (_MSC_VER >= version)
#else
#define IS_MSVC_AND_MSVC_VERSION_LT(version) 0
#define IS_MSVC_AND_MSVC_VERSION_GTE(version) 0
#endif