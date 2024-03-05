//
// Created by Grey, Benedict P on 04/03/2024.
//

#include <string>
#include <cmath>
#include "CelestialBody.hpp"

#define G 6.67430e-11


CelestialBody::CelestialBody(
        std::string &name, Vector3D<double> &position, double &mass, Vector3D<double> &velocity
): name(name), position(position), mass(mass), velocity(velocity) {}

Vector3D<double> CelestialBody::computeGForce(const CelestialBody &body) {
    /*
     computes the gravitational force between two celestial bodies
     F = GM m / r^2, where
     F is the G force,
     G is the gravitational constant
     M and m are the masses of each body
     r is the distance between the bodies
     */

//    double r = position.computeDistance(body.position);
    Vector3D distance = position - body.position;
    double distMag = distance.getMagnitude();

    double forceMagnitude = (mass * body.mass) /  pow(distMag, 2);
    return distance.norm() * forceMagnitude;

//    return (G * body.mass) / pow(r, 2);
}

void CelestialBody::setVelocity(Vector3D<double> &a, double &dt) {
    // velocity_new += velocity * delta_t

    velocity.x += a.x * dt;
    velocity.y = a.y * dt;
    velocity.z = a.z * dt;
}

void CelestialBody::setPosition(Vector3D<double> &v, double &dt) {
    // pos_new += pos * velocity * delta_t
    position.x += v.x * dt;
    position.y = v.y * dt;
    position.z = v.z * dt;
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


