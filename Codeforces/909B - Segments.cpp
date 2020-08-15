#include <bits/stdc++.h>
using namespace std;

#define debug(var) cout << "[" << #var << " = " << var << "]" << endl;
typedef long long i64;

const int MAXN = 105;
int d[MAXN];

int main(){
	memset(d, 0, sizeof(d));
	
	int N; 
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			d[i + 1]--;
			d[j]++;
		}
	}
	
	int a = 0, m = 0;
	for (int i = 0; i < N; i++) {
		a += d[i];
		m = max(m, a);
	}
	
	cout << m << endl;
}
