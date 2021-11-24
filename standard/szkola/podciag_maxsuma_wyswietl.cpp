#include <bits/stdc++.h>
using namespace std;

int main(){

    srand(time(NULL));
    const int n = 5;
    int mxl = 0, mxr = 0;
    vector<int> v(n);

    for(int i = 0; i < n; i++) v[i] = rand()%100-50;
    v[rand()%n] = rand()%50;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    int prawy = 0, mx = -99999999, suma = 0;
    bool cnt = false;

    while(prawy < n){
        if(suma >= 0){
            if(!cnt){
                cnt = true;
                mxl = prawy;
            }
            suma += v[prawy++];
            if(mx < suma){
                mx = suma;
                mxr = prawy;
            }
        }
        else{
            suma = 0;
            cnt = false;
        }
    }

    cout<<endl<<mx<<endl;
    for(int i = mxl; i < mxr; i++) cout<<v[i]<<" ";


    return 0;
}