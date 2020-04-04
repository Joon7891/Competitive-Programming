#include<bits/stdc++.h>

using namespace std;

int main(){
	string a; cin >> a;
	reverse(a.begin(), a.end());
	
	int num;
	for (int i = 0; i < a.length(); i++){
		num = a[i]-'0';
		
		if (num % 8 == 0){
			cout << "YES" << endl;
			cout << num << endl;
			return 0;
		}
		
		for (int j = 0; j < i; j++){
			num = a[j]-'0' + 10 * (a[i]-'0');
			
			if (num % 8 == 0){
				cout << "YES" << endl;
				cout << num << endl;
				return 0;
			}
			
			for (int k = 0; k < j; k++){
				num = a[k]-'0' + 10 * (a[j]-'0') + 100 * (a[i]-'0');
				
				if (num % 8 == 0){
					cout << "YES" << endl;
					cout << num << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "NO" << endl;
}