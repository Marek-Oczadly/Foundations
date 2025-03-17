#pragma once
#include <string>
#include <initializer_list>
#include <array>
#include <iostream>
#include <stdexcept>

class Matrix {
private:
	const unsigned int ROWS;
	const unsigned int COLS;

	double** const DATA;

	double** const allocate(const unsigned int rows, const unsigned int cols) const {
		double** data = new double* [rows];
		for (double** row = data; row < data + rows; ++row) {
			*row = new double[cols];
			for (double* val = *row; val < *row + cols; ++val) {
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
		for (double** row = DATA; row < DATA + ROWS; ++row) {
			delete[] * row;
		}
		delete[] DATA;
	}
	
	std::string display() const noexcept {
		std::string str = "";
		for (const double* const * row = DATA; row < DATA + ROWS; ++row) {
			str += "[";
			for (const double* val = *row; val < *row + COLS - 1; ++val) {
				str += std::to_string(*val) + "  ";
			}
			str += std::to_string(*(*row + COLS - 1)) + "]\n";
		}
		return str;
	}
	
	 double* const operator[](const unsigned int row) {
		 if (row > ROWS) throw std::out_of_range("The row does not correspond to a row in the matrix");
		 return *(DATA + row);
	 }

};
