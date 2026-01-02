#include "../../Include/Log.h"
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>


namespace Bear{
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

Log::Log(){

}
Log::~Log(){


}
void Log::Init(){
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%n] %v");


    auto console_sink_client = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto console_sink_core   = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    s_ClientLogger = std::make_shared<spdlog::logger>("SandBox", console_sink_client);
    s_CoreLogger   = std::make_shared<spdlog::logger>("Bear", console_sink_core);

    spdlog::register_logger(s_ClientLogger);
    spdlog::register_logger(s_CoreLogger);

    s_ClientLogger->set_level(spdlog::level::trace);
    s_CoreLogger->set_level(spdlog::level::trace);
}
}
