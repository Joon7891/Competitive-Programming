#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
int psa[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int buffer;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            cin >> psa[0];
        }
        else
        {
            cin >> buffer;
            psa[i] = psa[i - 1] + buffer;
        }
    }

    int q;
    cin >> q;
    int a, b;
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;

        if (a == 0)
        {
            cout << psa[b] << "\n";
        }
        else
        {
            cout << psa[b] - psa[a - 1] << "\n";
        }
    }
}