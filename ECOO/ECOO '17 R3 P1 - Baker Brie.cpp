#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[5000][200];
int F, D, t = 0;

int solve()
{
    cin >> F >> D;

    for (int i = 0; i < D; ++i)
    {
        for (int j = 0; j < F; ++j)
        {
            cin >> a[i][j];
        }
    }

    t = 0;
    for (int i = 0; i < F; ++i)
    {
        int fSum = 0;

        for (int j = 0; j < D; ++j)
        {
            fSum += a[j][i];
        }

        if (fSum % 13 == 0)
        {
            t += fSum / 13;
        }
    }

    for (int i = 0; i < D; ++i)
    {
        int dSum = 0;

        for (int j = 0; j < F; ++j)
        {
            dSum += a[i][j];
        }

        if (dSum % 13 == 0)
        {
            t += dSum / 13;
        }
    }

    return t;
}

int main()
{
    int T = 10;

    while (T--)
    {
        cout << solve() << endl;
    }
}
