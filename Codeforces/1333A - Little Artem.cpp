#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>

using namespace std;
const int MAXN = 105;
char grid[MAXN][MAXN];

void solve(){
	memset(grid, 'E', sizeof(grid));
	
	int N, M; cin >> N >> M;
	
	if (N % 2 == 1 &&  M % 2 == 1){
		for (int i = 0; i < N - 1; i += 2){
			for (int j = 0; j < M; j++){
				grid[i][j] = 'B';
			}
		}
		
		for (int i = 1; i < N - 1; i += 2){
			for (int j = 0; j < M; j++){
				grid[i][j] = 'W';
			}
		}
		
		for (int j = 0; j < M; j++){
			if (j % 2 == 0) grid[N - 1][j] = 'B';
			else grid[N - 1][j] = 'W';
		}
	}
	else {
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if ((i + j) % 2 == 0) grid[i][j] = 'W';
				else grid[i][j] = 'B';
			}
		}
		
		grid[0][0] = 'B';
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) cout << grid[i][j];
		cout << endl;
	}
}

int main(){
	int T; cin >> T;
	while (T--) solve();
}