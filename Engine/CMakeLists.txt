add_library(HadesEngine STATIC
    Source/Core/Timer.cpp
    Source/Core/Logging/Log.cpp
    Source/Core/Logging/Sink.cpp
    Source/Core/Math/HadesMath.cpp
    Source/Core/Math/Vector3.cpp
    Source/Engine/Engine.cpp
    Source/EngineLoop/EngineLoop.cpp
    Source/Platform/Linux/LinuxPlatformUtils.cpp
    Source/Utility/Paths.cpp
)

target_include_directories(HadesEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(HadesEngine PUBLIC cxx_std_20)
