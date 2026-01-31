#pragma once

#ifdef SMN_PLATFORM_WINDOWS
	#ifdef SMN_BUILD_DLL
		#define SALMON_API __declspec(dllexport)
	#else
		#define SALMON_API __declspec(dllimport)
	#endif
#else
	#error Salmon only supports Windows atm.
#endif