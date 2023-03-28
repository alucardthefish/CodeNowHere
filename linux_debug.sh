cmake -Bdebug -DCMAKE_BUILD_TYPE=Debug
cmake --build debug
ctest --test-dir ./debug/tests