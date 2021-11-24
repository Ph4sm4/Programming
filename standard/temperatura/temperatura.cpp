#include <iostream>
using namespace std;

int main(){
    
    int x;

    cout<<"Podaj liczbe dni z jakiej chcesz zliczyc srednia temperatur: ";
    cin>>x;

    float *tab;
    tab = new float [x];

    float srednia = 0;
    float suma = 0;

    for(int i = 0; i<x; i++){
        cout<<"Podaj temperature z dnia "<<i+1<<": ";
        cin>>tab[i];
        suma = suma + tab[i];
    }

    srednia = suma/x;

    cout<<"Srednia temperatur z okresu "<<x<<" dni wynosi: "<<srednia<<endl;

    delete [] tab;
    


return 0;}
