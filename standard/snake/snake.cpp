#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

bool gameOver;

const int width = 20;
const int height = 20;

int tailX[100];
int tailY[100];

int lTail;
int x, y, fruitX, fruitY, score, highest_score;
int ans1, ans2;

enum eDirection {STOP = 0, RIGHT, LEFT, UP, DOWN};
eDirection dir;

void setup();
void draw();
void input();
void logic();
void highestscore();
void gamemode();
void difficulty();


int main(){
        gamemode();
        difficulty();

        setup();
    while(!gameOver){
        draw();
        input();
        logic();
        if(ans2 == 1){
            Sleep(200);
        }
        else if(ans2 == 2){
            Sleep(100);
        }
        else if(ans2 == 3){

        }
    }
    highestscore();

    cout<<endl<<endl<<"Thanks for playing! "<<endl;
    cout<<"Your score: "<<score<<endl;
    cout<<"Your highest score: "<<highest_score<<endl;
    getch();getch();

return 0;}

void gamemode(){
        cout<<"Choose gamemode: "<<endl;
        cout<<"1. Walls kill you"<<endl;
        cout<<"2. No walls"<<endl;
        cin>>ans1;
        if(ans1 == 1 || ans1 == 2){

        }
        else{
            cout<<"This is not an option! ";
            getch();
            system("cls");
            gamemode();
        }
}

void difficulty(){
    system("cls");
    cout<<"Choose difficulty: "<<endl;
    cout<<"1. 0,25 speed"<<endl;
    cout<<"2. 0,50 speed"<<endl;
    cout<<"3. 1,00 speed"<<endl;
    cin>>ans2;

    if(ans2 == 1 || ans2 == 2 || ans2 == 3){

    }
    else{
        cout<<"This is not an option! ";
        getch();
        system("cls");
        difficulty();
    }
}
void setup(){

    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;

}

void draw(){
    system("cls");
    //drawing the map
    for(int i = 0; i<width+2; i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){

            if(j == 0)
                cout<<"#";
            //drawing head of the snake
            if(i == y && j == x)
                cout<<"O";
            else if(i == fruitY && j == fruitX)
                cout<<"@";
            else{
                bool print = false;
                for(int k = 0; k< lTail; k++){

                    if(tailX[k] == j && tailY[k] == i){
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print){
                    cout<<" ";
                }

            }

            if(j == width-1){
                cout<<"#";
            }

        }
        cout<<endl;
    }
    for(int i = height+2; i>0; i--){
        cout<<"#";
    }

    cout<<endl<<"Score: "<<score<<endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w': dir = UP;     break;
            case 'd': dir = RIGHT;  break;
            case 's': dir = DOWN;   break;
            case 'a': dir = LEFT;   break;
            case 27: gameOver = true; break;
        }
    }

}

void logic(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i = 1; i < lTail; i++){

        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){

        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;

    }
    if(ans1 == 2){
      if(x >= width){
        x = 0;
      }
    else if(x < 0){
       x = width-1;
    }
    if(y >= height){
       y = 0;
    }
    else if(y < 0){
      y = height-1;
    }
    }
    else{
        if(x > width || x < 0 || y > height || y < 0){
            gameOver = true;
        }
    }

    for(int i = 0; i < lTail; i++){
        if(tailX[i] == x && tailY[i] == y){
            gameOver = true;
        }
    }

    if(x == fruitX && y == fruitY){
        lTail++;
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
    }
}

void highestscore(){

    ofstream file;
    file.open("highest_score.txt", ios::out | ios::app);
    file.close();

    ifstream ifile;
    ifile.open("highest_score.txt", ios::in);
    ifile>>highest_score;
    ifile.close();

    if(highest_score < score){
        file.open("highest_score.txt", ios::out);
        file<<score;
        file.close();
        highest_score = score;
    }



}
