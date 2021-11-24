#include <bits/stdc++.h>
using namespace std;

int main(){

    srand(time(NULL));
    const int x = 10;
    int n;
    cin>>n;
    int cnt = 0;
    vector<pair<int,int>> ans;
    vector<int> v = {1, 2, 5, 1, 2, 4, -1, 6, 7, 1, 1, 1, 3};
    //for_each(v.begin(), v.end(), [](int &a){a = rand()%10;});
    //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    //for(int i = 0; i < x; i++) v[i] = rand()%10;
    for(int i = 0; i < x; i++) cout<<v[i]<<" ";
    v.push_back(0);

    int lewy = 0, prawy = 0, suma = 0, dist = 1;
    int first, last;
    bool continous = false;
    while(lewy <= v.size() && prawy <= v.size()){      
        if(suma <= n){
            if(!continous){
                first = lewy;
                continous = true;
            }
            if(suma == n){
                cnt++;
                suma = 0;
                lewy = prawy;
                dist = 0;
                //cout<<"equaled ";
                last = prawy;
                ans.push_back(make_pair(first, last));
                continous = false;
            }
            //cout<<"normal add ";
            suma += v[prawy++];
            dist++;
        }
        else{
            if(dist > 1){
                //cout<<"deleted ";
                suma -= v[lewy++];
                dist--;
            }
            else if(dist == 1){
                //cout<<"2nd add ";
                suma += v[prawy++];
                dist++;
            }     
        }
        //cout<<lewy<<" "<<prawy<<" "<<suma<<endl;
    }
    cout<<endl<<cnt<<endl;
    //for_each(ans.begin(), ans.end(), [v](pair<int, int> p){for(int i = p.first; i < p.second; i++) cout<<v[i]<<" "; cout<<endl;});
    for(int i = 0; i < ans.size(); i++){
        for(int j = ans[i].first; j < ans[i].second; j++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

