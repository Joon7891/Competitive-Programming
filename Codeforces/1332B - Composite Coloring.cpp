#include<bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1005;
map<int, int> factor;
int cur = 1;
int a[MAXN];
int c[MAXN];
int N;
 
void solve(){
	factor.clear();
	cur = 1;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	
	for (int i = 0; i < N; i++){
		for (int j = 2; j <= a[i]; j++){
			if (a[i] % j == 0){
				if (factor[j] == 0) factor[j] = cur++;
				c[i] = factor[j];		
				break;		
			}
		}
	}
	
	cout << cur - 1 << endl;
	for (int i = 0; i < N; i++) cout << c[i] << " ";
	cout << endl;
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}