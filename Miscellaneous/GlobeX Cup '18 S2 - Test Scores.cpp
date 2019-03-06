#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k;
long long minimum;
long long current = 0;
long long studyTime = 0;
const int MAXN = 100000;
pair<int, int> studying[MAXN];

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }

    return a.second < b.second;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    minimum = n * k;

    ll x, y;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x >> y;
        current += x;
        studying[i] = make_pair(x, y);
    }

    sort(studying, studying + n, compare);

    ll scoreChange;
    for (ll i = 0; i < n && minimum > current; ++i)
    {
        if (minimum - current <= m - studying[i].first)
        {
            scoreChange = minimum - current;
            studyTime += scoreChange * studying[i].second;
            current += scoreChange;
            break;
        }
        else
        {
            scoreChange = m - studying[i].first;
            studyTime += scoreChange * studying[i].second;
            current += scoreChange;
        }
    }

    cout << studyTime << "\n";
}