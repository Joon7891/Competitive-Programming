#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl "\n"

using namespace std;
const int MAXN = 150005;
int dp[3][MAXN];
int v[3][MAXN];
int N;

int solve(int a, int b, int c)
{
    memset(dp, INF, sizeof(dp));

    dp[a][0] = v[a][0];
    for (int i = 1; i < N; ++i)
    {
        dp[a][i] = dp[a][i - 1] + v[a][i];
        dp[b][i] = min(dp[a][i - 1] + v[b][i], dp[b][i - 1] + v[b][i]);
        dp[c][i] = min(dp[b][i - 1] + v[c][i], dp[c][i - 1] + v[c][i]);
    }

    return dp[c][N - 1];
}

int main()
{
    cin >> N;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> v[i][j];
        }
    }

    int ans = INF;
    ans = min(ans, solve(0, 1, 2));
    ans = min(ans, solve(0, 2, 1));
    ans = min(ans, solve(1, 0, 2));
    ans = min(ans, solve(1, 2, 0));
    ans = min(ans, solve(2, 0, 1));
    ans = min(ans, solve(2, 1, 0));

    cout << ans << endl;
}