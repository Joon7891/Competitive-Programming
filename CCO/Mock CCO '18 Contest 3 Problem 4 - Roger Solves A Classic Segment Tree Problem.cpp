#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))
#define debug() cout << "..." << endl
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define pb push_back
#define endl "\n"
#define f first
#define s second

using namespace std;
typedef long long ll;

const int MAXN = 50001;
int minTree[4 * MAXN];
int maxTree[4 * MAXN];
int values[MAXN];

void build(int treeIndex, int left, int right)
{
    if (left == right)
    {
        minTree[treeIndex] = values[left];
        maxTree[treeIndex] = values[left];
    }
    else
    {
        int mid = (right - left) / 2 + left;
        build(2 * treeIndex, left, mid);
        build(2 * treeIndex + 1, mid + 1, right);

        minTree[treeIndex] = min(minTree[2 * treeIndex], minTree[2 * treeIndex + 1]);
        maxTree[treeIndex] = max(maxTree[2 * treeIndex], maxTree[2 * treeIndex + 1]);
    }
}

int maxQuery(int treeIndex, int left, int right, int a, int b)
{
    if (right < a || left > b || left > right)
    {
        return -INF;
    }

    if (a <= left && right <= b)
    {
        return maxTree[treeIndex];
    }

    int mid = (right - left) / 2 + left;
    return max(maxQuery(2 * treeIndex, left, mid, a, b), maxQuery(2 * treeIndex + 1, mid + 1, right, a, b));
}

int minQuery(int treeIndex, int left, int right, int a, int b)
{
    if (right < a || left > b || left > right)
    {
        return INF;
    }

    if (a <= left && right <= b)
    {
        return minTree[treeIndex];
    }

    int mid = (right - left) / 2 + left;
    return min(minQuery(2 * treeIndex, left, mid, a, b), minQuery(2 * treeIndex + 1, mid + 1, right, a, b));
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    forn(i, n) cin >> values[i + 1];
    build(1, 1, n);

    int a, b;
    forn(i, q)
    {
        cin >> a >> b;
        cout << maxQuery(1, 1, n, a, b) - minQuery(1, 1, n, a, b) << endl;
    }
}