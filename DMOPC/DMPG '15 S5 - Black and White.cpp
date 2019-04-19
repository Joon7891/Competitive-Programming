#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 10005;
bool d[MAXN][MAXN];
bool v[MAXN][MAXN];
int N, M;

int main()
{
    memset(d, 0, sizeof(d));

    cin >> N >> M;

    for (int i = 0, x, y, w, h; i < M; ++i)
    {
        cin >> x >> y >> w >> h;
        d[++x][++y] ^= 1;
        d[x][y + h] ^= 1;
        d[x + w][y] ^= 1;
        d[x + w][y + h] ^= 1;
    }

    int counter = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            v[i][j] ^= d[i][j];
            v[i][j] ^= v[i - 1][j];
            v[i][j] ^= v[i][j - 1];
            v[i][j] ^= v[i - 1][j - 1];
            if (v[i][j]) counter++;
        }
    }

    cout << counter << endl;
}