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


    double earthMass = 1, jupyterMass = 20, starMass = 10000;
    float earthRadius = 15., jupyterRadius = 20., starRadius = 100.;

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

    system.forward(150, 1);
    system.writeOrbitalPaths();

    LOG("Simulation successfully complete.")


    return 1;
}