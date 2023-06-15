#include "Menu.h"
#include "Game.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

Menu::Menu(int triess, bool win)
{
	m_triess = triess;
	m_win = win;
}

void Menu::color(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}

void Menu::gotoxy(int x, int y)// metoda odpowiedzialna za ustalenie pozycji na konsoli
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Menu::start()
{	
	system("cls");
	attempts();
	data_save();
	srand(time(NULL));
	m_triess = 0;
	string word_to_guess;
	string guesses;
	Game g1;
	word_to_guess = g1.load_words("words.txt");
	do
	{
		system("cls");
		g1.print("--------------------------");
		g1.print("Dostepne litery");
		g1.print("--------------------------");
		g1.print_letters(guesses);
		g1.print("--------------------------");
		g1.draw(m_triess);
		g1.print("---------------------------");
		g1.print("1 - wyjscie do menu glownego");
		g1.print("---------------------------");
		m_win = g1.word_check(word_to_guess, guesses);
	
		if (m_win)
			break;

		char x;
		cout << ">";
		cin >> x;
		if (guesses.find(x) == string::npos)
			guesses += x;

		m_triess = g1.tries(word_to_guess, guesses);

		if (x == '1')
		{
			play();
		}
		

	} while (m_triess < 10);

	if (m_win)
	{
		system("cls");
		wins();
		data_save();
		fstream file;
		file.open("win.txt", ios::in);
		string information;
		while (getline(file, information))
		{
			cout << information << endl;
		}
		cin.get();
		cin.get();
		play();
	}
	else
	{
		system("cls");
		loses();
		data_save();
		fstream file;
		file.open("lose.txt", ios::in);
		string information;
		while (getline(file, information))
		{
			cout << information << endl;
		}
		cin.get();
		cin.get();
		play();
	}
}
int Menu::l;
int Menu::w;
int Menu::a;

void Menu::wins()
{
	w++;
}
void Menu::loses()
{
	l++;
}
void Menu::attempts()
{
	a++;
}

void Menu::stats()
{
	system("cls");
	data_load();
	cout << "Statystyki" << endl;
	cout << "Liczba prob : " << a << endl;
	cout << "Liczba wygranych : " << w << endl;
	cout << "Liczba przegranych : " << l << endl;
	cout << "Nacisnij ENTER aby przejsc do menu ";
	cin.get();
	cin.get();
	system("cls");
	play();
}
void Menu::data_load()
{
	fstream file_2;
	file_2.open("save.txt", ios::in);
	if (file_2.good())
	{

	}
	string line;
	int n_line = 1;
	while (getline(file_2, line))
	{
		switch (n_line)
		{
		case 1: a = stoi(line); break;
		case 2: w = stoi(line); break;
		case 3: l = stoi(line); break;
		}
		n_line++;
	}
	file_2.close();

}
void Menu::data_save()
{
	fstream file_1;
	file_1.open("save.txt", ios::out);
	file_1 << a << endl;
	file_1 << w << endl;
	file_1 << l << endl;

	file_1.close();
}
void Menu::reset()
{
	system("cls");
	fstream file_1;
	file_1.open("save.txt", ios::out);
	file_1 << 0 << endl;
	file_1 << 0 << endl;
	file_1 << 0 << endl;
	a = 0;
	w = 0;
	l = 0;

	file_1.close();
	cout << "Twoje statystyki zostaly zresetowane. Nacisnij ENTER aby wrocic do menu";
	cin.get();
	cin.get();
	system("cls");
	play();
}

void Menu::info()
{
	system("cls");
	fstream file;
	file.open("informacja.txt", ios::in);
	string information;
	while (getline(file, information))
	{
		cout << information << endl;
	}
	cin.get();
	play();
}


void Menu::play()
{
	int Set[] = { 7,7,7,7,7 };
	int counter = 3;
	char key;
	system("cls");
	fstream file;
	file.open("logo.txt", ios::in);
	string logo;
	while (getline(file, logo))
	{
		cout << logo << endl;
	}

	for (int i =0;;)
	{
		gotoxy(60,7);
		color(Set[0]);
		cout << "Start";

		gotoxy(60, 8);
		color(Set[1]);
		cout << "Info";

		gotoxy(60, 9);
		color(Set[2]);
		cout << "Statystyki";

		gotoxy(60, 10);
		color(Set[3]);
		cout << "Reset statystyk";

		gotoxy(60, 11);
		color(Set[4]);
		cout << "Wyjscie";

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 6))
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 5))
		{
			counter++;
		}
		if (key == '\r')
		{
			switch (counter)
			{
			case 1:
				start();
				break;
			case 2:
				info();
				break;
			case 3:
				stats();
				break;
			case 4:
				reset();
				break;
			case 5:
				exit(0);
				break;
			}
			break;
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;

		if (counter == 1)
		{
			Set[0] = 2;
		}
		if (counter == 2)
		{
			Set[1] = 2;
		}
		if (counter == 3)
		{
			Set[2] = 2;
		}
		if (counter == 4)
		{
			Set[3] = 2;
		}
		if (counter == 5)
		{
			Set[4] = 2;
		}

		
	}
	
}
