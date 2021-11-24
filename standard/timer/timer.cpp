#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    int hours = 0;
    int minutes = 0;
    int sec = 0;
    unsigned int k = 1;

    while(true){
        if(k == 16) k = 1;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, k | FOREGROUND_INTENSITY);
  
        system("cls");
        if(sec == 60){
            sec = 0;
            minutes++;
        }
        if(minutes == 60){
            minutes = 0;
            hours++;
        }
        if(hours < 10) cout<<'0'<<hours;
        else cout<<hours;
        if(minutes < 10) cout<<":0"<<minutes;
        else cout<<':'<<minutes;
        if(sec < 10) cout<<":0"<<sec;
        else cout<<':'<<sec;
            
        Sleep(1000);
        sec++; 
        k++;
    }

    return 0;
}