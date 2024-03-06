//
// Created by Grey, Benedict P on 04/03/2024.
//


#include "SolarSystem.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>


SolarSystem::SolarSystem() = default;
SolarSystem::SolarSystem(std::vector<CelestialBody> &bodies) : bodies{bodies} {}
//SolarSystem::~SolarSystem

void SolarSystem::updateGForce() {

    int n = bodies.size();

    // first set the diagonal to zero
    for (int i = 0; i < n; i++)
        (*GForceMatrix)(i, i) = Vector3D<double>(0., 0., 0.);

    // now we can use the fact that forces are equal and opposite for corresponding bodies
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            Vector3D<double> force = bodies[i].computeGForce(bodies[j]);
            (*GForceMatrix)(i, j) = force;
            (*GForceMatrix)(j, i) = force * -1;
        }
    }
}

Vector3D<double> SolarSystem::computeNetAcceleration(int i) {
    Vector3D<double> netForce = {0, 0, 0};
    // Accumulate forces from bodies before i
    for (int j = 0; j < i; j++) {
        netForce += (*GForceMatrix)(i, j);
    }
    // Accumulate forces from bodies after i
    for (int j = i + 1; j < bodies.size(); j++) {
        netForce += (*GForceMatrix)(i, j);
    }
    return netForce / bodies[i].getMass();
}

void SolarSystem::forward(int N, double dt) {
    /*
     Initialise the GForce matrix using the memory library
     this matrix will hold the GForce between all celestial bodies in the system
     it's essentially an adjacency matrix
     */

    int n = bodies.size();
    GForceMatrix = std::make_unique<Matrix<Vector3D<double>>>(n, n);
    Vector3D<double> a;

    // run forward for N time steps
    for (int t = 0; t < N; t++) {
        updateGForce();
        // iterate through bodies in system
        for (int i = 0; i < bodies.size(); i++) {
            // calculate net acceleration from all forces acting on body
            a = computeNetAcceleration(i);

            // update velocity and position
            bodies[i].setVelocity(a, dt);
            bodies[i].setPosition(dt);
        }

    }


}

std::vector<CelestialBody> SolarSystem::getBodies() const {return bodies;}


void SolarSystem::writeOrbitalPaths() {
    /*
     Write orbital paths to file for plotting.
     */

    for (const CelestialBody& body: bodies) {

        // construct a unique filename for each body
        std::stringstream filename;
        filename << "../data/" << body.getName() << "_orbitalPath.txt";

        std::ofstream file(filename.str());

        if (file.is_open()) {
            std::vector<Vector3D<double>> orbitalPath = body.getOrbitalPath();
            for (const Vector3D<double>& path : orbitalPath) {
                file << path << "\n";
            }
            file.close();
        }
        else {
            std::cerr << "Failed to open file: " << filename.str() << std::endl;
        }
    }
}


