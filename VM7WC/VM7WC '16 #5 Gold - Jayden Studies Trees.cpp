#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 10005;
bool visited[MAXN];
vector<int> adj[MAXN];
int n;

int dfs(int u)
{
    int best = 1;
    forn(i, adj[u].size())
    {
        int v = adj[u][i];

        if (!visited[v])
        {
            visited[v] = true;
            int d = 1 + dfs(v);
            best = max(best, d);
        }
    }

    return best;
}

int main()
{
    MEM(visited, false);

    cin >> n;

    int a, b;
    forn(i, n - 1)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int best1 = 0;
    int best2 = 0;
    visited[1] = true;

    forn(i, adj[1].size())
    {
        visited[adj[1][i]] = true;
        int d = dfs(adj[1][i]);

        if (d > best1)
        {
            best2 = best1;
            best1 = d;
        }
        else if (d > best2)
        {
            best2 = d;
        }
    }

    int diameter = best1 + best2;
    cout << diameter << endl;
}