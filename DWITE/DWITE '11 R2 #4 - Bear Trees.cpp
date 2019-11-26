#include <bits/stdc++.h>
//#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 1005;
vector<int> edge[MAXN];
int vis[MAXN];
int adj[MAXN];
int N;

void setup()
{
    queue<int> q; q.push(0);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        vis[cur] = 1;

        int counter = 0;
        for (int next : edge[cur]) {
            if (adj[next] == 0) {
                counter++;
                q.push(next);
            }
        }

        adj[cur] = counter;
    }
}

int main()
{
    int T = 5;
    while (T--) {
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < MAXN; ++i) edge[i].clear();

        cin >> N;

        for (int i = 1, x, y; i < N; ++i) {
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        setup();

        int worst = 0;
        memset(vis, 0, sizeof(vis)); vis[0] = 1;
        vector<int> travel; travel.push_back(0);

        while (travel.size() > 0) {
            worst = max(worst, static_cast<int>(travel.size()));

            int minSize = INF;
            int minChoice, index;
            for (int i = 0; i < travel.size(); ++i) {
                int next = travel[i];

                if (adj[next] < minSize) {
                    index = i;
                    minChoice = next;
                    minSize = adj[next];
                }
            }

            vis[minChoice] = 1;
            travel.erase(travel.begin() + index);
            for (int next : edge[minChoice]) {
                if (!vis[next]) travel.push_back(next);
            }
        }

        cout << worst << endl;
    }
}
