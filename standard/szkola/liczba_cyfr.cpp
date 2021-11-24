#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    cout<<"Podaj liczbe: ";
    int liczba;
    cin>>liczba; 
    int ile[10] = {0};
    string temp = to_string(liczba);
    for(int i = 0; i < 10; i++){
        int c = count(temp.begin(), temp.end(), i + '0');
        ile[i] += c;
    }
    
    for(int i = 0; i < 10; i++){
        cout<<i<<" "<<ile[i]<<endl;
    }

    return 0;
}