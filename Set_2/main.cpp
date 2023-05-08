#include<iostream>
#include"MyString.hpp"
#include"Figure.hpp"
#include"Rectangle.hpp"
#include"Square.hpp"

using namespace std;

int main()
{
    Figure newFig(12.f, 34.f,"Jakas");
    newFig.print();
    Rectangle newRec(32.f, 95.f, 33.f, 65.f,"trojkacik");
    newRec.print();
    Square newSquare(31.f, 45.f, 75.f,"kwadracik");
    newSquare.print();
    return 0;

}