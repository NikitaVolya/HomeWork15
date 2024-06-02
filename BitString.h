#pragma once

#include "MyString.h"

class BitString : protected MyString
{
private:
	bool negative;

	void test();
public:
	BitString(bool isNegative = false) : MyString(), negative(isNegative) { };
	BitString(const char* value, bool isNegative = false) : MyString(value), negative(isNegative) { revers(); test(); }

	BitString& operator=(const BitString& other);

	void swap();
	BitString operator!() const;

	BitString operator+(const BitString& other);
	BitString& operator+=(const BitString& other) { *this = *this + other; };

	void clear();

	bool operator==(const BitString& other) const { return compare(other); }
	bool operator!=(const BitString& other) const { return !compare(other); }

	std::ostream& print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const BitString& bit_str) { return bit_str.print(out); };
};

