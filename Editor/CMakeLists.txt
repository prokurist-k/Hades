find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)

file(GLOB_RECURSE HADES_EDITOR_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Source/Viewport*.cpp)

add_executable(HadesEditor ${HADES_EDITOR_SOURCES})

target_link_libraries(HadesEditor PRIVATE HadesEngine Qt6::Widgets Qt6::OpenGLWidgets)

target_compile_features(HadesEditor PUBLIC cxx_std_20)

set_target_properties(HadesEditor PROPERTIES AUTOMOC ON)
