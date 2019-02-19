#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 10000;
int freq[MAXN + 1];
bool isPrime[MAXN + 1];
vector<int> primes;

void init()
{
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i <= MAXN; ++i)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= MAXN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAXN; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

vector<pii > solve(int n)
{
    memset(freq, 0, sizeof(freq));

    vector<int> factors;
    vector<pii > ans;

    for (int i = 2; i <= n; ++i)
    {
        int v = i;

        for (int j = 0; j < primes.size() && v > 1; ++j)
        {
            if (v % primes[j] == 0)
            {
                v /= primes[j];

                if (find(factors.begin(), factors.end(), primes[j]) == factors.end())
                {
                    factors.push_back(primes[j]);
                }
                freq[primes[j]]++; j--;
            }
        }
    }

    for (int i = 0; i < factors.size(); ++i)
    {
        ans.push_back({factors[i], freq[factors[i]]});
    }

    return ans;
}

void output(vector<pii > a)
{
    cout << a[0].first << "^" << a[0].second;

    for (int i = 1; i < a.size(); ++i)
    {
        cout << " * " << a[i].first << "^" << a[i].second;
    }

    cout << endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int t = 5;

    while (t--)
    {
        int n; cin >> n;
        output(solve(n));
    }
}