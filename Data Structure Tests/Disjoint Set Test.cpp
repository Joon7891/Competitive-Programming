#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 100005;
int parent[MAXN];
int m_rank[MAXN];
int n, m;

int find_root(int index)
{
    if (index != parent[index])
    {
        parent[index] = find_root(parent[index]);
    }

    return parent[index];
}

int counter = 0;
vector<int> edges;

bool union_set(int i, int j)
{
    int x = find_root(i);
    int y = find_root(j);

    if (x != y)
    {
        ++counter;

        if (m_rank[x] > m_rank[y])
        {
            parent[y] = x;
        }
        else if (m_rank[y] > m_rank[x])
        {
            parent[x] = y;
        }
        else
        {
            parent[x] = y;
            m_rank[y]++;
        }

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%i %i", &n, &m);

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        m_rank[i] = 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        scanf("%i%i", &a, &b);

        bool state = union_set(a, b);

        if (state)
        {
            edges.push_back(i);
        }

        if (counter == n - 1)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                cout << edges[i] << endl;
            }
            return 0;
        }
    }

    cout << "Disconnected Graph" << endl;
}
