#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>
 
using namespace std;
const int MAXN = 100005;
int a[MAXN];
 
void solve(){
	int N, X;
	cin >> N >> X;
	
	for (int i = 0; i < N; i++) cin >> a[i];
	
	sort(a, a + N);
	reverse(a, a + N);
	
	int count = 0;
	i64 total = 0;
	for (int i = 0; i < N; i++){
		total += (a[i] - X);
		
		if (total < 0) break;
		else count++;
	}
	
	cout << count << endl;
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}