#pragma once
#include <iostream>
#include <stdexcept>

typedef unsigned long long Unsigned_LLong;

/// @brief Functions based off of Euclid's Algorithm
class EuclidsAlgorithm {
	const Unsigned_LLong x, y;

	void extended_euclids_algorithm(Unsigned_LLong& h, Unsigned_LLong& x0, Unsigned_LLong& y0) {

	}

public: 
	struct XandY {
		Unsigned_LLong x, y;
	};

	/// @brief Constructor function for the EuclidsAlgorithm class
	/// @param x A number 
	/// @param y Another number
	EuclidsAlgorithm(const Unsigned_LLong x, const Unsigned_LLong y) :
		x(x), y(y) {}
	
	/// @brief Calculates the highest common factor between x and y
	/// @return The highest common factor beween the numbers
	Unsigned_LLong highestCommonFactor() const noexcept {
		Unsigned_LLong a, b, c;
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
	Unsigned_LLong verboseHighestCommonFactor() const noexcept {
		Unsigned_LLong a, b, c;
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

	bool integerSolution(const Unsigned_LLong c) const noexcept {
		Unsigned_LLong hcf = highestCommonFactor();
		return (c % hcf == 0);
	}

	/// @brief Get x and y for the equation ax + by = h where h is the highest common factor for a and b
	/// @return 
	XandY getXY0() const {

	}

	XandY getIntegerSolution(const Unsigned_LLong c, const Unsigned_LLong k = 0) const {
		Unsigned_LLong x, y;
		const Unsigned_LLong h = highestCommonFactor();
		if (c % h != 0) { throw std::invalid_argument("No integer solutions"); }


	}


};
