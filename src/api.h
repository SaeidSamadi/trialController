#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define TrialController_DLLIMPORT __declspec(dllimport)
#  define TrialController_DLLEXPORT __declspec(dllexport)
#  define TrialController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define TrialController_DLLIMPORT __attribute__((visibility("default")))
#    define TrialController_DLLEXPORT __attribute__((visibility("default")))
#    define TrialController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define TrialController_DLLIMPORT
#    define TrialController_DLLEXPORT
#    define TrialController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef TrialController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define TrialController_DLLAPI
#  define TrialController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef TrialController_EXPORTS
#    define TrialController_DLLAPI TrialController_DLLEXPORT
#  else
#    define TrialController_DLLAPI TrialController_DLLIMPORT
#  endif // TrialController_EXPORTS
#  define TrialController_LOCAL TrialController_DLLLOCAL
#endif // TrialController_STATIC