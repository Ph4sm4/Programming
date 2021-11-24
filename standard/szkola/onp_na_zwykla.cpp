#include <iostream>
#include <string> //getline
#include <stack> //stos
#include <math.h> // pow()
using namespace std;

bool isOper(char n){
    return n == '*' || n == '/' || n == '-' || n == '+' || n == '^';
}

string convert(string n){
    stack<string> s;
    for(int i = 0; i < n.length(); i++){
        if(isblank(n[i])) continue;
        if(isOper(n[i])){ // jesli znak jest operatorem to pobieramy 2 ostatnie wyrazenia ze stosu i uzywamy na nich tego operatora
            string n1 = s.top();
            s.pop();
            string n2 = s.top();
            s.pop();
            string oper = ""; oper += n[i];
            string temp = "(" + n2 + oper + n1;
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
            s.push(temp);
        } else{
            string temp = "";
            temp += n[i];
            s.push(temp);
        }
    }
    string output = s.top();
    output.erase(0, 1);
    output.erase(output.length() - 1, 1);

    return output;
}
double calculate(string n){
    double _res;
    stack<double> s;
    for(int i = 0; i < n.length(); i++){
        if(isblank(n[i])) continue;
        if(isOper(n[i])){
            double n1 = s.top();
            s.pop();
            double n2 = s.top();
            s.pop();
            switch(n[i]){
                case '*':{
                    s.push(n2 * n1);
                    break;
                }
                case '/':{
                    s.push(n2 / n1);
                    break;
                }
                case '-':{
                    s.push(n2 - n1);
                    break;
                }
                case '+':{
                    s.push(n2 + n1);
                    break;
                }
                case '^':{
                    s.push(pow(n2, n1));
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
            s.push(stoi(temp));
        }else{
            s.push(n[i] - '0');
        }
    }
    _res = s.top();
    s.pop();

    return _res;
}

int main(){

    string n;
    getline(cin, n); //pobranie wyrazenia, moga byc w tym spacje/znaki biale 
    cout<<convert(n)<<endl;
    cout<<calculate(n);

    return 0;
}
//3 4 2 * 1 5 - 2 ^ / +