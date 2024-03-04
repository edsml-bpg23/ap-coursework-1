//
// Created by Grey, Benedict P on 04/03/2024.
//

#ifndef STAR_H
#define STAR_H

#include <string>
#include "CelestialBody.hpp"

class Star : public CelestialBody {
public:
    Star(std::string &name, vector3D &position, double &mass, vector3D &velocity, float radius);
    float radius;
    std::string printSummary();
};


#endif //STAR_H
