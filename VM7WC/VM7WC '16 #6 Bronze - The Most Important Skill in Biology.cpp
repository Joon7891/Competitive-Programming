#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int x[MAXN];
int y[MAXN];
int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        total += x[i] * y[(i + 1) % n];
        total -= x[(i + 1) % n] * y[i];
    }

    int answer = (int)((abs(total) + 1) / 2);
    cout << answer << endl;
}