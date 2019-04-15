#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int N;

pair<int, int> solve()
{
    int top = max(a[N - 2] - a[0], a[N - 1] - a[1]) - N + 2;

    int low = 0;
    if (a[N - 2] - a[0] == N - 2 && a[N - 1] - a[N - 2] > 2)
    {
        low = 2;
    }
    else if (a[N - 1] - a[1] == N - 2 && a[1] - a[0] > 2)
    {
        low = 2;
    }
    else
    {
        int i, j = 0, ans = 0;
        for (i = 0; i < N; ++i)
        {
            while (j < N - 1 && a[j + 1] - a[i] <= N - 1)
            {
                j++;
            }
            ans = max(ans, j - i + 1);
        }

        low = N - ans;
    }

    return {low, top};
}

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    cin >> N;

    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);

    pair<int, int> ans = solve();
    cout << ans.first << endl;
    cout << ans.second << endl;
}
