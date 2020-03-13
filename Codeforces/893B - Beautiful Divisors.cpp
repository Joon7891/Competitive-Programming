#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
bool flag = false;
int N, ans, k = 1;

int main()
{
    cin >> N;

    while (!flag)
    {
        int d = (1 << ((k << 1) - 1)) - (1 << (k++ - 1));

        if (N % d == 0) ans = d;
        if (d >= N) flag = true;
    }

    cout << ans << endl;
}
