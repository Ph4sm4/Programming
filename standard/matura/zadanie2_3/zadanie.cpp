#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream plik;
    plik.open("dane2_3.txt");
    string linia;
    
    while(getline(plik, linia)){
        int count = 0, max = 0;
        for(int i = 0; i < linia.length(); i++){
            if(linia[i] == '[') count++;
            else count = 0;
            if(max < count) max = count;
        }
        cout<<max<<endl;
    }
    

    plik.close();

    return 0;
}