#include<iostream>
#include"ComplexNumber.hpp"

using namespace std;

int main()
{
    ComplexNumber newComplex(4.5,5);
    ComplexNumber com(5,2);
    cout<<newComplex<<"\n";
    com = com * newComplex;
    cout<<com;
    return 0;
}