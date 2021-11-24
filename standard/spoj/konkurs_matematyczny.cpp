#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include "printSTL.h"
using namespace std;

int main(){

    cout<<"Zestawy: ";
    int zestawy;
    cin>>zestawy;
    vector<list<int>> wyniki;
    for(int i = 0; i < zestawy; i++){
        int uczestnicy, max = 0;
        cout<<"Liczba uczestnikow: ";
        cin>>uczestnicy;
        list<int> temp;
        multiset<int, less<int>> temp_set;
        for(int j = 0; j < uczestnicy; j++){
            int pkt;
            cin>>pkt;
            if(max < pkt) max = pkt;
            temp_set.insert(pkt);
        }
        int c = count(temp_set.begin(), temp_set.end(), max);
        temp_set.erase(max);
        copy(temp_set.begin(), temp_set.end(), back_inserter(temp));
        for(int j = 0; j < c; j++){
            temp.push_front(max);
        }
        wyniki.push_back(temp);
    }
    for(auto it = wyniki.begin(); it != wyniki.end(); it++){
        printSTL(*it, " ");
    }
    // for(int i = 0; i < wyniki.size(); i++){
    //     auto it = wyniki.at(i).begin();
    //     for(int j = 0; j < wyniki.at(i).size(); j++){
    //         cout<<*it<<" ";
    //         it++;
    //     }
    //     cout<<endl;
    // }

    return 0;
}