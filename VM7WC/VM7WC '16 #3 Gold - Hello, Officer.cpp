#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl "\n"

using namespace std;
const int MAXN = 2005;
typedef pair<int, int> pii;

vector<pii> adj[MAXN];
int N, M, B, Q;
int d[MAXN];

void compute()
{
    memset(d, INF, sizeof(d));

    queue<int> q;
    q.push(B);
    d[B] = 0;

    while (!q.empty())
    {
        int c = q.front(); q.pop();

        for (pii a : adj[c])
        {
            if (d[c] + a.second < d[a.first])
            {
                d[a.first] = d[c] + a.second;
                q.push(a.first);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> B >> Q;

    int a, b, c;
    while (M--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    compute();

    while (Q--)
    {
        cin >> a;

        if (d[a] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[a] << endl;
        }
    }
}
