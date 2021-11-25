#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 20;
int tab[2*base];
//100
void update(int _start, int _end){
    _start += base;
    _end += base;
    if(_start == _end){
        tab[_start]++;
        return;
    }
    tab[_start]++;
    tab[_end]++;
    while(_start/2 != _end/2){
        if(_start % 2 == 0) tab[_start + 1]++;
        if(_end % 2 == 1) tab[_end - 1]++;
        _start /= 2;
        _end /= 2;
    }
}

int query(int _ind){
    _ind += base;
    int res = 0;
    while(_ind > 0){
        res += tab[_ind];
        _ind /= 2;
    }
    return res;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    string x;
    cin>>x;
    for(int i = 1; i <= x.length(); i++){
        if(x[i-1] == 'o'){
            update(i,i);
        }
    }
    for(int i = 0; i < q; i++){
        char z;
        cin>>z;
        if(z == 'Q'){
            int temp;
            cin>>temp;
            int val = query(temp);
            cout<<(val%2 == 0? "OFF\n" : "ON\n");
        }else{
            int a, b;
            cin>>a>>b;
            update(a, b);
        }
    }

    return 0;
}