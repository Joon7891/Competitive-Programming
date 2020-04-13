#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>
 
using namespace std;
const int MAXN = 105;
int p[MAXN], c[MAXN];
int N;
 
void solve(){
	cin >> N;
	
	p[0] = c[0] = 0;
	for (int i = 1; i < N + 1; i++){
		cin >> p[i] >> c[i];
	}
	
	for (int i = 0; i < N; i++){
		int pDif = p[i + 1] - p[i];
		int cDif = c[i + 1] - c[i];
				
		if (cDif > pDif){
			cout << "NO" << endl;
			return;
		}
		else if (cDif < 0 || pDif < 0){
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}