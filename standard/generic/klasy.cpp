#include <iostream>
using namespace std;

template<typename T>
class Test{
    T x, y;
public:
    Test(T a, T b): x(a), y(b){
        cout<<x + b<<endl;
    }
};

template<>
class Test<string>{ //osobne przeciazenie dla typu string, tak mozna okreslic dzialanie dla jakiegos specyficznego typu danych
    string x, y;
public:
    Test(string a, string b): x(a), y(b){
        cout<<x + "jestem" +  b<<endl;
    }
};

int main(){

    Test<float> obj(1.0f, 2.5f);
    Test<string> obj1("Ol", "af");
    Test<int> obj2(1, 5);

    return 0;
}