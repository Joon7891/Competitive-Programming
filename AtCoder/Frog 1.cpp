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
typedef long long ll;

const int MAXN = 100006;
int best[MAXN];
int cost[MAXN];

int main()
{
    MEM(best, INF);
    best[1] = 0;

    int n;
    cin >> n;

    forn(i, n)
    {
        cin >> cost[i + 1];
    }

    for (int i = 1; i <= n; ++i)
    {
        int current = best[i];

        int newCost = abs(cost[i] - cost[i + 1]);
        best[i + 1] = min(best[i + 1], newCost + current);

        newCost = abs(cost[i] - cost[i + 2]);
        best[i + 2] = min(best[i + 2], newCost + current);
    }

    cout << best[n] << endl;
}
