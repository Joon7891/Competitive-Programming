#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 500005;
int d[MAXN];
long long M;
int N;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i) cin >> d[i];

    int best = INF;
    int left = 0, right = 0;
    long long sum = d[0];
    while (right < N)
    {
        if (sum >= M)
        {
            best = min(best, right - left + 1);
            sum -= d[left++];
        }
        else
        {
            sum += d[++right];
        }
    }

    cout << (best == INF ? -1 : best) << endl;
}
