#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct point
{
    int x, y;

    point(int x, int y) : x(x), y(y) {}
};

const int N = 10;
int grid[N][N];
int cost[N][N];
queue<point> q;
vector<point> dir =
{
    point(0, 1),
    point(1, 0),
    point(0, -1),
    point(-1, 0)
};


int main()
{
    int T = 5;
    while (T--)
    {
        memset(cost, INF, sizeof(cost));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char a; cin >> a;
                grid[i][j] = a - '0';
            }
        }

        string line;
        cin >> line;

        for (int i = 0; i < N; ++i) {
            cost[i][0] = 0;
            q.push(point(i, 0));
        }

        while (!q.empty()) {
            point cur = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                point next = point(cur.x + dir[i].x, cur.y + dir[i].y);

                if (0 <= next.x && next.x < 10 &&
                    0 <= next.y && next.y < 10 &&
                    abs(grid[next.x][next.y] - grid[cur.x][cur.y]) < 2 &&
                    cost[next.x][next.y] > cost[cur.x][cur.y] + 1) {

                    cost[next.x][next.y] = cost[cur.x][cur.y] + 1;
                    q.push(next);
                }
            }
        }

        int best = INF;
        for (int i = 0; i < N; ++i) best = min(best, cost[i][N - 1]);
        cout << (best == INF ? "IMPOSSIBLE" : to_string(best)) << endl;
    }
}
