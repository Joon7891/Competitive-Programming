#include <bits/stdc++.h>
#define i64 long long

using namespace std;
const int MAXN = 1005;
i64 x[MAXN];

void solve(int caseNum){
	int N;
	i64 D; 
	
	cin >> N >> D;
	
	for (int i = 0; i < N; i++) cin >> x[i];
	
	for (int i = N - 1; i >= 0; i--){
		if (D % x[i] == 0) continue;
		else D = x[i] * (D / x[i]);
	}
	
	cout << "Case #" << caseNum << ": " << D << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}
