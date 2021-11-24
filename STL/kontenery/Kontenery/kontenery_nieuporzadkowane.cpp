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
#include "printSTL.h"

// C++17
using namespace std;

/*

Kontenery nieporządkujące implementowane są jako tablice mieszające (a nie drzewa binarne!).
Istnieje tylko operator ++ (w przód). Nie ma np. rbegin(), rend().
Operacji dostępu do elementu w mapie nieuporządkowanej jest zamortyzowany i stały bez względu na długość i pozycję.

*/
/*
	Małe wyjaśnienie ogólne. Ucząc się C++ niekiedy trzeba się "cofać" i powtarzać (albo pogłębiać) rozumienie pewnych elementów. Dzieje się tak dlatego, że wiele elementów języka jest mocno powiązanych i chcąc dogłębnie wytłumaczyć jedną rzecz, musielibyśmy tłumaczyć powiązania, a te z kolejnymi powiązaniami itd. Dlatego niekiedy pewne rzeczy omawiam krótko a nawet nie omawiam, zostawiając tylko pewną ogólną informację. W innym odcinku będzie to pewnie wyjaśnione. Wtedy warto wrócić do wcześniejszego odcinka - wiedza się uzupełni, a potem pogłębi i z każdym kolejnym elementem rozumienie działania różnych technik będzie pełniejsze. Uczenie się (w tym uczenie C++ szczególnie) przypomina trochę fale przypływu. Wchodzimy w temat trochę (żeby zacząć, żeby już coś umieć), potem się cofamy, potem podchodzimy do tematu znowu, ale trochę głębiej. Każda kolejna fala niby robi coś podobnego, ale zagłębia się w ląd i poziom wody się podnosi. I o to chodzi!
	Przeglądałem kilka podręczników do C++ i sporo z nich jest zorganizowane mniej więcej tak:
	- 1 część: ogólnie o wszystkim, ale płytko, bez wchodzenia w szczegóły
	- 2 część: dokładniej, pokazując zależności, tłumacząc więcej, ale wciąż pozostawiając pytania
	- 3 część: do końca, cała specyfikacja (jednak i tu nie ma wszystkiego, dlatego często pełne rozumienie jakiejś funkcji/biblioteki/kodu wymaga po prostu STUDIOWANIA KODU, ŹRÓDŁA itp.)
	(mówiłem o tym w jednej z lekcji)
*/

namespace hehe_space {
	const int ABC = 100;
}

