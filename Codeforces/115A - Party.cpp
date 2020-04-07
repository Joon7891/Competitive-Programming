#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2005;
vector<int> low[MAXN];
vector<int> tops;

int dfs(int cur){
	if (low[cur].empty()) return 1;
	
	int best = 0;
	for (int nextt : low[cur]) best = max(best, 1 + dfs(nextt));
	return best;
}

int main(){
	int N; cin >> N;
	
	for (int i = 1, x; i <= N; i++){
		cin >> x;
		
		if (x == -1) tops.push_back(i);
		else low[x].push_back(i);
	}
	
	int most = 0;
	for (int top : tops) most = max(most, dfs(top));
	
	cout << most << endl;
}