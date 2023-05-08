
#include<iostream>

using namespace std;

class Shape
{
protected:
    string Colour;
public:
    Shape(string colour):Colour(colour){};
    virtual float getArea() = 0;
};

class IMovable
{
public:
    virtual void move(float dx, float dy) = 0;
    virtual void moveToRigin() = 0;
};
class IPrintable
{
public:
    virtual void print() = 0;
};


class Circle : public Shape, public IPrintable, public IMovable 
{
    float Radius;
    float Y;
    float X;
public:
    Circle(float radius,float x,float y, string colour): Radius(radius),X(x), Y(y), Shape(colour) {}
    string getColour(){
        return Colour;
    }
    float getRadius(){
        return Radius;
    }
    float getX(){
        return X;
    }
    float getY(){
        return Y;
    }
    void setColour(string colour){
        Colour = colour;
    }
    void setRadius(float radius){
        Radius = radius;
    }
    void setX(float x){
        X = x;
    }
    void setY(float y){
        Y = y;
    }
    virtual float getArea()
    {
        cout << "Pole powierzchni kola: " << (3.14 * getRadius() * getRadius()) << "\n";
        return (3.14 * getRadius() * getRadius());
    }
    virtual void move(float dx, float dy)
    {
        setX(getX() + dx);
        setY(getY() + dy);
    }
    virtual void moveToRigin(){
        setX(0.f);
        setY(0.f);
    }
    void print(){
        cout << "Dane techniczne kola:" << "\n";
        cout << "Dlugosc promienia: ";
        cout << getRadius() << "\n";
        cout << "Pozycja x:  ";
        cout << getX() << "\n";
        cout << "Pozycja y: ";
        cout << getY() << "\n";
    }

};

class Triangle : public Shape, public IPrintable, public IMovable 
{
    float LengthOfBase;
    float LengthOfHeight;
    float Y;
    float X;
public:
    Triangle(float lengthOfBase,float lengthOfHeight ,float y, float x, string colour):
         LengthOfBase(lengthOfBase),LengthOfHeight(lengthOfHeight) ,X(x), Y(y), Shape(colour) {}
    string getColour(){
        return Colour;
    }
    float getLengthOfBase(){
        return LengthOfBase;
    }
    float getLengthOfHeight(){
        return LengthOfHeight;
    }
    float getX(){
        return X;
    }
    float getY(){
        return Y;
    }
    void setColour(string colour){
        Colour = colour;
    }
    void setLengthOfBase(float lengthOfBase){
        LengthOfBase = lengthOfBase;
    }
    void setLengthOfHeight(float lengthOfHeight){
        LengthOfHeight = lengthOfHeight;
    }
    void setX(float x){
        X = x;
    }
    void setY(float y){
        Y = y;
    }
    virtual float getArea()
    {   
        cout << "Pole powierzchni trojkata: " << (getLengthOfBase() * getLengthOfHeight())/2 << "\n";
        return (getLengthOfBase() * getLengthOfHeight())/2;
    }
    virtual void move(float dx, float dy)
    {
        setX(getX() + dx);
        setY(getY() + dy);
    }
    virtual void moveToRigin(){
        setX(0.f);
        setY(0.f);
    }
    void print(){
        cout << "Dane techniczne kola:" << "\n";
        cout << "Dlugosc podstawy: ";
        cout << getLengthOfBase() << "\n";
        cout << "Wysokosc: ";
        cout << getLengthOfHeight() << "\n";
        cout << "Pozycja x:  ";
        cout << getX() << "\n";
        cout << "Pozycja y: ";
        cout << getY() << "\n";
        cout << "Kolor: ";
        cout << getColour() << "\n";
    }

};


int main()
{
    Shape * figury[2]{
        new Circle(1,2,3,"red"),
        new Triangle(9,8,7,6,"green")
    };

    figury[0]->getArea();
    figury[1]->getArea();

    IPrintable * fig;
    Circle cir(3,4,5,"yellow");
    Triangle t(2,3,4,5,"pink");
    fig = &cir;
    fig->print();
    fig = &t;
    fig->print();
    return 0;
};