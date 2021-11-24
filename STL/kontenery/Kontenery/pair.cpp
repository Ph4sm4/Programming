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
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {	
	// para łączy dwa elementy w jeden, jest wykorzystywana 
	// w kontenerach np: map, multimap, unordered_map i undordered_multimap;	
	
	pair<int, int> p1 (5, 10);
	cout << typeid(p1).name() << endl;

	auto p2(p1); // kontruktor kopiujący (z p1)
	//printSTL(p2, " ");
	pair<double, double> pd( p1 );
	//printSTL(pd, " ");
	
	// .first : pierwsza wartość pary
	// .second : druga wartość pary
	cout << p1.first << " " << p1.second << endl;	 // 5,10
	++p2.second;
	cout << p2.first << " " << p2.second << endl; // 5,11

	// porównywanie par to porównanie kolejnych wartości first i potem second
	cout << (p1 == p2) << (p1 != p2) << (p1 > p2) << (p1 < p2) << endl;  // 5,10 vs 5,11
	p2.first = 2;
	cout << (p1 == p2) << (p1 != p2) << (p1 > p2) << (p1 < p2) << endl; // 5,10 vs 2,11

	cout << &p1 << " " << &p2 << endl; 
	p1.swap(p2); // podmianka wartości
	cout << &p1 << " " << &p2 << endl; // adresy się nie zmieniły...		
	cout << p1.first << " " << p1.second << endl; // ... ale wartości tak
	cout << p2.first << " " << p2.second << endl; 

	// make_pair : tworzy parę i nadaje się do inicjacji zmiennej z typem auto
	auto p3 = make_pair(1.0, string("Kaszanka jest smaczna.")); // tworzę parę double->string
	cout << typeid(p3).name() << endl;
	//printSTL(p3, " ");	

	// pareczka z int'a i ... wektora :) bo para nie musi być złożona z prostych typów
	auto p4 = make_pair(10, vector<int>{100, 200, 300}); 
	cout << typeid(p4).name() << endl;
	cout << p4.first << " " << p4.second[2] << endl;

	// klasyczny wskaźnik
	pair<string, string>* p_ptr;
	p_ptr = new pair<string, string>;
	p_ptr->first = "RAZ"; // -> zamiast .
	p_ptr->second = "DWA";
	//printSTL(*p_ptr);	

	// zdefinuję sobie taki 'alias' na typ pair<string,double> i nazwę go myPairType
	typedef pair<string, double> myPairType;	
	myPairType p_ptr2{ "ABC",10.5 };	
	//printSTL(p_ptr2, " ");

	// pary mogą być tworzone z niejawnie podanym typem (c++17)
	// nie muszę pisać pair<string,double> ! typ jest niejawny utworzony przy inicjacji
	pair <string, float> pshort(string("first"), 100.95f); // nie ma auto, nie ma make_pair
	//printSTL(pshort, " ");
	cout << typeid(pshort).name() << endl;
}
