//
// Created by Grey, Benedict P on 04/03/2024.
//


#include "SolarSystem.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <memory>

SolarSystem::SolarSystem(std::vector<CelestialBody> &bodies) : bodies(bodies) {}


void SolarSystem::initialiseGForceMatrix() {
    int n = bodies.size();

//    this->GForceMatrix = std::make_unique<Matrix<Vector3D<double>>>(n, n);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i == j)
//                (*GForceMatrix)(i, j) = Vector3D<double>(0., 0., 0.);
//            else {
////                std::cerr << bodies[i].getName() + " > " + bodies[j].getName() + " " << bodies[i].computeGForce(bodies[j]) << ", ";
//                (*GForceMatrix)(i, j) = bodies[i].computeGForce(bodies[j]);
//            }
//        }
//    }
//    (GForceMatrix->print());
}

void SolarSystem::forward(int N) {
    /*
     initialise the GForce matrix using the memory library
     this matrix will hold the GForce between all celestial bodies in the system
     it's essentially an adjacency matrix
     */
    initialiseGForceMatrix();




}
