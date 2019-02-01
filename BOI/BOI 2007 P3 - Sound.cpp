#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
int n, m, c;

const int MAXN = 1000005;
int a[MAXN];
int minTree[3 * MAXN];
int maxTree[3 * MAXN];
int answers[MAXN];
int pointer = 0;

void build(int tree, int left, int right)
{
    if (left == right)
    {
        minTree[tree] = a[left];
        maxTree[tree] = a[left];
        return;
    }

    int mid = left + (right - left) / 2;
    build(2 * tree, left, mid);
    build(2 * tree + 1, mid + 1, right);
    minTree[tree] = min(minTree[2 * tree], minTree[2 * tree + 1]);
    maxTree[tree] = max(maxTree[2 * tree], maxTree[2 * tree + 1]);
}

int minQ(int tree, int left, int right, int qLeft, int qRight)
{
    if (qLeft > right || qRight < left || left > right)
    {
        return INF;
    }

    if (qLeft <= left && right <= qRight)
    {
        return minTree[tree];
    }

    int mid = left + (right - left) / 2;
    int l = minQ(2 * tree, left, mid, qLeft, qRight);
    int r = minQ(2 * tree + 1, mid + 1, right, qLeft, qRight);
    return min(l, r);
}

int maxQ(int tree, int left, int right, int qLeft, int qRight)
{
    if (qLeft > right || qRight < left || left > right)
    {
        return -INF;
    }

    if (qLeft <= left && right <= qRight)
    {
        return maxTree[tree];
    }

    int mid = left + (right - left) / 2;
    int l = maxQ(2 * tree, left, mid, qLeft, qRight);
    int r = maxQ(2 * tree + 1, mid + 1, right, qLeft, qRight);
    return max(l, r);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> c;

    forn(i, n) cin >> a[i + 1];
    build(1, 1, n);

    for (int i = 1; i < n - m + 2; ++i)
    {
        int low = minQ(1, 1, n, i, i + m - 1);
        int high = maxQ(1, 1, n, i, i + m - 1);

        if (high - low <= c) answers[pointer++] = i;
    }

    if (pointer == 0)
    {
        cout << "NONE" << endl;
        return 0;
    }

    forn(i, pointer)
    {
        cout << answers[i] << endl;
    }
}