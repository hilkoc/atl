#pragma once

//Include these definitins in all headers that need to be exported from the dll.
//Definitions for exporting
#if defined(_WIN32) || defined(__WIN32__)
#  if defined(ALGEBRA_VSPROJECT_EXPORTS) // define with CMake or other build tool (visual studio)
#    define  API_EXPORT  __declspec(dllexport)
#  else
#    define  API_EXPORT __declspec(dllimport)
#  endif //defined(SIMPLESHAREDLIB_EXPORTS)
#elif defined(linux) || defined(__linux)
#  define API_EXPORT
#endif //defined(linux)