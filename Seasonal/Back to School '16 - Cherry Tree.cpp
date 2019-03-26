#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10005;

vector<pair<int, int>> adj[MAXN];
int totalC[MAXN];
int c[MAXN];
int w[MAXN];
int N, C, W;
int total = 0;

void dfs(int cur, int prev)
{
    if (adj[cur].size() == 1 && adj[cur][0].first == prev)
    {
        totalC[cur] = c[cur];
        w[cur] = adj[cur][0].second;

        return;
    }
    else
    {
        for (pair<int, int> next : adj[cur])
        {
            if (next.first ^ prev)
            {
                dfs(next.first, cur);
                totalC[cur] += totalC[next.first];
                w[cur] += w[next.first];
            }
            else
            {
                w[cur] += next.second;
                totalC[cur] += c[cur];
            }
        }
    }
}

int main()
{
    cin >> N >> C >> W;

    for (int i = 1; i <= N; ++i) cin >> c[i];

    int x, y, z;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    dfs(1, -1);

    if (adj[1].size() == 1)
    {
        totalC[1] += c[1];
        w[1] += adj[1][0].second;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (totalC[i] >= C && w[i] <= W) total++;
    }

    cout << total << endl;
}
