//
// Created by Grey, Benedict P on 04/03/2024.
//


#ifndef MATRIX_H
#define MATRIX_H



class Matrix {
    public:
        unsigned int m;
        unsigned int n;
        Matrix(unsigned int, unsigned int);
        ~Matrix();

        // overloading the () operator
        double& operator()(int x, int y) const;

        void print() const;

    private:
        double** pointers{};
        void alloc();

};



#endif //MATRIX_H
