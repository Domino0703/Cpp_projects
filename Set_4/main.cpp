#include<iostream>
#include<math.h>
#include"ValueContainer.hpp"

using namespace std;

template <typename T1, typename T2, typename T3>

void solve_equation(T1 a, T2 b, T3 c)
{
    double x1,x2;
    x1 = (-b - sqrt(b*b - 4*a*c))/2*a;
    x2 = (-b + sqrt(b*b - 4*a*c))/2*a;
    cout << "Solution 1: " << x1 << "\n";
    cout << "Solution 2: " << x2 << "\n";
}

template<typename T = float, int p = 3>
T PowIt(T value)
{
	return static_cast<T>(pow(value, p));
}

int main()
{
   /* double a;
    float b;
    int c;
    cout << "Give a: ";
    cin >> a; 
    cout << "\n";
    cout << "Give b: ";
    cin >> b;
    cout << "\n";
    cout << "Give c: ";
    cin >> c;
    cout << "\n";
    solve_equation(a,b,c);
    */

    ValueContainer<int> object(5);
    ++object;
    cout<<  "Integer: "<<object;
    ValueContainer<char> character('j');
    ++character;
    cout<< "Character: "<< character;


    /*int intArr[] = { 1,2,3,4 };
	ArrayUtils<int, 4>::print(intArr);
	ArrayUtils<int, 4>::reversePrint(intArr);
	std::cout << ArrayUtils<int, 4>::sumAll(intArr) << "\n";
	std::cout << ArrayUtils<int, 4>::productOfArray(intArr) << "\n";

	std::cout << "\n\n";
	
	float floatArr[] = { 11.f,12.f,13.f,14.f, 15.f };
	ArrayUtils<float, 5>::print(floatArr);
	ArrayUtils<float, 5>::reversePrint(floatArr);
	std::cout << ArrayUtils<float, 5>::sumAll(floatArr) << "\n";
	std::cout << ArrayUtils<float, 5>::productOfArray(floatArr) << "\n";

	std::cout << "\n\n";

	std::string stringArr[] = { "Hello", " ", "World!" };
	ArrayUtils<std::string, 3>::print(stringArr);
	ArrayUtils<std::string, 3>::reversePrint(stringArr);
	std::cout << ArrayUtils<std::string, 3>::sumAll(stringArr) << "\n";*/
	//std::cout << ArrayUtils<std::string, 3>::productOfArray(stringArr) << "\n";
    return 0;

}