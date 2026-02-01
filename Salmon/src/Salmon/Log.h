#pragma once

#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>

namespace Salmon {

	class SALMON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& CoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& ClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core Log Macros
#define SMN_CORE_FATAL(...) ::Salmon::Log::CoreLogger()->fatal(__VA_ARGS__)
#define SMN_CORE_ERROR(...) ::Salmon::Log::CoreLogger()->error(__VA_ARGS__)
#define SMN_CORE_WARN(...) ::Salmon::Log::CoreLogger()->warn(__VA_ARGS__)
#define SMN_CORE_INFO(...) ::Salmon::Log::CoreLogger()->info(__VA_ARGS__)
#define SMN_CORE_TRACE(...) ::Salmon::Log::CoreLogger()->trace(__VA_ARGS__)


//Client Log Macros
#define SMN_FATAL(...) ::Salmon::Log::ClientLogger()->fatal(__VA_ARGS__)
#define SMN_ERROR(...) ::Salmon::Log::ClientLogger()->error(__VA_ARGS__)
#define SMN_WARN(...) ::Salmon::Log::ClientLogger()->warn(__VA_ARGS__)
#define SMN_INFO(...) ::Salmon::Log::ClientLogger()->info(__VA_ARGS__)
#define SMN_TRACE(...) ::Salmon::Log::ClientLogger()->trace(__VA_ARGS__)
