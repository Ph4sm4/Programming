#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma końcami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbiór
#include <map> // asocjacyjne kontenery 
#include <unordered_set>
#include <unordered_map> 
#include <stack> // stos
#include <queue> // kolejka
#include <algorithm> // algorytmy
#include <typeinfo> // typeid
#include <type_traits> // cechy typowe
#include <bitset> // bitset
#include <utility> // np. pair
#include <tuple> // krotki tuple
#include <memory> // inteligentne wskaźniki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // wątki 
#include <ctime>
#include "printSTL.h"


// C++17		

using namespace std;
int main() {				
/*
	array - tablica, do korzystania w miejsce tablic z C.

	Kontenery sekwencyjne (kolekcje uporządkowanane) cechuje to, że
	każdy element w kontenerze ma określoną pozycję zależną od momentu wstawienia
	i miejsca wstawienia i niezależną od wartości wkładanej do kontenera.

	array to prosty przedstawiciel takich kontenerów. 
	Tablica (array) musi przy tworzeniu mieć jasno określoną ilość elementów,
	bo nie można zmieniać jej wielkości a tylko wartość elementów.
	Do elementów tablicy dostęp mamy przez indeks/pozycję w tablicy.
	Array przechowuje dane w sposób zwarty, dokładnie jak tablica z C,
	ale dodaje lepszą kontrolę i jest częścią kontenerów STL'owych.
	
	Tablice były jeszcze w języku C i z racji na prostą konstrukcję tej starszej wersji
	tablicy korzystam z niej w edukacji dla początkujących do teraz.	
	Kiedy celem jest poznania samej idei programowania, 
	bardziej abstrakcyjny/skomplikowany zapis staje się barierą i rośnie
	prób wejścia w język. Czym innym jest bowiem zrozumienie idei programowania 
	a niekiedy czym innym dokładne poznanie jakiegoś języka. 
	Niestety w procesie	edukacji te dwa elementy 
	(w przypadku skomplikowanego języka jakim jest C++) stanowią (na początku!) trudne
	do pogodzenia zagadnienia i przyznaję - nie wiem do końca, jak to mądrze pogodzić.
	Dlatego np.: ukazuję ideę tablicy jeszcze z języka C, a potem powoli przechodzę
	do kontenerów, takich jak array.

	
*/
		/// TAKI "wklęsły" kod będę omijał - jest jako pewne informacja do wglądu
		/// samodzielnego, ale nie jest potrzebny do zagadnienia jako takiego
		/// tablica jeszcze z C, tak dla przypomnienia
		int ctab[2];
		ctab[0] = 5; ctab[1] = 10;
		cout << ctab[0] << " " << --ctab[1] << endl; // 5 i 9

// O! Takiej tablicy powinniśmy używać (tak się zaleca) 
// (nie, że się do kogoś zaleca, tylko się zaleca, jasne chyba...)
	// 6 elementów, ale inicjuję tylko 3, reszta będzie domyślnie pustym napisem
	array<string, 6> names{ "Janusz", "Grażyna", "Czesiek" };

	// poruszanie po tablicy może być po indeksie
	for (int i = 0; i < names.size(); i++)
		cout << i << ":=" << names[i] << " " << endl;

	// albo bardziej elegancko: e stanie się każdym elementem 
	// z tablicy (array) names (kopią kolejnych) | auto domyśli się typu z kontekstu
	for (auto e : names) cout << e << " ";
	cout << endl;
	// jak wyżej, ale referencja (zmiana e zmieni elementy names)
	for (auto& e : names) cout << e << " ";
	cout << endl;
	printSTL(names, " ", true); // a tu moja funkcyjka	

	// Jak nie można inicjować tablicy?
	// int a4 = 10; 
	// array<int, a4> tab1{ 1,2,3 }; // nie pójdzie, bo a4 nie jest stałe
	
	// ITERATOR to obiekty wskazujące na elementy w kontenerach. Można o nich 
	// myśleć, jak o wskaźnikach - ale to nie jest wskaźnik w rozumieniu języka C (*)
	// chociaż korzysta np. z operatora wyłuskania :) 
	// ITERATORY dokładniej omówię w odcinkach poświęconych WEKTOROM, ok?
	// teraz tylko zajawka
	cout << "Korzystam z iteratorów: ";
	for (auto iterator = names.begin(); iterator != names.end(); iterator++) {
		cout << *iterator << " "; // *iterator - wyłuskuję to, na co wskazuje iterator		
	} 
	cout << endl;
	// iterator++ przesuwa się na następny element, przypomina to ruch jak w liście 
	// jednokierunkowej, w praktyce to po prostu kolejny element w tablicy
	
	// a taki typ ma ów iterator...
	auto it = names.begin(); // it będzie typu jak nasz iterator na pierwszy element
	cout << typeid(it).name() << endl; // nasz iterator taki ma typ w przypadku names

	array<int, 20>tab{ 1,2,3 }; // 20 elementów, pierwsze to 1,2,3 a potem same 0	
	cout << "tab.size()=" << tab.size() << endl;
	printSTL(tab, " ", false);

	// warto korzystać z metody .at(indeks) bo		
	cout << tab.at(0) << endl; // kontrola zakresu, będzie błąd zgłoszony
	// cout << tab.at(20) << endl; // kontrola zakresu, będzie błąd zgłoszony
	// cout << tab[20] << endl; // brak kontroli zakresu, gdy korzystamy z []

	cout << tab.front() << endl; // pierwszy (nie iterator, wartość przechowywana)
	cout << tab.back() << endl; // ostatni (nie iterator, ostatnia wartość)

	
	
}