struct myKey {
	string a;
	string b;
};
namespace std {
	bool operator==(const myKey& l, const myKey& r) { // operator porównania dwóch elementów myKey
		return l.a == r.a && l.b == r.b;
	}
	template <>
	class hash<myKey> { // klasa hash'ująca, oblicza do jakiego kubełka trafi element myKey
	public:
		using argument_type = myKey;
		using result_type = size_t;
		result_type operator()(const argument_type& c) const {
			size_t suma = 0;
			for (auto& znak : c.a) suma += znak;
			for (auto& znak : c.b) suma += znak;
			cout << "("<<suma<<")\n";
			return static_cast<result_type>(suma); // to nie jest za mądre, ale przykład ok
			// elementy są przypisane do tego hash'a (pokażę na rysunku !) HASH powinien być tak obliczany, aby było jak najmniej powtórzeń dla elementu. static_cast to rzutowanie, omówimy w przyszłości
		}
	};
	// bucket_count() - ilość kubełków :)
	// rehash(n) - przemieszanie i ustawienie conajmniej n kubełków
	// reserve(n) - przemieszanie kontenera by było miejsce dla minimum n elementów
	// max_load_factor(0.7) - wartość do 1, ustawia maksymalny współczynnik obciążenia 0.7,0.8 OK
	// max_load_factor() - zwraca ten maksymalny współczynnik
	// load_factor() - zwraca obecny współczynnik obciążenia
	// Uwaga! Można się dobrać do tych kubełków metodami:
	// bucket(val) - id kubełka dla wartości val
	// begin(id_bucket) - zwraca iterator na element o podanym id kubełka
	
}
void _021() {	
	// definiowanie czegoś-tam we własnej przestrzeni (tak przy okazji)
	cout << hehe_space::ABC << endl; // ABC z przestrzeni hehe_space::
	// ABC; // bez hehe_space:: nie jest znane!

	/// unordered_set, unordered_multiset (nieuporządkowane zbiory i multizbiory)
	unordered_set<int> uset;
	uset = { 1,2,5,6,7,7,2,1,1,4,4,1 }; // elementy będą występować tylko RAZ i w nieuporządkowany sposób ...
	printSTL(uset,",",true); // ... oto dowód.
	uset.insert({ 1, 2, 3, 100, 1, 100 }); // 1 i 2 już było, 3 i 100 się wstawią
	printSTL(uset, ",", true); // zwróć uwagę, że elementy nie są zgodne z sekwencją dodawania


	unordered_multiset<int> umset;
	umset = { 1,2,5,6,7,7,2,1,1,4,4,1 };  
	printSTL(umset, ",", true); // wszystkie są
	umset.insert({ 1, 2, 3, 100, 1, 100 });
	printSTL(umset, ",", true);
	


	/// unordered_map
	unordered_map<string, int>elf;
	elf = { {"str",10},{"int",14},{"con",12},{"luck",10},{"hp",100},{"hp",200} }; // i tak zostanie pierwsze hp
	elf.insert({ { "str",11 }, {"dex",16} });
	cout << "Elf information:\n";
	for (auto& elem : elf) {
		cout << elem.first << "==" << elem.second << endl;
	}
	cout << "Elf str: " << elf["str"] << endl; // można odwołać się do klucza i używać jakby to była tablica, ale nie z indeksem całkowitym
	// co ciekawe, mogę "w locie" towrzyć nowy klucz !
	elf["quickness"] = 17;
	cout << "Elf quickness: " << elf["quickness"] << "!!!" << endl;
	// elf.at("ten atrybut nie istnieje") = 1; // zgłosi BŁĄD. Metoda at() daje dostęp do wartości poprzez klucz, ale klucz musi istnieć.

	unordered_multimap<string, int>orc;
	orc = { {"str",20},{"int",9},{"con",18},{"luck",10},{"hp",400},{"hp",600} }; // i tak zostanie pierwsze hp
	orc.insert({ { "str",21 }, {"dex",6} });
	cout << "Orc information:\n";
	for (auto& elem : orc) {
		cout << elem.first << "==" << elem.second << endl;
	}
	///////////////// dziwne klucze wymagają obsługi
	unordered_map<myKey, int> umapWithMyKey = {
		{{"ab","bc"},10}, // !
		{{"c","d"},11}, // !
		{{"a","d"},12}, // !
		{{"ab","bc"},13}, // - (dubel klucza, nie przejdzie)
		{{"b","a"},14}, // ! 
		{{"a","a"},15}, // !
		{{"a","b"},16} // ! jak 14, ten sam kubełek
	};
	for (auto [k, v] : umapWithMyKey) {
		cout << k.a << " " << k.b << "=" << v << endl;
	}

	/// a tu coś z kubełkami:
	cout << umapWithMyKey.bucket_size(umapWithMyKey.bucket({"a","b"})) << endl; // ile elementów w kuble?
	cout << umapWithMyKey.bucket_count() << endl; // ile kubełków dla mapy

	/// UWAGA! Jeżeli uporządkowanie elementów w mapie (map) nie jest jakimś priorytetem dla Ciebie, korzystaj raczej z unordered_map. Koszt 
	
}
//////////////////////////////////
/*
Kiedy co stosować?

* Wektor jest często wystarczającym rozwiązaniem. Posiada on najprostszą strukturę wewnętrzna i zapewnia dostęp bezpośredni. Dostęp do danych jest zatem wygodny, elastyczny i szybki. Pamiętać jednak należy, że wektory unieważniają wszystkie swoje iteratory, wskaźniki i referencje
przy każdym przekroczeniu pojemności wektora oraz część iteratorów, wskaźników i referencji przy operacjach wstawiania lub usuwania.

* Kolejka deque (o dwóch końcach) przydaje się, gdy często wykonujesz operacje na końcach zbioru i gdy istotna jest redukcja wykorzystywanej pamięci wewnętrznej przy usuwaniu elementów. Kolejka może teoretycznie pomieścić więcej elementów niż taki wektor. Wektor bowiem to jeden blok w pamięci, a kolejka może mieć ich więcej. 
  Iteratory, wskaźniki i referencje unieważniane są przy zmianie rozmiaru kolejek.

* Gdy wykonujemy dużo przemieszczeń wewnątrz kontenera, oraz dodajemy i usuwamy elementy z wnętrza kontenera, należy rozważyć zastosowanie list. Udostępniają dodatkowo funkcje przenoszące elementy pomiędzy kontenerami. Niestety listy nie oferują dostępu swobodnego — pojawia się więc spadek wydajności przy dostępie do elementów wewnątrz listy, jeśli znajdujemy się na jej początku (musimy przsuwać się po jej elementach). Listy - tak jak wszystkie kontenery oparte na węzłach - nie unieważniają iteratorów odnoszących się do ich elementów, kiedy np. dokonujemy operacji usuwania czy przesuwania. 
	Gdy potrzebny jest kontener sprawdzający czy operacja (np. wstawiania) kończy się powodzeniem lub nie powoduje żadnego skutku, należy użyćwać listy, kontenera asocjacyjnego albo nieuporządkowanego.

* Jeśli wymagane jest częste wyszukiwanie elementów stosuj nieuporządkowany zbiór/wielozbiór mieszający elementy. Kontenery nieuporządkowane powinny być wybierane nad porządkujące, gdy porządek nie jest dla nas istotny.

* Gdy organizujemy dane w modelu klucz-wartość (para) należy użyć nieuporządkowanej mapy/multimapy (a gdy kolejność elementów ma znaczenie, sortującej mapy/multimapy).

* Gdy chcesz skorzystać z mechaniki tablicy asocjacyjnej, bierz się za nieuporządkowaną mapę (a w przypadku oczekiwania na porządek - mapę sortującą)

* Tzw. słowniki uzyskujemy korzystając z nieuporządkowanej multimapy i mapy gdy oczekujemy sortowania.
UWAGA!
Spotkałem się z taką oto opinią wyrażoną w podręczniku do C++11:
"W praktyce trudno jest często przewidzieć, który typ kontenerowy będzie
najlepszy. Wielką zaletą biblioteki STL jest możliwość wypróbowania różnych
wersji bez większego trudu. Główna praca — implementacja różnych struktur
danych i algorytmów — została już wykonana. My musimy jedynie powiązać je
w sposób dla nas najkorzystniejszy".

Przeglądałem różne testy i przykładowo ten sam program w pewnych sytuacjach robiący to samo, ale korzystający z różnych kontenerów, zmieniał znacząco swoją wydajność +-10-40% A przecież to było tylko kilka testów. Pokazuje to jednak, że dobór kontenera MA ZNACZENIE! (szczególnie gdy w kontenerze przechowujemy dużo dużych obiektów)
*/