#include<bits/stdc++.h>

using namespace std;
const int MAXN = 300005;
int a[MAXN];

int main(){
	int N; cin >> N;
	
	for (int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	
	long long total = 0;
	for (int i = 1; i <= N; i++){
		total += abs(i - a[i]);
	}
	
	cout << total << endl;
}