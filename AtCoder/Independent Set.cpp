#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
int N;

const int MOD = 1000000007;
const int MAXN = 100005;
vector<int> adj[MAXN];
bool leaf[MAXN];
int d[MAXN];

ll blackCombo[MAXN];
ll whiteCombo[MAXN];

void solve(int index)
{
    if (leaf[index])
    {
        blackCombo[index] = 1;
        whiteCombo[index] = 1;
        return;
    }

    ll whiteTotal = 1;
    ll blackTotal = 1;
    for (int i = 0; i < adj[index].size(); ++i)
    {
        int a = adj[index][i];

        if (d[a] > d[index]) // AND, NOT OR - FCP vs Additive
        {
            solve(a);
            whiteTotal = (whiteTotal * (blackCombo[a] + whiteCombo[a])) % MOD;
            blackTotal = (blackTotal * whiteCombo[a]) % MOD;
        }
    }

    blackCombo[index] = blackTotal;
    whiteCombo[index] = whiteTotal;
}

int main()
{
    memset(d, INF, sizeof(d));
    memset(leaf, true, sizeof(leaf));

    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    d[1] = 0;

    while (!q.empty())
    {
        int current = q.front(); q.pop();

        for (int i = 0; i < adj[current].size(); ++i)
        {
            int next = adj[current][i];

            if (d[current] + 1 < d[next])
            {
                d[next] = d[current] + 1;
                q.push(next);
                leaf[current] = false;
            }
        }
    }

    solve(1);
    cout << (blackCombo[1] + whiteCombo[1]) % MOD << endl;
}
