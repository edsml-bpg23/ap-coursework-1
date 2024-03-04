//
// Created by Grey, Benedict P on 04/03/2024.
//


#include <string>
#include "Planet.hpp"
#include "CelestialBody.hpp"


Planet::Planet(
    std::string &name,
    vector3D &position,
    double &mass,
    vector3D &velocity,
    float radius  // km
) : CelestialBody(name, position, mass, velocity), radius(radius) {}


std::string Planet::printSummary() {
    std::string summary = CelestialBody::printSummary();
    return summary + "\nRadius = " + std::to_string(radius);
}



