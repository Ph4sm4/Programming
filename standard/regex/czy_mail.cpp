#include <iostream>
#include <regex>
using namespace std;

int main(){
    string mail;
    regex reg("[\\w._%-+]{1,20}\@[\\w\.\-]{2,20}\.[a-zA-Z]{2,3}");
    

    cout<<"Enter an email: ";
    cin>>mail;
    auto is_valid = [mail, reg]()->bool{

        if(regex_match(mail.begin(), mail.end(), reg)){
            return true;
        }
        else return false;
    };
    if(is_valid()){
        cout<<"VALID"<<endl;
    }
    else cout<<"NOT VALID"<<endl;

    return 0;
}