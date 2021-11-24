#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll x, ll n){
    if(x <= sqrt(n)) return false;
    return true;
}

ll lb(ll n) {
  ll l = 0, r = LLONG_MAX, s;
  
  while(l < r){
      s = (l + r)/2;
      if(check(s, n)){
          r = s;
      }else{
          l = s + 1;
      }
  }
  return l;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    ll n;
    cin>>n;

    cout<<lb(n);

    return 0;
}