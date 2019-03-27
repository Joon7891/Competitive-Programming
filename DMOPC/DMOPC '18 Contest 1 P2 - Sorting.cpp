#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 105;
int a[MAXN];
int N, K;

int main()
{
    cin >> N >> K;

    for (int i = 0; i < N; ++i) cin >> a[i];

    bool valid = 1;
    for (int i = 0; i < N; ++i)
    {
        valid &= (((i + 1) % K) == (a[i] % K));
    }

    if (valid)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
