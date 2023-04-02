cmake -Bdebug -DCMAKE_BUILD_TYPE=Debug
cmake --build debug
pushd ./debug/tests
ctest
popd