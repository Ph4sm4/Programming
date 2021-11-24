#include <iostream>
#include <future>
#include <thread>
#include <ctime>
#include <windows.h>
using namespace std;

void loop(){
    //cout<<"loop: "<<this_thread::get_id()<<endl;
    for(int i = 5; i < 100; i++){
        cout<<i<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    //cout<<endl<<"KONIEC LOOP"<<endl;
}
void loop2(){
    //cout<<"loop2: "<<this_thread::get_id()<<endl;
    for(int i = 0; i < 100; i++){
        cout<<i<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    //cout<<endl<<"KONIEC LOOP2!"<<endl;
}

int main(){
    srand(time(NULL));
    //cout<<"watek glowny: "<<this_thread::get_id()<<endl;
    //this_thread::sleep_until(chrono::steady_clock::now() + chrono::seconds(2));
    
    std::future<void> result1(std::async(launch::async,loop));
    cout<<endl;
    std::future<void> result2(std::async(launch::async, loop2));
    
    while(result2.valid()){
        Sleep(1000);
        system("cls");
    }

    return 0;
}