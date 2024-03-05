//
// Created by Grey, Benedict P on 04/03/2024.
//


#include <string>
#include "Planet.hpp"
#include "CelestialBody.hpp"


Planet::Planet(
        std::string &name,
        Vector3D<double> &position,
        double &mass,
        Vector3D<double> &velocity,
        float radius,  // km
        std::map<std::string, double> &atmosphericComposition
) : CelestialBody(name, position, mass, velocity), radius(radius), atmosphericComposition(atmosphericComposition) {}


std::map<std::string, double> Planet::getAtmosphericComposition() {
    return atmosphericComposition;
}

std::string Planet::printComposition() {
    std::string composition = "\nAtmospheric composition: \n";
    for (auto& [key, value]: getAtmosphericComposition())
        composition += key + ": " + std::to_string(value) + "\n";
    return composition;
}

std::string Planet::printSummary() {
    std::string summary = CelestialBody::printSummary();
    summary += "\nRadius = " + std::to_string(radius) + printComposition();
    return summary;
}



