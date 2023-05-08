#pragma once
#include"Figure.hpp"


using namespace std;

class Rectangle : public Figure
{
private:
    double m_w;
    double m_h;
public:
    Rectangle(double x, double y, double w, double h, const MyString& label);
    ~Rectangle();
    double getW();
    double getH();
};