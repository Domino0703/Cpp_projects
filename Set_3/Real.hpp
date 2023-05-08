#pragma once
#include<iostream>
#include"Complex.hpp"

using namespace std;

class Real : public Complex
{
public:
    Real(float real, float imag);
    void print(ostream& out) const;
};