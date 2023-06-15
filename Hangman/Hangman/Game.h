#pragma once
#include<iostream>
#include<string.h>

using namespace std;

class Game
{
public:

	void print(string mess);// metoda sluzaca do zapisu ciagu znakow w odpowiednim miejscu
	void draw(int guess_count);// metoda sluzaca do rysowania wisielca, obslugiwana przez counter liczby podanych blednych liter
	void letters(string input, char from, char to);// metoda odpowiedzialna za usuwanie liter z puli po ich uzyciu
	void print_letters(string taken);// metoda odpowiedzialna za wypisanie dostepnych liter na konsoli
	bool word_check(string word, string guessed);// metoda odpowiedzialna za wpisywanie odgadnietych liter w wyznaczonym miejscu
	string load_words(string path);// metoda odpowiedzialna za zaladowanie losowego slowa z pliku
	int tries(string word, string guessed);// metoda zliczajaca ilosc prob
};

