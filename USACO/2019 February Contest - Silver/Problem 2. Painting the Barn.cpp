#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAX = 1005;
int d[MAX][MAX];
int total = 0;
int N, K;

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    cin >> N >> K;

    int x1, y1, x2, y2;
    while (N--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2; ++j)
        {
            d[j][y1]++;
            d[j][y2]--;
        }
    }

    for (int i = 0; i < MAX; ++i)
    {
        int coats = 0;

        for (int j = 0; j < MAX; ++j)
        {
            coats += d[i][j];
            if (coats == K) total++;
        }
    }

    cout << total << endl;
}
