#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"

using namespace std;

const int MAXN = 100;
int a[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    forn(i, n)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    while (m--)
    {
        cout << a[0] << endl;
        ++a[0];
        sort(a, a + n);
    }
}