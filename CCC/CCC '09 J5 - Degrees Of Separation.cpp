#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define pb push_back
#define MEM(a, b) memset(a, (b), sizeof(a))
#define INF 0x3f3f3f3f

using namespace std;

const int MAX = 50;
vector<int> adj[MAX];

int f(int a)
{
    set<int> friends;
    friends.insert(a);
    vector<int> eval;
    set<int> fof;

    forn(i, adj[a].size())
    {
        friends.insert(adj[a][i]);
        eval.pb(adj[a][i]);
    }

    forn(i, eval.size())
    {
        int node = eval[i];

        forn(j, adj[node].size())
        {
            if (find(friends.begin(), friends.end(), adj[node][j]) == friends.end())
            {
                fof.insert(adj[node][j]);
            }
        }
    }


    return fof.size();
}

int bfs(int a, int b)
{
    int d[MAX];
    MEM(d, -1);

    queue<int> q;
    d[a] = 0;
    q.push(a);

    while (!q.empty())
    {
        int current = q.front(); q.pop();

        if (current == b)
        {
            return d[current];
        }

        forn(i, adj[current].size())
        {
            int o = adj[current][i];

            if (d[o] == -1)
            {
                d[o] = d[current] + 1;
                q.push(o);
            }
        }
    }

    return -1;
}

void add(int x, int y)
{
    adj[x].pb(y);
    adj[y].pb(x);
}

void init()
{
    add(2, 6);
    add(1, 6);
    add(6, 7);
    add(6, 4);
    add(6, 5);
    add(4, 5);
    add(3, 6);
    add(3, 4);
    add(3, 5);
    add(3, 15);
    add(7, 8);
    add(8, 9);
    add(9, 10);
    add(12, 9);
    add(11, 10);
    add(12, 11);
    add(15, 13);
    add(12, 13);
    add(13, 14);

    add(16, 17);
    add(17, 18);
    add(18, 16);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    char state;
    int x, y;
    while (true)
    {
        cin >> state;

        if (state == 'q')
        {
            break;
        }
        else if (state == 'i')
        {
            cin >> x >> y;

            if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end())
            {
                adj[x].pb(y);
                adj[y].pb(x);
            }
        }
        else if (state == 'd')
        {
            cin >> x >> y;
            adj[x].erase(find(adj[x].begin(), adj[x].end(), y));
            adj[y].erase(find(adj[y].begin(), adj[y].end(), x));

        }
        else if (state == 'n')
        {
            cin >> x;
            cout << adj[x].size() << endl;
        }
        else if (state == 'f')
        {
            cin >> x;
            cout << f(x) << endl;
        }
        else if (state == 's')
        {
            cin >> x >> y;

            int result = bfs(x, y);

            if (result == -1)
            {
                cout << "Not connected" << endl;
            }
            else
            {
                cout << result << endl;
            }
        }
    }
}