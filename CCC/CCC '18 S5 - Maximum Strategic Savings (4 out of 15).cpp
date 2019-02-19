#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

struct point
{
    int a, b;

    point(int a, int b) : a(a), b(b) {}
};

struct edge
{
    point a, b;
    int c;

    edge(point a, point b, int c) : a(a), b(b), c(c) {}

    bool operator < (const edge& adj) const
    {
        return c < adj.c;
    }
};

int N, M, P, Q;
vector<edge> edges;

ll total = 0;
ll totalCost = 0;
ll edgesTaken = 0;
const int MAXN = 100000;
map<int, map<int, pair<int, int> > > parent;
map<int, map<int, int> > ranker;

pair<int, int> findParent(pair<int, int> index)
{
    if (parent[index.first][index.second] != index)
    {
        parent[index.first][index.second] = findParent(parent[index.first][index.second]);
    }

    return parent[index.first][index.second];
}

bool combine(pair<int, int> a, pair<int, int> b)
{
    pair<int, int> x = findParent(a);
    pair<int, int> y = findParent(b);

    if (x == y) return false;

    int xRank = ranker[x.first][x.second];
    int yRank = ranker[y.first][y.second];

    if (xRank > yRank)
    {
        parent[y.first][y.second] = x;
    }
    else if (yRank > xRank)
    {
        parent[x.first][x.second] = y;
    }
    else
    {
        parent[x.first][x.second] = y;
        ranker[x.first][x.second]++;
    }

    edgesTaken++;
    return true;
}

int main()
{
    cin >> N >> M >> P >> Q;

    int a, b, c;
    for (int i = 0; i < P; ++i)
    {
        cin >> a >> b >> c;

        for (int j = 1; j <= N; ++j)
        {
            edges.push_back(edge(point(j, a), point(j, b), c));
            total += c;
        }
    }

    int x, y, z;
    for (int j = 0; j < Q; ++j)
    {
        cin >> x >> y >> z;

        for (int j = 1; j <= M; ++j)
        {
            edges.push_back(edge(point(x, j), point(y, j), z));
            total += z;
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            parent[i][j] = {i, j};
            ranker[i][j] = 0;
        }
    }

    for (int i = 0; i < edges.size(); ++i)
    {
        if (edgesTaken == N * M - 1)
        {
            break;
        }

        edge current = edges[i];
        pair<int, int> a = make_pair(current.a.a, current.a.b);
        pair<int, int> b = make_pair(current.b.a, current.b.b);

        if (combine(a, b))
        {
            totalCost += current.c;
        }
    }

    cout << total - totalCost << endl;

    return 0;
}