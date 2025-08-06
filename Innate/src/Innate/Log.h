#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Innate {
	class INNATE_API Log
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

// Core log macros
#define IN_CORE_TRACE(...)   ::Innate::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IN_CORE_INFO(...)    ::Innate::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IN_CORE_WARN(...)    ::Innate::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IN_CORE_ERROR(...)   ::Innate::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IN_CORE_FATAL(...)   ::Innate::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define IN_TRACE(...)   ::Innate::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IN_INFO(...)    ::Innate::Log::GetClientLogger()->info(__VA_ARGS__)
#define IN_WARN(...)    ::Innate::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IN_ERROR(...)   ::Innate::Log::GetClientLogger()->error(__VA_ARGS__)
#define IN_FATAL(...)   ::Innate::Log::GetClientLogger()->fatal(__VA_ARGS__)
