#pragma once

class Menu
{
private:
	int m_triess;// pole odpowiadajace liczbie podanych liter w jednej grze
	bool m_win;// pole odpowiadajace za informacje o wyniku gry
public:
	static int l; // zmienna do porazek
	static int w; // zmienna do wygranch
	static int a; // zmienna do prob
	Menu(int triess = 0, bool win = false);// konstruktor
	void color(int clr);// podswietla wybrane opcje w menu gry
	void gotoxy(int x, int y);// ustawia wspolrzedne opcji w menu gry
	void play();//obs³uga menu
	void start();// metoda rozpoczynajca gre i odpowiadajaca za jej przebieg
	void info();// informacja o projekcie
	void stats();// statystyki
	void reset();// reset statystyk
	void data_save();// metoda do zapisu danych statycznych
	void data_load();// metoda do zaladowania danych statycznych
	void wins();// licznik zwyciestw
	void loses();// licznik przegranych
	void attempts();// licznik prob
};

