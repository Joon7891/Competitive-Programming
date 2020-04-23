#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int MAX = 1000000000;
int A, B;

string ask(int x, int y){
	cout << x << " " << y << endl;
	string ans; cin >> ans;
	return ans;
}

void solve(){
	string verdict = "";
	
	int xStart, yStart;
	for (int i = -MAX; i <= MAX; i += 2 * MAX / 10){
		for (int j = -MAX; j <= MAX; j += 2 * MAX / 10){
			verdict = ask(i, j);
			
			if (verdict == "HIT"){
				xStart = i;
				yStart = j;
				break;
			}
			else if (verdict == "CENTER") return;
		}
		
		if (verdict == "HIT") break;
	}
	
	int low = -MAX, high = xStart;
	while (low < high){
		int mid = low + (high - low) / 2;
		verdict = ask(mid, yStart);
		
		if (verdict == "CENTER") return;
		else if (verdict == "HIT") high = mid;
		else low = mid + 1;
	}
	int xLow = low;
	
	low = xStart; high = MAX;
	while (high > low){
		int mid = low + (high - low + 1) / 2;
		verdict = ask(mid, yStart);
		
		if (verdict == "CENTER") return;
		else if (verdict == "HIT") low = mid;
		else high = mid - 1;
	}
	int xHigh = high;
	
	low = -MAX; high = yStart;
	while (low < high){
		int mid = low + (high - low) / 2;
		verdict = ask(xStart, mid);
		
		if (verdict == "CENTER") return;
		else if (verdict == "HIT") high = mid;
		else low = mid + 1;
	}
	int yLow = low;
	
	low = yStart; high = MAX;
	while (low < high){
		int mid = low + (high - low + 1) / 2;
		verdict = ask(xStart, mid);
		
		if (verdict == "CENTER") return;
		else if (verdict == "HIT") low = mid;
		else high = mid - 1;
	}
	int yHigh = high;
	
	int xAns = (xLow + xHigh) / 2;
	int yAns = (yLow + yHigh) / 2;
	
	verdict = ask(xAns, yAns);
	assert(verdict == "CENTER");
}

int main(){
	int T; cin >> T >> A >> B;
	for (int i = 1; i <= T; i++) solve();
}