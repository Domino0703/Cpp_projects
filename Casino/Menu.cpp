#include "Menu.h"
#include"Game.h"
using namespace std;

void Menu::menu()
{
	cout << "============================================================" << endl;
	string input;
	fstream file;
	file.open("kasyno.txt", ios::in);
	string logo;
	while (getline(file, logo))
	{
		cout << logo << endl;
	}
	cout << "============================================================"<< endl;
	cout << "1.Start" << endl;
	cout << "2.O grze" << endl;
	cout << "3.O autorze" << endl;
	cout << "4.Statystyki" << endl;
	cout << "5.Reset statystyk" << endl;
	cout << "6.Gracze" << endl;
	cout << "7.Wyjscie" << endl;
	cout << "============================================================"<< endl;
	cin >> input;
	if (input == "1")
	{
		system("cls");
		name();
		list();
		system("cls");
		load();
	}
	else if (input == "2")
	{
		info();
	}
	else if (input == "3")
	{
		autor();
	}
	else if (input == "4")
	{
		stat();
	}
	else if (input == "5")
	{
		reset();
	}
	else if (input == "6")
	{
		open();
	}
	else if (input == "7")
	{
		exit(0);
	}
	else
	{
		system("cls");
		menu();
	}
}

void Menu::info()
{
	system("cls");
	cout << "Gra zostala stworzona w ramach projektu na zajecia z Jezykow Programowania." << endl;
	cout << "Ma ona charakter rozrywkowy." << endl;
	cout << "Jest to prosty symulator kasyna, w ktorym wplacasz pewna kwote na gre i twoim zadaniem jest" << endl;
	cout << "odgadniecie jednej z 10 liczb. Jesli wybierzesz prawidlowo to twoj depozyt zostanie powiekszony dziesieciokrotnie." << endl;
	cout << "Milej zabawy" << endl;
	cout << "Nacisnij ENTER aby przejsc do menu. ";
	cin.get();
	cin.get();
	system("cls");
	menu();
}
void Menu::autor()
{
	system("cls");
	cout << "Autor - Dominik Gorny" << endl;
	cout << "Kierunek - Elektronika" << endl;
	cout << "Grupa 1" << endl;
	cout << "Nacisnij ENTER aby przejsc do menu. " << endl;
	cin.get();
	cin.get();
	system("cls");
	menu();
}
void Menu::stat()
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
	menu();
}
void Menu :: load()
{
	system("cls");
	tries();
	float m;
	int n;
	cout << "Podaj kwote, ktora chcesz wplacic:" << endl;
	while (!(cin >> m))
	{
		system("cls");
		cout << "Blad! Podaj kwote jeszcze raz :";
		cin.clear();
		cin.ignore(99999, '\n');
	}
	cout << "Podaj liczbe od 1 do 10: " << endl;
	while (!(cin >> n))
	{
		system("cls");
		cout << "Blad! Ponownie podaj liczbe z zakresu 1-10 :";
		cin.clear();
		cin.ignore(99999, '\n');
	}
	if (n > 10 || n < 1)
	{
		cout << "Blad. Nacisnij ENTER aby sprobowac jeszcze raz." << endl;
		cin.get();
		cin.get();
		system("cls");
		lose();
		data_save();
		load();
	}
	else
	{
		Game g2(m, n);
		g2.compare();
	}
}
int Menu::l = 0;
int Menu::w = 0;
int Menu::a = 0;


void Menu::win()
{
	 w++;
}
void Menu::lose()
{
	 l++;
}
void Menu::tries()
{
	a++;
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
	file_1.open("save.txt",ios::out);
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
	menu();
}
vector<string> player;
void Menu::name()
{
	cout << "Podaj imie: ";
	string f_name;
	cin >> f_name;
	player.push_back(f_name);
}
void Menu::list()
{
	fstream file;
	file.open("players.txt", ios::out);
	for (int i =0; i<player.size(); i++)
	{
		file <<i+1<<"."<< player[i] << endl;
	}
	file.close();
}
void Menu::open()
{
	system("cls");
	cout << "Lista wszystkich graczy w sesji:"<< endl;
	fstream file;
	file.open("players.txt", ios::in);
	string logo;
	while (getline(file, logo))
	{
		cout << logo << endl;
	}
	cout << "Nacisnij ENTER aby wrocic do menu";
	cin.get();
	cin.get();
	system("cls");
	menu();
}

