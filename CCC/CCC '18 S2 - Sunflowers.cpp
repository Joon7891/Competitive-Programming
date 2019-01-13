#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int grid[MAXN][MAXN];
int rotatedGrid[MAXN][MAXN];
int n;

bool isValid()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (!(grid[i][j] > grid[i][j - 1]))
            {
                return false;
            }
        }
    }

    return true;
}

void rotateGrid()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rotatedGrid[i][j] = grid[j][n - 1- i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            grid[i][j] = rotatedGrid[i][j];
        }
    }
}

void output()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int topLeft = grid[0][0];
    int topRight = grid[0][n - 1];
    int bottomLeft = grid[n - 1][0];
    int bottomRight = grid[n - 1][n - 1];
    int lowest = min(min(topLeft, topRight), min(bottomLeft, bottomRight));

    if (topRight == lowest)
    {
        rotateGrid();
    }
    else if (bottomRight == lowest)
    {
        for (int i = 0; i < 2; ++i) rotateGrid();
    }
    else if (bottomLeft == lowest)
    {
        for (int i = 0; i < 3; ++i) rotateGrid();
    }

    output();
}
