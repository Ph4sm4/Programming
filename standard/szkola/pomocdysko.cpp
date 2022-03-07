#include <bits/stdc++.h>
using namespace std;

const int N = 1 < 10;
vector<int> tab[N];
bool vis[N];
queue<int> q;
int dist[N];

void DFS(int a)
{
    vis[a] = true;

    for (auto sasiad : tab[a])
    {
        if (!vis[sasiad])
        {
            DFS(sasiad);
        }
    }
}

void BFS(int a)
{
    vis[a] = true;
    dist[a] = 0;
    q.push(a);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (auto sasiad : tab[f])
        {
            if (!vis[sasiad])
            {
                dist[sasiad] = dist[f] + 1;
                vis[sasiad] = true;
                q.push(sasiad);
            }
        }
    }
}

struct kraw
{
    int id;
    int waga;
};

vector<kraw> v[500010];
long long dist[500010];
const long long inf = LONG_LONG_MAX;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int x)
{

    for (int i = 0; i < 500010; i++)
    {
        dist[i] = inf;
    }

    dist[x] = 0;
    pq.push({0, x}); // waga , numer wierzcholka

    while (!pq.empty())
    {
        int id, d;
        id = pq.top().second; // numer wierzcholka
        d = pq.top().first;   // waga

        pq.pop();

        if (dist[id] < d)
        {
            continue;
        }

        for (auto kraw : v[id])
        {
            if (dist[id] + kraw.waga < dist[kraw.id])
            {
                dist[kraw.id] = dist[id] + kraw.waga;
                pq.push({dist[kraw.id], kraw.id});
            }
        }
    }
}

int main()
{
    int wierzcholki, krawedzie;
    // fstream plik;
    // plik.open("dysko.txt");

    cin >> wierzcholki >> krawedzie;

    for (int i = 0; i < krawedzie; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b);
    }

    /*
    wczytanie dla dijkstry

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        // v[b].push_back({a, c});
    }
    */

    BFS(0);

    for (int i = 0; i < wierzcholki; i++)
    {
        cout << i << ". " << dist[i] << '\n';
    }

    // plik.close();

    return 0;
}