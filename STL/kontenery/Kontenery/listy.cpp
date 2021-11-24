#include <iostream>
#include <algorithm>
#include <list>
#include <forward_list>
using namespace std;

int main(){
    list<int> bigL = {1, 2, 3, 4, 5, 5, 5, 4, 3, 2, 1};
    bigL.insert(--bigL.end(), 100);//pierwsza zmienna odpowiada za miejsce gdzie chce to wstawic do list
    //natomiast druga co chce wstawic (tutaj bedzie to 100)
    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"---------"<<endl;
    cout<<"Size: "<<bigL.size()<<endl<<"---------"<<endl;
    bigL.pop_front();
    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    bigL.push_back(-5);
    bigL.push_front(-10);
    bigL.insert(bigL.begin(), 100);
    auto pos = ++++++bigL.begin();//iterator na 4 element

    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;
    auto newpos = bigL.insert(pos, 1500);
    *pos-= 1;//odejmujemy 1 od liczby z indeksem 4, w tym wypadku akurat 3
    *newpos -= 1;//odejmujemy 1 od liczby z indeksem 3 w tym wypadku od 1500

    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    int move = 5;
    auto pos2 = bigL.begin();
    while(pos2 != bigL.end() && move){
        ++pos2;
        --move;
    }
    cout<<*pos2<< "!"<<endl;
    cout<<endl<<"------"<<endl;

    //usuwanie
    bigL.remove(5);//usuwa wszystkie 5-ki
    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    //znajdowanie i zwrot iteratora

    auto found = find(bigL.begin(), bigL.end(), 100);
    bigL.erase(found);
    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    //sortowanie
    bigL.sort([](auto& a, auto& b){
        return (a<b);
    });//auto& a i auto& b to poszczegolne pary z listy
    //return(a>b) to warunek ktory odpowiada za to czy lista ma byc posortowana od najwiekszego do najmniejszego,
    //czy od najmniejszego do najwiekszego
    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    //usuwanie pod warunkiem, ze
    bigL.remove_if([](auto& e){
        return (e<4);
    });
    for(list<int>::iterator z = bigL.begin(); z!= bigL.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    forward_list<string> stringList {"tak", "nie", "nie wiem", "chyba"};
    cout<<*++++stringList.begin()<<endl;
    //--stringList.end(); nie przejdzie poniewaz jest to lista jedno kierunkowa
    //nie ma size()
    cout<<distance(stringList.begin(), stringList.end())<<endl; //tego mozna uzywac zamiast size()


return 0;}
