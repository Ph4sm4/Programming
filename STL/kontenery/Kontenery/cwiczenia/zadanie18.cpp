#include <iostream>
#include <algorithm>
#include <vector>
#include "printSTL.h"
using namespace std;

int main(){
    double number;
    double c;

    cout<<"Enter a number: ";
    cin>>number;

    while ( c < 1 || c > 10){
        cout<<number<<endl;
        number = number * 2; 
        cout<<"Enter number between 1 and 10 to stop the program: ";
        cin>>c;
        if(c >= 1 && c <= 10){
            break;
        }
    }
    return 0;
}