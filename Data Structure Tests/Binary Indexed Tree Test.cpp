#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 100002;
ll values[MAXN];
ll bit[MAXN];
ll leq[MAXN];
ll n, m;

void updateBIT(ll index, ll value)
{
    while (index <= n)
    {
        bit[index] += value;
        index += index & (-index);
    }
}

ll sumBIT(ll index)
{
    ll sum = 0;

    while (index > 0)
    {
        sum += bit[index];
        index -= index & (-index);
    }

    return sum;
}

void updateLEQ(ll index, ll plusminus)
{
    while(index <= MAXN)
    {
        leq[index] += plusminus;
        index += index & (-index);
    }
}

ll sumLEQ(ll index)
{
    ll sum = 0;

    while (index > 0)
    {
        //cout << index << " " << leq[index] << "\n";
        sum += leq[index];
        index -= index & (-index);
    }

    //cout << sum << "\n";
    return sum;
}


int main()
{
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(values, 0, MAXN);
    memset(bit, 0, MAXN);
    memset(leq, 0, MAXN);
    cin >> n >> m;

    for (ll i = 1; i <= n; ++i)
    {
        cin >> values[i];
        updateBIT(i, values[i]);
        updateLEQ(values[i], 1);
    }

    char op; ll a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> op;

        if (op == 'C')
        {
            cin >> a >> b;
            updateBIT(a, -values[a]);
            updateLEQ(values[a], -1);

            values[a] = b;
            updateBIT(a, b);
            updateLEQ(b, 1);
        }
        else if (op == 'S')
        {
            cin >> a >> b;
            cout << sumBIT(b) - sumBIT(a - 1) << "\n";
        }
        else
        {
            cin >> a;
            cout << sumLEQ(a) << "\n";
        }
    }
}
