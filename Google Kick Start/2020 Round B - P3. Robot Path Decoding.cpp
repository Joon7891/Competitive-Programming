#include <bits/stdc++.h>
#define MOD 1000000000
#define i64 long long
#define f first
#define s second

using namespace std;

int i = 0;
pair<i64, i64> getMoves(string a){
	pair<i64, i64> ans = {0, 0};
	
	int n = a.size();
	for (; i < n; i++){
		if (a[i] == 'N') ans.f = (ans.f - 1 + MOD) % MOD;
		else if (a[i] == 'E') ans.s = (ans.s + 1) % MOD;
		else if (a[i] == 'S') ans.f = (ans.f + 1) % MOD;
		else if (a[i] == 'W') ans.s = (ans.s - 1 + MOD) % MOD;
		else if (a[i] == ')') return ans;
		else {
			int mult = a[i]-'0';
			i += 2;
			pair<i64, i64> below = getMoves(a);
			below.f = (mult * below.f) % MOD;
			below.s = (mult * below.s) % MOD;
			ans.f = (ans.f + below.f) % MOD;
			ans.second = (ans.s + below.s) % MOD;
		}
	}
	
	return ans;
}

void solve(int caseNum){
	string moves; cin >> moves;
	
	i = 0;
	pair<i64, i64> cur = {1, 1};
	pair<i64, i64> ans = getMoves(moves);
	
	cur.f = cur.f + ans.f;
	cur.s = cur.s + ans.s;
	
	while (cur.f > MOD) cur.f -= MOD;
	while (cur.s > MOD) cur.s -= MOD;
	
	cout << "Case #" << caseNum << ": " << cur.s << " " << cur.f << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}