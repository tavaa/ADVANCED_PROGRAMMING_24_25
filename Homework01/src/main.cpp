#include <iostream>
#include <vector>
#include <stdexcept>
#include "../include/SparseMatrix.hpp"
#include "../include/SparseMatrixCOO.hpp"
#include "../include/SparseMatrixCSR.hpp"

int main() {
   
    /*
    example_matrix =
     [ 0 0 3.1 0 4 ]
     [ 0 0 5 0 7.4 ]
     [ 0 0 0 0 0 ]
     [ 0 2 0 6 0 ]

    */

    /////////////// COO TEST //////////////////////////
    std::cout << " " << std::endl;
    std::cout << "-----------------------C00 TEST-----------------" << std::endl;

    // constructor
    SparseMatrixCOO<double> matrix_coo(4,5);

    // insert using () operator
    matrix_coo(0, 2, 3.1);
    matrix_coo(0, 4, 4.0);
    matrix_coo(1, 2, 5.0);
    matrix_coo(1, 4, 7.4);
    matrix_coo(3, 1, 2.0);
    matrix_coo(3, 3, 6.0);

    //access using ()
    double val = matrix_coo(0, 4);
    double val5 = matrix_coo(0, 0);

    //test exceptions
    //double val2 = matrix_coo(6, 6);
    //double val3 = matrix_coo(3, 6);
    //double val4 = matrix_coo(6, 3);
    
    std::cout << "Access test: " << std::endl;
    std::cout << val << " " << val5 << std::endl;

    int row_number = matrix_coo.numRows();
    int col_number = matrix_coo.numCols();
    int nnz = matrix_coo.getNonZeros();

    std::cout << "Size test: " << std::endl;
    std::cout << row_number << " " << col_number << " " << nnz << std::endl;

    std::vector<double> vec1{5.6, 3.2, 4.0, 1.0, 6.5};
    std::vector<double> mul1 = matrix_coo*vec1;

    //std::vector<double> vec2(3, 0.0); 
    //std::vector<double> mul2 = matrix_coo*vec2; size mismatch test

    std::cout << "Mul test: " << std::endl;
    
    for (size_t i = 0; i < mul1.size(); ++i){
        std::cout << mul1[i] << " ";
    }
    std::cout << std::endl;

    //print matrix test
    matrix_coo.printMatrix();

    std::cout << " " << std::endl;
    std::cout << "-----------------------CSR TEST-----------------" << std::endl;
    //////////// CSR TEST //////////////////////////

    //constructor test
    SparseMatrixCSR<int> matrix_csr(4,5);

    // insert using () operator
    matrix_csr(0, 2, 3);
    matrix_csr(0, 4, 4);
    matrix_csr(1, 2, 5);
    matrix_csr(1, 4, 7);
    matrix_csr(3, 1, 2);
    matrix_csr(3, 3, 6);

    //access using ()
    int val_csr = matrix_csr(0, 4);
    int val5_csr = matrix_csr(0, 0);

    std::cout << "Access test: " << std::endl;
    std::cout << val_csr << " " << val5_csr << std::endl;

    int row_number_csr = matrix_csr.numRows();
    int col_number_csr = matrix_csr.numCols();
    int nnz_csr = matrix_csr.getNonZeros();

    std::cout << "Size test: " << std::endl;
    std::cout << row_number_csr << " " << col_number_csr << " " << nnz_csr << std::endl;

    std::vector<int> vec1_csr{6, 3, 4, 1, 7};
    //std::vector<double> vec2(3, 0.0);

    std::vector<int> mul1_csr = matrix_csr*vec1_csr;
    //std::vector<double> mul2 = matrix_coo*vec2;

    std::cout << "Mul test: " << std::endl;
    
    for (size_t i = 0; i < mul1_csr.size(); ++i){
        std::cout << mul1_csr[i] << " ";
    }
    std::cout << std::endl;

    matrix_csr.printMatrix();
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}