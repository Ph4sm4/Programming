#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 17;
int tab[2*base]; //values
int tab2[2*base]; //how many are divisible
//25 czas
void add(int _ind, int _val){
    _ind += base;
    tab[_ind] += _val;
    _ind /= 2;
    while(_ind > 0){
        tab[_ind] = tab[2*_ind] + tab[2*_ind + 1];
        _ind /= 2;
    }
}

void setup(int _ind, int _mod){
    _ind += base;
    tab2[_ind] = (tab[_ind]%_mod == 0? 1 : 0);
    _ind /= 2;
    while(_ind > 0){
        tab2[_ind] = tab2[2*_ind] + tab2[2*_ind + 1];
        _ind /= 2;
    }
}

int query(int _start, int _end, int _mod){
    int res = 0;
    _start = _start + base - 1;
    _end = _end + base + 1;
    for(int i = 0; i < base; i++){
        setup(i, _mod);
    }
    while(_start/2 != _end/2){
        if(_start % 2 == 0) res += tab2[_start + 1];
        if(_end % 2 == 1) res += tab2[_end-1];
        _start /= 2;
        _end /= 2;
    }
    return res;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    for(int i = 0; i < q; i++){
        string x;
        cin>>x;
        if(x == "DODAJ"){
            int a, b;
            cin>>a>>b;
            add(a, b);
        }else{
            int a,b,c;
            cin>>a>>b>>c;
            cout<<query(a,b,c)<<'\n';
        }
    }


    return 0;
}