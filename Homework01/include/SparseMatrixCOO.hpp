/*
* Derived class of SparseMatrix for the COO implementation.
* Header file, see effective implementation in /src/SparseMatrixCOO.cpp
* Matrix is stored following the assignement directives.
*/

#ifndef SPARSE_MATRIXCOO_HPP__
#define SPARSE_MATRIXCOO_HPP__

#include "SparseMatrix.hpp"
#include <vector>

template <typename T>

class SparseMatrixCOO : public SparseMatrix<T> {

    private:

        int rows;
        int cols;
        std::vector<T> values;
        std::vector<int> rowIndex, colIndex;
    
    public:

    // public constructor for SparseMatrixCOO
    SparseMatrixCOO(int row, int col);

    //header declaration of pure virtual functions
    int numRows() const override;
    int numCols() const override;
    int getNonZeros() const override;
    T operator()(int row, int col) const override;
    void operator()(int row, int col, T val) override;
    std::vector<T> operator*(const std::vector<T> &vector) const;
    void printMatrix() const override;

};

#endif // SPARSE_MATRIXCOO_HPP__
