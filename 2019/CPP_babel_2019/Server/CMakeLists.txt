project(Server)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

set(CMAKE_BUILD_TYPE Debug)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake
        ./include)
conan_basic_setup()

include_directories(${CMAKE_INCLUDE_PATH} include)
add_executable(Server
    src/Dbcall.cpp
    src/DbComm.cpp
    src/User.cpp
    src/Contact.cpp
    src/tcp_connection.cpp
    src/main.cpp
    )
target_link_libraries(Server ${CONAN_LIBS})
