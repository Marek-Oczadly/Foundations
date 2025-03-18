// Foundations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "euclids_algorithm.h"
#include "LinearAlgebra.h"

int main() {
	Matrix<int> m = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	IdentityMatrix<int> i(3);
	std::cout << m.display() << std::endl;
	return 0;
}
