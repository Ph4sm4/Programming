#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include "printSTL.h"
using namespace std;

string ip, mask;

vector<int> part_mask;
list<int> p1_mask;
list<int> p2_mask;
list<int> p3_mask;
list<int> p4_mask;


vector<int> part_ip;
list<int> p1_ip;
list<int> p2_ip;
list<int> p3_ip;
list<int> p4_ip;

void enter();
void ip_to_bin();
void mask_to_bin();
void not_oper();
void net_address();
void broadcast_address();
int to_dec(int n);


int main(){

    enter();
    ip_to_bin();
    mask_to_bin();
    net_address();

    return 0;
}

void enter(){
    cout<<"Enter ip addres: ";
    cin>>ip;
    cout<<"Enter mask addres: ";
    cin>>mask;
}

void ip_to_bin(){


    for(int i = 0 ; i < 4; i++){
        part_ip.push_back(atoi(ip.substr(0, ip.find('.')).c_str()));
        ip.erase(0, ip.find('.')+1);
    }
    //printSTL(part_ip, " | ", true);
    
    vector<int> s_ip;
    for(int i = 0; i < 4; i++){
        switch(i){
            case 0:
                while(part_ip.at(i)){
                    p1_ip.push_back(part_ip.at(i) % 2);
                    part_ip.at(i) /= 2;
                }
                p1_ip.reverse();
                s_ip.push_back(p1_ip.size());
                if(s_ip.at(i) < 8){
                    for(int j = 0; j < 8 - s_ip.at(i); j++){
                        p1_ip.push_front(0);
                    }
                }
                
                break;
            case 1:
                while(part_ip.at(i)){
                    p2_ip.push_back(part_ip.at(i) % 2);
                    part_ip.at(i) /= 2;
                }
                p2_ip.reverse();
                s_ip.push_back(p2_ip.size());
                if(s_ip.at(i) < 8){
                    for(int j = 0; j < 8 - s_ip.at(i); j++){
                        p2_ip.push_front(0);
                    }
                }
                break;
            case 2:
                while(part_ip.at(i)){
                    p3_ip.push_back(part_ip.at(i) % 2);
                    part_ip.at(i) /= 2;
                }
                p3_ip.reverse();
                s_ip.push_back(p3_ip.size());
                if(s_ip.at(i) < 8){
                    for(int j = 0; j < 8 - s_ip.at(i); j++){
                        p3_ip.push_front(0);
                    }
                }
                break;
            case 3:
                while(part_ip.at(i)){
                    p4_ip.push_back(part_ip.at(i) % 2);
                    part_ip.at(i) /= 2;
                }
                p4_ip.reverse();
                s_ip.push_back(p4_ip.size());
                if(s_ip.at(i) < 8){
                    for(int j = 0; j < 8 - s_ip.at(i); j++){
                        p4_ip.push_front(0);
                    }
                }
                break;
        }
        
    }
    //printSTL(p1_ip, " ");
    //printSTL(p2_ip, " ");
    //printSTL(p3_ip, " ");
    //printSTL(p4_ip, " ");

}

void mask_to_bin(){


    for(int i = 0 ; i < 4; i++){
        part_mask.push_back(atoi(mask.substr(0, mask.find('.')).c_str()));
        mask.erase(0, mask.find('.')+1);
    }
    //printSTL(part_mask, " | ", true);
    
    vector<int> s_mask;
    for(int i = 0; i < 4; i++){
        switch(i){
            case 0:
                while(part_mask.at(i)){
                    p1_mask.push_back(part_mask.at(i) % 2);
                    part_mask.at(i) /= 2;
                }
                p1_mask.reverse();
                s_mask.push_back(p1_mask.size());
                if(s_mask.at(i) < 8){
                    for(int j = 0; j < 8 - s_mask.at(i); j++){
                        p1_mask.push_front(0);
                    }
                }
                
                break;
            case 1:
                while(part_mask.at(i)){
                    p2_mask.push_back(part_mask.at(i) % 2);
                    part_mask.at(i) /= 2;
                }
                p2_mask.reverse();
                s_mask.push_back(p2_mask.size());
                if(s_mask.at(i) < 8){
                    for(int j = 0; j < 8 - s_mask.at(i); j++){
                        p2_mask.push_front(0);
                    }
                }
                break;
            case 2:
                while(part_mask.at(i)){
                    p3_mask.push_back(part_mask.at(i) % 2);
                    part_mask.at(i) /= 2;
                }
                p3_mask.reverse();
                s_mask.push_back(p3_mask.size());
                if(s_mask.at(i) < 8){
                    for(int j = 0; j < 8 - s_mask.at(i); j++){
                        p3_mask.push_front(0);
                    }
                }
                break;
            case 3:
                while(part_mask.at(i)){
                    p4_mask.push_back(part_mask.at(i) % 2);
                    part_mask.at(i) /= 2;
                }
                p4_mask.reverse();
                s_mask.push_back(p4_mask.size());
                if(s_mask.at(i) < 8){
                    for(int j = 0; j < 8 - s_mask.at(i); j++){
                        p4_mask.push_front(0);
                    }
                }
                break;
        }
        
    }
    //printSTL(p1_mask, " ");
    //printSTL(p2_mask, " ");
    //printSTL(p3_mask, " ");
    //printSTL(p4_mask, " ");

}

