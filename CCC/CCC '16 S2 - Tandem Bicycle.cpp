#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAXN = 100;
int a[MAXN];
int b[MAXN];

int main()
{
    int q; cin >> q;

    int n; cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int total = 0;
    if (q == 2)
    {
        for (int i = 0; i < n; ++i)
        {
            total += max(a[i], b[n - i - 1]);
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            total += max(a[i], b[i]);
        }
    }

    cout << total << endl;
}
