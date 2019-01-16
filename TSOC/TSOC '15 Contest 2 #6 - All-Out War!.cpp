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
typedef long long ll;

const int MAXN = 30000;
int n, q;
int tree[4 * MAXN];
int lazy[4 * MAXN];
int a[2 * MAXN];

void build(int node, int left, int right)
{
    if (left == right)
    {
        tree[node] = a[left];
    }
    else
    {
        int mid = (right - left) / 2 + left;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int left, int right, int a, int b, int c)
{
    if (lazy[node] != 0)
    {
        tree[node] = max(0, tree[node] + lazy[node]);

        if (left != right)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (right < a || b < left || left > right) return;

    if (a <= left && right <= b)
    {
        tree[node] = max(0, tree[node] - c);

        if (left != right)
        {
            lazy[2 * node] -= c;
            lazy[2 * node + 1] -= c;
        }

        return;
    }

    if (left == right) return;

    int mid = (right - left) / 2 + left;
    update(2 * node, left, mid, a, b, c);
    update(2 * node + 1, mid + 1, right, a, b, c);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int left, int right, int a, int b)
{
    if (lazy[node] != 0)
    {
        tree[node] = max(0, tree[node] + lazy[node]);

        if (left != right)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (right < a || b < left || left > right) return INF;

    if (a <= left && right <= b)
    {
        return tree[node];
    }
    else
    {
        int mid = (right - left) / 2 + left;
        ll s1 = query(2 * node, left, mid, a, b);
        ll s2 = query(2 * node + 1, mid + 1, right, a, b);
        return min(s1, s2);
    }
}

int main()
{
    MEM(lazy, 0);

    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    forn(i, n) cin >> a[i + 1];
    build(1, 1, n);

    int a, b, c;
    while (q--)
    {
        cin >> a >> b >> c;
        update(1, 1, n, a, b, c);

        cout << query(1, 1, n, a, b) << " " << tree[1] << endl;
    }
}