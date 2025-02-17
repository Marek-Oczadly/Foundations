#pragma once
#include <iostream>


/// @brief Functions based off of Euclid's Algorithm
class EuclidsAlgorithm {
	const unsigned long long x;
	const unsigned long long y;

public:
	/// @brief Constructor function for the EuclidsAlgorithm class
	/// @param x A number 
	/// @param y Another number
	EuclidsAlgorithm(const unsigned long long x, const unsigned long long y) :
		x(x), y(y) {}
	
	/// @brief Calculates the highest common factor between x and y
	/// @return The highest common factor beween the numbers
	unsigned long long highestCommonFactor() const noexcept {
		unsigned long long a, b, c;
		a = x;
		b = y;
		if (a % b == 0) {
			return b;
		}
		while (true) {
			c = a % b;
			if (b % c == 0) {  return c; } 
			else { a = b; b = c; }
		}
	}

	/// @brief Calculates the highest common factor between x and y using Euclid's Algorithm and prints every step in the console
	/// @return The highest common factor between the numbers
	unsigned long long verboseHighestCommonFactor() const noexcept {
		unsigned long long a, b, c;
		a = x;
		b = y;
		if (a % b == 0) {
			std::cout << a << " = (" << (a / b) << " * " << b << ") + 0\n";
			std::cout << "Highest common factor is: " << b << "\n";
			return b;
		}
		while (true) {
			c = a % b;
			std::cout << a << " = (" << (a / b) << " * " << b << ") + " << c << "\n";
			if (b % c == 0) {
				std::cout << b << " = (" << (b / c) << " * " << c << ") + 0\n";
				std::cout << "Highest common factor is: " << c << "\n";
				return c; 
			} else { a = b; b = c; }
		}
	}
};
