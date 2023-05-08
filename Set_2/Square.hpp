#pragma once
#include"Rectangle.hpp"

using namespace std;

class Square : public Rectangle
{
public:
    Square(double x, double y, double w, const MyString& label);
    ~Square();
};