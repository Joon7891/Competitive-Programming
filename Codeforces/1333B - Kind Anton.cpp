#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>
 
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int b[MAXN];
int N;
 
void solve(){
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	
	for (int i = 0; i < N; i++){
		if (a[i] == 0 && b[i] != 0){
			cout << "NO" << endl;
			return;
		}
		else if (a[i] != 0){
			if (a[i] == b[i]) break;
			else {
				cout << "NO" << endl;
				return;
			}
		}
	}
	
	int posOne = -1;
	int negOne = -1;
	
	for (int i = 0; i < N; i++){
		if (posOne == -1 && a[i] == 1) posOne = i;
		if (negOne == -1 && a[i] == -1) negOne = i;
	}
	
	if (posOne == -1 && negOne == -1){
		cout << "YES" << endl;
	}
	else if (posOne != -1 && negOne != -1){
		bool flag = true;
		if (posOne < negOne){
			for (int i = posOne + 1; i <= negOne; i++){
				if (b[i] >= a[i]) continue;
				else flag = false;
			}			
		}
		else {
			for (int i = negOne + 1; i <= posOne; i++){
				if (b[i] <= a[i]) continue;
				else flag = false;
			}
		}
		
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if (posOne == -1 && negOne != -1){
		bool flag = true;
		for (int i = negOne + 1; i < N; i++){
			if (b[i] <= a[i]) continue;
			else flag = false;
		}
		
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if (posOne != -1 && negOne == -1){
		bool flag = true;
		for (int i = posOne + 1; i < N; i++){
			if (b[i] >= a[i]) continue;
			else flag = false;
		}
		
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}