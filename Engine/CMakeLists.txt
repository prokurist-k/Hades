add_library(HadesEngine STATIC
    Source/Globals.h
    Source/Globals.cpp
    Source/Core/Timer.cpp
    Source/Core/Logging/Log.cpp
    Source/Core/Logging/Sink.cpp
    Source/Core/Math/HadesMath.cpp
    Source/Core/Math/Matrix3x3.cpp
    Source/Core/Math/Matrix4x4.cpp
    Source/Core/Math/Vector2.cpp
    Source/Core/Math/Vector3.cpp
    Source/Core/Math/Vector4.cpp
    Source/Engine/Engine.cpp
    Source/EngineLoop/EngineLoop.cpp
    Source/Platform/Keyboard.h
    Source/Platform/Keyboard.cpp
    Source/Platform/Linux/LinuxPlatformUtils.cpp
    Source/Platform/Linux/LinuxWindow.cpp
    Source/Utility/Paths.cpp
)

find_package(X11 REQUIRED)

target_link_libraries(HadesEngine
    PRIVATE
        X11::X11
)

target_include_directories(HadesEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(HadesEngine PUBLIC cxx_std_20)
