#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 260;
ll bit3D[MAXN][MAXN][MAXN];
int values[MAXN][MAXN][MAXN];
int n, q;
ll sum = 0;

void updateBIT(int x, int y, int z, int value)
{
    int xCache = x;
    int yCache = y;
    int zCache = z;

    for (; x <= n; x += (x & (-x)))
    {
        for (; y <= n; y += (y & (-y)))
        {
            for (; z <= n; z += (z & (-z)))
            {
                bit3D[x][y][z] += value;
            }

            z = zCache;
        }

        y = yCache;
    }
}

ll sumBIT(int x, int y, int z)
{
    int xCache = x;
    int yCache = y;
    int zCache = z;
    ll sum = 0;

    for (; x > 0; x -= (x & (-x)))
    {
        for (; y > 0; y -= (y & (-y)))
        {
            for (; z > 0; z -= (z & (-z)))
            {
                sum += bit3D[x][y][z];
            }

            z = zCache;
        }

        y = yCache;
    }

    return sum;
}

ll solve(int x1, int y1, int z1, int x2, int y2, int z2)
{
    ll current = sumBIT(x2, y2, z2);
    current -= sumBIT(x1 - 1, y2, z2);
    current -= sumBIT(x2, y1 - 1, z2);
    current += sumBIT(x1 - 1, y1 - 1, z2);
    current -= sumBIT(x2, y2, z1 - 1);
    current += sumBIT(x1 - 1, y2, z1 - 1);
    current += sumBIT(x2, y1 - 1, z1 - 1);
    current -= sumBIT(x1 - 1, y1 - 1, z1 - 1);
    return current;
}


int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(bit3D, 0, MAXN * MAXN * MAXN);
    memset(values,  0, MAXN * MAXN * MAXN);

    cin >> n;
    cin >> q;

    char op;
    int x, y, z, l;
    int x1, y1, z1, x2, y2, z2;

    ll runningTotal = 0;
    while (q--)
    {
        cin >> op;

        if (op == 'C')
        {
            cin >> x >> y >> z >> l;
            updateBIT(x, y, z, -values[x][y][z]);
            updateBIT(x, y, z, l);
            values[x][y][z] = l;
        }
        else
        {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            runningTotal += solve(x1, y1, z1, x2, y2, z2);
        }
    }

    cout << runningTotal << "\n";
}
