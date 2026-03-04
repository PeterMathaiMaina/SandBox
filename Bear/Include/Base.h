#pragma once
#include <memory>
#include <sstream>
#include <string>
namespace Bear {}

template <typename T> using Scope = std::unique_ptr<T>;

#if defined(_WIN32)
#define PLATFORM_WINDOWS
#elif defined(__linux__)
#define PLATFORM_LINUX
#elif defined(__APPLE__)
#define PLATFORM_MAC
#else
#error "Unknown platform!"
#endif

template <typename T, typename... Args>
constexpr Scope<T> CreateScope(Args &&...args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

#define BIT(x) (1 << x)
