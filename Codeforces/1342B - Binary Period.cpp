#include <bits/stdc++.h>
 
using namespace std;
typedef long long i64;
 
void solve(){
	string s; cin >> s;
	
	int aCount = 0, bCount = 0;
	int n = s.length();
	for (int i = 0; i < n; i++){
		if (s[i] == '0') aCount++;
		else bCount++;
	}
	
	if (aCount == n || bCount == n){
		cout << s << endl;
		return;
	}
	
	string ans = "";
	for (int i = 0; i < 2 * n; i++){
		ans += '0' + (i % 2);
	}
	
	cout << ans << endl;	
}
 
int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve();
}