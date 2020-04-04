#include<bits/stdc++.h>
#define MOD 1000000007 

using namespace std;
const int MAXN = 100005;
int dp[MAXN];
int prefix[MAXN];
int T, K;

int main(){
	cin >> T >> K;
	
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i < MAXN; i++){
		dp[i] = dp[i - 1];
		if (i - K >= 0) dp[i] = (dp[i] + dp[i - K]) % MOD;
	}
	
	prefix[0] = 0;
	for (int i = 1; i < MAXN; i++){
		prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
	}
	
	for (int i = 0, a, b; i < T; i++){
		cin >> a >> b;
		int ans = (prefix[b] - prefix[a - 1] + MOD) % MOD;
		cout << ans << endl;
	}	
}