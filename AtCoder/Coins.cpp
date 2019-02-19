#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long double LD;

const int MAXN = 3000;
LD dp[MAXN][MAXN];
LD p[MAXN];
int N;


int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> p[i + 1];
    }

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = 1.0f;
                continue;
            }

            dp[i][j] += p[i] * dp[i - 1][j - 1];
            dp[i][j] += (1 - p[i]) * dp[i - 1][j];
        }
    }

    LD total = 0.0f;
    for (int i = N / 2 + 1; i <= N; ++i)
    {
        total += dp[N][i];
    }

    cout << setprecision(9) << total << endl;
}
