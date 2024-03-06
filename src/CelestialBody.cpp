//
// Created by Grey, Benedict P on 04/03/2024.
//

#include <string>
#include <cmath>
#include "CelestialBody.hpp"


CelestialBody::CelestialBody(
        std::string &name, Vector3D<double> &position, double &mass, Vector3D<double> &velocity
): name{name}, position{position}, mass{mass}, velocity{velocity} {}

Vector3D<double> CelestialBody::computeGForce(const CelestialBody &body) {
    /*
     computes the gravitational force between two celestial bodies
     constant G is omitted to suit small scale simulations with arbitrary units of distance and mass
     F = (M . m) / r^2, where
     F is the G force,
     M and m are the masses of each body
     r is the distance between the bodies
     */

    Vector3D dist = body.position - position;
    double distMag = dist.magnitude();

    double forceMag = (mass * body.mass) /  pow(distMag, 2);
    return dist.norm() * forceMag;
}

void CelestialBody::setVelocity(Vector3D<double> &a, double &dt) {
    velocity += a * dt;
}

void CelestialBody::setPosition(double &dt) {
    position += velocity * dt;
    orbitalPath.push_back(position);
}

Vector3D<double> CelestialBody::getPosition() const {return position;}

Vector3D<double> CelestialBody::getVelocity() const {return velocity;}

std::vector<Vector3D<double>> CelestialBody::getOrbitalPath() const {return orbitalPath;}

double CelestialBody::getMass() const {return mass;}

std::string CelestialBody::getName() const {return name;}

std::string CelestialBody::printSummary() {
    return "Name: " + name +
           "\nMass = " + std::to_string(mass) +
           "\nVelocity = " + std::to_string(velocity.x) +
           ", " + std::to_string(velocity.y) +
           ", " + std::to_string(velocity.z) +
           "\nPosition: " + std::to_string(position.x) +
           ", " + std::to_string(position.y) +
           ", " + std::to_string(position.z);
}


