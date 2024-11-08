/*
* Abstract class for the representation of a Sparse Matrix. (pure virtual)
* Header file for the declaration,
* see /src/SparseMatrixCOO.ccp and SparseMatrixCSR for the implementation
* Methods within the class are some operation required for the assignement.
*/

#ifndef SPARSE_MATRIX_HPP__
#define SPARSE_MATRIX_HPP__

#include <vector>

template <typename T>

class SparseMatrix {

    public:

        //declaration of the virtual decostructor -mandatory in abs.classes
        virtual ~SparseMatrix(){}

        //1. getters for the number of rows and cols.
        virtual int numRows() const = 0;
        virtual int numCols() const = 0;

        //2. getter for the non-zero values of the matrix
        virtual int getNonZeros() const = 0;

        //3. reader for an entry of the matrix - overload
        virtual T operator()(int row, int col) const = 0;

        //4. setter for an entry of the matrix - overload
        virtual void operator()(int row, int col, T val)  = 0;

        //5. computer matrix-vector product - overload
        virtual std::vector<T> operator*(const std::vector<T> &vector) const = 0;

        //6. Printer in standard output format
        virtual void printMatrix() const = 0;

};

#endif // SPARSE_MATRIX_HPP__

