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
	int m_number; // pole odpowiadajace za podana liczbe do por�wnania
public:
	Game(float money, int number);  // konstruktor
	void compare(); // losowanie i por�wnywanie liczb
	void choice();  // wyb�r pomiedzy menu a ponowna proba

};

