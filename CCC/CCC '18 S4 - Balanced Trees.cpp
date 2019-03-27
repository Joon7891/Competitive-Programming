#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

unordered_map<int, ll> memo;

ll solve(int n)
{
    if (n == 1) return 1;
    if (memo[n]) return memo[n];

    ll result = 0;
    for (int i = n; i > 1;)
    {
        int a = n / i;
        int b = n / (a + 1);

        result += (ll)(i - b) * solve(a);
        i = b;
    }

    return memo[n] = result;
}

int main()
{
    int N;
    cin >> N;
    cout << solve(N) << endl;
}
