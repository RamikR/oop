#include <iostream>
#include <string>

std::string ConvertDec2Bin(const int decNumber)
{
	std::string binNumber = "";
	const int binNumberLength = 8;
	for (int i = binNumberLength; i >= 0; i--)
	{
		if ((1 << i) & decNumber)
		{
			binNumber = binNumber + "1";
		}
		else
		{
			binNumber = binNumber + "0";
		}
	}
	return binNumber;
}

bool IsIntNumber(const char *number)
{
	while (*number)
	{
		if (!isdigit(*number++))
		{
			return false;
		}
	}
	return true;
}

bool IsArgumentsExists(int argc, const int theNumberOfArguments)
{
	if (argc != theNumberOfArguments)
	{
		std::cout << "Invalid arguments count" << std::endl
			<< "Usage: copyfile.exe <input file> <output file>" << std::endl;
		return false;
	};
	return true;
}

int main(int argc, char * argv[])
{
	if (IsArgumentsExists(argc, 2))
	{
		if (IsIntNumber(argv[1]))
		{
			std::cout << ConvertDec2Bin(atoi(argv[1])) << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Incorrect input data" << std::endl;
			return 1;
		}
	}
	else
	{
		return 1;
	}
}