#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXS = 1030;
int bit2D[MAXS][MAXS];
int s;

void updateBIT(int x, int y, int a)
{
    int yCache = y;
    for (; x <= s; x += (x & (-x)))
    {
        for (; y <= s; y += (y & (-y)))
        {
            bit2D[x][y] += a;
        }
        y = yCache;
    }
}

ll sumBIT(int x, int y)
{
    ll sum = 0;
    int yCache = y;

    for (; x > 0; x -= (x & (-x)))
    {
        for (; y > 0; y -= (y & (-y)))
        {
            sum += bit2D[x][y];
        }
        y = yCache;
    }

    return sum;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(bit2D, 0, MAXS * MAXS);
    int instruction;
    cin >> instruction >> s;

    int x, y, a;
    int l, b, r, t;
    while (true)
    {
        cin >> instruction;

        if (instruction == 1)
        {
            cin >> x >> y >> a;
            ++x; ++y;
            updateBIT(x, y, a);
        }
        else if (instruction == 2)
        {
            cin >> l >> b >> r >> t;
            ++l; ++b; ++r; ++t;
            ll sum = sumBIT(r, t);
            ll dif1 = sumBIT(l - 1, t);
            ll dif2 = sumBIT(r, b - 1);
            ll over = sumBIT(l - 1, b - 1);

            cout << sum - dif1 - dif2 + over << "\n";
        }
        else
        {
            break;
        }
    }
}