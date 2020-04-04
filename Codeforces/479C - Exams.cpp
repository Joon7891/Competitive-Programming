#include<bits/stdc++.h>

using namespace std;
const int MAXN = 5000;
pair<int, int> ab[MAXN];
int N;

int main(){
	cin >> N;
	
	for (int i = 0; i < N; i++){
		cin >> ab[i].first >> ab[i].second;
	}
	
	sort(ab, ab + N);
	
	int cur = 1;
	for (int i = 0; i < N; i++){
		if (ab[i].first >= cur && ab[i].second >= cur){
			cur = min(ab[i].first, ab[i].second);
		}
		else if (ab[i].first >= cur){
			cur = ab[i].first;
		}
		else {
			cur = ab[i].second;
		}		
	}
	
	cout << cur << endl;
}