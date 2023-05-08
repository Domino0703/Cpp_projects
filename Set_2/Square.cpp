#include<iostream>
#include"Square.hpp"

using namespace std;


Square::Square(double x, double y, double w, const MyString& label) :
        Rectangle(x,y,w,w,label)
        {
            cout<<"Square constructor called" << "\n";
        }

Square::~Square()
{
    cout<<"Square destructor called" << "\n";
}