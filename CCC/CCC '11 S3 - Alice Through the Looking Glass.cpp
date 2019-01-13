#include <bits/stdc++.h>

using namespace std;

bool solve(int m, int x, int y)
{
    int xAdj = x / (pow(5, m - 1));
    int yAdj = y / (pow(5, m - 1));

    //cout << xAdj << " " << yAdj << "\n";

    if (m == 0) return false;

    if (xAdj == 1 && yAdj == 0 ||
        xAdj == 2 && yAdj == 0 ||
        xAdj == 3 && yAdj == 0 ||
        xAdj == 2 && yAdj == 1)
    {
        return true;
    }
    else if (xAdj == 1 && yAdj == 1 ||
             xAdj == 2 && yAdj == 2 ||
             xAdj == 3 && yAdj == 1)
    {
        return solve(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    }
    else
    {
        return false;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    int m, x, y;
    while (t--)
    {
        cin >> m >> x >> y;

        if (solve(m, x, y))
        {
            cout << "crystal" << "\n";
        }
        else
        {
            cout << "empty" << "\n";
        }
    }
}