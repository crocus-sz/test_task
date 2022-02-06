#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {

    private:
        unsigned int *rows;
        unsigned int *columns;
        std::vector <std::vector <int>> matrix;

    public:
        Matrix();
        ~Matrix();
        void inputDimension();
        void addition(const Matrix &mtrx);
        void substraction(const Matrix &mtrx);
        void multiplication(const Matrix &mtrx);
        const bool checkMatrixDimension(const Matrix &mtrx);
        void fillInMatrix();

        friend std::ostream& operator<< (std::ostream &out, const Matrix &mtrx);
};

#endif
