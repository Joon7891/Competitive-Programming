#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
int n, m;

const int MAXN = 100005;
int a[MAXN];
int minTree[4 * MAXN];
int gcdTree[4 * MAXN];
unordered_map<int, unordered_map<int, int> > BIT;

int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b % a, a);
}

void build(int tree, int left, int right)
{
    if (left == right)
    {
        minTree[tree] = a[left];
        gcdTree[tree] = a[left];
        return;
    }

    int mid = left + (right - left) / 2;
    build(2 * tree, left, mid);
    build(2 * tree + 1, mid + 1, right);
    minTree[tree] = min(minTree[2 * tree], minTree[2 * tree + 1]);
    gcdTree[tree] = gcd(gcdTree[2 * tree], gcdTree[2 * tree + 1]);
}

void updateBIT(int value, int index, int a)
{
    while (index <= n)
    {
        BIT[value][index] += a;
        index += index & (-index);
    }
}

void setupBIT()
{
    for (int i = 1; i <= n; ++i)
    {
        updateBIT(a[i], i, 1);
    }
}

int queryGCD(int tree, int left, int right, int qLeft, int qRight)
{
    if (qLeft > right || qRight < left || qLeft > qRight)
    {
        return 0;
    }

    if (qLeft <= left && right <= qRight)
    {
        return gcdTree[tree];
    }

    int mid = (left + right) / 2;
    return gcd(queryGCD(2 * tree, left, mid, qLeft, qRight), queryGCD(2 * tree + 1, mid + 1, right, qLeft, qRight));
}

int queryMin(int tree, int left, int right, int qLeft, int qRight)
{
    if (qLeft > right || qRight < left || qLeft > qRight)
    {
        return INF;
    }

    if (qLeft <= left && right <= qRight)
    {
        return minTree[tree];
    }

    int mid = (left + right) / 2;
    return min(queryMin(2 * tree, left, mid, qLeft, qRight), queryMin(2 * tree + 1, mid + 1, right, qLeft, qRight));
}

int total;

int bitSum(int index, int value)
{
    total = 0;

    while (index > 0)
    {
        total += BIT[value][index];
        index -= index & (-index);
    }

    return total;
}

int querySum(int left, int right, int value)
{
    return bitSum(right, value) - bitSum(left - 1, value);
}

void updateTree(int tree, int left, int right, int index)
{
    if (index == left && index == right)
    {
        minTree[tree] = a[index];
        gcdTree[tree] = a[index];
        return;
    }

    int mid = (left + right) / 2;

    if (left <= index && index <= mid)
    {
        updateTree(2 * tree, left, mid, index);
    }
    else
    {
        updateTree(2 * tree + 1, mid + 1, right, index);
    }

    gcdTree[tree] = gcd(gcdTree[2 * tree], gcdTree[2 * tree + 1]);
    minTree[tree] = min(minTree[2 * tree], minTree[2 * tree + 1]);
}

void update(int index, int value)
{
    updateBIT(a[index], index, -1);
    a[index] = value;
    updateBIT(a[index], index, 1);
    updateTree(1, 1, n, index);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    forn(i, n) cin >> a[i + 1];

    build(1, 1, n);
    setupBIT();

    char a; int x, y;
    while (m--)
    {
        cin >> a >> x >> y;

        switch(a)
        {
            case 'C':
                update(x, y);
                break;
            case 'M':
                cout << queryMin(1, 1, n, x, y) << endl;
                break;
            case 'G':
                cout << queryGCD(1, 1, n, x, y) << endl;
                break;
            case 'Q':
                int newGCD = queryGCD(1, 1, n, x, y);
                cout << querySum(x, y, newGCD) << endl;
                break;
        }
    }
}