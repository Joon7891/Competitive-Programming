#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXD = 5280;
int solve[MAXD + 1];

const int MAXN = 32;
int strokes[MAXN];

int main()
{
    int d;
    cin >> d;

    int n;
    cin >> n;

    memset(solve, INF, sizeof(solve));
    forn(i, n)
    {
        cin >> strokes[i];
        solve[strokes[i]] = 1;
    }
    solve[0] = 0;

    forn(i, d + 1)
    {
        if (solve[i] != INF) continue;

        forn(j, n)
        {
            if (i - strokes[j] >= 0)
            {
                solve[i] = min(solve[i], 1 + solve[i - strokes[j]]);
            }
        }
    }

    if (solve[d] == INF)
    {
        cout << "Roberta acknowledges defeat." << endl;
    }
    else
    {
        cout << "Roberta wins in " << solve[d] << " strokes." << endl;
    }
}
