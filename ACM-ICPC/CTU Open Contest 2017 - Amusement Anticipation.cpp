#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int v[MAXN];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);

    int N;
    while (cin >> N)
    {
        for (int i = 0; i < N; ++i) cin >> v[i];

        int d = v[N - 1] - v[N - 2], x;
        for (x = N - 1; x > 0; --x)
        {
            if (v[x] - v[x - 1] != d) break;
        }

        cout << x + 1 << endl;
    }
}
