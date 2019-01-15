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
typedef long long ll;

const int MAXN = 5001;
vector<pii > adj[MAXN]; // (destination, cost)
int cost[MAXN];
int best[MAXN];
int routeBest[MAXN];
int n, t;
int d;

int solution = INF;

struct node
{
    int cost, loc;

    node(int cost, int loc) : cost(cost), loc(loc) {};

    bool operator < (const node &b) const
    {
        return cost > b.cost;
    }
};

void solve()
{
    priority_queue<node> pq;

    pq.push(node(0, d));
    best[d] = 0;

    // Cost is with island cost
    while (!pq.empty())
    {
        node current = pq.top(); pq.pop();
        int noder = current.loc;

        if (cost[current.loc] != -1)
        {
            solution = min(solution, cost[current.loc] + current.cost);
        }

        if (current.cost > solution)
        {
            return;
        }

        forn(i, adj[noder].size())
        {
            int newCost = current.cost + adj[noder][i].s;

            if (newCost < best[adj[noder][i].first])
            {
                best[adj[noder][i].first] = newCost;
                pq.push(node(newCost, adj[noder][i].f));
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    MEM(cost, -1);

    MEM(best, INF);

    cin >> n >> t;

    int x, y, c;
    forn(i, t)
    {
        cin >> x >> y >> c;
        adj[x].pb({y, c});
        adj[y].pb({x, c});
    }

    int newN; cin >> newN;
    int z, p;
    forn(i, newN)
    {
        cin >> z >> p;
        cost[z] = p;
    }

    cin >> d;

    solve();

    cout << solution << endl;
}
