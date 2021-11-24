/*
LINEAR SEARCH ALGORITHM, IMPLEMENTED IN C++
*/


#include <iostream> //bliblioteka wejscia/wyjscia - wczytywanie danych (std::cin) | wypisywanie danych (std::cout)
using namespace std; //przestrzen nazw std (dzieki temu nie trzeba pisac przedrostka std::)
//bez tego bysmy musieli pisac std::cin, std::cout, std::endl, ale dzieki tej linijce mozemy pisac
//cin, cout, endl, (endl to znak nowej linii)

int linearSearch(int searched_value, int *arr, int array_size); //deklarujemy wlasna funkcje, do poszukiwania liniowego
//argumentami funkcji bedzie wartosc jaka chcemy znalezc, tablica liczb oraz rozmiar naszej tablicy w ktorej chcemy dana wartosc znalezc


//CO TO FUNKCJA
/*
jesli nie wiesz co to funkcje, to mozna je porownac do takich pracownikow w firmie - mamy szefa (czyli funkcje main())
oraz pracownikow (sa to wlasne funkcje, stworzone przez programiste), i to on okresla co dana funkcja ma robic
mozemy, do takiej funkcji przekazywac wartosci, z ktorymi potem cos bedziemy robic tak jak u nas - przekazujemy do funkcji
wartosc ktora chcemy wyszukac, oraz tablice (zbior liczb), w ktorym ta wartosc bedziemy szukac 
*/

//CO TO TABLICA
/*
jesli nie wiesz co to tablica to jest to po prostu taka struktura danych, w ktorej mozemy przechowywac wiele zmiennych naraz,
tj. jakichs wartosci okreslonego typu (int - liczby calkowite (1,2,3,4), float - zmienno przecinkowe (1.23, 234.42, -23.12), 
string - napisy (zapisuje sie je w cudzyslowiu: "Basia", "Ala ma kota"), char - znaki; pojedynczy cudzyslow ('a', 'b', 'c'))
przyklad zastosowania: chcemy przechowywac np imiona dzieci w klasie, to tworzymy sobie taka tablice typu string, bo imiona to napisy
robimy to najpierw przez okreslenie typu, potem nazwa, nawiasy kwadratowe [] i w nawiasach rozmiar tablicy: 
string imiona[5]; 
po kazdej instrukcji srednik, tak po prostu jest - dajemy kompilatorowi znac ze to jest koniec tej jednej instrukcji
a wiec, mamy taka tablice 5 elementowa, czyli mozemy w niej umiescic 5 napisow, w naszym wypadku beda to imiona. Jak to zrobic?
bardzo prosto, tablice tak jak powiedzialem, moga przechowywac wiele zmiennych naraz, a dostac do nich mozemy sie poprzez tzw. indeksy
indeks to po prostu jedna komorka w tablicy - jeden poszczegolny element
np. dajmy sobie t¥ nasza tablice imiona, aby zapisac jakies imie musimy sie odwolac do indeksu na ktorym chcemy te imie zapisac, ale 
musimy miec na uwadze to, ze indeksy numerujemy od 0. co to znaczy? jesli mamy tablice 5 elementow, to:
pierwszy element bedzie miec indeks 0
drugi indeks 1
trzeci indeks 2
czwarty indeks 3
piaty indeks 4

wiec wypelnic nasza tablice imiona wartosciami musimy zrobic tak: nazwa_tablicy[indeks] = wartosc;
czyli w naszym przypadku bedzie to wygladac nastepujaco:
imiona[0] = "Basia";
imiona[1] = "Wiktor";
imiona[2] = "Bartek";
imiona[3] = "Agnieszka";
imiona[4] = "Jakub";

w ten sposob wypelnilismy nasza tablice imionami :))))
*/

int main(){ //funkcja glowna (main) tutaj bedzie wykonywany caly program

    int arr[] = {1, 12, 3, 14, 5, 6, 10}; //tworzymy tablice liczb calkowitych, taki zapis spowoduje ze kompilator sam zliczy ile
    //elementow jest w tablicy
    cout<<"Enter the value you want to search for: "; //wyswietlamy taki komunikat
    int searched_value; //tworzymy zmienna typu calkowitego, ktora bedzie przechowywac wartosc jaka chcemy znalezc
    cin>>searched_value; //wczytujemy od uzytkownika, ta wlasnie wartosc

    int array_size = sizeof(arr) / sizeof(arr[0]);
    //w ten sposob uzyskamy liczbe elementow naszej tablicy - dzielimy liczbe 
    //bajtow jaka zajmuje nasza tablica, przez liczbe bajtow jaka zajmuje wartosc pierwszego elementu tablicy
    //dla liczb calkowitych (int) komputer przeznacza 4 bajty
    //czyli jesli nasza tablica ma np 10 takich liczb, to zajmuje ona 40 bajtow (4 * 10) wiec, jesli przedzielimy 
    //40 / 4 otrzymamy liczbe elementow, dla tego przykladu bedzie to 10 :)

    int index = linearSearch(searched_value, arr, array_size); //wywolanie funkcji, tj. uzycie jej. jak widzisz przekazalismy najpierw
    //zmienna searched_value, a pozniej arr - czyli nasza tablice. Zmienne do funkcji przekazujemy zgodnie z kolejnoscia w jakiej
    //okreslilismy to przy jej deklaracji (jej stworzeniu, u nas jest to linijka numer 11)

    if(index == -1){
        cout<<"Not found";
    }else{
        cout<<"Found at index: "<<index;
    }


    return 0; //nie trzeba, automatycznie to zwraca 0
}

