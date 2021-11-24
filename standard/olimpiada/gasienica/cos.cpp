#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int liczba_cyfr, n, x, suma = 0;
    cin>>liczba_cyfr>>n;
    vector<int> v;
    vector<int> v2;
    bool br = false;

    for(int i = 0; i < liczba_cyfr; i++){
        cin>>x;
        v.push_back(x);
    }
    copy(v.begin(), v.end(), back_inserter(v2));
    int ct = 0;
    for(int i = 0; i < n; i++){
        int min = v.at(0);
        for(int j = 0; j < v.size(); j++){
            int temp_min = v.at(j);
            if(min > temp_min) min = temp_min;
        }
        for(int j = 0; j < v2.size(); j++){
            if(ct == n){
                br = true;
                break;
            }
            if(v2.at(j) == min){
                v2[j] = 9;
                ct++;
            }
        }
        if(br) break;
        

        v.erase(remove(v.begin(), v.end(), min), v.end());
    }
    for(int i = 0; i < v2.size(); i++) suma += v2.at(i);
    cout<<suma<<endl;

    return 0;
}
