#include "Game.h"
#include "Menu.h"
#include<iostream>
using namespace std;

Game::Game(float money, int number)
{
	m_number = 0;
	m_money = 0;
	m_number = number;
	m_money = money;
}
void Game:: compare()
{
	srand(time(NULL));
	int chance;
	chance = rand() % 10 + 1;

	if (m_number == chance)
	{
		cout << "Gratulacje! Odgadles liczbe :) Twoj depozyt zostal zwiekszony X10." << endl;
		cout << "Wygrales : " << m_money * 10 << "!!!" << endl;
		Menu m3;
		m3.win();
		choice();
	}
	else
	{
		cout << "Niestety nie udalo Ci sie odgadnac liczby. Tracisz wszystkie swoje pieniadze." << endl;
		Menu m4;
		m4.lose();
		choice();
	}

}

void Game:: choice()
{

	cout << "Aby zagrac ponownie wybierz 'p'" << endl;
	cout << "Aby wrocic do menu wybierz 'm'" << endl;
	string inp;
	cin >> inp;
	system("cls");
	if (inp == "p")
	{
		system("cls");
		Menu m2;	
		m2.data_save();
		m2.load();
	}
	else if (inp == "m")
	{
		system("cls");
		Menu m2;
		m2.data_save();
		m2.menu();
	}
	else
	{
		choice();
	}

}


