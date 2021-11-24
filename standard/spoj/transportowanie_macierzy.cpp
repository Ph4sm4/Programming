#include <iostream>
using namespace std;

int main(){

    int row, col;
    cin>>row>>col;
    int tab[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin>>tab[i][j];
        }
    }
    int track = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            cout<<tab[j][track]<<" ";
        }
        cout<<endl;
        track++;
    }

    return 0;
}