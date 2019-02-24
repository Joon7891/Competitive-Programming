#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

struct edge
{
    int a, b, c, index;

    edge(int a, int b, int c, int index) : a(a), b(b), c(c), index(index) {}

    bool operator < (const edge &adj) const
    {
        if (c == adj.c)
        {
            return index < adj.index;
        }

        return c < adj.c;
    }
};

vector<int> finalEdges;
vector<edge> edges;
int total = 0;
int days = 0;
int N, M, D;

const int MAXN = 100005;
int parent[MAXN];
int ranker[MAXN];

int findParent(int index)
{
    if (index != parent[index])
    {
        parent[index] = findParent(parent[index]);
    }

    return parent[index];
}

bool merger(int i, int j)
{
    int x = findParent(i);
    int y = findParent(j);

    if (x == y) return false;

    ++total;

    if (ranker[x] > ranker[y])
    {
        parent[y] = x;
    }
    else if (ranker[y] > ranker[x])
    {
        parent[x] = y;
    }
    else
    {
        parent[x] = y;
        ranker[x]++;
    }

    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> D;

    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
        ranker[i] = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(edge(a, b, c, i));
    }

    sort(edges.begin(), edges.end());

    int counter = 0;
    for (int i = 0; i < M; ++i)
    {
        edge current = edges[i];

        if (merger(current.a, current.b))
        {
            if (current.index >= N - 1)
            {
                counter++;
            }
        }

        if (total == N - 1)
        {
            cout << counter << endl;
            return 0;
        }
    }
}