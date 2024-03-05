//
// Created by Grey, Benedict P on 04/03/2024.
//


#include <string>
#include "Planet.hpp"
#include "JovianPlanet.hpp"

JovianPlanet::JovianPlanet(
        std::string &name,
        Vector3D<double> &position,
        double &mass,
        Vector3D<double> &velocity,
        float radius,  // km
    std::map<std::string, double> atmosphericComposition
) : Planet(name, position, mass, velocity, radius, atmosphericComposition) {}


std::string JovianPlanet::printSummary() {
    return "Jovian planet: \n" + Planet::printSummary();
}



