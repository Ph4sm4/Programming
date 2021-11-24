#include <iostream>
#include <ctime>
#define sr srand(time(NULL));
using namespace std;

void makeHeap(int *tab, int s, int root){
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if(left < s && tab[left] > tab[root]) largest = left;
    if(right < s && tab[right] > tab[largest]) largest = right;
    if(largest != root){
        swap(tab[largest], tab[root]);
        for(int i = 0; i < s; i++) cout<<tab[i]<<" ";
        cout<<endl;
        makeHeap(tab, s, largest);
    }
}

int main(){
    sr
    const int n = 4;
    int *tab = new int [n];
    for(int i = 0; i < n; i++) tab[i] = rand()%100;
    for(int i = 0; i < n; i++) cout<<tab[i]<<" ";
    cout<<endl<<endl;

    for(int i = n/2-1; i >= 0; i--){
        makeHeap(tab, n, i);
    }
    
    for(int i = 0; i < n; i++) cout<<tab[i]<<" ";

    return 0;
}