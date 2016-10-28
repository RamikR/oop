#include <iostream>
#include <string>

std::string ConvertDec2Bin(const int decNumber)
{
	std::string binNumber = "";
	const unsigned int binNumberLength = 7;
	for (int i = binNumberLength; i >= 0; --i)
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

bool IsNumber(char * str)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		if (!isdigit(str[i])) 
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
			<< "Usage: dec2bin.exe <decNumber>" << std::endl;
		return false;
	};
	return true;
}

int main(int argc, char * argv[])
{
	if (IsArgumentsExists(argc, 2))
	{
		if (IsNumber(argv[1]))
		{
			std::cout << ConvertDec2Bin(atoi(argv[1])) << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Incorrect input data. Please enter a valid input data." << std::endl;
			return 1;
		}
	}
	else
	{
		return 1;
	}
}