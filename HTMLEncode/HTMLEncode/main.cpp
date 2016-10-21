#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string HTMLEncode(string & inputString)
{
	string encodeString = "";
	for (char& letter : inputString)
	{
		switch (letter)
		{
		case '&':  encodeString += "&amp;";  break;
		case '\"': encodeString += "&quot;"; break;
		case '\'': encodeString += "&apos;"; break;
		case '<':  encodeString += "&lt;";   break;
		case '>':  encodeString += "&gt;";   break;
		default:   encodeString += letter;   break;
		}
	}
	return encodeString;
}

int main(int argc, const char * argv[])
{
	string inputString = "";

	while (true)
	{
		cin >> inputString;
		cout << HTMLEncode(inputString);
	}

	return 0;
}