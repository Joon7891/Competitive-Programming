#include <bits/stdc++.h>
 
using namespace std;
typedef long long i64;
const int MAXN = 40005;
i64 f[MAXN];
 
void solve(){
	int a, b, q;
	
	cin >> a >> b >> q;
	
	int mod = a * b;
	
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= mod; i++){
		int left = (i % a) % b;
		int right = (i % b) % a;
		
		f[i] = f[i - 1];
		if (left != right) f[i]++;
	}
		
	i64 l, r;
	string out = "";
	for (int i = 0; i < q; i++){
		cin >> l >> r;
		
		i64 low = ceil((l - 1) / mod) * mod + 1;
		i64 high = floor(r / mod) * mod;
		i64 times = (high - low + 1) / mod;
		i64 ans = times * f[mod];
		ans += f[r % mod];
		ans -= f[(l - 1) % mod];
		out += to_string(ans) + " ";
	}
	
	cout << out << endl;
}
 
int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve();
}