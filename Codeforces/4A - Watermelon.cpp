#include<bits/stdc++.h>

using namespace std;

int main(){
	int N; cin >> N;
	
	for (int i = 1; i < N; i++){
		if (i % 2 == 0 && (N - i) % 2 == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
}