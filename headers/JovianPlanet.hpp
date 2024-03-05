//
// Created by Grey, Benedict P on 05/03/2024.
//

#ifndef JOVIAN_PLANET_H
#define JOVIAN_PLANET_H

#include "Vector3D.hpp"
#include "Planet.hpp"
#include <string>
#include <map>


class JovianPlanet : public Planet {
public:
//    JovianPlanet(
//            std::string &name,
//            Vector3D<double> &position,
//            double &mass,
//            Vector3D<double> &velocity,
//            float radius
//    );
    JovianPlanet(
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


#endif //JOVIAN_PLANET_H
