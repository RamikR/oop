#include "stdafx.h"
#include "HTMLEncoder_functions.h"
using namespace std;
int main(int argc, const char * argv[])
{
	string inputString;

	while (!cin.eof())
	{
		getline(cin, inputString);
		cout << HTMLEncode(inputString) << endl;
	}

	return 0;
}