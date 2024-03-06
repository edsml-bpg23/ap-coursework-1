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

    Vector3D();
    Vector3D(T x, T y, T z);
    ~Vector3D();
    Vector3D operator-(const Vector3D &rhs) const;
    Vector3D operator-=(const Vector3D &rhs);
    Vector3D operator+(const Vector3D &rhs) const;
    Vector3D operator+=(const Vector3D &rhs);
    Vector3D operator*(T scalar) const;
    Vector3D operator*=(T scalar);
    Vector3D operator/(T scalar) const;
    double magnitude();
    Vector3D norm();
    T x, y, z;

    // inline definition of friend as we need access to the full template definition
    inline friend std::ostream& operator<<(std::ostream &out, const Vector3D<T> &v) {
        out << '[' << v.x << ", " << v.y << ", " << v.z << ']';
        return out;
    }
};

#endif // VECTOR3D_H
