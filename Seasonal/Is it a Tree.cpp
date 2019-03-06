#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))

using namespace std;

int grid[4][4];

int main()
{
    forn(i, 4) forn(j, 4) cin >> grid[i][j];

    int counter = 0;

    forn(i, 4)
    {
        forn(j, 4)
        {
            if (grid[i][j] == 1)
            {
                ++counter;
                break;
            }
        }
    }

    if (counter != 4)
    {
        cout << "No" << endl;
        return 0;
    }

    int gridCount = 0;

    forn(i, 4)
    {
        forn(j, 4)
        {
            if (grid[i][j] == 1) ++gridCount;
        }
    }

    if (gridCount == 6)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}