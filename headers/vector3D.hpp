//
// Created by Grey, Benedict P on 04/03/2024.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>

struct vector3D {
  float x;
  float y;
  float z;
  double computeDistance(vector3D position);
};

#endif // VECTOR3D_H
