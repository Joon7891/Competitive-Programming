#include <bits/stdc++.h>
#include <bitset>
typedef long long ll;

using namespace std;

const ll MAXN = 20000001;
bitset<MAXN> prime;
vector<ll> cache;
ll a, b;

bool isPrime()
{
    for (int i = 0; i < cache.size(); ++i)
    {
        if (a % cache[i] == 0) return false;
    }

    return true;
}

ll sieve()
{
    ll UPPER = ceil(sqrt(b));
    ll dif = b - a;
    prime.set();

    for (ll i = 2; i <= UPPER; ++i)
    {
        if (prime[i])
        {
            for (ll j = 2 * i; j <= UPPER; j += i)
            {
                prime[j] = false;
            }
            cache.push_back(i);
        }
    }
    prime.reset();
    prime.set();

    ll beg;
    for (ll i = 0; i < cache.size(); ++i)
    {
        beg = cache[i] - a % cache[i];

        if (beg + a == cache[i] && a % cache[i] != 0) beg += cache[i];

        for (int j = beg; j < dif; j += cache[i])
        {
            prime[j] = false;
        }
    }

    ll total = 0;
    for (ll i = 1; i < dif; ++i)
    {
        if (prime[i])
        {
            ++total;
        }
    }

    if (isPrime()) ++total;

    return total;
}

int main()
{
    cin >> a;
    cin >> b;
    cout << sieve() << "\n";
}
