#pragma once
#include <iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
class Game
{
	float m_money; //pole odpowiadajace za depozyt
	int m_number; // pole odpowiadajace za podana liczbe do porównania
public:
	Game(float money, int number);  // konstruktor
	void compare(); // losowanie i porównywanie liczb
	void choice();  // wybór pomiedzy menu a ponowna proba

};

