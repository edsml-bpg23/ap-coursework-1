//
// Created by Grey, Benedict P on 04/03/2024.
//

#include "Vector3D.hpp"
#include <iostream>

template<typename T>
//Vector3D<T>::Vector3D() {x = 0, y = 0, z = 0;}
Vector3D<T>::Vector3D() = default;

template<typename T>
Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}

template<typename T>
Vector3D<T>::~Vector3D() = default;

template<typename T>
Vector3D<T> Vector3D<T>::operator-(const Vector3D &rhs) const {
    return {x - rhs.x, y - rhs.y, z - rhs.z};
}

template<typename T>
Vector3D<T> Vector3D<T>::operator-=(const Vector3D &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator+(const Vector3D &rhs) const {
    return {x + rhs.x, y + rhs.y, z + rhs.z};
}

template<typename T>
Vector3D<T> Vector3D<T>::operator+=(const Vector3D &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator*(T scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

template<typename T>
Vector3D<T> Vector3D<T>::operator*=(T scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template<typename T>
Vector3D<T> Vector3D<T>::operator/(T scalar) const {
    return {x / scalar, y / scalar, z / scalar};
}

template<typename T>
double Vector3D<T>::magnitude() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

template<typename T>
Vector3D<T> Vector3D<T>::norm() {
    double mag = magnitude();
    return Vector3D(x/mag, y/mag, z/mag);
}

template class Vector3D<double>;
template class Vector3D<float>;
template class Vector3D<int>;



