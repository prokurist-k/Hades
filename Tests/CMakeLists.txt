include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
# Verhindert, dass GTest seine eigenen Compiler-Flags/Settings global überschreibt
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE HADES_TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(HadesTests ${HADES_TEST_SOURCES})

target_link_libraries(HadesTests PRIVATE HadesEngine GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(HadesTests)
