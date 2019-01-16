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
const int MAXN = 1000000 + 1;
bool switches[MAXN];
int counters[MAXN];
int paths[MAXN][2];

int main()
{
    MEM(switches, false);
    MEM(counters, 0);

    int n, m;
    cin >> n >> m;

    int a, b;
    forn(i, n)
    {
        cin >> a >> b;
        paths[i + 1][0] = a;
        paths[i + 1][1] = b;
    }

    counters[1] = m;

    // Odd = Switch, Even = Stay
    for (int i = 1; i <= n; ++i)
    {
        if (counters[i] % 2 == 0)
        {
            // switches[i] = switches[i];
            int half = counters[i] / 2;
            counters[paths[i][0]] += half;
            counters[paths[i][1]] += half;
        }
        else
        {
            // Less, More
            int half1 = counters[i] / 2;
            int half2 = counters[i] - half1;

            if (!switches[i])
            {
                counters[paths[i][0]] += half2;
                counters[paths[i][1]] += half1;
            }
            else
            {
                counters[paths[i][1]] += half2;
                counters[paths[i][0]] += half1;
            }

            switches[i] = !switches[i];
        }
    }

    forn(i, n)
    {
        cout << switches[i + 1];
    }
}