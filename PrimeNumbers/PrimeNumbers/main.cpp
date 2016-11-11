#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

set<int> GeneratePrimeNumbersSet(unsigned upperBound)
{
	vector<bool> primeNumber(upperBound + 1);

	for (unsigned i = 1; i <= upperBound; i++)
	{
		primeNumber[i] = true;
	}

	set<int> primes;
	for (unsigned i = 2; ((i*i) <= upperBound); i++)
	{
		if (primeNumber[i])
		{
			for (unsigned j = (i*i); j <= upperBound; j += i)
			{
				if (primeNumber[j]) primeNumber[j] = false;
			}
		}
	}

	for (unsigned i = 3; i <= upperBound; i += 2)
	{
		if (primeNumber[i])
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
	auto primes = GeneratePrimeNumbersSet(upperBound);

	for (const auto prime : primes)
	{
		cout << prime << endl;
	}
	return 0;
}