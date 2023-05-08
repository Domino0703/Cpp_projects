#pragma once
#include<iostream>
#include"MyString.hpp"

using namespace std;

class Figure
{
private:
    double m_x;
    double m_y;
    MyString m_label;
public:
    Figure(double x, double y, const MyString& label);
    ~Figure();
    double getX();
    double getY();
    MyString getLabel();
    void print(void);
};