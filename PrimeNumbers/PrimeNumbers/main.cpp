#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

set<uint32_t> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> numbers(upperBound + 1, true);
	set<uint32_t> primes;
	numbers[1] = false;
	if (upperBound > 1)
	{
		primes.emplace_hint(primes.end(), 2);
	}
	for (int i = 2; ((i*i) <= upperBound); i++)
	{
		if (numbers[i])
		{
			for (int j = (i*i); j <= upperBound; j += i)
			{
				numbers[j] = false;
			}
		}
	}
	for (int i = 3; i <= upperBound; i += 2)
	{
		if (numbers[i])
		{
			primes.emplace_hint(primes.end(), i);
		}
	}
	return primes;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments." << endl;
		cout << "primes.exe <Number>" << endl;
		return 1;
	}

	if (atoi(argv[1]) < 0)
	{
		cout << "Invalid arguments." << endl;
		cout << "Numbers must be more then 0" << endl;
		return 1;
	}

	auto upperBound = atoi(argv[1]);
	auto primeNumbers = GeneratePrimeNumbersSet(upperBound);

	for (const auto prime : primeNumbers)
	{
		cout << prime << endl;
	}
	return 0;
}