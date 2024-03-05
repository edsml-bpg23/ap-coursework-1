//
// Created by Grey, Benedict P on 04/03/2024.
//

#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <vector>
#include <memory>
#include "CelestialBody.hpp"
#include "Matrix.hpp"

class SolarSystem {
public:
    SolarSystem(std::vector<CelestialBody> &bodies);
    void forward(int N);
    void initialiseGForceMatrix();
private:
    std::vector<CelestialBody> bodies;
    std::unique_ptr<Matrix<Vector3D<double>>> GForceMatrix;  // allows us to allocate memory when required
};

#endif //SOLARSYSTEM_H
