#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 200005;
int a[MAXN];
int N;
 
void solve(){
	cin >> N;
	
	map<int, int> counter;
	set<int> distinct;
	for (int i = 0; i < N; i++){
		cin >> a[i];
		counter[a[i]]++;
		distinct.insert(a[i]);
	}
	
	int maxCount = 0;
	for (int i = 1; i <= N; i++){
		maxCount = max(maxCount, counter[i]);
	}
	
	if (maxCount > distinct.size()){
		cout << distinct.size() << endl;
	}
	else if (maxCount < distinct.size()){
		cout << maxCount << endl;
	}
	else {
		cout << maxCount - 1 << endl;
	}
}
 
int main(){
	int T; cin >> T;
	while (T--) solve();
}