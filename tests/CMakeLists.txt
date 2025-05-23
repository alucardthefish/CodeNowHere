#see https://google.github.io/googletest/quickstart-cmake.html
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# we dont want to install gtest see https://github.com/google/googletest/blob/main/CMakeLists.txt
set(INSTALL_GTEST OFF)

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
    ../src/ICommandBehavior.cpp ../src/OnlyFileBehavior.cpp ../src/Helper.cpp ../src/cnh_structs.cpp ../src/injawrap.cpp ../src/cnhengine.cpp
)
target_link_libraries(
    AllTests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AllTests)
