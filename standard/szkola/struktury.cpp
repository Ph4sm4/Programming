#include <iostream>
using namespace std;

class Ulamek{
    public:
    Ulamek(){
        cout<<"Podaj: ";
        cin>>licznik>>mianownik;
    }
    Ulamek(int x, int y){
        licznik = x;
        mianownik = y;
    }
    void wyswietl(){
        skroc();
        cout<<"Po skroceniu: "<<licznik<<" / "<<mianownik<<endl;
    }

    private:
    int licznik, mianownik;
        int nwd(int a, int b){
            while(a != b){
                if(a>b){
                    a-=b;
                }
                else{
                    b-=a;
                }
            }
            return a;
        }
        void skroc(){
            int dzielnik = nwd(licznik, mianownik);
            licznik /= dzielnik;
            mianownik /= dzielnik;
        }
};

int main(){

    Ulamek ulamek;
    ulamek.wyswietl();

    return 0;
}