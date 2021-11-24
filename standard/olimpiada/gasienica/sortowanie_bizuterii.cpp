#include <bits/stdc++.h>
using namespace std;

int main(){

    int ilosc;
    cin>>ilosc;
    vector<string> lancuchy;
    for(int i = 0; i < ilosc; i++){
        string temp;
        cin>>temp;
        lancuchy.push_back(temp);
    }
    auto lambda = [](string a, string b){
        if(a.length() < b.length()) return true; 
        else if(a.length() == b.length()){
            return a < b;
        }
        else return false;
    };
    sort(lancuchy.begin(), lancuchy.end(), lambda);
    copy(lancuchy.begin(), lancuchy.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}