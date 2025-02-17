#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <memory>


class GeneratePrimes {
private:
	const unsigned int NUM_PRIMES;
	std::ofstream PRIMES_FILE;

public:
	GeneratePrimes(const char* file_name, const unsigned int num_primes) :
		NUM_PRIMES(num_primes), PRIMES_FILE(file_name, std::ios::app) {}

	static bool checkIfPrime( 
		const unsigned long long& num, 
		const unsigned long long* begin,
		const unsigned long long* end) {
		while (*begin <= std::sqrt(num) && begin < end) {
			if (num % *begin == 0) { return false; }
			++begin;
		}
		return true;
	}

	unsigned long long* run() const {
		unsigned long long* const PRIMES = new (unsigned long long[NUM_PRIMES]);
		PRIMES[0] = 2;
		unsigned long long* filled = &PRIMES[0] + 1;
		unsigned long long num = 3;
		while (filled < &PRIMES[0] + NUM_PRIMES) {
			if (GeneratePrimes::checkIfPrime(num, &PRIMES[0], filled)) {
				*filled = num;
				++filled;
			}
			num += 2;
		}
		return PRIMES;
	}

	void save(unsigned long long* const primes) {
		for (const unsigned long long* i = &primes[0];
			i < &primes[0] + NUM_PRIMES; ++i) {
			PRIMES_FILE << *i << "\n";
		}
		delete[] primes;
	}

};