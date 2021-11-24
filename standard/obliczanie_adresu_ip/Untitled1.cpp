#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

string usersip[4], usersmask[4], usersip_bin_number[4], usersmask_bin_number[4];
int usersip_int[4], usersmask_int[4];

void usersip_bin();
void usersmask_bin();
void calculate();

void users_ip_bin0();
void users_ip_bin1();
void users_ip_bin2();
void users_ip_bin3();

void users_mask_bin0();
void users_mask_bin1();
void users_mask_bin2();
void users_mask_bin3();

void check_bin0();
void check_bin1();
void check_bin2();
void check_bin3();

int main(){

    calculate();

return 0;}

void calculate(){

    usersip_bin();
    usersmask_bin();
}
void users_ip_bin0(){
    int g=0,tab[31];

    usersip_int[0] = stoi(usersip[0]);

    while(usersip_int[0])
    {
        tab[g++]=usersip_int[0]%2;
        usersip_int[0]/=2;
    }
    for(int j=g-1;j>=0;j--){
        cout<<tab[j];
    }
    cout<<endl;

}

void usersip_bin(){

    for(int i = 0; i<4; i++){
        cout<<"Enter "<<i+1<<" ip number: ";
        getline(cin, usersip[i]);
    }
    users_ip_bin0();
    //users_ip_bin1();
    //users_ip_bin2();
    //users_ip_bin3();
}


void usersmask_bin(){
    for(int i = 0; i<4; i++){
        cout<<"Enter "<<i+1<<" number of mask: ";
        getline(cin, usersmask[i]);
    }

    users_mask_bin0();
    //users_mask_bin1();
    //users_mask_bin2();
    //users_mask_bin3();
}

void users_mask_bin0(){
    int g=0,tab[31];

    usersmask_int[0] = stoi(usersmask[0]);

    while(usersmask_int[0])
    {
        tab[g++]=usersmask_int[0]%2;
        usersmask_int[0]/=2;
    }
    for(int j=g-1;j>=0;j--){
        cout<<tab[j];
        for(int i = 0; i<100; i++)
            usersip_bin_number[i] = tab[j];
        }
    cout<<usersip_bin_number[0];
    cout<<endl;

}

void check_bin0(){


}

void check_bin1(){

}

void check_bin2(){

}

void check_bin3(){

}

