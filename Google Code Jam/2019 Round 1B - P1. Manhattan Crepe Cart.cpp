#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<int, int>

using namespace std;

const int MAXP = 505;
const int MAXN = 100005;
int xDif[MAXN], yDif[MAXN];
int xFreq[MAXN];
int yFreq[MAXN];

void solve(int caseNum){
	memset(xDif, 0, sizeof(xDif));
	memset(yDif, 0, sizeof(yDif));
	memset(xFreq, 0, sizeof(xFreq));
	memset(yFreq, 0, sizeof(yFreq));
	
	int P, Q;
	cin >> P >> Q;
	
	int x, y; char dir;
	for (int i = 0; i < P; i++){
		cin >> x >> y >> dir;
		
		if (dir == 'N'){
			yDif[y + 1]++;
			yDif[Q + 1]--;
		}
		else if (dir == 'S'){
			yDif[0]++;
			yDif[y]--;
		}
		else if (dir == 'E'){
			xDif[x + 1]++;
			xDif[Q + 1]--;
		}
		else {
			xDif[0]++;
			xDif[x]--;
		}
	}
	
	int cur = 0;
	for (int i = 0; i <= Q; i++){
		cur += xDif[i];
		xFreq[i] = cur;
	}
	
	cur = 0;
	for (int i = 0; i <= Q; i++){
		cur += yDif[i];
		yFreq[i] = cur;
	}
	
	int xPos;
	int xBest = -1;
	for (int i = Q; i >= 0; i--){
		if (xFreq[i] >= xBest){
			xBest = xFreq[i];
			xPos = i;
		}
	}
	
	int yPos;
	int yBest = -1;
	for (int i = Q; i >= 0; i--){
		if (yFreq[i] >= yBest){
			yBest = yFreq[i];
			yPos = i;
		}
	}
	
	cout << "Case #" << caseNum << ": " << xPos << " " << yPos << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}