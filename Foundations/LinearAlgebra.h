#pragma once
#include <string>
#include <initializer_list>
#include <array>
#include <iostream>
#include <stdexcept>


template <typename T>
class Matrix {
protected:
	const unsigned int ROWS;
	const unsigned int COLS;

	T** const DATA;

	T** const allocate(const unsigned int rows, const unsigned int cols) const {
		T** data = new T* [rows];
		for (T** row = data; row < data + rows; ++row) {
			*row = new T[cols];
			for (T* val = *row; val < *row + cols; ++val) {
				*val = 0;
			}
		}
		return data;
	}

public:

	/// @brief Constructor. Initialises as 0 matrix.
	Matrix(const unsigned int rows, const unsigned int cols) :
		ROWS(rows), COLS(cols), DATA(allocate(rows, cols)) {
	}

	~Matrix() {
		for (T** row = DATA; row < DATA + ROWS; ++row) {
			delete[] * row;
		}
		delete[] DATA;
	}
	
	std::string display() const noexcept {
		std::string str = "";
		for (const T* const * row = DATA; row < DATA + ROWS; ++row) {
			str += "[";
			for (const T* val = *row; val < *row + COLS - 1; ++val) {
				str += std::to_string(*val) + "  ";
			}
			str += std::to_string(*(*row + COLS - 1)) + "]\n";
		}
		return str;
	}
	
	 T* const operator[](const unsigned int row) {
		 if (row > ROWS) throw std::out_of_range("The row does not correspond to a row in the matrix");
		 return *(DATA + row);
	 }

};


template <typename T>
class Vector : public Matrix<T> {
public:
	Vector(const unsigned int size) : Matrix<T>(size, 1) {}
	Vector(std::initializer_list<T> list) : Matrix<T>(list.size(), 1) {
		unsigned int i = 0;
		for (T val : list) {
			*(*(this->DATA + i++)) = val;
		}
	}

	std::string display() const noexcept {
		std::string str = "";
		for (const T* const* row = this->DATA; row < this->DATA + this->ROWS - 1; ++row) {
			str += "[" + std::to_string(**row) + "]\n";
		}
		str += "[" + std::to_string(**(this->DATA + this->ROWS - 1)) + "]";
		return str;
	}
};


template <typename T>
class IdentityMatrix : public Matrix<T> {
public:
	IdentityMatrix(const unsigned int size) : Matrix<T>(size, size) {
		for (unsigned int i = 0; i < size; ++i) {
			*(*(this->DATA + i) + i) = 1;
		}
	}
};