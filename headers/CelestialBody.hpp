//
// Created by Grey, Benedict P on 04/03/2024.
//


#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <string>
#include "Vector3D.hpp"


// interface for our celestial bodies, implementing using an abstract class
class CelestialBody {
public:
    // methods
    CelestialBody(std::string &name, Vector3D<double> &position, double &mass, Vector3D<double> &velocity);

    Vector3D<double> computeGForce(const CelestialBody &body);

    void setVelocity(Vector3D<double> &a, double &dt);

    void setPosition(Vector3D<double> &v, double &dt);

    Vector3D<double> getPosition() const;

    Vector3D<double> getVelocity() const;

    std::vector<Vector3D<double>> getOrbitalPath() const;

    double getMass() const;

    std::string getName() const;

    virtual std::string printSummary();

private:
    // private members/attributes
    std::string name;
    double mass;  // kg
    Vector3D<double> position;  // Euclidean
    Vector3D<double> velocity;  // km/s
    std::vector<Vector3D<double>> orbitalPath; // track trajectories
};

#endif //CELESTIALBODY_H