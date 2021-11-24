#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <typeinfo>
#include <string>
#include <ctime>
#include <iterator>
#include <algorithm>
#include "printSTL.h"

// C++17

using namespace std;
// więcej o iteratorach:
/*
	Przeglądając różne strony, podręczniki nigdzie nie spotkałem ultra-precyzyjnego wyjaśnienia tego, co za chwilę spróbuję nieudolnie pokazać. Wszędzie są jakieś niedopowiedzenia, jakieś nieścisłości definicyjne. Wszędzie aż prosi się o zestaw pytań. Jestem pewny, że twórcy tych wyjaśnień nie odpowiedzą jasno na pytanie: "czy osoba, która się uczy i nie spotkała się nigdy z tym zagadnieniem w ogóle zrozumie, co do niej mówimy?" 	
	C++ niekiedy jest w mojej ocenie tak abstrakcyjny, że - po prostu - sprawia dużą trudność poznawczą. Praktyka pokazuje, że pewne rzeczy trudniej opisać, a łatwiej zrozumieć czym są poprzez prezentację tego, co robią. W procesie edukacji nie raz zdarzało mi się - nie wstydzę się tego powiedzieć - najpierw zobaczyć jak coś działa, nie do końca to rozumiejąc a nawet nie potrafiąc tego wyraźnie od samego środka opisać. Zastanawiam się nawet, czy jest to zawsze konieczne? A potem powoli i po pewnym czasie pojawiło się takie "aaaa, dobra, wiem!" Zgłębiłem sens, działanie i istotę tego, co tu się wyprawia później. Wielu uczniów korzysta np. ze wskaźników ale do końca nie umie o tym opowiedzieć, co właściwie się dzieje. Ale z czasem naturalnie staje się to zrozumiałe. Ucząc sam muszę w pełni zrozumieć i nie zawsze jest to możliwe "od ręki".
	Podobny problem i podobny mechanizm napotkałem ucząc się o adaptatorach iteratorów. Nawet samo pojęcie trudno wyjaśnić, ponieważ nigdzie nie znalazłem jego bezpośredniej jasnej definicji. Jest to raczej definicja poprzez opis działania. To trochę tak, jakby bardzo doświadczeni programiści tworzący język zrealizowali zrozumiałą tylko sobie głęboką abstrakcję, wpier napisaną i działającą a dopiero potem opisali teoretycznie to co wymyślili. Ten nowe rzeczy trudno jest nauczyć się kolejnym osobom, szczególnie nie posiadających takiego doświadczenia, które sprawia, że język nie tyle się "zna" co dogłębnie rozumie, nim się wręcz myśli. Tak. Język jest czymś tak żywym, że wymaga sam w sobie pewnej dojrzałości i rozumienia. Dlatego bogactwo języka faktycznie zmienia myślenie a tym samym osoba rozumiejąca język głębiej się nim wyraża, pełniej opisuje to, co myśli. Jestem pewny, że moje wyobrażenie tego, co mogę "napisać w tym języku" jest płytkie w porównaniu do wyobrażenia tych, co język tworzyli i posługują się nim z rozmachem i obficie. Taka wyobraźnia, jakie bogactwo języka! Obrazy bowiem poruszą tylko zmysł wzroku, a język istotę rzeczy! Również język C++.
*/

