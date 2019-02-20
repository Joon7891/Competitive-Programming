#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 2005;
char grid[MAXN][MAXN];
vector<pair<int, int> > cars;
int N, M;

void dfs(int i, int j)
{
    switch (grid[i][j])
    {
    case 'E':
        for (int jj = M - 1; jj > j; --jj)
        {
            if (grid[i][jj] != '.')
            {
                dfs(i, jj);
            }
        }

        break;

    case 'S':
        for (int ii = N - 1; ii > i; --ii)
        {
            if (grid[ii][j] != '.')
            {
                dfs(ii, j);
            }
        }

        break;

    case 'N':
        for (int ii = 0; ii < i; ++ii)
        {
            if (grid[ii][j] != '.')
            {
                dfs(ii, j);
            }
        }

        break;

    case 'W':
        for (int jj = 0; jj < j; ++jj)
        {
            if (grid[i][jj] != '.')
            {
                dfs(i, jj);
            }
        }

        break;
    }

    grid[i][j] = '.';
    cout << "(" << i << "," << j << ")" << endl;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> grid[i][j];

            if (grid[i][j] != '.')
            {
                cars.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < cars.size(); ++i)
    {
        pair<int, int> car = cars[i];
        if (grid[car.first][car.second] != '.')
        {
            dfs(car.first, car.second);
        }
    }
}
