#include"Rational.hpp"

ostream& operator<<(ostream& stream, Number* number)
{
    number->print(stream);
    return stream;
}

int main()
{
    Number *complex =new Complex(34.f, 12.f);
    Number *real = new Real(135.f, 1);
    Number *rational = new Rational(34.f, 56.f);

    cout << complex;
    cout << real;
    cout << rational;
    return 0;
}