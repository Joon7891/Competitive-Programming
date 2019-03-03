#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int weight(int n)
{
    int w = 0;
    while (n)
    {
        if (n & 1) w++;
        n >>= 1;
    }

    return w;
}

int solve(int n)
{
    int k = weight(n);
    for (int i = 0; i < 31; ++i)
    {
        if (n & (1 << i))
        {
            n += (1 << i);
            break;
        }
    }

    k -= weight(n);
    for (int i = 0; i < 31; ++i)
    {
        if (k && !(n & (1 << i)))
        {
            n |= (1 << i);
            k--;
        }
    }

    return n;
}

int main()
{
    int T = 5;

    while (T--)
    {
        int n; cin >> n;
        cout << solve(n) << endl;
    }
}
