#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
    point(){}
    point(int len, int h) : x(len), y(h) {}
    friend ostream & operator<< (ostream &wyjscie, const point &p);
};

ostream &operator<<(ostream &wyjscie, const point &p){
        return wyjscie<<p.x<<" "<<p.y<<'\n';
}

vector<point> tab[100][100];
bool vis[100][100];

void nope(){
    cout<<"no valid way";
    exit(0);
}

void DFS(point p, point end_val){
    vis[p.x][p.y] = true;

    for(auto sasiad : tab[p.x][p.y]){
        if(!vis[sasiad.x][sasiad.y]){
            DFS(sasiad, end_val);
        }
    }
}

int main(){

    ifstream plik;
    plik.open("labirynt.txt");
    string temp;
    point end_cord = {0,0};
    point start_cord;
    bool startline = false;
    while(getline(plik, temp)){
        for(string::iterator it = temp.begin(); it != temp.end(); it++){
            if(*it == 'W') {
                end_cord.x = distance(temp.begin(), it);
                if(!startline) {
                    start_cord.x = distance(temp.begin(), it);
                    startline = true;
                }
                break;
            }
        }
        end_cord.y++;
    }
    //drzwi naprzeciwko mojego pokoju, czesci sa na rozowym talerzu
    //przesuwne drzwi u iwa
    //przesuwne drzwi u laury
    plik.close();
    end_cord.y--;
    cout<<start_cord;
    cout<<end_cord;

    plik.open("labirynt.txt");
    string linia;
    int len = 0, height = 0;
    while(getline(plik, linia)){
        for(string::iterator it = linia.begin(); it != linia.end(); it++){
            if(*it == 'W'){
                tab[len][height].push_back(point(len, height));
                tab[height][len].push_back(point(len, height));
            }
            len++;
        }
        height++;
    }
    plik.close();

    DFS(start_cord, end_cord);

    if(vis[end_cord.x][end_cord.y]) cout<<"TAK";
    else nope();

    return 0;
}