//
// Created by Grey, Benedict P on 04/03/2024.
//


#include <string>
#include "Planet.hpp"
#include "TerrestrialPlanet.hpp"


TerrestrialPlanet::TerrestrialPlanet(
        std::string &name,
        Vector3D<double> &position,
        double &mass,
        Vector3D<double> &velocity,
        float radius,  // km
    std::map<std::string, double> atmosphericComposition
) : Planet(name, position, mass, velocity, radius, atmosphericComposition){}


std::string TerrestrialPlanet::printSummary() {
    return "Terrestrial planet: \n" + Planet::printSummary();
}



