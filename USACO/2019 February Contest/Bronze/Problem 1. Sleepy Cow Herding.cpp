#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int a[3];

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    for (int i = 0; i < 3; ++i) cin >> a[i];
    sort(a, a + 3);

    if (a[0] + 1 == a[1] && a[1] + 1 == a[2])
    {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    else
    {
        if (a[1] + 2 == a[2] || a[0] + 2 == a[1])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }

        cout << max(a[1] - a[0] - 1, a[2] - a[1] - 1) << endl;
    }
}
