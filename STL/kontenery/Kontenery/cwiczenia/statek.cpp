#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <windows.h>
#include "printSTL.h"
using namespace std;


int main(){

    list<int> ship_price = {20000, 7000, 2000};
    vector<int> users_money;
    int value;

    cout<<"Enter the amount of metal you have: ";
    cin>>value;
    users_money.push_back(value);
    value = 0;

    cout<<"Enter the amount of crystal you have: ";
    cin>>value;
    users_money.push_back(value);
    value = 0;

    cout<<"Enter the amount of deuter you have: ";
    cin>>value; 
    users_money.push_back(value);
    value = 0;
 
    int m, c, d;
    float m1, c1, d1;
    list<int>::iterator it = ship_price.begin();
    m1 = users_money.at(0)/(*it);
    ++it;
    c1 = users_money.at(1)/(*it);
    ++it;
    d1 = users_money.at(2)/(*it);
    m = floor(m1);
    c = floor(c1);
    d = floor(d1);

    bool ex = false;

    if(users_money.at(0) < 0){
        cout<<"Error! You can't have negative number of metal"<<endl;
        ex = true;
    }
    if(users_money.at(1) < 0){
        cout<<"Error! You can't have negative number of crystal"<<endl;
        ex = true;
    }
    if(users_money.at(2) < 0){
        cout<<"Error! You can't have negative number of deuter"<<endl;
        ex = true;
    }
    if(ex == true){
        exit(0);
    }

    if(m<c && m<d || m == c && m < d|| m == d && m < c || m == d && m == c){
        if(m == 0){
            cout<<"You can't afford any new ships"<<endl;
        }
        else
            cout<<"You can buy "<<m<<" ships"<<endl;
    }
    else if(c<m && c<d || c == d && c < m){
        if(c == 0){
            cout<<"You can't afford any new ships"<<endl;
        }
        else
            cout<<"You can buy "<<c<<" ships"<<endl;
    }
    else if(d<m && d<c){
        if(d == 0){
            cout<<"You can't afford any new ships"<<endl;
        }
        else
            cout<<"You can buy "<<d<<" ships"<<endl;
    }
    
    
    return 0; 
}