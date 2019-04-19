#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 200005;

struct query
{
    int index, l, r, k;
    long long lowerSum = 0;

    query(int index, int l, int r, int k) : index(index), l(l), r(r), k(k) {}

    bool operator < (const query& adj)
    {
        return k < adj.k;
    }
};

pair<int, int> p[MAXN];
vector<query> queries;
long long BIT[MAXN];
long long ans[MAXN];
int N, Q, K = 0;

void update(int index, int value)
{
    while (index <= N)
    {
        BIT[index] += value;
        index += index & -index;
    }
}

long long queryBIT(int index)
{
    long long total = 0;
    while (index > 0)
    {
        total += BIT[index];
        index -= index & -index;
    }

    return total;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);

    memset(BIT, 0LL, sizeof(BIT));

    cin >> N >> Q;

    for (int i = 0, x; i < N; ++i)
    {
        cin >> x;
        p[i] = {x, i + 1};
    }

    sort(p, p + N);

    for (int i = 0, l, r, k; i < Q; ++i)
    {
        cin >> l >> r >> k;
        queries.push_back(query(i, l, r, k));
    }

    sort(queries.begin(), queries.end());

    int ptr = 0;
    for (query q : queries)
    {
        while (ptr < N && p[ptr].first < q.k)
        {
            update(p[ptr].second, p[ptr].first);
            ptr++;
        }

        ans[q.index] = queryBIT(q.r) - queryBIT(q.l - 1);
    }

    for (int i = ptr; i < N; ++i)
    {
        update(p[i].second, p[i].first);
    }

    for (query q : queries)
    {
        ans[q.index] -= queryBIT(q.r) - queryBIT(q.l - 1) - ans[q.index];
        ans[q.index] *= -1LL;
    }

    for (int i = 0; i < Q; ++i)
    {
        cout << ans[i] << endl;
    }
}