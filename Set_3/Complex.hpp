#include"Number.hpp"

using namespace std;

class Complex : public Number
{
private:
    float m_real;
    float m_imag;
public:
    Complex(float real, float imag);
    float getImag() const;
    float getReal() const;
    void setReal(float real);
    void setImag(float imag);
    virtual void print(ostream& out) const override;
};