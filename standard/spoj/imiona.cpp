#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include "printSTL.h"
#include <utility>
#include <vector>
#include <map>
using namespace std;

int main(){

    cout<<"Podaj liczbe studentow: ";
    int liczba_studentow;
    cin>>liczba_studentow;

    multiset<string, less<string>> studenci;
    set<string, less<string>> temp;

    for(int i = 0; i < liczba_studentow; i++){
        string name, num, surname;
        cin>>num>>surname>>name;
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        studenci.insert(name);
        temp.insert(name);
    }

    map<string, int> tab;
    set<string>::iterator it = temp.begin();

    for(int i = 0; i < temp.size(); i++){
        tab.insert(pair<string, int>(*it, studenci.count(*it)));        
        it++;
    }

    auto lambda = [](pair<string, int>& a, pair<string, int>&b)->bool{
        return a.second > b.second;
    };
    auto my_sort = [lambda](map<string, int >& M){
        vector<pair<string, int>> A;
        for(auto& it : M){
            A.push_back(it);
        }
        sort(A.begin(), A.end(), lambda);

        for(auto& it : A){
            cout<<it.first<<" "<<it.second<<endl;
        }

    };
    
    my_sort(tab);
    
    return 0;
}