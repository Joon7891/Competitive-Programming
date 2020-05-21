#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;
map<int, pii> curLoc;
map<char, pii> dirLoc = {
	{'N', make_pair(0, 1)},
	{'S', make_pair(0, -1)},
	{'E', make_pair(1, 0)},
	{'W', make_pair(-1, 0)}
};

void solve(int caseNum){
	curLoc.clear();
	
	int X, Y;
	string dir;
	
	cin >> X >> Y;
	cin >> dir;
	
	for (int i = 0; i < (int)dir.length(); i++){
		int c = dir[i];
		
		X += dirLoc[c].first;
		Y += dirLoc[c].second;
		
		curLoc[i + 1] = make_pair(X, Y);
	}
	
	int ans = INT_MAX;
	for (int i = 1; i <= dir.length(); i++){
		int d = abs(curLoc[i].first) + abs(curLoc[i].second);
		
		if (d <= i) ans = min(ans, i);		
	}
	
	cout << "Case #" << caseNum << ": ";
	if (ans == INT_MAX) cout << "IMPOSSIBLE" << endl;
	else cout << ans << endl;
}

int main(){
	int T; cin >> T;
	
	for (int i = 1; i <= T; i++) solve(i);
}
