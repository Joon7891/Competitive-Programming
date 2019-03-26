#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f

const int MAXN = 15;
int grid[MAXN][MAXN];
int cut[MAXN][MAXN];
int d[MAXN][MAXN];

std::pair<int, int> moves[4] =
{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

int main()
{
    memset(d, INF, sizeof(d));

    int R, C;
    std::cin >> R >> C;

    char line;
    std::pair<int, int> start;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            std::cin >> line;

            if (line == '.')
            {
                grid[i][j] = 0;
            }
            else if (line == 'X')
            {
                start = {i, j};
            }
            else
            {
                grid[i][j] = line - '0';
            }
        }
    }

    int best = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            best = std::max(best, grid[i][j]);
        }
    }

    int euclidDistance = INF;
    std::pair<int, int> bestTree;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            int newEuclidDistance = std::abs(i - start.first) + std::abs(j - start.second);

            if (newEuclidDistance < euclidDistance && grid[i][j] == best)
            {
                euclidDistance = newEuclidDistance;
                bestTree = {i, j};
            }
        }
    }

    std::queue<std::pair<int, int>> q;

    q.push(start);
    d[start.first][start.second] = 0;

    while (!q.empty())
    {
        std::pair<int,int> c = q.front(); q.pop();

        for (std::pair<int, int> mo : moves)
        {
            int x = c.first + mo.first;
            int y = c.second + mo.second;

            if (0 <= x && x < R && 0 <= y && y < C)
            {
                int newD = d[c.first][c.second] + grid[x][y];

                if (newD < d[x][y] || (newD == d[x][y] && cut[c.first][c.second] + (grid[x][y] > 0 ? 1 : 0) < cut[x][y]))
                {
                    cut[x][y] = cut[c.first][c.second] + (grid[x][y] > 0 ? 1 : 0);
                    d[x][y] = newD;
                    q.push({x, y});
                }
            }
        }
    }

    std::cout << cut[bestTree.first][bestTree.second]  - 1 << std::endl;
}