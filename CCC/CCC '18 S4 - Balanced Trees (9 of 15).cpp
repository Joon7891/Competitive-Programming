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

map<ll, ll> memo;

ll solve(ll n)
{
    if (n == 1) return 1;

    if (memo.find(n) != memo.end()) return memo[n];

    ll total = 0;

    for (ll i = 2; i <= n; ++i)
    {
        total += solve(n / i);
    }

    memo[n] = total;
    return total;
}

int main()
{
    ll n; cin >> n;
    cout << solve(n) << endl;
}
