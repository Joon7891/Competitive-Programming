#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
bool valid[MAXN];
int d[MAXN];
int P, F, D = -1;
int N, M, K;

void dfs(int cur, int prev)
{
    for (int next : adj[cur])
    {
        if (next ^ prev)
        {
            dfs(next, cur);
            valid[cur] |= valid[next];
        }
    }

    if (valid[cur]) K++;
}

void far(int cur, int prev)
{
    if (d[cur] > D)
    {
        D = d[cur];
        F = cur;
    }

    for (int next : adj[cur])
    {
        if (next ^ prev && valid[next])
        {
            d[next] = d[cur] + 1;
            far(next, cur);
        }
    }
}

int diam(int cur, int prev)
{
    int best = 0;
    for (int next : adj[cur])
    {
        if (next ^ prev && valid[next])
        {
            best = max(best, 1 + diam(next, cur));
        }
    }

    return best;
}

int main()
{
    cin >> N >> M;

    memset(valid, false, sizeof(valid));
    for (int i = 0; i < M; ++i)
    {
        cin >> P;
        valid[P] = true;
    }

    for (int i = 0,a, b; i < N - 1; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    F = P;
    d[P] = 0;
    dfs(P, -1);
    far(P, -1);

    int D = diam(F, -1);
    int ans = 2 * (K - 1) - D;
    cout << ans << endl;
}