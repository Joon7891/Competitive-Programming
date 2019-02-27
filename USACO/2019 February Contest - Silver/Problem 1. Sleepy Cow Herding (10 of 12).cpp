#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 100005;
int a[MAXN];
int N;

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    cin >> N;

    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);

    int high = 0;
    int minSpaces = INF;
    for (int i = 0; i < N - 1; ++i)
    {
        high += a[i + 1] - a[i] - 1;

        int taken = 0;
        for (int j = i; j <= N; ++j)
        {
            if (j == N) taken = 0;
            else
            {
                if (a[j] <= a[i] + N - 1) taken++;
                if (a[j] >= a[i] + N - 1) break;
            }
        }
        minSpaces = min(minSpaces, N - taken);
    }
    high -= min(a[1] - a[0] - 1, a[N - 1] - a[N - 2] - 1);

    cout << minSpaces << endl;
    cout << high << endl;
}
