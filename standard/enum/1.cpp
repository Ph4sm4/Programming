#include <iostream>
#include <string>
using namespace std;

enum Err_Type{
    CONN_ERR = 4,
    UNKNOWN_ERR = 6,
    RAM_ERR,
};

int main(){

    Err_Type error1;

    cout<<"Podaj blad : ";
    string ans;
    getline(cin, ans);

    if(ans == "CONN_ERR") error1 = CONN_ERR;
    else if(ans == "UNKNOWN_ERR") error1 = UNKNOWN_ERR;
    else error1 = Err_Type(5);

    cout<<error1<<endl;

    return 0;
}