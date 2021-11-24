#include <bits/stdc++.h>
using namespace std;
//65
int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k, b, d;
    cin>>n>>k>>b>>d;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];

    int l = 0, r = 0, sum = 0, mxsum = 0, first = 0, last = 0, smallest = 999999999;
    int ct = 0;
    while(l < n && r < n){
        if(v[r] % k == 0){
            sum += v[r];
            if(mxsum <= sum) {
                mxsum = sum;
                first = l;
                last = r;
            }
            r++;
        }
        else if(v[r] % k != 0 && ct < b){
            ct++;
            sum += v[r];
            if(mxsum <= sum) {
                mxsum = sum;
                first = l;
                last = r;
            }
            r++;
        }
        else if(v[r] % k != 0 && ct == b){
            sum -= v[l];
            if(v[l] % k != 0) ct--;
            l++;
        }
    }
    last++;
    if(last - first == 0) cout<<"NIE";
    else{
        cout<<last - first<<'\n';
        cout<<fixed<<setprecision(d)<<float(mxsum)/float((last-first))<<'\n';
        copy(v.begin() + first, v.begin() + last, ostream_iterator<int>(cout, " ")); 
    }

    return 0;
}