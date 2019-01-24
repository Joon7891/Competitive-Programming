#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define pb push_back
#define MEM(a, b) memset(a, (b), sizeof(a))
#define INF 0x3f3f3f3f

using namespace std;

int C, O, W, S;
int ci, wi, so, oo;
int si, oi, co, wo;

int solve(int c, int o, int w, int s)
{
    int current = o;

    if (c >= ci && w >= wi)
    {
        current = max(current, solve(c - ci, o + oo, w - wi, s + so));
    }

    if (s >= si && o >= oi)
    {
        current = max(current, solve(c + co, o - oi, w + wo, s - si));
    }


    return current;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 10;

    int n;
    while (t--)
    {
        cin >> C >> O >> W >> S;
        cin >> ci >> wi >> so >> oo;
        cin >> si >> oi >> co >> wo;

        cout << solve(C, O, W, S) << endl;
    }
}
