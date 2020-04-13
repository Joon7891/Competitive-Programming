#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 2005;
int dif[MAXN][30];
int a[MAXN];
int N;
 
void solve(){
	memset(dif, 0, sizeof(dif));
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) cin >> a[i];
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= 26; j++){
			dif[i][j] = dif[i - 1][j];
			if (j == a[i]) dif[i][j]++;
		}
	}
	
	if (N == 1) {
		cout << 1 << endl;
		return;
	}
	
	int bestLength = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j < i; j++){
			int aBest = 0;
			for (int x = 1; x <= 26; x++){
				int aCur = 2 * min(dif[j][x], dif[N][x] - dif[i - 1][x]);
				aBest = max(aBest, aCur);
			}
			
			int bBest = 0;
			for (int x = 1; x <= 26; x++){
				int bCur = dif[i - 1][x] - dif[j][x];
				bBest = max(bBest, bCur);
			}
						
			bestLength = max(bestLength, aBest + bBest);
		}
	}
	
	for (int i = 1; i <= N + 1; i++){
		for (int j = 0; j < i; j++){
			int aBest = 0;			
			for (int x = 1; x <= 26; x++){
				int curA = min(dif[j][x], dif[N][x] - dif[i - 1][x]);
				aBest = max(aBest, curA);
			}
						
			int bBest = 0;
			for (int x = 1; x <= 26; x++){				
				int curB = dif[i - 1][x] - dif[j][x];
				bBest = max(bBest, curB);
			}
			
			bestLength = max(bestLength, aBest + bBest);
		}
	}
	
	cout << bestLength << endl;
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}