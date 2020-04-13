#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 9;
int a[MAXN][MAXN];

void solve(){
	for (int i = 0; i < MAXN; i++){
		for (int j = 0; j < MAXN; j++){
			char c; cin >> c;
			a[i][j] = c-'0';
		}
	}
	
	a[0][0] = a[0][0] % 9 + 1;
	a[3][1] = a[3][1] % 9 + 1;
	a[6][2] = a[6][2] % 9 + 1;
	
	a[1][3] = a[1][3] % 9 + 1;
	a[4][4] = a[4][4] % 9 + 1;
	a[7][5] = a[7][5] % 9 + 1;
	
	a[2][6] = a[2][6] % 9 + 1;
	a[5][7] = a[5][7] % 9 + 1;
	a[8][8] = a[8][8] % 9 + 1;
	
	for (int i = 0; i < MAXN; i++){
		for (int j = 0; j < MAXN; j++){
			cout << a[i][j];
		}
		
		cout << endl;
	}
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}