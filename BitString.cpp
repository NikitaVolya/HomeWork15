#include "BitString.h"

void BitString::test()
{
    if (isClear())
        return;

    for (int i = 0; i < lenght(); i++)
    {
        if (at(i) != '1' && at(i) != '0')
        {
            clear();
            break;
        }
    }
}

BitString& BitString::operator=(const BitString& other)
{
    set(other);
    test();
    return *this;
}

void BitString::clear()
{
    MyString::clear();
    set("0");
}


void BitString::swap()
{
    negative = !negative;
    for (int i = 0; i < lenght(); i++)
        at(i) = (at(i) == '1' ? '0' : '1');
}

BitString BitString::operator!() const
{
    BitString rep = *this;
    rep.swap();
    return rep;
}

BitString BitString::operator+(const BitString& other)
{
    BitString otherCopy(other);
    BitString rep;


    if (negative != otherCopy.negative)
        throw std::invalid_argument("the values ​​must be similar");
    
    rep.negative = negative;
    bool rest = false;
    int i = 0;
    for (; i < size; i++)
    {
        bool numberA = body[i] == '1';
        bool numberB = (i < otherCopy.size ? otherCopy.body[i] == '1' : false);

        bool result = (numberA ^ numberB) ^ rest;
        rest = (numberA && numberB) || ((numberA ^ numberB) && rest);
        rep.push_back(result ? '1' : '0');
    }
    for (; i < otherCopy.size; i++)
    {
        bool numberA = otherCopy.body[i] == '1';
        rep.push_back(numberA ^ rest ? '1' : '0');

        rest = numberA && rest;
    }

    if (rest)
    {
        rep.push_back('1');
    }
    return rep;
}

std::ostream& BitString::print(std::ostream& out) const
{
    out << negative << " ";
    for (int i = (int)lenght() - 1; i >= 0; i--)
        out << at(i);
    return out;
}