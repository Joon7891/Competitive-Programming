#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct edge
{
    char a, b;

    edge(char a, char b) : a(a), b(b) {}
};

map<char, vector<char>> adj;
map<char, bool> visited;
vector<edge> edges;
vector<edge> ans;
string road;

bool dfs(char cur, char target, char a, char b)
{
    bool result = false;

    if (cur == target) return true;

    for (char e : adj[cur])
    {
        if (!visited[e] && !(e == a && cur == b) && !(e == b && cur == a))
        {
            visited[e] = true;
            result |= dfs(e, target, a, b);
        }
    }

    return result;
}

int main()
{
    cin >> road;
    while (road != "**")
    {
        char a = road[0], b = road[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back(edge(a, b));
        cin >> road;
    }

    for (edge e : edges)
    {
        visited.clear();

        visited[e.a] = true;
        if (!dfs(e.a, e.b, e.a, e.b))
        {
            ans.push_back(e);
        }
    }

    for (edge e : ans)
    {
        cout << e.a << e.b << endl;
    }
    cout << "There are " << ans.size() << " disconnecting roads." << endl;
}