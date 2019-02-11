#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define MEM(a, b) memset(a, b, sizeof(a))
#define forn(i, n) for (int i = 0; i < n; ++i)

struct query
{
    int l, r, k;

    query(int l, int r, int k) : l(l), r(r), k(k) {}

    bool operator < (const query &b) const
    {
        return k > b.k;
    }
};

using namespace std;

const int MAXN = 100005;
int BIT[MAXN];
int n, q;

vector<pii > values;
vector<query> queries;
vector<query> queries_sort;
map<int, map<int, map<int, int> > > answers;

int queryBIT(int index)
{
    int total = 0;

    while (index > 0)
    {
        total += BIT[index];
        index -= index & (-index);
    }

    return total;
}

int updateBIT(int index, int value)
{
    while (index <= n)
    {
        BIT[index] += value;
        index += index & (-index);
    }
}

int pointer = 0;

int solve(query q)
{
    while (values.size() > pointer && q.k <= values[pointer].f)
    {
        updateBIT(values[pointer].s, values[pointer].f);
        ++pointer;
    }

    int left = queryBIT(q.l - 1);
    int right = queryBIT(q.r);
    return right - left;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    forn(i, n)
    {
        int index, value;
        cin >> value;
        values.pb({value, i + 1});
    }

    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());

    cin >> q;

    forn(i, q)
    {
        int l, r, k;
        cin >> l >> r >> k;
        ++l; ++r;
        queries.pb(query(l, r, k));
        queries_sort.pb(query(l, r, k));
    }

    sort(queries_sort.begin(), queries_sort.end());

    forn(i, queries_sort.size())
    {
        query current = queries_sort[i];
        answers[current.l][current.r][current.k] = solve(current);
    }

    forn(i, queries.size())
    {
        query current = queries[i];
        cout << answers[current.l][current.r][current.k] << endl;
    }
}