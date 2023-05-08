#include<iostream>
#include"ComplexNumber.hpp"
#include<math.h>

using namespace std;

ComplexNumber::ComplexNumber(float real, float imag)
{
    Real = real;
    Imag = imag;
}

ComplexNumber::ComplexNumber(const ComplexNumber& CompNumb)
{
    Real = CompNumb.getReal();
    Imag = CompNumb.getImag();
}

float ComplexNumber::getReal() const
{
    return Real;
}

float ComplexNumber::getImag() const
{
    return Imag;
}

void ComplexNumber::setReal(float real)
{
    Real = real;
}

void ComplexNumber::setImag(float imag)
{
    Imag = imag;
}

ComplexNumber ComplexNumber::conjugate()
{
    return ComplexNumber(Real, -Imag);
}

ComplexNumber ComplexNumber::abs()
{
    float z;
    z = sqrt(Real*Real+Imag*Imag);
    ComplexNumber newComplex(z, 0.f);
    return newComplex;
}

ComplexNumber& ComplexNumber::operator+(const ComplexNumber& CompNum)
{
    Real += CompNum.getReal();
    Imag += CompNum.getImag();
    return *this;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& CompNum)
{
    Real -= CompNum.getReal();
    Imag -= CompNum.getImag();
    return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& CompNum)
{
    Real = Real * CompNum.getReal() - (Imag * CompNum.getImag()); 
    Imag = Real * CompNum.getImag() + (Imag * CompNum.getReal());
    return *this;
}

bool ComplexNumber::operator==(const ComplexNumber& CompNum)
{
    if(CompNum.getImag() == Imag && CompNum.getReal() == Real)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& ostream, const ComplexNumber& CompNum)
{
    ostream << CompNum.getReal();
    if (CompNum.getImag() != 0)
    {   
        if (CompNum.getImag() > 0.f)
        {
            ostream << "+";
            ostream << CompNum.getImag();
            ostream << "i";
        }
        else
        {
            ostream << "-";
            ostream << CompNum.getImag();
            ostream << "i";
        }
    }
    return ostream;
}