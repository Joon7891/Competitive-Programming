#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;
int N, W;

const int MAXN = 105;
const int MAXW = 100005;
int w[MAXN];
int v[MAXN];
ll dp[2][MAXW];

int main()
{
    cin >> N >> W;

    for (int i = 1; i <= N; ++i)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int cap = 0; cap <= W; ++cap)
        {
            dp[0][cap] = dp[1][cap];

            if (w[i] > cap)
            {
                dp[1][cap] = dp[0][cap];
            }
            else
            {
                dp[1][cap] = max(dp[0][cap - w[i]] + v[i], dp[0][cap]);
            }
        }
    }

    cout << dp[1][W] << endl;
    return 0;
}
