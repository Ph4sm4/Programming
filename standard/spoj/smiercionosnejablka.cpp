#include <bits/stdc++.h>
using namespace std;

struct Citizen{
    int height;
    int age;
    int grow;
};

bool check(int x, const Citizen &citizen, int v){
    if(abs(x - citizen.height)/1000 < v) return true;
    else return false;
}

int main(){

    int l, n, m;
    cin>>l;
    vector<int> ans(21);
    for(int i = 0; i < 21; i++) ans[i] = 999999;
    for(int i = 0; i < l; i++){  
        cin>>n>>m;
        for(int j = 0; j < m; j++){
            Citizen citizen;
            cin>>citizen.height>>citizen.age>>citizen.grow;
            int temp_tree_height = 0;
            for(int g = 0; g < 21; g++){
                while(check(temp_tree_height, citizen, n)){
                    temp_tree_height++;
                }
                cout<<temp_tree_height<<endl;
                if(citizen.age <= 20) citizen.height += citizen.grow;
                citizen.age++;
                if(ans[i] > temp_tree_height) ans[i] = temp_tree_height;
            }
        }
    }
    for(int i = 0; i < 21; i++){
        cout<<i<<": "<<ans.at(i)<<endl;
    }


    return 0;   
}