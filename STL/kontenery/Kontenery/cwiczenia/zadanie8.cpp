#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "printSTL.h"
using namespace std;

double add(vector<double> vName){

    double sum = vName.at(0) + vName.at(1);
    return sum;
}

double subtract1(vector<double> vName){

    double sub1 = vName.at(0) - vName.at(1);

    return sub1;
} 

double subtract2(vector<double> vName){

    double sub2 = vName.at(1) - vName.at(0);

    return sub2;
} 

double division1(vector<double> vName){  

        double div1 = vName.at(0) / vName.at(1);
        return div1;

}

double division2(vector<double> vName){
    
        double div1 = vName.at(1) / vName.at(0);
        return div1;

}

double mult(vector<double> vName){
    
    double m = vName.at(0)*vName.at(1);
    return m;

}


int main(){

    vector<double> v = {};

    cout<<"Enter 1 number: ";
    double value;
    cin>>value;
    v.push_back(value);
    value = 0;

    cout<<"Enter 2 number: ";
    cin>>value;
    v.push_back(value);
    cout<<"Enter sign: ";
    char sign;
    cin>>sign;

    if(sign == '+'){
         cout<<"Sum: "<<add(v)<<endl;
    }
    else if(sign == '-'){
        cout<<"Sub1: "<<subtract1(v)<<endl;
        cout<<"Sub2: "<<subtract2(v)<<endl;
    }
    else if(sign == '/'){
        if(v.at(0) == 0 || v.at(1) == 0){

            cout<<"ERROR: division by 0"<<endl;

        }
        else{
            cout<<"Div: "<<division1(v)<<endl;
            cout<<"Div: "<<division2(v)<<endl;
        }
        
    }
    else if(sign == '*'){
        cout<<"Mult: "<<mult(v)<<endl;
    }
    else{
        cout<<"There is no such operation!"<<endl;
    }
    return 0;
}