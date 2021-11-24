#include <iostream>
using namespace std;

int main(){

    try{
        char val;
        cin>>val;
        if(!isdigit(val)) throw 10;
        else if(val == '0') throw 0;
        else{
            cout<<"git"<<endl;
        }
    }
    catch(int x){
        switch (x)
        {
            case 0: cout<<"Nie mozna dzielic!"; break;
            case 10: cout<<"Nie liczba!"; break;
        }  
    }
    return 0;
}