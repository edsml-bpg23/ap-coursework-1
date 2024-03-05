//
// Created by Grey, Benedict P on 04/03/2024.
//
#include "Vector3D.hpp"
#include "CelestialBody.hpp"
#include "Planet.hpp"
#include "TerrestrialPlanet.hpp"
#include "JovianPlanet.hpp"
#include "Star.hpp"
#include "SolarSystem.hpp"
#include <iostream>
#include <string>
#include <map>

#define LOG(x) std::cout << x << std::endl;

int main() {

    // of course these are not realistic, this is a simple 3D model of the solar system
    Vector3D<double> starPos = Vector3D(0., 0., 0.); // origin of this numerical model
    Vector3D<double> earthPos = Vector3D(150., 50., 0.);
    Vector3D<double> jupyterPos = Vector3D(100., -50., 150.);

    Vector3D<double> starVelocity = Vector3D(0., 0., 0.); // origin of this numerical model
    Vector3D<double> earthVelocity = Vector3D(0., 5., 5.);
    Vector3D<double> jupyterVelocity = Vector3D(5., 0., 0.);

//    double distance = pos1.computeDistance(pos2);
    std::string earthName = "Earth", jupyterName = "Jupyter", starName = "Sun";

    // real stats
//    double earthMass = 5.972e24, jupyterMass = 1.898e27, starMass = 1.989e30;
//    float earthRadius = 6371., jupyterRadius = 71492., starRadius = 696340.;

    double earthMass = 1, jupyterMass = 10, starMass = 10000;
    float earthRadius = 15., jupyterRadius = 50., starRadius = 100.;

    std::map<std::string, double> earthComp = {
            {"N", .78},
            {"O2", .2},
            {"Ar", .093},
            {"CO2", .004},
    };

    std::map<std::string, double> jupyterComp = {
            {"H", .9},
            {"He", .1},
    };


    TerrestrialPlanet earth = TerrestrialPlanet(earthName, earthPos, earthMass, earthVelocity, earthRadius, earthComp);
    JovianPlanet jupyter = JovianPlanet(jupyterName, jupyterPos, jupyterMass, jupyterVelocity, jupyterRadius, jupyterComp);
    Star sun = Star(starName, starPos, starMass, starVelocity, starRadius);

    std::vector<CelestialBody> bodies = {sun, earth, jupyter};
    SolarSystem system = SolarSystem(bodies);
//    system.forward(15);

//    LOG(earth.printSummary())
//    LOG(jupyter.printSummary())
//    LOG(sun.printSummary())



//    LOG(sun.computeGForce(jupyter));
//    LOG(jupyter.computeGForce(sun));


    return 1;
}