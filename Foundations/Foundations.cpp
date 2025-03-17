// Foundations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "euclids_algorithm.h"
#include "LinearAlgebra.h"

int main() {
	Matrix<int> m(3, 3);
	Vector<int> v = { 1, 2, 3 };
	IdentityMatrix<int> i(3);
	std::cout << m.display() << std::endl;
	std::cout << v.display() << std::endl;
	std::cout << i.display() << std::endl;
	return 0;
}
