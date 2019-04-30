#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
typedef pair<int, int> pii;

vector<pii> points;
double slope;
int A, B;
double C;
int N;

double distance(int a)
{
    int x = points[a].first;
    int y = points[a].second;

    if (slope == INF)
    {
        return abs(C - x);
    }

    int top = (A * y + B * x + C) * (A * y + B * x + C);
    int bottom = A * A + B * B;
    return top / (double)bottom;
}

bool opposite(int a, int b)
{
    int ax = points[a].first;
    int ay = points[a].second;
    int bx = points[b].first;
    int by = points[b].second;

    double dy = by-ay;
    double dx = bx-ax;

    double d1 = distance(a);
    double d2 = distance(b);

    double newSlope;
    if (dx == 0) newSlope = INF;
    else newSlope = dy / dx;

    if (abs(d1 - d2) >= 1e-6) return false;

    if (dx == 0) return slope == 0;

    double recip = -1 / newSlope;

    if (newSlope == 0) return slope == INF;
    else return abs(recip - slope) < 1e-6;
}

bool check(int a, int b)
{
    int ax = points[a].first;
    int ay = points[a].second;
    int bx = points[b].first;
    int by = points[b].second;

    double dx = ax - bx;
    double dy = ay - by;

    A = dx;
    B = -dy;

    if (dx != 0)
    {
        C = -(ay - (dy / dx) * ax) * dx;
        slope = (dy / dx);
    }
    else
    {
        C = ax;
        slope = INF;
    }

    for (int i = 1; i < N / 2; ++i)
    {
        if (!opposite((a + i) % N, (a - i + N) % N)) return false;
    }

    return true;
}

int solve()
{
    cin >> N;

    points.clear();
    for (int i = 0, x, y; i < N; ++i)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    if (N & 1) return 0;

    int total = 0;
    for (int i = 0; i < N / 2; ++i)
    {
        if (check(i, i + N / 2)) total++;
    }

    return total;
}

int main()
{
    int T = 10;
    while (T--)
    {
        cout << solve() << endl;
    }
}