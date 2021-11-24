#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){

    srand(time(0));
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = rand()%10; 
    for(int i : v) cout<<i<<" ";

    int mx = 0, dl = 1;
    for(int i = 1; i < n; i++){
        if(v[i-1] <= v[i]){
            dl++;
            if(mx < dl) mx = dl;
        }
        else dl = 1;
    }
    cout<<endl<<mx;

    return 0;
}