#include <iostream>
#include <queue>
#include <math.h>
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
    if (a->F != b->F)
        return a->F > b->F; // we are always going to choose the node which has the lowest F cost

    return a->H > b->H; // if the F cost is the same, then we wanna choose the node which has the lowest H cost
};

priority_queue<node *, vector<node *>, decltype(compare)> q(compare);

void showGrid(int xStart, int yStart, int xEnd, int yEnd)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            node cell = grid[i][j];

            if (cell.x == xStart && cell.y == yStart)
                cout << "S ";
            else if (cell.x == xEnd && cell.y == yEnd)
                cout << "E ";
            else if (cell.isPartOfShortestPath)
                cout << "P ";
            else if (cell.obstacle)
                cout << "O ";
            else
                cout << "X ";
        }
        cout << endl;
    }
}

bool findInQueue(node *value)
{
    auto tempQueue = q;
    while (!tempQueue.empty())
    {
        if (tempQueue.top()->x == value->x && tempQueue.top()->y == value->y)
        {
            return true;
        }
        tempQueue.pop();
    }
    return false;
}

void calculateNeighbourValues(node *current, node *neighbour)
{
    const int gCandidate = sqrt((current->x - neighbour->x) * (current->x - neighbour->x) + (current->y - neighbour->y) * (current->y - neighbour->y)) * 10 + current->G;
    if (neighbour->G > gCandidate || !findInQueue(neighbour))
    {
        neighbour->G = gCandidate;
        neighbour->parent = current;
        neighbour->F = neighbour->G + neighbour->H;
    }
}

vector<node *> getNeighbours(node *current)
{
    vector<node *> out;
    if (current->x - 1 > 0)
    { // left neighbour
        node *neighbour = &grid[current->x - 1][current->y];

        out.push_back(neighbour);
    }
    if (current->x + 1 < N)
    {
        // right neighbour
        node *neighbour = &grid[current->x + 1][current->y];

        out.push_back(neighbour);
    }
    if (current->y + 1 < N)
    {
        // bottom neighbour
        node *neighbour = &grid[current->x][current->y + 1];

        out.push_back(neighbour);
    }
    if (current->y - 1 > 0)
    {
        // top neighbour
        node *neighbour = &grid[current->x][current->y - 1];

        out.push_back(neighbour);
    }
    if (current->x - 1 > 0 && current->y - 1 > 0)
    {
        // top left neighbour
        node *neighbour = &grid[current->x - 1][current->y - 1];

        out.push_back(neighbour);
    }
    if (current->x + 1 < N && current->y - 1 > 0)
    {
        // top right neighbour
        node *neighbour = &grid[current->x + 1][current->y - 1];

        out.push_back(neighbour);
    }
    if (current->x - 1 > 0 && current->y + 1 < N)
    {
        // bottom left neighbour
        node *neighbour = &grid[current->x - 1][current->y + 1];

        out.push_back(neighbour);
    }
    if (current->x + 1 < N && current->y + 1 < N)
    {
        // bottom right neighbour
        node *neighbour = &grid[current->x + 1][current->y + 1];

        out.push_back(neighbour);
    }

    return out;
}

int main()
{
    int xStart, yStart, xEnd, yEnd;
    cout << "Enter start node cords [x, y]: ";
    cin >> xStart >> yStart;

    cout << "Enter end node cords [x, y]: ";
    cin >> xEnd >> yEnd;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            node cell = grid[i][j];
            cell.x = j;
            cell.y = i;
            cell.obstacle = false;
            cell.visited = false;
            cell.G = INF;
            int dx = abs(cell.x - xEnd);
            int dy = abs(cell.y - yEnd);
            int d2 = sqrt(2) * 10;
            cell.H = (dx + dy) + (d2 - 2) * min(dx, dy);
            grid[i][j] = cell;
        }
    }

    grid[xStart][yStart].G = 0;
    q.push(&grid[xStart][yStart]);

    while (!q.empty())
    {
        node *current = q.top();
        current->visited = true;
        cout << current->F << endl;
        q.pop();

        if (current->x == xEnd && current->y == yEnd)
            break;

        vector<node *> neighbours = getNeighbours(current);
        for (node *neighbour : neighbours)
        {
            if (neighbour->visited)
                continue;

            calculateNeighbourValues(current, neighbour);
            if (!findInQueue(neighbour))
                q.push(neighbour);
        }
    }
    cout << endl;
    queue<node *> parents;
    parents.push(&grid[xEnd][yEnd]);
    while (!parents.empty())
    {
        node *current = parents.front();
        cout << current->x << " " << current->y << endl;
        current->isPartOfShortestPath = true;
        parents.pop();

        if (current->parent)
            parents.push(current->parent);
    }

    showGrid(xStart, yStart, xEnd, yEnd);

    return 0;
}

/*

*/