#include <bits/stdc++.h>
#include "printSTL.h"
using namespace std;

int main(){ 
    stack<int> cnt1;
    stack<int>::value_type x1_0 = 1;
    decltype(cnt1)::value_type x1_1 = 2;
    cout<<x1_0<<" "<<x1_1<<endl;
    cout<<typeid(x1_0).name()<<endl;

    vector<string> cnt2 = {"a", "b", "c"};

    [](decltype(cnt2)::reference str){
        str = "napis";
    }(cnt2[0]);
    printSTL(cnt2, " ");

    [](decltype(cnt2)::const_reference str){ //const decltype
        cout<<str<<endl;
    }(cnt2[0]);

    decltype(cnt2)::iterator it = cnt2.begin();
    *it = "nowy napis";
    cout<<*it<<endl;
    printSTL(cnt2, " ");

    decltype(cnt2)::const_iterator it2 = cnt2.begin();
    cout<<*it2<<endl;
    //sa jeszcze reverse_iterator ktory kiedy go zwiekszamy to bedzie jakby przechodzil od konca do poczatku i analogicznie const_reverse_iterator


    //pointer jest jeszcze const_pointer
    set<double> cnt3 = {1.5, 2.3, 6.4, 1.2};
    decltype(cnt3)::pointer ptr3 = new decltype(cnt3)::value_type;
    *ptr3 = 15.99;
    cout<<*ptr3<<endl;
    
    auto ptr3_1 = new decltype(cnt3)::value_type;
    cout<<typeid(ptr3_1).name()<<endl; 


    decltype(cnt3)::size_type ile3; //typ ktorym okresla sie rozmiar
    cout<<typeid(ile3).name()<<endl;


    //key_type : typ klucza w przypadku kontenera asocjacyjnego
    //mapped_type : typ wartosci w parze klucz-wartosc <- o to chodzi

    map<int, char> cnt4{};
    cout<<typeid(decltype(cnt4)::key_type).name()<<endl; //int
    cout<<typeid(decltype(cnt4)::mapped_type).name()<<endl; //char

    cout<<typeid(decltype(cnt4)::key_compare).name()<<endl;
    cout<<typeid(decltype(cnt4)::value_compare).name()<<endl;

    unordered_map<int, int> cnt5 = { {1,1}, {2,2}, {3,3}};
    cout<<typeid(decltype(cnt5)::hasher).name()<<endl;


    return 0;
}