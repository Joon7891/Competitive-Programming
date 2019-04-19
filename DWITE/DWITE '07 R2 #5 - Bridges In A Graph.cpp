#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 105;

struct edge
{
    int a, b;

    edge(int a, int b) : a(a), b(b) {}
};

vector<int> adj[MAXN];
vector<edge> edges;
bool visited[MAXN];
int N, M;

bool dfs(int index, int target, int a, int b)
{
    visited[index] = true;
    if (index == target) return true;

    bool result = false;
    for (int next : adj[index])
    {
        if (!visited[next] && !(index == a && next == b) && !(index == b && next == a))
        {
            result |= dfs(next, target, a, b);
        }
    }

    return result;
}

int main()
{
    int T = 5;
    while (T--)
    {
        for (vector<int> &next : adj)
        {
            next.clear();
        }
        edges.clear();

        cin >> N >> M;

        for (int i = 0, a, b; i < M; ++i)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back(edge(a, b));
        }

        int total = 0;
        for (edge e : edges)
        {
            memset(visited, false, sizeof(visited));
            if (dfs(e.a, e.b, e.a, e.b)) continue;
            else total++;
        }

        cout << total << endl;
    }
}
