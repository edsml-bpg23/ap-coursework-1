//
// Created by Grey, Benedict P on 04/03/2024.
//

#ifndef PLANET_H
#define PLANET_H

#include <string>
#include "CelestialBody.hpp"

class Planet : public CelestialBody {
public:
    Planet(std::string &name, vector3D &position, double &mass, vector3D &velocity, float radius);
    float radius;
//    void rotate();
//    void revolve();
    std::string printSummary();
};


#endif //PLANET_H
