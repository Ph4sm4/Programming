#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(){

    vector<int> gwozdzie;
    int z = 0;
    while(z < 5){
        int temp;
        cin>>temp;
        gwozdzie.push_back(temp);
        z++;
    }
    int x = 5;
    int left = 0, right = gwozdzie.size()-1;
    while(left < right){
        if(gwozdzie.at(left) + gwozdzie.at(right) < x) left++;
        else if(gwozdzie.at(left) + gwozdzie.at(right) > x) right--;
        else break;
    }
    cout<<left<<" "<<right<<endl;


    return 0;
}