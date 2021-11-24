#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <string>
#include "printSTL.h"
using namespace std;

char menu_choose;
vector<string> usersNameShow;
vector<string> usersSurnameShow;
vector<string> usersPhoneShow;
vector<string> usersMailShow;

void menu_input();
void add_tel_record();
void show_records();
void modify_records();

int main(){
    
    menu_input();

    return 0;
}


void menu_input(){
    cout<<"WELCOME TO THE TELEPHONE DIRECTORY SYSTEM!"<<endl;
    cout<<"------Choose one of the options below------"<<endl;
    cout<<"1. Add telephone record"<<endl;
    cout<<"2. Show telephone records"<<endl;
    cout<<"3. Modify records"<<endl;
    cout<<"4. Search for a phone record"<<endl;
    cout<<"5. Delete record"<<endl;
    cout<<"6. Exit program"<<endl;
    cin>>menu_choose;

    switch(menu_choose){
        case '1': add_tel_record(); break;
        case '2': show_records(); break;
        case '3': modify_records(); break;

        default: cout<<"No such an option"<<endl; break;
    }
}

void add_tel_record(){
    system("cls");

    vector<string> usersName;
    vector<string> usersSurname;
    vector<string> usersPhone;
    vector<string> usersMail;
    list<string> show = {"Enter users name: ", "Enter users surname: ", "Enter users phone number: ", "Enter users email addres: "};

    list<string>::iterator listit;
    
    int keep_track = 0;
    for(listit = show.begin(); listit != show.end(); ++listit){

        cout<<*listit;
        if(string enter; keep_track == 0){
            cin>>enter;
            usersName.push_back(enter);
            keep_track++;
        }
        else if(string enter; keep_track == 1){
            cin>>enter;
            usersSurname.push_back(enter);
            keep_track++;
        }
        else if(string enter; keep_track == 2){
            cin>>enter;
            usersPhone.push_back(enter);
            keep_track++;
        }
        else if(string enter; keep_track == 3){
            cin>>enter;
            usersMail.push_back(enter);
           
        }
    }
    keep_track = 0;

    string current_file_num;
    fstream filenames("filenumbers.txt");

    vector<int> filenum;
    filenum.reserve(100);

    while(getline(filenames, current_file_num)){
        filenum.push_back(atoi(current_file_num.c_str())+1);
    }
    printSTL(filenum, " ", true);

    filenames.close();
    
    ofstream ofilenames("filenumbers.txt");
    ofilenames<<to_string(filenum.back());
        
    ofilenames.close();

    ofstream addfile;
    addfile.open("usersinfo" + to_string(filenum.back()) + ".txt");
    
    addfile<<usersName.back()<<endl;
    addfile<<usersSurname.back()<<endl;
    addfile<<usersPhone.back()<<endl;
    addfile<<usersMail.back()<<endl;

    addfile.close();

    fstream alltogether;
    alltogether.open("alltogether.txt", ios::out | ios::app);
    alltogether<<usersName.back()<<endl;
    alltogether<<usersSurname.back()<<endl;
    alltogether<<usersPhone.back()<<endl;
    alltogether<<usersMail.back()<<endl;
    alltogether.close();
}

void show_records(){
    system("cls");


    ifstream ifile("alltogether.txt");
    string line;    
    unsigned int line_number = 1;
    unsigned int users_number = 0;

    while(getline(ifile, line)){
        
        switch(line_number){
            case 1: usersNameShow.push_back(line); break;
            case 2: usersSurnameShow.push_back(line); break;
            case 3: usersPhoneShow.push_back(line); break;
            case 4: usersMailShow.push_back(line); break;
        }
        if(line_number == 4){
            line_number = 0;
            users_number++;
        }
        line_number++;
    }
        
    system("cls");
    for(int i = 0; i<users_number; i++){
        cout<<"User number: "<<i+1<<endl;
        cout<<"Name: "<<usersNameShow.at(i)<<endl;
        cout<<"Surname: "<<usersSurnameShow.at(i)<<endl;
        cout<<"Phone number: "<<usersPhoneShow.at(i)<<endl;
        cout<<"E-mail: "<<usersMailShow.at(i)<<endl;
        cout<<"--------------"<<endl;

    }


}

void modify_records(){
    unsigned int users_number = 0;
    unsigned int modify_number;
    unsigned int line_number = 1;
    string line;
    fstream ifile; 
    ifile.open("alltogether.txt");

    if(ifile.peek() == ifstream::traits_type::eof()){
        cout<<"Directory is empty"<<endl;
        exit(0);
    }
    ifile.close();

    show_records();
    cout<<"Choose which record you want to modify: ";
    cin>>modify_number;

    fstream tempfile; 
    tempfile.open("alltogether.txt");

    while(getline(tempfile, line)){
        
        if(line_number == 4){
            line_number = 0;
            users_number++;
        }
        line_number++;
    }
    tempfile.close();

    if(modify_number > users_number || modify_number < 1){
        cout<<"Error there is no such a record!"<<endl;
        exit(0);
    }

    fstream file;
    file.open("usersinfo" + to_string(modify_number) + ".txt", ios::in | ios::out);
    string newname, newsurname, newphone, newmail;
    string currname, currsurname, currphone, currmail;

    cout<<"User number: "<<modify_number<<endl;
    cout<<"New name(type no - not to change anything): ";
    cin>>newname;

    if(newname == "no"){
        newname = usersNameShow.at(modify_number-1);
    }

    cout<<"New surname(type no - not to change anything): ";
    cin>>newsurname;
    if(newsurname == "no"){
        newsurname = usersSurnameShow.at(modify_number-1);
    }

    cout<<"New phone number(type no - not to change anything): ";
    cin>>newphone;
    if(newphone == "no"){
        newphone = usersPhoneShow.at(modify_number-1);
    }

    cout<<"New newmail(type no - not to change anything): ";
    cin>>newmail;
    if(newmail == "no"){
        newmail = usersMailShow.at(modify_number-1);
    }
    line_number = 1;
    
    file<<newname<<endl;
    file<<newsurname<<endl;
    file<<newphone<<endl;
    file<<newmail<<endl;
            
    file.close();

    
}