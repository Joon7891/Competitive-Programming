#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))
#define maxx(a, b) (a > b ? a : b)

using namespace std;
typedef long long ll;

const int MAXN = 1000005;
int a[MAXN];
ll dp[MAXN];

int main()
{
    int n; cin >> n;

    forn(i, n) cin >> a[i];

    dp[0] = maxx(0, a[0]);
    dp[1] = maxx(maxx(a[1], 0), dp[0]);

    for (int i = 2; i < n; ++i)
    {
        dp[i] = maxx(dp[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n - 1] << endl;
}