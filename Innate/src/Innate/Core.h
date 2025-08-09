#pragma once

// Macro
//#if defined(_WIN64)
//	#define IN_PLATFORM_WINDOWS
//#elif defined(__linux__)
//	#define IN_PLATFORM_LINUX
//#else
//	#error "Unknow platform!"
//#endif


// Macro
#ifdef IN_PLATFORM_WINDOWS
	#ifdef IN_BUILD_DLL
		#define INNATE_API __declspec(dllexport)
	#else
		#define INNATE_API __declspec(dllimport)
	#endif
#elif defined(IN_PLATFORM_LINUX)
	#ifdef IN_LINUX_SHARE
		// Building shared object on Linux/macOS
		#define INNATE_API __attribute__((visibility("default")))
	#else
		// use shared object - no special attribute needed
       		#define INNATE_API
	#endif
#else
	// error
	#error "No valid platform macro defined! Define IN_PLATFORM_WINDOWS or IN_PLATFORM_LINUX"
#endif
