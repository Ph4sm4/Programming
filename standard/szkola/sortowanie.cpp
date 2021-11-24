#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace chrono;

const int n = 50000;
//-------------------------------------------------------------------------------------------
void bubbleSort(int *tab){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(tab[j] > tab[j + 1]){
                swap(tab[j], tab[j + 1]);
                /* mamy 2 zmienne a = 2 i b = 3
                a = a - b; a = 2 - 3 = -1
                b = b + a; b = 3 - 1 = 2
                a = b - a; a = 2 - (-1) = 2 + 1 = 3
                */
            }
        }
    }
}
//-------------------------------------------------------------------------------------------
void quickSort(int *tab, int lewy, int prawy){
    if(prawy <= lewy) return;
    int pivot = tab[(lewy+prawy)/2]; //nasza o˜
    int i = lewy - 1, j = prawy + 1;
    while(true){
        while(pivot > tab[++i]); //tutaj szukamy idac od lewej strony liczby wiekszej od osi
        while(pivot < tab[--j]); //tutaj szukamy idac od prawej strony tablicy liczby mniejszej od osi
        if(i <= j) swap(tab[i], tab[j]); //jesli nasze zmienne (jedna idzie od lewej druga od prawej) sie przetna tzn ze udalo nam
        //sie stworzyc 2 mniejsze tablice, w ktorych jedna ma liczby tylko mniejsze od osi, a druga tylko wieksze, dlatego poki
        //zmienne sie nie spotkaja zamieniamy je miejscami ze soba (algorytm partycjonowania)
        else break;
    }
    if(i > lewy) quickSort(tab, lewy, j); //wywolujemy funckje quicksort aby posortowac nowo stworzona tablice z liczbami mniejszymi od osi
    if(j < prawy) quickSort(tab, i, prawy); //a tutaj bedziemy sortowac nowo powstala tablice z liczbami wiekszymi od osi
}
//-------------------------------------------------------------------------------------------
void selectSort(int *tab){
    for(int i = 0; i < n - 1; i++){
        int index = i;
        for(int j = i + 1; j < n; j++){
            if(tab[index] > tab[j]) index = j;
        }
        swap(tab[i], tab[index]);
    }
}//tutaj z kazda iteracja zmieniajszamy obszar szukania liczb poprzez znajdywanie minimalnej i wstawianie na poczatek aktualnej tablicy
//-------------------------------------------------------------------------------------------
void insertSort(int *tab){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && tab[j-1] > tab[j]){
            swap(tab[j], tab[j-1]);
            j--;
        }
    }
}//tutaj dla kazdej liczby w tabeli porownujemy czy liczba ta jest mniejsze od liczby po lewej stronie, jesli tak to zamieniamy ja 
//z ta liczba, powtarzamy to dopoki liczba na lewo jest mniejsza od naszej liczby

