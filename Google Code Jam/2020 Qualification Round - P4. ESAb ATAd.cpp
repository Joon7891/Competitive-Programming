#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
bool globalFlag = true;
int T, B;

void solve(){
    int sameIndex = -1;
    int difIndex = -1;
    vector<int> ans(B + 1, -1);

    for (int i = 1; i <= 5; i++){
        cout << i << endl;
        cin >> ans[i];

        cout << B + 1 - i << endl;
        cin >> ans[B + 1 - i];

        if (ans[i] == ans[B + 1 - i]) sameIndex = i;
        else difIndex = i;
    }

    int cur = 6;
    int input;
    while (cur <= B / 2){
        int counter = 0;
        bool sameChange = true;
        bool difChange = true;

        if (sameIndex != -1){
            cout << sameIndex << endl;
            cin >> input; counter++;

            if (input != ans[sameIndex]) sameChange = true;
            else sameChange = false;
        }

        if (difIndex != -1){
            cout << difIndex << endl;
            cin >> input; counter++;

            if (input != ans[difIndex]) difChange = true;
            else difChange = false;
        }

        if (counter == 1){
            cout << 1 << endl;
            cin >> input;
        }

        if (sameIndex == -1){
            if (difChange){
                reverse(ans.begin() + 1, ans.end());
            }
        }
        else if (difIndex == -1){
            if (sameChange){
                for (int i = 1; i <= B; i++){
                    if (ans[i] == 0) ans[i] = 1;
                    else if (ans[i] == 1) ans[i] = 0;
                }
            }
        }
        else {
            if (sameChange){
                if (difChange){
                    for (int i = 1; i <= B; i++){
                        if (ans[i] == 0) ans[i] = 1;
                        else if (ans[i] == 1) ans[i] = 0;
                    }
                }
                else {
                    reverse(ans.begin() + 1, ans.end());
                    for (int i = 1; i <= B; i++){
                        if (ans[i] == 0) ans[i] = 1;
                        else if (ans[i] == 1) ans[i] = 0;
                    }
                }
            }
            else {
                if (difChange){
                    reverse(ans.begin() + 1, ans.end());
                }
            }
        }

        for (int i = 0; i < 4 && cur <= B / 2; i++){
            cout << cur << endl;
            cin >> ans[cur];

            cout << B + 1 - cur << endl;
            cin >> ans[B + 1 - cur];

            if (ans[cur] == ans[B + 1 - cur]) sameIndex = cur;
            else difIndex = cur;
            cur++;
        }
    }

    for (int i = 1; i <= B; i++){
        cout << ans[i];
    }
    cout << endl;

    string result; cin >> result;
    if (result == "N") globalFlag = false;
}

int main(){
    cin >> T >> B;
    for (int i = 1; i <= T && globalFlag; i++) solve();
}