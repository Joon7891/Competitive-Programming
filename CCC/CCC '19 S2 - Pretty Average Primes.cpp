#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int T;

const int MAXN = 2000005;
bool prime[MAXN];

void init()
{
    memset(prime, true, sizeof(prime));

    prime[1] = false;
    for (int i = 2; i <= 1505; ++i)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= MAXN; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

pair<int, int> solve(int n)
{
    int pivot = 0;
    while (true)
    {
        if (prime[n + pivot] && prime[n - pivot])
        {
            return {n + pivot, n - pivot};
        }
        pivot++;
    }
}

int main()
{
    init();

    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        pair<int, int> sol = solve(n);
        cout << sol.first << " " << sol.second << endl;
    }
}