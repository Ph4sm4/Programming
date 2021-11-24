#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

int main(){

    deque<int> years;
    for(int i = 1; i<=7; i++){
        years.push_front(2019+i);
    }
    for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }

    cout<<years.size()<<" "<<years.max_size()<<endl;
    years.pop_front();
    cout<<"------"<<endl;

    years.resize(years.size()+5, 3);//dodajemy 5 w tym wypadku trojek, jesli nie bedzie tego przecinka tylko bedzie
    //samo years.size() to domyslnie wypelni dolozone miejsca zerami
    for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------"<<endl;

    years.insert(years.begin()+3, 1);
    for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }

    years.insert(years.end()-3, 5, -1);//cofniemy sie o 3 miejsce z miejsca za ostatnim elementem i wpakujemy tam
    //pięć -1

    for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------------"<<endl;
    vector<int> v{999, 998, 997};
    auto in = years.insert(years.begin()+1, v.begin(), v.end());//wkladam za pierwszym elementem wszystko co jest
    //pomiedzy iteratorami tzn caly vektor v

    for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<"------------"<<endl;
    auto next = years.erase(years.begin()+1);//kasuje drugi element tj. 999 zwraca nastepny element za tym
    //skasowanym. w tym wypadku 998
    for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }
    cout<<endl<<*next<<endl<<"--------"<<endl;

    years.emplace_front(100);//wstawia kopie, zwraca referencje do wstawionego obiektu
     for(deque<int>::iterator z = years.begin(); z!=years.end(); ++z){
        cout<<*z<<" ";
    }
}