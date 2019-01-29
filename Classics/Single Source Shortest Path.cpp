#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAXN = 1005;
int best[MAXN];

vector<pair<int, int> > adj[MAXN];

void setup()
{
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int current = q.front(); q.pop();

        for (int i = 0; i < adj[current].size(); ++i)
        {
            int next = adj[current][i].first;
            int weight = adj[current][i].second;

            if (best[next] == -1 || best[current] + weight < best[next])
            {
                best[next] = best[current] + weight;
                q.push(next);
            }
        }
    }
}

int main()
{
    memset(best, -1, sizeof(best));
    best[1] = 0;

    int n, m;
    cin >> n >> m;

    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    setup();

    for (int i = 1; i <= n; ++i)
    {
        cout << best[i] << endl;
    }
}