//
// Created by Grey, Benedict P on 04/03/2024.
//
#include <iostream>
#include <string>
#include "vector3D.hpp"
#include "CelestialBody.hpp"
#include "Planet.hpp"
#include "Star.hpp"

#define LOG(x) std::cout << x << std::endl;

int main() {

    // of course these are not realistic, this is a simple 3D model of the solar system
    vector3D starPos = vector3D{.x=0., .y=0., .z=0.}; // origin of this numerical model
    vector3D earthPos = vector3D{.x=1, .y=1, .z=1};
    vector3D marsPos = vector3D{.x=1, .y=.1, .z=0.};

    vector3D starVelocity = vector3D{.x=0., .y=0., .z=0.}; // origin of this numerical model
    vector3D earthVelocity = vector3D{.x=0., .y=0., .z=0.};
    vector3D marsVelocity = vector3D{.x=0., .y=0., .z=0.};

//    double distance = pos1.computeDistance(pos2);
    std::string earthName = "Earth", marsName = "Mars", starName = "Sun";
    double earthMass = 5.972e24, marsMass = 6.4171e23, starMass = 1.989e30;
    float earthRadius = 6371., marsRadius = 3389.5, starRadius = 696340.;

    Planet earth = Planet(earthName, earthPos, earthMass, earthVelocity, earthRadius);
    Star star = Star(starName, starPos, starMass, starVelocity, starRadius);
    Planet mars = Planet(marsName, marsPos, marsMass, marsVelocity, marsRadius);

    LOG(star.printSummary())

//    LOG(mars.printSummary())

    return 1;
}