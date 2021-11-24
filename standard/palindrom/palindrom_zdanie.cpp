#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){

    int i, j;
    string slowo;

    cout<<"Podaj zdanie, ktore chcesz sprawdzic: ";
    getline(cin, slowo);
    regex reg("(\\s+)");
    slowo = regex_replace(slowo, reg, "");
    transform(slowo.begin(), slowo.end(), slowo.begin(), ::tolower);

    int x = slowo.length();

    for(i = 0, j = x - 1; i<j; i++, j--){
        if(slowo[i] != slowo[j]){
            break;
        }
    }

    if (i < j){
        cout << "Podane zdanie nie jest palindromem" << endl;
    }
    else{
        cout << "Podane zdanie jest palindromem" << endl;
    }

return 0;
}
