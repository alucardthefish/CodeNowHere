cmake -Bbuild
cmake --build build --config=Debug
ctest --test-dir ./build/tests