#include"Rational.hpp"


Rational::Rational(float licz, float mian) :
    Real(licz, mian) 
{
    m_licz = licz;
    m_mian = mian;
}

void Rational::print(ostream& out) const 
{
    out << "Rational: " << m_licz << "/" << m_mian << "\n";
}