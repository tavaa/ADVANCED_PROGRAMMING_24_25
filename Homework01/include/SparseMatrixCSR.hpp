/*
* Derived class of SparseMatrix for the CSR implementation.
* Header file, see effective implementation in /src/SparseMatrixCSR.cpp
* Matrix is stored following the assignement directives.
*/

#ifndef SPARSE_MATRIXCSR_HPP__
#define SPARSE_MATRIXCSR_HPP__

#include "SparseMatrix.hpp"
#include <vector>

template <typename T>

class SparseMatrixCSR : public SparseMatrix<T>{

    private:

        int rows;
        int cols;
        std::vector<T> values;
        std::vector<int> colIndex;
        std::vector<int> rowIndexCSR;

    public:

        // public constructor for SparseMatrixCSR
        SparseMatrixCSR(int row, int col);

        //header declaration of pure virtual functions
        int numRows() const override;
        int numCols() const override;
        int getNonZeros() const override;
        T operator()(int row, int col) const override;
        void operator()(int row, int col, T val) override;
        std::vector<T> operator*(const std::vector<T> &vector) const;
        void printMatrix() const override;
        
};

#endif // SPARSE_MATRIXCSR_HPP__