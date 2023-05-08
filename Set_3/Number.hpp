#pragma once
#include<iostream>

using namespace std;

class Number
{

public:
    virtual void print(ostream& out) const = 0;
};
