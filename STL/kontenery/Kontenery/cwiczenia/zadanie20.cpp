#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "printSTL.h"
using namespace std;


int main(){

    list<int> l;

    for(int i = 1; i<=100; i++){
        if(i%5 != 0){
            l.push_back(i);
        }
        
    }
    
    //l.sort(); rosnaco
    //l.sort(greater<int>()); malejaco

    list<int>::iterator it = l.begin();
    auto e = l.end();

    /* 1 metoda
    for(it; it!=e; ++it){
        cout<<*it<<" ";
    }*/

    /* 2 metoda
    while(it != e){
        cout<<*it<<" ";
        ++it;
    }*/
    /* 3 metoda
    for(int x : l){
        cout<<x<<" ";
    }*/

    /* 4 metoda
    for_each(l.begin(), l.end(), [] (int& a){
        cout<<a<<" ";
    });*/
    ostream_iterator<int> out(cout, " : ");
    for(auto i : {1,2,3,4,5,6}){
        *out = i;
        out++;
    }
    cout<<endl;
    copy(l.begin(), l.end(), out);

}