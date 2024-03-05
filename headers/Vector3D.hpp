//
// Created by Grey, Benedict P on 04/03/2024.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

template<typename T>
class Vector3D {
public:
    Vector3D(T x, T y, T z);
    Vector3D operator-(const Vector3D &rhs) const;
    Vector3D operator*(T scalar) const;
    std::ostream& operator<<(std::ostream& os, const Vector3D& v);
    double getMagnitude();
    Vector3D norm();
    T x, y, z;
};

#endif // VECTOR3D_H
