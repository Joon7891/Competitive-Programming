#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
int a[MAXN];
int N, B;

void solve(int caseNum){
	cin >> N >> B;
	
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int total = 0;
	for (int i = 0; i < N; i++){
		if (B - a[i] >= 0){
			B -= a[i];
			total++;
		}
		else break;
	}
	
	 cout << "Case #" << caseNum << ": " << total << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}
