#include "Game.h"
#include"Menu.h"
#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

void Game::print(string mess) // metoda s³uzaca do zapisu "na œrodku" w trakcie gry (40 znaków przerwy-"napis"-40znaków przerwy)
{	
	bool front = true;
	for (int i = mess.length(); i < 40; i++)// 40 liczba odstepow
	{
		if (front)
		{
			mess = " " + mess; // miejsce lewo
		}
		else
		{
			mess = mess + " "; // miejsce prawo
		}
		front = !front;
	}
	cout << mess.c_str() << endl ;
}
void Game::draw(int guess_count)// metoda sluzaca do rysowania wisielca, obslugiwana przez counter liczby podanych blednych liter
{
	if (guess_count >= 1)
	{
		print("|");
	}
	else
	{
		print("");
	}
	if (guess_count >= 2)
	{
		print("|");
	}
	else
	{
		print("");
	}
	if (guess_count >= 3)
	{
		print("O");
	}
	else
	{
		print("");
	}
	if (guess_count == 4)
	{
		print("/  ");
	}
	if (guess_count == 5)
	{
		print("/| ");
	}
	if (guess_count >= 6)
	{
		print("/|\\");
	}
	else
	{
		print("");
	}
	if (guess_count >= 7)
	{
		print("|");
	}
	else
	{
		print("");
	}
	if (guess_count == 8)
	{
		print("/ ");
	}
	if (guess_count == 9)
	{
		print("/ \\");
	}
	else
	{
		print("");
	}
	
}

void Game::letters(string input, char from, char to)// metoda odpowiedzialna za usuwanie liter z puli po ich uzyciu
{
	string s;
	for (char i = from; i <= to; i++)
	{
		if (input.find(i) == string::npos) // jezeli podany znak lub ciag znakow bedzie taki sam jak z zestawu to kasuje litere
		{
			s += i;
			s += " ";
		}
		else
		{
			s += " ";
		}
	}
	print(s);
}
void Game::print_letters(string taken)// metoda odpowiedzialna za wypisanie liter na panelu
{
	letters(taken, 'a', 'm');
	letters(taken, 'n', 'z');
}
bool Game::word_check(string word, string guessed)// metoda odpowiedzialna za wpisywanie odgadnietych liter w wyznaczonym miejscu oraz
{													// za stworzenie "_" o ilosci wylosowanego slowa
	bool won = true;
	string s;
	for (int i = 0; i < word.length(); i++)
	{
		if (guessed.find(word[i]) == string::npos)
		{
			won = false;
			s += "_ ";
		}
		else
		{
			s += word[i];
			s += " ";
		}
	}
	print(s);
	return won;
}
string Game::load_words(string path)// metoda odpowiedzialna za zaladowanie losowego slowa z pliku
{
	int count_line = 0;
	string word;
	vector<string> v;
	ifstream reader(path);
	if (reader.is_open())
	{
		while (getline(reader, word))
			v.push_back(word);

		int random_line = rand() % v.size();

		word = v.at(random_line);
		reader.close();
	}
	return word;
}
int Game::tries(string word, string guessed)// metoda zliczajaca ilosc prob
{
	int error = 0;
	for (int i  = 0; i < guessed.length(); i++)
	{
		if (word.find(guessed[i]) == string::npos)
			error++;
	}
	return error;
}
