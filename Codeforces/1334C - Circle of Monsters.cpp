#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>
 
using namespace std;
const int MAXN = 300005;
i64 a[MAXN], b[MAXN];
int N;
 
void solve(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
	
	int minIndex;
	i64 bestChange = LLONG_MAX;
	i64 cur;
	for (int i = 0; i < N; i++){
		i64 change;
		int prev = i - 1;
		if (prev < 0) prev += N;
		
		if (a[i] <= b[prev]) change = a[i];
		else change = b[prev];
 
		if (change < bestChange){
			bestChange = change;
			cur = a[i];
			minIndex = i;
		}
		else if (change == bestChange && a[i] < cur){
			cur = a[i];
			minIndex = i;
		}
	}
	
	i64 total = a[minIndex];
	for (int i = 0; i < N; i++){
		int prev = i - 1;
		if (prev < 0) prev += N;
		
		if (i != minIndex){
			i64 next = a[i] - b[prev];			
			if (next > 0) total += next;
		}
	}
	
	cout << total << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T--) solve();
}