#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct point
{
    int x, y;

    point(int x, int y) : x(x), y(y) {}
};

const int MAXN = 505;
int grid[MAXN][MAXN];
int cost[MAXN][MAXN];
queue<point> q;
int N, M;

int main()
{
    memset(cost, INF, sizeof(cost));
    memset(grid, INF, sizeof(grid));

    cin >> N >> M;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    cost[0][0] = grid[0][0];
    q.push(point(0, 0));
    while (!q.empty()) {
        point cur = q.front(); q.pop();

        if (cost[cur.x][cur.y] + grid[cur.x + 1][cur.y] < cost[cur.x + 1][cur.y]){
            cost[cur.x + 1][cur.y] = cost[cur.x][cur.y] + grid[cur.x + 1][cur.y];
            q.push(point(cur.x + 1, cur.y));
        }

        if (cost[cur.x][cur.y] + grid[cur.x][cur.y + 1] < cost[cur.x][cur.y + 1]){
            cost[cur.x][cur.y + 1] = cost[cur.x][cur.y] + grid[cur.x][cur.y + 1];
            q.push(point(cur.x, cur.y + 1));
        }
    }

    cout << cost[N - 1][M - 1] << endl;
}
