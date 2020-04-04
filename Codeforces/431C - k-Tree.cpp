#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000000007
 
using namespace std;
const int MAXN = 105;
int dp[MAXN][2];
 
int n, k, d;
 
int main(){
	cin >> n >> k >> d;
	
	dp[0][0] = 1;
	dp[0][1] = 0;
	
	for (int i = 1; i <= n; i++){
		dp[i][0] = dp[i][1] = 0;
		
		for (int j = 1; j <= k && i - j >= 0; j++){
			if (j >= d){
				dp[i][1] = (dp[i - j][0] + dp[i][1]) % MOD;
				dp[i][1] = (dp[i - j][1] + dp[i][1]) % MOD;
			}
			else {
				dp[i][0] = (dp[i - j][0] + dp[i][0]) % MOD;
				dp[i][1] = (dp[i - j][1] + dp[i][1]) % MOD;
			}
		}
	}
	
	cout << dp[n][1] << endl;
}