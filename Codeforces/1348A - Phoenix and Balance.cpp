#include <bits/stdc++.h>
 
using namespace std;
typedef long long i64;
 
int main(){
	int T; cin >> T;
	
	while (T--){
		int N;
		cin >> N;
		
		int s = N / 2;
		i64 a = pow(2, N);
		i64 b = 0;
		for (int i = 1; i < s; i++) a += pow(2, i);
		for (int i = s; i < N; i++) b += pow(2, i);
		cout << abs(a - b) << endl;
	}
}