#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <ctime>
#include <bits/stdc++.h>//remove()

using namespace std;


int main(){
    //vector<int> w = {1, 1, 1}; 3 razy wartosc 1 
    //vector<int> w {1, 1, 1}; 3 razy 1 w wektorze
    /*int x = 15;
    vector<int> numbers;
    for(int i = 0; i<10; i++){
        numbers.push_back(i);
        cout<<numbers.at(i)<<endl;
    }
    cout<<"size: "<<numbers.size()<<endl;
    cout<<"capacity: "<<numbers.capacity()<<endl;*/

    vector<int> vec2 {1,2,3,4,5};
    for(auto iter= vec2.begin(); iter!= vec2.end(); ++iter){
        cout<<*iter<<" ";
    }
    auto iter = vec2.begin()+3;
    cout<<endl<<*iter<<endl;

    //vector<int>::const_iterator it = vec2.end()-3;
    vector<int>::iterator it = vec2.end()-3;
    //tylko do odczytu, nie mozna zrobic tego co w petli ponizej
    //jesli byloby samo ::iterator to mozna by ta petle zastosowac
    //for(it; it!=vec2.end(); ++it){
    //   *it = *it+3;
    //   cout<<*it<<endl;
    //}
    cout<<"----------"<<endl;
    it = vec2.begin();
    while(it!=vec2.end()){
        cout<<*it++<<endl;
    }
    cout<<"--------"<<endl;
    cout<<vec2.front()<<endl;
    cout<<vec2.back()<<endl<<"-------"<<endl;


    cout<<*vec2.cbegin()<<endl;
    cout<<*--vec2.cend()<<endl;
    cout<<"----------"<<endl;


    cout<<*++vec2.crbegin()<<endl;
    cout<<"------"<<endl;

    for(auto it = vec2.crbegin(); it != vec2.crend(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl<<"----------"<<endl;
    //r powoduje przekierowanie iteratora na ostatni element wektora tzn ze kiedy
    //wskazywal na pierwszy element z funkcja begin() to z funkcja rbegin() bedzie
    //wskazywal na ostatni element, a z funkcja rend() na pierwszy. mozna go
    //modyfikowac czyli *it = cos

    //natomiast kiedy bedziemy mieli crend() lub crbegin to procz tego ze bedzie
    //wskazywac tak jakby od tylu to jeszcze nie bedzie mozna modyfikowac szufladki
    //na ktora dany iterator wskazuje tj. *it = cos nie bedzie mozna wykonac

    vec2.push_back(10);//dodaje 10 na koniec wektora
    auto x = vec2.size();
    vec2.push_back(vec2.size());
    //cout<<vec2.at(x-1)<<endl;
    //vec2.pop_back();//zabiera z konca 10
    //cout<<vec2.at(z-1)<<endl;
    for(auto it = vec2.cbegin(); it!=vec2.cend(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl<<"---------"<<endl;
    vector<int> v {2, 3, 5, 2, 10, 2, 123};
    //auto newEnd = remove(v.begin(), v.end(), 2);//pozbedzie sie 2 z wektora
    //przesuwajac elementy tzn. zawartosc wektora: 1 2 3 4 5
    //po usunieciu: 1 3 4 5 5 tyle ile elementow usunelismy tyle z konca
    //zostanie powtorzone size() sie nie zmieni
    cout<<"tutaj: ";
    for(auto it10 = v.begin(); it10 != v.end(); it10++){
        cout<<*it10<<" ";
    }
    cout<<endl;
    auto newEnd = remove(v.begin(), v.end(), 2);

    for(vector<int>::iterator z = v.begin(); z!=v.end(); ++z){
        cout<<*z<<" ";
    }
    v.erase(newEnd, v.end());
    cout<<endl<<"-------"<<endl;

    for(vector<int>::iterator z = v.begin(); z!=v.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"---------"<<endl;

    do{
        auto foundIndex = find(v.begin(), v.end(), 5);
        if(foundIndex!=v.end()){
            *foundIndex = v.back(); //najpierw do zmiennej foundindex przypisze index w ktorym wystepuje cyfra 5
            //nastepnie przypisuje do tego indeksu wartosc jaka byla na koncu czyli w tym wypadku na miejsce
            //piatki trafi liczba 123, a pozniej usuwamy ostatni element
            v.pop_back();
        }
        else{
            break;
        } 
    }while(true);

    for(vector<int>::iterator z = v.begin(); z!=v.end(); ++z){
        cout<<*z<<" ";
    }

    v.reserve(100);
    cout<<endl<<"---------"<<endl<<v.size()<<" "<<v.capacity()<<endl;
    v.shrink_to_fit();//dopasowuje capacity do size
    cout<<"--------"<<endl;
    cout<<"After shrink to fit: "<<v.capacity()<<endl;

    v.resize(50, 0); //zwieksza size do 50, a wszystkie nowe szufladki zapelnia zerami gdyby bylo
    //v.resize(50, 2) to wypelnilby dwojkami
    cout<<"-------"<<endl;
    cout<<v.size()<<" "<<v.capacity()<<" "<<v.at(39)<<endl;
    cout<<"---------"<<endl;


    auto a = v.insert(v.begin()+17, 9);
    //cout<<v.size()<<" "<<v.capacity()<<" "<<v.at(18)<<endl;
    for(vector<int>::iterator z = v.begin(); z!=v.end(); ++z){
        cout<<*z<<" ";
    }
    auto foundIndex = find(v.begin(), v.end(), 9);
    int index = distance(v.begin(), foundIndex);//zwraca index liczby znalezionej przez find()
    cout<<endl<<index<<endl;
}
