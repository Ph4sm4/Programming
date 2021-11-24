#include <bits/stdc++.h>
using namespace std;

int64_t fastexp(int64_t _base, int64_t _exp, int64_t _mod) {
    if(_base == 0) return 0;
    if(_exp == 0) return 1;
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
//95 potem jakby wywala poza long longa 
int main(){

    int64_t a, b, m;
    cin>>a>>b>>m;
    cout<<fastexp(a, b, m);

    return 0;
}