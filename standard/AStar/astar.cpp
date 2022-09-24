#include <iostream>
#include <set>
#include <math.h>
#include <fstream>
#include <list>
using namespace std;

const int INF = INT_MAX;

struct node
{
    int H; // distance from end node (heuristic)
    int G; // distance from start node
    int F; // G + H
    bool obstacle;
    int x;
    int y;
    bool visited;
    node *parent;
    bool isPartOfShortestPath = false;
};

const int N = 10;
node grid[N][N];

auto compare = [](node *a, node *b)
{
    // if (a->F != b->F)
    return a->F > b->F; // we are always going to choose the node which has the lowest F cost

    // return a->H > b->H; // if the F cost is the same, then we wanna choose the node which has the lowest H cost
};

set<node *, decltype(compare)> s(compare);

void prepareGrid(node &start, node &end);
void showGrid(node start, node end);
int getHeuristic(node *current, node end);
set<node *> getNeighbours(node *current);

int main()
{
    node start, end;
    prepareGrid(start, end);

    start.G = 0;
    start.H = getHeuristic(&start, end);
    start.F = start.G + start.H;
    s.insert(&start);

    while (!s.empty())
    {
        node *current = *s.begin();
        current->visited = true;
        s.erase(current);

        if (current->x == end.x && current->y == end.y)
            break;

        set<node *> neighbours = getNeighbours(current);
        for (auto it = neighbours.begin(); it != neighbours.end(); it++)
        {
            node *neighbour = *it;
            if (neighbour->obstacle || neighbour->visited)
                continue;

            const int gCandidate = sqrt((current->x - neighbour->x) * (current->x - neighbour->x) + (current->y - neighbour->y) * (current->y - neighbour->y)) * 10 + current->G;
            if (neighbour->G > gCandidate || s.find(neighbour) == s.end())
            {
                neighbour->H = getHeuristic(neighbour, end);
                neighbour->G = gCandidate;
                neighbour->F = neighbour->G + neighbour->H;
                neighbour->parent = current;
                if (s.find(neighbour) == s.end())
                    s.insert(neighbour);
            }
        }
    }

    list<node *> parents;
    parents.push_back(&end);
    while (!parents.empty())
    {
        node *current = parents.front();
        parents.pop_back();
        cout << current->x << " " << current->y << endl;

        current->isPartOfShortestPath = true;
        if (current->parent)
            parents.push_back(current->parent);
    }

    showGrid(start, end);

    return 0;
}

void prepareGrid(node &start, node &end)
{
    fstream file;
    file.open("grid.txt", ios::in);
    string line;
    int i = 0;
    while (getline(file, line))
    {
        for (int j = 0; j < line.length(); j++)
        {
            node *current = &grid[i][j];
            current->x = j;
            current->y = i;
            current->G = INF;
            if (line[j] == 'S')
            {
                start.x = j;
                start.y = i;
            }
            else if (line[j] == 'E')
            {
                end.x = j;
                end.y = i;
            }
            else if (line[j] == 'O')
            {
                current->obstacle = true;
            }
        }
        i++;
    }

    file.close();
}

void showGrid(node start, node end)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (start.x == j && start.y == i)
                cout << "S ";
            else if (end.x == j && end.y == i)
                cout << "E ";
            else if (grid[i][j].isPartOfShortestPath)
                cout << "P ";
            else
                cout << "X ";
        }
        cout << endl;
    }
}

int getHeuristic(node *current, node end)
{
    int D2 = sqrt(2) * 10; // diagonal distance between nodes
    int D = 1;             // length of the node, in terms of grid is 1
    int dx = abs(current->x - end.x);
    int dy = abs(current->y - end.y);

    return D * (dx + dy) + (D2 - 2 * D) * min(dx, dy);
}

set<node *> getNeighbours(node *current)
{
    set<node *> out;
    if (current->x - 1 > 0)
    { // left neighbour
        node *neighbour = &grid[current->x - 1][current->y];

        out.insert(neighbour);
    }
    if (current->x + 1 < N)
    {
        // right neighbour
        node *neighbour = &grid[current->x + 1][current->y];

        out.insert(neighbour);
    }
    if (current->y + 1 < N)
    {
        // bottom neighbour
        node *neighbour = &grid[current->x][current->y + 1];

        out.insert(neighbour);
    }
    if (current->y - 1 > 0)
    {
        // top neighbour
        node *neighbour = &grid[current->x][current->y - 1];

        out.insert(neighbour);
    }
    if (current->x - 1 > 0 && current->y - 1 > 0)
    {
        // top left neighbour
        node *neighbour = &grid[current->x - 1][current->y - 1];

        out.insert(neighbour);
    }
    if (current->x + 1 < N && current->y - 1 > 0)
    {
        // top right neighbour
        node *neighbour = &grid[current->x + 1][current->y - 1];

        out.insert(neighbour);
    }
    if (current->x - 1 > 0 && current->y + 1 < N)
    {
        // bottom left neighbour
        node *neighbour = &grid[current->x - 1][current->y + 1];

        out.insert(neighbour);
    }
    if (current->x + 1 < N && current->y + 1 < N)
    {
        // bottom right neighbour
        node *neighbour = &grid[current->x + 1][current->y + 1];

        out.insert(neighbour);
    }

    return out;
}