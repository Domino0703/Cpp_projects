#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

class IGate 
{
public:
    virtual int evaluate() = 0;
    ~IGate() {};
};


class Gate : public IGate
{
private:
    map<int,int> &Nodes;
public:
    Gate(map<int, int> &nodes): Nodes(nodes) {}
    map<int,int>& getGate(void){
        return Nodes;
    }
};

class AndGate : public Gate
{
private:
    int In1;
    int In2;
    int Out;
public:
    AndGate(int in1, int in2, int out, map<int, int> &nodes) : 
        In1(in1), In2(in2), Out(out), Gate(nodes) {}
    int evaluate(){

        map<int,int> &nodes = getGate();

       if ((nodes[In1] == -1) || (nodes[In2] == -1))
		{
			nodes[Out] = -1;
			return -1;
		}
		else if (nodes[In1] == nodes[In2])
		{
			nodes[Out] = 0;
			return 0;
		}
		else
		{
			nodes[Out] = 1;
			return 1;
		}
    }
};

class OrGate : public Gate
{
private:
    int In1;
    int In2;
    int Out;
public:
    OrGate(int in1, int in2, int out, map<int, int> &nodes) : 
        In1(in1), In2(in2), Out(out), Gate(nodes) {}
    int evaluate(){

        map<int,int> &nodes = getGate();

        if ((nodes[In1] == -1) || (nodes[In2] == -1))
		{
			nodes[Out] = -1;
			return -1;
		}
		else if ((nodes[In1] == 0) && (nodes[In2] == 0))
		{
			nodes[Out] = 0;
			return 0;
		}
		else
		{
			nodes[Out] = 1;
			return 1;
		}
    }
};
class XorGate : public Gate
{
private:
    int In1;
    int In2;
    int Out;
public:
    XorGate(int in1, int in2, int out, map<int, int> &nodes) : 
        In1(in1), In2(in2), Out(out), Gate(nodes) {}
    int evaluate(){

        map<int,int> &nodes = getGate();

        if ((nodes[In1] == -1) || (nodes[In2] == -1))
		{
			nodes[Out] = -1;
			return -1;
		}
		else if (nodes[In1] == nodes[In2])
		{
			nodes[Out] = 0;
			return 0;
		}
		else
		{
			nodes[Out] = 1;
			return 1;
		}
    }
};
class NotGate : public Gate
{
private:
    int In1;
    int Out;
public:
    NotGate(int in1, int out, map<int, int> &nodes) : 
        In1(in1), Out(out), Gate(nodes) {}
    int evaluate(){

        map<int,int> &nodes = getGate();

        if (nodes[In1] == -1)
		{
			nodes[Out] = -1;
			return -1;
		}
		else if (nodes[In1] == 1)
		{
			nodes[Out] = 0;
			return 0;
		}
		else
		{
			nodes[Out] = 1;
			return 1;
		}
    }
};
void print_nodes(const map<int, int>& nodes)
{
	cout << "\nSymuluje uklad kombinacyjny...\nStany wszystkich wezlow:\n[indeks: stan]" << endl;
	for (pair<int, int> element : nodes)
	{
		int wezel = element.first;
		int stan = element.second;
		cout << wezel << ": " << stan << endl;
	}
}


int main()
{
   	string text;

	vector<Gate *> gates;
	map<int, int> nodes;

	/* Dodawanie bramek */
	bool stop = false;
	while (stop == false)
	{
		int in1, in2, out; //zmienne pomocnicze w petli
		cout << "Podaj typ bramki [and/or/xor/not] Zeby zakonczyc wpisz [end].\n";

		cout << "Typ: ";
		cin >> text;
		if (text == "end") //koniec
		{
			stop = true;
			break;
		}
		else
		{
			cout << "Podaj indeksy wejsc i wyjsc." << endl;
			if (text == "and" || text == "or" || text == "xor") // And/Or/Xor
			{
				cout << "wejscie1: ";
				cin >> in1;
				cout << "wejscie2: ";
				cin >> in2;

			}
			else if (text == "not") //Not
			{
				cout << "wejscie1: ";
				cin >> in1;

			}
		}
		
		/** Indeksy we/wy **/
		cout << "wyjscie: ";
		cin >> out;
		cout << endl;

		/** Dodawanie podanych bramek do listy(vector) **/
		if (text == "not") //Not
		{
			NotGate* bramka = new NotGate(in1, out, nodes);
			gates.push_back(bramka);
		}
		else if(text == "and") //And
		{
			AndGate* bramka = new AndGate(in1, in2, out, nodes);
			gates.push_back(bramka);
		}
		else if(text == "or") //Or
		{
			OrGate* bramka = new OrGate(in1, in2, out, nodes);
			gates.push_back(bramka);
		}
		else if(text =="xor") //Xor
		{
			XorGate* bramka = new XorGate(in1, in2, out, nodes);
			gates.push_back(bramka);
		}


		nodes[in1] = -1;
		if (text != "not")
			nodes[in2] = -1;
		nodes[out] = -1;
	}


	stop = false;
	while (stop == false)
	{
		int wezel, stan;
		cout << "\nWprowadz stany [0/1] dla wezlow o podanych indeksach.  Wpisz indeks [-1] zeby zakonczyc.\n";
		cout << "Indeks: ";
		cin >> wezel;
		if (wezel == -1)
		{
			stop = true;
			break;
		}

		cout << "Stan: ";
		cin >> stan;

		nodes[wezel] = stan; //przypisuje wprowadzony stan odpowiedniemu wezlowi
	}
	

	/* Symulacja obwodu z bramkami */
	for (pair<int, int> element : nodes)
	{
		if (element.second == -1)
			for (size_t i = 0; i < gates.size(); i++)
			{
				Gate &temp = *gates[i];
				temp.evaluate();
			}
	}


	/** Wypisanie stanow na w�z�ach **/
	print_nodes(nodes);

	system("pause");
	return 0;
};