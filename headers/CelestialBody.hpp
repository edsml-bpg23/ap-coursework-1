//
// Created by Grey, Benedict P on 04/03/2024.
//


#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <string>
#include "vector3D.hpp"


// interface for our celestial bodies, implementing using an abstract class
class CelestialBody {
public:
    // methods
    CelestialBody(std::string &name, vector3D &position, double &mass, vector3D &velocity);

    double computeGForce(const CelestialBody &body);

    void updateVelocity(vector3D &a, double &dt);

    void updatePosition(vector3D &v, double &dt);

    vector3D getPosition() const;

    vector3D getVelocity() const;

    double getMass() const;

    std::string getName() const;

    virtual std::string printSummary();
private:
    // private members/attributes
    std::string name;
    double mass;  // kg
    vector3D position;  // Euclidean
    vector3D velocity;  // km/s
    std::vector<vector3D> orbitalPath; // track trajectories
};

#endif //CELESTIALBODY_H