#pragma once

#include <iostream>

class MyString
{
protected:
	char* body;
	size_t size;

	size_t getCharLenght(const char* value);
public:
	MyString() : body(nullptr), size(0) {};
	MyString(const char* value);
	MyString(const MyString& other);
	~MyString();

	MyString& set(const MyString& other);
	virtual MyString& operator=(const MyString& other) { return set(other); };

	MyString& push_forward(char value);
	MyString& push_back(char value);

	MyString& insret_forward(const MyString& other);
	MyString& insret_back(const MyString& other);

	MyString operator+(const MyString& other) const { return MyString(*this).insret_forward(other); };
	friend MyString operator+(const char* value, const MyString& str) { return MyString(str).insret_forward(value); }

	MyString& operator+=(const MyString& other) { return this->insret_forward(other); };

	bool compare(const MyString& other) const;
	bool operator==(const MyString& other) const { return compare(other); };
	friend bool operator==(const char* value, const MyString& other) { return other.compare(value); }

	bool operator!=(const MyString& other) const { return !compare(other); };
	friend bool operator!=(const char* value, const MyString& other) { return !other.compare(value); }

	char& at(int index);
	const char& at(int index) const;

	char& operator[](int index) { return at(index); }
	const char& operator[](int index) const { return at(index); }

	MyString& revers();

	virtual void clear();

	size_t lenght() const { return size; };
	bool isClear() const { return !body; }

	virtual std::ostream& print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const MyString& str) { return str.print(out); }
};