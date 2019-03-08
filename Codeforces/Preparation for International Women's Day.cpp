#include <bits/stdc++.h>

using namespace std;
const int MAXK = 105;

int f[MAXK];
int N, K;

int main()
{
    cin >> N >> K;

    int d = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> d;
        f[d % K]++;
    }

    int t = 2 * (f[0] / 2);
    for (int i = 1; i < K - i; ++i)
    {
        t += 2 * min(f[i], f[K - i]);
    }

    if (K % 2 == 0)
    {
        t += 2 * (f[K / 2] / 2);
    }

    cout << t << endl;
}
