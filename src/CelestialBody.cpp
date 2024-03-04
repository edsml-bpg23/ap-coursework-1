//
// Created by Grey, Benedict P on 04/03/2024.
//

#include <string>
#include <cmath>
#include "CelestialBody.hpp"

#define G 6.67430e-11


CelestialBody::CelestialBody(
    std::string &name, vector3D &position, double &mass, vector3D &velocity
): name(name), position(position), mass(mass), velocity(velocity) {}

double CelestialBody::computeGForce(const CelestialBody &body) {
    /*
     computes the gravitational force between two celestial bodies
     F = GM m / r^2, where
     F is the G force,
     G is the gravitational constant
     M and m are the masses of each body
     r is the distance between the bodies
     */

    double r = position.computeDistance(body.position);
    return (G * body.mass) / pow(r, 2);
}

void CelestialBody::updateVelocity(vector3D &a, double &dt) {
    // velocity_new += velocity * delta_t
    velocity.x += a.x * dt;
    velocity.y = a.y * dt;
    velocity.z = a.z * dt;
}

void CelestialBody::updatePosition(vector3D &v, double &dt) {
    // pos_new += pos * velocity * delta_t
    position.x += v.x * dt;
    position.y = v.y * dt;
    position.z = v.z * dt;
    orbitalPath.push_back(position);
}





double CelestialBody::getMass() const {return mass;}

vector3D CelestialBody::getVelocity() const {return velocity;}

vector3D CelestialBody::getPosition() const {return position;}

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


