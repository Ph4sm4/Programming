#include <bits/stdc++.h>
using namespace std;

int64_t fastexp(int64_t _base, int64_t _exp, int64_t _mod) {
int64_t _res = 1, _mult = _base;
while(_exp > 0) {
  if (_exp % 2) {
    _res *= _mult;
    _res %= _mod;
  }
  _mult *= _mult;
  _mult %= _mod;
  _exp /= 2;
}
return _res;
}

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int k;
    cin>>k;
    cout<<6 * fastexp(4, pow(2, k) - 2, (long long)(10e9+7));


    return 0;
}