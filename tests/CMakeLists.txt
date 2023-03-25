#see https://google.github.io/googletest/quickstart-cmake.html
set(CMAKE_CXX_STANDARD 14)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
    AllTests
    AllTests.cpp
    ../src/ICommandBehavior.cpp ../src/OnlyFileBehavior.cpp ../src/Helper.cpp ../src/cnh_structs.cpp
)
target_link_libraries(
    AllTests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AllTests)