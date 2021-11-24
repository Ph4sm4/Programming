#include <bits/stdc++.h>
using namespace std;

void buildArr(string s, vector<int> &c){
    int j = 0, i = 1;
    c[0] = 0;
    while(i < s.length()){
        if(s[i] == s[j]){
            c[i] = j + 1;
            i++;
            j++;
        }else{
            if(j != 0){
                j = c[j - 1];
            }else{
                c[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string s, string patt, vector<int> c){
        int i=0;
        int j=0;
        int curr = 0;
        while(i < s.length()){
            if(s[i] == patt[j]){
                curr++;
                i++;
                j++;
            }else{
                if(j != 0){
                    j = c[j-1];
                }else{
                    i++;
                    curr++;
                }
            }
            if(curr == patt.length()){
                cout<<i - j + 1<<endl;
                j = c[j-1];
                curr = 0;
            }
        }
}

int main(){

    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    string patt, s;
    vector<int> prebuilt(n);
    cin>>patt>>s;
    buildArr(patt, prebuilt);

    KMP(s, patt, prebuilt);

    return 0;
}