#include<bits/stdc++.h>

using namespace std;
const int MAXN = 15;

int n, l, r, x;
int c[MAXN];


bool check(int mask){
	int count = 0;
	for (int i = 0; i < n; i++){
		if ((1 << i) & mask) count++;
	}
	
	int low = INT_MAX;
	int high = INT_MIN;
	
	int total = 0;
	for (int i = 0; i < n; i++){
		if ((1 << i) & mask){
			low = min(low, c[i]);
			high = max(high, c[i]);
			total += c[i];
		}
	}
	
	return total >= l && total <= r && (high - low) >= x;
}

int main(){	
	cin >> n >> l >> r >> x;
	
	for (int i = 0; i < n; i++) cin >> c[i];

	int total = 0;
	for (int i = 1; i < (1 << n); i++){
		if (check(i)) total++;
	}
	
	cout << total << endl;
}