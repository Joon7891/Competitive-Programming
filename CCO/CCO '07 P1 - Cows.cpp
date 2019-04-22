#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef pair<int, int> pii;
vector<pii> points;
vector<pii> hull;
int N;

bool pos(pii p, pii q, pii r)
{
    int result = (q.second - p.second) * (r.first - q.first) -
    (q.first - p.first) * (r.second - q.second);

    if (result < 0) return true;
    return false;
}

int main()
{
    cin >> N;

    for (int i = 0, x, y; i < N; ++i)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    int left = 0;
    for (int i = 1; i < N; ++i)
    {
        if (points[i].first < points[left].first)
        {
            left = i;
        }
    }

    bool flag = true;
    int cur = left, next;
    while (cur != left || flag)
    {
        flag = false;
        hull.push_back(points[cur]);

        next = (cur + 1) % N;

        for (int i = 0; i < N; ++i)
        {
            if (pos(points[cur], points[i], points[next]))
            {
                next = i;
            }
        }

        cur = next;
    }

    int shoelace = 0;
    int K = hull.size();
    for (int i = 0; i < K; ++i)
    {
        int j = (i + 1) % K;
        shoelace += (hull[i].first * hull[j].second);
        shoelace -= (hull[j].first * hull[i].second);
    }
    int ans = abs(shoelace) / 100;
    cout << ans << endl;
}