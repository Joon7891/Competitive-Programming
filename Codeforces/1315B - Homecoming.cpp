#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    int T; cin >> T;

    while (T--){
        int a, b, p;
        cin >> a >> b >> p;

        string line; cin >> line;
        int n = line.length();

        const int A = 0;
        const int B = 1;
        int cur = -1;
        int total = 0;
        bool switched = false;

        bool canStart = total <= p;
        for (int i = n - 1; i > 0; i--){
            if (line[i - 1] == 'A') {
                if (cur != A) {
                    total += a;
                    cur = A;
                    switched = true;
                }
            }
            else {
                if (cur != B){
                    total += b;
                    cur = B;
                    switched = true;
                }
            }

            if (!switched && i == 1) total = cur == A ? a : b;

            if (total <= p && i == 1) {
                cout << 1 << endl;
                break;
            }
            else if (total > p) {
                if (canStart) {
                    cout << i + 1 << endl;
                }
                else {
                    cout << n << endl;
                }

                break;
            }
        }
    }

}