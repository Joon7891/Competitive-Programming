#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef pair<int, int> pii;
unordered_map<int, bool> visited;

int N, mask = 0;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0, x; i < N; ++i)
    {
        cin >> x;
        mask = (mask << 1) | x;
    }

    queue<pii> q; q.push({mask, 0});
    visited[mask] = 1;

    while (!q.empty())
    {
        pii current = q.front(); q.pop();
        int mask = current.first;
        int length = current.second;

        for (int i = 0; i < N; ++i)
        {
            int sizer = 0;

            for (int j = i; j < N; ++j)
            {
                if ((1 << j) & mask) ++sizer;
                else break;
            }

            if (sizer > 3)
            {
                for (int j = i; j < i + sizer; ++j)
                {
                    mask &= ~(1 << j);
                }
            }
        }

        if (!mask)
        {
            cout << length << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < N; ++i)
            {
                int new_mask = mask | (1 << i);

                if (!visited[new_mask])
                {
                    visited[new_mask] = 1;
                    q.push({new_mask, length + 1});
                }
            }
        }
    }
}