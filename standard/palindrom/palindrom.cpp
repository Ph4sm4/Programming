#include <iostream>
#include <string>
using namespace std;

int main(){

    int i, j;
    string slowo;

    cout<<"Podaj wyraz, ktory chcesz sprawdzic: ";
    cin>>slowo;
    int x = slowo.length();
    for(i = 0, j = x - 1; i<j; i++, j--){
        if(toupper(slowo[i]) != toupper(slowo[j])){
            break;
        }
    }

    if (i < j){
        cout << "Podany wyraz nie jest palindromem" << endl;
    }
    else{
        cout << "Podany wyraz jest palindromem" << endl;
    }

return 0;
}
