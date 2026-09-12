#pragma once

// ToDo: Move to definitions
#define HADES_ENABLE_ASSERTS

#ifdef HADES_ENABLE_ASSERTS

#if defined(_MSC_VER)
#define HADES_DEBUGBREAK() __debugbreak()
#elif defined(__GNUC__) || defined(__clang__)
#include <csignal>
#define HADES_DEBUGBREAK() raise(SIGTRAP)
#else
#define HADES_DEBUGBREAK() ((void)0)
#endif

#define HADES_ASSERT(x, ...)                                         \
    {                                                                \
        if (!(x))                                                    \
        {                                                            \
            HADES_LOG(Error, "Assertion failed: %s", ##__VA_ARGS__); \
            HADES_DEBUGBREAK();                                      \
        }                                                            \
    }
#else
#define HADES_ASSERT(x, ...)
#endif
