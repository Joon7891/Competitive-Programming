#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
string a, b;

const int MAXN = 3005;
int dp[MAXN][MAXN];
pair<int, int> prev[MAXN][MAXN];

int main()
{
    cin >> a >> b;

    int aSize = a.length();
    int bSize = b.length();

    for (int i = 1; i <= aSize; ++i)
    {
        for (int j = 1; j <= bSize; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int aIndex = aSize;
    int bIndex = bSize;
    string result = "";
    while (aIndex > 0 && bIndex > 0) // Traverse through DP table and take maximum path
    {
        if (a[aIndex - 1] == b[bIndex - 1])
        {
            result += a[aIndex - 1];
            aIndex--; bIndex--;
        }
        else
        {
            if (dp[aIndex][bIndex - 1] > dp[aIndex - 1][bIndex])
            {
                --bIndex;
            }
            else
            {
                --aIndex;
            }
        }
    }

    reverse(result.begin(), result.end());
    cout << result << endl;
}
