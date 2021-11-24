#include <bits/stdc++.h>
using namespace std;

int main(){


    int l;
    cin>>l;
    int temp = l - 1;
    int antiPrime;
    int max = 0;
    while(temp){
        int max_temp = 0;
        for(int i = 2; i < 10; i++){
            if(temp % i == 0) max_temp++;
        }
        if(max < max_temp){
            max = max_temp;
            antiPrime = temp;
            if(max == 8) break;
        }
        temp--;
    }
    cout<<antiPrime;

    return 0;
}