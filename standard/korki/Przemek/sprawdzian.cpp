#include <iostream>
using namespace std;

/*
Lewa strona jest suma kolejnych n liczb parzystych. Po prawej stronie podany jest wzór obliczający sumę.


2*1 + 2*2 + 2*3 + ... + 2*n = (1+n)*n



Oblicz iteracyjnie lewą stronę równania.

Napisz funkcję pozwalającą obliczyć prawą stronę.

Napisz funkcję pozwalającą obliczyć lewą stronę rekurencyjnie.

Podaj wyniki swoich obliczeń.

Wyniki uzyskane trzema metodami powinny być równe.



Umieść poniżej listing programu.
*/

int sumaIteracyjnie(int n)
{
    int suma = 0;

    for (int i = 1; i <= n; i++)
    {
        suma += 2 * i;
    }

    return suma;
}

int sumaRekurencyjnie(int n)
{
    if (n == 1)
        return 2;

    return 2 * n + sumaRekurencyjnie(n - 1);
}

int obliczPrawaStrone(int n)
{
    return n * (n + 1);
}

int main()
{
    int n;
    cout << "Podaj n: ";
    cin >> n;

    cout << "Suma iteratycjnie: " << sumaIteracyjnie(n) << endl;
    cout << "Suma rekurencyjnie: " << sumaRekurencyjnie(n) << endl;
    cout << "Wartosc prawej strony: " << obliczPrawaStrone(n) << endl;

    return 0;
}
