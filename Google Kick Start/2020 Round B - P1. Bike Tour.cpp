#include <bits/stdc++.h>

using namespace std;
const int MAXN = 105;
int h[MAXN];

void solve(int caseNum){
	int N; cin >> N;
	
	for (int i = 1; i <= N; i++) cin >> h[i];
	
	int total = 0;
	for (int i = 2; i < N; i++) {
		if (h[i] > h[i - 1] && h[i] > h[i + 1]) total++;
	}
	
	cout << "Case #" << caseNum << ": " << total << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}
