//
// Created by Grey, Benedict P on 04/03/2024.
//

#ifndef PLANET_H
#define PLANET_H

#include "CelestialBody.hpp"
#include <string>
#include <map>

class Planet : public CelestialBody {
public:
    Planet(std::string &name, Vector3D<double> &position, double &mass, Vector3D<double> &velocity, float radius, std::map<std::string, double> &atmosphericComposition);
    float radius;
//    void rotate();
    std::map<std::string, double> getAtmosphericComposition();
    std::string printSummary() override;
private:
    std::map<std::string, double> atmosphericComposition;
    std::string printComposition();
};

#endif //PLANET_H
