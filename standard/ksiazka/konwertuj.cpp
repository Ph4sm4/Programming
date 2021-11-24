#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    cout<<"Podaj litry/100 km: ";
    double litry;
    cin>>litry;

    const double galon = 3.875;
    const double mila = 0.6214;
    
    double x = 100/litry;
    double km_galon = x * galon;
    double mil_galon = km_galon*mila;

    cout<<fixed<<setprecision(1)<<"Samochod pali "<<litry<<"l/100 km, czyli "<<mil_galon<<"mil/galon"<<endl;

    return 0;
}