#pragma once

#ifdef _WIN32
#define EXPORT __declspec(dllexport)

#define strcpy strcpy_s
#else
#define EXPORT
#endif