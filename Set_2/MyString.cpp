#include<iostream>
#include"MyString.hpp"

using namespace std;

MyString::MyString(const char* txt) :
    string(txt)
{
    cout << "MyString constructor called." << "\n";
}

MyString::~MyString()
{
    cout << "MyString destructor called" << "\n";
}

ostream& operator<<(ostream& stream, const MyString& string)
{
    stream << string.c_str();
    return stream;
}