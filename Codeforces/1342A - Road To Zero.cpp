#include <bits/stdc++.h>
 
using namespace std;
typedef long long i64;
 
void solve(){
	i64 x, y, a, b; 
	
	cin >> x >> y >> a >> b;
	
	i64 a1 = b * x + a * abs(y - x);
	i64 a2 = b * y + a * abs(x - y);
	i64 a3 = a * (x + y);
	i64 ans = min(a1, min(a2, a3));
	cout << ans << endl;
}
 
int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve();
}