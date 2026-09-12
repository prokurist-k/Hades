add_library(HadesEngine STATIC
    Source/Core/Logging/Log.cpp
    Source/Core/Logging/Sink.cpp
    Source/Utility/Paths.cpp
    Source/Platform/Linux/LinuxPlatformUtils.cpp
)

target_include_directories(HadesEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(HadesEngine PUBLIC cxx_std_20)
