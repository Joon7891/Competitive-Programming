#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>

using namespace std;
const int MAXN = 300;
string a[MAXN];
set<int> cur;
int N;

char get_win(int index){
	bool r, s, p;
	r = s = p = false;
	
	for (int i = 0; i < N; i++){
		if (cur.find(i) != cur.end()){
			r |= a[i][index % a[i].length()] == 'R';
			s |= a[i][index % a[i].length()] == 'S';
			p |= a[i][index % a[i].length()] == 'P';
		}
	}
		
	if (r && !s && !p) return 'P';
	if (!r && s && !p) return 'R';
	if (!r && !s && p) return 'S';
	
	if (r && s && !p) return 'R';
	if (r && !s && p) return 'P';
	if (!r & s && p) return 'S';
	
	return 'N';
}

char win_over(char c){
	if (c == 'R') return 'S';
	else if (c == 'P') return 'R';
	else return 'P';
}

void solve(int caseNum){
	cur.clear();
	
	cin >> N;
	
	for (int i = 0; i < N; i++){
		cin >> a[i];
		cur.insert(i);
	}
	
	string ans = "";
	for (int i = 0; cur.size() > 0; i++){
		char next = get_win(i);
		
		if (next == 'N'){
			cout << "Case #" << caseNum << ": IMPOSSIBLE" << endl;
			return;
		}
		
		ans += next;
		for (int j = 0; j < N; j++){
			if (cur.find(j) != cur.end()){
				if (a[j][i % a[j].size()] == win_over(next)) cur.erase(j);
			}
		}
	}
	
	cout << "Case #" << caseNum << ": " << ans << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}