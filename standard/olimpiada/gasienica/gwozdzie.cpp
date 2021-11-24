#include <bits/stdc++.h>
using namespace std;

int main(){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int lgw, maxuderz;
    cin>>lgw>>maxuderz;
    vector<int> gwozdzie;
    for(int i = 0; i < lgw; i++){
        int tmp; 
        cin>>tmp;
        gwozdzie.push_back(tmp);
    }
    int x = 5;
    int left = 0, right = gwozdzie.size()-1;
    while(left < right){
        if(gwozdzie.at(left) + gwozdzie.at(right) < x) left++;
        else if(gwozdzie.at(left) + gwozdzie.at(right) > x) right--;
        else break;
    }
    cout<<left<<" "<<right<<endl;


    return 0;
}