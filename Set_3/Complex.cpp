#include"Complex.hpp"

using namespace std;

Complex::Complex(float real, float imag):
    m_real(real), m_imag(imag)
{}

float Complex::getImag() const 
{
    return m_imag;
}

float Complex::getReal() const
{
    return m_real;
}

void Complex::setImag(float imag)
{
    m_imag = imag;
}

void Complex::setReal(float real)
{
    m_real = real;
}

void Complex::print(ostream& out) const
{
    out << "Complex: " << getReal() << " + " << getImag() << "i" << "\n";
}

