#include <iostream>
using namespace std;

int main(){

    cout<<"Podaj: ";
    int number;
    int count = 0;
    cin>>number;

    for(int i = 1; i <= 9; i++){
        if(number%i == 0){
            count++;
        }
    }
    if(count == 2){
        cout<<"TAK"<<endl;
    }
    else{
        cout<<"NIE"<<endl;
    }
    
    return 0;
}