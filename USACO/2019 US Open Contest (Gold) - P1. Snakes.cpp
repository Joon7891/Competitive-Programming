#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 755;

int dp[MAXN][MAXN];
int m[MAXN][MAXN];
int psa[MAXN];
int a[MAXN];
int N, K;

int main()
{
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            int maximum = 0;
            for (int k = j; k <= i; ++k)
            {
                maximum = max(maximum, a[k]);
            }
            m[j][i] = maximum;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        dp[i][0] = m[1][i] * i - psa[i];
    }

    for (int k = 1; k <= K; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            dp[i][k] = dp[i][k - 1];
            for (int j = 1; j <= i; ++j)
            {
                int delta = m[j][i] * (i - j + 1) - (psa[i] - psa[j - 1]);
                dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + delta);
            }
        }
    }

    cout << dp[N][K] << endl;
}