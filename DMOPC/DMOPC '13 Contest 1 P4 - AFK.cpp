#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define MEM(a, b) memset(a, (b), sizeof(a))
#define INF 0x3f3f3f3f

using namespace std;
const int MAX = 50;
char grid[MAX][MAX];
int d[MAX][MAX];
int l, w;

struct point
{
    int y, x;
    point(int y, int x) : y(y), x(x) {}
};

point get_start()
{
    forn(i, w)
    {
        forn(j, l)
        {
            if (grid[i][j] == 'C')
            {
                return point(i, j);
            }
        }
    }
}

point get_end()
{
    forn(i, w)
    {
        forn(j, l)
        {
            if (grid[i][j] == 'W')
            {
                return point(i, j);
            }
        }
    }
}

bool valid(int y, int x)
{
    return -1 < y && y < w && -1 < x && x < l && grid[y][x] != 'X' && d[y][x] == -1;
}

int bfs(point a, point b)
{
    queue<point> q;
    q.push(a);
    d[a.y][a.x] = 0;

    while (!q.empty())
    {
        point current = q.front(); q.pop();
        int y = current.y;
        int x = current.x;

        if (d[y][x] >= 60)
        {
            return -1;
        }

        if (y == b.y && x == b.x)
        {
            return d[y][x];
        }

        if (valid(y - 1, x))
        {
            d[y - 1][x] = d[y][x] + 1;
            q.push(point(y - 1, x));
        }

        if (valid(y + 1, x))
        {
            d[y + 1][x] = d[y][x] + 1;
            q.push(point(y + 1, x));
        }

        if (valid(y, x - 1))
        {
            d[y][x - 1] = d[y][x] + 1;
            q.push(point(y, x - 1));
        }

        if (valid(y, x + 1))
        {
            d[y][x + 1] = d[y][x] + 1;
            q.push(point(y, x + 1));
        }
    }

    return -1;
}

void solve()
{
    MEM(d, -1);
    cin >> l >> w; // Flip (l, w) -> (w, l)

    string buffer;
    forn(i, w)
    {
        cin >> buffer;

        forn(j, l)
        {
            grid[i][j] = buffer[j];
        }
    }

    point start = get_start();
    point wash = get_end();

    int final_d = bfs(start, wash);

    if (final_d == -1)
    {
        cout << "#notworth" << endl;
    }
    else
    {
        cout << final_d << endl;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}