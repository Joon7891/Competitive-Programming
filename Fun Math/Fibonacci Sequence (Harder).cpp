#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int MOD = 1e9 + 7;

unordered_map<ll, ll> memo;
ull N = 0;


ll solve(ull n)
{
    if (n == 1 || n == 2) return 1;
    else if (memo.find(n) != memo.end()) return memo[n];

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

    return memo[n] = (ans + MOD) % MOD;;
}

int main()
{
    char digit;

    while ((digit = getchar()) < '0') continue;

    do N = (10 * N + digit-'0') % 2000000016;
    while ((digit = getchar()) >= '0');

    cout << solve(N) << endl;
}