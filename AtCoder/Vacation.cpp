#include <bits/stdc++.h>
#define endl "\n"
#define INF 3x3f3f3f3f

using namespace std;
const int MAXN = 100005;

int N;
int a[MAXN], b[MAXN], c[MAXN];
int dpA[MAXN], dpB[MAXN], dpC[MAXN];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        dpA[i] = max(dpB[i - 1] + a[i], dpC[i - 1] + a[i]);
        dpB[i] = max(dpA[i - 1] + b[i], dpC[i - 1] + b[i]);
        dpC[i] = max(dpA[i - 1] + c[i], dpB[i - 1] + c[i]);
    }

    int best = max(dpA[N], max(dpB[N], dpC[N]));
    cout << best << endl;
}