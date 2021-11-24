#include <iostream>
#include <stack> //stos 
#include <regex> //wyrazenia regularne 
#include <string> //getline
using namespace std;
//    ((3-2)^3*(3+3)*3)/2
//    2-(a*3-(4+a*c-b))

string convert(string n){
    string output = "";
    stack<char> s; //operatory
    for(int i = 0; i < n.length(); i++){
        bool looped = false;
        if((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z')) output = output + n[i] + " "; //jesli nie jest to operator to dodaj do wyjscia
        else if(n[i] >= '0' && n[i] <= '9'){
            while(n[i] >= '0' && n[i] <= '9'){
                output += n[i];
                i++;
            }
            i--;
            output += ' ';
        } 
        else if(!s.empty()){
            //cout<<"operator: "<<n[i]<<" "<<i<<endl;
            //cout<<"current output is: "<<output<<endl;
            //cout<<"stack: ";
            //for (stack<char> dump = s; !dump.empty(); dump.pop())
            //     cout << dump.top() << " ";
            //cout<<endl;
            while(!s.empty() && (((n[i] == '-' || n[i] == '+') && (s.top() == '-' || s.top() == '+')) ||
                ((n[i] == '-' || n[i] == '+') && (s.top() == '*' || s.top() == '/')) ||
                ((n[i] == '*' || n[i] == '/') && (s.top() == '*' || s.top() == '/')) ||
                ((n[i] == '-' || n[i] == '+' || n[i] == '*' || n[i] == '/') && s.top() == '^'))){
                    output += s.top();
                    output += ' ';
                    //cout<<"top: "<<s.top()<<endl;
                    //cout<<"first while: "<<output<<endl;
                    s.pop();
                    looped = true; 
            }//tutaj jesli natrafimy na znak o mniejszej lub rownej waznosci niz jest na stosie to zdejmujemy
            //ze stosu poki stos jest pusty lub poki na stosie nie ma operatora wazniejszego niz obecny
            
            if(looped){
                s.push(n[i]);
                //cout<<"looped if: "<<s.top()<<endl;
                //cout<<"looped if output: "<<output<<endl;
                looped = false;
                continue;
            }//jesli skonczylismy zdejmowanie to dodajemy teraz aktualny operator na stos i idziemy dalej
            if(((n[i] == '*' || n[i] == '/') && (s.top() == '-' || s.top() == '+')) || n[i] == '^' || n[i] == '(' || (s.top() == '(')){
                s.push(n[i]);
            }//tutaj jesli operator obecny jest wazniejszy od operatora na stosie to po prostu wkladamy na stos
            else if(n[i] == ')'){
                //cout<<"before here: "<<output<<endl;
                while(s.top() != '('){
                    output += s.top();
                    output += ' ';
                    //cout<<"here top: "<<s.top()<<endl;
                    s.pop();
                    //cout<<"here: "<<output<<endl;
                }
                //cout<<"before pop: "<<s.top()<<endl;
                s.pop();
                //cout<<"stack after: ";
                //for (stack<char> dump = s; !dump.empty(); dump.pop())
                 //cout << dump.top() << " ";
                 //cout<<endl;
            }//jesli natrafimy na znak ')' to znaczy, ze musimy zdjac wszystkie operatory po kolei ze stosu az do znaku '(' wlacznie z nim
        }
        else{
            s.push(n[i]);
        }//jesli stos jest pusty to po prostu wkladamy operator

        if(i == n.length() - 1){
            while(!s.empty()){
                output += s.top();
                output += ' ';
                s.pop();
            }
        }//jesli dojdziemy do konca wyrazenia to po prostu zdejmujemy wszystkie operatory, ktore zostaly ze stosu na wyjscie
    }

    return output;
}

int main(){

    string n;
    getline(cin, n); //pobranie wyrazenia, moga byc w tym spacje/znaki biale 
    regex reg("\\s+");
    n = regex_replace(n, reg, ""); //usuwamy wszystkie znaki biale z wyrazenia
    cout<<convert(n);

    return 0;
}

//12 + a * (b * c + d / e)