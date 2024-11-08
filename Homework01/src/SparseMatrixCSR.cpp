/*
* Implementation of the SparseMatrix in CSR format
* Derived class from SparseMatrix pure virtual.
* include /include/SparseMatrixCSR.hpp as header file
* Matrix is stored following the assignement directives.
*/

#include <stdexcept>
#include <vector>
#include <iostream>
#include "../include/SparseMatrixCSR.hpp"

    //public constructor for SparseMatrixCSR
    template <typename T>
    SparseMatrixCSR<T>::SparseMatrixCSR(int row, int col) : rows(row), cols(col) {

        rowIndexCSR.resize(rows + 1, T(0));
    }

    // getter method for the number of rows of the matrix
    template <typename T>
    int SparseMatrixCSR<T>::numRows() const {
        return rows;
    }

    // getter method for the number of columns
    template <typename T>
    int SparseMatrixCSR<T>::numCols() const {
        return cols;
    }

    // getter method for the number of non-zero values within the matrix
    template <typename T>
    int SparseMatrixCSR<T>::getNonZeros() const {
        return values.size();
    }

    /*
    * overload method to get an entry of the matrix
    * @return result: value at the entry (row, col)
    * @throws out_of_range exception 
    */
    template <typename T>
    T SparseMatrixCSR<T>::operator()(int row, int col) const {

        if ( row < 0 || col < 0 || row >= rows || col >= cols ) {
            throw std::out_of_range("Index out of range!");
        } else {

            int rowStart = rowIndexCSR[row];
            int rowFinish = rowIndexCSR[row + 1];

            for (int i = rowStart; i < rowFinish; ++i){
                if ( colIndex[i] == col ){
                    return values[i];
                }
            }
        }

        return T(0);
    }

    /*
    * overload method for setting an entry (row, col) inside the matrix in CSR format
    * @param val; value to set
    * @throws out_of_range exception
    */
    template <typename T>
    void SparseMatrixCSR<T>::operator()(int row, int col, T val) {
    
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            throw std::out_of_range("Index out of range!");
        }

        int start = rowIndexCSR[row];     
        int end = rowIndexCSR[row + 1];  
    
        for (int i = start; i < end; ++i) {
            if (colIndex[i] == col) {
                if (val == T(0)) { 
                
                    values.erase(values.begin() + i);
                    colIndex.erase(colIndex.begin() + i);

                    for (int j = row + 1; j <= rows; ++j) {
                        rowIndexCSR[j]--;
                    }
                } else {
                    values[i] = val;
                }
                return; 
            }
        }

        if (val != T(0)) {
        
            int pos = start;
            while (pos < end && colIndex[pos] < col) {
                ++pos;
            }

            values.insert(values.begin() + pos, val);
            colIndex.insert(colIndex.begin() + pos, col);

            for (int j = row + 1; j <= rows; ++j) {
                rowIndexCSR[j]++;
            }
        }
    }

    /* 
    * overload method to calculate matrix-vector product
    * @param vector: vector to multiply with sparse matrix
    * @throws invalid_argument exception if it is not possible to perform multiplication
    * @return result: vector of the product 
    */
    template <typename T>
    std::vector<T> SparseMatrixCSR<T>::operator*(const std::vector<T> &vector) const {
        
        if (static_cast<int>(vector.size()) != cols) {
            throw std::invalid_argument("Vector size does not match matrix dimensions!");
        } else {
            std::vector<T> result(rows, T(0)); 

            for (int i = 0; i < rows; ++i) {
                int start = rowIndexCSR[i];
                int end = rowIndexCSR[i + 1];

                for (int j = start; j < end; ++j) {
                    result[i] += values[j] * vector[colIndex[j]];
                }
            }

            return result; 
        }
    }

    // Method to print matrix
    template <typename T>
    void SparseMatrixCSR<T>::printMatrix() const {
        std::cout << "Sparse Matrix (CSR Format):\n";
        for (int i = 0; i < rows; ++i) {

            int start = rowIndexCSR[i];
            int end = rowIndexCSR[i+1];

            for (int j = start; j < end; ++j){
                std::cout << "A(" << i << ", " << colIndex[j] << ") = " << values[j] << "\n";    
            }
        }
    }

template class SparseMatrixCSR<int>;
template class SparseMatrixCSR<double>;