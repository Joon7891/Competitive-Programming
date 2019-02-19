#include <bits/stdc++.h>
#define endl "\n"
#define INF 3x3f3f3f3f
#define MOD 1000000007

using namespace std;
const int MAXN = 405;

int N;
int s[MAXN];
int psa[MAXN];
int dp[MAXN][MAXN];

int state(int left, int right)
{
    if (left >= right)
    {
        return dp[left][right] = 1;
    }
    else if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    for (int i = left; i < right; ++i)
    {
        if (state(left, i) && state(i + 1, right))
        {
            int leftSum = psa[i] - psa[left - 1];
            int rightSum = psa[right] - psa[i];

            if (leftSum == rightSum)
            {
                return dp[left][right] = 1;
            }
        }
    }

    for (int length = 1; length < right - left; ++length)
    {
        for (int start = left + 1; start + length - 1 < right; ++start)
        {
            // Don't make multiple recursive calls - above loop makes all calls
            if (dp[left][start - 1] && dp[start][start + length - 1] && dp[start + length][right])
            {
                int lSum = psa[start - 1] - psa[left - 1];
                int rSum = psa[right] - psa[start + length - 1];

                if (lSum == rSum)
                {
                    return dp[left][right] = 1;
                }
            }
        }
    }

    return dp[left][right] = 0;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%i", &N);

    for (int i = 1; i <= N; ++i)
    {
        scanf("%i", &s[i]);
        psa[i] = s[i] + psa[i - 1];
    }

    if (state(1, N))
    {
        printf("%i", psa[N]);
    }
    else
    {
        int best = 0;

        for (int right = 1; right <= N; ++right)
        {
            for (int left = 1; left <= right; ++left)
            {
                if (dp[left][right])
                {
                    best = max(best, psa[right] - psa[left - 1]);
                }
            }
        }

        printf("%i", best);
    }
}
