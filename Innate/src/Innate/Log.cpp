#include "Log.h"

namespace Innate {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Color %^, Timestamp %T, name of logger %n, log message %v%$%
		spdlog::set_pattern("%^[%T] %n: %v%$%");

		s_CoreLogger = spdlog::stdout_color_mt("INNATE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}
	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger() { return s_CoreLogger; }
	std::shared_ptr<spdlog::logger>& Log::GetClientLogger() { return s_ClientLogger; }
}