//-------------------------------------------------------------------------------------------
void merge(int *tab, int l, int m, int r){
    const int n1 = m - l + 1; //wielkosc tablicy po lewej od mida
    const int n2 = r - m; //wielkosc tablicy po prawej od mida
    int *arr1 = new int [n1], *arr2 = new int [n2]; //alokacja tak duzych tablic na stosie - stack nie jest mozliwa, dlatego 
    //alokuje te 2 tablice na "stercie" - heap
    for(int i = 0; i < n1; i++) arr1[i] = tab[l + i]; //wpisujemy dane do tablicy po lewej od mida
    for(int i = 0; i < n2; i++) arr2[i] = tab[m + 1 + i]; //tutaj dla tablicy po prawej od mida (prawa tablica zaczyna sie od 
    //pierwszej tablicy [mid+1] i idzie w gore)

    int i = 0, j = 0, k = l; //i jest do odwolywania sie do indeksow tablicy po lewej od mida, natomiast j do indeksow tablicy po
    //prawej od mida, zmienna k jest do odwolywania sie do indeksow tablicy glownej, tj. int *tab
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            tab[k] = arr1[i];
            i++;//tutaj porownujemy wartosci tych dwoch podtablic i wstawiamy na odpowiednie miejsce, tutaj sortujemy malejaco
        }
        else{
            tab[k] = arr2[j];
            j++;
        }
        k++;
    }
    /* sa dlatego ze kiedy np mamy 2 tablice liczb : 4 , 0 to loopujac przez while na gorze i = 0 j = 0 oraz n1 = 1 i n2 = 1
        nastepnie sprawdzamy czy tablica1[i] <= tablica2[j] (one przechowuja wartosci kolejno 4 i 0), czyli sprawdzamy czy
        4 <= 0, a wiemy ze nie jest wiec dostaniemy sie w ten sposob do else'a ktory ustawi nam nasza zerowa szufladke tablicy bazowej
        na element mniejszy, czyli tak jak to okreslilismy tablica2[j] czyli tablica2[0] czyli na wartosc 0, i zwiekszamy j,
        czyli teraz i = 0, j = 1, n1 = 1, n2 = 1, k bylo rowne 0, teraz jest rowne 1 bo tez zwiekszylismy, wracamy teraz wiec do
        poczatku while'a, ale on nie wykona sie poniewaz ma byc mniejsze od n1 oraz j ma byc mniejsze od n2 a teraz sytuacja wyglada
        tak: 0 < n1 ale 1 !< n2 bo 0 < 1, ale 1 !< 1 wiec sie nie wykona, a przeciez mamy jeszcze jedna liczbe - 4 ktora musi trafic
        do nowo stworzonej tablicy, wiec kopiujemy teraz po prostu pozostale wartosci kolejno z tablicy lewej - mniejszej od mida,
        oraz 2 while kopiujemy z tablicy prawej - wiekszej od mida czyli w tym wypadku na poczatku wlozylismy do tablicy bazowej
        0, a teraz w uzyciemy tych while'i sprawdzimy czy i < n1 - tak, wiec przypiszemy do szufladki tab[k] - tab[1] wartosc
        tablicy mniejszej od mida, arr1[i] - arr1[0] bo i = 0
    */
    /* 
    to tez jest dlatego ze jesli np. dostaniemy takie 2 tablice: 0 1 2 3 oraz 4 5 6 to porownania beda takie: 
    czy 0 < 4 - tak
    czy 1 < 4 - tak
    czy 2 < 4 - tak
    czy 3 < 4 - tak
    i w tym momencie dochodzimy do momentu kiedy nasze i = rozmiarowi tablicy, czyli 4 wiec while sie juz nie wykona
    a przeciez mamy jeszcze cala druga tablice - 4 5 6, ale tez wiemy ze sa one posortowane juz rosnaco wiec wystarczy ze
    przekopiujemy wartosci tej tablicy pokolei do tablicy bazowej zaczynajac od ostatniej nieprzekopiowanej szufladki, czyli od
    k, dla tego przypadku zaczynamy z k = 4, i kopiujemy kolejne wartosci z tablicy drugiej - 4 5 6
    */
    while(i < n1){
        tab[k] = arr1[i];
        i++; k++;
    }
    while(j < n2){
        tab[k] = arr2[j];
        j++; k++;
    }
    delete [] arr1;
    delete [] arr2;
}

void mergeSort(int *tab, int l, int r){
    if(n == 1) return;
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(tab, l, m); //dzielimy tablice z lewej od mida na poszczegolne elementy
        mergeSort(tab, m+1, r); //to samo tylko dla tablicy z prawej od mida
        merge(tab, l, m, r); //zaczynamy sortowanie
    }
}

//-------------------------------------------------------------------------------------------
void heapify(int *tab, int n, int index){
    int largest = index; //to jest nasz korzen w drzewie binarnym
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && tab[left] > tab[largest]) largest = left;

    if(right < n && tab[right] > tab[largest]) largest = right;
    
    if(largest != index){
        swap(tab[largest], tab[index]);
        heapify(tab, n, largest);
    }
}

