#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2005;
char grid[MAXN][MAXN];
int height[MAXN][MAXN];
int N;

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        cin >> N;

        int total = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> grid[i][j];
                total += (grid[i][j] == '#');
            }
        }
    
        for (int i = N - 1; i >= 0; --i)
        {
            for (int j = 1; j < N - 1; ++j)
            {
                if (grid[i][j] == '#' && grid[i + 1][j - 1] == '#' &&
                    grid[i + 1][j] == '#' && grid[i + 1][j + 1] == '#')
                {
                    height[i][j] = min(height[i + 1][j - 1], height[i + 1][j + 1]) + 1;
                    total += height[i][j];
                }
            }
        }
    
        cout << total << endl;
        
        memset(height, 0, sizeof(height));
    }
}