#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <typeinfo>
#include <string>
#include <ctime>
#include <set>
#include <algorithm>
#include <iterator>
#include <utility>
#include "printSTL.h"


// C++17
using namespace std;

int main() {
	/*
	mapa, multimapa (kontener asocjacyjny/sortowany) (set, multiset, map, multimap)
	KONTENERY ASOCJACYJNE / KOLEKCJE SORTOWANE : Pozycja elementu zależy od jego wartości, lub klucza gdy mamy doczynienia z parą klucz-wartość. Elementy tego kontenera są sortowane domyślnie według pewnego kryterium. Kolejność czy moment wstawiania elementu nie ma więc znaczenia.Domyślnie sortowanie jest wg algorytmu "od mniejszego do większego" ( operator < ). Można to zmienić.

	map przechowuje pary klucz-wartość, gdzie klucz nie może się powtarzać, a w multimap - może  w obu przypadkach wartości klucza nie można zmieniać, a ta para to w rzeczywistości typ pair<const klucz,wartość>; Mapa jest najczęściej implementowana z pomocą drzewa binarnego (chodzi o wyszukiwanie klucza i wstawianie klucza o złożoności log(n), obie operacje tyle samo kosztują, bo wyszukanie i wstawianie szuka miejsca w drzewie. Mapa ma swoje algorytmy równoważenia drzewa, niemniej odsyłam do poznania drzewa i związanych z nim mechanik. Tutaj nie skupiam się na tych bebechach mapy, co raczej na tym, jak z niej korzystać).
	*/

	map<int, string> ids;
	ids = {
		{21,"gorąca woda"},
		{8,"filiżanka"},
		{11,"cukier"},
		{3,"łyżka"},
		{19,"herbatka"}
	};
	ids.insert({ {11,"cytrynka"},{12,"imbir"} }); // cytrynka się nie doda :( 11 już jest !
	ids[1000] = "kropla miłości"; // HA ! działa bez insert ;) Doda się nowy element. Ale uwaga! To nie jest indeks jak w tablicach, jest to tzw. tablica asocjacyjna a 1000 to klucz. Równie dobrze kluczem tu może być napis itp.
	for (auto& elem : ids) {
		cout << elem.first << "==" << elem.second << endl;
	}

	// obiekty funkcyjne do sortowania podobnie jak w zbiorze
	map<float, float, greater<float>> malej{ {1,2},{2.4,2.1},{0,10} };	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;

	for_each(
		malej.begin(), malej.end(),
		[](pair<const float,float>& element) { // można też decltype(malej)::value_type
			element.second += 1;
		}
	);
	for (auto [k, v] : malej) cout << k << "=" << v << " ";
	cout << "[" << malej.size() << "]" << endl;

	// funkcje takie jak w zbiorze: count(klucz), find(klucz),
	// lower_bound, upper_bound, equal_range


	// c++17
	map<unsigned int, pair<const string, string>> m1{ {1,{"kod","123"}}, {2,{"kod","234"}} };
	// try_emplace - warunkowe tworzenie elementu (jeżeli klucz istnieje, nie utworzy pary)
	// jak nie istnieje ,dopiero zrobi parę z dwóch pozostałych elementów. Wcześniej korzystaliśmy z wciąż sensownych metod insert i emplace
	auto [it, ok] = m1.try_emplace(1, "kod","456");
	cout << it->first << " " << it->second.second << " " << ok << endl; // iterator do elementu kolidującego z potencjalnie wstawianyn, oraz wartość false (po nie udało się wstawić)
	auto [it2, ok2] = m1.try_emplace(3, "kod", "456");
	cout << it2->first << " " << it2->second.second << " " << ok2 << endl;  // iterator do nowo wstawionego elementu i true (bo udało się wstawić)

	// rozpakowanie
	for(auto & e : m1) {
		auto& [key, value] = e;
			cout << key << "=>" << value.first << ", " << value.second << endl;
	}
	// rozpakowanie bez pośrednika jak wyżej, od razu siorbię klucz i vartość
	for (auto& [k, v] : m1) {
		cout << k << "=>" << v.first << v.second << " ";
	}
	cout << endl;

	// Wstawianie może być poprzedzone tzw. PODPOWIEDZIĄ. Jest to podanie pewnego elementu
	// w drzewie, który może być prawidłową podpowiedzią (lub nie).
	// Gdy podpowiedź jest prawidłowa czas takiego włożenia jest O(1). Gdyby podpowiedź okazała się błędna, to element zostanie włożony normalną drogą (poprzedzone wyszukiwaniem o złożności O(log(n)).
	/*
	Podpowiedź poprawna jest iteratorem istniejącego elementu, który jest większy (chodzi o klucz) niż element przeznaczony do wstawienia. Dlatego nowy klucz zostanie umieszczony w miejscu znajdującym się tuż przed elementem wskazanym przez podpowiedź.
	*/
	auto podpow = m1.end(); // na początku nie mam lepszej podpowiedzi, biorę coś...
	podpow = m1.insert(podpow, { 10, {"kod","500"} } );
	podpow = m1.insert(podpow, { 4, {"kod","750"} } );
	podpow = m1.insert(podpow, { 0, {"kod","900"} } );
	for (auto& [k, v] : m1) {
		cout << k << "=>" << v.first << v.second << " ";
	}
	cout << endl;

	// Normalnie klucza nie wolno modyfikować, dlatego elementy się usuwało i potem ponownie dodawało zgodnie z logiką wewnętrznego drzewa. ALE od C++17 jest możliwa pewna operacja...
	map<int, string> m2{ {1,"Mleko"},{2,"Woda"},{3,"Herbata"},{4,"Kawa"},{5,"Maślanka"},{6,"Podpiwek"},{7,"Serwatka"} }; // hierarchia ulubionych napojów
	for (auto& [k, v] : m2) {
		cout << k << "=>" << v << " ";
	}
	cout << endl;
	/// ... mianowicie jest nowa funkcja, extract(klucz) - która usuwa element z mapy ale nie ma skutków ubocznych związanych z alokowaną pamięcią (elementy, ich struktura w pamięci nie zaburza się).
	/// Powiedzmy, że nagle polubiłem Serwatkę a Mleko spadło na koniec napojów ulubionych.
	{
		auto temp1 = m2.extract(1); // podeję klucz, można też podać iterator, będzie szybciej
		auto temp2 = m2.extract(7);
				// cout << typeid(temp1).name() << endl; // spradźcie jaki to typ :-D
		swap(temp1.key(), temp2.key()); // klucze są niemodyfikowalne w mapie, ale te pobrane przez extract już są
		m2.insert(move(temp1));
		m2.insert(move(temp2)); // insert od c++17 ma możliwość przesunięcia wyodrębnionego węzła.
	}
	for (auto& [k, v] : m2) {
		cout << k << "=>" << v << " ";
	}
	// powyższy mechanizm niejako podmienia miejscami całe pary w mapie. Można je tak podmieniać również pomiędzy różnymi mapami, ale muszą być zachowane typy
	cout << string(3, '\n');

	// multimapa
	multimap<int, string> ids2; // po prostu wiele kluczy
	ids2 = {
		{21,"gorąca woda"},
		{8,"filiżanka"},
		{11,"cukier"},
		{3,"łyżka"},
		{19,"herbatka"}
	};
	ids2.insert({ {11,"cytrynka"},{12,"imbir"} }); // cytrynka się doda pod tym samym kluczem
	for (auto& elem : ids2) {
		cout << elem.first << "==" << elem.second << endl;
	}

}
