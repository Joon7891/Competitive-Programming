#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"

using namespace std;
typedef long long ll;

const int MAXN = 200000;
int a[MAXN];

const int MAXK = 50000;
int prefix[MAXK + 1];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(prefix, 0, sizeof(prefix));

    int n, k;
    cin >> n >> k;

    forn(i, n)
    {
        cin >> a[i];
    }

    int counter = 0;

    ll cumTotal = 0;
    forn(i, n)
    {
        cumTotal += a[i];
        prefix[cumTotal % k] += 1;
    }

    forn(i, k)
    {
        if (prefix[i] > 1)
        {
            counter += (prefix[i] * (prefix[i] - 1)) / 2;
        }
    }

    counter += prefix[0];
    cout << counter << endl;
}