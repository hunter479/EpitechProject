project(Babel)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)

include_directories(
  "./include/"
  "./include/Sound/"
  "./include/Sound/Opus/"
  "./include/Sound/PortAudio/"
  ${CMAKE_INCLUDE_PATH}
)

set(SRCS
    ./src/main.cpp
    ./src/server.cpp
    ./src/callState.cpp
    ./src/mainwindow.cpp
    ./src/mainwindow.ui
    ./src/User.cpp

    ./src/Sound/SoundManager.cpp
    ./src/Sound/CallManager.cpp
    ./src/Sound/Opus.cpp
    ./src/Sound/PortAudioM.cpp
    ./src/Sound/SoundInput.cpp
    ./src/Sound/SoundOutput.cpp

)

set(HEADERS
    ./include/server.h
    ./include/Serial.hpp
    ./include/mainwindow.h
    ./include/ui_mainwindow.h
    ./include/peerTopeer_rfc.h
    ./include/Serial.hpp

    ./include/Sound/Opus/Opus.hpp

    ./include/Sound/PortAudio/IDataFlow.hpp
    ./include/Sound/PortAudio/PortAudioM.hpp
    ./include/Sound/PortAudio/Sound.hpp
    ./include/Sound/PortAudio/SoundInput.hpp
    ./include/Sound/PortAudio/SoundOutput.hpp

    ./include/Sound/CallManager.hpp
    ./include/Sound/ICodec.hpp
    ./include/Sound/ISoundDevice.hpp
    ./include/Sound/SoundManager.hpp

    ./include/Serial.hpp
    ./include/User.hpp
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(babel ${SRCS} ${HEADERS})
target_link_libraries(babel ${CONAN_LIBS} Qt5::Widgets Qt5::Network)
target_compile_options(babel PUBLIC -std=gnu++11 -Wall -g)
