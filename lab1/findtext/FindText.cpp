#include "stdafx.h"

bool SearchString(std::string SearchStr, std::ifstream & input)
{
	std::string CurrStr;
	unsigned int StrNumber = 1;
	bool stringWasFound = false;

	while (std::getline(input, CurrStr))
	{
		if (CurrStr.find(SearchStr) != std::string::npos)
		{
			std::cout << "Word was found on the " << StrNumber << " line." << std::endl;
			stringWasFound = true;
		}
		++StrNumber;
	}

	return stringWasFound;
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count\n" << "Usage: findtext.exe <input file> <search text>\n";
		return 1;
	}
	std::ifstream input(argv[1]);
	if(!input.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	std::string SearchStr(argv[2]);
	
	if (!SearchString(SearchStr, input))
	{
		std::cout << "String wasn't found.";
	}
    return 0;
}

