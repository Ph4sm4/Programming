#include <bits/stdc++.h>
#define ll long long
using namespace std;

//70
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;

    vector<int> v(n);
    vector<int> pref(n + 1);
    pref[0] = 0;
    int suma = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        suma += v[i];
        pref[i + 1] = suma;
    }
    ll min = 9999999999999999;
    for(int i = 0; i <= n - k; i++){
        if(min > pref[i + k] - pref[i]) min = pref[i + k] - pref[i]; 
    }
    cout<<(min == 9999999999999999? 0 : min);

    return 0;
}

/*

std::ios_base::sync_with_stdio(0);
    int input_count, interval;
    long long ans = LLONG_MAX;
    std::cin>>input_count>>interval;
    for(int i = 1; i <= input_count; i++) {
        std::cin>>num[i];
        }
        pref[0] = 0;
    for(int i = 1; i <= input_count; i++) {
        pref[i] = pref[i - 1] + num[i];
        }
        for(int i = 1; i <= input_count - interval + 1; i++) {
           ans = std::min(pref[i + interval - 1] - pref[i - 1], ans);
        }
        std::cout<<ans;
*/