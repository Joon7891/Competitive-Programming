#include<bits/stdc++.h>

using namespace std;
const int MAXN = 105;
int a[MAXN];

int main(){
	int N; cin >> N;
	
	for (int i = 1, x; i <= N; i++){
		cin >> x;
		a[x] = i;
	}
	
	for (int i = 1; i <= N; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}