#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int N, M;

const int MAXN = 100005;
vector<int> adj[MAXN];
int d[MAXN];

int solve(int index) // DFS is faster in a DAG*
{
    if (d[index] != -1) return d[index];

    d[index] = 0;
    for (int i = 0; i < adj[index].size(); ++i)
    {
        int next = adj[index][i];

        d[index] = max(d[index], solve(next) + 1);
    }

    return d[index];
}

int main()
{
    memset(d, -1, sizeof(d));

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        ans = max(ans, solve(i));
    }

    cout << ans << endl;
}