cmake_minimum_required(VERSION 3.26)
project(ap_coursework_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

add_executable(ap_coursework_1
        headers/Matrix.hpp
        src/Matrix.cpp
        main.cpp
        headers/CelestialBody.hpp
        headers/Vector3D.hpp
        headers/Planet.hpp
        src/CelestialBody.cpp
        src/Vector3D.cpp
        src/Planet.cpp
        headers/Star.hpp
        src/Star.cpp
        headers/SolarSystem.hpp
        src/SolarSystem.cpp
        headers/TerrestrialPlanet.hpp
        src/TerrestrialPlanet.cpp
        headers/JovianPlanet.hpp
        src/JovianPlanet.cpp)
