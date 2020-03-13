#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 30;
int cCount[MAXN];

int main(){
    int T; cin >> T;

    while (T--){
        memset(cCount, 0, sizeof(cCount));

        string line; cin >> line;
        int n = line.length();
        line = line + ')';

        char cur = line[0];
        int start = 0;
        for (int i = 1; i <= n; i++){
            if (line[i] != cur){
                if (cCount[cur - 'a'] == 0) cCount[cur - 'a'] = (i - start) % 2;
                start = i;
            }

            cur = line[i];
        }

        for(char c = 'a'; c <= 'z'; c++){
            if (cCount[c - 'a'] == 1) cout << c;
        }
        cout << endl;
    }
}
