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
    SolarSystem();
    SolarSystem(std::vector<CelestialBody> &bodies);
    void forward(int N, double dt = 1.);
    void updateGForce();
    Vector3D<double> computeNetAcceleration(int i);
    std::vector<CelestialBody> getBodies() const;
    void writeOrbitalPaths();
private:
    std::vector<CelestialBody> bodies;
    std::unique_ptr<Matrix<Vector3D<double>>> GForceMatrix;  // allows us to allocate memory when required
};

#endif //SOLARSYSTEM_H
