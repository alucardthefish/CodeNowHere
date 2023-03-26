set(project "cnh")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BunchFileBehavior.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CodeNowHere.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Helper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ICommandBehavior.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ManyFileBehavior.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OnlyFileBehavior.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cnh_structs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/docopt.cpp
)
add_executable(cnh ${${project}_SOURCES} )
install(TARGETS cnh)
