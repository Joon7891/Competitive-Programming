#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
int N, M;

const int MAXN = 100005;
int parent[MAXN];
int ranker[MAXN];
vector<int> infected;

int root(int index)
{
    if (parent[index] != index)
    {
        parent[index] = root(parent[index]);
    }

    return parent[index];
}

void combo(int i, int j)
{
    int x = root(i);
    int y = root(j);

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
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
        ranker[i] = 0;
    }

    int first;
    for (int i = 0; i < M; ++i)
    {
        int length; cin >> length;

        int first; cin >> first;

        while (--length)
        {
            int next; cin >> next;
            combo(first, next);
        }
    }

    int rootParent = root(1);
    infected.push_back(1);
    for (int i = 2; i <= N; ++i)
    {
        if (root(i) == rootParent)
        {
            infected.push_back(i);
        }
    }

    cout << infected.size() << endl;
    for (int i = 0; i < infected.size(); ++i)
    {
        cout << infected[i] << " ";
    }
    cout << endl;
}