#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> reszta;
    cout<<"Podaj system: ";
    int system;
    cin>>system;
    cout<<"Podaj liczbe: ";
    int liczba;
    cin>>liczba;

    while(liczba){
        reszta.push_back(liczba%system);
        liczba /= system;
    }
    reszta.reverse();
    list<int>::iterator it = reszta.begin();

    if(system > 10){
        while(it != reszta.end()){
            if(*it >= 10){
                char x = 55+*it;
                cout<<x;
            }
            else{
                cout<<*it;
            }
        it++;
        }
    }
    else{
        for(list<int>::iterator it2 = reszta.begin(); it2 != reszta.end(); it2++){
            cout<<*it2;
        }
    }


    return 0;
}