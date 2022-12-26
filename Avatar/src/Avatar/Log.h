#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"


namespace AR{
	class AR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define AR_CORE_TRACE(...)			::AR::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AR_CORE_INFO(...)			::AR::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AR_CORE_WARN(...)			::AR::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AR_CORE_ERROR(...)			::AR::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AR_CORE_FATAL(...)			::AR::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core APP Macros
#define AR_TRACE(...)		::AR::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AR_INFO(...)			::AR::Log::GetClientLogger()->info(__VA_ARGS__)
#define AR_WARN(...)			::AR::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AR_ERROR(...)		::AR::Log::GetClientLogger()->error(__VA_ARGS__)
#define AR_FATAL(...)		::AR::Log::GetClientLogger()->fatal(__VA_ARGS__)