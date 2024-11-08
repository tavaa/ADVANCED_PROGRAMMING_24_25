/*
* Implementation of the SparseMatrix in COO format
* Derived class from SparseMatrix pure virtual.
* include /include/SparseMatrixCOO.hpp as header file
* Matrix is stored following the assignement directives.
*/

#include <stdexcept>
#include <vector>
#include <iostream>
#include "../include/SparseMatrixCOO.hpp"

    //public constructor for SparseMatrixCOO
    template <typename T>
    SparseMatrixCOO<T>::SparseMatrixCOO(int row, int col) : rows(row), cols(col) {}

    // getter method for the number of rows of the matrix
    template <typename T>
    int SparseMatrixCOO<T>::numRows() const {
        return rows;
    }

    // getter method for the number of columns
    template <typename T>
    int SparseMatrixCOO<T>::numCols() const {
        return cols;
    }

    // getter method for the number of non-zero values within the matrix
    template <typename T>
    int SparseMatrixCOO<T>::getNonZeros() const {
        return values.size();
    }

    /*
    * overload method to get an entry of the matrix
    * @return result: value at the entry (row, col)
    * @throws out_of_range exception 
    */
    template <typename T>
    T SparseMatrixCOO<T>::operator()(int row, int col) const {

        if ( row < 0 || col < 0 || row >= rows || col >= cols ) {
            throw std::out_of_range("Index out of range!");
        } else {
            for (size_t i=0; i < values.size(); ++i){
                if (rowIndex[i] == row && colIndex[i] == col) {
                        return values[i];
                }
            }
        }

        return T(0);
    }

    /*
    * overload method for setting an entry (row, col) inside the matrix
    * @param val; value to set
    * @throws out_of_range exception
    */
    template <typename T>
    void SparseMatrixCOO<T>::operator()(int row, int col, T val)  {

        if ( row < 0 || col < 0 || row >= rows || col >= cols ) {
            throw std::out_of_range("Index out of range!");
        } else {
            for (size_t i=0; i < values.size(); ++i) {
                if(rowIndex[i] == row && colIndex[i] == col) {
                    if (val == T(0)) { 
                        rowIndex.erase(rowIndex.begin() + i);
                        colIndex.erase(colIndex.begin() + i);
                        values.erase(values.begin() + i);
                    } else {
                        values[i] = val; 
                    }
                }
            }

            if (val != T(0)) { 
                rowIndex.push_back(row);
                colIndex.push_back(col);
                values.push_back(val);
            }
        }

    }

    /* 
    * overload method to calculate matrix-vector product
    * @param vector: vector to multiply with sparse matrix
    * @throws invalid_argument exception if it not possible to perform multiplication
    * @return result: vector of the product 
    *  
    */
    template <typename T>
    std::vector<T> SparseMatrixCOO<T>::operator*(const std::vector<T> &vector) const {

        if (static_cast<int>(vector.size()) != cols) {
            throw std::invalid_argument("Vector size does not match matrix dimensions!");
        } else {
            std::vector<T> result(rows, T(0));

            for (size_t i = 0; i < values.size(); ++i) {
                result[rowIndex[i]] += values[i] * vector[colIndex[i]];
            }

            return result;
        }    
    }

    // Method to print matrix
    template <typename T>
    void SparseMatrixCOO<T>::printMatrix() const {
        std::cout << "Sparse Matrix (COO Format):\n";
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << "A(" << rowIndex[i] << ", " << colIndex[i] << ") = " << values[i] << "\n";
        }
    }

template class SparseMatrixCOO<int>;
template class SparseMatrixCOO<double>;