void not_oper(){
    list<int>::iterator first = p1_mask.begin();
    list<int>::iterator second = p2_mask.begin();
    list<int>::iterator third = p3_mask.begin();
    list<int>::iterator forth = p4_mask.begin();
    cout<<endl<<endl;
    for(int i = 0; i < 4; i++){

        switch (i)
        {
        case 0:
            
            for(first; first != p1_mask.end(); ++first){
                if(*first == 1){
                    *first = 0;
                }
                else{
                    *first = 1;
                }
            }
            break;
        case 1:
            
            for(second; second != p2_mask.end(); ++second){
                if(*second == 1){
                    *second = 0;
                }
                else{
                    *second = 1;
                }
            }
            break;
        case 2:
            
            for(third; third != p3_mask.end(); ++third){
                if(*third == 1){
                    *third = 0;
                }
                else{
                    *third = 1;
                }
            }
            break;
        case 3:
        
            for(forth; forth != p4_mask.end(); ++forth){
                if(*forth == 1){
                    *forth = 0;
                }
                else{
                    *forth = 1;
                }
            }
            break;
        }

    }
    //printSTL(p1_mask, " ", true);
    //printSTL(p2_mask, " ", true);
    //printSTL(p3_mask, " ", true);
    //printSTL(p4_mask, " ", true);


}

void net_address(){

    list<int>::iterator first = p1_mask.begin();
    list<int>::iterator second = p2_mask.begin();
    list<int>::iterator third = p3_mask.begin();
    list<int>::iterator forth = p4_mask.begin();

    list<int>::iterator first2 = p1_ip.begin();
    list<int>::iterator second2 = p2_ip.begin();
    list<int>::iterator third2 = p3_ip.begin();
    list<int>::iterator forth2 = p4_ip.begin();
    //cout<<endl<<endl;

    for(int i = 0; i < 4; i++){

        switch (i)
        {
        case 0:
            
            for(first; first != p1_mask.end(); ++first){
                if(*first == 0){
                    *first2 = 0;
                    ++first2;
                }      
            }
            break;
        case 1:
            
            for(second; second != p2_mask.end(); ++second){
                if(*second == 0){
                    *second2 = 0;
                    ++second2;
                }          
            }
            break;
        case 2:
            
            for(third; third != p3_mask.end(); ++third){
                if(*third == 0){
                    *third2 = 0;
                    ++third2;
                }               
            }
            break;
        case 3:
        
            for(forth; forth != p4_mask.end(); ++forth){
                if(*forth == 0){
                    *forth2 = 0;
                    ++forth2;
                }
            }
            break;
        }

    }
    string p1ip, p2ip, p3ip, p4ip;
    int int_p1ip, int_p2ip, int_p3ip, int_p4ip;
    for(int i = 0; i < 4; i++){
        switch(i){
            case 0:
                for(list<int>::iterator it = p1_ip.begin(); it != p1_ip.end(); --it){
                    if(*it == 0){
                         p1_ip.pop_front();
                    }else
                        break;
                    }
                for(list<int>::iterator it = p1_ip.begin(); it != p1_ip.end(); ++it){
                    p1ip = p1ip + to_string(*it);
                    }
                int_p1ip = atoi(p1ip.c_str());
            break;
            
            case 1:
                for(list<int>::iterator it = p2_ip.begin(); it != p2_ip.end(); --it){
                    if(*it == 0){
                         p2_ip.pop_front();
                    }else
                        break;
                    }
                for(list<int>::iterator it = p2_ip.begin(); it != p2_ip.end(); ++it){
                    p2ip = p2ip + to_string(*it);
                    }
                int_p2ip = atoi(p2ip.c_str());
            break;

            case 2:
                for(list<int>::iterator it = p3_ip.begin(); it != p3_ip.end(); --it){
                    if(*it == 0){
                         p3_ip.pop_front();
                    }else
                        break;
                    }
                for(list<int>::iterator it = p3_ip.begin(); it != p3_ip.end(); ++it){
                    p3ip = p3ip + to_string(*it);
                    }
                int_p3ip = atoi(p3ip.c_str());
            break;

            case 3:
                for(list<int>::iterator it = p4_ip.begin(); it != p4_ip.end(); --it){
                    if(*it == 0){
                         p4_ip.pop_front();
                    }else
                        break;
                    }
                for(list<int>::iterator it = p4_ip.begin(); it != p4_ip.end(); ++it){
                    p4ip = p4ip + to_string(*it);
                    }
                int_p4ip = atoi(p4ip.c_str());
            break;
        }
    }
    vector<int> decip = {to_dec(int_p1ip), to_dec(int_p2ip), to_dec(int_p3ip), to_dec(int_p4ip)};
    cout<<"Net address: ";
    for(int i = 0; i < 4; i++){
        if(i == 3){
            cout<<decip.at(i); 
            break;
        }
        cout<<decip.at(i)<<".";
    }
    
}

int to_dec(int n){

    int num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}


void broadcast_address(){

    //not_oper();
    
    

}