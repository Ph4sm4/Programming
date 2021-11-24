#include <iostream>
#include <memory>
using namespace std;

int main(){

    auto lambda = [](auto x, auto y){ return x + y; };

    cout<<lambda(1,2)<<endl;
    cout<<lambda(string("ol"), string("af"))<<endl;

    return 0;
}