#include <bits/stdc++.h>
using namespace std;

int main(){

    srand(time(NULL));
    const int x = 10;
    int n;
    cin>>n;
    int cnt = 0;

    vector<int> v(x);
    //for_each(v.begin(), v.end(), [](int &a){a = rand()%10;});
    //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    for(int i = 0; i < x; i++) v[i] = rand()%10;
    for(int i = 0; i < x; i++) cout<<v[i]<<" ";
    cout<<endl;
    v.push_back(0);

    int lewy = 0, prawy = 0, suma = 0, dist = 1;
    while(lewy <= v.size() && prawy <= v.size()){      
        if(suma <= n){
            if(suma == n){
                cnt++;
                suma = 0;
                lewy = prawy;
                dist = 0;
                //cout<<"equaled ";
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
    cout<<endl<<cnt;


    return 0;
}

