#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <typeinfo>
#include <string>
#include <ctime>
#include <utility>
#include "printSTL.h"

// C++17

using namespace std;

/*
	set (zbiór), multiset (multizbiór) to kontener asocjacyjny, porządkujący/sortujący.
	W set element może wystąpić tylko raz. Dla multiset, elementy mogą się powtarzać i także zachowują porządek. Zbiór to zazwyczaj zrównoważone drzewo binarne. Dlatego plusem jest:
	+ szybkie wyszukiwanie elementów o określonej wartości!
	Zbiór jest automatycznie sortowany wg ustalonych kryteriów. Elementy w zbiorze niezależnie od typu powinny dać się posortować. Porządkowanie musi mieć właściwości:
	* asymetryczne (gdy x<y jest prawdą, to y<x jest fałszem i odwrotnie),
	* przechodnie (x<y i y<z to x<z) (równoważność też musi być przechodnia, a=b i b=c to a=c)
	* niezwrotne (x<x to zawsze fałsz)
	
	Automatyczne sortowanie w zbiorze ma jednak i wady: 
	- w c++11 bezpośrednia zmiana przechowywanych wartości w zbiorze może zaburzyć drzewo binarne (element usuwało się i wkładało ponownie, a iterator widzi elementy jako stałe). W c++17 są pewne rozwiązania, które to obchodzą.
	
*/

int main() {				
	// elementami są obiekty typu string, można je porządkować
	set<string> snames{ "Kowalski","Nowak","Brzężyszczykiewicz","Kowalski" };
	printSTL(snames,", ");	
	snames.insert({ "Kowalski", "Adamski", "Piotrowski", "Zenonkowski", "Kowalski" });
	printSTL(snames,", ");
	// insert pojedyńczego elementu zwraca parę <iterator,bool> gdzie iterator to pozycja po wstawieniu, o ile się udało (jak już był element to się nie uda)	
	auto [pos, success] = snames.insert("Uf");
	cout << *pos << " " << success << endl;
	if (!snames.insert("Uf").second) cout << "już jest!" << endl;
	
	auto [pos2,success2] = snames.insert("Kowalski");
	cout << *pos2 << " " << success2 << endl;
	

	// elementami jest int, można porządkować
	set<int, greater<int>> mono = { 2,3,4,1,2,5,5,3,6,7,8,11,24 }; /// drugi parametr greater<int> zmienia sposób sortowania dla kontenerów porządkujących . Domyślny jest sposób less<>. greater i less to OBIEKTY funkcyjne (wkrótce o nich). Teraz można myśleć o nich jako o narzędziu sortującym obiekty w momencie wkładania ich do zbioru.	
	printSTL(mono,", "); //  uporządkowane malejąco

	set<int, less<int>> mono2 = { 2,3,4,1,2,5,5,3,6,7,8,11,24 }; // less jest domyślne ale tutaj użyłem go jawnie
	printSTL(mono2, ", ");
	if (!mono2.empty()) cout << "Nie jestem pusty!\n";
	mono2.clear();
	printSTL(mono2, ": ");
	
	/// count(), find(), lower_bound(), upper_bound(), equal_range()
	// insert, erase, clear
	   

	// elementami są obiekty string, a więc da się je porządkować. multiset może mieć wiele elementów identycznych, pamiętaj o tym. Też są porządkowane.
	multiset<string> dogs{ "Burek","Reksio","Burek","Reksio","Pyra","Apofis" };
	printSTL(dogs," ");
	dogs.insert({ "Burek","Żulek" }); // Nowy wstawia się na KONIEC istniejących a takich samych elementów. Taki insert nic nie zwraca.
	printSTL(dogs," "); 	
	
	// emplace - wstaw i pokaż gdzie
	auto insertIt = dogs.emplace("Dżdżon"); // wstawia kopie i zwraca pozycję
	cout << *insertIt << endl; // iterator pozycji wstawionej	
	printSTL(dogs, ",");

	// count()
	cout << dogs.count("Burek") << endl; // ile Burków ?

	// find() - zwraca pozycję pierwszego elementu
	multiset<string>::iterator it = dogs.find("Reksio");
	if (it != dogs.end()) {
		cout << *it << endl;		
		dogs.erase(it);
		printSTL(dogs, ", ");
	}	


	it = dogs.lower_bound("Burek"); // iterator na pierwszy element >= "Burek"
	cout << *it << endl;
	// a tu takie info, że w sumie i find i lower_bound robią przy takim wywołaniu to samo i zwracają dokładnie ten sam iterator
	cout << (dogs.find("Burek") == dogs.lower_bound("Burek")) << endl;
	

	it = dogs.upper_bound("Burek"); // iterator na pierwszy element > "Burek"
	cout << "Za Burkiem: " << *it << endl;
	

	// zwraca parę: lower_bound + upper_bound
	auto [first, last] = dogs.equal_range("Burek");
	cout << *first << " " << *last << endl;
	while (first != last) { // idę od operatora first do last (bez last) i pokazuje co tam jest
		cout << *first << " ";
		first++;
	} // będą same Burki
	
	
}