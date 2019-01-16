#include<bits/stdc++.h>

using namespace std;

const int MAXC = 1001;
int n[MAXC];
int k[MAXC];

map<pair<int, int>, int> memo;

int solve(int c, int balance)
{
    int dp[c + 1][balance + 1];

    for (int i = 0; i <= c; ++i)
    {
        for (int j = 0; j <= balance; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (k[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], n[i] + dp[i - 1][j - k[i]]);
            }
        }
    }

    return dp[c][balance];
}

int main()
{
    int c, m;
    cin >> c >> m;

    for (int i = 0; i < c; ++i)
    {
        cin >> n[i] >> k[i];
    }

    cout << solve(c, m) << "\n";
}