#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct Point
{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

const int MAXN = 45;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
Point loc[6] = {
    Point(0, 0),
    Point(0, 0),
    Point(0, 0),
    Point(0, 0),
    Point(0, 0),
    Point(0, 0)
};
int R, C;

int flood(Point a) {
    queue<Point> q; q.push(a);
    vis[a.x][a.y] = 1;

    int counter = 0;
    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        counter++;

        if (cur.x + 1 < R && grid[cur.x + 1][cur.y] == '.'
            && !vis[cur.x + 1][cur.y])
        {
            vis[cur.x + 1][cur.y] = 1;
            q.push(Point(cur.x + 1, cur.y));
        }

        if (cur.y + 1 < C && grid[cur.x][cur.y + 1] == '.'
        && !vis[cur.x][cur.y + 1])
        {
            vis[cur.x][cur.y + 1] = 1;
            q.push(Point(cur.x, cur.y + 1));
        }

        if (0 <= cur.x - 1 && grid[cur.x - 1][cur.y] == '.'
            && !vis[cur.x - 1][cur.y])
        {
            vis[cur.x - 1][cur.y] = 1;
            q.push(Point(cur.x - 1, cur.y));
        }

        if (0 <= cur.y - 1 && grid[cur.x][cur.y - 1] == '.'
            && !vis[cur.x][cur.y - 1])
        {
            vis[cur.x][cur.y - 1] = 1;
            q.push(Point(cur.x, cur.y - 1));
        }
    }

    return counter;
}

int main()
{
    memset(vis, 0, sizeof(vis));

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        string line; cin >> line;

        for (int j = 0; j < C; ++j) {
            grid[i][j] = line[j];

            if (grid[i][j] == '1' ||
                grid[i][j] == '2' ||
                grid[i][j] == '3' ||
                grid[i][j] == '4' ||
                grid[i][j] == '5') {

                loc[grid[i][j] - '0'] = Point(i, j);
            }
        }
    }

    for (int i = 1; i <= 5; ++i) {
        cout << flood(loc[i]) << endl;
    }
}
