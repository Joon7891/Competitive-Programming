#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define MEM(a, b) memset(a, b, sizeof(a))
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const int MAXN = 25;
int initial_mask = 0;
int n;

void solve()
{
    queue<pii > q; // (mask, length)
    q.push({initial_mask, 0});
    set<int> visited;
    visited.insert(initial_mask);

    while (!q.empty())
    {
        pii current = q.front(); q.pop();
        int mask = current.f;
        int length = current.s;

       // cout << mask << " " << length << endl;

        //cout << mask << " " << length << endl;

        // Check for switch light
        for (int i = 0; i < n; ++i)
        {
            int length = 0;

            for (int j = i; j < n; ++j)
            {
                if ((1 << j & mask) > 0)
                {
                    ++length;
                }
                else
                {
                    break;
                }
            }

            if (length >= 4)
            {
                for (int j = i; j < i + length; ++j)
                {
                    mask -= (1 << j);
                    //cout << "New Mask: " << mask << endl;
                }
            }
        }

        if (mask == 0)
        {
            cout << length << endl;
            return;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                int value = mask + (1 << i);
                if (!(mask & (1 << i)) && visited.find(value) == visited.end())
                {
                     q.push({value, length + 1});
                     visited.insert(value);
                }
            }
        }
    }
}

int main()
{
    cin >> n;


    int current;
    forn(i, n)
    {
        cin >> current;
        initial_mask = initial_mask * 2 + current;
    }

    solve();
}