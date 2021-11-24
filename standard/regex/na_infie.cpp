#include <iostream>
#include <regex>
using namespace std;

int main(){

    cout<<"Podaj napis: ";
    string str;
    getline(cin, str);
    regex reg("(^\\s+)|($\\s+)");
    string cleared_side = regex_replace(str, reg, "");
    regex reg2 ("(\\s+)");
    string cleared_all = regex_replace(cleared_side, reg2, " ");
    cout<<cleared_all<<endl;


    return 0;
}