//
// Created by Grey, Benedict P on 04/03/2024.
//

#include "vector3D.hpp"

double vector3D::computeDistance(vector3D position) {
  // Euclidean distance between two 3D points in space
  return sqrt(pow(x - position.x, 2) + pow(y - position.y, 2) +
              pow(z - position.z, 2));
}