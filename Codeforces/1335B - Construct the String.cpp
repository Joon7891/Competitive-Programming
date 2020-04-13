#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	
	string ans = "";
	for (int i = 0; i < n; i++){
		int modI = i % a;
		
		if (modI < b - 1) ans += 'a' + modI;
		else ans += 'a' + b - 1;
	}
	
	cout << ans << endl;
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}