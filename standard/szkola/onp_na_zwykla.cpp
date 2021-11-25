#include <iostream>
#include <string> //getline
#include <stack> //stos
#include <cmath> // pow()
using namespace std;

bool isOper(char n){
    return n == '*' || n == '/' || n == '-' || n == '+' || n == '^';
}

string convert(string n){
    stack<string> s;
    for(int i = 0; i < n.length(); i++){
        if(isblank(n[i])) continue; //jesli znak bialy to nic nie robimy
        if(isOper(n[i])){ // jesli znak jest operatorem to pobieramy 2 ostatnie wyrazenia ze stosu i uzywamy na nich tego operatora
            string n1 = s.top();
            s.pop();
            string n2 = s.top();
            s.pop();
            string oper = ""; oper += n[i];
            string temp = "(" + n2 + oper + n1; //wykonujemy operacje w kolejnosci: wyraz 2 ze stosu; operator; wyraz 1 ze stosu
            temp += ")";
            s.push(temp);
        }
        else if(n[i] >= '0' && n[i] <= '9'){
            string temp = "";
            while(n[i] >= '0' && n[i] <= '9'){
                temp += n[i];
                i++;
            }
            i--;
            s.push(temp); //tak jak w przeliczaniu zwyklego zapisu na ONP jesli liczba ma wiecej niz jedna cyfre w sobie, to zbieramy je wszystkie
            //i wkladamy na stos jako jedna liczbe
        } else{
            string temp = "";
            temp += n[i];
            s.push(temp); //jesli zaden z powyzszych warunkow nie zostal spelniony to po prostu wkladamy na stos
        }
    }
    string output = s.top(); //pozadany wynik jest na samej gorze naszego stosu
    output.erase(0, 1); //usuwamy lewy najbardziej skrajny nawias
    output.erase(output.length() - 1, 1); //usuwamy prawy najbardziej skrajny nawias
    
    return output;
}
double calculate(string n){
    double _res;
    stack<double> s;
    for(int i = 0; i < n.length(); i++){
        if(isblank(n[i])) continue; //jesli znak bialy to nic nie robimy
        if(isOper(n[i])){
            double n1 = s.top();
            s.pop();
            double n2 = s.top();
            s.pop(); //tak jak wczesniej zdejmujemy 2 pierwsze liczby ze stosu i w zaleznosci od operatora wykonujemy na nich operacje
            //pamietamy dalej o kolejnosci: liczba 2 w kolejnosci ze stosu; operator; liczba ktora na poczatku zostala zdjeta
            switch(n[i]){
                case '*':{
                    s.push(n2 * n1); //mnozenie 
                    break;
                }
                case '/':{
                    s.push(n2 / n1); //dzielenie
                    break;
                }
                case '-':{
                    s.push(n2 - n1); //odejmowanie
                    break;
                }
                case '+':{
                    s.push(n2 + n1); //dodawanie
                    break;
                }
                case '^':{
                    s.push(pow(n2, n1)); //potegowanie
                    break;
                }
            }
        }else if(n[i] >= '0' && n[i] <= '9'){
            string temp = "";
            while(n[i] >= '0' && n[i] <= '9'){
                temp += n[i];
                i++;
            }
            i--;
            s.push(stoi(temp)); //jesli liczba ma wiecej cyfr niz 1 to zbieramy je w calosc i wkladamy na stos
        }else if((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z')){
            return NULL; //jesli wyrazenie zawiera zmienna to nie mozemy obliczyc jego wartosci
        }
        else{
            s.push(n[i] - '0'); //jesli zadne z powyzszych wyrazen logicznych nie jest spelnione to po prostu wkladamy ta liczbe na stos
        }
    }
    _res = s.top(); //wynik jest na wierzchu stosu
    s.pop();

    return _res;
}

int main(){

    string n;
    getline(cin, n); //pobranie wyrazenia, moga byc w tym spacje/znaki biale 
    cout<<convert(n)<<endl;
    double val = calculate(n);
    if(val == NULL) cout<<"not possible";
    else cout<<val;

    return 0;
}
//3 4 2 * 1 5 - 2 ^ / +