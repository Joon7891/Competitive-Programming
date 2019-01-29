#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int M = 1000000007;

int n, c;
int dp[1002][10002];

int main()
{
    cin >> n >> c;

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;

        for (int j = 1; j <= c; ++j)
        {
            if (j >= i)
            {
                dp[i][j] = (dp[i - 1][j] - dp[i - 1][j - i] + M) % M;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
        }
    }

    cout << dp[n][c] << endl;
}
