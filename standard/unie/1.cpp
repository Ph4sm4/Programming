#include<iostream>
using namespace std;

union liczba{
	int calkowita;
	double rzeczywista;
};

struct samochod{
	char marka[20];
	char model[20];
	int rocznik;
	liczba pojemnosc;
};

int main()
{
	samochod renault;
    liczba a,b;

    a.calkowita = 5;
    b.rzeczywista = 10;
    cout<<a.calkowita<<endl;
    cout<<b.rzeczywista<<endl;
	
	cout<<"Podaj mark©: ";
	cin>>renault.marka; //odwoˆujemy si© za pomoc¥ operatora "."
	
	cout<<"Podaj pojemnosc: ";
	cin>>renault.pojemnosc.rzeczywista; //odwoˆujemy si© za pomoc¥ operatora "."
	
	//wypisanie danych
	cout<<"Marka: "<<renault.marka<<endl;
	cout<<"Pojemno˜†: "<<renault.pojemnosc.rzeczywista<<endl;

	return 0;
}