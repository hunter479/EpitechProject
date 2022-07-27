# EPITECH PROJECT, 2019
# HERE
# File description:
# cmake configuration file for the project

cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0054 NEW)

project(bomberman)

#WINDOWS
############################
IF (MSVC)
  set(CMAKE_MODULE_PATH "C:/Users/$31V000-DGNFCGQDCPB0/Desktop/irrlicht-1.8.4")
  set(Irrlicht_DIR "C:/Users/$31V000-DGNFCGQDCPB0/Desktop/irrlicht-1.8.4/lib/Win32-visualstudio")

  set(CMAKE_SFML_PATH "C:/Users/$31V000-DGNFCGQDCPB0/Desktop/SFML-2.4.2")
  set(SFML_ALL_INCLUDES_DIRS "C:/Users/$31V000-DGNFCGQDCPB0/Desktop/SFML-2.4.2/include")
ENDIF (MSVC)
############################

IF (NOT Irrlicht_INCLUDE_DIRS OR NOT Irrlicht_LIBRARIES)
  FIND_PATH(Irrlicht_INCLUDE_DIRS
    NAMES
      irrlicht.h
    PATHS
      /usr/include/irrlicht/          # Default Fedora28 system include path
      /usr/include/irrlicht/include   # Default Fedora28 system include path
      ${CMAKE_MODULE_PATH}/include/   # Expected to contain the path to this file for Windows10
      ${Irrlicht_DIR}/include/        # Irrlicht root directory (if provided)
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(Irrlicht_LIBRARIES
    NAMES
      Irrlicht
    PATHS
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library path
      ${CMAKE_MODULE_PATH}/         # Expected to contain the path to this file for Windows10
      ${Irrlicht_DIR}/              # Irrlicht root directory (if provided)
  )
ENDIF (NOT Irrlicht_INCLUDE_DIRS OR NOT Irrlicht_LIBRARIES)

IF (Irrlicht_INCLUDE_DIRS AND Irrlicht_LIBRARIES)
  SET(Irrlicht_FOUND TRUE)
ELSE (Irrlicht_INCLUDE_DIRS AND Irrlicht_LIBRARIES)
  SET(Irrlicht_FOUND FALSE)
ENDIF (Irrlicht_INCLUDE_DIRS AND Irrlicht_LIBRARIES)

IF (Irrlicht_FIND_REQUIRED AND NOT Irrlicht_FOUND)
  MESSAGE(FATAL_ERROR
    "  Irrlicht not found.\n"
    "      Windows: Fill CMake variable CMAKE_MODULE_PATH to the provided directory.\n"
    "      Linux: Install Irrlicht using your package manager ($> sudo dnf install irrlicht-devel).\n"
  )
ENDIF (Irrlicht_FIND_REQUIRED AND NOT Irrlicht_FOUND)

# ============================================================================= #

IF (NOT Sfml_INCLUDE_DIRS OR NOT Sfml_LIBRARIES)
  FIND_PATH(Sfml_INCLUDE_DIRS
    NAMES
      Audio.hpp
    PATHS
      /usr/include/SFML/          # Default Fedora28 system include path
      ${CMAKE_SFML_PATH}/include/   # Expected to contain the path to this file for Windows10
      ${CMAKE_SFML_PATH}/include/SFML   # Expected to contain the path to this file for Windows10
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(Sfml_LIBRARIES
    NAMES
      sfml-audio
    PATHS
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library path
      ${CMAKE_SFML_PATH}/lib        # Expected to contain the path to this file for Windows10
  )
ENDIF (NOT Sfml_INCLUDE_DIRS OR NOT Sfml_LIBRARIES)

IF (Sfml_INCLUDE_DIRS AND Sfml_LIBRARIES)
  SET(Sfml_FOUND TRUE)
ELSE (Sfml_INCLUDE_DIRS AND Sfml_LIBRARIES)
  SET(Sfml_FOUND FALSE)
ENDIF (Sfml_INCLUDE_DIRS AND Sfml_LIBRARIES)

IF (Sfml_FIND_REQUIRED AND NOT Sfml_FOUND)
  MESSAGE(FATAL_ERROR
    "  Sfml not found.\n"
    "      Windows: Fill CMake variable CMAKE_SFML_PATH to the provided directory.\n"
    "      Linux: Install Sfml 2.4 using your package manager ($> sudo dnf install sfml-devel).\n"
  )
ENDIF (Sfml_FIND_REQUIRED AND NOT Sfml_FOUND)

# ================================================== #
# INIT PART (set sources / path / version / etc)     #
# ================================================== #

set(SRCS
  src/main.cpp
  src/EventReceiver.cpp
  src/Menu/Menu.cpp
  src/Menu/MenuEvent.cpp
  src/MapGen/MapGen.cpp
  src/PauseMenu/PauseMenu.cpp
  src/PauseMenu/PauseMenuEvent.cpp
  src/SceneHandler/SceneHandler.cpp
  src/Character/Character.cpp
  src/Character/CharacterSelection.cpp
  src/Character/CharacterSelectionEvent.cpp
  src/Credits/Credits.cpp
  src/Credits/CreditsEvent.cpp
  src/PlayerInfo/PlayerInfo.cpp
  src/TileMap.cpp
  src/IA/IA.cpp
  src/Bomb.cpp
  src/Core.cpp
  src/Save.cpp
  src/Explosion.cpp
  src/Game.cpp
  src/powerUp/SpeedUp.cpp
  src/powerUp/PowerUp.cpp
  src/powerUp/BombUp.cpp
  src/powerUp/Bonus.cpp
  src/Sound/Sound.cpp
  )

set(HEADERS
  include/IScene.hpp
  include/MapGen.hpp
  include/SceneHandler.hpp
  include/game/Bomb.hpp
  include/game/BombUp.hpp
  include/game/Bonus.hpp
  include/game/Character.hpp
  include/game/Core.hpp
  include/game/EventReceiver.hpp
  include/game/Explosion.hpp
  include/game/Game.hpp
  include/game/ICharacter.hpp
  include/game/PowerUp.hpp
  include/game/Save.hpp
  include/game/Sound.hpp
  include/game/SpeedUp.hpp
  include/game/TileMap.hpp
  include/game/CharacterSelection/CharacterSelection.hpp
  include/game/CharacterSelection/CharacterSelectionEvent.hpp
  include/game/Menu/Menu.hpp
  include/game/Menu/MenuEvent.hpp
  include/game/PauseMenu/PauseMenu.hpp
  include/game/PauseMenu/PauseMenuEvent.hpp
  include/game/PlayerInfo/PlayerInfo.hpp
  include/game/Credits/Credits.hpp
  include/game/Credits/CreditsEvent.hpp
  )

include_directories(
  "./include/"
  "./include/game/"
  "./include/game/Menu/"
  "./include/game/PauseMenu/"
  "./include/game/PlayerInfo/"
  "./include/game/CharacterSelection/"
  "./include/game/Credits/"
  "${SFML_ALL_INCLUDES_DIRS}/"
  "${Irrlicht_INCLUDE_DIRS}/"
  )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR})

