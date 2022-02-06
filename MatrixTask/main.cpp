#include "Matrix.h"
#include <iostream>

int main() {
    Matrix m1, m2;
    std::cout << m1;
    std::cout << m2;
    //it is necessary that the columns and rows of the two matrices are the same!
    m1.addition(m2);
    m1.substraction(m2);

    //it is necessary that the column of one matrix is equal to the row of the other matrix and vice versa
    //m1.multiplication(m2);
    
    return 0;
}
