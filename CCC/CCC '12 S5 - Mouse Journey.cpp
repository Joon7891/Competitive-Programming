#include <iostream>

using namespace std;

int r, c;
int grid[27][27];
int n;
int x, y;

int main() 
{    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> y >> x;
        grid[y][x] = -1;
    }

    grid[1][0] = 1;
    grid[0][1] = 0;

    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (grid[i][j] != -1)
            {
                if (grid[i - 1][j] != -1 && grid[i][j - 1] != -1)
                {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];   
                }               
                else if (grid[i - 1][j] != -1 && grid[i][j - 1] == -1)
                {
                    grid[i][j] = grid[i - 1][j];
                } 
                else if (grid[i - 1][j] == -1 && grid[i][j - 1] != -1)
                {
                    grid[i][j] = grid[i][j - 1];
                }
            }
        }
    }

    cout << grid[r][c] << "\n";
}