#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define MEM(a, b) memset(a, b, sizeof(a))
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{
    int h1, w1;
    int h2, w2;
    cin >> h1 >> w1;
    cin >> h2 >> w2;

    h1--; h2--;

    int c1 = 0, c2 = 0;
    while (h1 && h2)
    {
        ++c1; ++c2;

        if (c1 % w1 == 0)
        {
            h2--;
        }

        if (c2 % w2 == 0)
        {
            h1--;
        }
    }

    if (h1 == h2)
    {
        cout << -1 << endl;
    }
    else if (h1 > h2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}
