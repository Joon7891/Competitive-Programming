#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 100005;
int parent[MAXN];
int ranker[MAXN];
bool used[MAXN];
int N, M;

int finder(int index)
{
    if (parent[index] != index)
    {
        parent[index] = finder(parent[index]);
    }

    return parent[index];
}

void combine(int a, int b)
{
    int x = finder(a);
    int y = finder(b);

    if (x == y) return;

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
}

int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        used[i] = false;
        parent[i] = i;
        ranker[i] = 0;
    }

    char type; int a, b;
    while (M--)
    {
        cin >> type >> a >> b;
        combine(a, b);
    }

    int total = 0;
    for (int i = 1; i <= N; ++i)
    {
        int indexParent = finder(i);

        if (!used[indexParent])
        {
            used[indexParent] = true;
            total++;
        }
    }

    cout << "1";
    while (total--)
    {
        cout << "0";
    }
    cout << endl;
}