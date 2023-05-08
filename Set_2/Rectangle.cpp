#include"Rectangle.hpp"

using namespace std;

Rectangle::Rectangle(double x, double y, double w, double h, const MyString& label) :
    m_w(w), m_h(h), Figure(x,y,label)
    {
        cout << "Rectangle constructor called" << "\n";
    }

Rectangle::~Rectangle()
{
    cout << "Rectangle destructor called" << "\n"; 
}

double Rectangle::getW()
{
    return m_w;
}

double Rectangle::getH()
{
    return m_h;
}
