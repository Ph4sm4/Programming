#include <iostream>
#include <future> // to interfejs wysokiego poziomu 
#include <thread> // tu mam w¥tki niskiego poziomu
#include <chrono>
#include <iterator>
#include <sstream> // stringstream
using namespace std;

auto start = chrono::system_clock::now();
int ZMIENNA = 100;

/*
	W¤TKI.
	Interfejs wysokiego poziomu czyli <future> i metoda async.
	Interfejs niskiego poziomu czyli thread.
	---------------------------------------------------------------------------------------------
	std::thread to klasa reprezentuj¥ca poszczeg¢lne w¥tki wykonania.
	W¥tek jest sekwencj¥ instrukcji, kt¢re mog¥ by† wykonywane r¢wnolegle z innymi takimi w¥tkami. W¥tki dziel¥ t© sam¥ przestrzeä adresow¥. Ka¾dy w¥tek ma unikalny identyfikator.
*/
// wy˜wietla literki alfabetu od a=97 lub A=65
int letters(int a=65) {
	cout << "\nSTART letters: thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	int step = 0, i;
	ostream_iterator<char> out(std::cout,"");
	do {
		step++;
		*out++ = i = rand() % 26 + a; // nasze interatory wstawiaj¥ce do strumienia		
		this_thread::sleep_for(chrono::milliseconds(150)); // troszk© poczekaj
	} while (i != a + 25 || step < 15); // nie koäcz za szybko!
	cout << "\nEND letters: thread id=>" << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	return step;
}
// funkcji wy˜wietla n znak¢w char z, i przedstawia id w¥tku
void line(char z, unsigned n) {
	cout << "\nSTART line thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;	
	while (n--) {
		cout << z;
		this_thread::sleep_for(chrono::milliseconds(125));
	}
	cout << "\nEND line thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
}
// funkcji wy˜wietla n znak¢w char z, i przedstawia id w¥tku
void f(unsigned int mili) {
	this_thread::sleep_for(chrono::milliseconds(mili));	
	cout << "\nEND f thread id=> " << this_thread::get_id() << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
}
void setValue(int* a) { *a = 100; ZMIENNA = 200; }