void heapSort(int *tab, int n){
    if(n == 1) return;
    //tworzenie drzewa binarnego o najwiekszym korzeniu
    for(int i = n/2-1; i >= 0; i--){
        heapify(tab, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(tab[0], tab[i]); //tutaj zamieniamy najwiekszy element tablicy z pierwszym dzieki czemu wiemy ze
        //ostatni element tablicy jest juz na wlasciwym miejscu - ostatnim
        heapify(tab, i, 0);
    }
}


//-------------------------------------------------------------------------------------------


int main(){
    int *tab = new int [n], *tab2 = new int [n], *tab3 = new int [n], *tab4 = new int [n], *tab5 = new int [n];
    int *tab6 = new int [n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        tab[i] = rand()%100; 
    }
    for(int i = 0; i < n; i++){
        tab2[i] = tab[i];
        tab3[i] = tab[i];
        tab4[i] = tab[i];
        tab5[i] = tab[i];
        tab6[i] = tab[i];
    }

    //for(int i = 0; i < n; i++) cout<<tab[i]<<" ";
    cout<<endl<<endl<<"========================="<<endl<<endl;

    auto start = high_resolution_clock::now();
    bubbleSort(tab);
    auto end = high_resolution_clock::now()-start;
    milliseconds ms = duration_cast<milliseconds>(end % seconds(1));
    seconds s = duration_cast<seconds>(end % minutes(1));
    cout<<"Bubble sort: ";
    //for(int i = 0; i < n; i++) cout<<tab[i]<<" ";
    cout<<" czas: "<<s.count()<<"."<<ms.count()<<" sec";

    cout<<endl<<endl;

    start = high_resolution_clock::now();
    quickSort(tab2, 0, n-1);
    end = high_resolution_clock::now() - start;
    ms = duration_cast<milliseconds>(end % minutes(1));
    s = duration_cast<seconds>(end % minutes(1));
    cout<<"Quick sort: czas: "<<s.count()<<"."<<ms.count()<<" sec";
    //for(int i = 0; i < n; i++) cout<<tab2[i]<<" ";

    cout<<endl<<endl;
    start = high_resolution_clock::now();
    selectSort(tab3);
    end = high_resolution_clock::now()-start;
    ms = duration_cast<milliseconds>(end % seconds(1));
    s = duration_cast<seconds>(end % minutes(1));
    cout<<"Select sort: czas : "<<s.count()<<"."<<s.count()<<" sec";
    //for(int i = 0; i < n; i++) cout<<tab3[i]<<" ";

    cout<<endl<<endl;
    start = high_resolution_clock::now();
    insertSort(tab4);
    end = high_resolution_clock::now() - start;
    ms = duration_cast<milliseconds>(end % seconds(1));
    s = duration_cast<seconds>(end % minutes(1));
    cout<<"Insert sort: czas: "<<s.count()<<"."<<ms.count()<<" sec";
    //for(int i = 0; i < n; i++) cout<<tab4[i]<<" ";

    cout<<endl<<endl;
    start = high_resolution_clock::now();
    mergeSort(tab5, 0, n-1);
    end = high_resolution_clock::now() - start;
    ms = duration_cast<milliseconds>(end % seconds(1));
    s = duration_cast<seconds>(end % minutes(1));
    cout<<"Merge sort: czas: "<<s.count()<<"."<<ms.count()<<" sec";

    cout<<endl<<endl;
    start = high_resolution_clock::now();
    heapSort(tab6, n);
    end = high_resolution_clock::now() - start;
    ms = duration_cast<milliseconds>(end % seconds(1));
    s = duration_cast<seconds>(end % minutes(1));
    cout<<"Heap sort: czas: "<<s.count()<<"."<<ms.count()<<" sec";

    delete [] tab;
    delete [] tab2;
    delete [] tab3;
    delete [] tab4;
    delete [] tab5;
    delete [] tab6;

    return 0;
}