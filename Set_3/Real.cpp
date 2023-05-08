#include"Real.hpp"

Real::Real(float real, float imag) :
        Complex(real, imag) {}

void Real::print(ostream& out) const
{
    out << "Real: " << getReal() <<"\n";
}