#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){//58 czas i odp

    int n;
    cin>>n;
    vector<pair<int, int>> minim;
    v.resize(n + 1);
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }
    int suma = 0;
    
    int current_min = INT_MAX;
    for(int i = n; i > 0; i--){
        if(current_min > v[i]) {
            current_min = v[i];
            minim.push_back(make_pair(current_min, i));
        }
    }
    int poz = 0;
    for_each(minim.rbegin(), minim.rend(), [&suma, &poz](auto x){
        suma += x.first * (x.second - poz);
        poz = x.second;
    });
    
    cout<<suma;


    return 0;
}

