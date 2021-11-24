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


    return 0;
}