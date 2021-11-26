#include <iostream>
#include <cmath>
using namespace std;

int main(){

string slowo;
cout<<"Podaj slowo ktore chcesz sprawdzic, czy jest palindromem: ";
cin>>slowo;
int x = slowo.length();
int j = x;
bool check = false;
for(int i = 0; i < ceil(x/2); i++){
    if(slowo[i] == slowo[j-1]){
        check = true;
    }
    else{
        check = false; 
        break;
    }
    j--;
}
if(check){
    cout<<"Palindrom"<<endl;
}
else{
    cout<<"Nie palindrom"<<endl;
}


return 0;
}
