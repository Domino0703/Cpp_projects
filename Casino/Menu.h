#pragma once
#include <iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
class Menu
{

public:
	static int l; // zmienna do porazek
	static int w; // zmienna do wygranch
	static int a; // zmienna do prob
	void menu();  // obsu³ga menu
	void info();  // informacja na temat gry
	void autor();  // informacje o autorze
	void stat();  // statystyki
	void load();  // wczytywanie danych
	void win(); // metoda liczaca liczbe wygranych
	void lose(); // metoda liczaca liczbe przegranych
	void tries(); // metoda liczaca liczbe prob
	void data_load(); // metoda do ladowania danych statystycznych
	void data_save(); // metoda do zapisywania danych statystycznych
	void reset(); // resetowanie statysyk
	void name(); // wpisanie imieni do vektora
	void list(); // zapisywanie wektora do pliku
	void open(); // odczytywanie wektora z pliku
};

