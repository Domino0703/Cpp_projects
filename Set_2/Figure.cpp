#include<iostream>
#include"Figure.hpp"

using namespace std;

Figure::Figure(double x, double y, const MyString& label) :
    m_x(x), m_y(y), m_label(label)
{
    cout << "Figure constructor called" << "\n";
}

Figure::~Figure()
{
    cout<<"Figure destructor called"<<"\n";
}

double Figure::getX()
{
    return m_x;
}

double Figure::getY()
{
    return m_y;
}

MyString Figure::getLabel()
{
    return m_label;
}

void Figure::print(void)
{
    cout<<"I am a Figure: " << m_label << " x = " << getX() << " y = " << getY() << "\n";
}


