//
// Created by Grey, Benedict P on 04/03/2024.
//


#ifndef MATRIX_H
#define MATRIX_H

// we are going to use our
template<typename T>
class Matrix {
    public:
        Matrix(unsigned int rows, unsigned int cols);
        ~Matrix();

        // overloading the () operator
        T& operator()(int x, int y) const;

        void print() const;

    private:
        unsigned int m, n;
        T** pointers{};
        void alloc();

};



#endif //MATRIX_H
