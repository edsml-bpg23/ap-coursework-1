//
// Created by Grey, Benedict P on 05/03/2024.
//

#ifndef TERRESTRIAL_PLANET_H
#define TERRESTRIAL_PLANET_H

#include "Vector3D.hpp"
#include "Planet.hpp"
#include <string>
#include <map>


class TerrestrialPlanet : public Planet {
public:
    TerrestrialPlanet(
            std::string &name,
            Vector3D<double> &position,
            double &mass,
            Vector3D<double> &velocity,
            float radius,
            std::map<std::string, double> atmosphericComposition
    );
    std::string printSummary() override;
private:
};


#endif //TERRESTRIAL_PLANET_H
