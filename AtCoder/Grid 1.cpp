#include <bits/stdc++.h>
#define endl "\n"
#define INF 3x3f3f3f3f
#define MOD 1000000007

using namespace std;
const int MAXN = 1005;

char grid[MAXN][MAXN];
int dp[MAXN][MAXN];
int H, W;

int main()
{
    cin >> H >> W;

    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (i == 1 && j == 1) continue;

            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
            }
            else
            {
                int top = grid[i - 1][j] == '#' ? 0 : dp[i - 1][j];
                int left = grid[i][j - 1] == '#' ? 0 : dp[i][j - 1];
                dp[i][j] = (top + left) % MOD;
            }
        }
    }

    cout << dp[H][W] << endl;
}
