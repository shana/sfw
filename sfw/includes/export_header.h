#pragma once

#ifdef WIN32PROJECT1_EXPORTS
#define SFW_EXPORT_API extern "C" __declspec(dllexport)
#else
#define SFW_EXPORT_API __declspec(dllimport)
#endif