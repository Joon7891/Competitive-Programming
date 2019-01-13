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

struct edge
{
    int next, t, h;

    edge(int next, int t, int h) : next(next), t(t), h(h) {}
};

struct node
{
    int value, t, h;

    node(int value, int t, int h) : value(value), t(t), h(h) {}

    bool operator < (const node &b) const
    {
        if (t == b.t)
        {
            return h < b.h;
        }

        return t >= b.t;
    }
};

const int MAXN = 2001;
vector<edge> adj[MAXN]; // ()
int hBest[MAXN];
int tBest[MAXN];

int k, n, m;
int A, B;

int solve()
{
    priority_queue<node> pq;
    pq.push(node(A, 0, k));

    while (!pq.empty())
    {
        node current = pq.top(); pq.pop();
        int value = current.value;
        int t = current.t;
        int h = current.h;

        if (h < 1)
        {
            continue;
        }

        if (value == B && h > 0)
        {
            return t;
        }

        for (int i = 0; i < adj[value].size(); ++i)
        {
            edge newEdge = adj[value][i];
            int newT = t + newEdge.t;
            int newH = h - newEdge.h;

            if (newT < tBest[newEdge.next] && newH > 0)
            {
                tBest[newEdge.next] = newT;
                pq.push(node(newEdge.next, newT, newH));
            }
            if (newH > hBest[newEdge.next])
            {
                hBest[newEdge.next] = newH;
                pq.push(node(newEdge.next, newT, newH));
            }
        }
    }

    return -1;
}

int main()
{
    // bool operator < (const node &b) const - does it have priority over b?
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    MEM(hBest, 0);
    MEM(tBest, INF);

    cin >> k >> n >> m;
    tBest[1] = 0;
    hBest[1] = k;

    int a, b, t, h;
    forn(i, m)
    {
        cin >> a >> b >> t >> h;
        adj[a].pb(edge(b, t, h));
        adj[b].pb(edge(a, t, h));
    }

    cin >> A >> B;

    cout << solve() << endl;
}
