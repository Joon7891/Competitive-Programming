#include <bits/stdc++.h>
using namespace std;

#define debug(var) cout << "[" << #var << " = " << var << "]" << endl;
typedef long long i64;

const int MAXN = 200005;
int n, k, a[MAXN], c[MAXN];

void solve(int caseNum){
	memset(c, 0, sizeof(c));
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	
	c[0] = 1;
	for (int i = 1; i < n; i++){
		if (a[i] + 1 == a[i - 1]) c[i] = c[i - 1] + 1;
		else c[i] = 1;
		
		if (c[i] >= k && a[i] == 1) ans++;
	}
	
	cout << "Case #" << caseNum << ": " << ans << endl;
}

int main(){
	int T; cin >> T;
	
	for (int i = 1; i <= T; i++) solve(i);
}