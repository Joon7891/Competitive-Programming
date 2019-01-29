#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

const int MAXN = 1005;
int best[MAXN][MAXN];
int a[MAXN];
int b[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> a[i + 1];
    for (int j = 0; j < m; ++j) cin >> b[j + 1];

    for (int i = 0; i <= n; ++i)
    {
        best[i][0] = 0;
    }

    for (int i = 0; i <= n; ++i)
    {
        best[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
            {
                best[i][j] = 1 + best[i - 1][j - 1];
            }
            else
            {
                best[i][j] = max(best[i - 1][j], best[i][j - 1]);
            }
        }
    }

    cout << best[n][m] << endl;
}