#include <bits/stdc++.h>
#include <Windows.h>
#include <cstdio>
using namespace std;

struct point{
    int x;
    int y;
    point(){}
    point(int len, int h) : x(len), y(h) {}
    friend ostream & operator<< (ostream &wyjscie, const point &p);
};

vector<point> points;
vector<point> tab[100][100];
bool vis[100][100]; //for DFS

//=====================================================================================================

int dist[100][100];
bool vis2[100][100];
queue<point> q;
const int INF = 1 << 20; //for BFS

//=====================================================================================================

void display();
void BFS(const point _start);
void DFS(const point a, const point end);
void yes(const point _start, const point _end);
void nope(const point _start, const point _end);

int main(){
    ifstream plik;
    display();

//=====================================================================================================
    plik.open("labirynt.txt");
    string temp;
    point end_cord = {0,0};
    point start_cord = {0,0};
    bool startline = false;
//=====================================================================================================
    bool found_entry = true;
    int entry_count = 0;
    getline(plik, temp);
    for(string::iterator it = temp.begin(); it != temp.end(); it++){
        if(*it == 'W'){
            start_cord.x = distance(temp.begin(), it);
            break;
        }
        if(entry_count == temp.length()-1){
            found_entry = false;
        }
        entry_count++;
    }//otrzymanie wspolrzednych punktu wejscia, jesli istnieje
    if(!found_entry){
        cout<<"ENTRY POINT NOT FOUND";
        exit(0);
    }
//=====================================================================================================
    bool exit_point_found = true;
    while(getline(plik, temp)){
        bool temp_exit = false;
        for(string::iterator it = temp.begin(); it != temp.end(); it++){
            if(*it == 'W') {
                end_cord.x = distance(temp.begin(), it);
                temp_exit = true;
                break;
            }
        }
        if(!temp_exit) exit_point_found = false;
        else exit_point_found = true;
        end_cord.y++;
    }//otrzymanie wspolrzednych punktu wyjscia, jesli istnieje
    
    plik.close();

    if(!exit_point_found){
        cout<<"EXIT POINT NOT FOUND";
        exit(0);
    }
//=====================================================================================================
    end_cord.y--;
    plik.open("labirynt.txt");

    string linia;
    int len = 0, hg = 0;
    while(getline(plik, linia)){
        for(string::const_iterator it = linia.begin(); it != linia.end(); it++){
            if(*it == 'W'){
                points.push_back(point(len, hg));
            }
            len++;
        }
        len = 0;
        hg++;
    }//wczytywanie punktow sciezek
    plik.close();
//=====================================================================================================
    for(int i = 0; i < points.size() - 1; i++){
        point a1 = points.at(i);
        for(int j = i + 1; j < points.size(); j++){
            point a2 = points.at(j);
            if(((a1.x == a2.x) && (abs(a1.y-a2.y) == 1)) || ((a1.y == a2.y) && (abs(a1.x-a2.x) == 1))){
                tab[a1.x][a1.y].push_back(a2);
                tab[a2.x][a2.y].push_back(a1);
            }
        }
    }//wczytywanie grafu
//=====================================================================================================
    DFS(start_cord, end_cord);
    BFS(start_cord);

    if(vis[end_cord.x][end_cord.y]) yes(start_cord, end_cord);
    else nope(start_cord, end_cord);
   
    return 0;
}

//=====================================================================================================

ostream &operator<<(ostream &wyjscie, const point &p){
        return wyjscie<<p.x+1<<","<<p.y+1;
}

//=====================================================================================================

void nope(const point _start, const point _end){
    cout<<"VALID PATH FROM ("<<_start<<") TO ("<<_end<<") DOES NOT EXIST";
    exit(0);
}

//=====================================================================================================

void yes(const point _start, const point _end){
    cout<<"VALID PATH FROM ("<<_start<<") TO ("<<_end<<") EXISTS\n";
    cout<<"SHORTEST PATH LENGTH: "<<dist[_end.x][_end.y] + 2;
    //entry point distance is 0, exit point is not getting involved
    exit(0);
}

//=====================================================================================================

void DFS(const point a, const point end){
    vis[a.x][a.y] = true;

    for(auto sasiad : tab[a.x][a.y]){
        if(!vis[sasiad.x][sasiad.y]){
            DFS(sasiad, end);
        }
    }
}
//=====================================================================================================

void display(){
    ifstream plik;
    plik.open("labirynt.txt");
    string disp;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD changed = BACKGROUND_RED | BACKGROUND_INTENSITY;
    WORD normal = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
    
    while(getline(plik, disp)){
        for(auto e : disp){
            if(e == 'X'){    
                cout<<'X';
            }
            else{
                SetConsoleTextAttribute(handle, changed);
                cout<<' ';
            }
            SetConsoleTextAttribute(handle, normal);
        }
        
        cout<<'\n';
    }
    plik.close();
}

//=====================================================================================================

void BFS(const point _start){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            dist[i][j] = INF;
        }
    }
    vis2[_start.x][_start.y] = true;
    dist[_start.x][_start.y] = 0;
    q.push(_start);
    while(!q.empty()){
        point a = q.front();
        q.pop();
        for(auto sasiad : tab[a.x][a.y]){
            if(!vis2[sasiad.x][sasiad.y]){
                vis2[sasiad.x][sasiad.y] = true;
                dist[sasiad.x][sasiad.y] = dist[a.x][a.y] + 1;
                q.push(sasiad);
            }
        }

    }

}

//=====================================================================================================