#pragma once
#include<iostream>

using namespace std;

class MyString : public string
{
public:
    MyString(const char* txt);
    ~MyString();
    friend ostream& operator<<(ostream& stream, const MyString& string);
};