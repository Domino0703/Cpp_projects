#include <iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"Menu.h"
#include"Game.h"

using namespace std;


int main()
{
	Menu m1;
	m1.menu();
	m1.load();
	return 0;
}