int linearSearch(int searched_value, int *arr, int array_size){//zaczynamy implementacje funkcji, czyli de facto tutaj dopiero okreslamy co ta funkcja
//ma robic, jak widzisz sa tutaj klamerki, ktore okreslaja poczatek i koniec ciala funkcji

    //CO TO JEST PETLA
    /*
    jak sama nazwa wskazuje, petla to cos co powoduje powtorzenie jakiejs operacji iles razy
    w c++ jest wiele takich petli, najbardziej podstawowe to: for oraz while
    w jaki sposob dziala taka petla?
    for(int i = 0; i < 10; i++){

    }
    tlumaczac powyzszy kod na normalny jezyk otrzymalibysmy cos takiego:
    dla i zaczynajacego sie od 0, wykonuj to co jest miedzy klamerkami poki i jest mniejsze od 10 oraz z kazdym powtorzeniem petli
    zwieksz i o 1
    czyli w tym wypadku nasza petla wykona 10 powtorzen:
    najpierw i = 0 potem i = 1, i = 2, i = 3, itd az do 9, poniewaz kiedy i osiagnie wartosc 10, petla sie nie wykona, tylko zakonczy
    dzialanie - tak jak okreslilismy (wykonuj to co jest miedzy klamerkami poki i jest mniejsze od 10)
    */

   //JAK DZIALA WYRAZENIE LOGICZNE IF?
   /*
    znowu - tak jak sama nazwa mowi - if to po prostu warunek (co ma sie stac jesli dane wyrazenie sie spelni)
    jak zapisac takiego if'a?
    if(nasz_warunek){
        co ma sie stac jesli warunek sie spelni
    }
    prawdziwy kod:
    int x = 10;
    if(x == 10){
        cout<<"wartosc zmiennej x to "<<x<<endl;
    }
    czyli utworzylismy sobie zmienna o nazwie x i nadalismy jej wartosc 10
    nastepnie porownujemy czy przypadkiem wartosc zmiennej x to 10, jesli tak to wyswietlamy komunikat "wartosc zmiennej x to 10" i
    przechodzimy do nowej linii. miej na uwadze to ze jesli chcemy przypisac jakas wartosc do zmiennej to uzywamy pojedynczego znaku =
    a kiedy chcemy porownac, uzywamy podwojnego czyli ==
   */

    //a wiec tutaj jest praktycznie nasz caly algorytm przeszukiwania liniowego
    //dziala on w ten sposob ze zaczynajac od skrajnie lewego elementu naszej tablicy, przechodzimy w prawo po kazdym nastepnym elemencie
    //i z kazdym takim przejsciem sprawdzamy czy wartosc tego elementu jest rowna wartosci jaka szukamy, jesli tak to zwracamy indeks
    //czyli miejsce w ktorym nasza liczba wystepuje
    //jesli takiej liczby nie znalezlismy to zwracamy -1
    for(int i = 0; i < array_size; i++){
        if(arr[i] == searched_value){
            return i;
        }
    }
    return -1;
}

//zlozonosc naszego algorytmu jest liniowa czyli O(n), tak jak sama nazwa wskazuje - przeszukiwanie liniowe
//co to znaczy? to znaczy tyle ze w pesymistycznym przypadku algorytm wykona n operacji, gdzie n to ilosc danych/rozmiar tablicy


//SPECYFIKACJA PROBLEMU
/*
    Wyszukiwanie liniowe (ang. linear search), polega na przegl¥daniu 
    kolejnych element¢w zbioru Z. Je˜li przegl¥dany element posiada odpowiednie wˆasno˜ci (np. jest liczb¥ o poszukiwanej warto˜ci), 
    to zwracamy jego pozycj© w zbiorze i koäczymy. 
    W przeciwnym razie kontynuujemy poszukiwania a¾ do przejrzenia wszystkich pozostaˆych element¢w zbioru Z.
    Jesli nie znajdziemy danej wartosci to zwracamy wczesniej ustalona wartosc, np. -1
*/