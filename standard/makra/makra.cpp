#include <iostream>
using namespace std;
#define LOG(x) cout<<x<<endl;

namespace color{
    string red = "red";
    string blue = "blue";
    string black = "black";
}

enum Level{

    Error, Warning, Info

};

int main(){

    LOG("Hello");
    cout<<color::red<<endl;

    Level level = Error;
    cout<<level<<endl;

    return 0;
}