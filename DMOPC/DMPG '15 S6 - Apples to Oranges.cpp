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

int n, m;

map<string, double> appleValue;
map<string, vector<pair<string, double> > > adj;

bool solve()
{
    queue<string> q;
    q.push("APPLES");

    while (!q.empty())
    {
        string current = q.front(); q.pop();

        //cout << appleValue["APPLES"] << endl;

        if (appleValue["APPLES"] > 1.00001)
        {
            return true;
        }

        for (int i = 0; i < adj[current].size(); ++i)
        {
            pair<string, double> mapper = adj[current][i];

            if (appleValue[current] * mapper.s > appleValue[mapper.f])
            {
                appleValue[mapper.f] = appleValue[current] * mapper.s;
                q.push(mapper.f);
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    string name;
    forn(i, n)
    {
        cin >> name;
        appleValue[name] = 0;
    }
    appleValue["APPLES"] = 1;

    string a, b; double c;
    forn(i, m)
    {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    if (solve())
    {
        cout << "YA" << endl;
    }
    else
    {
        cout << "NAW" << endl;
    }
}