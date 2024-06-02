#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pet
{
protected:
	string kind;
	string name;
	float weight;

public:
	Pet(const string& pKind, const string& pName, float pWeight) : kind(pKind), name(pName) { setWeignt(pWeight); };

	string getKind() const { return kind; }
	string getName() const { return name; }
	float getWeight() const { return weight; }

	void setName(const string& value) { name = value; }
	void setWeignt(float value) { if (value > 0) weight = value; else throw invalid_argument("invalid value"); }
};

class Dog : public Pet
{
public:
	Dog(const string& pName) : Pet("Dog", pName, 30) {};
	Dog(const string& pName, float weight) : Pet("Dog", pName, weight) {};
};

class Cat : public Pet
{
public:
	Cat(const string& pName) : Pet("Cat", pName, 4) {};
	Cat(const string& pName, float weight) : Pet("Cat", pName, weight) {};
};

class Parrot : public Pet
{
public:
	Parrot(const string& pName) : Pet("Parrot", pName, 2.25f) {};
	Parrot(const string& pName, float weight) : Pet("Parrot", pName, weight) {};
};