#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

bool existsAhead(int a, int index){
	for (int i = index + 1; i < 31; i++){
		if (a & (1 << i)) return true;
	}
	
	return false;
}

void solve(int caseNum){
	int X, Y; cin >> X >> Y;
	
	int xDif = abs(X);
	int yDif = abs(Y);
	int xBack = 0;
	int yBack = 0;
	
	int prevDifIndex = -1;
	int oneBitType = 0;
	for (int i = 0; i < 31; i++){
		int xBit = xDif & (1 << i);
		int yBit = yDif & (1 << i);
		
		if (xBit && yBit){
			if (prevDifIndex == -1){
				cout << "Case #" << caseNum << ": IMPOSSIBLE" << endl;
				return;
			}

			if (oneBitType == 1){
				xBack |= 1 << prevDifIndex;
				xDif += 1 << prevDifIndex;
			}
			else {
				yBack |= 1 << prevDifIndex;
				yDif += 1 << prevDifIndex;
			}
			
			prevDifIndex = -1;
		}
		else if (!xBit && !yBit) {
			if (existsAhead(xDif, i) || existsAhead(yDif, i)){
				if (prevDifIndex == -1){
					cout << "Case #" << caseNum << ": IMPOSSIBLE" << endl;
					return;
				}
				
				if (oneBitType == 1){
					xBack |= 1 << prevDifIndex;
					xDif += 1 << prevDifIndex;
				}
				else {
					yBack |= 1 << prevDifIndex;
					yDif += 1 << prevDifIndex;
				}
				
				prevDifIndex = -1;
			}
			else break;
		}
				
		xBit = xDif & (1 << i);
		yBit = yDif & (1 << i);
		
		if (xBit != yBit){
			prevDifIndex = i;
			if (xBit) oneBitType = 1;
			else oneBitType = -1;
		}
	}
	
	char xFront, yFront, xBackC, yBackC;
	if (X < 0){
		xFront = 'W';
		xBackC = 'E';
	}
	else {
		xFront = 'E';
		xBackC = 'W';
	}
	
	if (Y > 0){
		yFront = 'N';
		yBackC = 'S';
	}
	else {
		yFront = 'S';
		yBackC = 'N';
	}
	
	string ans = "";
	for (int i = 0; i < 31; i++){
		int bit = 1 << i;
		if (xDif & bit) ans += xFront;
		else if (xBack & bit) ans += xBackC;
		else if (yDif & bit) ans += yFront;
		else if (yBack & bit) ans += yBackC;
		else break;
	}
	
	cout << "Case #" << caseNum << ": " << ans << endl;
}

int main(){
	int T; cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
}