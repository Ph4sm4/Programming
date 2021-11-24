#include <iostream>
using namespace std;

class Entity{
    int x, y;
    mutable int z;
public:
    int GetX() const{
        //ta funkcja nic nie modyfikuje bo jest const, chyba ze zmienna jest mutable
        z = 5;

        return x;
    }
    void SetX(int x){
        this->x = x;
    }
};

void PrintEntity(const Entity &entity){
    //musi byc const przy getx bo argumentem jest const ref, wiec jesli nie bedzie const przy ciele funkcji to nie bede jej tu mogl 
    //wywolac
    cout<<entity.GetX()<<endl;
}

int main(){

    const int maxAge = 99;

    const int *a = new int; //nie mozna zmienic wartosci pod tym adresem
    //mozna tez int const* a = new int; to jest to samo
    //*a = 2;
    //to mozna:
    a = (int*)&maxAge;
    cout<< *a <<endl;

    int* const b = new int; //moge zmienic wartosc pod adresem, ale nie adres
    //to mozna
    *b = 2;
    //ale to juz nie
    //b = (int*)&maxAge;

    const int* const c = new int (5); //nie moge zmienic ani wartosci pod adresem, ani samego adresu
    cout << *c << endl;

    return 0;
}