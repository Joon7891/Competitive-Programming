#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))

using namespace std;

int main()
{
    int n; cin >> n;

    int x = 0, y;
    forn(i, n)
    {
        cin >> y;
        x = x ^ y;
    }

    cout << x << endl;
}
