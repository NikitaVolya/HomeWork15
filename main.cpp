
#include <iostream>
#include "BitString.h"


int main()
{
	BitString test("1001101", false);
	BitString b("101", true);

	std::cout << test + b;

	return 0;
}