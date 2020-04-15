#include<bits/stdc++.h>

using namespace std;

void solve(int caseNum){
	cout << "Case #" << caseNum << ":" << endl;
	
	int N; cin >> N;
	
	if (N <= 500){
		for (int i = 1; i <= N; i++) cout << i << " 1" << endl;
		return;
	}

	N -= 30;
	int K = 0;
	bool isLeft = true;
	
	int i;
	for (i = 0; i < 30; i++){
		if (N & (1 << i)){
			if (isLeft){
				for (int j = 1; j <= i + 1; j++){
					cout << i + 1 << " " << j << endl;
				}
			}
			else {
				for (int j = i + 1; j >= 1; j--){
					cout << i + 1 << " " << j << endl;
				}
			}
			
			K++;
			isLeft = !isLeft;
		}
		else {
			if (isLeft) cout << i + 1 << " 1" << endl;
			else cout << i + 1 << " " << i + 1 << endl;
		}
	}
		
	while (K--){
		if (isLeft) cout << i + 1 << " 1" << endl;
		else cout << i + 1 << " " << i + 1 << endl;
		i++;
	}
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}
