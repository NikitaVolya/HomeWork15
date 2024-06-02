#include "MyString.h"

size_t MyString::getCharLenght(const char* value)
{
	size_t tmp = 0;
	while (value[tmp] != '\0')
		tmp++;
	return tmp;
}

MyString::MyString(const char* value)
{
	size = getCharLenght(value);
	if (size == 0)
	{
		body = nullptr;
		return;
	}

	body = new char[size];
	
	for (int i = 0; i < size; i++)
		body[i] = value[i];
}

MyString::MyString(const MyString& other) : body(new char[other.size]), size(other.size)
{
	for (int i = 0; i < size; i++)
		body[i] = other.body[i];
}

MyString::~MyString()
{
	if (body)
		delete[] body;
}

MyString& MyString::set(const MyString& other)
{
	if (other == *this)
		return *this;

	if (!other.body)
	{
		clear();
		return *this;
	}

	if (size != other.size)
	{
		delete[] body;

		size = other.size;
		body = new char[size];
	}

	for (int i = 0; i < size; i++)
		body[i] = other.body[i];

	return *this;
}

MyString& MyString::push_forward(char value)
{
	size++;
	if (!body)
	{
		body = new char[size];
		body[0] = value;
		return *this;
	}

	char* newBody = new char[size];
	newBody[0] = value;

	for (int i = 0; i < size - 1; i++)
		newBody[i + 1] = body[i];
	delete[] body;
	body = newBody;

	return *this;
}

MyString& MyString::push_back(char value)
{
	size++;
	if (!body)
	{
		body = new char[size];
		body[0] = value;
		return *this;
	}

	char* newBody = new char[size];
	newBody[size - 1] = value;

	for (int i = 0; i < size - 1; i++)
		newBody[i] = body[i];

	delete[] body;
	body = newBody;

	return *this;
}

MyString& MyString::insret_forward(const MyString& other)
{
	char* newBody = new char[size + other.size];
	for (int i = 0; i < other.size; i++)
		newBody[i] = other.body[i];
	for (int i = 0; i < size; i++)
		newBody[i + other.size] = body[i];
	delete[] body;
	body = newBody;
	size = size + other.size;

	return *this;
}

MyString& MyString::insret_back(const MyString& other)
{
	char* newBody = new char[other.size + size];
	for (int i = 0; i < size; i++)
		newBody[i] = body[i];
	for (int i = 0; i < other.size; i++)
		newBody[i + size] = other.body[i];
	delete[] body;
	body = newBody;
	size = size + other.size;

	return *this;
}

bool MyString::compare(const MyString& other) const
{
	if (size != other.size)
		return false;
	for (int i = 0; i < size; i++)
		if (body[i] != other.body[i])
			return false;
	return true;
}

char& MyString::at(int index)
{
	if (index < 0 || index >= size)
		throw std::out_of_range("out of range of string");
	return body[index];
}

const char& MyString::at(int index) const
{
	if (index < 0 || index >= size)
		throw std::out_of_range("out of range of string");
	return body[index];
}

MyString& MyString::revers()
{
	if (!body)
		return *this;

	char* newBody = new char[size];
	for (int i = (int) size - 1; i >= 0; i--)
		newBody[size - i - 1] = body[i];

	delete[] body;
	body = newBody;
	return *this;
}

void MyString::clear()
{
	if (body)
		delete[] body;
	size = 0;
	body = nullptr;
}

std::ostream& MyString::print(std::ostream& out) const
{
	for (int i = 0; i < size; i++)
		out << body[i];
	return out;
}
