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

const int MAXN = 500000;
int n, m;

vector<pii > adj[MAXN + 1];
int d2[MAXN + 1];
int d[MAXN + 1];

void solve()
{
    deque<int> q;
    q.push_back(1);

    while(!q.empty())
    {
        int current = q.front(); q.pop_front();

        for (int i = 0; i < adj[current].size(); ++i)
        {
            pii next = adj[current][i];

            if (d[current] + next.s < d[next.f])
            {
                d2[next.f] = d[next.f];
                d[next.f] = d[current] + next.s;
                q.push_back(next.f);
            }

            if (d[current] + next.s < d2[next.f] && d[current] + next.s != d[next.f])
            {
                d2[next.f] = d[current] + next.s;
                q.push_back(next.f);
            }

            if (d2[current] + next.s < d2[next.f] && d2[current] + next.s != d[next.f])
            {
                d2[next.f] = d2[current] + next.s;
                q.push_back(next.f);
            }

            if (d2[current] == INF && d[current] < INF)
            {
                d2[current] = d[current] + 2 * next.s;
                // cout << "Being used" << endl;
            }
        }
    }

}

int main()
{
    MEM(d, INF);
    MEM(d2, INF);
    d[1] = 0;
    d2[1] = 0;
    cin >> n >> m;

    int a, b, w;
    forn(i, m)
    {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    solve();

    cout << d2[n] << endl;
}