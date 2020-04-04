#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
const int MAXN = 105;
int grid[MAXN][MAXN];
bool vis[MAXN];
int N;

void solve(int num){
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    int trace = 0;
    for (int i = 0; i < N; i++) trace += grid[i][i];

    int row = 0;
    for (int i = 0; i < N; i++){
        memset(vis, 0, sizeof(vis));

        for (int j = 0; j < N; j++){
            int cur = grid[i][j];
            if (vis[cur]){
                row++;
                break;
            }

            vis[cur] = 1;
        }
    }

    int col = 0;
    for (int j = 0; j < N; j++){
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < N; i++){
            int cur = grid[i][j];
            if (vis[cur]){
                col++;
                break;
            }

            vis[cur] = 1;
        }
    }

    cout << "Case #" << num << ": " << trace << " " << row << " " << col << endl;
}

int main(){
    int T; cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}