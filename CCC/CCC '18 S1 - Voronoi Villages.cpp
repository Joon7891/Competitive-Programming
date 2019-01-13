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

const int MAXN = 100;
int villages[MAXN];

int main()
{
    int n; cin >> n;

    forn(i, n) cin >> villages[i];

    sort(villages, villages + n);

    double best = INF;

    for (int i = 1; i < n - 1; ++i)
    {
        double sum = (villages[i + 1] - villages[i - 1]) / 2.0;
        best = min(best, sum);
    }

    cout << setprecision(1) << fixed << best << endl;
}
