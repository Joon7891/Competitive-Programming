#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl "\n"

using namespace std;

struct point
{
    int node, cost, mask;

    point (int node, int cost, int mask) : node(node), cost(cost), mask(mask) {}
};

const int MAXN = 20;
int cost[MAXN][1 << MAXN];
int best[MAXN];
int n, m;
vector<pair<int, int> > adj[MAXN];

int solve()
{
    queue<point> q;

    cost[0][1] = 0;
    best[0] = 0;
    q.push(point(0, 0, 1));

    while (!q.empty())
    {
        point current = q.front(); q.pop();

        for (int i = 0; i < adj[current.node].size(); ++i)
        {
            int next = adj[current.node][i].first;
            int new_cost = current.cost + adj[current.node][i].second;

            if ((1 << next & current.mask) == 0)
            {
                int new_mask = current.mask | (1 << next);
                if (new_cost >= cost[next][new_mask])
                {
                    cost[next][new_mask] = new_cost;
                    q.push(point(next, new_cost, new_mask));
                    best[next] = max(best[next], new_cost);
                }
            }
        }
    }

    return best[n - 1];
}


int main()
{
    memset(cost, 0, sizeof(cost));

    scanf("%i %i", &n, &m);

    while (m--)
    {
        int s, d, l;
        scanf("%i %i %i", &s, &d, &l);
        adj[s].push_back({d, l});
    }

    cout << solve() << endl;
}