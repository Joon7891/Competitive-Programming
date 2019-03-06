#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10001;

int N, M;
vector<int> adj[MAXN];
bool v[MAXN][MAXN];
bool p[MAXN];
bool t[MAXN];

bool topologicalCheck(int i)
{
    if (t[i]) return false;
    if (p[i]) return true;

    t[i] = 1;
    for (int a : adj[i])
    {
        if (!topologicalCheck(a))
        {
            return false;
        }
    }

    t[i] = false;
    p[i] = true;
    return true;
}

int main()
{
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;

        if (v[a][b]) continue;

        adj[a].push_back(b);
        v[a][b] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!p[i])
        {
            if (!topologicalCheck(i))
            {
                cout << "N" << endl;
                return 0;
            }
        }
    }

    cout << "Y" << endl;
}