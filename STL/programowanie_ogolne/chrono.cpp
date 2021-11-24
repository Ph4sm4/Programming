#include <iostream>
#include <array> // tablica
#include <vector> // wektor
#include <deque> // kolejka z dwoma koäcami
#include <list> // lista
#include <forward_list> // lista jednokierunkowa
#include <set> // zbi¢r
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
#include <memory> // inteligentne wska«niki
#include <functional> // reference_wrapper<>
#include <chrono> // czas
#include <iomanip> // manipulatory io
#include <string> // wiadomo
#include <thread> // w¥tki
#include <ctime>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <cstdlib>

// C++17
using namespace std;
/*
	Najwy¾szy czas na czas.
*/

int main() {	
	/*
	termin: epoka - pocz¥tek pomiaru upˆywu czasu
	termin: takt - np. 1 sekunda (co˜ jak jednostka do definiowania okresu ilo˜ci¥ takt¢w). Takt podstawowy to waˆa˜nie jedna sekunda, ale mog¥ by† inne warto˜ci takt¢w. Takt okre˜la si© poprzez ratio<1,1> (jedna sekunda), albo np. ratio<60,1> - 60 sekund/1 minuta. ratio om¢wione jest we wcze˜niejszym kursie.
	termin: okres - definiowany przez n razy jaki˜ takt czasu np. 2 minuty to 2 razy takt minutowy
	
	termin: punkt w czasie to wyliczenie - okresu od epoki (np. je¾eli epok¥ jest 5 listopada 2019 godzina 15:00:00 to dla okresu 4 minut punktem w czasie
	b©dzie 5 listpada 2019 godzina 15:04:00 */

	// okres
	chrono::duration<int> sek20(20); // 20 sekund, bo okres (duration) domy˜lnie taktuje sekundami
	chrono::duration<int, ratio<60>> min3(3); // 3 minuty, bo int to 3, a ratio to stosunek do sekundy (tu, 60 sekund, czyli MINUTA), zatem 3 minuty !
	chrono::duration<double, ratio<10>> x(0.5); // 5 sekund :) bo jest to poˆowa 10-sekundowego taktu
	chrono::duration<long, ratio<1, 1000>> ms(5); // 5 milisekund (1/1000 sekundy)
	// mamy te¾ wbudowane:
	chrono::seconds sek(15); // 15 sekund
	

	chrono::hours day(24); // 24 godziny
	using namespace chrono;
	auto okres = minutes(2);
	cout << typeid(okres).name() << endl;
	//chrono::miliseconds(10);
	//chrono::microseconds(1);
	//chrono::nanoseconds(4);

	cout << sek.count() << endl; // ile sekund ? (count zwraca ilo˜† takt¢w)
	sek++; // 15 sekund + 1
	cout << sek.count() << endl;

	chrono::seconds r = sek20 - sek; // 20 - 16 sekund
	cout << r.count() << endl;
	// aby zobaczy† ratio<num,den> czyli parametry taktu (tutaj ratio dla predefiniowanego duration - minutes
	cout << chrono::minutes::period::num << " " << chrono::minutes::period::den << endl; // 60,
	// tutaj takt dla wˆasnego duration
	cout << chrono::duration<long, ratio<10>>::period::num << " " << chrono::duration<long, ratio<10>>::period::den << endl; //  10, 1 bo ratio<10> to domy˜lnie ratio<10,1>

	chrono::milliseconds ms2(r); // 4000 ms ! KONWERSJA z 4 sekund (tyle wynosiˆo r) na milisekundy
	cout << ms2.count() << endl;

	/// mo¾na przekonwertowa† :)	
	milliseconds ms3(12344321); // chrono:: ju¾ jest, bo using namespace chrono; poszˆo wy¾ej
	// podziel na godziny, minuty, sekundy i milisekundy
	hours hh = duration_cast<hours>(ms3); // obcinam nie-godziny
	minutes mm = duration_cast<minutes>(ms3 % chrono::hours(1)); // cz©˜† mniejsza od godziny (reszta z dzielenia) zamieniam na minuty reszt© z dzielenia ms3 przez godziny (zostaj¥ tylko minuty, wi©c ma to sens ;)
	seconds ss = duration_cast<seconds>(ms3 % chrono::minutes(1)); // cz©˜† reszta z minuty (sekundy)
	cout << ms3.count() << "ms to " << setw(2) << hh.count() << "g, " << setw(2) << mm.count() << "m, " << setw(2) << ss.count() << "s" << endl;
	// zauwa¾, ¾e obci¥ˆem troch© milisekund przy konwersji ... trudno :)

	// zagar :)
	/*
	s¥ dost¥pne 3 zegary w systemie
	std::chrono::system_clock // systemowy, o taki podstawowy
	std::chrono::high_resolution_clock	 // dokˆadniejszy (ale mo¾e by† zgodny z systemowym)
	std::chrono::steady_clock // miarowy, niemalej¥cy, nie da si© go cofa†
	*/
	auto start = system_clock::now(); // uwaga! system_clock mo¾e ulega† korektom, wi©c da si© oszuka† miar© czasu :)
	while (system_clock::now() < start + milliseconds(25)) {
		cout << setw(4) << '.';
	} // przez 25 milisekund b©d© sobie wy˜wietlaˆ kropki ...
	cout << endl;

	auto start2 = high_resolution_clock::now(); // 
	while (high_resolution_clock::now() < start2 + milliseconds(25)) {
		cout << setw(4) << '-';
	} // przez 25 milisekund b©d© sobie wy˜wietlaˆ -
	cout << endl;

	this_thread::sleep_for(seconds(2)); // ciekawe prawda? to z programowania wsp¢ˆbie¾nego
	cout << "Troch© pospaˆem...\n";

	this_thread::sleep_until(chrono::high_resolution_clock::now() + seconds(5)); 
	cout << "Te¾ kimn¥ˆem ciutk© zn¢w...\n";

	// czas lokalny do postaci tekstowej
	char str[100];
	auto t = system_clock::to_time_t(start); // konwersja na czas systemowy wyra¾ony liczbowo	
	ctime_s(str, sizeof(str), &t); // a tu str b©dzie napisem z dat¥ systemow¥ - konwersja napisowa najprostsza posta†
	cout << str << endl;	
}