#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define MEM(a, b) memset(a, (b), sizeof(a))
#define INF 0x3f3f3f3f

using namespace std;

struct point
{
    int y, x;

    point(int y, int x) : y(y), x(x) {}
};

const int MAX = 1000;
char grid[MAX][MAX];
bool endpoint[MAX][MAX];
int d[MAX][MAX];
int r, c;

bool valid(int y, int x)
{
    return -1 < y && y < r && -1 < x && x < c && grid[y][x] == 'O';
}

int solve(point start)
{
    queue<point> q;
    q.push(start);

    MEM(d, -1);

    d[start.y][start.x] = 0;

    while (!q.empty())
    {
        point current = q.front(); q.pop();
        int y = current.y;
        int x = current.x;

        if (endpoint[y][x])
        {
            return d[y][x];
        }

        if (valid(y - 1, x) && (d[y - 1][x] == -1 || d[y][x] + 1 < d[y - 1][x]))
        {
            d[y - 1][x] = d[y][x] + 1;
            q.push(point(y - 1, x));
        }

        if (valid(y + 1, x) && (d[y + 1][x] == -1 || d[y][x] + 1 < d[y + 1][x]))
        {
            d[y + 1][x] = d[y][x] + 1;
            q.push(point(y + 1, x));
        }

        if (valid(y, x - 1) && (d[y][x - 1] == -1 || d[y][x] + 1 < d[y][x - 1]))
        {
            d[y][x - 1] = d[y][x] + 1;
            q.push(point(y, x - 1));
        }

        if (valid(y, x + 1) && (d[y][x + 1] == -1 || d[y][x] + 1 < d[y][x + 1]))
        {
            d[y][x + 1] = d[y][x] + 1;
            q.push(point(y, x + 1));
        }
    }
}

int get(point start, point office)
{
    queue<point> q;
    q.push(start);

    MEM(d, -1);

    d[start.y][start.x] = 0;

    while (!q.empty())
    {
        point current = q.front(); q.pop();
        int y = current.y;
        int x = current.x;

        if (y == office.y && x == office.x)
        {
            return d[y][x];
        }

        if (valid(y - 1, x) && (d[y - 1][x] == -1 || d[y][x] + 1 < d[y - 1][x]))
        {
            d[y - 1][x] = d[y][x] + 1;
            q.push(point(y - 1, x));
        }

        if (valid(y + 1, x) && (d[y + 1][x] == -1 || d[y][x] + 1 < d[y + 1][x]))
        {
            d[y + 1][x] = d[y][x] + 1;
            q.push(point(y + 1, x));
        }

        if (valid(y, x - 1) && (d[y][x - 1] == -1 || d[y][x] + 1 < d[y][x - 1]))
        {
            d[y][x - 1] = d[y][x] + 1;
            q.push(point(y, x - 1));
        }

        if (valid(y, x + 1) && (d[y][x + 1] == -1 || d[y][x] + 1 < d[y][x + 1]))
        {
            d[y][x + 1] = d[y][x] + 1;
            q.push(point(y, x + 1));
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    MEM(d, -1);

    cin >> r >> c;

    int y, x;
    cin >> y >> x;
    point start = point(y, x);

    cin >> y >> x;
    point office = point(y, x);

    string buffer;
    forn(i, r)
    {
        cin >> buffer;

        forn(j, c)
        {
            grid[i][j] = buffer[j];
        }
    }

    int t;
    cin >> t;

    MEM(endpoint, false);
    forn(i, t)
    {
        cin >> y >> x;
        endpoint[y][x] = true;
    }

    cout << get(start, office) - solve(start) << endl;
}