void _029() {

	// <iterator>
	// Iteratory wstawiające ! Bardzo ciekawa mechanika sprzężona z pewnymi funkcjami kontenerów	
	// Iterator, który wstawia na końcu konetenera w momencie przypisania doń wartości:
	// na końcu (wstawiacz końcowy) Uwaga! kontener musi mieć jakąś metodę wstawiającą na koniec
	vector<int> x; // vector ma metody wstawiania na koniec (push_back)
	auto it = back_inserter(x);
	cout << typeid(it).name() << endl; // back_insert_iterator<vector<int>> - specjalny iterator wstawiania na koniec
	back_inserter(x) = 100; // to jakbym miał *iterator = 100; iterator++; back_inserter to taka funkcja - tzw. adaptator iteratorów: back_inserter wstawia coś do kontenera zawsze na końcu. Adaptator to taka funkcja, która przystosowuje iteratory do użytku trochę innego niż było przeznaczone. 
	
	back_inserter(x) = 200;
	printSTL(x, ",", false);
	// albo
	x.reserve(x.size() * 2); // rezerwuję sobie odpowiednio miejsca by unikać realokacji i w efekcie podczas operacji kopiowania nie zgubić wartości iteratorów 
	copy(x.begin(), x.end(), back_inserter(x)); // kopiuje ze źrodła określonego zasięgiem do miejsca przeznaczenia, którym jest ten sam kontener <algorithm>, do algorytmów jeszcze wrócimy.
	printSTL(x, ",", false); // 100,200,100,200

	cout << endl;
	deque<int> set1 = { 1,2,3,4,5,6,5,4,3 };
	vector<int> set2;
	transform(set1.cbegin(), set1.cend(), // źrodło
		back_inserter(set2), 
		[](const auto& p) { return p + p;  }); // tu obliczam element z set1 zanim wstawię do set2
	printSTL(set2, " ", false);

	// wstawiacz początkowy (iterator wstawiający na początku), a więc np. do listy, czy kolejki o dwóch końcach (praktycznie push_front())
	deque<int> y;
	front_inserter(y) = 300;
	front_inserter(y) = 400;
	printSTL(y, ",", false); // 400,300
	copy(y.begin(), y.end(), front_inserter(y)); // nie muszę przydzielać pamięci
	printSTL(y, ",", false);//300,400,400,300 :)

	// wstawiacz ogólny praktycznie dla każdego kontenera z wyjątkiem array i forward_list
	list<int> L1;
	list<int> L2;
	inserter(L1, L1.end()) = 500;
	inserter(L1, --L1.end()) = 600; // przed 500
	inserter(L1, L1.end()) = 700; // na koniec	
	printSTL(L1, ",", false);//600,500,700
	copy(L1.begin(), L1.end(), // źródło
		inserter(L2, L2.begin())); // miejsce docelowe
	printSTL(L2, "->", false);
	
	/// iteratory strumienia

	// Iteratory strumieni wyjściowych zapisują przypisywane wartości do strumienia 	wyjściowego.Wykorzystując iteratory strumieni wyjściowych, algorytmy mogą zapisywać dane bezpośrednio do strumieni.
	ostream_iterator<int> out(cout, ":"); // argumentem jest strumień, a potem ogranicznik
	for (auto i : { 1,2,3,4,5 }) { // wyślę w praktyce elementy typi int do cout
		*out = i;		
		out++;
	}
	cout << endl;
	vector<int> data{ 1,2,3,4,5,6,7,8,9,10 };
	copy(data.begin(), data.end(), out); // "kopiuję" z wektora do strumienia wyjścia
	cout << endl;
	// można też nie definiować out
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "<-"));
	cout << endl;

	
	// Iterator strumienia wejściowego odczytuje elementy ze strumienia wejściowego. 
	vector<int> fromUser; // wkrótce zapełni się danymi :)
	copy(istream_iterator<int>(cin), // początek, iterator początkowy strumienia cin gotowy do pobierania int'ów 
		istream_iterator<int>(), // domyślny konstruktor iteratora strumienia, dzięki któremu mamy określony iterator końca strumienia, bo tego oczekuje algorytm copy() 
		back_inserter(fromUser)); /// kopiuje ze strumienia wejścia aż do EOF lub błędu (np. nie int) [EOF to Ctrl+Z]	
	printSTL(fromUser,",",true); /// wszystkie wprowadzone liczby :)
	unique_copy(fromUser.begin(), fromUser.end(),
		ostream_iterator<int>(cout, ",")); // kopiuje z kolekcji na strumień wyjścia (ale pomija już wyświetlone)
	cin.clear();
	
	vector<string> strings;
	istream_iterator<string> endOfStream; // iterator końca strumienia
	copy(istream_iterator<string>(cin), // kopiuj z cin 
		endOfStream, // dopóki nie osiągnie końca 
		back_inserter(strings)); /// dodawaj na koniec strings
	printSTL(strings," ",false); /// wszystkie wprowadzone napisy :)
	cin.clear();
	
	strings.clear();
	istream_iterator<string> getString(cin); // wprowadź np. a b c d e
	while (getString != endOfStream) {
		cout << *getString << " " << *getString << endl; // dwa razy iterator tego samego elementu
		++getString; // przechodzi na następny
		//advance(getString, 2); // przechodzi co drugi, ale pilnuj, by nie wyjść poza endOfStream!
	}

	cin.clear();
	
}
/*
		Iteratory i ich rodzaj - podsumowanie
	array,vector,deque,string: swobodne iteratory
	list: -- ++
	forward_list: jednokierunkowa: ++
	set, multiset: ++ -- (elementy są stałe)
	map, multimap: ++ -- (klucz jest stały)
	unordered_map, unordered_multimap, unordered_set, unordered_multiset: ++
	*/