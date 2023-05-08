#include<iostream>

using namespace std;

class ComplexNumber
{
private:
    float Real;
    float Imag;
public:
    ComplexNumber(float real, float imag);
    ComplexNumber(const ComplexNumber& CompNum);
    float getReal() const;
    float getImag() const;
    void setImag(float imag);
    void setReal(float real);

    ComplexNumber conjugate();
    ComplexNumber abs();

    ComplexNumber& operator+(const ComplexNumber& CompNum);
    ComplexNumber operator-(const ComplexNumber& CompNum);
    ComplexNumber operator*(const ComplexNumber& CompNum);
    bool operator==(const ComplexNumber& CompNum);
    
    friend ostream& operator<<(ostream& ostream, const ComplexNumber& CompNum);
};