int main() {
	srand(time(0));
	
	cout << "Start programu: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now()-start).count() << endl;
	cout << "W¥tek gˆ¢wny=" << this_thread::get_id() << endl;
	
		// 1) Funkcja letters ruszy jako oddzielny w¥tek, jednak decyzj© o starcie pozostawiam maszynie a zatem w¥tek mo¾e w og¢le nie ruszy† (a¾ do wywoˆania jawnie metody .get()).	
		std::future<int> result1(std::async(launch::async,letters, 65));
		/// uruchamia ale program idzie dalej (nie stoi w tym miejscu)
		/* Uwaga! Je˜li wywoˆanie asynchroniczne nie jest mo¾liwe w tym miejscu, program zgˆosi wyj¥tek std::system_error. Je¾eli udaˆo si© uruchomi†, wynik dziaˆania w¥tku zostanie przypisany specjalnemu obietowi result_1 klasy future<int>
		*/
		/*
			.get() wywoˆane na obiekcie result1 klasy future "domaga" si© zwr¢cenia wyniku, wi©c je¾eli w¥tek do tej pory jeszcze nie ruszyˆ - rusza
			i program ju¾ teraz czeka a¾ zwr¢ci wynik i si© zakoäczy.
		*/
		int s2 = letters(97); // tu wywoˆanie w gˆ. w¥tku, normalnie - maˆe literki. 		
		cout << result1.get() << endl; // zwraca wynik dziaˆania letters, je¾eli jeszcze nie odpaliˆ si© - to si© odpali.
		cout << s2 << endl;

		// Wywoˆanie .get() na obiekcie future praktycznie niszczy ten obiekt, 
		// wi©c ponowne wywoˆanie .get() nie b©dzie mo¾liwe
		// .valid() sprawdza czy obiekt result1 jeszcze jest wa¾ny
		if (result1.valid()) cout << "result1 jest `valid`, mo¾na go .get()\n";
		else cout << "result1 nie jest `valid`, nie da si© go .get()\n";
		cout << endl;

		std::future<int> result2(std::async(letters, 65)); // du¾e lierki
		result2.wait(); // metoda .wait() wywoˆana na obiekcie future wymusza start i czeka na skoäczenie (idea w¥tku troch© pada)
		cout << "\n\nPO WAIT() " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;

	/// UWAGA! w ostateczno˜ci to, czy co˜ "zyskamy" na wielow¥tkowo˜ci zale¾y od wielu czynnik¢w, cho†by od zu¾ycia zasob¢w, obci¥¾eniu systemu, jako˜ci tego, co˜my spˆodzili itp. itd.
	/// R¢¾ne w¥tki mog¥ mie† dost©p do tych samych danych w pami©ci, co mo¾e prowadzi† do nieprzewidzianych skutk¢w. Programowanie wielow¥tkowe jest pozornie proste, w praktyce musi by† bardzo dobrze zaprojektowane, aby w¥tki faktycznie wykorzystywaˆy moce procesor¢w i aby nie kolidowaˆy, tworz¥c kompletnie nieprzewidywalne zachowania programu.	
	
	std::thread thread1(line, '!', 50); // start funkcji w tle
	cout << thread1.get_id() << endl; // thread1 - pobieranie jego id w w¥tku gˆ¢wnym
	this_thread::sleep_for(chrono::milliseconds(1000)); // poczekaj 1s
	line('*', 10);

	thread1.join(); // .join() ka¾e czeka† procesowi gˆ¢wnemu na skoäczenie w¥tku thread1
	/*
		Je¾eli .join() zabraknie, to w¥tek gˆ¢wny skoäczy si© PRZED zakoäczeniem w¥tku thread1 !! Tymczasem proces-w¥tek potomny nie skoäczyˆ dziaˆania,	dlatego zobaczymy bˆ¥d, a w¥tek thread1 zostanie zdmuchni©ty. ( std::terminate() )
	*/

	/// Odˆ¥czam w¥tek od obiektu, 
	/// Nawet, gdy w¥tek gˆ¢wny si© skoäczy, w¥tek thread2 zostanie "odˆ¥czony" od gˆ¢wnego i b©dzie samodzielnie dziaˆa†.
	std::thread thread2(f, 500); // start funkcji w tle
	cout << thread2.get_id() << endl; // thread2 - pobieranie jego id w w¥tku gˆ¢wnym	
	thread2.detach();
	f(2500); // czeka i tworzy plik ze znacznikiem czasu

	cout << "\n\nEND " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << "\n\n";
		
	/*
		W¥tki niskiego poziomu uruchamiamy tworz¥c obiekt klasy std::thread (biblioteka <thread>)
		DLACZEGO uruchomienie w¥tku jako w¥tku (klasa std::thread) jest NISKOPOZIOMOWE w stosunku do async() ? Mi©dzy innymi dlatego, ¾e:
		*Uruchomienie takie jak <std::thread thread1 (line,'!',40);> nie gwarantuje strategii startu w¥tku.	[Strategia startu/uruchomienia w¥tku to np. fakt, ¾e w¥tek mo¾e nie wystartowa† od razu, ale z op¢«nieniem. Mo¾na go wymusi†, lub po utworzeniu uruchomi† w innym momencie itp. itd.]
		*Nie ma ¾adnego interfejsu przechwytuj¥cego wynik dziaˆania w¥tku. Mo¾na co najwy¾ej sprawdzi† identyfikator w¥tku.
			[Mo¾na jednak przekaza† wynik dziaˆaj¥cego w¥tku wykorzystuj¥c referencj©/wska«nik]
			[Mo¾na te¾ skorzysta† z promes, ale to ju¾ w innym kursie ... ;) ]
	*/

	/// UWAGA! Odˆ¥czone w¥tki (.detach()) mog¥ stanowi† PROBLEM, je¾eli nie zostan¥ zabite :)
	
	int x;
	thread thread3(setValue, &x);
	thread3.detach();
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << endl << x << "," << ZMIENNA << " " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
	
}
/**
	ZOTA ZASADA!
		Jedyna bezpieczna sytuacja, kiedy r¢¾ne w¥tki maj¥ dost©pdo tych samych danych (r¢wnolegle) jest wtedy,
		gdy WSZYSTKIE mog¥ dane tylko czyta†.
		Mniej bezpieczna, ale jeszcze ˆatwa do przewidzenia jest sytuacja, gdy TYLKO jeden konkretny w¥tek mo¾e dane zmienia†.
		Wszystkie inne sytuacje s¥ ju¾ kˆopotliwe i zawsze generuj¥ ryzyko chaosu. le zaprojektowane w¥tki mog¥ tak zadziaˆa†, zrobi†
		takie combo, ¾e nikt nie przewidzi co si© stanie ze wsp¢lnymi danymi ... :-D
		Jak sobie radzi† z problemami wsp¢ˆbie¾no˜ci? O tym w innym kursie !
*/