#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 2005;
typedef pair<int, int> pii;

int d[MAXN][MAXN];
pii moves[4] =
{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
queue<pii> q;
int N, M, K;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(d, INF, sizeof(d));

    cin >> N >> M >> K;

    int x, y;
    while (K--)
    {
        cin >> x >> y;
        q.push({x, y});
        d[x][y] = 0;
    }

    while (!q.empty())
    {
        pii c = q.front(); q.pop();

        for (pii m : moves)
        {
            int nx = c.first + m.first, ny = c.second + m.second;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && d[c.first][c.second] + 1 < d[nx][ny])
            {
                d[nx][ny] = d[c.first][c.second] + 1;
                q.push({nx, ny});
            }
        }
    }

    pii ans;
    int best = -1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (d[i][j] > best)
            {
                best = d[i][j];
                ans = {i, j};
            }
        }
    }

    cout << ans.first << " " << ans.second << endl;
}
