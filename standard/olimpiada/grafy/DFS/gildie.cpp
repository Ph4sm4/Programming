#include <bits/stdc++.h>
using namespace std;

vector<int> tab[200010];
int vis[200010];
//100
void DFS(int a){
    
    for(int sasiad : tab[a]){
        if(vis[sasiad] == -1){
            vis[sasiad] = vis[a]^1; //jesli na obecnym wierzcholku jest 0 to na sasiedzie ma byc 1 aby bylo na zmiane
            //wiec jesli zrobimy 0^1 to otrzymamy 1, a jesli zrobimy 1^1 to otrzymamy 0
            //jesli bedzie 0 to wyswietlamy S a jesli 1 to K
            //0000 0000 = 0
            //0000 0001 = 1
            //----------- bo XOR czyli ^ zwraca 0 jesli bity w jednej kolumnie sa takie same czyli 0,0 lub 1,1 oraz zwraca 1 jesli
            //sa rozne
            //0000 0001 = 1, wiec 0^1 = 1

            //0000 0001 = 1
            //0000 0001 = 1
            //-----------
            //0000 0000 = 0, wiec 1^1 = 0
            //
            DFS(sasiad);
        }
    }
}
void nie(){
    cout<<"NIE";
    exit(0);
}
//100
int main(){
    int n, m, a, b;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) vis[i] = -1; //dosc nietypowa tablica odwiedzonych ze wzgledu na to ze mamy rozstawiac jeszcze
    //filie, wiec wartosc -1 mowi nam o tym ze dany wierzcholek nie byl jeszcze odwiedzony
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(tab[i].empty()) nie(); //jesli dostaniemy wierzcholek bez polaczenia to znaczy ze nie mozna w tym miescie rozstawic
        //odpowiednio filii
        if(vis[i] == -1){
            vis[i] = 0; //jesli wierzcholek nie byl odwiedzony to znaczy ze jest to nowy cykl i graf nie jest spojny
            //wiec wchodzac ustawiamy wartosc na 0 co znaczy ze w tym wierzcholku ma byc filia szwaczek (S)
            //a potem dfs bedzie rozstawial na zmiane odpowiednie filie
            DFS(i);
        }
    }
    cout<<"TAK\n";
    for(int i = 1; i <= n; i++) cout<<(vis[i]? "K\n" : "S\n");
    

    return 0;
}