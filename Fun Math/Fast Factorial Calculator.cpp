#include <bits/stdc++.h>

using namespace std;
const unsigned long long MOD = 4294967296;
const int MAXN = 34;
unsigned long long fact[MAXN];
int N;

int main()
{
    fact[0] = 1;
    for (unsigned long long i = 1; i < MAXN; ++i)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }

    cin >> N;
    for (unsigned long long i = 0, x; i < N; ++i)
    {
        cin >> x;
        cout << (x > 33 ? 0 : fact[x]) << endl;
    }
}
