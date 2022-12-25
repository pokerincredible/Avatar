#pragma once

#ifdef AR_PLATFORM_WINDOWS
	#ifdef AR_BUILD_DLL
		#define AR_API __declspec(dllexport)
	#else
		#define AR_API __declspec(dllimport)
	#endif // AR_BUILD_DLL
#else
	#error Avatar only support Windows!
#endif // AR_PLATFORM_WINDOWS
