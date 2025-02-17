#pragma once
#include <iostream>


class EuclidsAlgorithm {
	const unsigned long long x;
	const unsigned long long y;

public:
	EuclidsAlgorithm(const unsigned long long x, const unsigned long long y) :
		x(x), y(y) {}

	unsigned long long highestCommonFactor() const noexcept {
		unsigned long long a, b, c;
		a = x;
		b = y;
		while (true) {
			c = a % b;
			if (b % c == 0) {  return c; } 
			else { a = b; b = c; }
		}
	}

	unsigned long long verboseHighestCommonFactor() const noexcept {
		unsigned long long a, b, c;
		a = x;
		b = y;
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
