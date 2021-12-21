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
        return wyjscie<<p.y<<" "<<p.x<<'\n';
}

vector<point> points;
vector<point> tab[100][100];
bool vis[100][100];

void nope(){
    cout<<"VALID PATH DOES NOT EXIST";
    exit(0);
}

void yes(){
    cout<<"VALID PATH EXISTS";
    exit(0);
}

void DFS(point a, point end){
    vis[a.x][a.y] = true;

    for(auto sasiad : tab[a.x][a.y]){
        if(!vis[sasiad.x][sasiad.y]){
            DFS(sasiad, end);
        }
    }
}

int main(){

    ifstream plik;
    plik.open("labirynt.txt");
    string temp;
    point end_cord = {0,0};
    point start_cord = {0,0};
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
    plik.close();

    end_cord.y--;
    cout<<start_cord;
    cout<<end_cord;
    cout<<endl;
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
    }
    plik.close();
    
    //nie dziala bo sciezka moze tez isc od prawej do lewej
    //i wtedy sie wysypuje, sprobowalbym moze jednak zrobic graf ze wszystkich punktow
    //tej sciezki i po nim DFSa, w teorii zadziala, ale trzeba dobrze graf zaprezentowac
    copy(points.begin(), points.end(), ostream_iterator<point>(cout, ""));

    for(int i = 0; i < points.size() - 1; i++){
        point a1 = points.at(i);
        for(int j = i + 1; j < points.size(); j++){
            if(abs(points.at(j).x + points.at(j).y - a1.x - a1.y) == 1){
                tab[a1.x][a1.y].push_back(points.at(j));
                tab[points.at(j).x][points.at(j).y].push_back(a1);
                break;
            }
        }
    }
    cout<<"size: "<<points.size();

    DFS(start_cord, end_cord);

    if(vis[end_cord.x][end_cord.y]) yes();
    else nope();
   
    return 0;
}