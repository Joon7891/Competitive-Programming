#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define MEM(a, b) memset(a, b, sizeof(a))
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
int n, h;
const int MAXN = 1500;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool solve()
{
    queue<pii > q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        pii current = q.front(); q.pop();
        int y = current.f, x = current.s;
        int e = grid[y][x];

        if (y == n - 1 && x == n - 1)
        {
            return true;
        }

        if (abs(e - grid[y + 1][x]) <= h && !visited[y + 1][x])
        {
            q.push({y + 1, x});
            visited[y + 1][x] = true;
        }

        if (abs(e - grid[y][x + 1]) <= h && !visited[y][x + 1])
        {
            q.push({y, x + 1});
            visited[y][x + 1] = true;
        }
    }

    return false;
}

int main()
{
    MEM(visited, false);
    cin >> n >> h;

    forn(i, n)
    {
        forn(j, n)
        {
            cin >> grid[i][j];
        }
    }

    if (solve())
    {
        cout << "yes" << endl;
    }
    else
        cout << "no" << endl;
}