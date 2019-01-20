#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int MOD = 1000000007;

map<ll, ll> memo;

ll solve(ull n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }

    ll ans, mid;
    if (n % 2 == 0)
    {
        mid = n / 2;
        ans = (solve(mid) * (2 * solve(mid + 1) - solve(mid))) % MOD;
    }
    else
    {
        mid = (n - 1) / 2;
        ans = (solve(mid) * solve(mid) + solve(mid + 1) * solve(mid + 1)) % MOD;
    }

    memo[n] = (ans + MOD) % MOD;
    return memo[n];
}

int main()
{
    ull n;
    cin >> n;
    cout << solve(n) << endl;
}