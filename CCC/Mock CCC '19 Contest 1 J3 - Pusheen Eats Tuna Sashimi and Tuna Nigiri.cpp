#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))
#define debug() cout << "..." << endl
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define pb push_back
#define endl "\n"
#define f first
#define s second
#define MAXN 2000001

using namespace std;

bool solve(int a, int b, int n)
{
    if (n % a == 0 || n % b == 0) return true;

    while (n > 0)
    {
        if (n % b == 0) return true;

        n -= a;
    }

    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    forn(i, t)
    {
        int a, b, n;
        cin >> a >> b >> n;

        if (solve(a, b, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
