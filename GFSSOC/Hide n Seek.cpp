#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAX = 20;
char grid[MAX][MAX];
int distances[10][10];
int n, m, t;

struct point
{
    int y, x;

    point(int y, int x) : y(y), x(x) {}
};

point get_start()
{
    forn(i, n)
    {
        forn(j, m)
        {
            if (grid[i][j] == 'G')
            {
                return point(i, j);
            }
        }
    }
}

vector<point> get_hiders()
{
    vector<point> hiders;

    forn(i, n)
    {
        forn(j, m)
        {
            if (grid[i][j] == 'H')
            {
                hiders.push_back(point(i, j));
            }
        }
    }

    return hiders;
}

bool valid(int y, int x)
{
    return -1 < y && y < n && -1 < x && x < m && grid[y][x] != 'X';
}

int bfs(point a, point b)
{
    queue<point> q; q.push(a);
    int d[MAX][MAX];
    memset(d, -1, sizeof(d));

    d[a.y][a.x] = 0;

    while (!q.empty())
    {
        point current = q.front(); q.pop();
        int y = current.y;
        int x = current.x;

        if (y == b.y && x == b.x)
        {
            return d[y][x];
        }

        if (valid(y - 1, x) && d[y - 1][x] == -1)
        {
            d[y - 1][x] = d[y][x] + 1;
            q.push(point(y - 1, x));
        }

        if (valid(y + 1, x) && d[y + 1][x] == -1)
        {
            d[y + 1][x] = d[y][x] + 1;
            q.push(point(y + 1, x));
        }

        if (valid(y, x - 1) && d[y][x - 1] == -1)
        {
            d[y][x - 1] = d[y][x] + 1;
            q.push(point(y, x - 1));
        }

        if (valid(y, x + 1) && d[y][x + 1] == -1)
        {
            d[y][x + 1] = d[y][x] + 1;
            q.push(point(y, x + 1));
        }
    }

    return -1;
}

bool included[10];

int solve(int currentIndex)
{
    int best = INF;

    forn(i, t + 1)
    {
        if (i == currentIndex || included[i]) continue;
        included[i] = true;
        best = min(best, distances[currentIndex][i] + solve(i));
        included[i] = false;
    }

    if (best == INF)
    {
        return 0;
    }

    //cout << currentIndex << " " << best << endl;
    return best;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    string buffer;

    forn(i, n)
    {
        cin >> buffer;

        forn(j, m)
        {
            grid[i][j] = buffer[j];
        }
    }

    point start = get_start();
    vector<point> points = get_hiders();
    points.push_back(start);

    forn(i, t + 1)
    {
        forn(j, i)
        {
            int d = bfs(points[i], points[j]);
            distances[i][j] = d;
            distances[j][i] = d;
        }
    }

    memset(included, false, sizeof(included));
    included[t] = true;
    cout << solve(t) << endl;
}