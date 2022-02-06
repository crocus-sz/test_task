#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {
    rows = new unsigned int;
    columns = new unsigned int;

    inputDimension();

    fillInMatrix();

}

Matrix::~Matrix() {
    delete rows;
    delete columns;
}

void Matrix::inputDimension() {
    std::cout << "Enter a quantity of matrix rows: ";
    std::cin >> *rows;
    std::cout << "Enter a quantity of matrix columns: ";
    std::cin >> *columns;
}

void Matrix::addition(const Matrix &mtrx) {
    if(this->checkMatrixDimension(mtrx)) {
        std::cout << "Matrices after addition: " << std::endl;
        for(int i = 0; i < *this->rows; i++) {
            std::cout << "[ ";

            for(int j = 0; j < *this->columns; j++) {
                std::cout << this->matrix[i][j] + mtrx.matrix[i][j] << " ";
            }

            std::cout << "]";
            std::cout << std::endl;
        }
}
    else {
        std::cout << "matrices of different dimensions!" << std::endl;
    }
}

void Matrix::substraction(const Matrix &mtrx) {
    if(this->checkMatrixDimension(mtrx)) {
        std::cout << "Matrices after substraction: " << std::endl;
        for(int i = 0; i < *this->rows; i++) {
            std::cout << "[ ";

            for(int j = 0; j < *this->columns; j++) {
                std::cout << this->matrix[i][j] - mtrx.matrix[i][j] << " ";
            }

            std::cout << "]";
            std::cout << std::endl;
        }
}
    else {
        std::cout << "matrices of different dimensions!" << std::endl;
    }
}

void Matrix::multiplication(const Matrix &mtrx) {
    if((*this->rows == *mtrx.columns) && (*this->columns == *mtrx.rows)) { //check matrices dimensions 
        std::cout << "Matrices after multiplication: " << std::endl;

        for(int i = 0; i < *this->rows; i++) {
            std::cout << "[ ";
            for(int j = 0; j < *this->columns; j++) {
                std::cout << this->matrix[i][j] * mtrx.matrix[j][i] << " ";
            }
            std::cout << "]";
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "matrices of different dimensions!" << std::endl;
    }
}

const bool Matrix::checkMatrixDimension(const Matrix &mtrx) {
    return (*this->rows == *mtrx.rows) && (*this->columns == *mtrx.columns);

}

void Matrix::fillInMatrix() {
    // fill in the matrix of random numbers;

    for(int i = 0; i < *rows; i++) {
        std::vector<int> tmp_vector;

        for(int j = 0; j < *columns; j++) {
            tmp_vector.push_back(rand() % 100);
        }

        matrix.push_back(tmp_vector);
    }
}

std::ostream& operator<< (std::ostream &out, const Matrix &mtrx) {
    //overload cout operator to print the matrix

    out << std::endl;
    for(int i = 0; i < mtrx.matrix.size(); i++) {
        out << "[ ";
        for(int j = 0; j < mtrx.matrix[i].size(); j++) {
            out <<  mtrx.matrix[i][j] << " ";
        }
        out << "]";
        out << std::endl;
    }
    out << std::endl;
    
    return out;
}
