#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    srand(time(NULL));

    const int n = 10;
    queue<int> q;
    vector<int> v;

    for(int i = 0; i < n; i++) v.push_back(rand()%19 - 10);

    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [&q](int a){q.push(a);});
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}