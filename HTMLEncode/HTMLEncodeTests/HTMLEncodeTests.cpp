// HTMLEncodeTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\HTMLEncode\HTMLEncoder_functions.h"

BOOST_AUTO_TEST_SUITE(HTMLEncode_function)

BOOST_AUTO_TEST_CASE(empty_str)
{
	std::string line = "";
	std::string correctStr = "";
	BOOST_CHECK_EQUAL(HTMLEncode(line), correctStr);
}

BOOST_AUTO_TEST_CASE(without_symbols)
{
	std::string line = "test";
	std::string correctStr = "test";
	BOOST_CHECK_EQUAL(HTMLEncode(line), correctStr);
}

BOOST_AUTO_TEST_CASE(correct_signs_more_and_less)
{
	std::string line = "Cat <says>";
	std::string correctLine = "Cat &lt;says&gt;";
	BOOST_CHECK_EQUAL(HTMLEncode(line), correctLine);
}

BOOST_AUTO_TEST_CASE(correct_quotes)
{
	std::string line = "Cat \"Meow\".";
	std::string correctLine = "Cat &quot;Meow&quot;.";
	BOOST_CHECK_EQUAL(HTMLEncode(line), correctLine);
}

BOOST_AUTO_TEST_CASE(correct_ampersand)
{
	std::string line = "Cat M&M's";
	std::string correctLine = "Cat M&amp;M&apos;s";
	BOOST_CHECK_EQUAL(HTMLEncode(line), correctLine);
}

BOOST_AUTO_TEST_CASE(correct_all_values)
{
	std::string line = "Cat <says> \"Meow\". M&M's";
	std::string correctLine = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	BOOST_CHECK_EQUAL(HTMLEncode(line), correctLine);
}
BOOST_AUTO_TEST_SUITE_END()