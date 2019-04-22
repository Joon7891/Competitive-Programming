#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef pair<int, int> pii;
vector<pii> points;
vector<pii> hull;
int R, M;

bool pos(pii p, pii q, pii r)
{
    int result = (q.second - p.second) * (r.first - q.first) -
    (q.first - p.first) * (r.second - q.second);

    if (result < 0) return true;
    return false;
}

double dist(pii a, pii b)
{
    int x = (a.first - b.first) * (a.first - b.first);
    int y = (a.second - b.second) * (a.second - b.second);
    return sqrt(x + y);
}

int main()
{
    int T = 5;
    while (T--)
    {
        cin >> R >> M;

        hull.clear();
        points.clear();
        for (int i = 0, x, y; i < R; ++i)
        {
            cin >> x >> y;
            points.push_back({x, y});
        }

        int left = 0;
        for (int i = 1; i < R; ++i)
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
            hull.push_back({points[cur]});

            next = (cur + 1) % R;

            for (int i = 0; i < R; ++i)
            {
                if (pos(points[cur], points[i], points[next]))
                {
                    next = i;
                }
            }

            cur = next;
        }

        int K = hull.size();
        int length = 0;
        for (int i = 0; i < K; ++i)
        {
            length += ceil(dist(hull[i], hull[(i + 1) % K]));
        }

        double ans = length * M;
        cout << "$" << ans << ".00" << endl;
    }
}