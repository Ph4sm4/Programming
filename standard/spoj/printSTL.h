#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <deque>
#include <set>
#include <array>
using namespace std;

template <typename T>
//list, vector, deque, array, set, multiset
void printSTL (T const& containerName, string sep = "", bool s = false){

    typename T::const_iterator pos;
    typename T::const_iterator end = containerName.end();

    for(pos = containerName.begin(); pos != end; ++pos){
            cout<<*pos<<sep;
    }
    if(s){
        cout<<" "<<"[elements: "<<containerName.size()<<"]"<<endl; 
    }
    cout<<endl;
}

template <typename T>
//pair
void printPair ( T const& pairName, string sep = ""){

    cout<<pairName.first<<sep<<pairName.second<<endl;

}