# =================================================== #
# SYSTEME D'EXPLOIT.  (Vérifier si Windows ou Linux)  #
#   puis recherche des libraries pour compilation     #
# =================================================== #

IF (MSVC)     # Windows
	configure_file("${CMAKE_MODULE_PATH}/bin/Win32-VisualStudio/Irrlicht.dll" "./" COPYONLY)
	configure_file("${CMAKE_SFML_PATH}/bin/sfml-audio-2.dll" "./" COPYONLY)
	configure_file("${CMAKE_SFML_PATH}/bin/sfml-system-2.dll" "./" COPYONLY)
	configure_file("${CMAKE_SFML_PATH}/bin/openal32.dll" "./" COPYONLY)
    add_library(Irrstatic STATIC IMPORTED)
    set_property(TARGET Irrstatic PROPERTY IMPORTED_LOCATION "${Irrlicht_LIBRARIES}")
	add_library(Sfmlstatic STATIC IMPORTED)
	set_property(TARGET Sfmlstatic PROPERTY IMPORTED_LOCATION "${Sfml_LIBRARIES}")
ELSE (MSVC)   # Linux
    add_library(audio_sfml SHARED IMPORTED)
    set_property(TARGET audio_sfml PROPERTY IMPORTED_LOCATION "${Sfml_LIBRARIES}")
    add_library(Irrshared SHARED IMPORTED)
    set_property(TARGET Irrshared PROPERTY IMPORTED_LOCATION "${Irrlicht_LIBRARIES}")
ENDIF(MSVC)

add_executable(bomberman ${SRCS} ${HEADERS})

# =================================================== #
#             INSTALLATION DE L'EXEC                  #
# =================================================== #

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_link_libraries(bomberman "${Irrlicht_LIBRARIES}" "${Sfml_LIBRARIES}")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_link_libraries(bomberman "${Irrlicht_LIBRARIES}" "${Sfml_LIBRARIES}")
    install (TARGETS bomberman DESTINATION bin)
    target_compile_options(bomberman PUBLIC -std=gnu++11 -Wall -g)
endif()
