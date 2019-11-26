#include <bits/stdc++.h>
//#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 35;
const int MAX_TOTAL = 30005;
bool vis[2][MAX_TOTAL];
int total = 0;
int v[MAXN];

int main()
{
    int T = 5;
    while (T--) {
        total = 0;
        memset(vis, 0, sizeof(vis));

        int N; cin >> N;

        for (int i = 0; i < N; ++i) {
            cin >> v[i];
            total += v[i];
        }

        vis[0][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= total; ++j) {
                vis[1][j] = vis[0][j];

                if (j - v[i] >= 0) {
                    vis[1][j] |= vis[0][j - v[i]];
                }
            }

            for (int j = 0; j <= total; ++j) {
                vis[0][j] = vis[1][j];
                vis[1][j] = 0;
            }
        }

        int best = INF;
        for (int i = total; i >= 0; --i) {
            if (vis[0][i]) {
                best = min(best, abs(total - 2 * i));
            }
        }

        cout << best << endl;
    }
}
