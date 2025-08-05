#pragma once

// Macro
#ifdef IN_PLATFORM_WINDOWS
	#ifdef IN_BUILD_DLL
		#define INNATE_API __declspec(dllexport)
	#else
		#define INNATE_API __declspec(dllimport)
	#endif
#else
	#error Innate only supports Windows!
#endif