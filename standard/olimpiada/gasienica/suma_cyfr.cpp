#include <bits/stdc++.h>
using namespace std;

int main(){

    int l_cyfr, l_zmien;
    cin>>l_cyfr>>l_zmien;
    vector<int> v;
    for(int i = 0; i < l_cyfr; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int suma = 0;
    sort(v.begin(), v.end(), [](int a, int b){return a < b;});
    for_each(v.begin(), v.begin()+l_zmien, [](int &a){a=9;});
    for_each(v.begin(), v.end(), [&suma](const int a){suma += a;});
    cout<<suma<<'\n';

    return 0;
}