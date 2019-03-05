#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 105;
int a[MAXN];
int N, l, r, c;

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        l += a[i];
    }

    sort(a, a + N);

    int c = 0;
    while ((l >= r))
    {
        l -= a[N - 1 - c];
        r += a[N - 1 - c++];
    }

    cout << c << endl;
}
