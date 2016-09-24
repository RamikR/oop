#include "stdafx.h"

int main(int argc, char * argv[])
{
	std::ifstream input(argv[1]);
	std::string SearchStr(argv[2]);
	std::string CurrStr;
	unsigned StrNumber = 1;
	if(!input.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	bool stringWasFound = false;
	while (std::getline(input, CurrStr))
	{
		if(CurrStr.find(SearchStr) != std::string::npos)
		{
			std::cout << "Word was found on the " << StrNumber << " line." << std::endl;
			stringWasFound = true;
		}
		++StrNumber;
	}
	if(!stringWasFound)
	{
		std::cout << "Word was not found" << std::endl;
	}
    return 0;
}

