#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 100005;

int p[MAXN];

int main()
{
    memset(p, 1, sizeof(p));

    double upper = sqrt(MAXN) + 1;
    for (int i = 2; i < upper; ++i)
    {
        if (p[i])
        {
            for (int j = 2 * i; j < MAXN; j += i)
            {
                p[j] = 0;
            }
        }
    }

    for (int i = 0, x; i < 5; ++i)
    {
        cin >> x;

        long long total = 0;
        for (int j = 2; j <= x; ++j)
        {
            if (p[j]) total += j;
        }

        cout << total << endl;
    }
}
