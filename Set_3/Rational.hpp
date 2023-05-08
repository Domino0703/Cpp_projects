#pragma once
#include"Real.hpp"


class Rational : public Real
{
private:
    float m_licz;
    float m_mian;
public:
    Rational(float licz, float mian);
    void print(ostream& out) const;
};