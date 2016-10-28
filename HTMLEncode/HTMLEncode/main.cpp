#include "stdafx.h"
#include "HTMLEncoder_functions.h"
using namespace std;
int main(int argc, const char * argv[])
{
	string inputString;

	while(true)
	{
		getline(cin, inputString);
		if (inputString == "...")
		{
			return 0;
		}
		cout << HTMLEncode(inputString);
	}
}