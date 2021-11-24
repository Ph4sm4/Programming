#include <iostream>
using namespace std;

class Kwadrat{
    double *bok1, *bok2;

public:
    Kwadrat();
    Kwadrat(double a, double b);
    Kwadrat(Kwadrat &kw);
    ~Kwadrat();
    void wyswietl();
    void aktualizuj(double a, double b);
    Kwadrat& operator=(const Kwadrat &KwadratPrawy);
};

Kwadrat::Kwadrat(): bok1(new double (0)), bok2(new double (0)) {}

Kwadrat::Kwadrat(double a, double b): bok1(new double (a)), bok2(new double (b)) {}

Kwadrat::~Kwadrat(){
    delete bok1;
    delete bok2;
}

Kwadrat& Kwadrat::operator=(const Kwadrat &KwadratPrawy){
    if(this == &KwadratPrawy) return *this;

    *this->bok1 = *KwadratPrawy.bok1;
    *this->bok2 = *KwadratPrawy.bok2;

    return *this;
}

void Kwadrat::wyswietl(){
    cout<<*bok1<<" "<<*bok2<<endl;
}

void Kwadrat::aktualizuj(double a, double b){
    *bok1 = a;
    *bok2 = b;
}

Kwadrat::Kwadrat(Kwadrat &kw){
    bok1 = new double (*kw.bok1);
    bok2 = new double (*kw.bok2);
    // *bok1 = *kw.bok1;
    // *bok2 = *kw.bok2;
}

int main(){

    Kwadrat k1, k2(4, 5);

    k1.wyswietl();
    k2.wyswietl();
    k1.aktualizuj(1, 2);
    k2.aktualizuj(44, 55);
    k1.wyswietl();
    k2.wyswietl();

    Kwadrat k3(k2);
    cout<<"-"<<endl;
    k3.wyswietl();

    return 0;
}