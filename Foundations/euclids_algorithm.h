#pragma once


class EuclidsAlgorithm {
	const unsigned long long x;
	const unsigned long long y;

public:
	EuclidsAlgorithm(const unsigned long long x, const unsigned long long y) :
		x(x), y(y) {}

	unsigned long long highest_common_factor() const noexcept {
		unsigned long long a, b, c;
		a = x;
		b = y;
		while (true) {
			c = a % b;
			if (b % c == 0) { 
				return c; 
			} else {
				a = b;
				b = c;
			}
		}
		return c;
	}
};
