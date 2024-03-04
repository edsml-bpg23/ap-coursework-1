//
// Created by Grey, Benedict P on 04/03/2024.
//


#include <vector>
#include "SolarSystem.hpp"
#include <memory>
#include "Matrix.hpp"

SolarSystem::SolarSystem(std::vector<CelestialBody> &bodies) : bodies(bodies) {}

void SolarSystem::runSimulation(int N) {
    /*
     initialise the GForce matrix using the memory library
     this matrix will hold the GForce between all celestial bodies in the system
     it's essentially an adjacency matrix
     */
    GForceMatrix = std::make_unique<Matrix>(N, N);
}
