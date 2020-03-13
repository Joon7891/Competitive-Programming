#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 20005;
typedef pair<int, int> pii;

bool visited[MAXN];
queue<pii> q;
int N, M;

int main()
{
    memset(visited, false, sizeof(visited));

    cin >> N >> M;

    q.push({N, 0});
    visited[N] = 1;

    while (!q.empty())
    {
        pii c = q.front(); q.pop();

        if (c.first == M)
        {
            cout << c.second << endl;
            return 0;
        }

        if (c.first * 2 <= MAXN && !visited[c.first * 2])
        {
            visited[c.first * 2] = 1;
            q.push({c.first * 2, c.second + 1});
        }

        if (c.first - 1 <= MAXN && c.first - 1 >= 0 && !visited[c.first - 1])
        {
            visited[c.first - 1] = 1;
            q.push({c.first - 1, c.second + 1});
        }
    }
}
