//
// Created by Grey, Benedict P on 04/03/2024.
//

#include "Matrix.hpp"
#include "Vector3D.hpp"
#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
#define EPS 1e-10;

/*
Constructors
*/
template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
    alloc();  // initialise 2D array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            pointers[i][j] = T{};
    }
}

/*
Destructor
*/
template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < m; i++)
        delete[] pointers[i];  // delete the array of pointers at each row
    delete[] pointers;  // finally delete the whole empty data sctructure
}

template<typename T>
T& Matrix<T>::operator()(int x, int y) const {
    return pointers[x][y];
}



// allocate the memory required for the matrix by initialising the double pointer (pointer to a pointer)
template<typename T>
void Matrix<T>::alloc() {
    pointers = new T*[m];
    for (int i = 0; i < m; i++)
        pointers[i] = new T[n];
}


template<typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < m; i++) {
        std::string suffix;
        for (int j = 0; j < n; j++) {
            if (j != n-1) {suffix = ", ";}
            else {suffix = "";}
            std::cout << pointers[i][j] << suffix;
        }
        std::cout << "\n";
    }
}

template class Matrix<double>;
template class Matrix<float>;
template class Matrix<int>;
template class Matrix<Vector3D<double>>;

