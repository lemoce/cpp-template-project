#ifndef __SHARED_H__
#define __SHARED_H__

#ifdef _WIN32
    #ifndef LIBRARY_API_IMPORT
        #define LIBRARY_API __declspec(dllexport)
    #else
        #define LIBRARY_API __declspec(dllimport)
    #endif
#else
    #define LIBRARY_API 
#endif

#endif
