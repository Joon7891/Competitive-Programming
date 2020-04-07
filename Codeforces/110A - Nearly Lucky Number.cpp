#include<bits/stdc++.h>

using namespace std;

int main(){
	string line; cin >> line;
	
	int count = 0;
	int length = line.length();
	for (int i = 0; i < length; i++){
		if (line[i] == '4' || line[i] == '7') count++;
	}
	
	string res = to_string(count);
	for (int i = 0; i < res.length(); i++){
		if (res[i] != '4' && res[i] != '7'){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
}