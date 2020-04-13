#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int T; cin >> T;
	for (int i = 0, n; i < T; i++) {
		cin >> n;
		
		int ans;
		if (n % 2 == 0) ans = n / 2 - 1;
		else ans = n / 2;
		
		cout << ans << endl;
	}
}