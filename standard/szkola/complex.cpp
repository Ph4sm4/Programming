#include <bits/stdc++.h>
using namespace std;

int main(){
    //srand(time(0));
    vector<vector<vector<int>>> v;

    for(int i = 0; i < 3; i++){
        vector<vector<int>> temp2;
        for(int j = 0; j < 3; j++){
            vector<int> temp1;
            for(int h = 0; h < 10; h++){
                temp1.push_back(rand()%10);
            }
            temp2.push_back(temp1);
        }
        v.push_back(temp2);
    }
    for_each(v.crbegin(), v.crend(), [](const vector<vector<int>> a){
        for_each(a.crbegin(), a.crend(), [](const vector<int> b){
            copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
            cout<<endl;
        });
        cout<<endl;
    });

    
    return 0;
}