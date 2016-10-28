#include "stdafx.h"
using namespace std;

string HTMLEncode(string const & codedString)
{
	string encodedString;
	for (char letter : codedString)
	{
		switch (letter)
		{
			case '&':  encodedString.append("&amp;");    break;
			case '\"': encodedString.append("&quot;");   break;
			case '\'': encodedString.append("&apos;");   break;
			case '<':  encodedString.append("&lt;");     break;
			case '>':  encodedString.append("&gt;");     break;
			default:   encodedString.append(&letter, 1); break;
		}
	}
	return encodedString;
}