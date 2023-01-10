#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"


namespace VE{
	VE_API std::shared_ptr<spdlog::logger>;
	class VE_API Log
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
#define VE_CORE_TRACE(...)			::VE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VE_CORE_INFO(...)			::VE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VE_CORE_WARN(...)			::VE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VE_CORE_ERROR(...)			::VE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VE_CORE_FATAL(...)			::VE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core APP Macros
#define VE_TRACE(...)				::VE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VE_INFO(...)				::VE::Log::GetClientLogger()->info(__VA_ARGS__)
#define VE_WARN(...)				::VE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VE_ERROR(...)				::VE::Log::GetClientLogger()->error(__VA_ARGS__)
#define VE_FATAL(...)				::VE::Log::GetClientLogger()->fatal(__VA_ARGS__)