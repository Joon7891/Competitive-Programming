#include<bits/stdc++.h>

using namespace std;

int dp[51][1501];
int v[51][31];
int N, K, P;

void solve(int caseNum){
	cin >> N >> K >> P;
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= K; j++) cin >> v[i][j];
	}
	
	memset(dp, 0, sizeof(dp));
	for (int j = 1; j <= K; j++) dp[1][j] = dp[1][j - 1] + v[1][j];
	
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= P; j++){
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			
			int total = 0;
			for (int k = 1; k <= K; k++){
				total += v[i][k];
				if (j - k >= 0){
					dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + total);
				}
			}
		}
	}
	
	cout << "Case #" << caseNum << ": " << dp[N][P] << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}