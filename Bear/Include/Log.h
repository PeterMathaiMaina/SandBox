#pragma once 
#include "Engine.h"
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
namespace Bear {
class Log{
public:
    Log();
    ~Log();
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()    {return s_CoreLogger;}
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger()    {return s_ClientLogger;}
private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger; 
    static std::shared_ptr<spdlog::logger> s_ClientLogger; 

};
}
#define BEAR_CORE_TRACE(...)  ::Bear::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BEAR_CORE_INFO(...)   ::Bear::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BEAR_CORE_WARN(...)   ::Bear::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BEAR_CORE_ERROR(...)  ::Bear::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BEAR_CORE_FATAL(...)  ::Bear::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define BEAR_TRACE(...)  ::Bear::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BEAR_INFO(...)   ::Bear::Log::GetClientLogger()->info(__VA_ARGS__)
#define BEAR_WARN(...)   ::Bear::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BEAR_ERROR(...)  ::Bear::Log::GetClientLogger()->error(__VA_ARGS__)
#define BEAR_FATAL(...)  ::Bear::Log::GetClientLogger()->critical(__VA_ARGS__)
